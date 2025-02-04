#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>
 
void solve() {
    lli x, b;
    cin>>x>>b;
    //li mx=mi(x,b);
    set<lli>se;
    lli cnt = 0;
    lli mx;
    if(b>1e9){
        mx=x;
    }else{
        mx=b;
    }
    for (lli i=1;i<=mx; i++) {
        
        lli res=x^i;
        //cout<<i<<" "<<res<<" "<<b<<endl;
        if(res>b)continue;
        if(x==i)continue;
 
        
        lli y = x^i;
        if (x%i == 0) {
            se.insert(i);
            lli z1=x/i;
            lli z2=z1^i;
            if(z2<=b){
            se.insert(i);
            }
 
        }
        if(y%i==0){
        se.insert(i);
            lli z1=y/i;
            
            lli z2=z1^i;
            if(z2<=b){
            se.insert(i);
            }
        }
    }
    cout<<se.size()<<endl;
    }
    
int main(){
    lli t;
    cin>>t;
    while(t--)solve();
    return 0;
}