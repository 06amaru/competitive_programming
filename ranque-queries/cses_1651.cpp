#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5+4;

ll st[4*N];

ll arr[N];

int n, q, a, b, k;
ll u;

ll query(int start, int end, int l, int r, int pos = 1) {
    if(l > end || r < start || start > end) return 0;
    else if(start <= l && r <= end) return st[pos];

    int mid = (l+r)/2;
    return query(start, end, l, mid, 2*pos) + query(start, end, mid+1, r, 2*pos+1);
}

void update(int i, ll val, int l, int r, int pos = 1) {
    if (l == r) {
        st[pos] += val;
    } else {
        int mid = (l+r)/2;
        if(mid >= i)
            update(i, val, l, mid, 2*pos);
        else
            update(i, val, mid+1, r, 2*pos +  1);
        st[pos] = st[2*pos]+st[2*pos+1];
    }
}

int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    while(q--) {
        int t;
        cin  >> t;
        if(t == 1) {
            cin >> a >> b >> u;
            update(a, u, 1, n);
            if(b != n) {
                update(b+1, -u, 1, n);
            }
        } else {
            cin >> k;
            cout << arr[k]+ query(1, k, 1, n) << '\n';
        }
    }
}
