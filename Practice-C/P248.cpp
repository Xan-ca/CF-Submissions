#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int t , n , m , low[N] , num[N] , cnt , stt[N] , sl , ans , dem[N] , a[N];
int ck[N];
vector<int> mp[N] , nmp[N];
stack<int> st;
void dfs(int u){
    low[u] = num[u] = ++cnt;
    st.push(u);
    for(auto x : mp[u]){
        if(stt[x]) continue;
        if(!num[x]){
            dfs(x);
            low[u] = min(low[x],low[u]);
        }else low[u] = min(low[u],num[x]);
    }
    if(low[u] == num[u]){
        sl++;
        int v;
        do{
            ck[sl]++;
            v = st.top();
            st.pop();
            stt[v] = sl;
        }while (v != u);
    }
}
queue<pair<int,int>> ls;
int solve(int u){
    int res = 1;
    for(auto x : nmp[u]) res += solve(x);
    return res;
}
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1 ; i <= n ; i++){
            cin>>a[i];
            mp[i].push_back(a[i]);
        }
        for(int i = 1 ; i <= n ; i++){
            if(!num[i]) dfs(i);
        }
        for(int i = 1 ; i <= n ; i++){
            if(!stt[i]){
                sl++;
                stt[i] = sl;
            }
        }
        for(int i = 1 ; i <= n ; i++){
            if(ck[stt[i]] == 1 && ck[stt[a[i]]] == 1){
                nmp[stt[a[i]]].push_back(stt[i]);
                dem[stt[i]]++;
            }
        }
        for(int i = 1 ; i <= sl ; i++){
            if(ck[i] == 1 && !dem[i]){
                ans = max(ans,solve(i));
            }
        }
        cout<<ans+2<<'\n';
        for(int i = 1 ; i <= n ; i++){
            mp[i].clear();
            nmp[i].clear();
            num[i] = 0;
            low[i] = 0;
            dem[i] = 0;
            sl = 0;
            stt[i] = 0;
            ans = 0;
            ck[i] = 0;
        }
    }
}