#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
   ll n,u,d;
   cin>>n>>u>>d;
   vector<ll>v(n,0);
   ll para=1;
   for(ll i=0;i<n;i++)cin>>v[i];
   	ll i,j;
   for(i=0,j=1;i<n-1;i++,j++){
   	if(v[j]>=v[i] && v[j]-v[i]<=u){
       continue;
   	}else if(v[i]>v[j] ){
   		if(v[i]-v[j]<=d)continue;
   		else if(v[i]-v[j]>d){
   			if(para==1){
   				para--;
   				continue;
   			}else break;
   		}
   	}else break;
   }
   cout<<i+1<<endl;
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