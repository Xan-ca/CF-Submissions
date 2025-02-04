#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
lli multiples(lli a,lli b,lli x){
	if(x>b)return 0;
	return ((b+x)/(x*x))-((a-1+x)/(x*x));
}
void solve(){
	lli n,m;
	cin>>n>>m;
	lli res=0;
	for(lli i=1;i<=m;i++){
	res+=multiples(1,n,i);
	}
	cout<<res<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}