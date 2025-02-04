#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
lli gcd(lli a, lli b)
{
if (b == 0)
return a;
return gcd(b, a % b);
}
lli lcm(lli a, lli b)
{
    return (a/gcd(a, b)) * b;
}

void solve(){
    lli a,b;
    cin>>a>>b;
  for(int i=a;i<=b;i++){
    if(i%a==i%b){
        cout<<i<<endl;
        return;
    }
  }
  cout<<lcm(a,b)<<endl;
  return;  
}
int main(){
    lli t;
    cin>>t;
    while(t--)solve();
    return 0;
}



