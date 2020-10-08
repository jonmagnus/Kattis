#include <cstdio>
using namespace std;

int X,Y,N;

int main()
{
	while (scanf("%d %d %d ", &X,&Y,&N) != EOF)
		for (int i = 1; i <= N; i++)
		{
			if (i % X && i % Y)
				printf("%d\n", i);
			else if (i % X)
				printf("Buzz\n");
			else if (i % Y)
				printf("Fizz\n");
			else
				printf("FizzBuzz\n");
		}

	return 0;
}
