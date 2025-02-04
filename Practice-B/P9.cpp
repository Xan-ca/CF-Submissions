#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[3]={0};
    string s;

    for(int i=0;i<3;i++){
        cin>>s;
        if(s[1]=='>'){
            arr[int(s[0])-65]++;
        }else{
            arr[int(s[2])-65]++;
        }
    }
    for(int i=0;i<3;i++){
        if(i==2&& arr[i]!=0){
            cout<<"Impossible";
            return 0;
        }
        if(arr[i]==0)break;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[j]==i){
                cout<<char(j+65);
            }
        }
    }
    return 0;
}