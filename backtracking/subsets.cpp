#include <bits/stdc++.h>

using namespace std;

vector<char> subset;
void subsets(int k, string word) {
    if(k == word.size()) {
        cout<<"[";
        for (auto i: subset) {
            cout << i;
        }
        cout <<"]"<< endl;
    } else {
        subset.push_back(word[k]);
        subsets(k+1, word);
        subset.pop_back();
        subsets(k+1, word);
    }
}

void subsets(string &word) {
    subsets(0, word);
}

int main() {
    string input;
    cin >> input;
    subsets(input);
}

