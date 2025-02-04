#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    string a;
    ll n;
    cin>>n;
    cin>>a;
    vector<vector<ll>>freq(2,vector<ll>(26,0));
    vector<vector<ll>>freq2(2,vector<ll>(26,0));
    ll res=1e9;
    for(ll i=0;i<n;i++){
    	if(i%2==0)freq[1][a[i]-'a']++;
    	else freq[0][a[i]-'a']++;
    }
    if(n%2==1)for(ll i=0;i<n;i++){
        freq[i%2==0][a[i]-'a']--;
        if(i-1>=0)freq2[i%2][a[i-1]-'a']++;
        ll eve=0,od=0;
        for(ll j=0;j<26;j++){
        	
        	eve=max(eve,freq[1][j]+freq2[0][j]);
        	od=max(od,freq[0][j]+freq2[1][j]);
        }
        ll temp=n-1-(eve+od);
       res=min(res,temp);
    }else{
    	  ll eve=0,od=0;
    	 for(ll j=0;j<26;j++){
        	
        	eve=max(eve,freq[1][j]);
        	od=max(od,freq[0][j]);
        }
         ll temp=n-(eve+od);
       res=min(res,temp);
       cout<<res<<endl;
       return;
    }
    cout<<res+1<<endl;
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