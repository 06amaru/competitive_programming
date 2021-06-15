
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5+1;
int n, q, a, b;
int x[N];
int M[32][N];
 
void preproc() {
    for (int i = 1; i <= n; i++)
    {
        cin>>x[i];
        M[0][i] = x[i];
    }
    int level = floor(log2(n));
    for (int i = 1; i <= level; i++)
    {
        for (int j = 1; j <= n-pow(2,i)+1 ; j++)
        {
            int range = pow(2,i-1);
            M[i][j] = min(M[i-1][j], M[i-1][j+range]);
        }
 
    }
}
 
int main() {
    cin >> n >> q;
    preproc();
    while(q--) {
        cin >> a >> b;
        int size_query = (b-a)+1;
        int row = floor(log2(size_query));
        int l = b - pow(2,row) + 1;
 
        cout << min(M[row][a], M[row][l]) << endl;
    }
}