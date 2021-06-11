#include <bits/stdc++.h>

/* the longest path is the path has the
*  maximum number of edges
*/

using namespace std;

const int N = 1e6+3;
const int M = 1e6+3;

vector<int> graph [N];

int dp[N] = {-1};

int dfs(int v)
{
	if(dp[v] != -1) return dp[v];
	int longest = 0;
	for(auto &u: graph[v])
	{
		longest = max(longest, dfs(u) + 1);
	}
	return dp[v] = longest;
}

int main () 
{
	int x, y;
	scanf("%d%d",&x,&y);
	
	for(int i=0; i<y; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		graph[u].push_back(v);
	}
	for(int i=1; i <= x; i++) dp[i] = -1;
	int longest = -1;
	for(int i = 1; i<=x; i++)
	{
		longest = max(longest, dfs(i));
	}
	printf("%d\n", longest);
}
