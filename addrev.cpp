#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int N;
    
    cin >> N;
    
    string prvi, drugi;
    for (int i = 0; i < N; ++i)
    {
        cin >> prvi >> drugi;
        prvi = string(prvi.rbegin(), prvi.rend());
        drugi = string(drugi.rbegin(), drugi.rend());
        
        int prviInt;
        stringstream ss(prvi);
        ss >> prviInt;
        
        int drugiInt;
        stringstream ss2(drugi);
        ss2 >> drugiInt;
        
        int suma = prviInt + drugiInt;
        stringstream ss3;
        ss3 << suma;
        string rezultat = ss3.str();
        rezultat = string(rezultat.rbegin(), rezultat.rend());
        
        stringstream ss4(rezultat);
        int rezultatInt;
        ss4 >> rezultatInt;
        
        cout << rezultatInt << endl;
    }
    return 0;
}