#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define inf 1e6;

int solve(){
	ll int n,m,l;
	cin>>n>>m>>l;
	vector<pair<ll int,ll int>>ob;
	vector<vector<ll int>> power(n);
	for(int i=0;i<n;i++){
	ll int a,b;
	cin>>a>>b;
	ob.push_back(make_pair(a,b));
	}
	ll int j=0;

	 for(int i=0;i<m;i++){
	 int a,b;
	 cin>>a>>b;
	 while(j<ob.stze() && a>ob[j].first){
		j++;
	 }
	 //if(j>ob.size())
	 power[j].push_back(b);

	}
	priority_queue<int>pq;
	int jump=0;
	int res=0;
     for (int i = 0; i < ob.size(); i++)
    {
        for (int k = 0; k < power[i].size(); k++)
        {
          pq.push(power[i][k]); 
        }    
        while(pq.size()>0 && jump<ob[i].second-ob[i].first+1){
        	jump+=pq.top();
        	pq.pop();
        	res++;
        }
        if(pq.size()==0 && jump<ob[i].second-ob[i].first+1){
        	//cout<<jump<<endl;
        	res=-1;
        	break;
        }
    }
    //cout<<jump<<endl;
    cout<<res<<endl;
	
	
    return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
	solve();
	}
	return 0;
}