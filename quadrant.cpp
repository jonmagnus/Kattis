#include <cstdio>
using namespace std;

int x,y;

int main()
{
	while (scanf("%d %d ", &x, &y) != EOF)
	{
		if (y > 0)
			printf("%d\n", x > 0 ? 1 : 2);
		else
			printf("%d\n", x > 0 ? 4 : 3);
	}

	return 0;
}
