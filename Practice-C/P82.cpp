#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
 
void solve(){
	lli x,m;
	cin>>x>>m;
	lli mx;
	lli cnt=0;
	if(x>m || m<=1e6){
		mx=m;
		for(lli i=1;i<=mx;i++){
			lli z=x^i;
		if(z%x==0 || z%i==0){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return;
	}
	else{
		cnt+=((m-x)/x)-1;
		for(int i=1;i<2*x;i++){
			lli z=x^i;
			if(z>=2*x)continue;
			//if(z==0)continue;
			//if(z>x)continue;
		    if(z%i==0 || z%x==0){
			cnt++;}
		}
		for(lli i=m-x+1;i<=m+x;i++){
			lli z=x^i;
			if(z>m || z==0 )continue;
			if(i%z==0|| i%x==0)cnt++;
 
 
		}
		cout<<cnt<<endl;
 
 
	}
 
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}
