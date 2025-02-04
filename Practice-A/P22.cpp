#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool comp (int a, int b) {
  return a > b;
}
int main(){
int t;
cin>>t;
for(int j=0;j<t;j++){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[k]={0};
    for(int i=0;i<k;i++){
        int temp1,temp2;
        cin>>temp1;
        cin>>temp2;
        arr[temp1-1]+=temp2;
    }
    sort(arr,arr+k,comp);
    int res=0;
    for(int i=0;i<n;i++){
        if(i>=k)break;
        res+=arr[i];
    }
    cout<<res<<endl;
}
return 0;
}