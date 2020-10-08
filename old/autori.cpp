#include <cstdio>
using namespace std;

#define MAX_N 103
int n;
char in[MAX_N], out[MAX_N];

int main()
{
	while (scanf("%s%n ", in, &n) != EOF)
	{
		int m = 0;
		for (int i = 0; i < n; i++) if (in[i] >= 'A' && in[i] <= 'Z')
			out[m++] = in[i];
		out[m] = '\0';
		printf("%s\n", out);
	}

	return 0;
}
