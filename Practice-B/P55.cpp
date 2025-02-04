#include<bits/stdc++.h>
using namespace std;
#define ll long long
int solve(){
    ll int n,k;
    cin>>n>>k;
    ll int arr[n];
    for(ll int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll int j=-1,mx=0;
    ll int i=0,d=1;
    while(j<n-1 && i<n-1){
        j++;
      if(arr[j]==arr[j+1]||arr[j]==arr[j+1]+1) {
        
        if(arr[j]==arr[j+1]+1){
            d++;
        }
        mx=max(j-i,mx);
        if(d>k){
            while(arr[i]==arr[i+1]){
                i++;
            }
            d--;
            i++;
        }
        
       
       
      }  
      else{
        i=j;
        
      }
    }
    cout<<mx<<endl;
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}