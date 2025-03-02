#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
          #define MOD 1e9+7
vector<ll>dp(300001,0);
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
  void init(){
    dp[0]=1;
    dp[1]=1;
    for(ll i=2;i<=300000;i++){
        dp[i]=add(dp[i-1],mult((i-1)*2,dp[i-2]));
    }
  }
void Solve() 
{
    ll n,k,temp1,temp2;
    cin>>n>>k;
    for(ll i=0;i<k;i++){
      cin>>temp1>>temp2;
      if(temp1==temp2)n--;
      else n-=2;
    }
    cout<<dp[n]<<endl;
}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    ll t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
      init();
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