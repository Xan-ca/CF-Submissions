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
    vector<pair<ll,ll>>v(n);
    for(ll i=0;i<n;i++)cin>>v[i].first>>v[i].second;

    auto check=[&](ll num)->bool{
    	//if(num==n+1)return false;
    	ll cnt=0;
    	ll ahead=num-1;
    	ll behind=0;
        for(ll i=0;i<n;i++){
           if(v[i].first>=ahead && v[i].second>=behind){
                ahead--;
                behind++;
                cnt++;
           }
        }
        //cout<<"count:"<<cnt<<endl;
        return cnt>=num;
    };
    ll lo=0;
    ll hi=n+1;
    while(hi-lo>1){
    	ll mid=(lo+hi)/2;
    	//cout<<mid<<endl;
    	if(check(mid)){
             lo=mid;
    	}else{
             hi=mid;
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