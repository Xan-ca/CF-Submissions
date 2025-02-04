// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// long double combinatorics(long double a,long double b,long double c){
//     if(a==c)return 1;
//     if(b==0)return 1;
//      //cout<<a/b*(combinatorics(a-1,b-1,c))<<endl;   
    
//     long double z=a/b*(combinatorics(a-1,b-1,c));
//     cout<<z<<endl;
//     return z;
    
// }
// int main(){
//     int a, b;
//     while(cin>>a>>b){
//         int c=a-b;
//         int l=b;
//         if(b>c){
//             swap(b,c);
//         }
//         //cout<<a<<b<<c;
//         unsigned long long int ans=combinatorics(double(a),double(b),double(c));
//         cout<<a<<" things taken "<<l<<" at a time is "<<ans<< " exactly."<<endl;
//     }
//     return 0;
// }
#include <cstdio>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int arr[101][101]={0};
    for(int i=0;i<101;i++){
        arr[i][0]=1;
        arr[i][i]=1;
    }
    for(int i=2;i<101;i++){
        for(int j=1;j<i;j++){
            
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    }
    int n,m;
   while (scanf("%d%d", &n, &m), n || m) {
		printf("%d things taken %d at a time is %lld exactly.\n", n, m,
				arr[n][m]);
	}return 0;
    
}