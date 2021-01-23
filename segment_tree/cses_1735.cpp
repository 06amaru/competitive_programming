#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int N = 2e5;

int segment_tree[4*N];
int rooms[N], n, m;
bool found;

void build(int a[], int vertex, int left, int right) {
    if (left == right) {
        segment_tree[vertex] = a[left];
    } else {
        int mid = (left + right)/2;
        build(a, vertex*2, left, mid);
        build(a, vertex*2+1, mid+1, right);
        segment_tree[vertex] = segment_tree[vertex*2] + segment_tree[vertex*2+1];
    }
}

int sum(int vertex, int left, int right, int beginq, int endq) {
    if (beginq > endq) return 0;

    if (left == beginq && right == endq) {
        return segment_tree[vertex];
    } else {
        int mid = (left+right)/2;
        return sum(vertex*2, left, mid, beginq, min(endq, mid))
            + sum(vertex*2+1, mid+1, right, max(beginq, mid+1), endq);
    }
}

void update(int vertex, int left, int right, int position, int new_val) {
    if(left == right) {
        segment_tree[vertex] = new_val;
    } else {
        int mid = (left+right)/2;
        if(position <= mid) {
            update(vertex*2, left, mid, position, new_val);
        } else {
            update(vertex*2+1, mid+1, right, position, new_val);
        }
        segment_tree[vertex] = segment_tree[2*vertex]+segment_tree[2*vertex+1];
    }
}

void dfs(int vertex, int q) {
    if( segment_tree[vertex] >= q ) {
        if (segment_tree[vertex*2] == -1) {
            segment_tree[vertex] -= q;
	    cout << vertex - n + 1<< " " ;
            found = true;
        } else {
            dfs(vertex*2, q);
            if(!found) dfs(vertex*2+1, q);
            segment_tree[vertex] = segment_tree[2*vertex]+segment_tree[2*vertex+1];
        }
    }
}


int main() {
    fill(segment_tree, segment_tree+4*N, -1);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin>>rooms[i];
    }
    build(rooms, 1, 0, n-1);
    int q;
	
    while(m--) {
        found = false;
        cin >> q;
        dfs(1, q);

	if(!found) cout << 0 << " ";
    }
}
