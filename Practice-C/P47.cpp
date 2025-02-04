#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<char, int>& a, 
        pair<char, int>& b) 
{ 
    return a.second > b.second; 
} 
 

vector<pair<char,int>> sort(map<char, int>& M) 
{ 
 
    vector<pair<char, int> > A; 
 
    
    for (auto& it : M) { 
        A.push_back(it); 
    } 

    sort(A.begin(), A.end(), cmp); 

    return A;
   
} 
void solve(){
int n;
cin>>n;
string s;
cin>>s;
int arr[26]={0};

 map<char,int>mp;
for(int i=0;i<n;i++){
    
    mp[s[i]]++;
 }
vector<pair<char,int>>vect =sort(mp);
string res=s;

int i=0;
for(auto it:vect){
   for(int j=0;j<it.second;j++){
    if(i>=n){
        i=1;
    }
    res[i]=it.first;
    i+=2;
   }
  
}
  cout<<res<<endl;    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}