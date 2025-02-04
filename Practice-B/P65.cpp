#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int solve(){
	ll int n;
	cin>>n;
	ll int arr[n+1];
	arr[0]=0;
	for(ll int i=1;i<=n;i++){
	cin>>arr[i];
	}
	for(ll int i=1;i<=n-1;i++){
		if(i==arr[i])continue;
	    else{

	     if(arr[i]-1!=arr[i+1]){
	        cout<<"NO"<<endl;
	         return 0;
	        }
	        else{
	         swap(arr[i],arr[i+1]);
	         }

	      if(arr[i]!=i){
		  cout<<"NO"<<endl;
		   return 0;
	       }
	   }

	}
	cout<<"YES"<<endl;
	return 0;
}
int main(){
	ll int t;
	cin>>t;
	while(t--){
      solve();
	}
}