#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
using ll = long long;

vector<int> d[N];
void solve() {
  int n, m; cin >> n >> m;
  vector<int> s(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> s[i];
  }
  vector<int> a(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    set<int> banned;
    for (int j: d[i]) {
      banned.insert(a[j]);
    }
    for (int k = m; k >= 1; k--) {
        if (banned.find(s[k]) == banned.end()) {
            a[i] = s[k];
            break;
        }
    }
    if (a[i] == -1) {
        cout << -1 << '\n';
        return;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
        d[j].push_back(i);
    }
  }
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}