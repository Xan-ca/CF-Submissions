#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n,a,b;
	cin>>n>>a>>b;
	if((b-1-a)%2!=0){
		cout<<"YES"<<endl;
	}else cout<<"NO"<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}