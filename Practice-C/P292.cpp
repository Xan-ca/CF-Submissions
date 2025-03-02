#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define szinput(x) for(auto &it: x)cin>>it;
#define forn(i,start,n) for(ll i=start;i<n;i++)
#define all(x) (x).begin(), (x).end()
#define double long double
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>pos;
    vector<ll>t;
    vector<pair<ll,ll>>inp(n);
     map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        cin>>inp[i].first;
        mp[inp[i].first]=0;
    }
    for(ll i=0;i<n;i++)cin>>inp[i].second;  
    sort(all(inp));
   
    for(auto it:inp){
        mp[it.first]=max(mp[it.first],it.second);
    }
    for(auto it:mp){
        pos.push_back(it.first);
        t.push_back(it.second);
    }
    n=pos.size();
    
    
        vector<ll>prefix(n);
    vector<ll>suffix(n);
    prefix[0]=t[0];
    suffix[n-1]=t[n-1];
    for(ll i=1;i<n;i++){
    	prefix[i]=max(t[i],prefix[i-1]+pos[i]-pos[i-1]);
    }
    for(ll i=n-2;i>=0;i--){
    	suffix[i]=max(t[i],suffix[i+1]+abs(pos[i]-pos[i+1]));
    }

    auto find_min=[&](ll a, ll b,ll st, ll dist)->pair< double, double>{

    	double ad=a;
    	double bd=b;
    	double dis=dist;
    	double start=st;
        if(a+dist<=b){
            return{b,start+dis};
        }
        if(b+dist<=a){
            return{a,start};
        }
    	double mid= ((bd-ad)+dis)/2;
        return {ad+mid,st+mid};
    };
    double local_min,glb_min=10000000000;
    double res;
    for(ll i=-1;i<n;i++){
      if(i==-1){
          local_min=suffix[i+1];
          if(local_min<glb_min){
          	glb_min=min(local_min,glb_min);
          	res=pos[i+1];
          }
      }
      else if(i==n-1){
           local_min=prefix[i];
           if(local_min<glb_min){
          	glb_min=min(local_min,glb_min);
          	res=pos[i];
          }
      }else{
           pair<double,double>p=find_min(prefix[i],suffix[i+1],pos[i],pos[i+1]-pos[i]);
           //cout<<p.first<<" "<<p.second<<endl;
           if(p.first<glb_min){
           	glb_min=min(p.first,glb_min);
          	res=p.second;
           }

      }
      

    }
     
    //cout<<glb_min<<endl;
    cout<<setprecision(10)<<res<<endl;

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
      //  cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}