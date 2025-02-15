#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n);
    set<ll>b;
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<m;i++){
    ll temp;
    cin>>temp;
    b.insert(temp);
    }
   // sort(b.begin(),b.end());
    a[0]=min(a[0],*b.begin()-a[0]);
    for(ll i=1;i<n;i++){
    if(b.lower_bound(a[i-1]+a[i])!=b.end())if(a[i]>=a[i-1]){
    	a[i]=min((*b.lower_bound(a[i-1]+a[i]))-a[i],a[i]);
    }else a[i]=(*b.lower_bound(a[i-1]+a[i]))-a[i];
    if(a[i]<a[i-1]){
    cout<<"NO"<<endl;
    return;
    }
    }
    cout<<"YES"<<endl;
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