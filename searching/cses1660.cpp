#include <bits/stdc++.h>

using namespace std;

const int N = 2*1e5+2;
int arr[N] = {0};

int main() {
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int i = 0;
    int j = 0;
    int s = 0;
    int count = 0;
    while(i < n) {
        
        while(s < x && j < n) {
            s+= arr[j];
            j++;
        }
        
        if(s == x) {
            count++;
        }

        s-= arr[i];
        i++;
    }
    cout << count << endl;
}