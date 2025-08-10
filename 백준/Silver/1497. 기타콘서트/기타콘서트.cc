#include <bits/stdc++.h>
using namespace std ; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 0; 
    int n, m ; 
    cin >> n >> m; 

    vector<unsigned long long> mask(n, 0); //기타별 비트 저장 
    int cover = 0; //비트 연산 과정 저장 
    
    string name,song; 
        
    for (int i = 0 ; i< n ; i++) {
        cin >> name >> song;  
        for (int k = 0 ; k<m; k++){
            if (song[k] == 'Y') mask[i] |= (1ULL << k);
        }
    }

    int songnum = 0 ; //칠 수 있는 곡의 수 
    int minGuitar = INT_MAX; //필요한 기타 수 
    
    //부분집합 (조합) - subset의 i번째 비트가 1이면 i번 기타 사용 
    //const unsigned long long allMask = (m == 64? ~0 : ((1<<m)-1);
    const unsigned long long allMask = (1ULL << m)-1ULL; 

    for (int subset = 1; subset < (1<<n); subset++) { //비트셋으로 기타 조합 순회 설정 (subset은 10진수-> 이걸 비트화해서 특정 기타들의 조합)  
        uint64_t cover = 0 ; //subset이 커버하는 비트 셋 
        for (int b = 0; b<n; b++) {
            if (subset & (1 << b)) { //subset에 속한 기타들 파악 
                cover |= mask[b]; 
            }
            if (cover == allMask) break ; 
        }
  

    int curSongs = __builtin_popcountll(cover); //1인 비트의 개수를 세서 반환 (64비트 정수용)
    int curGuitars = __builtin_popcount(subset);  //1인 비트의 개수 반환 

    if (curSongs > songnum) {
        songnum = curSongs; 
        minGuitar = curGuitars; 
    }else if (curSongs == songnum && curGuitars < minGuitar) {
        minGuitar = curGuitars; 
        }
    }
   cout << (songnum == 0 ? -1 : minGuitar) << "\n"; 
}

    
