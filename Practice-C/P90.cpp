#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<int>
#define vld vector<long double>

void solve(){
	vector<lli>C;
	vector<lli>H;
	vector<lli>D;
	vector<lli>S;
	lli n;
	cin>>n;
	char t;
	cin>>t;
	lli c=0,h=0,d=0,s=0;

	for(lli i=0;i<n*2;i++ ){
	string str;
	cin>>str;
	//cout<<str<<endl;
	if(str[1]=='C'){
		C.push_back(str[0]-'0');
	    c++;
	}
	if(str[1]=='H'){
	  h++;
	  H.push_back(str[0]-'0');
	}
	if(str[1]=='D'){
	  d++;
	  D.push_back(str[0]-'0');
	}
	if(str[1]=='S'){
	  s++;
	  S.push_back(str[0]-'0');
	}
	}
	sort(D.begin(),D.end());
	sort(C.begin(),C.end());
	sort(H.begin(),H.end());
	sort(S.begin(),S.end());
	if(t=='C'){
		//cout<<"c"<<endl;
		int c1=c,d1=d,h1=h,s1=s;
		s=s%2,d=d%2,h=h%2;

		if(c<s+d+h){

			cout<<"IMPOSSIBLE"<<endl;
			return;
		}

		if(d1>0){for(int i=0;i<D.size()-d;i+=2){
         cout<<D[i]<<"D "<<D[i+1]<<"D"<<endl;
		}}
		if(s1>0){for(int i=0;i<S.size()-s;i+=2){
         cout<<S[i]<<"S "<<S[i+1]<<"S"<<endl;
		}}
		if(h1>0){for(int i=0;i<H.size()-h;i+=2){
         cout<<H[i]<<"H "<<H[i+1]<<"H"<<endl;
		}}
		//cout<<C.size()<<endl;
		for(int i=0;i<C.size();i+=2){
			if(s==1){
				s--;
				cout<<S[S.size()-1]<<"S "<<C[i]<<"C "<<endl;
				i++;
			}
			if(d==1){
				d--;
				cout<<D[D.size()-1]<<"D "<<C[i]<<"C "<<endl;
				i++;
			}
			if(h==1){
				h--;
				cout<<H[H.size()-1]<<"H "<<C[i]<<"C "<<endl;
				i++;
			}
			for(i;i<C.size()-1;i+=2)cout<<C[i]<<"C "<<C[i+1]<<"C"<<endl;
		}
		//return;

	}
	if(t=='H'){
		int c1=c,d1=d,h1=h,s1=s;
	s=s%2,d=d%2,c=c%2;
	if(h<s+d+c){

			cout<<"IMPOSSIBLE"<<endl;
			return;
		}
	if(d1>0){for(int i=0;i<D.size()-1;i+=2){
         cout<<D[i]<<"D "<<D[i+1]<<"D"<<endl;
		}
	}
		if(s1>0){for(int i=0;i<S.size()-1;i+=2){
         cout<<S[i]<<"S "<<S[i+1]<<"S"<<endl;
		}
	}
		if(c1>0){for(int i=0;i<C.size()-1;i+=2){
         cout<<C[i]<<"C "<<C[i+1]<<"C"<<endl;
		}
	}
	//cout<<H.size()<<endl;
		for(int i=0;i<H.size();i+=2){
			if(s==1){
				s--;
				cout<<S[S.size()-1]<<"S "<<H[i]<<"H "<<endl;
				i++;
			}
			if(d==1){
				d--;
				cout<<D[D.size()-1]<<"D "<<H[i]<<"H "<<endl;
				i++;
			}
			if(c==1){
				c--;
				cout<<C[C.size()-1]<<"C "<<H[i]<<"H "<<endl;
				i++;
			}
			for(i;i<H.size()-1;i+=2)cout<<H[i]<<"H "<<H[i+1]<<"H"<<endl;
		}
	}
	if(t=='D'){
		int c1=c,d1=d,h1=h,s1=s;

	s=s%2,c=c%2,h=h%2;

	if(d<s+h+c){

			cout<<"IMPOSSIBLE"<<endl;
			return;
		}
		if(c1>0){
			for(int i=0; i<C.size()-1;i+=2){
         cout<<C[i]<<"C "<<C[i+1]<<"C"<<endl;
		}
		}
	if(s1>0){
		for(int i=0;i<S.size()-1;i+=2){
         cout<<S[i]<<"S "<<S[i+1]<<"S"<<endl;
		}
	}
		
		if(h1>0){for(int i=0;i<H.size()-1;i+=2){
         cout<<H[i]<<"H "<<H[i+1]<<"H"<<endl;
		}
	}
		for(int i=0;i<D.size();i+=2){
			if(s==1){
				s--;
				cout<<S[S.size()-1]<<"S "<<D[i]<<"D "<<endl;
				i++;
			}
			if(h==1){
				h--;
				cout<<H[H.size()-1]<<"H "<<D[i]<<"D "<<endl;
				i++;
			}
			if(c==1){
				c--;
				cout<<C[C.size()-1]<<"C "<<D[i]<<"D"<<endl;
				i++;
			}
			for(i;i<D.size()-1;i+=2)cout<<D[i]<<"D "<<D[i+1]<<"D"<<endl;
		}
	}
	if(t=='S'){
		//cout<<s<<c<<d<<h<<endl;
		int c1=c,d1=d,h1=h,s1=s;
	c=c%2,d=d%2,h=h%2;
	if(s<d+h+c){

			cout<<"IMPOSSIBLE"<<endl;
			return;
		}
	if(d1>0){
		for(int i=0;i<D.size()-1;i+=2){
         cout<<D[i]<<"D "<<D[i+1]<<"D"<<endl;
		}
	}
		if(c1>0){
			for(int i=0;i<C.size()-1;i+=2){
         cout<<C[i]<<"C "<<C[i+1]<<"C"<<endl;
		}
	}
		 if(h1>0){
		 	for(int i=0;i<H.size()-1;i+=2){
          cout<<H[i]<<"H "<<H[i+1]<<"H"<<endl;
		 }
		}
		//cout<<S.size()<<endl;
		for(int i=0;i<S.size();i+=2){
			//cout<<"hi";
			if(d==1){
				d--;
				cout<<D[D.size()-1]<<"D "<<S[i]<<"S"<<endl;
				i++;
			}
			if(h==1){
				h--;
				cout<<H[H.size()-1]<<"H "<<S[i]<<"S "<<endl;
				i++;
			}
			if(c==1){
				c--;
				cout<<C[C.size()-1]<<"C "<<S[i]<<"S"<<endl;
				i++;
			}
			for(i;i<S.size()-1;i+=2)cout<<S[i]<<"S "<<S[i+1]<<"S"<<endl;
		}
	}
	return;
	
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}