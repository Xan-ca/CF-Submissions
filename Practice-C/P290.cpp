#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 // 1110011001 ->1110011010
// 11001101->11001001
// 0111->1000
// 011->100
//
void Solve() 
{   
	ll n,k;
	cin>>n>>k;
	bitset<64>b1(n),b2(k),res(0);
	ll c=n&k
	for(ll i=b1.size();i>=0;i--){
		if(b1[i]!=b2[i]){
			if(b1[i]==0 && b2[i]==1){
                  cout<<-1<<endl;
					return;
			}else{
				if(b1[i+1]==0){
					res[i+1]=1;
					while(i>=0 && b2[i]==0)i--;
					if(i==-1){
                      cout<<res.to_ullong()<<endl;
					  return;
					}else{
						 cout<<-1<<endl;
					     return;
					}
					
					
				}else{
                    cout<<-1<<endl;
                    return;
				}
			}
		}else res[i]=b1[i];
	}
	cout<<res.to_ullong()<<endl;
	return;
    
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