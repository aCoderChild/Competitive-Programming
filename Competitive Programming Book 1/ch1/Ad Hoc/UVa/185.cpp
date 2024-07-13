/* Rules:
1. A letter from the left column can never appear more than three times in a row, and there can
never be more than one other occurrence of that letter.

2. A letter from the right column can never appear more than once.

3. Once a letter has been used in a ‘negative’ position, all subsequent characters (apart from the one
immediately following) may not be greater than that character.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> romanToArabic = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int toArabic(string romanNum) {
    int arabicNum = 0;
    for (int i = 0; i < romanNum.length() - 1; i++) {
        if (romanToArabic[romanNum[i]] < romanToArabic[romanNum[i + 1]]) {
            arabicNum -= romanToArabic[romanNum[i]];
        } else {
            arabicNum += romanToArabic[romanNum[i]];
        }
    }
    arabicNum += romanToArabic[romanNum.back()];
    return arabicNum;
}

bool isCorrect(string romanNum1, string romanNum2, string romanSum) {
    int arabicNum1 = toArabic(romanNum1);
    int arabicNum2 = toArabic(romanNum2);
    int arabicSum = toArabic(romanSum);
    if (arabicNum1 + arabicNum2 == arabicSum) {
        return true;
    }
    return false;
}

//Achtung
bool isAmbiguous(int arabicNum) {
    for (int i = 1; i < 5; i++) {
        if (arabicNum % i == 0) {
            return true;
        }
    }
    return false;
}

void solve(string input) {
    string romanNum1, romanNum2, romanSum;
    size_t pos = input.find("+");
    romanNum1 = input.substr(0, pos);
    romanNum2 = input.substr(pos + 1, input.find("=") - pos - 1);
    romanSum = input.substr(input.find("=") + 1);
    int arabicSum = toArabic(romanSum);
    if (isCorrect(romanNum1, romanNum2, romanSum)) {
        if (isAmbiguous(arabicSum)) {
            cout << "Correct ambiguous" << std::endl;
        } else {
            cout << "Correct valid" << std::endl;
        }
    } 

    else {
        if (isAmbiguous(arabicSum)) {
            cout << "Incorrect ambiguous" << std::endl;
        } 

        else {
            cout << "Incorrect valid" << std::endl;
        }
    }
}

int main() {
    string input;
    while (getline(cin, input)) {
        if (input == "#") {
            break;
        }
        solve(input);
    }
}