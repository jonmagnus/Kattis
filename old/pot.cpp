#include <cstdio>
#include <cmath>
using namespace std;

int n,num,p;

int main()
{
	while (scanf("%d ", &n) != EOF)
	{
		int sum = 0, len;
		char str[10];
		while (n--)
		{
			scanf("%s%n ", str, &len);
			p = str[--len] - '0';
			str[len] = '\0';
			sscanf(str, "%d ", &num);
			fprintf(stderr, "pow(%d,%d)=%d\n", num,p,(int)pow(num,p));
			sum += pow(num,p);
		}
		printf("%d\n", sum);
	}
	
	return 0;
}
