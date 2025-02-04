#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int temp;
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp>mx){
            mx=temp;
        }
    }
    cout<<mx;
}