#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    long int k;
    while(cin>>k && k){
        bool cond=0;
        long long int div=sqrt(k);
        if(div*div==k){
            cond=1;
        }
        if(cond)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}