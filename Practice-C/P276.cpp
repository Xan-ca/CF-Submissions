#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{  
	ll n;
	cin>>n;
	vector<ll>v(n+1,0);
	ll MAXN=0;

	for(ll i=1;i<=n;i++){
		cin>>v[i];
		MAXN=max(v[i],MAXN);
	}
		vector<vector<ll>>smaller(MAXN,vector<ll>(n+1,0));
	vector<vector<ll>>larger(MAXN,vector<ll>(n+1,0));
	for(ll i=1;i<=MAXN;i++){
		for(ll j=1;j<=n;j++)
		{    smaller[i][j]=smaller[i][j-1];
	          larger[i][j]=larger[i][j-1];
			if(i>v[j]){
				smaller[i][j]=smaller[i][j-1]+1;
			}
			if(i<v[j]){
				larger[i][j]=larger[i][j-1]+1;
			}
		}
	}

	 auto inv= [&] (ll start,ll end,ll num)->ll{
 	 if(start==end) return 0ll;
       ll in=smaller[num][end]-smaller[num][start];
       ll de=larger[num][end]-larger[num][start];
       ll ret=in-de;
       return ret;
 };
	ll maxinv=0;
	pair<ll,ll>res={1,1};
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			ll inver=inv(i,j,v[i]);
            if(inver>maxinv){
              maxinv=inver;
              res.first=i;
              res.second=j;
            }
		}
	}
	cout<<res.first<<" "<<res.second<<endl;

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