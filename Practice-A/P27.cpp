#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    int n,m;
    while(cin>>n>>m){
        int mx=max(n,m);
        int mi=min(n,m);
        if(gcd(mx,mi)==1){
            cout<<n<<" "<<m<<" "<<"Good Choice"<<endl;
            cout<<endl;
        }
        else{
            cout<<n<<" "<<m<<" "<<"Bad Choice"<<endl;
            cout<<endl;
        }
    }
    return 0;
}
