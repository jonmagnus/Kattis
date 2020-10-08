#include <cstdio>
using namespace std;

#define p 1000000009LL
#define x 97LL
#define y 103LL

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
		
int n;
ll h1[300005],h2[300005];
char str[300005];

inline ll g1(int i, int j) {return ((h1[j] - h1[i]*fast_exp(x,j-i)) % p + p) % p;}
inline ll g2(int i, int j) {return ((h2[j] - h2[i]*fast_exp(y,j-i)) % p + p) % p;}
inline ll g(int i, int j) {return g1(i,j)*p + g2(i,j);}

int main()
{
	fprintf(stderr, "a %d, b %d\n", (int)'a', (int)'b');
	fprintf(stderr, "exp(%lld,%lld)=%lld\n", 10LL,13LL,fast_exp(10LL,13LL));
	while (scanf("%s%n ", str,&n) != EOF)
	{
		h1[0] = 0;
		h2[0] = 0;
		for (int i = 0; i < n; i++) h1[i + 1] = (h1[i]*x + (ll)str[i]) % p;
		for (int i = 0; i < n; i++) h2[i + 1] = (h2[i]*y + (ll)str[i]) % p;
		int q;
		scanf("%d ", &q);
		
		for (int i = 0; i < n; i++)
			fprintf(stderr, "h1[%d] %lld, h2[%d] %lld\n", i,h1[i],i,h2[i]);

		while (q--)
		{
			int i,j;
			scanf("%d %d ", &i,&j);
			printf("%lld\n", g(i,j));
		}	
	}
	return 0;
}
