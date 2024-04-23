#include <bits/stdc++.h>
using namespace std;
#define ull long unsigned int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--) {
        ull n;
        cin >> n;
        cout <<  (ull) floor((sqrt(1+8*n) - 1) / 2) << endl;
    }

    return 0;
}
