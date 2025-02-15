#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    ll s1,s2;
    cin>>n>>s1>>s2;
    vector<pair<ll,ll>>freq(n);
    for(ll i=0;i<n;i++){
    	ll temp;
    	cin>>temp;
    	freq[i]={temp,i+1};
}
vector<ll>v1,v2;
    sort(freq.begin(),freq.end());
    reverse(freq.begin(),freq.end());
    ll time1=s1,time2=s2;
    for(auto it :freq){
    	if(time1<=time2){
    		v1.push_back(it.second);
    		time1+=s1;
    	}else{
    		v2.push_back(it.second);
    		time2+=s2;
    	}
    }
    
    cout<<v1.size()<<" ";
    for(auto it:v1)cout<<it<<" ";
    	cout<<endl;
    cout<<v2.size()<<" ";
    for(auto it:v2)cout<<it<<" ";
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