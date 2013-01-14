#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a[4], b[4];
    
    while (true)
    {
        for (int i = 0; i < 4; ++i)
        {
            cin >> a[i];
        }
        
        for (int i = 0; i < 4; ++i)
        {
            cin >> b[i];
        }
        
        if (a[0] == -1)
            return 0;
        
        int mod[4];
        for (int i = 0; i < 4; ++i)
        {
            mod[i] = (b[i] - (a[i] % b[i])) % b[i];
            a[i] += mod[i];
        }
        
        int rj[4];
        for (int i = 0; i < 4; ++i)
        {
            rj[i] = mod[i];
        }
        
        int div[4], maxdiv = 0;
        for (int i = 0; i < 4; ++i)
        {
            div[i] = a[i] / b[i];
            if (div[i] > maxdiv)
                maxdiv = div[i];
        }
        
        for (int i = 0; i < 4; ++i)
        {
            rj[i] += (maxdiv - div[i]) * b[i];
        }
        
        for (int i = 0; i < 4; ++i)
        {
            cout << rj[i] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
