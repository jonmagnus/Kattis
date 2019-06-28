#include <cstdio>
#include <cmath>
using namespace std;

const double pi = 4*atan((double)1.);

int h,v;

int main()
{
	while (scanf("%d %d ", &h,&v) != EOF)
	{
		int l = ceil((double)h/sin(v*pi/180.));
		printf("%d\n", l);
	}

	return 0;
}
