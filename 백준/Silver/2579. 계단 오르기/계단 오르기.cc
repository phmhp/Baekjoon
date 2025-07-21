#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> score(n,0);
    vector<int> dp(n,-1);

    for(int i=0;i<n;i++){
        cin>>score[i];
    }
    
    if (n==1){
        cout << score[0];
        return 0;
    }
    else if (n==2){
        cout << (score[0]+score[1]);//score[1]로 바로 가는 방법도 있긴한데 수가 더 작음
        return 0;
    }

    dp[0]=score[0];//첫번째 계단(n=1)
    dp[1]=score[0]+score[1];//두번째 계단(n=2)
    dp[2]=max(dp[0]+score[2],score[1]+score[2]);//세번째 계단(n=3)

    //+2 경우:dp[j-2]+score[j]
    //+1 경우,연속3칸 불가:dp[j-3]+score[j-1]+score[1] 
    for (int j=3;j<n;j++){
        dp[j]= max(dp[j-2]+score[j],dp[j-3]+score[j-1]+score[j]);
    }
cout<<dp[n-1] ;
}