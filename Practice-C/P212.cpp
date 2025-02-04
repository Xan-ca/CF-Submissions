#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    ll ncpy=n;
    vector<vector<ll>>grid(n,vector<ll>(n));
    vector<vector<ll>>sumg(n,vector<ll>(n));
    vector<vector<ll>>vec(n);
    for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
    cin>>grid[j][i];
    
    }
    }
    for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
   
    if(i==0)sumg[i][j]=grid[i][j];
   else sumg[i][j]+=sumg[i-1][j]+grid[i][j];
    }
    }
    
    vector<ll>res(n,100);
    for(ll j=0;j<n;j++){
       
            for(ll k=0;k<=n;k++){
                if(k==n ){
                    if(sumg[n-1][j]!=n)res[j]=k-1;
                    else res[j]=k;
                    break; 
                }
               if(k!=n) if(sumg[n-1][j]-sumg[n-1-k][j]!=k){
                //cout<<k<<" "<<sumg[n-1-k][j]<<endl;
               res[j]=k-1;
               break;
           }
            }
        
    }
    sort(res.begin(),res.end());
    ll k=0;
    for(ll i=0;i<n;i++){
        if(res[i]>=k){
            res[i]=k;
          k++;
        }
    }
    
 
    for(ll i=0;i<=n;i++){
        if(find(res.begin(), res.end(), i)==res.end()){
            cout<<i<<endl;
            return;}
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