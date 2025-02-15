#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
  vector<bool> is_prime,is_semiprime;
  vector<ll>spfactors;
 void seive_init(int n) 
 {
 is_prime.resize(n+1);
 spfactors.resize(n+1);
 fill(spfactors.begin(),spfactors.end(),0);
 fill(is_prime.begin(),is_prime.end(),true);
 is_semiprime.resize(n+1);
 fill(is_semiprime.begin(),is_semiprime.end(),false);
 is_prime[0] = is_prime[1] = false;
 for (int i = 2; i <= n; i++) {
     if (is_prime[i] && (long long)i * i <= n) {
         for (int j = i * i; j <= n; j += i)
             is_prime[j] = false;
     }
 }
 int x=sqrt(n);
 vector<int>primes;
 for(ll i=2;i<=n;i++)if(is_prime[i])primes.push_back(i);
 for ( int i = 2; i <= n ; i++){

   for(auto j:primes){
    if(j*j>n)break;
    if ( is_prime[j] && i%j == 0 ){
       if(is_prime[i/j]){
        is_semiprime[i] = true;
        spfactors[i] = j;
       }
    }
   }
 }
 }
  
void Solve() 
{ ll n,cnt=0,res=0;
cin>>n;
vector<ll>v(n),mp(n+1,0),mp2(n+1,0);
 for(auto &it:v)cin>>it;


    for(ll i=0;i<n;i++){

        if(is_prime[v[i]] ){
            mp[v[i]]++;
            
        }
        if(is_semiprime[v[i]]){
            mp2[v[i]]++;
        }
    }


for(ll i=2;i<=n;i++){
   res+=mp[i]*cnt;
   cnt+=mp[i];
}

for(ll i=2;i<=n;i++){
    if(spfactors[i]!=0 && is_semiprime[i]){
        if(spfactors[i]==(i/spfactors[i]))res+=mp2[i]*mp[spfactors[i]];
        else res+=mp2[i]*(mp[spfactors[i]]+mp[i/spfactors[i]]);
        res+=(mp2[i]*(mp2[i]+1))/2;
    }
}
   cout<<res<<endl;
}


 
int32_t main() 
{    seive_init(200000);
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