#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define sqrt(x) static_cast<long long>(sqrt(x));


void Solve() 
{
    ll pos,k;
    cin>>pos>>k;
    ll a=pos-k;
    ll b=pos+(k-2);
    ll res=0;
    ll sqa=sqrt(a);
    ll sqb=sqrt(b);
    map<ll,ll>mp;
    auto check = [&](ll a){
       return(((a+2)/2)>=k);
    };
    for(ll i=1;i<=sqa;i++){
     if(a%i !=0)continue;
    	if(i%2==0 && check(i))mp[i]=i;
    		if((a/i)%2==0 && check(a/i))mp[a/i]=i;
    		
    	}
    if(a==b){
    	cout<<mp.size()<<endl;
    	return;
    };
    a=b;
     for(ll i=1;i<=sqa;i++){
     if(a%i !=0)continue;
    	if(i%2==0 && check(i))mp[i]=i;
    		if((a/i)%2==0 && check(a/i))mp[a/i]=i;
    		
    	}
    
    cout<<mp.size()<<endl;
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