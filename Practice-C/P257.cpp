#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 /*we can prefix sum to get the sum of the k valuse between two numbers
 we can also do dp  and two pointer 
 enjoyed it the idea came to mind when some one mentioned two pinter the idea is 
 lets fix i and see how first the first valid segement goes the we know after that segment we get zero 
 and after that segment we can start over again now if so for a given i the solution is no of segemnet starting from i
 + no of segment starting from the loactation it starts over again
 another way which is less impl heavy is to binary search till the point you can eat for first segment instead of doing two pointer
 a lot of time finding ranges using two pointer can be replace swith binary search if they have a mono tonic property like prfix suffix sum etc
 
 */
void Solve() 
{
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    vector<ll>prefix(n+1);
    prefix[0]=0;
    vector<pair<ll,ll>>dp(n+1,{0,0});
    for(ll i=0;i<n;i++){
    
    cin>>v[i];
   // if(i==0)prefix[1]=v[1];
    prefix[i+1]=prefix[i]+v[i];
    }
    
    for(ll i=1,j=1;i;i){
    	
       while(prefix[j]-prefix[i-1]<=k && j<=n){
       if(j<=n)j++;
       }
       if(j<i)j=i;
       dp[i].first=j;
       dp[i].second=(j-i);
       if(i<=n)i++;
       if(i>n)break;
    }

    for(ll i=n;i>=1;i--){
    	if(dp[i].first>=n){
    		dp[i].second+=0;
    	}else{
    		dp[i].second+=dp[dp[i].first+1].second;
    	}
    }
   
    	ll res=0;
    for(auto it:dp)res+=it.second;
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