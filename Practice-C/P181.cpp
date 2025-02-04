#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll l,r;
    cin>>l>>r;
    bitset<32>ls(l);
    bitset<32>rs(r);
    bitset<32>res1(0);
    bitset<32>res2(0);
    for(ll i=ls.size()-1;i>=0;i--){
        
        if(ls[i]==false && rs[i]==true){
             res1[i]=false;
             res2[i]=true;
             i--;
            for(i;i>=0;i--){
                
                    res1[i]=true;
                    res2[i]=false;
                
            }
        }else{
        res1[i]=rs[i];
        res2[i]=ls[i];
        }
    }
    //cout<<res1.to_ulong()<<" "<<res2.to_ulong()<<endl;
    for(ll i=l;i<=r;i++){
        if(i!=res1.to_ulong()&& i!=res2.to_ulong() ){
          cout<<res1.to_ulong()<<" "<<res2.to_ulong()<<" "<<i<<endl;
          return;  
        }
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