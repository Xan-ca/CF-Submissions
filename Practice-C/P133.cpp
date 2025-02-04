#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
lli n,k;
cin>>n>>k;
vli v(n),sum(n+1,0),ones(n+1,0);
for(lli i=0;i<n;i++)cin>>v[i];

	lli s=0,o=0;
for(lli i=0;i<n;i++){
	if(v[i]==1){
		o+=1;
		
	}else{
		s+=v[i]-1;
		
	}
	ones[i+1]=o;
	sum[i+1]=s;
}
while(k--){
	lli a,b;
	cin>>a>>b;
    //cout<<ones[b];
	if( a!=b && sum[b]-sum[a-1]>=ones[b]-ones[a-1])cout<<"YES";
	else cout<<"NO";
	cout<<endl;
}
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}