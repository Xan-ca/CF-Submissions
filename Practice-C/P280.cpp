#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 // v v v imp remember nc2 follows 1+2+3... becoz n(n-1)/2 form which is similar to sum (n)(n+1)/2 form

void Solve() 
{
    ll q;
    cin>>q;

    vector<pair<ll,ll>>v;
    v.push_back({0,0});
    ll pr=0;

    for(ll i=1;i<500;i++){
        if(pr+i>q){
        	break;
        }else{
        	v.push_back({i,0});
        	pr+=i;
        }
    }
    ll x=v.size();
    ll f=1;
    for(ll j=1;j<=v.size();j++){
    for(ll i=1;i;i++){
    	if(pr+i>q){
        	break;
        }else{
        	v.push_back({j,f});
        	f++;
        	pr+=i;
        }
    }	
    }
    
    cout<<v.size()<<endl;
    for(auto it:v)cout<<it.first<<" "<<it.second<<endl;
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