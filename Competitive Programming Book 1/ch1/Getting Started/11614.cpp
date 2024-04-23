#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--) {
        int n;
        cin >> n;
        int row = 0;
        int i = 1;
        int num = 0;
        while (i) {
            num += i;
            if (num > n) break;
            row ++;
            i++;
        }

        cout << row << endl;
    }

    return 0;
}
