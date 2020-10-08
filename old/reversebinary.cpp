#include <cstdio>
using namespace std;

int n,m;

int main()
{
	while (scanf("%d ", &n) != EOF)
	{
		int len;
		for (len = 0; (1 << len) <= n; len++);
		m = 0;
		for (int i = 0; i < len; i++) if (n & (1 << i))
			m |= (1 << (len - i - 1));
		
		printf("%d\n", m);
	}

	return 0;
}
