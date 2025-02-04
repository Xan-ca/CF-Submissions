#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool islovely(ll int n){
    ll int x=sqrt(n);
    for(int ll i=2;i<=x;i++){
        if(n%(i*i)==0){
            return false;
        }
    }
    return true;
}
int main(){
    ll int n;
    cin>>n;
    vector<ll int>vec;
    ll int x=sqrt(n);
    for(ll int i=1;i<=x;i++){
        if(n%i==0){
            if(i==n/i) vec.push_back(i);
            else{
                vec.push_back(i);
                vec.push_back(n/i);
            } 
        }
    }
    sort(vec.begin(),vec.end());
    for(ll int i=size(vec)-1;i>=0;i--){
       if(islovely(vec[i])){
        cout<<vec[i]<<endl;
        return 0;
       }
    }

}