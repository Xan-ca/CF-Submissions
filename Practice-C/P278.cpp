#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 // this problem was good because it taught me how to use prefix sum to account for overlapping ranges which goes till the end==prefix sum
 // so instead of inc each cell by 1 each time if the overlap goes till the end just increase the total value using prefix sum
 // prefix sum is used for over lap or inculude or add till end and segment tree for a given range
 // taught inclusion exclusion mistake i did was for the larger sets i took bound of t3 , t4 and the smaller set i was supposed to remove i took all set elemnts even the ones larger that the super set which didnt fit my second criteria with disregard for my first critera
void Solve() 
{
    ll n,ki;
    cin>>n>>ki;
    vector<pair<ll,ll>>v;
    ll res=0;
    vector<vector<ll>>precomp(1002,vector<ll>(1002,0));
    vector<pair<pair<ll,ll>,pair<ll,ll>>>q;
    for(ll i=0;i<n;i++){
    	ll t1,t2;
    	cin>>t1>>t2;
    	v.push_back({t1,t2});
    	res+=t1*t2;

    }

    sort(v.begin(),v.end());
    ll k=0;
    for(ll i=1;i<=1001;i++){
       for(ll j=1;j<=1001;j++){
       	precomp[i][j]=precomp[i][j-1];
       	if(k<n && i-1==v[k].first && j-1==v[k].second){
            while(k<n && v[k]==v[k+1]){
               precomp[i][j]+=(i-1)*(j-1);
               k++;
            }
       		precomp[i][j]+=(i-1)*(j-1);
       		k++;
       	}
       }
    }
    for(ll j=1;j<=1000;j++){
       for(ll i=1;i<=1000;i++){
       	precomp[i][j]+=precomp[i-1][j];
       
       }
    }
 
   
    for(ll i=0;i<ki;i++){
       ll t1,t2,t3,t4;
      cin>>t1>>t2>>t3>>t4;
      ll ans=precomp[t3][t4]-(((precomp[t3][t2+1])+(precomp[t1+1][t4]))-precomp[t1+1][t2+1]);
    cout<<ans<<endl;
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
       // cout << "Case #" << i << ": "<<endl;
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}