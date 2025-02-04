#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    char s[26]={0};
    char ch;
    for(ll int i=0;i<m;i++){
        cin>>ch;
        s[ch-'a']=1;
    }
    ll int dp[n+1];
    dp[0]=0;
    ll int k=0;
    for(ll int i=1;i<=n;i++){
        if(s[str[i-1]-'a']==0){
            dp[i]=dp[i-1];
            k=i;
        }else{
            dp[i]=dp[i-1]+i-k;
        }
    }
    cout<<dp[n]<<endl;

}