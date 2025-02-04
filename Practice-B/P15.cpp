#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool hcfone(int a, int b){
    int k;
    int m= min(a,b);
for(int i=1;i<=m;i++){
    if(a%m==0&& b%m==0 && m!=1){
        return false;
    }
}
return true;
}
int main(){
    int n;
while(cin<<n&& n!=0){
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    double count=0;
    double nohcf=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            else{
                count++;
                nohcf+=(double)hcfone(arr[i],arr[j]);
            }
        }
    }
    if(nohcf==0||count==0){
        cout<<"err"<<endl;
        continue;
    }
    double ans=sqrt(6/(count/nohcf));
    cout<<ans;
}
return 0;
}