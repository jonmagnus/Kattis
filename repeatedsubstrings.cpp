#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_N 100003
#define P 1000000009LL
#define X 10007LL
#define max(A,B) ((A) > (B) ? (A) : (B))

typedef long long ll;
typedef pair<int,int> ii;

int n;
char str[MAX_N];
ll h[MAX_N];

ll pow(ll a, ll b)
{
	ll prod = 1;
	while (b)
	{
		if (b & 1) prod = (prod*a) % P;
		a = (a*a) % P;
		b /= 2;
	}
	return prod;
}

inline ll g(int i, int j) {return ((h[j] - h[i]*pow(X,j-i)) % P + P) % P;}

int binary_equal(int a, int b)
{
	int hi = n - max(a,b) + 1;
	int lo = 0;
	while (hi > lo + 1)
	{
		int mid = (hi + lo)/2;
		if (g(a,a + mid) == g(b,b + mid))
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

bool compare(int a, int b)
{
	int len = binary_equal(a,b);
	if (len == n - a) return true;
	if (len == n - b) return false;
	return str[a + len] < str[b + len];
}

int main()
{
	while (scanf("%s%n ", str, &n) != EOF)
	{
		h[0] = 0;
		for (int i = 0; i < n; i++)
			h[i+1] = (h[i]*X + (int)str[i]) % P;

		int table[MAX_N];
		for (int i = 0; i < n; i++) table[i] = i;
		sort(table, table + n, compare);

		/*
		for (int i = 0; i < n; i++)
			fprintf(stderr,"%2d: %s\n", i, str + table[i]);
			*/

		int longest = 0, length = 0;
		for (int i = 1; i < n; i++)
		{
			int l = binary_equal(table[i], table[i-1]);
			//fprintf(stderr,"%d: l %d, s1 %s, s2 %s\n", i,l,str + table[i], str + table[i-1]);
			if (l > length)
				longest = table[i], length = l;
		}

		printf("%.*s\n", length,str + longest);
	}

	return 0;
}
