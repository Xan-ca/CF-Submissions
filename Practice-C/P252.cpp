#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    vector<ll>c(n);
    vector<pair<ll,ll>>res;
    for(auto &it:v)cin>>it;
    for(ll i=0;i<n;i++)c[i]=v[i];
    vector<ll>cnt(3,0);
    for(auto it:v)cnt[it]++;
    ll pos1=0;
    while(v[pos1]!=1)pos1++;
    for(ll i=0,j=cnt[0]+cnt[1];j<n && i<n ;j++){
    while(v[i]!=2 && i<cnt[0]+cnt[1])i++;
    if(v[j]==2 || v[j]==0)continue;
    if(v[j]==1){
    swap(v[i],v[j]);
    res.push_back({i,j});
    pos1=i;
    }
    }
    for(ll i=0,j=cnt[0]+cnt[1];j<n && i<n ;j++){
    while(v[i]!=2 && i<cnt[0]+cnt[1])i++;
    if(v[j]==2 || v[j]==1)continue;
    
    if(v[j]==0){
    swap(v[pos1],v[j]);
    res.push_back({pos1,j});
    swap(v[i],v[j]);
    res.push_back({i,j});
    pos1=i;
    }
    }



    for(ll i=0,j=cnt[0];j<cnt[0]+cnt[1];j++){
        while(v[i]!=1 && i<cnt[0])i++;
        if(v[j]==1)continue;
        if(v[j]==0){
           swap(v[i],v[j]);
           res.push_back({i,j});
        }
    }

    cout<<res.size()<<endl;
    for(auto it:res)cout<<it.first+1<<" "<<it.second+1<<endl;
        
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