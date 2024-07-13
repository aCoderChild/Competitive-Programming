#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    set<int> diff;
    for (int i = 0; i < n-1; i++) {
        int d = abs(a[i] - a[i+1]);
        if (d>0 && d<n) diff.insert(d);
    }

    if (diff.size() == n-1) cout << "Jolly" << endl;
    else cout << "Not jolly" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        solve(n);
    }

    return 0;
}