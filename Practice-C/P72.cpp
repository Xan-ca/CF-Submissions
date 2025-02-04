#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solve(){
	ll int n;
	cin>>n;
	ll int arr[n];
	for(ll int i=0;i<n;i++){
     cin>>arr[i];
	}
	ll int res=0;
	ll int a1,b1,a2,b2;
	for(ll int i=0;i<(n/2)-1;i++){
		a1=0,a2=0,b1=0,b2=0;
		if(arr[i]==arr[i+1]){
			a1=1;
		}
		if(arr[i]==arr[n-i-2]){
			a2=1;
		}
		if(arr[n-1-i]==arr[n-i-2]){
			b1=1;
		}
		if(arr[n-1-i]==arr[i+1]){
			b2=1;
		}
		if(a1+b1>a2+b2){
			swap(arr[i+1],arr[n-2-i]);
			res+=(a2+b2);
		}else{
			res+=(a1+b1);
		}
	}
	if(n%2==1){
		ll int i=(n/2);
		//cout<<i<<endl;
		if(i+1<n && arr[i]==arr[i+1])res++;
		if(i-1>=0 && arr[i]==arr[i-1])res++;
	}else{
		ll int i=(n/2);
		if(i-1>=0 && arr[i]==arr[i-1])res++;
	}
	
	cout<<res<<endl;
	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}