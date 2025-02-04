#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,pos;
    cin>>n>>pos;
    vector<ll>v(31,0);
    for(ll i=1,k=0;i<=n;i*=2,k++){
    v[k]=n/i;
    }
    vector<ll>a(31,0);
    a[0]=n-v[1];
    for(ll i=30;i>=1;i--){
    ll reduc=0;
    for(ll j=i+1;j<31;j++)reduc+=v[j];
    v[i]-=reduc;
    a[i]=v[i];
    }
    ll k=0;
    for(ll i=0;i<=31;i++){
    if(k+a[i]>=pos){
     ll z=pos-k;
     ll res=((z*2)-1)*(pow(2,i));
     cout<<res<<endl;
     return;
    }else{
    	k+=a[i];
    }
    }
    cout<<endl;
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