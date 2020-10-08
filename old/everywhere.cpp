#include <cstdio>
#include <string>
#include <set>
using namespace std;

int n;

int main()
{
	int t; scanf("%d ", &t);
	while (t--)
	{
		scanf("%d ", &n);
		set<string> s;
		s.clear();
		
		while (n--)
		{
			char str[23];
			scanf("%s ", str);
			s.insert(string(str));
		}

		printf("%d\n", (int)s.size());
	}

	return 0;
}
