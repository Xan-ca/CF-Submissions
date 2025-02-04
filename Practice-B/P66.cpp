#include<bits/stdc++.h>
using namespace std;
#define ll long long
int solve(){
	ll int n;
	cin>>n;
	if(n==27){
		cout<<"1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 13 13 1 12"<<endl;
		return 0;
	}


	if(n%2==0){
		ll int j=1;
		for(ll int i=0;i<n;i++){
			cout<<j<<" ";
			if(i%2==1)j++;
		}
	}
	else{
		if(n<28){
			cout<<-1<<endl;
			return 0;
		}
		else{
			ll int j=2;
			ll int k=1;
			ll int l;
			for(ll int i=0;i<n;i++){

		    if(i==0 ||i==9 ||i==25 ){
		    	cout<<1<<" ";
		    	if(i==25){
		    		l=j;
		    		j++;
		    		k=1;
		    	}
		    	continue;
		    	
		    }
		    if(i==28){
		    	cout<<l<<" ";
		    	j++;
		    	k=1;
		    	continue;
		    }
			cout<<j<<" ";
			k++;
			if(k>2){
				k=1;
				j++;
			}
		}
		}
	}
	cout<<endl;
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}