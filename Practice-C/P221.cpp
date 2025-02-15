#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>>res;
    for(ll i=2;i<=n;i++){
    	cout<<"?"<<i<<" "<<1<<endl;
    	cout<<flush;
    	ll a,neighbour;
    	cin>>a;
        while(a!=i){
            break;
        	cout<<"?"<<i<<" "<<a<<endl;
        	cout<<flush;
        	cin>>a;
        	if(a==i)break;
        	neighbour=a;
        }
        res.push_back({i,a});
    }
    cout<<"?"<<" ";
    for(auto it:res)cout<<it.first<<" "<<it.second<<" ";
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