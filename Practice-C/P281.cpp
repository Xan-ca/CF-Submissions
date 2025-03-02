#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// this problem teches us that pro a string we can find the min char of any substr in o(26) using prefix sum
// another great idea is to implement a stack to get the guaranteed order
void Solve() 
{
   string s;
   cin>>s;
   ll n;
   cin>>n;

  ll remove=0;
   vector<vector<ll>>pref(s.size()+1,vector<ll>(26,0));

   for(ll i=1;i<=s.size();i++){
   	pref[i]=pref[i-1];
   	pref[i][s[i-1]-'a']++;
   }
   auto query = [&](ll start, ll end)->char{
      for(ll i=0;i<26;i++){
      	if(pref[end][i]-pref[start][i]>0)return ('a'+i);
      }
      return '0';
   };
  ll f=s.size();
   for(ll i=f;i>=0;i--){
   
   	if(n > i){

   		remove++;

   		n-= i;
   	}else break;
   }

    string res="";

   for(ll i=0;i<s.size();){
   	  ll j=i+remove;

   	  if( j>=s.size())break;
   	   
        res+=query(i,j+1);

        for(i ; i<s.size() && s[i]!=res.back() ; i++){
        	remove--;
        }
        i++;

       j=i+remove;

   	  if( j>=s.size())break;

   }
   cout<<res[n-1];
  
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