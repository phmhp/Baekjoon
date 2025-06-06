#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int a, int b, int c, int d) {
    map<int, int> cnt;
    cnt[a]++; cnt[b]++; cnt[c]++; cnt[d]++;
    
    // 숫자가 하나 뿐 = 네 주사위 숫자가 모두 같은 경우 
    if (cnt.size() ==1) {
        return 1111 * a ;
    }
    
    // 2가지로 나뉠 때 = 3:1 이나 2:2 인 경우 
    else if (cnt.size() == 2) {
        for (auto it : cnt) {
            if (it.second == 3) {//빈도수가 3인 경우 
                int p = it.first; // key값(=주사위 돌려서 나온 값) 을 p로 설정 
                int q = (cnt.begin()->first == p)? (++cnt.begin())-> first : cnt.begin()->first;
                return (10 * p + q) * (10 *p +q);
            }
        }
        
        auto it = cnt.begin();
        int p = it->first;
        int q = (++it)-> first;
        return (p+q) * abs(p-q);
    }
    
    // 2개만 같고 1개 1개 다른 경우 
    else if (cnt.size() ==3){
        int pairVal = 0;
        int single1 = 0, single2 = 0;
        for (auto it : cnt) {
            if (it.second == 2)pairVal = it.first;
            else if (single1 == 0) single1 = it.first;
            else single2 = it.first;
            
        }
        return single1 * single2;
    }
    else {
        return min ({a,b,c,d});
    }
       
}