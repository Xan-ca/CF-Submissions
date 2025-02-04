#include<bits/stdc++.h>
using namespace std;
#define ll long long
int solve(){
ll int n;
cin>>n;
ll int a[3];
ll l=1,r=n,i=0;
ll xr;
ll newxor;
cout<<"xor "<<l<<" "<<mid<<endl;
cin>>xr>>endl;
ll int a,b,c;
while(l<=r){
	ll mid=l+(r-1)/2;
	cout<<"xor "<<l<<" "<<mid<<endl;
	cout<<flush;
    cin>>newxor;
    if(xr==0){
     l=mid+1;
    }
    else if(newxor!=xr){
    	r=mid;
    	xr=newxor;
    	int a[i]=number;
    	i++;
    }else{
    	r=mid;
    }
}
}
int main(){
	ll int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}