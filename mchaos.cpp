#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

#define MAX 100002

using namespace std;

string a[MAX], b[MAX];
int fenwick[MAX];
int n;

void ubaci(int index, int value)
{
    for (int i = index + 1; i < MAX; i += i&-i)
    {
        fenwick[i] += value;
    }
}

long long sum(int index)
{
    long long retVal = 0;
    for (int i = index; i > 0; i -= i&-i)
    {
        retVal += fenwick[i];
    }
    return retVal;
}

bool cmp1 (int x, int y)
{
    // vrati true ako je prvi manji
    return a[x] < a[y];
}

bool cmp2 (int x, int y)
{
    return b[x] < b[y];
}

void ispisi(string *a)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "" << endl;
}

int main(int argc, char *argv[])
{
    cin.sync_with_stdio(false);
    
    cin >> n;
    
    int prvi[n], drugi[n], pos[MAX];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = string(a[i].rbegin(), a[i].rend());
        prvi[i] = drugi[i] = i;
    }
    
    sort(prvi, prvi + n, cmp1);
    sort(drugi, drugi + n, cmp2);
    
    for (int i = 0; i < n; ++i)
    {
        pos[drugi[i]] = i;
    }
    
    for (int i = 0; i < n; ++i)
    {
        ubaci(i, 1);
    }
    
    long long sol = 0;
    for (int i = 0; i < n; ++i)
    {
        // a[prvi[i]] je string na kojem smo trenutno
        // pos[prvi[i]] je pozicija gdje se taj string nalazi u drugome
        sol += sum(pos[prvi[i]]);
        ubaci(pos[prvi[i]], -1);
    }
    
    //ispisi(a);
    //ispisi(b);
    
    cout << sol << endl;
    
    return 0;
}
