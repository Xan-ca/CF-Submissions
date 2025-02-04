#include<bits/stdc++.h>
using namespace std;
int solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
     int mx=0;
	int freq[51]={0};
	for(int i=0;i<n;i++){
		freq[arr[i]]+=1;
		mx=max(freq[arr[i]],mx);
	}

	cout<<n-mx<<endl;

	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
	solve();
	}
	return 0;
}