#include<bits/stdc++.h>
using namespace std;
int cyclelen(vector<int>&vis,vector<int> &adj ,int curr){
	if(vis[curr]!=0)return 0;
	vis[curr]=1;
	return 1+cyclelen(vis,adj,adj[curr]);

}
int solve(){
	int n;
	cin>>n;
	vector<int> adj(n+1);
	int res=0;
	for(int i=1;i<=n;i++){
	cin>>adj[i];
	}
	vector<int> vis(n+1);
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
     int k=cyclelen(vis,adj,i);
     if(k==0 || k==1 || k==2)continue;
     if(k%2==1)res+=k/2;
     else res+=(k/2)-1;
	}
	cout<<res<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
	solve();
	}
}