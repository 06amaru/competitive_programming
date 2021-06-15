#include <bits/stdc++.h>
using namespace std;


#define ll long long

const int N = 2e5;
ll segment_tree[4*N];

ll a[N];

void build(int vertex, int left, int right) {
    if(left == right) {
        segment_tree[vertex] = a[left];
    } else {
   	int mid = (left+right)/2;
	build(vertex*2, left, mid);
	build(vertex*2+1, mid+1, right);
	segment_tree[vertex] = segment_tree[vertex*2] + segment_tree[vertex*2+1];
    }
}

ll sum(int vertex, int left, int right, int beg, int end) {
    if (beg > end) return 0;
    if(left == beg && right == end) {
        return segment_tree[vertex];
    } else {
        int mid = (left+right)/2;
        return sum(vertex*2, left, mid, beg, min(end, mid)) + 
                sum(vertex*2+1, mid+1, right, max(beg, mid+1), end);
    }
}

void update(int vertex, int left, int right, int pos, ll val) {
    if(left == right) {
        segment_tree[vertex] = val;
    } else {
        int mid = (left+right)/2;
        if(pos <= mid) {
            update(vertex*2, left, mid, pos, val);
        } else {
            update(vertex*2+1, mid+1, right, pos, val); 
        }
        segment_tree[vertex] = segment_tree[2*vertex]+segment_tree[2*vertex+1];
    }
}

int main() {
    int n , q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0 , n-1);
    int x, y;
    ll z;
    while(q--) {
        cin >> x >> y >> z;
        if( x == 2) {
            cout << sum(1, 0, n-1, y-1, z-1) << endl;
        } else {
            update(1, 0, n-1, y-1, z);
        }
    }

}














