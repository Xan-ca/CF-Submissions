#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,k;
    cin>>n>>k;
    if(n==4 && k==n-1){
    	cout<<-1<<endl;
    	return;
    }
    if(k==0){
    for(ll i=0;i<n/2;i++){
    	cout<<i<<" "<<n-1-i<<endl;
    }
    return;
    }	
    
    else if(k!=n-1){
    for(ll i=0;i<n/2;i++){
    	if(i==k || i==n-1){
    		continue;
    	}
    	if(i==n-1-k || i==0){
    		continue;
    	}
    	cout<<i<<" "<<n-1-i<<endl;
    }
    cout<<k<<" "<<n-1<<endl;
    cout<<n-1-k<<" "<<0<<endl;
    return;

}
    else if(k==n-1){
    	for(ll i=0;i<n/2;i++){
    	if(i==1 || i==3 || i==0){
    		continue;
    	}
    	cout<<i<<" "<<n-1-i<<endl;
    }
    cout<<0<<" "<<n-1-3<<endl;
    cout<<1<<" "<<3<<endl;
    cout<<n-1<<" "<<n-2<<endl;
    return;

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
        //cout << "Case #" << i << ": "<<endl;
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}