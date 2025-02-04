#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int mod(int b ,int p ,int m){
    if(p==0)return 1;
    if(p%2==0){
        int x=mod(b,p/2,m);
        return (x*x)%m;
    }
    else{
        return ((b%m)*mod(b,p-1,m))%m;
    }
}
int main(){
    int B,P,M;
    
    while(cin>>B>>P>>M)
        cout<<mod(B,P,M)<<endl;

	return 0;
}