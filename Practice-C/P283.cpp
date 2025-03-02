#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 //to check how many interveral a cell is a part of fo some thing like prefix array where you inc 1 when you see a start pint ande recuce 1 when you seed end point
 // for questions like how nay valid answers or how much value in a giver segment or range use prefis sum.
void Solve() 
{   ll n,m;
   cin>>n>>m;
    vector<pair<ll,ll>>v(m);
    for(ll i=0;i<m;i++){
    	cin>>v[i].first>>v[i].second;
    }
    ll k;
    cin>>k;
    vector<ll>query(k);
    for(ll i=0;i<k;i++){
    	cin>>query[i];
    }
    auto check=[&](ll query_till)->bool{
    	if(query_till==k+1) return true;
    	if(query_till==0) return false;
      vector<ll>prefix(n+1,0);
      for(ll i=0;i<query_till;i++){
        prefix[query[i]]=1;
      }
      for(ll i=1;i<=n;i++){
      	prefix[i]=prefix[i-1]+prefix[i];
      }
      for(ll i=0;i<m;i++){
        if(prefix[v[i].second]-prefix[v[i].first-1]>=(((v[i].second-v[i].first)+1)/2)+1) return true;
      }
      return false;
    };
    ll lo=0;
    ll hi=k+1;
    while(hi-lo>1){
    	ll mid=(hi+lo)/2;
    	if(check(mid)){
           hi=mid;
    	}else{
    		lo=mid;
    	}
    }
    if(hi==k+1)cout<<-1<<endl;
    else cout<<hi<<endl;
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