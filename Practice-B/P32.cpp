#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    char p;
    cin>>n>>m>>p;
    char arr[n][m];
    pair pos={-1,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char temp;
            cin>>temp;
            arr[i][j]=temp;;
            if(pos.first==-1 && temp==p){
                pos={i,j};
            }
        }
    }
    set<char>v;
    for(int i=pos.first;i<n;i++){
        if(arr[i][pos.second]!==p)break;
        for(int j=pos.second;j<m;j++){
            if(arr[pos.first][j]!==p)break;
            else{
                 if (arr[i][j + 1] != arr[i][j] && arr[i][j + 1] != '.' && j + 1 < m) {
                    v.insert(arr[i][j + 1]);
                }
 
                if (arr[i][j - 1] != arr[i][j] && arr[i][j - 1] != '.' && j - 1 >= 0) {
                    v.insert(arr[i][j - 1]);
                }
 
                if (arr[i + 1][j] != arr[i][j] && arr[i + 1][j] != '.' && i + 1  < n) {
                    v.insert(arr[i + 1][j]);
                }
 
 
                if (arr[i - 1][j] != arr[i][j] && arr[i - 1][j] != '.' && i - 1  >= 0) {
                    v.insert(arr[i - 1][j]);
                }
            }
        }
    }
    cout<<size(v)<<endl;
    
}