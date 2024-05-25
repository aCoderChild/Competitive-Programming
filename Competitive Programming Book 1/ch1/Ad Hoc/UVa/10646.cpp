/*
#include <bits/stdc++.h>
using namespace std;

int calculate_value(const string& card) {
    int value = card[0] - '0';
    return (value >= 2 && value <= 9) ? value : 10;
}

string solve(vector<string> deck) {
    vector<string> hand(deck.begin() + 27, deck.end());
    vector<string> remainingCards(deck.begin(), deck.begin() + 27);

    int Y = 0;
    int remainingSize = remainingCards.size();
    for (int i = 0; i < 3; i++) {
        int cardValue = calculate_value(remainingCards[remainingSize - 1]);
        Y += cardValue;
        
        //TODO: debug
        //cout << cardValue << endl;

        remainingCards.pop_back();
        int t = 10 - cardValue;
        while (t--) {
            remainingCards.pop_back();
        }

        remainingSize = remainingCards.size();
    }

    for (int i = 0; i < 25; i++) {
        remainingCards.push_back(hand[i]);
    }

    string res;
    int resIndex = remainingCards.size() - 1;
    while(Y--) {
        res = remainingCards[resIndex];
        resIndex--;
    }

    return res;
}
*/

//Steven Kester Yuwono - UVa 10646 - What is the Card?
#include <iostream>
#include <string>
using namespace std;


int main(){
	string temp;
	string ans;
	int n=0;
	cin >> n;
	for(int j=1;j<=n;j++){
		for(int i=0;i<52;i++){
			cin >> temp;
			if(i==32){
				ans=temp;
			}
		}
		
		cout << "Case " << j << ": ";
		cout << ans << endl;
	}
	return 0;
}

//if you cant do it properly, do it dirty :)