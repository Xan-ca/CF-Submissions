#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll int n;
    cin>>n;
    ll inf=1e7;
    ll int dp[n+1][8]={inf};
    dp[0][0]=0
    for(ll int i=0;i<n;i++){
        ll int cost;
        string s;
        cin>>cost>>s;
        int string_mask=0;
        for(int pos=0;p<3;p++){
            char c='C'-pos;
            bool have=0;
            for(char d:s){
                if(d==c)have=1;
            }
            if(have){
                string_mask+= pow(2,pos);
            }
        }
        for(int mask=0;mask<8;mask++){
          dp[i+1][mask]=min(dp[i+1][mask],dp[i][mask]);
          dp[i+1][mask|string_mask]=min(dp[i+1][mask|string_mask],dp[i][mask]+cost);
        }  
    }
    cout<<dp[n][7]<<endl;
    return 0;
    
}