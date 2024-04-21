#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    char dominant;
    cin >> n >> dominant;

    int total;
    for (int i = 0; i < 4*n; i++) {
        string s;
        cin >> s;
        if (s[1] != dominant) {
            switch (s[0]) {
                case '7':
                    total += 0;
                    break;
                case '8':
                    total += 0;
                    break;
                case '9':
                    total += 0;
                    break;
                case 'T':
                    total += 10;
                    break;
                case 'J':
                    total += 2;
                    break;
                case 'Q':
                    total += 3;
                    break;
                case 'K':
                    total += 4;
                    break;
                case 'A':
                     total += 11;
                     break;

            }
        }

        else {
            switch (s[0]) {
                case '7':
                    total += 0;
                    break;
                case '8':
                    total += 0;
                    break;
                case '9':
                    total += 14;
                    break;
                case 'T':
                    total += 10;
                    break;
                case 'J':
                    total += 20;
                    break;
                case 'Q':
                    total += 3;
                    break;
                case 'K':
                    total += 4;
                    break;
                case 'A':
                     total += 11;
                     break;

            }
        }
    }
    cout << total << endl;
    return 0;
}
