#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,k,m;
    string s;
    cin>>n>>k>>m>>s;
    vector<int>vec(26,0);
    ll pc=0;
    string elem1,elem2;
    for(ll pos=0;pos<m;pos++){
      vec[s[pos]-'a']++;
        bool val=false;
      for(ll i=0;i<k;i++){
      if(vec[i]<1){
      	val=true;;
      }

      }
      if(val)continue;
       
      for(ll i=0;i<k;i++){
      vec[i]=0;
      }
      elem1+=s[pos];
            pc++;

    }
    for(ll i=0;i<k;i++){
    if(vec[i]==0){
    elem1+='a'+i;
    break;
    }
    }

    if(pc>=n){
    cout<<"YES"<<endl;
    }else{
    
    for(ll i=elem1.size();i<n;i++)elem1+='a';

    cout<<"NO"<<endl;
    cout<<elem1<<endl;
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