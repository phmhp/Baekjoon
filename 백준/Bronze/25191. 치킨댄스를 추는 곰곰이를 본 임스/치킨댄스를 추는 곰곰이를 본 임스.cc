#include <iostream>
using namespace std;

int main(){
    //치킨 1마리 -> 콜라 2캔 or 맥주 1캔 
    //먹을 수 있는 치킨 <= 치킨집의 치킨 수 

    //치킨집 치킨의 수, 콜라의 수, 맥주의 수
    int N, A, B, count = 0;  
    cin >> N; 
    cin >> A >> B; 

    
    bool flag = true; 
    
    while (flag) {
        if (N <= 0) { //치킨집의 치킨이 없을 때 
            flag = false; 
            break; 
        }
        else if (A < 2 && B < 1) { //같이 마실 콜라나 맥주가 부족할 때 
            flag = false; 
            break; 
        }

        while (A>=2 && N>0){
            N -= 1;
            A -= 2;
            count += 1;
        }
        while (B>=1 && N>0){
            N -= 1;
            B -= 1;
            count += 1;
        }
    
    }
    cout << count << "\n";
    return 0; 
}