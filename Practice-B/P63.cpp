#include<bits/stdc++.h>
using namespace std;
#define N 100000
#define ll long long
long long int dp[100000]={0};
 ll int recur(vector<int>&vect,int curr,int last){
	if(curr>=vect.size()/2)return 0;
    if(last>=0 && dp[curr]!=-1)return dp[curr];
	ll int pick=0,nopick=0;
	ll int update=vect[((curr+1)*2)-1];
	ll int did=0;
	ll int z=vect[((curr+1)*2)-2];
	if(z>=last){
		pick=recur(vect,curr+1,update);
		pick++;
		did=1;
	}
	nopick=recur(vect,curr+1,last);
    return dp[curr]=max(pick,nopick);
    return max(pick,nopick);
}
int solve(){
	ll int n;
	memset(dp,-1,sizeof(dp));
	cin>>n;
	ll int arr[n];
	map<ll int,ll int>mp;
	vector<int>vect;
	for(ll int i=0;i<n;i++){
	cin>>arr[i];
	}
	for(ll int i=1;i<n;i++){
	  arr[i]+=arr[i-1];
	}
	ll int res=0;
	if(arr[0]==0){
		res++;
	}
	mp[0]=0;
	for(ll int i=0;i<n;i++){
		if(mp.find(arr[i])==mp.end()){
			mp[arr[i]]=i;	
		}else{
			vect.push_back(mp[arr[i]]);
			vect.push_back(i);
			mp[arr[i]]=i;
		}

	}
	ll int mx=recur(vect,0,0);
    cout<<mx<<endl;
    return 0;
	
}
int main(){
	ll int t;
	cin>>t;
	while(t--)solve();
	return 0;
}