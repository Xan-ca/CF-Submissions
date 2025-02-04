#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll int l,r,k;
    cin>>l>>r>>k;
    ll int ans=0;
    ll int l1=l;
    ll int r1=r;
    ll int k1=k;
    ll int mid=l1 +(r1-l1)/2;
    while(l1<=r1){
        mid=l1 +(r1-l1)/2;
        if(mid*k<r){
            l1=mid+1;
        }else if(mid*k>r){
            r1=mid-1;
        }
        else{
            ans=mid;
            break;
        }
    }
    if(ans){
        cout<<ans-l+1<<endl;
        return;
    }
    cout<<l1-l<<endl;
    return ;
}
int main(){
ll int t;
cin>>t;
while(t){
    t--;
    solve();
}
}