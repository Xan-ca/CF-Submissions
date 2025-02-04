#include<iostream>
using namespace std;
int main(){
   int n,h,temp;
   cin>>n;
   cin>>h;
   int res=0;
   for(int i=0;i<n;i++){
      res++;
      cin>>temp;
      if(temp>h){
        res++;
      }
   }
   cout<<res;
}