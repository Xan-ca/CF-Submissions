#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	lli N;
	string st;
	string res;
	cin>>N>>st;
	if(N==2){
		if(st[0]!=st[1]){
			cout<<"NO"<<endl;
			return;
		}
}
	int n=0,s=0,e=0,w=0;
	if(N==4){
		for(lli i=0;i<N;i++){
		if(st[i]=='N')n++;
		if(st[i]=='S')s++;
		if(st[i]=='E')e++;
		if(st[i]=='W')w++;
		}
	if(n<2&&s<2&&e<2&&w<2){
		if(N==4){
			for(lli i=0;i<N;i++){
				if(st[i]=='N'||st[i]=='S')res+='R';
				else res+='H';
			}
			cout<<res<<endl;
			return;
		}
		
	}
}
n=0,s=0,e=0,w=0;
	
	for(lli i=0;i<N;i++){
	if(st[i]=='N'){
	if(n==0){
	n=1;
	res+='R';
	}
	else if(n==1){
	n=0;
	res+='H';
	}
	}
	if(st[i]=='E'){
	if(e==0){
	e=1;
	res+='R';
	}
	else if(e==1){
	e=0;
	res+='H';
	}
	}
	if(st[i]=='W'){
	if(w==0){
	w=1;
	res+='R';
	}
	else if(w==1){
	w=0;
	res+='H';
	}
	}
	if(st[i]=='S'){
	if(s==0){
	s=1;
	res+='R';
	}
	else if(s==1){
	s=0;
	res+='H';
	}
	}
	}
	if((n==0 && s==1) || (n==1 && s==0)){
	cout<<"NO"<<endl;
	return;
	}
    if((e==0 && w==1) ||( e==1 && w==0)){
	cout<<"NO"<<endl;
	return;
	}
	cout<<res<<endl;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}