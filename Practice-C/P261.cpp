#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 		 #define MOD 998244353
 
 
  bool ispalin(ll n,string &s,ll pos,vector<vector<ll>> &prefix){
    ll m=n/2;
    if(pos<=m){
    	 for(int i=0; i<26; i++) {
            if(prefix[pos][i] != prefix[n][i] -prefix[n-pos][i])
                return false;
        }
    	ll left=pos, right=s.size()-pos-1;
        while(left<right) {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
    }
    }
    if(pos>m){
    	ll dec=pos-m;
    	for (int i=0;i <26; i++) {
            if(prefix[pos][i]<prefix[s.size()][i]-prefix[pos][i])
                return false;
        }
    }
    
  
  return true;
}
void Solve() 
{
    string s;
    cin>>s;
    
    ll f=0,b=s.size();
    ll n=s.size()-1;
    while( f<n && s[f]==s[n] ){
        b-=2;
        f++;
        n--;
    }
    s=s.substr(f,b);
    // cout<<s<<s.size()<<endl;
    if(s.size()==0){
    	cout<<0<<endl;
    	return;
    }
    vector<vector<ll>>prefix(s.size()+1,vector<ll>(26));
    for(ll i=0;i<s.size();i++){
          prefix[i+1]=prefix[i]; 
         	
          prefix[i+1][s[i]-'a']+=1; 
         }
 
    
    ll lo=0;
    ll hi=s.size()+1;
    while(hi-lo>1){
    	ll mid=(hi+lo)/2;
    	if(ispalin(s.size(),s,mid,prefix)){
    		hi=mid;
    	}else{
    		lo=mid;
    	}
    }
    reverse(s.begin(),s.end());
    vector<vector<ll>>prefix2(s.size()+1,vector<ll>(26));
    for(ll i=0;i<s.size();i++){
          prefix2[i+1]=prefix2[i]; 
            
          prefix2[i+1][s[i]-'a']+=1; 
         }

    ll lo2=0;
    ll hi2=s.size()+1;
    while(hi2-lo2>1){
        ll mid=(hi2+lo2)/2;
        if(ispalin(s.size(),s,mid,prefix2)){
            hi2=mid;
        }else{
            lo2=mid;
        }
    }
    cout<<min(hi,hi2)<<endl;
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