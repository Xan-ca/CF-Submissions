#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,m,k;
    cin>>n>>m>>k;
    string res;
    if(max(n,m)-min(n,m)>k){
    cout<<-1<<endl;
    return;
    }
    if(max(n,m)<k){
    cout<<-1<<endl;
    return;
    }
    
    ll z=n+m;
    ll mx=max(n,m);
    ll mn=min(n,m);
    if(n>m){
    	for(ll i=0;i<z;i++){
    	for(ll i1=0;i1<min(n,k);i1++)res+='0';
    		n-=min(n,k);
    	for(ll i1=0;i1<min(m,k);i1++)res+='1';
    		m-=min(m,k);
    }
}else{
	for(ll i=0;i<z;i++){
		for(ll i1=0;i1<min(m,k);i1++)res+='1';
    		m-=min(m,k);
    	//cout<<m<<endl;
    	for(ll i1=0;i1<min(n,k);i1++)res+='0';
    		n-=min(n,k);
    	//cout<<n<<endl;
    	
}
}
    
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