#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
int n,e,start;
vector<int> graph[N];
bool visited[N];
int distances[N];
queue<int> q;

void bfs() {
    for (size_t i = 1; i <= n; i++)
    {
        visited[i] = false;
        distances[i] = -1;
    }
    q.push(start);
    visited[start] = true;

    int level = 0;
    int first = -1;
    bool checkpoint = false;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        if(current == first) checkpoint = false;
        for ( int next : graph[current] ) {
            if(!visited[next]) {
                if (!checkpoint) {
                    checkpoint = true;
                    first = next;
                    level++;
                }
                q.push(next);
                visited[next] = true;
                distances[next] = level*6;
            }
        }
    }

    for (size_t i = 1; i <= n; i++)
    {
        graph[i].clear();
        if(i != start) {
            cout << distances[i] << " ";
        }
    }
    cout << endl;
    
}

int main() {
    int test;

    cin>> test;
    
    while(test--) {
        cin>> n >> e;
        int u,v;
        for(int i = 0; i < e; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cin>>start;
        bfs();
    }

}