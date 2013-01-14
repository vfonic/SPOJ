#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    cin.sync_with_stdio(false);
    int n;
    
    cin >> n;
    
    string s;
    for (int i = 0; i < n; ++i)
    {
        getline(cin, s);
        
        int ng, nm;
        cin >> ng >> nm;
        
        int x, maxg = 0;
        for (int j = 0; j < ng; ++j)
        {
            cin >> x;
            if (x > maxg)
                maxg = x;
        }
        
        int maxm = 0;
        for (int j = 0; j < nm; ++j)
        {
            cin >> x;
            if (x > maxm)
                maxm = x;
        }
        
        cout << (maxg >= maxm ? "Godzilla" : "MechaGodzilla") << endl;
    }
    return 0;
}