#include <bits/stdc++.h>
 
 
 
using namespace std;
 
typedef long long ll;
const int N = 2e5+7;
 
 
int q,n,k,x,u,a,b;
 
int arr[N];
 
int st[2*N]; //root is index one not zero
 
void build()
{
    for (int i = 0; i < n; i++)
    {
        st[i+n] = arr[i];
    }
    for (int i = n-1; i > 0; i--)
    {
        st[i] = min(st[2*i], st[2*i + 1]);
    }
 
}
 
int minimum(int a, int b)
{
    a+= n;
    b+= n;
    int ans = INT32_MAX;
    while(a <= b)
    {
        if(a % 2)
        {
            ans = min(ans, st[a++]);
        }
        if(b % 2 == 0)
        {
            ans = min(ans, st[b--]);
        }
        a/=2;
        b/=2;
    }
    return ans;
}
 
void update(int k, int x)
{
    k+=n;
    st[k] = x;
    for (k/=2; k >= 1; k/=2)
    {
        st[k] = min(st[2*k], st[2*k+1]);
    }
}
 
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build();
    while(q--)
    {
        cin >> u;
        if(u == 2)
        {
            cin >> a >> b;
            cout << minimum(a-1, b-1) << '\n';
        } else {
            cin >> k >> x;
            update(k-1, x);
        }
    }
}