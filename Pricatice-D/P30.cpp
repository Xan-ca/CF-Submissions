#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int i0=2;
    int parent[n+1]={-1};
    parent[0]=-1;
    parent[1]=0;
    vector<int>leaves;
    leaves.push_back(1);
    int k;
    while(i0<n){
        cout<<"? "<<i0<<" "<<1<<endl;
        cout<<flush;
        int ans;
        cin>>ans;
        if(ans==0){ 
            leaves.erase(leaves.begin());
            leaves.push_back(i0);
            parent[i0]=1;
            k=i0;
            break;
        }else{
            parent[i0]=0;
            leaves.push_back(i0);
        }
        i0++;
    }
    int j=k+1;
    int toerase=0;
    //sort(leaves.begin(),leaves())
    while(j<n){
        for(int i=0;i<size(leaves);i++){
            if(i==size(leaves)-1){
                parent[j]=leaves[i];
                leaves[i]=j;
                break;
            }
           cout<<"? "<<leaves[i]<<" "<<j<<endl;
           cout<<flush;
           int ans;
           cin>>ans;
           if(ans==0){
            parent[j]=leaves[i];
            leaves.erase(leaves.begin()+i);
            leaves.push_back(j);
            break;
           }else{
            toerase++;
           }
        }
        while(toerase>0){
            leaves.erase(leaves.begin());
            toerase--;
        }
       
        j++;
        
    }
    cout<<"! ";
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" ";
    }
    cout<<flush;
}

int main(){
    int t;
    cin>>t;
    while(t){
        solve();
        t--;
    }
}