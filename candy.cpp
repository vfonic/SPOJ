#include <iostream>
#include <cstring>

#define MAXN 10000

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int A[MAXN];
    while (n != -1) {
        memset(A, 0, sizeof A);
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &A[i]);
            sum += A[i];
        }

        if (sum % n != 0) {
            printf("-1\n");
        } else {
            int mid = sum / n;
            int sol = 0;
            for (int i = 0; i < n; ++i) {
                if (A[i] < mid) sol += mid - A[i];
            }

            printf("%d\n", sol);
        }

        scanf("%d", &n);
    }
    
    return 0;
}
