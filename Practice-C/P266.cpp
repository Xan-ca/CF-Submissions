#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
	ll n;
	cin>>n;
	if(n==2){
        cout<<1<<" "<<1<<endl<<1<<" "<<2<<endl;
        cout<<endl;
        return;
	}
	if(n==3){
		cout<<2<<" "<<1<<endl<<2<<" "<<3<<endl<<3<<" "<<1<<endl;
		cout<<endl;
		return;
	}
	vector<pair<ll,ll>>v;
    v.push_back({1,1});
    v.push_back({1,2});
    v.push_back({2,4});
    v.push_back({4,4});
	for(ll i=5;i<=n;i++){
     v.push_back({i,i});
	}
	for(auto it:v)cout<<it.first<<" "<<it.second<<endl;
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