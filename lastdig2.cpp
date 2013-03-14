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
    int a;
    char x;
    while (true) {
      scanf("%c", &x);
      if (x == ' ') break;
      a = x - '0';
    }
    long long b;
    scanf("%lld", &b);
    if (b == 0) { printf("1\n"); continue; }
    
    int base_a = a;
    a %= 10;
    int br = 0;
    vector<int> dig;
    while (!bio[a]) {
      dig.push_back(a);
      bio[a] = true;
      a = (a * base_a) % 10;
      ++br;
    }
    printf("%d\n", dig[(b-1) % br]);
  }
  return 0;
}
