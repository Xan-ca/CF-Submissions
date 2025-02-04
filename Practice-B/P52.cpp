#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    ll int n,b,c;
    cin>>n>>b>>c;
    if(b==0){
        if(c==n-2 || c==n-1){
            cout<<n-1<<endl;
            return;
        }else if(c>n-1){
            cout<<n<<endl;
            return;
        }
         if(c<n-2){
            cout<<-1<<endl;
            return;
         }
    }
    else{
        if(c>=n){
            cout<<n<<endl;
            return;
        }
        cout<<n-(((n-1-c)/b)+1)<<endl;
        return;
    }
}
int main(){
    ll int t;
    cin>>t;
    while(t--){
        solve();
    }
}