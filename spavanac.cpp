#include <cstdio>
using namespace std;

int h,m;

int main()
{
	while (scanf("%d %d ", &h, &m) != EOF)
	{
		m -= 45;
		if (m < 0)
		{
			m += 60;
			h--;
		}
		if (h < 0)
			h += 24;

		printf("%d %d\n", h,m);
	}
	return 0;
}
