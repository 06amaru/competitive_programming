// https://codeforces.com/contest/734/problem/E

#include <bits/stdc++.h>
using namespace std;

#define N 200000

vector<int> graph [N];

int color [N];
int n; //number of vertices of tree
//1 is white
//0 is black

set<int> set_black;
set<int> set_white;

void paint(int v, int x) 
{
    for (auto &u : graph[v])
    {
        if(color[u] == color[v] && u != x)
        {
            paint(u, v);
        }
    }
    if(color[v] % 2 == 0) set_black.erase(v);
    else set_white.erase(v);
}

int main() 
{
    cin >> n;
    int color_input;
    for (size_t i = 1; i <= n; i++)
    {
        cin >> color_input;
        color[i]  = color_input;
        if(color_input%2 == 0) 
        {
            set_black.insert(i);
        } else {
            set_white.insert(i);
        }
    }
    int u,v;
    for (size_t i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int white_operation = 0;
    while(!set_black.empty()) 
    {
        int black = *set_black.begin();
        paint(black, black);
        white_operation++;
    }
    
    
    int black_operation = 0;
    while(!set_white.empty()) 
    {
        int white = *set_white.begin();
        paint(white, white);
        black_operation++;
    }
    cout << min(black_operation, white_operation);
};