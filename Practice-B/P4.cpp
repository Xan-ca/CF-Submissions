
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a;
    cin>>a;
    a=a-1;
    int temp;
    int cat=0;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    for(int i=0;i<n;i++){
        //cout<<"hi";
        if(i==0){
            cat+=arr[a];
            continue;
        }

        if(a+i<n && a-i<0 &&arr[a+i]==1){
            cat++;
        }
       else if(a-i>=0 && a+i>=n &&arr[a-i]==1){
            cat++;
        }
        else if(a+i<n && a-i>=0 && arr[a-i]==1 && arr[a+i]==1){
            cat+=2;
        }
        
    }
    cout<<cat;
    return 0;
}