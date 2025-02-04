#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define MOD  998244353

vector<ll>pow2;
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


void init(ll _n, ll m = MOD)
{
    pow2.clear();
     pow2.resize(_n+1);
    pow2[0]=1;
    for(int i=1;i<=_n;i++){
        pow2[i] = add(pow2[i - 1], pow2[i - 1], m);
        
    }
    
}


mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
	ll n;
	cin>>n;
	vector<ll>v(n);
	vector<ll>dp(n,0);
	
	for(auto &it:v)cin>>it;
	for(ll i=1;i<=n;i++){
       for(ll j=i-1;j<n;j+=i){
       	dp[i-1]=max(dp[i-1],v[j]);
       }
	}
        
	sort(dp.begin(),dp.end());

	
	ll res=0;
	for(ll i=0;i<n;i++){
	
     res+=pow2[i]*dp[i];
     res%=MOD;
	}
	cout<<res<<endl;
	return;
    
}
 
int32_t main() 
{   
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    init(100000,MOD);
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