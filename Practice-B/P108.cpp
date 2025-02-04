#include <iostream>
#include <string>
using namespace std;
 
 
int main(){
 
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int q=s.length();
		int i=0;
		for ( i = 0; i < q; ++i)
		{
			if(s[i]=='0')break;
		}
		if(i==q)i=q-1;
		int m=i-1;
		int n=0;
		for(n=i;n<q&&m>=0;n++,m--){
			if(s[n]=='1')break;
		}
		m++;
		cout<<1<<" "<<q<<" "<<m+1<<" "<<m+q-i<<endl;
	}
}