#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    
    cin >> t;
    
    for (int xyxsa = 0; xyxsa < t; ++xyxsa)
    {
        int n;
        
        cin >> n;
        
        long long previous = 0, x;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            x += previous;
            previous = x % n;
        }
        
        if (previous == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
