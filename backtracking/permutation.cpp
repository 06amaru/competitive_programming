#include <bits/stdc++.h>

using namespace std;

void swap(string &word, int i, int j) {
    const char temp = word[i];
    word[i] = word[j];
    word[j] = temp;
}

void permutation(string word, int start, int end) {
    if(start == end) {
        cout << word << endl;
    } else {
        for(int i = start; i < end; i++) {
            swap(word, start, i);
            permutation(word, start+1, end);
            swap(word, i, start);
        }
    }

}

int main() {
    string input;
    cin >> input;
    permutation(input, 0, input.size());
}
