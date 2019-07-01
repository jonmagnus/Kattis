#include <cstdio>
#include <stack>
using namespace std;

char str[MAX_N], num[100];

struct node
{
	node() {left = right = nullptr; h = 0;}
	node *left, *right;
	int h;
}

int h[MAX_N];

int main()
{
	stack<*node> s;
	char c = 0;
	node root();
	s.push(&root);
	while(c || (scanf("%c", &c) != EOF && c != '\n'))
	{
		if (c >= '0' && c <= '9')
		{
			int len = 1;
			num[0] = c;
			while (scanf("%c", &c) != EOF && c >= '0' && c <= '9')
				num[len++] = c;
			num[len] = '\0';
			int val; sscanf(num, "%d ", &val);
			
			s.top().h = h[val];
			continue;
		}
		if (c == '(')
		{
			node n();
			s.top()
			


	return 0;
}
