#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>v(n),pref(n+1,0);
    for(auto &it:v)cin>>it;
    //cout<<"hi";	
    for(int i=1;i<=n;i++){
        pref[i]=v[i-1]^pref[i-1];
    }
    string s;
    cin>>s;
    ll zero=0,one=0;
    for(ll i=0;i<n;i++){
    	if(s[i]=='0')zero=zero^v[i];
    	if(s[i]=='1')one=one^v[i];
    }
    ll q;
    cin>>q;
    //cout<<"hi";
    while(q--){
    	ll type;
    	cin>>type;
    	if(type==1){
    		ll l,r;
    		cin>>l>>r;
    		zero=zero^(pref[r]^pref[l-1]);
    		one=one^(pref[r]^pref[l-1]);
    	}else{
    		ll qu;
    		cin>>qu;
    		qu?cout<<one<<" ":cout<<zero<<" ";
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