#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 /*fuck all the stupid thought this copy is just car salesman idea which i dont understand 
 the idea check if grouping of unique elements are possible to grough them into decks of same size
 for given size for different unique elements */
void Solve() 
{
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n),nv;
    ll res=0;
    ll maxi=0;
    for(auto &it:v){
    	cin>>it;
    	res+=it;
    	maxi=max(maxi,it);
    }
    //cout<<res<<endl;
    ll lo=0;
    ll hi=n+1;
   for(ll i=1;i<=n;i++){
   	if(res<(i*maxi)){
           if(res+k>=i*maxi){
           	lo=i;
           }
    	}
    if(res==maxi*i){
    	lo =i;
    }
    if(res>maxi*i ){
    	ll rem=res%(i);

        if(k+rem>=i || rem==0){
        	lo=i;
        }
    }
   
   }
    	
    cout<<lo<<endl;
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