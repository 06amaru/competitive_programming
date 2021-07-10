#include <bits/stdc++.h>
using namespace std;

#define N (int) 2e5+4

typedef unsigned long long ll;

ll tree[4*N], lazy[4*N];
ll arr[N] = {0};

ll build(int start, int end, int i)
{
    lazy[i] = 0;
    if(start == end)
        return tree[i] = arr[start];
    
    ll mid = (start+end)/2;
    return tree[i] = build(start, mid, 2*i+1) + build(mid+1, end, 2*i+2);
}

void showSegTree(ll n)
{
  ll i, j, h = ceil(log2(n));
  cout<<"Segment Tree:"<<endl;
  for(i=0 ; i<=h ; ++i)
  {
    for(j=0 ; j<pow(2, i) ; ++j)
      cout<<tree[ll(pow(2, i)-1 + j)]<<' ';
    cout<<endl;
  }
  cout<<"Lazy Tree:"<<endl;
  for(i=0 ; i<=h ; ++i)
  {
    for(j=0 ; j<pow(2, i) ; ++j)
      cout<<lazy[ll(pow(2, i)-1 + j)]<<' ';
    cout<<endl;
  }
}

/*
* start, end :  fixed position of query
* l, r: recursive position of query (begins with 0 and n-1)
*/
ll query(int start, int end, int l, int r, int i)
{
    //cout << start << " " << end << "  " << l << " " << r << " " << i << '\n';
    if(lazy[i] != 0)
    {
        tree[i] += (r-l+1)*lazy[i];
        if(l!=r)
        {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(end < l || start > r || l > r)
    {
        //cout  << "end\n";
        return 0;
    }
        
    if(start <= l && r <= end )
        return tree[i];
    ll mid = (l+r) / 2;
    //cout << "mid " << mid  << '\n'; 
    return query(start, end, l, mid, 2*i+1)+query(start,end, mid+1, r, 2*i+2);
}

void update(int start, int end, ll val, int l, int r, int i)
{
    if(lazy[i] != 0) 
    { 
        tree[i] += (r-l+1)*lazy[i];
        if(l!=r)
        {
            lazy[2*i+1] += lazy[i];
            lazy[2*2+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(end < l || start > r || l > r)
        return;
    if(start <= l && r <= end )
    {
        tree[i] += (r-l+1)*val;
        if(l != r)
        {
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
    } else 
    {
        ll mid = (l+r)/2;
        update(start, end, val, l, mid, 2*i+1);
        update(start, end, val, mid+1, r, 2*i+2);
        tree[i] = tree[2*i+1]+tree[2*i+2];
    }
}

int main() 
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(0, n-1, 0);
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1) 
        {
            int start,end;
            ll u;
            cin >> start >> end >> u;
            update(start-1, end-1, u, 0, n-1, 0);
            //showSegTree(n);
        } else {
            int k;
            cin >> k;
            cout << query(k-1, k-1, 0, n-1, 0) << endl;
        }
    }
}