#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  bool bio[10];
  for (int qwertz = 0; qwertz < t; ++qwertz) {
    memset(bio, 0, sizeof bio);
    int a, b;
    scanf("%d %d", &a, &b);
    if (b == 0) { printf("1\n"); continue; }
    if (a == 0) { printf("0\n"); continue; }
    
    int base_a = a;
    a %= 10;
    int br = 0;
    vector<int> ordered_last_digits;
    while (!bio[a]) {
      ordered_last_digits.push_back(a);
      bio[a] = true;
      a = (a * base_a) % 10;
      ++br;
    }
    printf("%d\n", ordered_last_digits[(b-1) % br]);
  }
  return 0;
}
