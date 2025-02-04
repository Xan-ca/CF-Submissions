#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
   ll n,k;
   cin>>n>>k;
   string s;
   cin>>s;
   ll i=0;
   int mx=0;
   while(k>0 && i<=n){
   // break;
   for(i;i<n;i++){
   	if(s[i]-'a'<=k){
   		mx=max(s[i]-'a',mx);
   		continue;
   	}else if(s[i]-'a'>k) {
   		for(ll j=0;j<n;j++){
   			if(s[j]-'a'<=mx){
   		      s[j]='a';
        	}}

           // break;
        ll nmx=s[i]-'a';
        k-=mx;
        char c=nmx-k+'a';
        k=0;
        for(i;i<n;i++ ){
            if(s[i]-'a'<=nmx && s[i]-'a'>c-'a'){
              s[i]=c;
            }
        }
        
   		}
   	}
    if(i==n){
    for(ll j=0;j<n;j++){
            if(s[j]-'a'<=mx){
              s[j]='a';
            }
            i++;
            k=0;
   } 
}
   }
   cout<<s<<endl;
   
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