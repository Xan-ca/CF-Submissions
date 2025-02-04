#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int digit_sum(ll digit){
	int res=0;
	while(digit>0){

		res+=digit%10;
		digit/=10;
	}
	return res;
}
void Solve() 
{
   ll n,q;
   cin>>n>>q;
   vector<ll>v(n);
   set<ll>st;
   for(auto &it:v)cin>>it;
   for(ll i=1;i<=n;i++)st.insert(i);
   	st.insert(n+1);
   	vector<ll>activ(n+1,0);
   while(q--){
   	int type;
      cin>>type;
      if(type==1){
        ll l,r;
        cin>>l>>r;
         for(ll i=*st.lower_bound(l);i<=r;i=*st.lower_bound(i)){
         	if(i==n+1)break;
         	 if(activ[i]<=3){
         	 	v[i-1]=digit_sum(v[i-1]);
             activ[i]++;
         }
         if(activ[i]>=3){
         	st.erase(i);
         }
          i++;
         }
      }
      else if(type==2){
      	ll pos;
      	cin>>pos;
      	cout<<v[pos-1]<<endl;
      }
   }
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