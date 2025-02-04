// Online C++ compiler to run C++ program online
#include<iostream>
#include<vector>
using namespace std;
int main(){
int n,h,s;
int fill=0;
int temp;
int time=0;
cin>>n;
cin>>h;
cin>>s;
int i=0;
vector<int>arr;
for(int j=0;j<n;j++){
    cin>>temp;
    arr.push_back(temp);
}
while(i+1<n){
    fill+=arr[i];
    while(fill+arr[i+1]>h){
        time++;
        fill-=s;
        if(fill<0)fill=0; 
    }
    if(i+1==n-1){
        fill+=arr[i+1];
        break;
    }
    i++;
}
while(fill>0){
        time++;
        fill-=s;
        if(fill<0)fill=0;  
}
cout<<time;
}