#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_M 103

int n,m;
char str[105];

int main()
{
	while (scanf("%d ", &n) != EOF)
		while (n-- > 0)
		{
			fgets(str, 100, stdin);
			m = strlen(str);
			if (m >= 10 && !strncmp("Simon says ", str, 10))
				printf("%s", str + 10);
		}

	return 0;
}
