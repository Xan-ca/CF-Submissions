#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
   ll n;
    ll mod=998244353;
    cin>>n;
    vector<ll>a(n+1,0);

    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
     if(n==1){
        if(a[1]==0)cout<<2<<endl;
        else cout<<1<<endl;
        return;
    }
    vector<vector<ll>>dp(2,vector<ll>(n+1,0));
    for(ll i=1;i<=n;i++){
    	if(a[i]>=i){
    		//dp[0][i]=0;
    		dp[1][i]=dp[0][i-1];
    	}
    	if(a[i]==i-1 && i<=2){
            dp[0][i]=1;
            dp[1][i]=1;
        }
    	if(i>=2 && a[i]==a[i-1]){
            dp[0][i]+=dp[0][i-1]%mod;
        }
        if(i>=3 &&  a[i]==a[i-2]+1 ){
            dp[0][i]+=dp[1][i-1]%mod;
        }
        dp[1][i]=dp[0][i-1];

    }
    cout<<(dp[0][n]+dp[1][n])%mod<<endl; 
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