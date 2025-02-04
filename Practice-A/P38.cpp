#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long;
bool sortbysec(const pair<int,int> &a,
            const pair<int,int> &b)
{
    return (a.second > b.second);
}

void solve(){
    int k;
    cin>>k;
    vector<pair<int,int>>vec;
    int a,b;
    for(int i=0;i<k;i++){
        
        cin>>a>>b;
        vec.push_back(make_pair(a,b));
    }
    sort(vec.begin(),vec.end(),sortbysec);
    int perimeter=0;
    perimeter+=vec[0].first*2+vec[0].second*2;
    int maxb=vec[0].first;
    
    for(int i=1;i<k;i++){
        if(vec[i].first>maxb){
        perimeter+=(vec[i].first-maxb)*2;
        
        maxb=vec[i].first;
        }
    }
    cout<<perimeter<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t){
        solve();
        t--;
    }
}