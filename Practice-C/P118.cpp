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
	vli a(n),b(n),c(n);
	for(lli i=0;i<n;i++)cin>>a[i];
	for(lli i=0;i<n;i++)cin>>b[i];
	for(lli i=0;i<n;i++)cin>>c[i];
	lli a0=0,b0=0,c0=0;
    lli tot=accumulate(a.begin(),a.end(),0LL);
    tot=ceil(double(tot)/3);
    lli prev=1,mx=0;
    vli res;
    for(lli i=0;i<n;i++){
       lli curr=i+1;
       if(a0!=-1)a0+=a[i];
       if(b0!=-1)b0+=b[i];
       if(c0!=-1)c0+=c[i];
       mx=max(max(a0,b0),c0);
       //cout<<c0<<endl;
       if(mx>=tot){
       	res.push_back(prev);
       	res.push_back(curr);
       	prev=curr+1;
       	//a0=0,b0=0,c0=0;
       	
       	if(mx==a0){
       		a0=-1;
       		if(b0==-1)b0=-1;
       		else b0=0;
       		if(c0==-1)c0=-1;
       		else c0=0;

           
       	}
       	else if(mx==b0){
       		b0=-1;
       		if(a0==-1)a0=-1;
       		else a0=0;
       		if(c0==-1)c0=-1;
       		else c0=0;

           
       	}
       	else {
       		c0=-1;
       		if(a0==-1)a0=-1;
       		else a0=0;
       		if(b0==-1)b0=-1;
       		else b0=0;

           
       	}

       }
    }
    if(res.size()<6)cout<<-1;
    else for(int i=0;i<6;i++)cout<<res[i]<<" ";
    cout<<endl;
    return;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}