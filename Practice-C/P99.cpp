#include<bits/stdc++.h>
using namespace std;
int a[100002],c[100002];
string s;
int t,n,i,q,op,x,y,ans;
void solve(){
	cin>>n,ans=0;
	for(i=1;i<=n;i++)cin>>a[i],c[i]=c[i-1]^a[i];
	cin>>s>>q;
	for(i=0;i<s.size();i++)if(s[i]=='1')ans^=a[i+1];
	while(q--){
		cin>>op>>x;
		if(op==1){
			cin>>y;
			ans^=c[y]^c[x-1];
		}
		if(op==2)cout<<(ans^(x?0:c[n]))<<" ";
	}
	cout<<endl;
}
int main(){
	cin>>t;
	while(t--){
		solve();
	}
	
}