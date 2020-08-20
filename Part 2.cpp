#include<iostream>
#include<climits>    

using namespace std;

#define Vertex 7      

int minimumDist(int Dist[], bool D_set[])   
{
	int Minimum = INT_MAX, Index;   
	
	for (int v = 0; v < Vertex; v++)
	{
		if (D_set[v] == false && Dist[v] <= Minimum)
		{
			Minimum = Dist[v];

			Index = v;
		}
	}
	return Index;
}
void Dijkstra(int Graph[Vertex][Vertex], int Src) 
{
	int Dist[Vertex];
	bool Dset[Vertex];

	for (int i = 0; i < Vertex; i++)                   
	{
		Dist[i] = INT_MAX;
		Dset[i] = false;
	}

	Dist[Src] = 0;   

	for (int i = 0; i < Vertex; i++)
	{
		int u = minimumDist(Dist, Dset);              
		Dset[u] = true;                             
		for (int j = 0; j < Vertex; j++)
			
		{
			if (!Dset[j] && Graph[u][j] && Dist[u] != INT_MAX && Dist[u] + Graph[u][j] < Dist[j])
				Dist[j] = Dist[u] + Graph[u][j];
		}
	}

	cout << "The Vertex\t Distance from the source" << endl;

	for (int i = 0; i < Vertex; i++)                       
	{
		char c = 65 + i;

		cout << c << "\t\t" << Dist[i] << endl;
	}
}

int main()
{
	int graph[Vertex][Vertex] = { {0,5,3,0,0,0,0},{0,0,2,0,3,0,1},{0,0,0,7,7,0,0},{2,0,0,0,0,6,0},{0,0,0,2,0,1,0},{0,0,0,0,0,0,0},
								{0,0,0,0,1,0,0} };
	Dijkstra(graph, 0);

	return 0;
}