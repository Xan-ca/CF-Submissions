#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long
void solve(){
  lli n, m, k;  
        string s;
        int ans=0;
        cin >> n >> m >> k >> s;

       

        lli i = 0;
        lli start=0;
        lli f=0;
        if(n<=m){
         while (i < n){
          if(s[i] == '1') f++;
         i++;
         }
         if(f>=1){
           cout<<0<<endl;
           return;
         }else{
           cout<<1<<endl;
           return;
         }
         
        }
        
        while (i < n) {
            if (s[i] == '0') {
              //cout<<i<<endl;
                lli j = i;
                while (i < n && s[i] == '0') {
                  
                    if(i<n && i+1-j==m){
                     // cout<<i<<endl;
                      ans++;
                      i+=k;
                      break;
                    }
                    i++;
                }
                //ans++;
              
            } else {
                i++;
            }
        }
        cout <<ans<< endl;
    }



int main() {
   lli t;  
    cin >> t;

    while (t--) solve();
    return 0;
}
