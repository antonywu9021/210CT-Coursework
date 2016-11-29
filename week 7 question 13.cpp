#include<iostream>
#define  MAX 10
using namespace std;
class Graph
{
private:
	int nodeNum;
	int edgeNum;
	int node[MAX];
	int edge[MAX][MAX];
	int visit[MAX];
public:
	Graph()
	{
		for (int i=0;i<MAX;i++)
		{
			node[i] = -1;
			for(int j=0;j<MAX;j++)
			{
				edge[i][j] = -1;
			}
		}
		nodeNum = 0;
		edgeNum = 0;
	};
	void addNode()
	{
		node[nodeNum] = 1;
		edge[nodeNum][nodeNum] = 1;
		nodeNum++;
	};
	void addEdge(int start,int end)
	{
		if (start > nodeNum - 1 || end > nodeNum - 1)
		{
			cout << "Wrong num" << endl;
			return;
		}
		edge[start][end] = 1;
		edgeNum++;
	}
	void show()
	{
		for (int i = 0; i<nodeNum; i++)
		{
			visit[i] = 0;
		}
		for (int i=0;i<nodeNum;i++)
		{
			if (visit[i] == 0)
			{
				visit[i] = 1;
				for (int j=0;j<nodeNum;j++)
				{
					if (edge[i][j] > 0 && visit[j] == 0)
					{
						visit[i] = 1;
						cout << i << "--->" << j<<endl;
					}
				}
			}
		}
	}
};

int main()
{
	Graph graph;
	graph.addNode();
	graph.addNode();
	graph.addNode();
	graph.addNode();
	graph.addNode();

	graph.addEdge(0,1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);
	graph.addEdge(1, 4);
	graph.show();
	return 0;
}

