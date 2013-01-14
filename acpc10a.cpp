#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a1, a2, a3;
    
    while(true)
    {
        cin >> a1 >> a2 >> a3;
        if (!a1 && !a2 && !a3)
            break;
        
        // aritmeticki
        if (a3 - a2 == a2 - a1)
        {
            cout << "AP " << a3 + a3 - a2 << endl;
        }
        // geometrijski
        else
        {
            cout << "GP " << a3 * a3 / a2 << endl;
        }
    }
    return 0;
}