#include <iostream>

using namespace std;

int shiftaj(long long x)
{
    x--;
    int br = 0;
    while (x > 0)
    {
        x >>= 1;
        br++;
    }
    return br;
}

int main(int argc, char const *argv[])
{
    cin.sync_with_stdio(false);
    int t;
    
    cin >> t;
    
    long long rj_ruke, rj_noz;
    for (int i = 0; i < t; ++i)
    {
        int n, m, k;
        cin >> n >> m >> k;
        
        long long prvi, drugi, treci;
        if (n > m)
        {
            if (n > k)
            {
                prvi = n;
                if (m > k)
                {
                    drugi = m;
                    treci = k;
                }
                else
                {
                    drugi = k;
                    treci = m;
                }
            }
            else
            {
                prvi = k;
                drugi = n;
                treci = m;
            }
        }
        else
        {
            if (m > k)
            {
                prvi = m;
                if (k > n)
                {
                    drugi = k;
                    treci = n;
                }
                else
                {
                    drugi = n;
                    treci = k;
                }
            }
            else
            {
                prvi = k;
                drugi = m;
                treci = n;
            }
        }
        rj_ruke = prvi - 1 + prvi * (drugi - 1) + prvi * drugi * (treci - 1);
        int prvi_br = shiftaj(prvi);
        int drugi_br = shiftaj(drugi);
        int treci_br = shiftaj(treci);
        rj_noz = prvi_br + drugi_br + treci_br;
        cout << "Case #" << (i + 1) << ": " << rj_ruke << " " << rj_noz << endl;
    }
    return 0;
}

