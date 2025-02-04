#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
//two pointer rules if you want all the pairs above or below or equal to certainvale just two pinter the bitch
 
//we can simlify the problem by just adding individual contribution of each elemnt then check for their remainders with two pointer
void Solve() 
{
    ll n,k;
    cin>>n>>k;
    ll res=0;
   // cout<<"ji";
    vector<ll>mp(k+10,0);
    vector<ll>v(n),l(n);
    for(auto &it:v)cin>>it;
    for(ll i=0;i<n;i++){
    	res+=v[i]/k;
    	l[i]=v[i]%k;
    }
    sort(l.begin(),l.end());
    for(ll i=0,j=n-1;i<j;){
    	if(l[i]+l[j]>=k){
    		res+=1;
    		i++;
    		j--;
    	}else{
    		i++;
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