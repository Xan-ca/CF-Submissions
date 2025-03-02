#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 /* there is one obvious observation if we romove elements from begin if element affects the ans its zero else its one 
 .now the other obs is that if we rome a elements that make the reamining sub array give value as zero that means there are no 1 succeding a zero 
 . removing that element tells us how many one there are ahead of it if it affects the answer now it we know no of 1s ahead of it and we now there are no 1 succeding a zero we can figure out the structur eof the binary string*/
void Solve() 
{
    ll n;
    cin>>n;
    ll val,preval;
    ll zeros=0,ones=0;
    string s;
    for(ll i=1;i<=n-1;i++){
     cout<<"? "<<i<<" "<<n<<endl;
     cout<<flush;
     cin>>val;
     if(i==1)
     {
       if(i==n-1 && val==1){
          s+='0';
          s+='1';
          cout<<"! "<<s<<endl;
          return;
        }
        if(val ==0){
     cout<<"! IMPOSSIBLE"<<endl;
     return;
     }
     
     }
     else{
       if(val<preval){
        s+='0';
        ones=preval-val;
        zeros=n-i-ones+1;
        }else{
        s+='1';
        }
    if(i==n-1 && val==1){
          s+='0';
          s+='1';
          cout<<"! "<<s<<endl;
          return;
        }
      if(val==0){
       for(ll i=0;i<ones;i++)s+='1';
       for(ll i=0;i<zeros;i++)s+='0';
       cout<<"! "<<s<<endl;
       return;
      }
     }
     preval=val;
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