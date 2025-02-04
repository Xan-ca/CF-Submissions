#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
  string s1,s2,rem1,rem2;
  vector<ll>arr1(26,0),arr2(26,0);
  ll n,k;
  cin>>n>>k;
  cin>>s1>>s2;

  if(n-1<k){
if(s1!=s2) cout<<"NO"<<endl;
else cout<<"YES"<<endl;
return;
  }
  if(n-1==k){
  	
  if(s1.substr(1,n-2)==s2.substr(1,n-2)){
  	
  if((s1[0]==s2[0] && s1[n-1]==s2[n-1]) || (s1[n-1]==s2[0]&& s2[n-1]==s1[0])){

   cout<<"YES"<<endl;
   return;
  }else {
  cout<<"NO"<<endl;
  return;
  }
  }else{
  cout<<"NO"<<endl;
  return;
  }

  
  }

  for(ll i=0,j=n-1;i<n;i++,j--){
  if(max(i,j)>=k+1 || (max(i,j)>=k && min(i,j)>=1)){
  arr1[s1[i]-'a']++;
  arr2[s2[i]-'a']++;
  }else{
  if(s1[i]!=s2[i]){
  	cout<<"NO"<<endl;
  return;
  }
  }
  }
   
 
  for(ll i=0;i<26;i++){
   if(arr1[i]!=arr2[i]){
   
   cout<<"NO"<<endl;
  return;
   }
  }
  cout<<"YES"<<endl;


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