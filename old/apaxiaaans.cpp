#include <cstdio>
using namespace std;

int n,m;
char in[250],out[250];

int main()
{
	while (scanf("%s%n ", in, &n) != EOF)
	{
		m = 1;
		out[0] = in[0];
		for (int i = 1; i < n; i++)
			if (in[i] != in[i - 1])
				out[m++] = in[i];

		out[m] = '\0';
		printf("%s\n", out);
	}

	return 0;
}
