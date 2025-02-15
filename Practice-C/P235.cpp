#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 //convert 999 to 10^3-1
void Solve() 
{
    ll n;
    cin>>n;
    
    vector<ll>ans(10,100);
    for(ll i=0;i<=9;i++){
        ll k=n-i;
        string s=to_string(k);
        s='0'+s;
        for(ll j=0;j<s.size();j++){
            if(s[j]=='7')ans[j]=min(i,ans[j]);
            if(((s[j]-'0')+i)%10==7)ans[j]=min(i,ans[j]);
        }
    }
    ll mn=100;
    for(auto it :ans)mn=min(mn,it);
        cout<<mn<<endl;

    	



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