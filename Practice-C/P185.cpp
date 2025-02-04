#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,k;
    cin>>n>>k;
    ll curr=1,red=0;
    vector<ll>res;
    ll sum=0;

    for(ll i=1;i<=n;i++){
        curr=((i+1)*i)/2;
        if(curr>k){
            //cout<<curr<<endl;
            k=(k)-((i-1)*i)/2;
           // cout<<k<<endl;
            ll rem=res.size()-k;
            res.push_back(-(rem*2)-1);
           k=0; 
        }else res.push_back(2);
      
    }
    for(auto it:res)cout<<it<<" ";
    cout<<endl;
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