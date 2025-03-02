#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    string s;
    cin>>s;
    vector<ll>v(10,0);
    for(ll i=s.size()-1;i>=0;i--){
   
      v[s[i]-'0']++;
    }
    vector<ll>v2(10,0);
    for(ll i=s.size()-1;i>=0;i--){
   
      v2[s[i]-'0']++;
    }

    string res;
    vector<ll>r;
    ll k=0;
    ll i=0;
      for(ll i=0;i<s.size();i++){
        while(k<10 && v[k]==0)k++;
        if(k==10)break;
        v[s[i]-'0']--;
        if(s[i]-'0'==k){
           v2[k]--;
           res+=(s[i]);
        }
      }
     for(ll i=0;i<10;i++){
      while(v2[i]!=0) {
        r.push_back(min(i+1,9ll));
        v2[i]--;
    }
     }
     for(ll i=0;i<res.size();i++){
        r.push_back(res[i]-'0');
     }
    sort(r.begin(),r.end());
    for(auto it:r)cout<<it;
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