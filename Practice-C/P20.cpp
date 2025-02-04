#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int n1,n2;
    cin>>n1>>n2;
    queue <int> q1,q2;
    int temp;
    for(int i=0;i<n1;i++){
        cin>>temp;
        q1.push(temp);
    }
    for(int i=0;i<n2;i++){
        cin>>temp;
        q2.push(temp)
    }
    int fights=0;
    while(size(q1) && size(q2)){
        fights++;
        int top1=q1.front();
        int top2=q2.front();
        q1.pop();
        q2.pop();
        if(top1>top2){
            q1.push(top2);
            q1.push(top1);
        }else{
            q2.push(top1);
            q2.push(top2);
        }
    }
    int winner;
    if(size(q1)==0){
        winner=2;
    }else{
        winner=1;
    }
    cout>>fights>>" ">>winner;
    return 0;
}