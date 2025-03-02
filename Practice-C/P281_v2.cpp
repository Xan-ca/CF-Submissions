#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 // you can use stack to get lexicographically smaller or and smaller to largest or largest to smallest oreder montonic results
 // stack can also be used for limited numbers of removal

 // i could have done this solution if i put in element one by one instead of checking the whole array at once like my prev idea when checking with
 // last or near to last or any bulding string probelm where you have to remove some elemnts check if you can build the string insted of removing the
 // elements form string as building a string takes o(n) while removing elemnts form string to get string takes o(n2) time intead;
void Solve() 
{
	string s;
   cin>>s;
   ll n;
   cin>>n;

  ll remove=0;

    ll f=s.size();
   for(ll i=f;i>=0;i--){
   
   	if(n > i){

   		remove++;

   		n-= i;
   	}else break;
   }
   string res;
   for(ll i=0;i<s.size();i++){
     
     if(remove>0)	while (remove> 0 && s[i]<res.back()){
           res.pop_back();
           remove--;

     	}
     	res.push_back(s[i]);
     
   }
   cout<<res[n-1];
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