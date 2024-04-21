#include <bits/stdc++.h>
using namespace std;

int getVal (char c) {
    switch (c) {
        case 'T':
            return 10;
        case 'J':
            return 2;
        case 'Q':
            return 3;
        case 'K':
            return 4;
        case 'A':
            return 11;
    }
    return 0;
}

int getTrumpVal (char c) {
    switch (c) {
        case '9':
            return 14;
        case 'T':
            return 10;
        case 'J':
            return 20;
        case 'Q':
            return 3;
        case 'K':
            return 4;
        case 'A':
            return 11;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int hands;
    char trump;

    cin  >> hands >> trump;

    char num, suit;
    int sum = 0;

    while (cin >> num && cin >> suit) {
        if (suit == trump) {
            sum += getTrumpVal (num);
        }
        else sum += getVal (num);
    }
    cout << sum << endl;
    return 0;
}

// while (cin >> variable): input validation, as long as the input of num is a char and suit is a char
