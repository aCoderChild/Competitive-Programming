#include <bits/stdc++.h>
using namespace std;

void solve() {
    //a board, starting from 1

    char c;
    int row, col;
    cin >> c >> row >> col;

    if (c == 'r') {
        cout << min(row, col) << endl;
        return;
    }

    if (c == 'k') {
        if (row % 2 == 1) {
            if (col % 2 == 0) cout << (row / 2) * (col / 2) + (row / 2 + 1) * (col / 2) << endl;
            else cout << (row / 2) * (col / 2) + (row / 2 + 1) * (col / 2 + 1) << endl;
        } 

        else {
            if (col % 2 == 0) cout << (row / 2) * (col / 2) + (row / 2) * (col / 2) << endl;
            else cout << (row / 2) * (col / 2) + (row / 2) * (col / 2 + 1) << endl;
        }

        return;
    }

    if (c == 'K') {
        int a = row / 2;
        int b = col / 2;
        if (row % 2 == 1) a ++;
        if (col % 2 == 1) b ++;
        cout << a*b << endl;
        return;
    }

   //Queen case
   cout << min(row, col) << endl;
   return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}