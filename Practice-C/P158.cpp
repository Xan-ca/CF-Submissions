#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool willdie(ll k,vector<vector<ll>>&v,ll n,ll turn){
    ll dmg2=0;
	for(ll i=0;i<n;i++){
     ll mul=turn/v[0][i];
     dmg2+=v[1][i]*mul;
     if(dmg2>=k){
     	return true;
     }
    }
    if(k>dmg2){
     return false;
    }else return true;

}
void Solve() 
{
    ll k,n;
    cin>>k>>n;
    vector<vector<ll>>v(2,vector<ll>(n,0));
    for(ll i=0;i<n;i++)cin>>v[1][i];
    for(ll i=0;i<n;i++)cin>>v[0][i];
   
    ll dmg2=0;
    ll dmg1=0;
    for(ll i=0;i<n;i++){
      dmg1+=v[1][i];
    }
    k-=dmg1;
    if(k<=0){
 
    cout<<1<<endl;
    return ;
    }
    

  // cout<<k<<endl;
    ll lo=0;
    ll hi=1e14;
    while(hi-lo>1){
     ll mid=(lo+hi)/2;
     if(willdie(k,v,n,mid)){
     hi=mid;
     }else{
     lo=mid;
     }

    }
    cout<<lo+2<<endl;
    return;
    

}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
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