#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solve(){
    ll int  n,d,k;
    cin>>n>>d>>k;
   // int arr[n];
    vector<vector<int>>inTime(n+1);
    vector<vector<int>>outTime(n+1);
    for(ll int i=1;i<=k;i++){
       ll int in,out;
       cin>>in>>out;
       inTime[in].push_back(i);
       outTime[out].push_back(i);
    }
    ll int mx=0,mi=INT_MAX;
    ll int mii=0,mxi=0;
    set<ll int>s;
    for(ll int i=1;i<=n;i++){
       for(auto it:inTime[i]){
        s.insert(it);
       }
       if(s.size()>mx){
        mx=s.size();
        //mxi=i;
        if(i-d+1>0)mxi=i-d+1;
        else{
          mxi=1;
        }
        //cout<<mxi<<mx<<endl;
       } 
       if(i-d>=0 && s.size()<mi){
        mi=s.size();
        //mii=i;
        if(i-d+1>0)mii=i-d+1;
        else{
          mii=1;
        }
       }
       if(i-d+1>=1){
       for(auto it:outTime[i-d+1]){
        s.erase(it);
       }
       }

    }
    cout<<mxi<<" "<<mii<<endl;
   // cout<<mx<<" "<<mi<<endl;
    return 0;
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}