#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
vector<ll>sq(100002,0);
 void init(){
   for(ll i=1;i<=100001;i++){
   sq[i]=pow(i,2);
   }
 }
void Solve() 
{  
    ll r;
    cin>>r;
    ll res=0;
    for(ll i=0;i<=r;i++){
          ll lo=0;
          ll hi=r+1;
          while(hi-lo>1){
          	ll mid=(lo+hi)/2;
          	if(sq[i]+sq[mid]<sq[r]){
          		lo=mid;
          	}else{
          		hi=mid;
          	}
          }
          res-=lo;
    }
    r++;
    for(ll i=0;i<=r;i++){
          ll lo=0;
          ll hi=r+1;
          while(hi-lo>1){
          	ll mid=(lo+hi)/2;
          	if(sq[i]+sq[mid]<sq[r]){
          		lo=mid;
          	}else{
          		hi=mid;
          	}
          }
          res+=lo;
    }
    cout<<res*4<<endl;
}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
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