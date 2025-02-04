#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n;
	cin>>n;
	vli v(n);
	vli res;
	lli mx=0,mn=1e10;
	for(lli i=0;i<n;i++)cin>>v[i];
	for(lli i=0;i<n;i++){
	mx=max(mx,v[i]);
	mn=min(mn,v[i]);
	}
	while(mx!=mn){
	if(mn%2==1 ){
	res.push_back(1);
    mn=(mn+1)/2;
    mx=(mx+1)/2;
	}else{
    res.push_back(0);
    mn/=2;
    mx/=2;
	}

	}
	cout<<res.size()<<endl;
	if(res.size()<=n && res.size()>0){
     for(auto it:res)cout<<it<<" ";
     cout<<endl;
	}
	}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}