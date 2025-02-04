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
    for(auto &it:v)cin>>it;
    sort(v.begin(),v.end());
    ll combo=0,res=0;
    for(ll i=0,j=n-1;i<n;){
    	 if(i==j){
           
           res+= (v[i]-combo)/2;
           
           
           res+=(v[i]-combo)%2;
           combo+=(v[i]-combo)/2;
        
           if(combo>0)res++;
           break;
        }
        if(combo+v[i]<=v[j]){
           
        	combo+=v[i];
            res+=v[i];
        	v[i]=0;
        	i++;
        }
        else{
            res+=v[j]-combo;
        	v[i]-=v[j]-combo;
        	combo=v[j];
        }
        if(i==j){
           
           res+= (v[i]-combo)/2;
           
           
           res+=(v[i]-combo)%2;
           combo+=(v[i]-combo)/2;
        
           if(combo>0)res++;
           break;
        }
        
    	if(combo==v[j]){
    		v[j]=0;
            res++;
    		j--;
    		combo=0;
    	}
    }
    cout<<res<<endl;

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