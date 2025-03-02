#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 vector<vector<ll>>dp(5002,vector<ll>(5002,0));
void Solve() 
{   
    int n,m;
    cin>>n>>m;
    vector<ll>v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    } 
    if(v.back()!=0){
        v.push_back(0);
        n++;
    }
   //for(auto &it:dp)fill(all(it),0);
   
   vector<ll>v1,v2;
   ll tot=0,res=0;
   for(ll i = 0 ; i < n ; i++){
    if(v[i] > 0){
      v1.push_back(v[i]);
    }
    else if(v[i] < 0){
        v2.push_back(abs(v[i]));
    }
    else{
        tot++;
        sort(all(v1));
        sort(all(v2));
        // for(auto it: v2)cout<<it<<" ";
        //     cout<<endl;
        for(ll j=0;j<=tot;j++){
            if(j!=0){
               ll c1=j-1, c2=tot-j;
                ll val=(upper_bound(all(v1),c1)-v1.begin())+
                       (upper_bound(all(v2),c2)-v2.begin());
                dp[tot][j]=max(dp[tot][j],dp[tot-1][j-1]+val);

            }
            if(j < tot){
               ll c1=j,c2=(tot-j)-1;
                ll val=(upper_bound(all(v1),c1)-v1.begin())+
                       (upper_bound(all(v2),c2)-v2.begin());
                dp[tot][j]=max(dp[tot][j],dp[tot-1][j]+val);
            }
            res=max(res,dp[tot][j]);
            
        }v1.clear(),v2.clear();
    }

   }
   // for(auto it:dp){
   //  for(auto i:it)cout<<i<<" ";
   //      cout<<endl;
   // }
  // cout<<dp[tot][0]<<endl;
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
    
    //cin >> t;
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