#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int N = 1e6+3;

ll dp[N] = {0};

int main()
{
	
	int n;
	cin >> n;
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 6; j++)
		{
			if(i-j >= 0) dp[i] = (dp[i] + dp[i-j])%mod;
		}

	cout << dp[n];
}
