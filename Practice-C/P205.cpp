#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
   ll n,m;
   cin>>n>>m;
   ll k;
   cin>>k;
   vector<ll>v(k);
   for(ll i=0;i<k;i++){
   	cin>>v[i];
   } 
   set<ll>st;
   ll stsize=n*m-3;
   ll i=k,j=0;
   while(i>=0){
   	
      if(st.size()>=stsize)break;
      if(i==v[j]){
      	j++;
      	i--;
      }
      else{
      	st.insert(v[j]);
      	j++;
      }
      if(j==k|| i==0)break;
      while(st.find(i)!=st.end()){
   		
   		st.erase(i);
         //cout<<st.size();
   		i--;
   		if( i==0)break;
   	}
   }
  while(st.find(i)!=st.end()){
         
         st.erase(i);
         i--;
         if( i==0)break;
      }
   if(i==0)cout<<"YA"<<endl;
  else  cout<<"TIDAK"<<endl;

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