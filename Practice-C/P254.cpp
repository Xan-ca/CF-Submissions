#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 /*
 a 1 msb can guarantee consume till the first 1 bit and ig then we have to check and then gurantee cant consume if it encounters another 1
 a 0 bits can only ig consume upto before the 1st 1 bit
 Note : the difference bet mine and the intenden solution was to calculate the no of fisrt slime  left to current position with msb less than a certain msb(1,30) for each position of 1 resulting
 in a 2d array of 30*n size and a tc of just n log n instead of my n log^2 n(with sparse table)
 the prefix making array of intended solution is a nice idea to think and use because as we are doing query on the same msb array why not find the solution precomputatively as the
 queries are non persistent and get soltuion for each msb for each bit
 */
//segtree template
 #define ll long long
 template<class T, class U>
 // T -> node, U->update.
 struct Lsegtree{
     vector<T>st;
     vector<U>lazy;
     ll n;
     T identity_element;
     U identity_update;
     Lsegtree(ll n, T identity_element, U identity_update)
     {
         this->n = n;
         this->identity_element = identity_element;
         this->identity_update = identity_update;
         st.assign(4*n,identity_element);
         lazy.assign(4*n, identity_update);
     }
     T combine(T l, T r)
     {
         // change this function as required.
         T ans = max(l , r);
         return ans;
     }
     void buildUtil(ll v, ll tl, ll tr, vector<T>&a)
     {
         if(tl == tr)
         {
             st[v] = a[tl];
             return;
         }
         ll tm = (tl + tr)>>1;
         buildUtil(2*v + 1, tl, tm,a);
         buildUtil(2*v + 2,tm+1,tr,a);
         st[v] = combine(st[2*v + 1], st[2*v + 2]);
     }
     // change the following 2 functions, and you're more or less done.
     T apply(T curr, U upd, ll tl, ll tr)
     {
         T ans = (tr-tl+1)*upd;
         return ans;
     }
     U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
     {
         U ans = old_upd;
         ans=new_upd;
         return ans;
     }  
     void push_down(ll v, ll tl, ll tr)
     {
         if(lazy[v] == identity_update)return;
         st[v] = apply(st[v], lazy[v], tl, tr);
         if(2*v + 2 < 4*n)
         {
             ll tm = (tl + tr)>>1;
             lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm);
             lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr);            
         }
         lazy[v] = identity_update;
     }
     T queryUtil(ll v, ll tl, ll tr, ll l, ll r)
     {
         push_down(v,tl,tr);
         if(l > r)return identity_element;
         if(tr < l or tl > r)
         {
             return identity_element;
         }
         if(l <= tl and r >= tr)
         {
             return st[v];
         }
         ll tm = (tl + tr)>>1;
         return combine(queryUtil(2*v+1,tl,tm,l,r), queryUtil(2*v+2,tm+1,tr,l,r));
     }
  
     void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd)
     {
         push_down(v,tl,tr); 
         if(tr < l or tl > r)return;
         if(tl >=l and tr <=r)
         {
             lazy[v] = combineUpdate(lazy[v],upd,tl,tr);
             push_down(v,tl,tr);
         }
         else
         {
             ll tm = (tl + tr)>>1;
             updateUtil(2*v+1,tl,tm,l,r,upd);
             updateUtil(2*v+2,tm+1,tr,l,r,upd);
             st[v] = combine(st[2*v + 1], st[2*v+2]);
         }
     }
 
 
 
     void build(vector<T>a)
     {
         assert(a.size() == n);
         buildUtil(0,0,n-1,a);
     }
     T query(ll l, ll r)
     {
         return queryUtil(0,0,n-1,l,r);
     }
     void update(ll l,ll r, U upd)
     {
         updateUtil(0,0,n-1,l,r,upd);
     }
 };
 //starts here
void Solve() 
{
    ll n,z;
    cin>>n>>z;
    map<ll,ll>sol;
    vector<int>v(n);
    vector<int>xorv(n+1);
    for(auto &it:v)cin>>it;
    v.push_back(0);
    reverse(v.begin(),v.end());
    vector<int>msb(n+1);
    msb[0]=0;
    xorv[0]=0;
    for(int i=0;i<n;i++){
        xorv[i+1]=v[i+1]^xorv[i];
        int k=  __builtin_clz(v[i+1]);
        msb[i+1]=31-k+1;
    }
        Lsegtree <int,int>st(n+1,0,0);
    st.build(msb);
    for(ll r=1;r<=z;r++){
    int x;
    cin>>x;
    ll f=x;
    if(sol.find(f)!=sol.end()){
        cout<<sol[f]<<" ";
        continue;
    }
    int k=0;
    int res=0;
    while(res<n && x>=v[res+1]){
    k++;
    int msbx=31-__builtin_clz(x)+1;

    int hi=n+1;
    int lo=res;
    
    while(hi-lo>1){
        int mid=((hi-lo)/2)+lo;
        if(st.query(res+1,mid)<msbx){
              lo=mid;
        }else{
            hi=mid;
        }
    }
    if(lo==n){
        res=n;
        break;
    }
    x^=(xorv[lo]^xorv[res]);
    res=lo;
    if(x>=v[hi]){
        x^=v[hi];
        res=hi;
        if(res>=n)break;
    }else{
        break;
    }
    }
    sol[f]=res;
    cout<<res<<" ";
    }
    
    cout<<endl;
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