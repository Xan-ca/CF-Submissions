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
vector<vector<lli>>ab(n,vector<lli>(2));
vector<vector<lli>>benifit(n,vector<lli>(2));
for(lli i=0;i<n;i++)cin>>ab[i][0];	
for(lli i=0;i<n;i++)cin>>ab[i][1];
//for(lli i=0;i<n;i++)ab[i][2]=i;


for(lli i=0;i<n;i++){
	benifit[i][0]=ab[i][0]+ab[i][1]-1;
	benifit[i][1]=i;
}
sort(benifit.begin(),benifit.end());
// for(auto it:benifit){
// 	cout<<it[0]<<" "<<it[1]<<endl;
// }
lli a=0,b=0;
for(lli i=n-1,k=0;i>=0;i--,k++){
	if(k%2==0){
	a+=ab[benifit[i][1]][0]-1;
	//cout<<a<<endl;
	}else{
	b+=ab[benifit[i][1]][1]-1;
	}
}
cout<<a-b<<endl;	



}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}