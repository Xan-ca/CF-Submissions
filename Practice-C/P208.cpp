#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,exor=0,oxor=0;
    cin>>n;
    for(ll i=0;i<n;i++){
    	if(i%2==0){exor^=i;}
    	else {oxor^=i;}
    }
    if(exor==oxor){
    for(ll i=0;i<n;i++){
    	cout<<i<<" ";
    }
    cout<<endl;	
    //cout<<exor<<" "<<oxor<<endl;
    return;	
    }
    else{
    	ll x=0;
    	for(ll i=1;i<n;i+=2){

    		ll z=oxor^i;
    		
    	if(z!=exor){
    		//cout<<"hi"<<endl;
    		x=i;
    		oxor^=i;
    		break;
    	}
    }
    //cout<<x<<endl;
    //cout<<oxor<<" "<<exor<<endl;
    ll big=pow(2,31)-1;
     ll ab=exor^big;
     ll bb=oxor^big;
    
     
     for(ll i=0;i<n;i++){
     	if(i==0){
          cout<<ab<<" ";
     		continue;
     	}
     	else if(i==x){
     		cout<<bb<<" ";
     		continue;
     	}
     	else cout<<i<<" ";

     }
     cout<<endl;
     
    }
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