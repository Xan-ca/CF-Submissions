#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 		 #define MOD 998244353
/*for each additional 2 check how it increases the no of subsequences it will give no of subsequence before that and an addittional 1 increase*/
 ll add(ll a, ll b, ll m = MOD)
  {
      a+=b;
      if(abs(a)>=m) a%=m;
      if(a<0) a+=m;
      return a;
  }
  ll mult(ll a, ll b, ll m = MOD)
  {
      if(abs(a)>=m) a%=m;
      if(abs(b)>=m) b%=m;
      a*=b;
      if(abs(a)>=m) a%=m;
      if(a<0) a+=m;
      return a;
  }
  void radd(ll &a, ll b, ll m = MOD){ a=add(a,b,m); }
  void rmult(ll &a, ll b, ll m = MOD){ a=mult(a,b,m); }
  ll pw(ll a, ll b, ll m = MOD)
  {
      assert(b >= 0);  // can return 0 if desired
      if(abs(a)>=m) a%=m;
      if(a==0 && b==0) return 0; // value of 0^0
      ll r=1;
      while(b){
          if(b&1) r=mult(r,a,m);
          a=mult(a,a,m);
          b>>=1;
      }
      return r;
  }
  ll inverse(ll a, ll m = MOD)
  {
      return pw(a,m-2,m);
  }
void Solve() 
{
    ll n=0;
    cin>>n;
    vector<ll>v(n),dp(n+1,0);
    for(auto &it:v)cin>>it;
   
   ll inc=0;
ll res=0;
    for(ll i=n-1;i>=0;i--){
    	  dp[i]=dp[i+1];
    	if(i!=n-1 && v[i]==2){
          dp[i]=add(dp[i+1],inc);
          dp[i]=add(dp[i+1],dp[i]);
    	}
    	if(v[i]==3){
          inc++;
    	}
    	if(v[i]==1){
           res=add(res,dp[i]);
    	}
    }
    for(ll i=0;i<n;i++){

    }
    ll md=MOD;
    cout<<res%md<<endl;
    
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