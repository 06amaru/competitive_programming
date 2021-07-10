#include <bits/stdc++.h>

//https://www.spoj.com/problems/STRMATCH/

using namespace std;

#define MAXN 65536
#define MAXLG 17


#define N 1000010

typedef pair<int,int> pii;
typedef pair<pii,int> piii;

int suffix[N], labels[2*N], n, up, low, q;
int C[N];

string s, patron;

void build() {
    n = s.size();
    for(int i = 0; i < n; i++)
        labels[i] = s[i] - 'A';

    for(int k=0; k <n; (k==0)? k = 1 : k *= 2) {
        vector<piii> aux;
        for(int i = 0; i < n; i++) {
            aux.push_back({ {labels[i], labels[i+k]} , i});
        }
        sort(aux.begin(), aux.end());
        int cont = 0;
        for(int i = 0; i < n; i++) {
            int pos = aux[i].second;
            if(i > 0 && aux[i].first != aux[i-1].first) cont++;
            labels[pos] = cont + 1;
        }
        if(cont == n-1) break;
    }
    for(int i = 0; i < n; i++) {
        suffix[labels[i] - 1] = i;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, queries;
    cin >> n >> queries;
    cin >> s;
    build();
    while(queries--) {
        cin >> patron;
        /*for(int i = 0; i < n; i++) {
            cout << suffix[i] << ' ';
            for(int j = suffix[i]; j < n; j++) {
                cout << s[j];
            }
            cout << '\n';
        }*/
        int l = 0, r = s.size() - 1;
        bool found = false;
        for (int i = 0; i < patron.size(); ++i) {
            q = patron[i];
            int start = l, end = r;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (s[suffix[mid] + i] < q) start = mid + 1;
                if (s[suffix[mid] + i] > q) end = mid - 1;
                if (s[suffix[mid] + i] == q) {
                    found = true;
                    end = mid - 1;
                }
            }
            if (!found) break;
            int start2 = l, end2 = r;
            while (start2 <= end2) {
                int mid = (start2 + end2) / 2;
                if (s[suffix[mid] + i] < q) start2 = mid + 1;
                if (s[suffix[mid] + i] > q) end2 = mid - 1;
                if (s[suffix[mid] + i] == q) {
                    found = true;
                    start2 = mid + 1;
                }
            }
            l = start;
            r = end2;
        }
        if (found) cout << r - l + 1 << '\n';
        else cout << 0 << '\n';
    }
}