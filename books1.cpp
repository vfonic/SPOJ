#include <iostream>

using namespace std;

int radnika, knjiga;
int stranice[500];

bool fit(int mid)
{
    int tmpStranica = 0;
    int br = 0;
    for (int i = knjiga - 1; i >= 0; --i)
    {
        if (tmpStranica + stranice[i] <= mid)
        {
            tmpStranica += stranice[i];
        }
        else
        {
            br++;
            tmpStranica = stranice[i];
            
            if (br == radnika)
                return false;
        }
    }
    return true;
}

void ispisiFit(int mid)
{
    int tmpStranica = 0;
    int indexi[500] = {0};
    int br = radnika - 1;
    for (int i = knjiga - 1; i >= 0; --i)
    {
        if (tmpStranica + stranice[i] <= mid)
        {
            tmpStranica += stranice[i];
        }
        else
        {
            br--;
            indexi[br] = i + 1;
            tmpStranica = stranice[i];
        }
    }
    
    for (int i = 0; i < radnika - 1; ++i)
    {
        if (indexi[i] == 0 || (i > 0 && indexi[i] <= indexi[i - 1]))
            indexi[i] = i + 1;
    }
    /*if (indexi[0] == 0)
    {
        int i = 0;
        while (indexi[i + 1] == i + 1)
        {
            indexi[i] = indexi[i + 1];
            i++;
        }
        indexi[i] = i + 1;
    }*/
    
    /*for (int i = 0; i < radnika - 1; ++i)
    {
        cout << indexi[i] << " i";
    }
    cout << endl;*/
    
    br = 0;
    cout << stranice[0] << " ";
    for (int i = 1; i < knjiga; ++i)
    {
        if (indexi[br] == i)
        {
            cout << "/ ";
            br++;
        }
        cout << stranice[i];
        if (i + 1 < knjiga) cout << " ";
        
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    cin.sync_with_stdio(false);
    
    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> knjiga >> radnika;
        
        int sum = 0, max = 0;
        for (int j = 0; j < knjiga; ++j)
        {
            cin >> stranice[j];
            sum += stranice[j];
            if (stranice[j] > max)
                max = stranice[j];
        }
        
        int lower = max, upper = sum, mid;
        while (lower < upper)
        {
            mid = lower + (upper - lower) / 2;
            
            if (fit(mid))
            {
                upper = mid;
            }
            else
            {
                lower = mid + 1;
            }
        }
        
        ispisiFit(lower);
        //cout << lower << endl;
    }
    
    return 0;
}
