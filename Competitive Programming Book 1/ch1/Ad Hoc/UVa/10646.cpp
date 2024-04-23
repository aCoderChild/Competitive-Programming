#include<bits/stdc++.h>
using namespace std;

int getVal(char c) {
    switch(c) {
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 10;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int casenum = 1;
    int t;
    cin >> t;
    while (t--) {

        char deck[52][3];
        for (int i = 51; i >= 0; i--) {
            cin >> deck[i][0] >> deck[i][1];
            deck[i][2] = 'u';
        }

        int Y = 0;

        int dump = 0;
        int pos = 25;
        int remain = 52;

        for (int i = 1; i <= 3; i++) {
            pos += dump;

            int X = getVal(deck[pos][0]);
            //cout << "X: " << X << endl;
            
            Y += X;
            dump = 10 - X + 1;
            //cout << "dump: " << dump << endl;
        
            for (int j = pos; j < pos + dump; j++) {
                deck[i][3] = 'd';
            }

            remain -= dump;
            //cout << "remain: " << remain << endl;
        }
        //cout << Y << endl;
 
        char newDeck[remain][2];
        int idx = 0;
        for (int i = 0; i < 52; i++) {
            if (deck[i][2] == 'u') {
                newDeck[idx][0] = deck[i][0];
                newDeck[idx][1] = deck[i][1];
                idx++;
            }
        }

        cout << "Case " << casenum << ": " << newDeck[remain - Y][0] << newDeck[remain - Y][1] << endl;
        casenum++;
    }

    return 0;
}
