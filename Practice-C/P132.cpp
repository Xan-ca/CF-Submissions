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
	vli a(n),b(n);
	for(lli i=0;i<n;i++)cin>>a[i];
	for(lli i=0;i<n;i++)cin>>b[i];
	lli diff=0,bidx=-1,big=0;	
	for(lli i=0;i<n;i++){
		if(b[i]>a[i]){
			big+=1;
			bidx=i;
			diff=b[i]-a[i];
         }
		if(big>1){
			cout<<"NO"<<endl;
			return;
		}
	}
	for(lli i=0;i<n;i++){
		if(i!=bidx && b[i]>a[i]-diff){
             cout<<"NO"<<endl;
             return;
		}
	}
	cout<<"YES"<<endl;
	return;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}