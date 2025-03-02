#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// this beautiful bs problem taught me that instead  of taking a base and incrementing greeding we choose one elemnt and check how much can we increase that element the max amount is ans
// very nice binary search <3 
// binary search oprimisation alert !! set lower bound to max(a1,a2..) and upper bound to max(a1,a2..)+n <3
// tc goes from n2 log A to n2 log n
void Solve() 
{
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    for( auto &it:v)cin>>it;
    ll mx=*max_element(all(v));

    auto cost= [&](ll index,ll increment)-> ll{
      ll cst=increment;
    for(ll i=index+1,inx=1;i<n;i++,inx++){
    	if(cst>k){
    		return INF;
    	}

         if(v[i] >= (v[index]+increment)-inx){
         	return cst;
         }else{
         	cst+=((v[index]+increment)-inx)-v[i];
         }
    }
    return INF;
    };

    for(ll i=0;i<n;i++){
     
     ll hi=mx+n+1-v[i];
     ll lo=0;
     while(hi-lo>1){
     	ll mid=(hi+lo)/2;
        if(cost(i,mid)>k){
        	hi=mid;
        }else{
        	lo=mid;
        }
     }

     mx=max(v[i]+lo,mx);
    }
    cout<<mx<<endl;
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