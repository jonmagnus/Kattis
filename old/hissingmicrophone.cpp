#include <cstdio>
#include <cstring>
using namespace std;

int n;
char str[33];

int main()
{
	while (scanf("%s%n ", str, &n) != EOF)
	{
		bool hiss = 0;
		for (int i = 0; i < n - 1; i++)
			if (str[i] == 's' && str[i + 1] == 's')
				hiss = 1;
		
		if (hiss)
			printf("hiss\n");
		else
			printf("no hiss\n");
	}

	return 0;
}
