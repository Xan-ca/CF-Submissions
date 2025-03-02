#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 bool anycommon(string s1,string s2){
 	if(s1[0]== s2[0]|| s1[0]==s2[1])return true;
 	if(s1[1]== s2[0]|| s1[1]==s2[1])return true;
 	return false;
 }
 ll test_ID=0;
void Solve() 
{
    ll n,k;
    cin>>n>>k;
    vector<string>v(n+1);
    vector<ll>a,b,c;
    v[0]="hi";
    string temp;
    for(ll i=1;i<n+1;i++){
    	cin>>temp;
    	v[i]=temp;
    	
    	if((temp=="BR"|| temp=="GY")|| (temp=="BY" || temp=="GR") ){
    		a.push_back(i);
    	
    	}
        if((temp=="BG"|| temp=="RY")|| (temp=="BY"|| temp=="GR") ){
    		b.push_back(i);
    	
    	}
    	if((temp=="BR"|| temp=="GY")|| (temp=="BG"|| temp=="RY") ){
    		c.push_back(i);
    		
    	}
    	
    
    }

    for(ll i=0;i<k;i++){
    	test_ID++;
    
    	ll res=INF,ress=INF,resd=INF;
    	ll temp1,temp2;
    	cin>>temp1>>temp2;
    	
    	ll ahed=0,bhed=0;
        if(!anycommon(v[temp1],v[temp2])){
        	ll src=min(temp1,temp2);
        	ll dest=max(temp1,temp2);
        	string tp=v[src];
        	{
        		if(tp =="BG"|| tp=="RY"){
        			ll res1=INF,res2=INF;
        			auto it1=lower_bound(a.begin(),a.end(),src);
        			auto it2=upper_bound(a.begin(),a.end(),src);
        			(it1!=a.begin())?bhed=*(it1-1):bhed=0;
        			(it2!=a.end())?ahed=*it2:ahed=0;
        			if(bhed>0)res1=abs(src-bhed)+abs(dest-bhed);
        			if(ahed>0)res2=abs(src-ahed)+abs(dest-ahed);
        			ress=min(res1,res2);
        		}
        		if(tp=="BR"|| tp=="GY"){
        			ll res1=INF,res2=INF;
        			auto it1=lower_bound(b.begin(),b.end(),src);
        			auto it2=upper_bound(b.begin(),b.end(),src);
        			(it1!=b.begin())?bhed=*(it1-1):bhed=0;
        			(it2!=b.end())?ahed=*it2:ahed=0;
        			if(bhed>0)res1=abs(src-bhed)+abs(dest-bhed);
        			if(ahed>0)res2=abs(src-ahed)+abs(dest-ahed);
        			ress=min(res1,res2);
        		}
        		if(tp=="BY"|| tp=="GR"){
        			ll res1=INF,res2=INF;
        			auto it1=lower_bound(c.begin(),c.end(),src);
        			auto it2=upper_bound(c.begin(),c.end(),src);
        			(it1!=c.begin())?bhed=*(it1-1):bhed=0;
        			(it2!=c.end())?ahed=*it2:ahed=0;
        			if(bhed>0)res1=abs(src-bhed)+abs(dest-bhed);
        			if(ahed>0)res2=abs(src-ahed)+abs(dest-ahed);
        			ress=min(res1,res2);
        		}
        	
        	swap(src,dest);
        	if(tp =="BG"|| tp=="RY"){
        			ll res1=INF,res2=INF;
        			auto it1=lower_bound(a.begin(),a.end(),src);
        			auto it2=upper_bound(a.begin(),a.end(),src);
        			(it1!=a.begin())?bhed=*(it1-1):bhed=0;
        			(it2!=a.end())?ahed=*it2:ahed=0;
        			if(bhed>0)res1=abs(src-bhed)+abs(dest-bhed);
        			if(ahed>0)res2=abs(src-ahed)+abs(dest-ahed);
        			resd=min(res1,res2);
        		}
        		if(tp=="BR"|| tp=="GY"){
        			ll res1=INF,res2=INF;
        			auto it1=lower_bound(b.begin(),b.end(),src);
        			auto it2=upper_bound(b.begin(),b.end(),src);
        			(it1!=b.begin())?bhed=*(it1-1):bhed=0;
        			(it2!=b.end())?ahed=*it2:ahed=0;
        			if(bhed>0)res1=abs(src-bhed)+abs(dest-bhed);
        			if(ahed>0)res2=abs(src-ahed)+abs(dest-ahed);
        			resd=min(res1,res2);
        		}
        		if(tp=="BY"|| tp=="GR"){
        			ll res1=INF,res2=INF;
        			auto it1=lower_bound(c.begin(),c.end(),src);
        			auto it2=upper_bound(c.begin(),c.end(),src);
        			(it1!=c.begin())?bhed=*(it1-1):bhed=0;
        			(it2!=c.end())?ahed=*it2:ahed=0;
        			if(bhed>0)res1=abs(src-bhed)+abs(dest-bhed);
        			if(ahed>0)res2=abs(src-ahed)+abs(dest-ahed);
        			resd=min(res1,res2);
        		}
        	}
        	res=min(resd,ress);
        	if(res!=INF)cout<<res<<endl;
        	else cout<<-1<<endl;
        }
        	else{
        		cout<<abs(temp2-temp1)<<endl;
        	}
    }

}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(ll i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}