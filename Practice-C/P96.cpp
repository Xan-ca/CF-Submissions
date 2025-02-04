 #include<bits/stdc++.h>
 using namespace std;
 #define inf 10000000
 #define lli long long
 #define lld long double
 #define vli vector<long long>
 #define vld vector<long double>
 
 void solve(){
 	lli n,m;
 	cin>>n>>m;
 	vli vn(n);
 	vli vm(m);
 	//int cr;
 	//cin>>cr;
 	for(lli i=0;i<n;i++){
        cin>>vn[i];
 	}
 	for(lli i=0;i<m;i++){
 		cin>>vm[i];
 	}
 	lli cr=vn[0];
 	vli vx(m);
 	sort(vn.begin(),vn.end());
 	sort(vm.begin(),vm.end());

 	auto it = std::lower_bound(vn.begin(), vn.end(), cr);
    int pos= vn.end() - it;
    for(int i=0;i<m;i++){
    	if(vm[i]<=cr){
    		vx[i]=1;
    		continue;
    	}
    auto it2 = std::lower_bound(vn.begin(), vn.end(), vm[i]);
    int pos2= vn.end() - it2;
    vx[i]=pos2+1;
    }
        sort(vx.begin(),vx.end());
       vli res(m,0);
     

    for(lli i=1;i<=m;i++){
    	for(lli j=i-1;j<m;j+=i){
    		res[i-1]+=vx[j];
    	}
    }
    for(int i=0;i<m;i++)cout<<res[i]<<" ";
cout<<endl;

 }
 int main(){
 	lli t;
 	cin>>t;
 	while(t--)solve();
 	return 0;
 }