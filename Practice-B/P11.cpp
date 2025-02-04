#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string operator * (string a, unsigned int b) {
    string output = "";
    while (b--) {
        output += a;
    }
    return output;
}
int main(){
    int n;
    cin>>n;
    string s="VIBGYOR";
    string res=s*(n/7);
    int m=n%7;
    if(m==1){
        res+="G";
    }
    if(m==2){
        res+="BG";
    }
    if(m==3){
        res+="BGY";
    }
    if(m==4){
        res+="IBGY";
    }
    if(m==5){
        res+="IBGYO";
    }
    if(m==6){
        res+="VIBGYO";
    }
    cout<<res;
    return 0;
}