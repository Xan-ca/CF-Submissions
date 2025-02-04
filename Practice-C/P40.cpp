#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll int,vector<ll int>>mp;
map<ll int,ll int>vis;
ll int dfs(ll int a){
     if(mp.find(a)==mp.end())return 0;
    if(vis.find(a)!=vis.end() && vis[a]!=-1)return vis[a];
   
    ll int mx=0;
    for(auto it:mp[a]){
       // cout<<a+it<<endl;
        ll int k=0;
        if(mp.find(a+it)!=mp.end()){
             k+=dfs(a+it);
        }
        k+=it;
        mx=max(k,mx);
    }
    vis[a]=mx;
    //cout<<mx<<endl;
    return mx;
};
 
void solve(){
ll int n;
cin>>n;
ll int arr [n];
for(ll int i=0;i<n;i++){
    cin>>arr[i];
}
 
for(ll int i=1;i<n;i++){
    mp[arr[i]+(i+1)].push_back(i);
    vis[arr[i]+(i+1)]=-1;
}
if(mp.find(n+1)!=mp.end()){
    cout<<n+dfs(n+1)<<endl;
}else{
    cout<<n<<endl;
}
mp.clear();
vis.clear();
 
}
int main(){
    int t;
    cin>>t;
    while(t){
        solve();
        t--;
    }
}
