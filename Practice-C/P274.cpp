#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,k,d;
    cin>>n>>k>>d;
    vector<ll>a(n+1,0),b(k+1,0);
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=k;i++)cin>>b[i];
    ll res=0;
    ll t=0;
    ll ptr=1;
    for(ll j=1;j<=n;j++){
         if(a[j]==j)t++;
    }
    res=max(((d-1)/2)+t,res);
    for(ll i=1;i<=2*n;i++){
    	
    	t=0;
    	if(ptr==k+1){
            ptr=1;
    	}
    	ll b_i=b[ptr];
    	ptr++;
    	for(ll j=1;j<=b_i;j++){
    	 a[j]++;
    	}
    	for(ll j=1;j<=n;j++){ 
         if(a[j]==j)t++;
    	}
    	if(i<d)res=max(t+((d-(i+1))/2),res);
    }
    cout<<res<<endl;

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