#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
if(n%2==0){
    cout<<-1;
    return 0;
}
int a[n],b[n],c[n];
for(int i=0;i<n;i++){
    a[i]=i;
    cout<<a[i]<<" ";
}
cout<<"\n";
for(int i=0;i<n;i++){
    b[i]=(i+1)%n;
    cout<<b[i]<<" ";
}
cout<<"\n";
for(int i=0;i<n;i++){
    c[i]=(a[i]+b[i])%n;
    cout<<c[i]<<" ";
}
return 0;

}