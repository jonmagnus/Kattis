#include <cstdio>
#include <algorithm>
using namespace std;

#define MOD 360000LL
#define MAX_N 200003
#define P 1000000007LL
#define X 1000003LL

typedef long long ll;

int n, a[MAX_N], b[MAX_N], da[MAX_N], db[MAX_N];
ll h[MAX_N];

ll exp(ll a, ll b)
{
	ll prod = 1;
	while (b)
	{
		if (b & 1) prod = (prod * a) % P;
		a = (a*a) % P;
		b /= 2;
	}
	return prod;
}

int main()
{
	while (scanf("%d ", &n) != EOF)
	{
		for (int i = 0; i < n; i++) scanf("%d ", &a[i]);
		for (int i = 0; i < n; i++) scanf("%d ", &b[i]);
		
		sort(a,a + n);
		sort(b,b + n);
		for (int i = 1; i < n; i++)
		{
			da[i] = a[i] - a[i-1];
			db[i] = b[i] - b[i-1];
		}
		da[0] = a[0] - a[n-1] + MOD;
		db[0] = b[0] - b[n-1] + MOD;

		/*
		for (int i = 0; i < n; i++)
			fprintf(stderr, "%d: da %d, db %d\n", i,da[i],db[i]);
			*/

		ll ah = 0;
		for (int i = 0; i < n; i++)
		{
			ah *= X;
			ah += da[i];
			ah %= P;
		}

		//fprintf(stderr, "ah %lld\n", ah);

		h[0] = 0;
		for (int i = 0; i < n; i++)
		{
			ll &bh = h[0];
			bh *= X;
			bh += db[i];
			bh %= P;
		}

		int possible = 0;
		//ll X_pow =  exp(X,n);
		ll X_pow = 1;
		for (int i = 0; i < n; i++)
			X_pow = (X*X_pow) % P;

		for (int i = 1; i < n; i++)
		{
			h[i] = (h[i-1]*X - db[0]*(X_pow - 1)) % P;
			h[i] = (h[i] + P) % P;
			//fprintf(stderr, "h[%d] %lld\n", i, h[i]);
			if (h[i] == ah) possible = 1;
		}

		if (h[0] == ah) possible = 1;

		if (possible)
			printf("possible\n");
		else
			printf("impossible\n");
	}
	return 0;
}
	 
