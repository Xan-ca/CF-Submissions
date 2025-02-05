#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,a,b;
    cin>>n>>a>>b;
    n++;
    vector<ll>v(n);
    vector<ll>av(n),bv(n);
     v[0]=0;
    for(ll i=1;i<n;i++)cin>>v[i];

    for(ll i=n-1;i>=0;i--){
        if(i==n-1){
            av[i]=0;
        }else{
            av[i]=(n-1-i)*b*(v[i+1]-v[i])+av[i+1];
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(i==n-1){
            bv[i]=0;
        }else{
            bv[i]=(b+a)*(v[i+1]-v[i])+bv[i+1];
        }
    }
    // for(auto it:av)cout<<it<<" ";
    //     cout<<endl;
    // for(auto it:bv)cout<<it<<" ";
    //     cout<<endl;
    ll cost=INF;
    for(ll i=-1;i<n;i++){
     if(i==-1){
        cost=min(cost,av[0]);
     }
     if(i==n-1){
        continue;
     }
     else{
        cost=min(cost,av[i+1]+abs(bv[i+1]-bv[0]));
     }
    }
    cout<<cost<<endl;

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