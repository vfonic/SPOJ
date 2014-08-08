#include <cstdio>
#include <algorithm>
#define MAXN 300000

using namespace std;

int main() {
	int n, m;
	int a[MAXN];
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int sol = 0;
	int sum = 0;
	int right = 0;
	int left = 0;
	while (true) {
		while (right < n && sum + a[right] < m) {
			sum += a[right++];
		}

		sol = max(sol, sum);

		if (right == n) break;

		sum += a[right++];

		while (left < n && sum > m) {
			sum -= a[left++];
		}
	}

	printf("%d\n", sol);

	return 0;
}