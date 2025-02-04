#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll int n;
    cin>>n;
    vector<ll int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<ll int>sum=arr;
    for(ll int i=1;i<n;i++){
        sum[i]+=sum[i-1];
    }

    sort(arr.begin(),arr.end());
    vector<ll int>sortsum=arr;
    for(ll int i=1;i<n;i++){
        sortsum[i]+=sortsum[i-1];
    }
    ll int num,type,start,end;
    cin>>num;
    for(ll int i=0;i<num;i++){
        cin>>type>>start>>end;
        if(type==1){
            if (start==1)cout<<sum[end-1];
            else cout<<sum[end-1]-sum[start-2];
        }else{
            if (start==1)cout<<sortsum[end-1];
            else cout<<sortsum[end-1]-sortsum[start-2];
        }
        cout<<endl;
    }
    
}