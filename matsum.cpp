#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 1026

int n;
int fenwick[MAXN][MAXN];
int mat[MAXN][MAXN];

void insert(int x, int y, int num) {
	int val = num - mat[x][y];
	for (int i = x+1; i <= n; i+=i&-i) {
		for (int j = y+1; j <= n; j+=j&-j) {
			fenwick[i][j] += val;
		}
	}
	mat[x][y] = num;
}

int sum(int x, int y) {
	int retVal = 0;
	for (int i = x+1; i > 0; i-=i&-i) {
		for (int j = y+1; j > 0; j-=j&-j) {
			retVal += fenwick[i][j];
		}
	}
	return retVal;
}

void print() {
	int lim = 10;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%4d ", fenwick[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	//printf("t:%d\n", t);

	while (t--) {
		scanf("%d", &n);
		//printf("n:%d\n", n);
		memset(fenwick, 0, sizeof fenwick);
		memset(mat, 0, sizeof mat);
		char comm[4];
		while (1) {
			scanf("%s", comm);
			//printf("comm:%s\n", comm);

			if (comm[2] == 'T') { // seT, suM, enD
				//printf("T\n");
				int x, y, num;
				scanf("%d%d%d", &x, &y, &num);
				//printf("x:%d y:%d num:%d\n", x, y, num);
				insert(x, y, num);
			} else if (comm[2] == 'M') { // seT, suM, enD
				//printf("M\n");
				int x1, y1, x2, y2;
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				printf("%d\n", sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1));
				//print();
			}
			else break;
		}
		printf("\n");
	}
	return 0;
}