#include <bits/stdc++.h>
using namespace std;
int main(){
          int t;
          cin>>t;
          while(t--){
                    int n;
string s,r;
cin >> n >> s >> r;
int j=0;
int i;
for(i=0;i<n-1;i){
  while((i-1>=0 && s[i]!=s[i-1]) ||(s[i]!=s[i+1] && i+1<s.size())){
                  if(s[i]!=s[i+1] && i+1<s.size()){
                        s.erase(s.begin()+i);
                        s[i]=r[j++];
                        //cout<<s<<endl;
                        }else{
                           i--;
                         s.erase(s.begin()+i);
                        s[i]=r[j++];  
                        //cout<<s<<endl;
                        }
     
 }
                              
                              
                    i++;
                              
                              n=s.size();
                    }
                    //cout<<s<<endl;
                   // if( n==2 && s[i]!=s[i-1]) cout<<"YES";
                     if(s.size()==1) cout<<"YES";
                    else cout<<"NO";
                    cout<<endl;
          }
          
}