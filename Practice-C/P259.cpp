#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 /*For each element, you can calculate its positions in both matrices.
  You can see that the rearrangement of rows does not affect the column
   positions of the elements being rearranged. Similarly, column rearrangement
    does not affect row positions. Since the permutation of rows affects
     the entire rows, for all elements that have the same position row in
      the original matrix, the position row in the resulting matrix must
        also match. Similarly, the columns must match.*/
void Solve() 
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>gridA(n,vector<ll>(m,0)),gridB(n,vector<ll>(m,0));
    map<ll,pair<ll,ll>>mp;
    for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
       cin>>gridA[i][j];
       mp[gridA[i][j]]={i,j};
    }
    }
    for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
       cin>>gridB[i][j];
      
    }
    }
    for(ll i=0;i<n;i++){
    for(ll j=1;j<m;j++){
       if(mp[gridB[i][j]].first!=mp[gridB[i][j-1]].first){
       cout<<"NO"<<endl;
       return;
       }
       
    }
    }
    for(ll j=0;j<m;j++){
    for(ll i=1;i<n;i++){
       if(mp[gridB[i][j]].second!=mp[gridB[i-1][j]].second){
       cout<<"NO"<<endl;
       return;
       }
       
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