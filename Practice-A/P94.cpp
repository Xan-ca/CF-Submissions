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
	lli odd=0,eve=0,odsum=0,evsum=0;
	for(int i=0;i<n;i++){
	lli num;
	cin>>num;
	if(i%2==0){
	odd++;
	odsum+=num;
	}
	else{
	eve++;
	evsum+=num;
	}
	}
	if((evsum % eve==0 && odsum % odd==0)&&(evsum/eve==odsum/odd)){
	cout<<"YES"<<endl;
	}else{
	cout<<"NO"<<endl;
	}
	return ;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}