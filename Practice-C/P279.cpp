#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// this question teaches us how the the drgree or postions of digits matter in a number or digsum question same way i would think
// for a binary number like if my quetion was to check for equality for binary i would
//check for each place as no carry due to digi sum condition hence i think like its a binary number
// we know that for 2 numbers to be same their every 10s palce number has to be same 
// lets say we have number 1234 the 1000s should have 1 the 100s place should have 2 and so on
// now for digi sum part
// next is to satisfy the condition for digi sum we can tell that we can take carry for this because lets 
// say we do take a carry that mwans for a digit at pos x to get carry digits at pos(x-1) must have given 10 extra
// than we require for digit sum and we know the futher we go for the digits left to it it has to be same sum 
// for each pos so no carry can be taken else the digi sum increase by 9 more than we want 
 vector<ll>dp(10,0);
 void init(){
 	dp[0]=1;
 	for(ll i=1;i<=9;i++){
 		dp[i]=dp[i-1]+(i+1);
 	}
 }
void Solve() 
{
    string s;
    cin>>s;
    ll res=1;
    for(ll i=0;i<s.size();i++){
    		res*=dp[s[i]-'0'];
    }
    cout<<res<<endl;
}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    init();
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