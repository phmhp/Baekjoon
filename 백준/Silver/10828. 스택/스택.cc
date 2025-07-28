#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int N;
    cin>>N;
    
    vector<int> stack;
    cin.ignore(); // 줄바꿈 문자 제거
    while(N--){
        string line,word;
        getline(cin,line);
        stringstream ss(line);
        
        ss>>word;
        
        if (word=="push"){
            int x;
            ss >> x;
            stack.push_back(x);
        }  
        else if (word=="pop"){
            if (stack.size()>0) {
                cout<<stack.back()<<"\n";
                stack.pop_back();
            }
            else {
                cout<<"-1\n";
            }
       }
       else if (word=="size"){
            cout<<stack.size()<<"\n";
       }    
       else if (word=="empty"){
           if (stack.empty()){
               cout<<"1\n"; 
           }
           else{
               cout<<"0\n";
           }
       }
       else if (word=="top"){
           if (stack.size()>0){
               cout<<stack.back()<<"\n";
           }
           else {
               cout <<"-1\n";
           }
       } 
    }
}