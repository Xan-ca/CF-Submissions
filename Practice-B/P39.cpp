#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
int n;
cin>>n;
ll int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int min=INT_MAX;
for(int i=0;i<n;i++){
    int k=i;
    for(int j=i;j<n;j++){
       if(arr[i]<arr[j]){
         k+=1;
       }
    }
    if(k<min){
        min=k;
    }
}
cout<<min;
}
int main(){
    int t;
    cin>>t;
    while(t){
        solve();
        t--;
    }
}