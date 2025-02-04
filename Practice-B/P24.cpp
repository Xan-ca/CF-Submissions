#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int isSubstring(string s1, string s2) 
{ 
    int M = s1.length(); 
    int N = s2.length(); 
  
    if(M>N)return -1;
    
    for (int i = 0; i <= N - M; i++)  
    { 
        int j; 
  
        
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
  
        if (j == M) 
            return i; 
    } 
    return -1; 
} 
int main(){
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        string s;
        cin>>s;
        int n;
        cin>>n;
        int pos=isSubstring(s,"1100");
        for(int i=0;i<n;i++){
            int q;
            char c;
            cin>>q>>c;
            s[q-1]=c;
            if(pos!=-1 && (q-1>pos+4 || q-1<pos)){
                cout<<"yes"<<endl;
            }else{
                int start=q-4;
                if(start<0)start=0;
                int end=min(7,(int)size(s)-start);
                string s1=s.substr(start,end);
                //cout<<start<<endl;
                //cout<<s1<<endl;
                pos=isSubstring("1100",s1);
                if(pos==-1){
                    cout<<"no"<<endl;
                    
                }else{
                    cout<<"yes"<<endl;
                    pos=isSubstring("1100",s1)+start;
                }
            }
            
        }

    }
    return 0;
}