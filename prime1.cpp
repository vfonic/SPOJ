#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    cin.sync_with_stdio(false);
    
    int t;
    
    cin >> t;
    
    int cookie = 0;
    int a[100005];
    char b[100005];
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    
    for (int asfjasdg = 0; asfjasdg < t; ++asfjasdg)
    {
        int lower, upper;
        cin >> lower >> upper;
        
        if (lower < 2)
            lower = 2;
        
        ++cookie;
        
        int i = 2;
        while (i*i <= upper)
        {
            int pocetak;
            if (i >= lower)
                pocetak = i + i;
            else
            {
                pocetak = lower + (i - (lower % i));
                if (lower % i == 0)
                    a[0] = cookie;
            }
            // cout << "i = " << i;
            // cout << "\tpocetak = " << pocetak << endl;
            for (int j = pocetak; j <= upper; j += i)
            {
                if (j + i <= upper)
                    b[j - pocetak + i] = 1;
                a[j - lower] = cookie;
            }
            
            ++i;
            while (i < 100003 && b[i] == cookie)
            {
                ++i;
            }
        }
        
        for (int i = 0; i <= upper - lower; ++i)
        {
            if (a[i] != cookie)
                cout << i + lower << endl;
        }
    }
    
    return 0;
}
