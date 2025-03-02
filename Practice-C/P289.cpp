#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
	ll n,k;
	cin>>n>>k;
	vector<ll>v(n);
	vector<ll>penals;
	string s;
	cin>>s;
	for(auto &it:v)cin>>it;
   ll start=0,end=n-1;
   while(start<n && s[start]=='R')start++;
   while(end>=0 && s[end]=='R')end--;
   if(end==-1){
   	cout<<0<<endl;
   	return;
   }
   ll sum=0;
   for(ll i=start+1;i<=end;i++){
     if(s[i]=='R'){
     	sum+=v[i];
     }
     if(s[i]=='B' && s[i-1]=='R'){
       if(sum>0) penals.push_back(sum);
        sum=0;
     }
   }
   vector<ll>nonpenals;
   sum=0;
   for(ll i=start;i<=end;i++){
     if(s[i]=='B'){
     	sum+=v[i];
     }
     else{
     	if(sum>0) penals.push_back(sum);
        sum=0;
     }
   }

   
   sort(all(penals));
   sort(all(nonpenals));
   auto check=[&](ll penalty)->bool{
   	ll tot=0;
   	ll moves=penals.size()+1;
   	for(ll i=0;i<penals.size();i++){
   		if(tot+penals[i]<=penalty)moves--;
   			else break;
   	}
   	return(moves<=k);
   };
   ll lo=-1,hi=1e9;
   while(hi-lo>1){
   	ll mid=(hi+lo)/2;
      if(check(mid)){
      	hi=mid;
      }else{
      	lo=mid;
      }
   }
   cout<<hi<<endl;


    
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
       // cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}