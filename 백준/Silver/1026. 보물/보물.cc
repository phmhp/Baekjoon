#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,a,b;
    cin>>N;
    cin.ignore();// cin 이후 개행 제거


    int result=0;
    vector<int> A;
    vector<int> B;
    vector<int> B_index(N);
    iota(B_index.begin(),B_index.end(),0);
    string temp;
    
    getline(cin,temp);
    stringstream ssa(temp);
    while (ssa>>a){
        A.push_back(a);
    }
    getline(cin,temp);
    stringstream ssb(temp);
    while (ssb>>b){
        B.push_back(b);
    }
    
    sort(A.begin(),A.end());

    sort(B_index.begin(),B_index.end(), [&](int i,int j){
        return B[i]>B[j];
    });
    
    for (int j=0; j<N; j++){
        result+= (A[j]*B[B_index[j]]);
    }
    cout<<result;
    return 0;
}