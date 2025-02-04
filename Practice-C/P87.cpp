#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
lli ANS;
map<lli,lli>mp;
bool isPerfectSquare(long long x)
{
    if (x > 0) {

        long long sr = sqrt(x);

        return (sr * sr == x);
    }
 
    return false;
}
void permut(string s,string curr ,lli n ,lli size,lli num,lli iter){
	if(mp.find(num)!=mp.end())return;
	else{
		mp[num]=1;
	}

  if(iter==size+1)return;

  //cout<<num<<" "<<iter<<endl;


if(isPerfectSquare(num)){
  //cout<<num<<" "<<iter<<endl;
ANS=min(size-n,ANS);	
}

permut(s,curr,n,size,num,iter+1);

for(lli i=iter;i<size;i++){
	if(curr[i]=='0'){
	if(n==0 && s[i]=='0')continue;
	curr[i]=1;
	permut(s,curr,n+1,size,num*10+abs(s[i]-'0'),i);
	curr[i]=0;
}

}
	
}

void solve(){
	ANS=INT_MAX;
	mp.clear();

	string s;
	cin>>s;
	lli taken[9]={0};
	lli size=s.size();
	permut(s,"0000000000",0,size,0,0);
	if(ANS==INT_MAX)cout<<-1<<endl;
	else cout<<ANS<<endl;
	
	
}
int main(){
	lli t=1;
	//cin>>t;
	while(t--)solve();
	return 0;
}