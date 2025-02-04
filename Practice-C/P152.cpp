#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define MOD 1e9+7
 vector<ll> fact,ifact,inv,pow2;
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
 ll nCr(ll a, ll b, ll m = MOD)
 {
     if(a<b) return 0;
     if(b==0) return 1;
     if(a==b) return 1;
     return mult(fact[a], mult(ifact[b], ifact[a - b], m), m);
 }
 void init(ll _n, ll m = MOD)
 {
     fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
     fact.resize(_n+1); ifact.resize(_n+1); inv.resize(_n+1); pow2.resize(_n+1);
     pow2[0]=1; ifact[0]=1; fact[0]=1;
     for(int i=1;i<=_n;i++){
         pow2[i] = add(pow2[i - 1], pow2[i - 1], m);
         fact[i] = mult(fact[i - 1], i, m);
     }
     ifact[_n] = inverse(fact[_n], m);
     for(int i=_n-1;i>=1;i--){
         ifact[i] = mult(ifact[i + 1], i + 1, m);
     }
     for(int i=1;i<=_n;i++){
         inv[i] = mult(fact[i - 1], ifact[i], m);
     }
 } 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
   ll n,k;
   cin>>n>>k;
   ll zero=0,one=0;
   for(ll i=0;i<n;i++){
   	ll temp;
   	cin>>temp;
   	if(temp==0)zero++;
   	else one ++;
   } 
   ll l=(k/2);
   ll res=0;
   ll m=MOD;
   for(ll i=0;i<=l;i++){
      res+=mult(nCr(zero,i),nCr(one,k-i))%m;
   }
   cout<<res%m<<endl;
}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    init(200000);
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