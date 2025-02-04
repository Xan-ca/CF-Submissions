#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
ll int a,b;
cin>>a>>b;
ll int rr[3]={2,3,5};
ll int arr[3]={0};
ll int brr[3]={0};
for(ll int i=0;i<3;i++){
    while(a%rr[i]==0){
        arr[i]++;
        a=a/rr[i];
    }
}
for(ll int i=0;i<3;i++){
    while(b%rr[i]==0){
        brr[i]++;
        b=b/rr[i];
    }
}
if(a!=b){
    cout<<-1;
    return 0;
    }
    else{
        ll int sum=0;
       for(ll int i=0;i<3;i++){
          sum+= abs(arr[i]-brr[i]);
    }

    cout<<sum;
    } 
    return 0;
}

