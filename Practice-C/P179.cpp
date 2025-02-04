#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    ll q=0;
    cin>>q;
    vector<ll>v(n);
    for(auto &it:v)cin>>it;
    vector<ll>pref(n+1,0);
    pref[1]=1;
    for(ll i=1;i<n;i++){
    if(i==n-1){
    pref[i+1]=pref[i]+1;
    break;
    }
   
    if(v[i]>v[i-1] || v[i+1]>v[i])pref[i+1]=pref[i]+1;
    else {
      pref[i+1]=pref[i]; 
     // v[i]=0;  
    }
    }
    for(auto it:pref)cout<<it<<" ";
        cout<<endl;
  
    ll mn=2;
 
    while(q--){
    ll l,r;
    cin>>l>>r;
    if((r-l)+1<=2){
        //cout<<r<<" "<<l<<endl;
     cout<<(r-l)+1<<endl;
    }
    else if((r-l)+1>=3){
         if(pref[r]==pref[r-1]||pref[l-1]==pref[l]){

         cout<<max((pref[r]-pref[l-1])+1,mn)<<endl;
         }else if(pref[r]==pref[r-1] && pref[l-1]==pref[l]){
           cout<<max((pref[r]-pref[l-1])+2,mn)<<endl; 
         }
         else{
           // cout<<r<<l<<endl;
         cout<<max(pref[r]-pref[l-1],mn)<<endl;
         }
    }
    }

}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    //cin >> t;
    for(ll i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}