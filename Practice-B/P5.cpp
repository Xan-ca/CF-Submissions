
#include <iostream>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int capacity,container,reduc,res=0;
    cin>>capacity;
    cin>>container;
    vector<pair<int,int>>matches;
    for(int i=0;i<container;i++){
        int boxinp,matchinp;
        cin>>boxinp;
        cin>>matchinp;
        matches.push_back(make_pair(matchinp,boxinp));
    }
    sort(matches.begin(),matches.end());
    int curr=container-1;
    while(capacity>0&& curr>=0){
       reduc=min(matches[curr].second,capacity);
       capacity-=reduc;
       res+=matches[curr].first*reduc;
       curr--;
    }
    cout<<res;
    return 0;
}