#!/usr/bin/env python3
from __future__ import annotations

import json
import re
from dataclasses import dataclass
from pathlib import Path
from typing import List
from urllib.request import urlopen

ROOT = Path(__file__).resolve().parents[1]
README_PATH = ROOT / "README.md"
WORKBOOKS_PATH = Path(__file__).with_name("workbooks.json")

START_MARKER = "<!-- BARKINGDOG_PROGRESS_START -->"
END_MARKER = "<!-- BARKINGDOG_PROGRESS_END -->"

RAW_BASE = "https://raw.githubusercontent.com/encrypted-def/basic-algo-lecture/master/workbook/"

ROW_RE = re.compile(
    r"\|\s*(연습 문제|기본 문제(?:✔)?|응용 문제(?:✔)?)\s*"
    r"\|\s*(\d+)\s*"
    r"\|\s*\[([^\]]+)\]\(([^)]+)\)\s*"
    r"\|\s*([^|]*)\|"
)

TITLE_RE = re.compile(r"#\s+(.+?)\s+!\[")
LINK_RE = re.compile(r"\[문제집 링크\]\((https://www\.acmicpc\.net/workbook/view/\d+)\)")


@dataclass
class Problem:
    kind: str
    number: int
    title: str
    url: str


@dataclass
class Workbook:
    workbook_id: str
    title: str
    workbook_url: str
    source_file: str
    problems: List[Problem]


def fetch_text(url: str) -> str:
    with urlopen(url) as resp:
        return resp.read().decode("utf-8")


def parse_workbook(source_file: str, workbook_id: str) -> Workbook:
    text = fetch_text(RAW_BASE + source_file)
    title_match = TITLE_RE.search(text)
    link_match = LINK_RE.search(text)
    if not title_match or not link_match:
        raise ValueError(f"Failed to parse workbook header: {source_file}")

    problems = []
    for kind, number, title, url, _code in ROW_RE.findall(text):
        problems.append(
            Problem(
                kind=kind.strip(),
                number=int(number),
                title=title.strip(),
                url=url.strip(),
            )
        )

    workbook_url = link_match.group(1)
    if not workbook_url.endswith(workbook_id):
        raise ValueError(
            f"Workbook ID mismatch for {source_file}: expected {workbook_id}, got {workbook_url}"
        )

    return Workbook(
        workbook_id=workbook_id,
        title=title_match.group(1).strip(),
        workbook_url=workbook_url,
        source_file=source_file,
        problems=problems,
    )


def find_solved_problem_numbers(repo_root: Path) -> set[int]:
    solved = set()
    baekjoon_root = repo_root / "백준"
    if not baekjoon_root.exists():
        return solved

    pattern = re.compile(r"^(\d+)\.")
    for path in baekjoon_root.rglob("*"):
        if not path.is_dir():
            continue
        match = pattern.match(path.name)
        if match:
            solved.add(int(match.group(1)))
    return solved


def progress_bar(done: int, total: int, width: int = 20) -> str:
    if total == 0:
        return "░" * width
    filled = round(width * done / total)
    return "█" * filled + "░" * (width - filled)


def render_problem_list(wb: Workbook, solved: set[int]) -> str:
    lines = []
    lines.append("<details>")
    lines.append(f"<summary>문제 목록 보기 ({len(wb.problems)}문제)</summary>")
    lines.append("")
    lines.append("| 상태 | 번호 | 문제 |")
    lines.append("|---|---:|---|")
    for p in wb.problems:
        status = "✅" if p.number in solved else "⬜"
        lines.append(f"| {status} | {p.number} | [{p.title}]({p.url}) |")
    lines.append("")
    lines.append("</details>")
    return "\n".join(lines)


def render_workbook_section(wb: Workbook, solved: set[int]) -> str:
    done = sum(1 for p in wb.problems if p.number in solved)
    total = len(wb.problems)
    percent = 0 if total == 0 else round(done * 100 / total, 1)

    lines = []
    lines.append("---")
    lines.append("")
    lines.append(f"## [{wb.title}]({wb.workbook_url})")
    lines.append("")
    lines.append(f"- 진행도: **{done}/{total} ({percent}%)** | `{progress_bar(done, total)}`")
    lines.append("")
    lines.append(render_problem_list(wb, solved))
    lines.append("")
    return "\n".join(lines)


def generate_progress_section(workbooks: List[Workbook], solved: set[int]) -> str:
    lines = []
    for wb in workbooks:
        lines.append(render_workbook_section(wb, solved))
    return "\n".join(lines).rstrip() + "\n"


def replace_between_markers(text: str, new_block: str) -> str:
    pattern = re.compile(
        rf"({re.escape(START_MARKER)})(.*)({re.escape(END_MARKER)})",
        re.DOTALL,
    )
    replacement = rf"\1\n{new_block}\n\3"
    new_text, count = pattern.subn(replacement, text)
    if count != 1:
        raise ValueError("README markers not found or duplicated.")
    return new_text


def main() -> None:
    workbook_defs = json.loads(WORKBOOKS_PATH.read_text(encoding="utf-8"))
    workbooks = [parse_workbook(item["source"], item["id"]) for item in workbook_defs]
    solved = find_solved_problem_numbers(ROOT)

    progress_section = generate_progress_section(workbooks, solved)
    readme = README_PATH.read_text(encoding="utf-8")
    updated = replace_between_markers(readme, progress_section)
    README_PATH.write_text(updated, encoding="utf-8")
    print(f"Updated README.md with {len(workbooks)} workbooks and {len(solved)} solved problem folders detected.")


if __name__ == "__main__":
    main()
