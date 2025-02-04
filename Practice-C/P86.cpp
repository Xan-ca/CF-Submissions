#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
lli dp[3];
int add(lli x,lli a){
	if(x<a)return 1;
	else if(x>a)return -1;
	else return 0;
}
void solve(){
	lli n;
	cin>>n;
	dp[0]=0;
	dp[1]=-n;
	dp[2]=-n;
	for(int i=1;i<=n;i++){
	lli a;
	cin>>a;
	dp[2]=max(dp[1]+add(dp[1],a),dp[2]+add(dp[2],a));
	dp[1]=max(dp[0],dp[1]);
	dp[0]=dp[0]+add(dp[0],a);
	}
	cout<<max(dp[1],dp[2])<<endl;
	return;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}