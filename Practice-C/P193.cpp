#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,h;
    cin>>n>>h;
    vector<ll>v(n);
    for(auto &it:v)cin>>it;
    sort(v.begin(),v.end());
    ll gs=2,bs=1;
    ll i=0;
    for(i=0;i<n;i++){
    if(h>v[i])h+=v[i]/2;
    else if(h*2>v[i] && gs>0){
    	h*=2;
     gs--;
     h+=v[i]/2;
    }else if(h*3>v[i] && bs>0){
    	h*=3;
     bs--;
     h+=v[i]/2;
    }else if(h*4>v[i] && gs>1){
    	h*=3;
   gs--;
   gs--;
   h+=v[i]/2;
    }
    else if(h*6>v[i] && (bs>0 && gs>0)){
    	h*=6;
bs--;
gs--;
h+=v[i]/2;
    }else if(h*12>v[i] &&(bs>0 && gs>1)){
    	h*=12;
gs=0;
bs=0;
h+=v[i]/2;
    }else break;
    }
    cout<<i<<endl;
    if(bs>0)h=h*3;
    if(gs>1)h=h*4;
    else if(gs>0)h=h*2;
    
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