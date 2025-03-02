#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e17
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool dfs(ll n,ll m,pair<ll,ll>curr,string &s,vector<vector<char>> &grid,vector<vector<ll>> &pdis,vector<vector<ll>> &dis,vector<vector<ll>> &vis){

    vis[curr.first][curr.second]=1;
    if((curr.first==0 || curr.first==n-1)|| (curr.second==0|| curr.second==m-1))return true;
    if(curr.first-1>=0) if((grid[curr.first-1][curr.second]=='.'||grid[curr.first-1][curr.second]=='B')){

        if(pdis[curr.first-1][curr.second]<dis[curr.first-1][curr.second] && vis[curr.first-1][curr.second]==0){
            s+='U';
         if(dfs(n,m,{curr.first-1,curr.second},s,grid,pdis,dis,vis))return true;  
            s.pop_back();
        }
      
   }
    if(curr.first+1<=n-1) if((grid[curr.first+1][curr.second]=='.'||grid[curr.first+1][curr.second]=='B')){

        if(pdis[curr.first+1][curr.second]<dis[curr.first+1][curr.second] && vis[curr.first+1][curr.second]==0){
            s+='D';
          if(dfs(n,m,{curr.first+1,curr.second},s,grid,pdis,dis,vis))return true;  
          s.pop_back();
        }
       
     }
    if(curr.second-1>=0) if((grid[curr.first][curr.second-1]=='.'||grid[curr.first][curr.second-1]=='B')){

        if(pdis[curr.first][curr.second-1]<dis[curr.first][curr.second-1] && vis[curr.first][curr.second-1]==0){
            s+='L';
           if(dfs(n,m,{curr.first,curr.second-1},s,grid,pdis,dis,vis))return true;  
           s.pop_back();
        }
      
          
       }
    if(curr.second+1<=m-1) if((grid[curr.first][curr.second+1]=='.'||grid[curr.first][curr.second+1]=='B')){

        if(pdis[curr.first][curr.second+1]<dis[curr.first][curr.second+1] &&  vis[curr.first][curr.second+1]==0){
            s+='R';
            if(dfs(n,m,{curr.first,curr.second+1},s,grid,pdis,dis,vis))return true; 
            s.pop_back();  
        }

         }
     
     return false;

}
void Solve() 
{
    ll n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    vector<vector<ll>>dis(n,vector<ll>(m,INF));
    vector<vector<ll>>pdis(n,vector<ll>(m,INF));
    vector<vector<string>>seq(n,vector<string>(m,""));
    vector<pair<ll,ll>>msrc;
    pair<ll,ll>dest,src;
    for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
        char c;
        cin>>c;
        if(c=='A')src={i,j};
        if(c=='M') msrc.push_back({i,j});
        grid[i][j]=c;
    }
    } 

    queue<pair<ll,pair<ll,ll>>>q;
        q.push({0,src});

        pdis[src.first][src.second]=0;
        pair<ll,ll>curr;
         while(!q.empty()){
            curr=q.front().second;
            q.pop();
             if(curr.first-1>=0) if((grid[curr.first-1][curr.second]=='.'||grid[curr.first-1][curr.second]=='B')){

         if(pdis[curr.first-1][curr.second]>pdis[curr.first][curr.second]+1){
            pdis[curr.first-1][curr.second]=pdis[curr.first][curr.second]+1 ;
          //  seq[curr.first-1][curr.second]=seq[curr.first][curr.second]+'U';
            q.push({pdis[curr.first-1][curr.second],{curr.first-1,curr.second}});
        }
      
   }
    if(curr.first+1<=n-1) if((grid[curr.first+1][curr.second]=='.'||grid[curr.first+1][curr.second]=='B') ){

         if(pdis[curr.first+1][curr.second]>pdis[curr.first][curr.second]+1){
            pdis[curr.first+1][curr.second]=pdis[curr.first][curr.second]+1;
          //  seq[curr.first+1][curr.second]=seq[curr.first][curr.second]+'D';
            q.push({ pdis[curr.first+1][curr.second],{curr.first+1,curr.second}});
    }
       
     }
    if(curr.second-1>=0) if((grid[curr.first][curr.second-1]=='.'||grid[curr.first][curr.second-1]=='B')){

         if(pdis[curr.first][curr.second-1]>pdis[curr.first][curr.second]+1){
            pdis[curr.first][curr.second-1]=pdis[curr.first][curr.second]+1;
           // seq[curr.first][curr.second-1]=seq[curr.first][curr.second]+'L';
            q.push({pdis[curr.first][curr.second-1],{curr.first,curr.second-1}});
        }
      
          
       }
    if(curr.second+1<=m-1) if((grid[curr.first][curr.second+1]=='.'||grid[curr.first][curr.second+1]=='B')){

         if(pdis[curr.first][curr.second+1]>pdis[curr.first][curr.second]+1){
            pdis[curr.first][curr.second+1]=pdis[curr.first][curr.second]+1;
           // seq[curr.first][curr.second+1]=seq[curr.first][curr.second]+'R';
            q.push({pdis[curr.first][curr.second+1],{curr.first,curr.second+1}});
        }

         }
     }

    //q.clear(); 
    
    //queue<pair<ll,pair<ll,ll>>>q;
        for(ll i=0;i<msrc.size();i++){
            q.push({0,msrc[i]});
            dis[msrc[i].first][msrc[i].second]=0;
        }

        dis[src.first][src.second]=0;
        //pair<ll,ll>curr;
         while(!q.empty()){
            curr=q.front().second;
            q.pop();
    if(curr.first-1>=0) if((grid[curr.first-1][curr.second]=='.'||grid[curr.first-1][curr.second]=='B')){

         if(dis[curr.first-1][curr.second]>dis[curr.first][curr.second]+1){
            dis[curr.first-1][curr.second]=dis[curr.first][curr.second]+1 ;
          //  seq[curr.first-1][curr.second]=seq[curr.first][curr.second]+'U';
            q.push({dis[curr.first-1][curr.second],{curr.first-1,curr.second}});
        }
      
   }
    if(curr.first+1<=n-1) if((grid[curr.first+1][curr.second]=='.'||grid[curr.first+1][curr.second]=='B') ){

         if(dis[curr.first+1][curr.second]>dis[curr.first][curr.second]+1){
            dis[curr.first+1][curr.second]=dis[curr.first][curr.second]+1;
          //  seq[curr.first+1][curr.second]=seq[curr.first][curr.second]+'D';
            q.push({ dis[curr.first+1][curr.second],{curr.first+1,curr.second}});
    }
       
     }
    if(curr.second-1>=0) if((grid[curr.first][curr.second-1]=='.'||grid[curr.first][curr.second-1]=='B')){

         if(dis[curr.first][curr.second-1]>dis[curr.first][curr.second]+1){
            dis[curr.first][curr.second-1]=dis[curr.first][curr.second]+1;
           // seq[curr.first][curr.second-1]=seq[curr.first][curr.second]+'L';
            q.push({dis[curr.first][curr.second-1],{curr.first,curr.second-1}});
        }
      
          
       }
    if(curr.second+1<=m-1) if((grid[curr.first][curr.second+1]=='.'||grid[curr.first][curr.second+1]=='B')){

         if(dis[curr.first][curr.second+1]>dis[curr.first][curr.second]+1){
            dis[curr.first][curr.second+1]=dis[curr.first][curr.second]+1;
           // seq[curr.first][curr.second+1]=seq[curr.first][curr.second]+'R';
            q.push({dis[curr.first][curr.second+1],{curr.first,curr.second+1}});
        }

         }
     }
     vector<vector<ll>>vis(n,vector<ll>(m,0));
     string s="";
     
     if(dfs(n,m,src,s,grid,pdis,dis,vis)){
         cout<<"YES"<<endl;
         cout<<s.size()<<endl;
         cout<<s<<endl;
     }else  cout<<"NO"<<endl;
return;

}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
   // cin >> t;
    for(ll i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}