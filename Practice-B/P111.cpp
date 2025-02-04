#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	int n;
	cin>>n;
	vli v(n);
	lli pos=0,neg=0;
	for(int i=0;i<n;i++){
	lli k;
	cin>>k;
	if(k>0){
	v[i]=1;
	}else{
	v[i]=-1;
	}
	}
	vli m(n);
	m[0]=v[0];
	for(int i=1;i<n;i++){
     m[i]=v[i];
     m[i]=m[i-1]*m[i];
	}
	//for(int i=0;i<n;i++)cout<<m[i]<<endl;
	lli p=0,ni=0;
	for(int i=0;i<n;i++){
		
		

	    if(m[i]==1){
	    	pos+=ni;
	    	neg+=p;
	    	neg++;
	    }else{
	    	pos+=p;
	    	neg+=ni;
	    	pos++;
	    }
	    if(m[i]>0)p++;
	    else ni++;
	    
	    //cout<<pos<<" "<<neg<<endl;
	}

	cout<<pos<<" "<<neg<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}