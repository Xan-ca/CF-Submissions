#include<bits/stdc++.h>
using namespace std;
int solve(){
	int n;
	cin>>n;
	int arr[n];
	int brr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		cin>>brr[i];
	}
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++){
		sum1+=arr[i];
		sum2+=brr[i];
	}
	int res1=0,res2=0;
	for(int i=0;i<n;i++){
		sum1-=arr[i];
		sum2-=brr[i];
		if(arr[i]>brr[i]){
			res1+=arr[i];
			}
			else if(arr[i]<brr[i]){
				res2+=brr[i];
			}
			else{
				if(arr[i]==0)continue;
				if(arr[i]==1){
					if(res1+sum1>res2+sum2){
						res2+=arr[i];
					}
					else{
						res1+=arr[i];
					}
				}
				if(arr[i]==-1){
					if(sum2+res2>sum1+res1){
						res2+=arr[i];
					}
					else{
						res1+=arr[i];
					}
				}
			}

		}
		cout<<min(res1,res2)<<endl;
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