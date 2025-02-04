#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
lli n,m;
cin>>n>>m;
string s;
int arr[100]={0};
int ans=0;
int siz=0;
for(int i=0;i<n;i++){
	cin>>s;
	arr[i]=s.size();
}
for(int i=0;i<n;i++){
if(siz+arr[i]<=m){
	ans=i+1;
	siz+=arr[i];
}else break;
}
cout<<ans<<endl;
return;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}