#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#define inf INT_MAX

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    
    string line;
    while(getline(cin, line))
    {
        if (line[0] == '_' || line[line.size() - 1] == '_' || line.find("__") != -1 || isupper(line[0]))
        {
            cout << "Error!" << endl;
            continue;
        }
        if (line.find('_') == -1)
        {
            stringstream ss;
            bool error = false;
            for (int i = 0; i < line.size(); ++i)
            {
                if (!isalpha(line[i]))
                {
                    cout << "Error!" << endl;
                    error = true;
                    break;
                }
                if (isupper(line[i]))
                    ss << "_" << (char)tolower(line[i]);
                else
                    ss << line[i];
            }
            if (!error)
                cout << ss.str() << endl;
        }
        else
        {
            stringstream ss;
            bool error = false;
            bool prosli = false;
            for (int i = 0; i < line.size(); ++i)
            {
                if ((line[i] != '_' && !isalpha(line[i])) || isupper(line[i]))
                {
                    cout << "Error!" << endl;
                    error = true;
                    break;
                }
                if (line[i] == '_')
                    prosli = true;
                else if (prosli)
                {
                    prosli = false;
                    ss << (char)toupper(line[i]);
                }
                else
                    ss << line[i];
            }
            if (!error)
                cout << ss.str() << endl;
        }
    }
    
    return 0;
}
