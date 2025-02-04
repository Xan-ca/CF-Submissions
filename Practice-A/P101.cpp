#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n;
	cin>>n;
	vli vec(n);
	for(lli i=0;i<n;i++){
		cin>>vec[i];
	}
	for(lli i=0;i<n-1;i++){
		lli mx=max(vec[i],vec[i+1]);
		lli mn=min(vec[i],vec[i+1]);
		if(mn*2>mx){
			cout<<"YES"<<endl;
			return ;
		}
	}
	cout<<"NO"<<endl;
	return ;

}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}