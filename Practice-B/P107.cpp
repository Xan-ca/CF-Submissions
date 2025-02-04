#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
lli n,x,y;
cin>>n>>x>>y;
x--;
y--;
vector<int>g(n,-1);
//g[0]=0;
for(int i=0;i<n;i++){
	for(int c=0;c<3;c++){
	lli a=i-1,b=i+1;
	if(a<0)a=n-1;
	if(b>=n)b=0;
      if(g[a]==c||g[b]==c)continue;
      if(i==x && g[y]==c)continue;
      if(i==y && g[x]==c)continue;
      g[i]=c;
      break;
	}
}
for(int i=0;i<n;i++)cout<<g[i]<<" ";
	cout<<endl;
return;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}