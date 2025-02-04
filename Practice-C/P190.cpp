#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
  int n;
  string s;
  cin>>n;
  cin>>s;
  
  int less=0,more=0;
  //cout<<s<<endl;
  vector<ll>res;
  for(ll i=0;i<n;i++){
  	if(s[i]=='1')less+=1;
  	else more+=1;
  }
  ll end=pow(2,n);
  ll mp=pow(2,more);
  ll lp=pow(2,less);
  //cout<<mp<<" "<<lp<<endl;
  for(ll i=1,j=end;i<=end;i++,j--){
    if(i/lp>=1 && j/mp>=1){
    	res.push_back(i);
    }
  }
  for(auto it:res)cout<<it<<" ";
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
    
    //cin >> t;
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