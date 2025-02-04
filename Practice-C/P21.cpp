#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool sortbyfirst(const pair<long long int,long long int> &a,const pair<long long int,long long int> &b)
{   if(a.first==b.first)return (a.second < b.second);
    else return(a.first<b.first);
}
bool sortbysec(const pair<long long int,long long int> &a,
            const pair<long long int,long long int> &b)
{
    return (a.second < b.second);
}
int main(){
    int n;
    cin>>n;
    vector<pair<long long int,long long int>>vec;
    for(int i=0;i<n;i++){
        long long int temp1,temp2;
        cin>>temp1>>temp2;
      vec.push_back({temp1,temp2});
    }
    long long int res=0;
    long long int s=0;
    long long int c=0;
    long long int copy=0;
    sort(vec.begin(),vec.end(),sortbyfirst);
    for(int i=1;i<n;i++){
       if(vec[i].first==vec[i-1].first)
       {s++;
       if(vec[i].second==vec[i-1].second){
        c++;
       }else{
          copy+=(c*(c+1))/2;
        c=0; 
       }
       }else{
        res+=(s*(s+1))/2;
        s=0;
        copy+=(c*(c+1))/2;
        c=0;
       }
       
    }
   
    res+=(s*(s+1))/2;
    copy+=(c*(c+1))/2;
    c=0;
    res-=copy;
    s=0;
    
    sort(vec.begin(),vec.end(),sortbysec);
    for(int i=1;i<n;i++){
       if(vec[i].second==vec[i-1].second){
        s++;
       }else{
        res+=(s*(s+1))/2;
        s=0;
       }
    }
    res+=(s*(s+1))/2;
    s=0;
    cout<<res;
}