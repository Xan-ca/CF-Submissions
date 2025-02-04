#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m,v;
    cin>>n>>m>>v;
    //int arr[n];
    vector<int>fwd;
    vector<int>bwd;
    
    fwd.push_back(0);
    bwd.push_back(n-1);
    int a=0,cnt=0;
    int pf[n];
    for(int i=0;i<n;i++){
        cin>>pf[i];
    }
    for(int i=1;i<n;i++){
       pf[i]+=pf[i-1];
       if(pf[i]-a>=v){
        a=pf[i];
        cnt++;
        fwd.push_back(i);
       }
    }
    if(cnt<m){
        cout<<-1<<endl;
        return;
    }
    a=0;
    for(int i=n-2;i>=0;i--){
      // bf[i]+=bf[i+1];
       if((pf[n-1]-pf[i])-a>=v){
        a=pf[i];
        bwd.push_back(i);
       }
    }
    int res=min(pf[fwd[m]],pf[n-1]-pf[bwd[m]-1]);
    for(int i=1;i<m;i++){
        res=min(res,(pf[fwd[i]]-pf[bwd[m-i] -1]+pf[n-1]));
    }
    res=pf[n-1]-res;
    cout<<res<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}