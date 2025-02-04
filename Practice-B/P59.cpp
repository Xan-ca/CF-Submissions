#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first+a.second != b.first+b.second)
        return (a.first+a.second < b.first+b.second);
    else
       return (a.second > b.second);
}
int solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>vect;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vect.push_back({a,b});
    }
    sort(vect.begin(),vect.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<vect[i].first<<" "<<vect[i].second<<" ";
    }
    cout<<endl;
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}