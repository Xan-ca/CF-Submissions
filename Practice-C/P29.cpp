#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(){
    int s;
    cin>>s;
    int arr[s];
    for(int i=0;i<s;i++){
        cin>>arr[i];
    }
    sort(arr,arr+s);
    int j=2;
    for(int i=1;i<s;i++){
        if(a[[i-1+j]]>=s)continue;
        while(a[i-1+j]>a[i]+a[i-1])j++;
        
    }
    cout<<s-j<<endl;
    return 0;
}
int main(){
    int n;
    cin>>n;
    for(int j=0;j<n;j++){
        solve()
    }
    return 0;
}