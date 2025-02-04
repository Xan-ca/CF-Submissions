#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,l,r;
    cin>>n>>l>>r;
    vector<ll>v(n);
    vector<ll>vl,vs,vr;
    ll res=0;

    for(auto &it:v)cin>>it;
    for(ll i=0;i<l-1;i++){
    	vl.push_back(v[i]);
    }
    for(ll i=l-1;i<r;i++){
    	vs.push_back(v[i]);
    	res+=v[i];
    }
    for(ll i=r;i<n;i++){
    	vr.push_back(v[i]);
    }
    sort(vl.begin(),vl.end());
    sort(vs.begin(),vs.end());
    sort(vr.begin(),vr.end());
    ll redl=0,redr=0;
    for(ll i=0,j=vs.size()-1;i<min(vs.size(),vl.size());i++,j--){
      ll red=vs[j]-vl[i];
      if(red<0)break;
      else redl+=red;
    }
    for(ll i=0,j=vs.size()-1;i<min(vs.size(),vr.size());i++,j--){
      ll red=vs[j]-vr[i];
      if(red<0)break;
      else redr+=red;
    }
    cout<<res-max(redl,redr)<<endl;

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