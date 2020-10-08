#include <cstdio>
#include <cmath>
using namespace std;

#define MAX_N 32
typedef long long ll;

int N, c[MAX_N];
double tape_len, zero_len = pow(2,-(double)1./4.);

void create(int s, int n)
{
	//fprintf(stderr, "c[%d]=%d\n", s,c[s]);
	int need = 2*n - c[s];
	if (need > 0) create(s + 1, need);
	c[s] -= 2*n;
	c[s - 1] += n;
	tape_len += n*zero_len*pow(2.,-(double)s/2);
}

int main()
{
	while (scanf("%d ", &N) != EOF)
	{
		ll mask = 0;
		tape_len = 0;
		for (int i = 1; i < N; i++) scanf("%d ", &c[i]);
		for (int i = 1; i < N; i++) mask += (ll)c[i]*(1LL << (N - i));
		//fprintf(stderr, "mask: %6llx\nN:    %6llx\n", mask, 1LL << N);
		c[0] = 0;
		if (mask >= (1LL << N)) 
		{
			create(1,1);
			printf("%.11lf\n", tape_len);
		}
		else printf("impossible\n");
	}

	return 0;
}
