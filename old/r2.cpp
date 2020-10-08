#include <cstdio>
using namespace std;

int main()
{
	int a,b;
	while (scanf("%d %d ", &a, &b) != EOF)
		printf("%d\n", 2*b - a);

	return 0;
}
