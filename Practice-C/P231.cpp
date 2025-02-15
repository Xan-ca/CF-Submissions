#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 set<ll>st;
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>v(n+1,0);
    vector<vector<ll>>neigh(n+1);
    vector<ll>mp(n+1,0);
    for(ll i=1;i<=n;i++)cin>>v[i];
    for(ll i=0;i<n-1;i++){
    ll temp1,temp2;
    cin>>temp1>>temp2;
    neigh[temp1].push_back(temp2);
    neigh[temp2].push_back(temp1);
    }

    for(ll i=1;i<=n;i++){
    	st.clear();
    for(auto it:neigh[i]){
    if(v[i]==v[it])mp[v[i]]=1;
    if(st.find(v[it])!=st.end())mp[v[it]]=1;
    else st.insert(v[it]);
    }
    
    }
    for(ll i=1;i<=n;i++)cout<<mp[i];
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