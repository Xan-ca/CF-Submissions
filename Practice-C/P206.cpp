#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll l,r;
    ll g;
    cin>>l>>r>>g;
    ll lr,gr;
   if(l%g==0)lr=l/g;
   else lr=(l/g)+1;
     gr=r/g;
    if(lr>gr){
    	 cout<<-1<<" "<<-1<<endl;
    	 return;
    }
    if(lr==gr){
     if(__gcd<ll>(lr,gr)==1){

      cout<<lr*g<<" "<<gr*g<<endl;
     return;
 }
    }
   else  if(__gcd<ll>(lr,gr)==1){
       cout<<lr*g<<" "<<gr*g<<endl;
         return;
    }else if(__gcd<ll>(lr,gr-1)==1){
        cout<<lr*g<<" "<<(gr-1)*g<<endl;
          return;
    }else if(__gcd<ll>(lr+1,gr)==1){
        cout<<(lr+1)*g<<" "<<gr*g<<endl;
          return;
    }else if(gr-lr>1 && __gcd<ll>(lr+1,gr-1)==1){
         cout<<((lr+1)*g)<<" "<<(gr-1)*g<<endl;
           return;
    }
    cout<<-1<<" "<<-1<<endl;

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