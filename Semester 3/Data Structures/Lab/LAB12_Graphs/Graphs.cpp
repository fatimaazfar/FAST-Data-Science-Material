#include<iostream>
#include<list>
#include<vector>
#include<fstream>
using namespace std;

void Listprint(list<int> const& list)
{
	for (auto it = list.cbegin(); it != list.cend(); it++) {
		cout << *it << " ";
	}
}

class Graph
{
	vector<list<int>> vertices;	//array for vertices
	int size;
public:
	Graph(int s = 10)
	{
		while(s < 1)
		{
			cout << "Size cannot be smaller than 1." << endl;
			cout << "Enter again : ";
			cin >> s;
		}
		size = s + 1;
		vertices.resize(size);
	}
	void addEdge(int vertex, int edge)//undirected graph
	{
		vertices[vertex].push_back(edge);
		vertices[edge].push_back(vertex);
	}
	void readFile(string path)
	{
		int elem1 = 0, elem2 = 0;
		char space = ' ';
		ifstream fin;
		fin.open(path);
		fin >> size; //first line has file
		size += 1;
		vertices.clear();
		vertices.resize(size);
		while (!fin.eof())
		{
			fin >> elem1;
			fin >> elem2;
			addEdge(elem1, elem2);
		}
		fin.close();
	}
	void print()
	{
		iter();
	}
	void iter()
	{
		for (int i = 1;i < size; i++)
		{
			cout << i << " : ";
			Listprint(vertices[i]);
			cout << endl;
		}
	}
	int inDegree(int vertex)//undirected graph
	{
		return vertices[vertex].size();
	}
	int outDegree(int vertex)//undirected graph
	{
		return vertices[vertex].size();
	}
	void printNeighbours(int vertex)
	{
		cout << "Neighbour vertices of " << vertex << " are : ";
		Listprint(vertices[vertex]);
		cout << endl;
	}
	void DFShelp(int v, bool visited[])
	{
		visited[v] = true;
		cout << v << " ";
		list<int>:: iterator i;
		for (i = vertices[v].begin();i != vertices[v].end();i++)
		{
			if (!visited[*i])
				DFShelp(*i, visited);
		}
	}
	void DFS(int v)
	{
		bool* visited = new bool[size];
		for (int i = 1; i < size;i++)
			visited[i] = false;
		DFShelp(v, visited);
	}
	~Graph()
	{
		for (int i = 1;i < size; i++)
		{
			vertices[i].clear(); //delete the lists
		}
		vertices.clear(); //delete the vector
	}
};

int main()
{
	Graph g;
	g.readFile("nodes.txt");
	g.print();
	cout << "InDegree of 1 : " << g.inDegree(1) << endl;
	g.printNeighbours(1);
	cout << "Printing using DFS : ";
	g.DFS(1);
	return 0;
}