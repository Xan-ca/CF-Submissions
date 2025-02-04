#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define MOD 1000000007
 vector<vector<ll>>dp;
 vector<ll>palmap;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
/* as only we need sum expressed in tems of palindrome we can use dp as only 498 palindrome
 between 1 and 40000 and each dp state says how many ways a number can be represented if the
  numbers use to add are higher than jth palindrome this is done to avoid repetation*/
bool checkPalindrome(ll n) {
    ll reverse = 0;
    ll temp = n;
    while (temp != 0) {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }

    return (reverse == n);
}
void assignplndrm(){
	for(auto i=0,j=0;i<40001;i++){
       if(checkPalindrome(i)){
       	palmap[j]=i;
       	j++;
       }
	}
}
 void init(){
  dp.resize(40001);
    for(auto &it:dp){
    	it.resize(502);
    	fill(it.begin(),it.end(),0);
    }
    // for(auto it:dp[1])cout<<it<<" ";
    // 	cout<<endl;
    palmap.resize(502);
    fill(palmap.begin(),palmap.end(),1e7);
    
    assignplndrm();
     
    for(ll i=1;i<=40000;i++){
    	for(ll j=500;j>=0;j--){
            if(palmap[j]>i){
            	dp[i][j]+=(dp[i][j+1])%MOD;
            }else if(palmap[j]==i){
            	dp[i][j]+=(1+dp[i][j+1])%MOD;
            }else{
            	dp[i][j]+=(dp[i-palmap[j]][j]+dp[i][j+1])%MOD;
            }
         
    	}
    
    }
 }
void Solve() 
{   ll n;
	cin>>n;

  cout<<(dp[n][0])%MOD<<endl;  
}
 
int32_t main() 
{   init();
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