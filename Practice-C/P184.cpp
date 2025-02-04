#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<ll>res;
    vector<vector<ll>>arr(n,vector<ll>(m));
    vector<ll>rs(n,0);
    vector<ll>cs(m,0);
    for(ll i=0;i<n;i++){

    for(ll j=0;j<m;j++){
    ll a;
    cin>>a;
    arr[i][j]=a;
     rs[i]+=a;
     cs[j]+=a;
    }
    }
    
    ll x=0,y=0;
    for(int i=0;i<s.size();i++){
    if(s[i]=='D'){
    res.push_back(-rs[y]);
    arr[y][x]=-rs[y];
    cs[x]+=-rs[y];
    y++;
    }
    else{
    res.push_back(-cs[x]);
    arr[y][x]=-cs[x];
    rs[y]+=-cs[x];
    x++;
    }

    }
    arr[n-1][m-1]=-rs[n-1];
    if(rs[n-1]!=cs[m-1])cout<<-1;
     for(ll i=0;i<n;i++){

    for(ll j=0;j<m;j++){
    
    cout<<arr[i][j]<<" ";
    
    }
    cout<<endl;
    }
    
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