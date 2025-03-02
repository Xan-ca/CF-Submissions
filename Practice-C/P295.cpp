#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,k;
    cin>>n>>k;
    vector<ll>b(n),c(n);
    ll N=1001;
    vector<int> d(1001, 1001);
    d[1] = 0;
    for (int i = 1; i < N; ++i) {
    for (int x = 1; x <= i; ++x) {
      int j = i + i / x;
      if (j < N) d[j] = min(d[j], d[i] + 1);
    }
  }
    vector<ll>cst(n+1);
    auto findcst=[](ll a)->ll{
    	ll x=log2(a);
    	ll now=pow(2,x);
    	ll moves=x;
    	while(a-now>0){
           ll div=ceil(double(now)/(a-now));
           now+=(now/div);
           moves++;
    	}
    	return moves;
    };
    ll totcost=0;
    cst[0]=0;
    for(ll i=0;i<n;i++){
      cin>>b[i];
      cst[i+1]=d[b[i]];
      totcost+=cst[i+1];
    }
    // cout<<endl;
    // for(auto it:cst)cout<<it<<" ";
    // 	cout<<endl;
    int lol=0;
    for(auto &it :c){
    	cin>>it;
    	lol+=it;
    }
    //cout<<lol<<endl;

     if(k>=totcost){
     	cout<<lol<<endl;
     	return;
     }
    vector<vector<ll>>dp(k+1,vector<ll>(n+1,0));
    dp[0][0]=0;
    for(ll i=0;i<=k;i++){
          for(ll j=1;j<=n;j++){
          	if(i>=1)dp[i][j]=max(dp[i-1][j],dp[i][j]);
          	if(j>=1)dp[i][j]=max(dp[i][j],dp[i][j-1]);
          	if(cst[j]<=i){
          		dp[i][j]=max(dp[i-cst[j]][j-1]+c[j-1],dp[i][j]);
          		
          	}
          }
    }
    // for(auto it:dp){
    // 	for(auto i:it)cout<<i<<" ";
    // 		cout<<endl;
    // }
    cout<<dp[k][n]<<endl;

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