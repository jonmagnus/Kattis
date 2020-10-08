#include <cstdio>
using namespace std;

int n,m;

int main()
{
	while (scanf("%d ", &n) != EOF)
		while (n--)
		{
			scanf("%d ", &m);
			printf("%d is %s\n", m, m % 2 ? "odd" : "even");
		}

	return 0;
}
