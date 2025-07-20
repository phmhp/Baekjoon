#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ; 
    cin >> n ; 

    vector<int> dp(n+1, 0); //dp[1] = 0

    for (int i = 2; i<=n; i++){ // -1해서 1을 만들 수 있는 횟수 (더 나은 경로가 있으면 갱신하기 위함)
        dp[i] = dp[i-1] + 1;

        if (i%2 == 0)
            dp[i] = min(dp[i], dp[i/2]+1);

        if (i%3 == 0)
            dp[i] = min(dp[i], dp[i/3]+1);
    }

    cout << dp[n] << "\n";
}