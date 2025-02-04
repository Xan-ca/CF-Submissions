#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,m;
    cin>>n>>m;
    vector<ll>v(n+m+1,0);
    vector<ll>added(n+m+1,0);
    vector<ll>removed(n+m+1,m+1);
    vector<ll>a(n+1,0);
    for(ll i=0;i<n;i++){
    	ll temp;
    	cin>>temp;
    	
    	a[i+1]=temp;

    }
    for(ll i=1;i<=m;i++){
    	ll temp2,temp;
    	cin>>temp2>>temp;
    	
    	removed[a[temp2]]=i;
        v[a[temp2]]+=removed[a[temp2]]-added[a[temp2]]; 
        added[temp]=i;           
    	a[temp2]=temp;
    	//for(auto it:a)v[it]++;
    }
    for(auto it:a)v[it]+=m+1-added[it];

    //for(auto it:v)cout<<it<<endl;
    ll res=0;
    for(ll i=1;i<n+m+1;i++){
    	if(v[i]==0)continue;

    	ll unq=m+1-v[i];
    	unq++;
    	//cout<<unq<<" "<<v[i]<<endl;

    	res+=v[i]*(unq-1);
    	res+=(v[i]*(v[i]-1))/2;
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