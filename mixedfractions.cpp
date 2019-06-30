#include <cstdio>
using namespace std;

int t,n;

int main()
{
	while (scanf("%d %d ", &t,&n), t || n)
	{
		int r = t % n;
		t /= n;

		printf("%d %d / %d\n", t,r,n);
	}
	
	return 0;
}

