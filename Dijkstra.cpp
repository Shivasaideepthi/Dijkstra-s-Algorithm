#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int minimumDist(vector<int>& dist, vector<bool>& Tset)
{
	int min = INT_MAX, index;

	for(int i = 0; i < dist.size(); i++)
	{
		if(Tset[i] == false && dist[i] <= min)
		{
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void Dijkstra(vector<vector<int>>& graph, int src)
{
	int n = graph.size();
	vector<int> dist(n, INT_MAX); // Initialize distances to infinity
	vector<bool> Tset(n, false); // Initialize Tset to false

	dist[src] = 0; // Source vertex distance is set to zero

	for(int i = 0; i < n; i++)
	{
		int m = minimumDist(dist, Tset);
		Tset[m] = true;
		for(int j = 0; j < n; j++)
		{
			if(!Tset[j] && graph[m][j] && dist[m] != INT_MAX && dist[m] + graph[m][j] < dist[j])
				dist[j] = dist[m] + graph[m][j];
		}
	}
	cout << "Vertex\t\tDistance from source" << endl;
	for(int i = 0; i < n; i++)
	{
		char str = 'A' + i; // Convert index to uppercase letter
		cout << str << "\t\t\t" << dist[i] << endl;
	}
}

int main()
{
	int n;
	cout << "Enter the number of vertices in the graph: ";
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));

	cout << "Enter the adjacency matrix:\n";
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	int src;
	cout << "Enter the source vertex (0 to " << n-1 << "): ";
	cin >> src;

	Dijkstra(graph, src);
	return 0;
}
