#include<bits/stdc++.h>
using namespace std;
int solve(){
	int n;
	cin>>n;
	int arr[n];
	int lock=-1;
	for(int i=0;i<n;i++){
	int temp;
	cin>>temp;
	arr[i]=temp;
	if(temp%2==0 && lock==-1){
	lock=0;
	}
	if(temp%2==1 && lock==-1){
	lock=1;
	}
 
	if(lock==0 && temp%2==1){
      cout<<-1<<endl;
      return 0;
	}else if(lock==1 && temp%2==0){
	  cout<<-1<<endl;
	  return 0;
	}
 
	}
	vector<int>v;
	sort(arr,arr+n);
	//cout<<arr[n-1];
	int a=(arr[n-1]+arr[0])/2;
	int b=arr[n-1]-arr[0];
	int c=arr[n-1];
	while(a>1){
	v.push_back(a);
	c=abs(c-a);
 
	b=ceil(double(b)/2);
	a=ceil(double(b)/2);
	}
 
	
	v.push_back(1);
	c=abs(c-1);
	if(c==1){
		v.push_back(1);
	}
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
		cout<<endl;
 
	//cout<<endl;
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