#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 /*.this one was combinatorics idea
 . we can see that we can either put at first or at last of the remaming cells 
 becoz lets say i put the small element at first cell now all the cell which has the first elemnts has that elment ast its min
 and the remaing cell subarray will be same for first and last left array as the subarray forming with the part behind them wont count
 as it has elements smaller than the so only forward count and thier forwads are same 
 next obs is that if we place a elemnt at first for one choice and last for other we know that first is samller than second choice 
 hence using binary tree of n-1 height we can determine that it will be order of binary representation of the k 
 nice problem rating 10/10 */
void Solve() 
{
    ll n,k;
    cin>>n>>k;
    if(k > pow(2,(n-1))){
      cout<<-1<<endl;
      return;
    }
    bitset<200001>bs(k-1);
    vector<ll>res(n);
    for(int i=0,j=n-1,l=n-2,f=1;f<=n;l--,f++){
    	if(l==-1){
    		res[i]=f;
    		break;
    	}

        if(bs[l]){
        res[j]=f;
        j--;
        }
        else{
        res[i]=f;
        i++;
        }
    }
    for(auto it:res)cout<<it<<" ";
    cout<<endl;
}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
   // cin >> t;
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