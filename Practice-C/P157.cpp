#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll k, n,q;
    cin>>k>>n>>q;
    vector<ll>dis(n+1,0);
    vector<ll>tim(n+1,0);

    for(ll i=1;i<n+1;i++)cin>>dis[i];
    for(ll i=1;i<n+1;i++)cin>>tim[i];
    while(q--){
        ll querdis;
        cin>>querdis;
        auto pos=lower_bound(dis.begin(),dis.end(),querdis);
        ll idx =pos-dis.begin();
        if(dis[idx]==querdis){
            cout<<tim[idx]<<" ";
            continue;
        }
        double speed=double(dis[idx]-dis[idx-1])/double(tim[idx]-tim[idx-1]);
        ll res=tim[idx-1]+(double(querdis-dis[idx-1])/speed);
        cout<<res<<" ";
    }
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