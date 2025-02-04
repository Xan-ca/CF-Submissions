#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{ll n,k;
cin>>n>>k;
vector<ll>a(n),b;
for(auto &it:a)cin>>it;
if(n==k){
for(ll i=0;i<n;i++){
	if(i%2==1){
		b.push_back(a[i]);
	}
}

for(ll i=0;i<b.size();i++){
	if(i+1!=b[i]){
		cout<<i+1<<endl;
		return;
	}

}
cout<<b.size()+1<<endl;
return;
}
if(n>k){
ll choice=n-k+1;
//cout<<choice<<endl;
for(ll i=1;i<=choice;i++){
	if(a[i]!=1){
		cout<<1<<endl;
		return;
	}
}
cout<<2<<endl;
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
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}