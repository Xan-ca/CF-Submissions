#include<iostream>
#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
int main(){
    int n,l;
    cin>>n>>l;
    double arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
   
    double max=0,diff=0;
    for(int i=0;i<=n;i++){
        if(i==0){
             diff=arr[i]-0;
        }else if(i==n){
            diff=l-arr[i-1];
        }else{
            diff=(arr[i]-arr[i-1])/2;
        }
        if(diff>max){
            max=diff;
        }
        
    }
    
    cout<<setprecision(10)<<max;
    return 0;
}