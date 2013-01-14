#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    long long rj = 0;
    
    cin >> n;
    
    int x;
    vector<int> S;
    map<long long, long long> intovi;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        S.push_back(x);
    }
    
    // sort(S.begin(), S.end());
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            long long iPutaJ = S[i] * S[j];
            for (int k = 0; k < n; ++k)
            {
                long long zbroj = iPutaJ + S[k];
                map<long long, long long>::iterator it = intovi.find(zbroj);
                if (it == intovi.end())
                {
                    if (S[i] != S[j])
                        intovi[zbroj] = 2;
                    else
                        intovi[zbroj] = 1;
                }
                else
                {
                    if (S[i] != S[j])
                        it->second += 2;
                    else
                        it->second++;
                }
            }
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            long long iPlusJ = S[i] + S[j];
            for (int k = 0; k < n; ++k)
            {
                if (S[k] == 0)
                    continue;
                long long umnozak = iPlusJ * S[k];
                map<long long, long long>::iterator it = intovi.find(umnozak);
                if (it != intovi.end())
                {
                    if (S[i] != S[j])
                        rj += it->second * 2;
                    else
                        rj += it->second;
                }
            }
        }
    }
    cout << rj << endl;
    return 0;
}
