
#include<bits/stdc++.h>
using namespace std;
int T,n,d;
long long int c;
int a[200010];
bool cmp(int a,int b) {
return a>b;
}
int main() {
cin>>T;
while(T--) {
cin>>n>>c>>d;
for(int i=0; i<n; i++)cin>>a[i];
sort(a,a+n,cmp);
int l=0,r=d+1;
while(l<r) {
int m=(r+l+1)/2;
long long int ans=0;
for(int i=0; i<d; i++) {
if(i%m<n)ans+=a[i%m];
}
if(ans>=c)l=m;
else r=m-1;
}
if(l==0) puts("Impossible");
else if(l==d+1) puts("Infinity");
else cout<<l-1<<endl;
}
return 0;
}