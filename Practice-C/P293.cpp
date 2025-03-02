#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define szinput(x) for(auto &it: x)cin>>it;
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 // n-1/2 disjoints pairs
 // each pairs is swapped except one 
 // return the element not swapped 
 //  
void Solve() 
{
    ll n;
    cin>>n;
    ll lo=1;
    ll hi=n;
    auto check=[&](ll l ,ll r)->bool{
    	vector<ll>arr(r-l+1);
    	for(auto &it:arr)cin>>it;
        ll a=arr.end()-lower_bound(arr.begin(), arr.end(), l);
        ll b=arr.end()-lower_bound(arr.begin(), arr.end(), r+1);
        return((a-b)%2==1);
    };
    ll res=0;
    while(hi>lo){
       ll mid=(hi+lo)/2;
       cout<<"? "<<lo<<" "<<mid<<endl;
       cout<<flush;

       if(check(lo,mid)){
          hi=mid;
          res=mid;
       }else{
          lo=mid+1;
          res=mid+1;
       } 
    }
    cout<<"!"<<" "<<res<<endl;
    return;

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