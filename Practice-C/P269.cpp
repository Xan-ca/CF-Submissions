#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    ll sum=0;
    for(ll i=n,j=(2*n)-1;i>0;i--,j-=2){
       sum+=i*j;
    }
    cout<<sum<<" "<<2*n<<endl;
    for(ll i=1;i<=2*n;i++){
        if(i%2==1){
            cout<<1<<" "<<n-(i/2)<<" ";
            for(ll i=n;i>=1;i--)cout<<i<<" ";
                cout<<endl;
        }
        if(i%2==0){
            cout<<2<<" "<<i/2<<" ";
            for(ll i=1;i<=n;i++)cout<<i<<" ";
                cout<<endl;
        }
    }

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