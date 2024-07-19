/*
#include <bits/stdc++.h>
using namespace std;

int getSize(string n) {
	return (int)n.size();
}

int getNum(char c) {
	return (int)(c - 'A');
}

string solve(vector<string>& names, int n) {
	string result = "";

	int min_name_size = 1001;
	for (int i = 0 ; i < n; i++) {
		if (getSize(names[i]) < min_name_size) min_name_size = getSize(names[i]);
	}
	//THIS IS WHERE I'M WRONG !!!

	for (int i = 0; i < min_name_size; i++) {
		vector<int> chars;
		for (auto j : names) {
			chars.push_back(getNum(j[i]));
		}
		sort(chars.begin(), chars.end());
		for (int j = 0; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				if (chars[j] != chars[k]) {
					int id = n / 2 - 1;
					char charNum = (char) (chars[id]+1+'A');
					result = result + charNum;
					return result;
				}
			}
		}
		char toInsert = (char) (chars[0] + 'A');
		result = result + toInsert;
	}
	return result;
}

int main()
{
	int n;

	vector<string> ans;
	
	while(true) {
		//cout << "Enter the number of guests: ";
		cin >> n;

		if (n == 0) break;

		if (n % 2 == 1) {
			cout << "Cant form 2 teams!" << endl;
			break;
		}

		vector<string> names;
		//cout << "Enter the names of the guests: ";
		for (int i = 0; i < n; i++) {
			string name;
			cin >> name;
			names.push_back(name);
		}
		int n = names.size();
		ans.push_back(solve(names, n));
	}

	for (auto i : ans) {
		cout << i << endl;
	}
	return 0;
}
*/

//---------------------------REDO------------------------------

/*
#include <bits/stdc++.h>
using namespace std;

int getSize(string n) {
	return (int)n.size();
}

string solve(vector<string> names, int n) {
	string result = "";

	sort(names.begin(), names.end());
	//cout << "Names of guests after reordering: ";
	//for (int i = 0; i < n; i++) {
	//	cout << names[i] << " ";
	//}

	string left_name = names[(n-1) / 2];
	string right_name = names[n / 2];

	int min_size = min(getSize(left_name), getSize(right_name));
	for (int i = 0; i < min_size; i++) {
		if (left_name[i] == right_name[i]) result = result + left_name[i];
		else {
			int charNum = (int) (min(left_name[i], right_name[i]) - 'A') + 1;
			char toInsert = (char) (charNum + 'A');
			result = result + toInsert;
			return result;
		}
	}

	return result;
}

int main()
{
	int n;

	vector<string> ans;
	
	while(true) {
		//cout << "Enter the number of guests: ";
		cin >> n;

		if (n == 0) break;

		//if (n % 2 == 1) {
			//cout << "Cant form 2 teams!" << endl;
			//break;
		//}

		vector<string> names;
		//cout << "Enter the names of the guests: ";
		for (int i = 0; i < n; i++) {
			string name;
			cin >> name;
			names.push_back(name);
		}
		int n = names.size();
		ans.push_back(solve(names, n));
	}

	for (auto i : ans) {
		cout << i << endl;
	}
	return 0;
}
*/

//-------------------------ANSWER------------------------------

// UVa 01610 Party Games
// Damn tilting, like legit, the number of edge cases are super annoying
// String and array concepts are simple to understand but hard to implement to deal with all the cases effectively
// Time: O(n log n) for sort per test case, Mem: O(n) for vector

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    
    while (true){
        cin >> n;
        //cout << "----" << endl;
        if (n == 0){
            break;
        }

        vector<string> names;
        for (int i=0;i<n;i++){
            string name;
            cin >> name; 
            names.push_back(name);
        }
        
        sort(names.begin(), names.end());

        /*
        for (auto i:names)cout << i << " ";
        cout << endl;*/

        

        string left_name = names[n/2 -1];
        string right_name = names[n/2];

        string ans = "";

        for (int i=0; i< min(left_name.length(), right_name.length()); i++){
            if (left_name[i] == right_name[i]){
                ans += left_name[i];
            }
            else break;
        }

        if (ans == left_name){
            cout << ans << endl;
            continue; 
        }
        string left_name_full = left_name;
        string right_name_full = right_name;
        left_name.erase(0, ans.length());
        right_name.erase(0, ans.length());

        //left_name[0] + 1 != right_name[0]
        //Ex: C + 1 == D

        if (left_name[0] + 1 != right_name[0]){
            if (left_name.length() != 1){
                ans += (left_name[0] + 1);
                cout << ans << endl;
            }
            else
                cout << ans + left_name << endl;
                
            continue;
        }
        
        // left_name[0] == right_name[0];

        if (right_name.length() == 1) {
            ans += left_name[0];
            for (int i=1; left_name_full > ans; i++){
                if (left_name[i] == 'Z')ans += left_name[i];
                else {
                    if (i != left_name.length()-1)
                    ans += left_name[i] + 1;
                    else
                    ans += left_name[i];
                }
            }
            cout << ans << endl;
            continue;
        }
        
        if (left_name.length() == 1){
            ans += (left_name[0]);
        }
        else
            ans += (left_name[0] + 1);
        cout << ans << endl;
 
    }

    return 0;
}