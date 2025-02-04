#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 bool is(string a,string b){
 	ll i=0,j=0;
  for(i=0,j=0;j<b.size()&& i<a.size();j++){
    if(a[i]==b[j])i++;
    if(i==a.size())break;
  }

  if(i==a.size())return true;
  else return false;
 }
void Solve() 
{ string a,b;
  cin>>a>>b; 

  if(is(a,b)|| is(b,a))cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return;
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