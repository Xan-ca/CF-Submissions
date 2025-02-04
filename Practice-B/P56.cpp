#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll int ce(ll a,ll b){
    if(a%b==0){
        return a/b;
    }else{
        return (a/b)+1;
    }
}
int solve(){
    ll int n,k;
    cin>>n>>k;
    ll int arr[n];
    long double sum=0;
    ll int mx=0;
    for(int i=0;i<n;i++){
        ll int temp;
        cin>>temp;
        arr[i]=temp;
        sum+=temp;
        mx=max(temp,mx);
    }
    cout<<max(mx,ce(sum,k))<<endl;
    return 0;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}