#include <bits/stdc++.h>
using namespace std;

int main() {
    int test = 512*8 + 24131;
    for (size_t i = 0; i < 32; i++)
    {
        if(test & (1 << i)) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    cout << endl;
}