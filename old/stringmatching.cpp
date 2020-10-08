#include <cstdio>
#include <cstring>
using namespace std;

#define p 1000000009LL
#define x 97LL

typedef long long ll;

//TODO: Larger prime modulo? Overflow when multiplying?

ll fast_exp(ll a, ll b)
{
	ll prod = 1;
	while (b)
	{
		if (b & 1) prod = (prod * a) % p;
		a = (a*a) % p;
		b /= 2;
	}
	return prod;
}
		
int n,m;
ll h[5000005];
char str[5000005], pat[5000005];

inline ll g(int i, int j) {return h[j] - h[i]*fast_exp(x,j-i);}

int main()
{
	while (fgets(pat, 5000001, stdin) != nullptr)
	{
		fgets(str, 5000001, stdin);
		//fprintf(stderr, "str: %spat: %s", str,pat);
		n = strlen(str); if (str[n - 1] == '\n') str[--n] = '\0';
		m = strlen(pat); if (pat[m - 1] == '\n') pat[--m] = '\0';
		fprintf(stderr, "n %d, m %d\n", n,m);

		if (!(n && m)) break;
		
		ll x_pow = 1;
		for (int i = 0; i < m; i++) x_pow = (x_pow*x) % p;
		
		ll hash = 0;
		for (int i = 0; i < m; i++)
		{
			//fprintf(stderr, "h[%d] %d\n", i,(int)h[i]);
			hash *= x;
			hash += (int)pat[i];
			hash %= p;
		}
		//fprintf(stderr, "hash %lld\n", hash);
		
		h[0] = (int)str[0];
		for (int i = 1; i < m; i++)
		{
			h[i] = h[i-1]*x;
			h[i] += (int)str[i];
			h[i] %= p;
		}
		
		for (int i = m; i < n; i++)
		{
			h[i] = h[i-1]*x - str[i - m]*x_pow;
			h[i] += (int)str[i];
			h[i] %= p;
			h[i] = (h[i] + p) % p;
		}

		for (int i = 0; i < n; i++) if (hash == h[i])
			printf("%d ", i-m + 1);

		printf("\n");
	}

	return 0;
}
