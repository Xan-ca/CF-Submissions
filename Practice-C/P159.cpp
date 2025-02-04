#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool isvalid(vector<ll>&sum,ll mid,ll l,ll u){
	if(sum[mid]-sum[l-1]>u+1){
		ll k=u-(sum[mid-1]-sum[l-1]);
		if(k<=0){
			return 1;
		}
		ll reduc=sum[mid]-sum[mid-1];
		ll k2=k-reduc+1;
		if(k+k2>0){
			return 0;
		}
		else{
			return 1;
		}
	}else{
		return 0;
	}
}
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++){
    cin>>v[i];
    }
    vector<ll>sum(n+1,0);
    sum[0]=0;
    for(ll i=1;i<=n;i++){
    sum[i]+=sum[i-1]+v[i-1];
    }
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++){
    ll u,l;
    cin>>l>>u;
    ll lo=l;
    ll hi=n+1;
    while(hi-lo>1){
    ll mid=(lo+hi)/2;

    if(isvalid(sum,mid,l,u)){
     hi=mid;
    }else{
     lo=mid;
    }

    }
    if(sum[lo]-sum[l-1]==u+1 && v[lo-1]==1){
    	cout<<lo-1<<" ";
    }else{
    cout<<lo<<" ";
    }
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