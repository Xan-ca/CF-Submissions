#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
ll n,m;
cin>>n>>m;
priority_queue<ll>a;
priority_queue<ll>b;
for(ll i=0;i<n;i++){
ll temp;
cin>>temp;
a.push(temp);
}
for(ll i=0;i<m;i++){
ll temp;
cin>>temp;
b.push(temp);
}
while((a.size()>0 && b.size()>0 )&&a.size()>=b.size()){
if(a.top()==b.top()){
	a.pop();
	b.pop();
}
else{
	if(b.top()>a.top()){
	if(b.top()%2==0){
	
	ll temp=(b.top()/2);
	b.pop();
	b.push(temp);
	b.push(temp);
	}else{
	
	ll temp=b.top()/2;
	b.pop();
	b.push(temp);
	b.push(temp+1);
	}
	}else{
	cout<<"NO"<<endl;
	return;
	}
}
}
if(a.size()==0 && b.size()==0){
cout<<"YES"<<endl;
return;
}
cout<<"NO"<<endl;
    
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