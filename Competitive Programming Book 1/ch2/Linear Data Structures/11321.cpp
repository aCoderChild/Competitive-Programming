#include<bits/stdc++.h>
using namespace std;

int getMod(int x, int k) {
	return x % k;
}

void sort(vector<int>& a) {
	int n = (int)a.size();

	int left = 0;
	int right = n - 1;

	while (left < right) {
		if (a[left] % 2 == 1) left++;
		if (a[right] % 2 == 0) right--;

		swap(a[left], a[right]);
		left++;
		right--;
	}
}

void solve(int a[], int n, int k) {
	map<int, vector<int>> mp;
	for (auto i : a) {
		int mod = i % k;
		mp[mod].push_back(i);
	}

	for (auto i : mp) {
		vector<int> toSort = i.second();

	}
}

int main()
{

}