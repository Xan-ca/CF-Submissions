#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli n,k;
	cin>>n>>k;
	vli res;
	lli mxrep=ceil(double(n)/k);
	lli mnrep=floor(double(n)/k);
	lli nmx=n%k;
	lli ele=0;
	lli rep=0;
	for(lli i=1;i<=n;i++){
	   ele++;
	   res.push_back(i);
	   if(ele<=nmx){
	   rep=mxrep;
	   }else{
	   rep=mnrep;
	   }
	   
       i+=rep-1;
       i++;
       //for(lli i=k-1+ele;i)
       //cout<<i<<endl;
       ele++;
       if(ele<=nmx){
	   rep=mxrep;
	   }else{
	   rep=mnrep;
	   }
	   i+=rep-1;
       if(i<=n)res.push_back(i);

	}
	for(lli i=k;i<n;i++){
		res.push_back(res[i-k]+1);
        i++;
        if(i<n)res.push_back(res[i-k]-1);
	}
		for(lli i=0;i<n;i++)cout<<res[i]<<" ";
			cout<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}