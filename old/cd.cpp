#include <cstdio>
using namespace std;

#define MAX_N 1000003

int N,M,jack[MAX_N],jill[MAX_N];

int main()
{
	while (scanf("%d %d ", &N, &M), N != 0 || M != 0)
	{
		for (int i = 0; i < N; i++)
			scanf("%d ", &jack[i]);
		for (int i = 0; i < M; i++)
			scanf("%d ", &jill[i]);

		int ans = 0;
		for (int i = 0, j = 0; i < N && j < M;)
		{
			if (jack[i] == jill[j])
				ans++, i++, j++;
			else if (jack[i] > jill[j])
				j++;
			else
				i++;
		}

		printf("%d\n", ans);
	}

	return 0;
}
