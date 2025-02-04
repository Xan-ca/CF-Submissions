#include<bits/stdc++.h>
using namespace std;
int division(int n){
	int lo=1;
	int hi=n;
	int mid;
	while(hi-lo>1){
		mid=(hi+lo)/2;

		if(floor(n/pow(3,mid))>0){
			
			lo=mid+1;
		}else{
			hi=mid;
		}
	}
	if(floor(n/(pow(3,lo)))==0){
		return lo;
	}else{
		return hi;
	}
}
int solve(){
	int l,r;
	cin>>l>>r;
	int res=0;
	int di=division(l);
	r++;
    int left=l;
	int next=0;
	while(next<r){
	next=pow(3,di);
    res+=di*((min(next,r)-left));
    	left=min(next,r);
    	di++;
	}
	//res+=di*((min(next,r)-l));
	cout<<res+division(l)<<endl;
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