#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n=0;
    cin>>n;
   // cout<<n<<endl;
    vector<ll>v(n,0);
    multiset<ll>st;
    for(ll i=0;i<n;i++)cin>>v[i];
    // for(auto it: v)cout<<it<<" ";
    // cout<<endl;
    for(auto it: v)st.insert(it);
    sort(all(v));
   auto findLowerElement=[&](ll target)-> ll{
    auto it = st.lower_bound(target); 
    if (it == st.begin()) {
        return INF;  
    }
    ll ret=*std::prev(it);
    st.erase(st.find(*std::prev(it)));
    return ret;
};
 ll sum=0;
  ll bound=v[n-1]-v[0];
  if(bound==0){
  	cout<<"NO"<<endl;
  	return;
  }
  vector<ll>res;
    for(ll i=0;i<n;i++){
    ll elem=findLowerElement(bound-sum);
    if(elem!=INF) res.push_back(elem);
    sum+=elem;
    }
    cout<<"YES"<<endl;
    for(auto it: res)cout<<it<<" ";
    cout<<endl;
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