#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
#define lli long long
#define lld long double
#define vli vector<long long>
#define vld vector<long double>

void solve(){
	string s;
        cin >> s;  
        for (lli i = 1; i < s.size(); i++) {
            while (i > 0 && s[i]-1 > s[i - 1]) {
                s[i]--;
                swap(s[i], s[i - 1]);
                i--;
            }
        }
        cout << s << endl;
    
    
    return;
}
int main(){
	lli t;
	cin>>t;
	while(t--)solve();
	return 0;
}
