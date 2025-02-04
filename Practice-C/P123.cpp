#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
lli dfs(vector<vector<lli>>&adj,vli &vis,lli node){
	//return 2;
    vis[node]=1;
    if(adj[node].size()==1)return 1;
	
	if(vis[adj[node][0]]==0){
		return dfs(adj,vis,adj[node][0])+1;
	}
	else if(vis[adj[node][1]]==0){
		return dfs(adj,vis,adj[node][1])+1;
	}
	
}
void solve(){
	lli n,t;
	cin>>n>>t;
	//vli vt(t);
	vector<vector<lli>>adj(n+1);
    for(lli i=0;i<n-1;i++){
    lli a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    }
    lli node;
    cin>>node;
    vli vis(n+1,0);
    vis[node]=1;
    if(adj[node].size()==1){
    if(n%2==0)cout<<"Ron"<<endl;
    else cout<<"Hermione"<<endl;
    return;
    }
   
    lli len1=dfs(adj,vis,adj[node][0])+1;
    lli len2=dfs(adj,vis,adj[node][1])+1;
    //cout<<len1<<len2;
    if((len1%2)==0 || (len2%2)==0)cout<<"Ron"<<endl;
    else cout<<"Hermione"<<endl;
    
    return ;
}
int main(){
	lli t=1;
	while(t--)solve();
	return 0;
}