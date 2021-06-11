#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

const int N = 100;
const int X = 1e6 +1;

ll coin[N] = {0};
ll dp[X] = {0};

int main() 
{
	int n, x;
	cin >> n >> x;
	for(int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	for(int value= 1; value <= x; value++)
	{
		for(int j = 0; j < n; j++)
			if(value - coin[j] >= 0)
				dp[value] = (dp[value] + dp[value-coin[j]])% mod;
	}
	cout << dp[x];
}
