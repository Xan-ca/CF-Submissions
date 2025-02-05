#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>a(n),b(n);

   // ll cost1,cost2,cost3;
    ll cost311=INF,cost312=INF;
    ll cost322=INF,cost321=INF;
    for(auto &it:a)cin>>it;
    for(auto &it:b)cin>>it;
    	 if(n==1){
    	cout<<abs(a[0]-b[0])<<endl;
    	return;
    }
    for(ll i=0;i<n;i++){
    	cost311=min(cost311,abs(a[0]-b[i]));
    	cost312=min(cost312,abs(a[n-1]-b[i]));
    }
    for(ll i=0;i<n;i++){
    	cost321=min(cost321,abs(b[0]-a[i]));
    	cost322=min(cost322,abs(b[n-1]-a[i]));
    }
    ll cost3=cost311+cost312+cost321+cost322;
    ll cost21=min(abs(a[n-1]-b[n-1])+cost311+cost321,abs(a[0]-b[0])+cost312+cost322);
    ll cost22=min(abs(a[n-1]-b[0])+cost311+cost322,abs(b[n-1]-a[0])+cost312+cost321);
    ll cost2=min(cost21,cost22);
    ll cost1=min(abs(a[n-1]-b[n-1])+abs(a[0]-b[0]),abs(a[n-1]-b[0])+abs(b[n-1]-a[0]));
    
    ll res=min(cost3,min(cost2,cost1));
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