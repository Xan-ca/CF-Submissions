#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,cnt=0;
    string s;
    cin>>s;
    n=s.size();
    vector<ll>v;
    for(ll i=0;i<n;i++){

    	if(s[i]=='A'){
    		cnt++;

    	}
    	if(s[i]=='B' || i==n-1){
    		v.push_back(cnt);
    		cnt=0;
    	}
    	if(s[i]=='B' && i==n-1){
    		v.push_back(0);
    		cnt=0;
    	}
    }
    sort(v.begin(),v.end());
    ll res=0;
    for(ll i=1;i<v.size();i++){
    	res+=v[i];
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