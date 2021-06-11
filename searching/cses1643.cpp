#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a[1000000];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	ll maxsum = INT32_MIN;
	ll sum = INT32_MIN;
	for(int i = 0; i < n; i++) {
		sum = max(a[i], sum+a[i]);
		maxsum = max(maxsum, sum);
	}

	cout << maxsum;
}
