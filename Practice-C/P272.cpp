#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 

{   ll n;
	string s;
    cin>>n;
	cin>>s;
	ll sum=0,carry;
	vector<ll>res,v(s.size());
    for(ll i=0;i<s.size();i++){
     v[i]=s[s.size()-i-1]-'0';
      sum+=v[i];
    }

    for(ll i=0;i<=s.size();i++){
          if(i>0){
          	sum-=v[i-1];
          	ll sum2=sum;
          	sum2+=carry;
            res.push_back(sum2%10);
            carry=sum2/10;
          }else{
          	res.push_back(sum%10);
          	carry=sum/10;
          }
    }
    while(carry>0){
    	res.push_back(carry%10);
          	carry=carry/10;
    }
    reverse(res.begin(),res.end());
    ll k=0;
    while(res[k]==0)k++;
    for(ll i=k;i<res.size();i++)cout<<res[i];
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