#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        
        int rj = 0;
        
        for (int j = 0; j < s.size(); ++j)
        {
            char broj = s[j] - '0';
            if (broj == 6 || broj == 9 || broj == 0)
                rj++;
            else if (broj == 8)
                rj += 2;
        }
        cout << rj << endl;
    }
    return 0;
}