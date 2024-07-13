#include<bits/stdc++.h>
using namespace std;

int solve(vector<long long> a, int n) {
	if (n % 2 == 1) {
		return a[n/2];
	}

	return (a[n/2] + a[(n-1)/2]) / 2;
}

int main()
{
	vector<long long> a;
	int n = 0;
	long long x;
	while(cin >> x) {
		a.push_back(x);
		n++;
		sort(a.begin(), a.end());
		cout << solve(a, n) << endl;
	}
}