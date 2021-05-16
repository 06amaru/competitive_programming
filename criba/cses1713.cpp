#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const ull m = 1e7+1;

ull sieve[m];

void init_sieve() 
{
    for (int i = 2; i < m; i++)
    {
        sieve[i] = i;
    }

    for (int i = 2; i < m; i++)
    {
        if (sieve[i] == i)
        {
            for (int j = 2; j < m/i; j++)
            {
                if (sieve[i*j] == i*j) sieve[i*j] = i;
            }
            
        }
        
    }
    
}

ull factors(int x)
{
    ull exp = 0;
    ull total = 1;
    ull n=x;
    while (x > 1)
    {
        if (x%sieve[n] == 0)
        {
            x/=sieve[n];
            exp++;
        } 
        else
        {
            total*=(exp+1);
            exp = 0;
            n=x;
        }
        
    }
    return total*(exp+1);
}

int main() 
{
    int n;
    cin >> n;

    init_sieve();

    while (n--) 
    {
        ull x;
        cin >> x;
        cout << factors(x)<< endl;

    }
}