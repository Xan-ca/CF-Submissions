
#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;
int main(){
    string recipie;
    int prices[3];
    int arr[3];
    ll int money;
    cin>>recipie;
    
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }
    for(int i=0;i<3;i++){
        cin>>prices[i];
    }
    cin>>money;
   
    int req[3]={0};
    for(int i=0;i<size(recipie);i++){
        if(recipie[i]=='B'){
           req[0]++;
        }else if(recipie[i]=='S')
        {
            req[1]++;
        }else {
            req[2]++;
        }
    }
    int mx=0,mn=INT_MAX;
   for(int i=0;i<3;i++){
        if(req[i]==0)continue;
        if(arr[i]/req[i]>mx)mx=arr[i]/req[i];
        if(arr[i]/req[i]<mn)mn=arr[i]/req[i];
    
   }

   ll int costburger=(req[0]*prices[0])+(req[1]*prices[1])+(req[2]*prices[2]);
   ll int burger=0;
   

   while(mx+1){
    for(int i=0;i<3;i++){
        if(req[i]<arr[i])arr[i]-=req[i];
        else if(arr[i]>0){
            money-=(req[i]-arr[i])*prices[i];
            arr[i]=0;
        }
        else{
            money-=prices[i]*req[i];
        }
    }
    if(money>=0)burger++;
    else break;
    mx--;

   }

   if(money>0){
    burger+=money/costburger;
   }
 
   cout<<burger<<endl;
}