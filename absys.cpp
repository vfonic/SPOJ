#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    
    cin >> t;
    
    string line[t];
    getline(cin, line[0]);
    for (int i = 0; i < t; ++i)
    {
        getline(cin, line[i]);
        getline(cin, line[i]);
    }
    
    for (int i = 0; i < t; ++i)
    {
        int m = line[i].find('m');
        int plus = line[i].find('+');
        int equals = line[i].find('=');
        stringstream ss(line[i]);
        string trash;
        int prvi, drugi, rezultat;
        
        if (m < plus)
        {
            ss >> trash >> trash >> drugi >> trash >> rezultat;
            prvi = rezultat - drugi;
        }
        else if (m < equals)
        {
            ss >> prvi >> trash >> trash >> trash >> rezultat;
            drugi = rezultat - prvi;
        }
        else
        {
            ss >> prvi >> trash >> drugi >> trash >> trash;
            rezultat = prvi + drugi;
        }
        
        cout << prvi << " + " << drugi << " = " << rezultat << endl;
    }
    return 0;
}