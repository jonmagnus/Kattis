#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX_N 1003

int N, tour[MAX_N], used[MAX_N];
double x[MAX_N], y[MAX_N];

inline double dist(int i, int j)
{
	return hypot(x[i] - x[j], y[i] - y[j]);
}

void greedy()
{
	memset(used,0,sizeof used);
	tour[0] = 0;
	used[0] = 1;
	for (int i = 1; i < N; i++)
	{
		int best = -1;
		for (int j = 0; j < N; j++) if (!used[j])
			if (best == -1 || dist(tour[i-1],j) < dist(tour[i-1],best))
				best = j;
		tour[i] = best;
		used[best] = 1;
	}
}

int main()
{
	while (scanf("%d ", &N) != EOF)
	{
		for (int i = 0; i < N; i++)
			scanf("%lf %lf ", &x[i], &y[i]);
		greedy();
		for (int i = 0; i < N; i++)
			printf("%d\n", tour[i]);
	}

	return 0;
}
