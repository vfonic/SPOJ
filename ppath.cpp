#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

vector<int> allPrimeNumbers;
int bio[10000] = {0};

bool isPrime(int x)
{
    int limit = sqrt(x);
    for (int i = 2; i <= limit; ++i)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void findAllPrimeNumbers()
{
    for (int i = 1001; i < 10000; i += 2)
    {
        if (isPrime(i))
            allPrimeNumbers.push_back(i);
    }
}

void printArray(vector<int> &vect)
{
    for (int i = 0; i < vect.size(); ++i)
    {
        cout << vect[i] << " ";
    }
    cout << endl;
}

bool slicni(int x, int y)
{
    int slic = 0;
    if (x % 10 == y % 10)
        slic++;
    if (x / 10 % 10 == y / 10 % 10)
        slic++;
    if (x / 100 % 10 == y / 100 % 10)
        slic++;
    if (x / 1000 == y / 1000)
        slic++;
    return slic == 3;
}

int process(int first, int second)
{
    if (first == second)
        return 0;
    queue< pair<int, int> > red;
    red.push(make_pair(first, 0));
    
    while (!red.empty())
    {
        pair<int, int> prajm_and_cost = red.front();
        red.pop();
        
        if (bio[prajm_and_cost.first])
            continue;
        
        bio[prajm_and_cost.first] = 1;

        int prajm = prajm_and_cost.first;
        int cost = prajm_and_cost.second;
        
        // nadji gdje sve mogu ici i dodaj u queue
        for (int i = 0; i < allPrimeNumbers.size(); ++i)
        {
            if (allPrimeNumbers[i] != prajm && !bio[allPrimeNumbers[i]] && slicni(allPrimeNumbers[i], prajm))
            {
                if (allPrimeNumbers[i] == second)
                    return cost + 1;
                red.push(make_pair(allPrimeNumbers[i], cost + 1));
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n;
    
    cin >> n;
    
    queue< pair<int, int> > parovi;
    
    int x, y;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        parovi.push(make_pair(x, y));
    }
    
    findAllPrimeNumbers();

    while(!parovi.empty())
    {
        pair<int, int> par = parovi.front();
        parovi.pop();
        
        int result = process(par.first, par.second);
        memset(bio, 0, sizeof(bio));
        
        if (result == -1)
            cout << "Impossible" << endl;
        else
            cout << result << endl;
    }
    
    return 0;
}
