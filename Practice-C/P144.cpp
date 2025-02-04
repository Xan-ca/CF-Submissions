#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
void Solve() 
{
    ll n,k;
    cin>>n>>k;
    n=n%k;
    
    ll mut=__gcd(n,k);
   
    n=n/mut;
    k=k/mut;
    ll res=0;
    if(log2(k)!=ceil(log2(k))){
    		cout<<-1<<endl;
    		return;
    	}
    while(n!=0){
    
     
     long double temp=(double(k)/n);
     
     ll po=ceil(log2(temp));
    
     ll t=n;
     n*=pow(2,po);
     res+=mut*t*(pow(2,po)-1);
     n=n%k;
     ll c=__gcd(n,k);
     mut*=c;
     n=n/c;
     k=k/c;
     if(log2(k)!=ceil(log2(k))){
    		cout<<-1<<endl;
    		return;
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