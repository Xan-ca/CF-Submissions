#include<bits/stdc++.h>
#include <atcoder/modint>
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
using namespace std;
using namespace atcoder;

using mint = modint998244353;
// or: typedef modint998244353 mint;
void solve(){
	lli sum=0;
	lli n;
	cin>>n;
	vli v(n);
	for(int i=0;i<n;i++){
	cin>>v[i];
	}
	sum=accumulate(v.begin(),v.end(),0LL);
	//cout<<sum;
	mint res=0;
	for(int i=0;i<n-1;i++){
	sum-=v[i];
	res+=(v[i]*sum);
	//cout<<(v[i]*sum)%(1000000007)<<endl;
	}
	//cout<<res<<endl;
	res=(res)/(((n)*(n-1))/2);
	cout<<res<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}