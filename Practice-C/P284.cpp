#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 vector<vector<ll>>sqsum(2024,vector<ll>(2024,0));
 void init(){
 	ll k=1;
 	for(ll i=1;i<=2023;i++){
 		for(ll j=1;j<=i;j++){
          sqsum[i][j]=k*k;
          k++;
 		}
 	}
 	for(ll i=1;i<=2023;i++){
 		for(ll j=1;j<=2023;j++){
          sqsum[i][j]+=sqsum[i][j-1];
 		}
 	}
 }
void Solve() 
{
    ll n;
    cin>>n;
    ll r=1,c=1;
    for(ll i=1;i<=n;i++){
       if(n-i>0){
       	r++;
       	n-=i;
       	c=n;
       }else break;
    }
    ll res=0;
    for(ll r1=r,c1=c, r2=r,c2=c; ; r1--,c1-- , r2--){
    	if((r1<1 && c1<r)&&(r2<1))break;
        ll end=sqsum[r2][c2];
        ll start=(r1 <=0 || c1-1<=0) ? 0 : sqsum[r1][c1-1];
        res+=end-start;
    }
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
    
    cin >> t;
    init();
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