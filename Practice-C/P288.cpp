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
   string s;
   cin>>s;
   vector<ll>v,vi(n);
   for(auto &it:vi)cin>>it;

   ll start=0,end=n-1;
   while(start<n && s[start]=='R')start++;
   while(end>=0 && s[end]=='R')end--;
   if(end==-1)
   {
   cout<<0<<endl;
   return;
   }
   ll sum=0;
   for(ll i=start;i<=end;i++){
   if(sum>0 && s[i]=='B'){
   v.push_back(sum);
   sum=0; 
   }
     if(s[i]=='R'){
     sum+=vi[i];
     }else{
     sum+=0;
     }
   }
   for(auto it:v)cout<<it<<" ";
    cout<<endl;

   sort(all(v));
   auto check=[&](ll penalty)->bool{
    ll sumi=0;
    ll moves=v.size()+1;
    if(v.size()==0)moves=1;
    for(ll i=0;i<v.size();i++){
    sumi+=v[i];
    if(sumi<=penalty)moves--;
    else break;
    }
    return (moves<=k);
    };
   ll lo=0;
   ll hi=1e9;
   while(lo-hi>1){
   ll mid=(lo+hi)/2;
     if(check(mid)){
       hi=mid;
     }else {
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
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}
   