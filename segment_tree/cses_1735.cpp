#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;

int segment_tree[4*N];

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

int main() {

}
