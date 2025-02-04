#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cal(ll int pos,ll int k,ll int n){
	if(pos==0)return 1e6;
	ll int res1=(k+pos)*(k+pos-1);
     ll int res2=((k-1)*(k))/2;
     ll int res3=((k+n-1)*(k+n))/2;
     return res1-res2-res3;
}
int solve(){
	ll int n,k;
	cin>>n>>k;
	ll int mid;
	ll l=1;
	ll r=n;
	 for(int i=l;i<=n;i++){
	 	cout<<cal(i,k,n)<<" ";
	 }

	cout<<endl;
	 while(r-l>1){
		mid=l+(r-l)/2;
		if(cal(mid,k,n)<0){
         l=mid+1;
		}else{
         r=mid;
		}
	}
	//cout<<l<<r<<endl;
	if(abs(cal(r,k,n))>abs(cal(l,k,n))){
		//cout<<l<<endl;
		if(l-1 >0 && abs(cal(l,k,n))>abs(cal(l-1,k,n))){
			cout<<abs(cal(l-1,k,n))<<endl;
		}else{
			cout<<abs(cal(l,k,n))<<endl;
		}
	}else{
		if(r-1 >0 && abs(cal(r,k,n))>abs(cal(r-1,k,n))){
			cout<<abs(cal(r-1,k,n))<<endl;
		}else{
			cout<<abs(cal(r,k,n))<<endl;
		}
	}
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
        solve();
	}
}