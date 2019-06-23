#include <cstdio>
#include <set>
#include <string>
using namespace std;

int t,n;

int main()
{
	scanf("%d ", &t);
	while (t--)
	{
		scanf("%d ", &n);
		bool legal = 1;
		
		char num[13];
		set<string> list;
		list.clear();
		while (n--)
		{
			scanf("%s ", num);
			string st(num);
			set<string>::iterator it = list.lower_bound(st);
				
			if (it != list.begin())
			{
				it--;
				if (it->length() < st.length() && *it == st.substr(0,it->length()))
					legal = 0;
				it++;
			}
			if (it != list.end() 
					&& st.length() < it->length() 
					&& st == it->substr(0,st.length()))
				legal = 0;
			list.insert(st);
		}
		if (legal)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
