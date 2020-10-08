#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_N 10005
typedef pair<int,double> id;
typedef vector<id> vid;
typedef vector<vid> vvid;
typedef pair<double,int> di;

int n,m;
vvid adj_list;


int main()
{
	while (scanf("%d %d ", &n, &m), n || m)
	{
		adj_list.assign(n,vid());
		for (int i = 0; i < m; i++)
		{
			int u,v;
			double d;
			scanf("%d %d %lf ", &u,&v,&d);
			adj_list[u].push_back(id(v,d));
			adj_list[v].push_back(id(u,d));
		}
		
		double dist[MAX_N];
		memset(dist,0,sizeof dist);
		priority_queue<di> pq;
		dist[0] = 1.;
		pq.push(di(1.,0));
		while (!pq.empty())
		{
			int u = pq.top().second;
			double d = pq.top().first;
			pq.pop();
			if (d < dist[u]) continue;
			for (int i = 0; i < (int)adj_list[u].size(); i++)
			{
				int v = adj_list[u][i].first;
				double f = adj_list[u][i].second;
				if (f*dist[u] <= dist[v]) continue;
				dist[v] = f*dist[u];
				pq.push(di(dist[v],v));
			}
		}
		
		printf("%.4lf\n", dist[n-1]);
	}

	return 0;
}
