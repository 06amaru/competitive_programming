#include <bits/stdc++.h>
 //BINARY INDEX TREE
using namespace std;
const int N = 2e5+1;
 
unsigned long long BIT[N], x[N], n, q, type, k, u, a ,b;
 
void update(int i, unsigned long long val)
{
      for(; i <= n; i += i&-i)
      {
          BIT[i] += val;
      }  
    
}
unsigned long long query(int x)
{
     unsigned long long sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}
 
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        update(i, x[i]);
    }
 
    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> k >> u;
            //u =  u - x[k];
            update(k, u - x[k]);
            x[k] = u;
        } else {
            cin >> a >> b;
            cout << query(b) - query(a-1) << endl;
        }
    }
}