#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n;
	cin>>n;
	vector<pair<lli,lli>>vec(n);
	vli vec2(n*2+1,0);
	vector<pair<pair<lli,lli>,lli>>rang;
	unordered_map<lli,int>mp;
	string s;
	pair<lli,lli>p;
	for(lli i=0;i<n;i++){
		lli a,b;
		cin>>a>>b;
		p=make_pair(a,b);
		vec[i]={p,i};
		if(p.first==p.second){
			mp[p.first]+=1;
			vec2[p.first]=1;
		}
	}
	for(lli i=0;i<n*2;i++){
		if(vec[i]==1 && vec[i+1]==1){
			lli a=i;
			while(i<n*2+1 && vec[i]==1)i++;
			if(i==n*2+1)i--;
			lli b=i;
			rang.push_back(make_pair(a,b));
	}
	}
	sort(vec);
	//for(auto it :mp)cout<<it.first<<" "<<it.second<<endl;
	//cout<<endl;	
	for(lli i=0;i<n;i++){
		bool bul=false;
		for(lli j=vec[i].first.first;j<=vec[i].first.second;j++){
			 if(vec[i].first.first==vec[i].first.second){

				if(mp[j==1]){s[vec[i].second]="1";
								bul=true;
								break;}

				}
				

				if(mp.find(j)==mp.end()){
				s+="1";
				bul=true;
				break;
			}
			
		}
		if(bul==false)s[vec[i].second]="0";
	}
	cout<<s<<endl;
	return ;

}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}