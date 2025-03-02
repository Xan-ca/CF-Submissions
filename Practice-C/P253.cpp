#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{    ll n ;
    cin>>n;

    vector<ll>v(n),pref(n,0),suf(n,0),mp(n+1,0);
    for(auto &it:v)cin>>it;
     if(n==1){
    	cout<<abs(v[0])<<endl;
    	return;
    }
    	if(v[n-1]<0){
    		suf[n-1]=abs(v[n-1]);
    	}else{
    		suf[n-1]=0;
    	}
    	if(v[0]>=0){
    		pref[0]=v[0];
    	}else{
    		pref[0]=0;
    	}

    for(ll i=1,j=n-2;i<n;i++,j--){
    	if(v[i]>0)
    		{
    		pref[i]+=pref[i-1]+v[i];
    		}
    	else{
            pref[i]=pref[i-1]; 
    	}
    	if(v[j]<0){
    		suf[j]+=suf[j+1]+abs(v[j]);
    	}else{
    		suf[j]=suf[j+1];
    	}
    }
    ll res=0;
    for(ll i=-1;i<n;i++){
      ll j=i+1;
      ll tres=0;
      if(i>=0){
        tres+=pref[i];
      }
      if(j<n){
      	tres+=suf[j];
      }
      res=max(tres,res);
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