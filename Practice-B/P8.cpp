#include<bits/stdc++.h>

using namespace std;
string s ;
int main(){
    cin >> s;int ans = 0;
    while(s.size()!=1){
        int n =0;for(int i=0;i<s.length();++i) n+=s[i]-'0';
        s = to_string(n);
        ans++; 
    } cout << ans << endl;
    return 0;
}