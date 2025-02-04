#include<iostream>
#include<bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;
int solve(){
    ll int n,k,q;
    cin>>n>>k>>q;
    ll int arr[n][k];
    for(ll int i=0;i<n;i++){
        for(ll int j=0;j<k;j++){
            cin>>arr[i][j];
        }
    }
    for(ll int i=1;i<n;i++){
        for(ll int j=0;j<k;j++){
            arr[i][j]=arr[i-1][j]|arr[i][j];
        }
    } 
    ll int l=0,r=n-1,mid;
    ll int index,target;
    ll int mx=0,mi=n-1;
    ll int ptr1,ptr2;
    bool lock;
    while(q--){
        ll int q2;
        lock =false;
        cin>>q2;
        mx=0;
      mi=n-1;
    while(q2--){
        
        char s;
        cin>>index;
        cin>>s;
        cin>>target;
        index--;
       
            if(s=='<'){
                l=0;
                r=n-1;
                while(l<=r){
                    mid=l+(r-l)/2;
                    if(arr[mid][index]<target){
                        l=mid+1;
                    }
                    else if(arr[mid][index]>=target){
                        r=mid-1;
                    }
                }
                while((r>=0 || r<n )&& arr[r][index]==target)r--;

                ptr1=0;
                ptr2=r;
               // cout<<r<<endl;
                if(ptr2<0){
                 // cout<<-1<<endl;
                  lock=true;
                }
                mx=max(ptr1,mx);
                mi=min(ptr2,mx);
                
            }
            else if(s=='>'){
               
                l=0;
                r=n-1;
                while(l<=r){
                    mid=l+(r-l)/2;
                    if(arr[mid][index]<=target){
                        l=mid+1;
                    }
                    else if(arr[mid][index]>target){
                        r=mid-1;
                    }
                }
                while((l>=0 || l<n )&& arr[l][index]==target)l++;
                
                ptr1=l;
                ptr2=n-1;
                if(ptr1>n-1){
                  //cout<<-1<<endl;
                  lock ==true;
                }
                mx=max(ptr1,mx);
                mi=min(ptr2,mx);

            }
        
    }
   // cout<<mi<<mx<<endl;
    if(mx+1>n || mx+1<=0|| mx>mi || mi<0 || mi>n-1 || lock){
      cout<<-1<<endl;
    }else{
      cout<<mx+1<<endl;
    }
    }
    return 0;
}
int main(){
    solve();
    return 0;
}