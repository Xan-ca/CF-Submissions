#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    ll int n=20000000;
    vector<ll int>prime(n+1,0);
    int sn=sqrt(n);
    vector<pair<ll int,ll int>>res;
    for(ll int i=2;i<=sn;i++){
        if(prime[i]==0){
            for(ll int j=i*2;j<=n;j+=i){
             if(prime[j]==0)prime[j]=1;
            }
        }
    }
    for(int i=4;i<=n;i++){
        if(prime[i]==prime[i-2] && prime[i]==0){
            res.push_back({i-2,i});
        }
    }
    ll int query;
    while(cin>>query){
    cout<<"("<<res[query-1].first<<", "<<res[query-1].second<<")"<<endl;
    }
    return 0;
}