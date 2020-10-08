#include <cstdio>
using namespace std;

#define MAX_N 12

int n,s[MAX_N],t[MAX_N];

int main()
{
	while (scanf("%d ", &n), n != -1)
	{
		for (int i = 0; i < n; i++)
			scanf("%d %d ", &s[i], &t[i]);
		
		for (int i = n - 1; i > 0; i--)
			t[i] -= t[i - 1];
		
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += s[i]*t[i];

		printf("%d miles\n", ans);
	}

	return 0;
}
