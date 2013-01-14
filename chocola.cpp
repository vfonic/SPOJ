#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int t;
    
    cin >> t;
    
    for (int asfa = 0; asfa < t; ++asfa)
    {
        long long m, n;
        cin >> m >> n;
        --m; --n;
        
        if (m == 0 && n == 0) { cout << "0" << endl; continue; }
        
        int a[1000], b[1000];
        
        long long suma = 0, sumb = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> a[i];
            suma += a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
            sumb += b[i];
        }
        
        if (m == 0) { cout << sumb << endl; continue; }
        if (n == 0) { cout << suma << endl; continue; }
        
        long long mnozitelja = 1, mnoziteljb = 1;
        sort(a, a+m); sort(b, b+n);
        int poza = m - 1, pozb = n - 1;
        long long sol = 0;
        
        while (true)
        {
            if (a[poza] > b[pozb])
            {
                sol += a[poza] * mnozitelja;
                ++mnoziteljb;
                --poza;
                if (poza == -1)
                {
                    while(pozb != -1)
                    {
                        sol += b[pozb] * mnoziteljb;
                        --pozb;
                    }
                    break;
                }
            }
            else
            {
                sol += b[pozb] * mnoziteljb;
                --pozb;
                ++mnozitelja;
                if (pozb == -1)
                {
                    while(poza != -1)
                    {
                        sol += a[poza] * mnozitelja;
                        --poza;
                    }
                    break;
                }
            }
        }
        
        cout << sol << endl;
    }
    
    return 0;
}


