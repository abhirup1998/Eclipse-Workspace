#include <iostream>
#include <climits>
using namespace std;
typedef struct Node{
	Node* next;
	int dest;
}Node;
struct AdjList{
	Node* head;
};
int diffsal = INT_MIN;
class Graph
{
public:
	int V;
	struct AdjList* array;
	Graph(int V)
	{
		this->V = V;
		array = new AdjList[V];
		for(int i = 0; i < V; i++)
			array[i].head = NULL;
	}
	Node* newAdjListNode(int dest)
	{
		Node* newNode = new Node;
		newNode->dest = dest;
		newNode->next = NULL;
		return newNode;
	}
	void addEdge(int src, int dest)
	{
		Node* newNode = newAdjListNode(dest);
		newNode->next = array[src].head;
		array[src].head = newNode;
		newNode = newAdjListNode(src);
		newNode->next = array[dest].head;
		array[dest].head = newNode;
	}
};

void dfs(AdjList* arr, int v, bool* visited, int* A, int maxsal)
{
	visited[v] = true;
	if(A[v] > maxsal) maxsal = A[v];
	diffsal = max(diffsal, maxsal - A[v]);

	Node *pcrawl = arr[v].head;
	int x = 0;
	while(pcrawl)
	{
		int u = pcrawl->dest;
		if(!visited[u])
		{
			dfs(arr, u, visited, A, maxsal);
		}
		pcrawl = pcrawl->next;
	}
}
void dfsUtil(AdjList* arr, int num, int root, int* A)
{
	bool visited[num];
	for (int i = 0; i < num; ++i) {
		visited[i] = false;
	}
	dfs(arr, root, visited, A, A[root]);
}

int main()
{
	int num;
	cin >> num;
	Graph gh(num);
	int A[num], P[num], i = 0, root = 0;
	for (i = 0; i < num; ++i) {
		cin >> A[i];
	}
	for (i = 0; i < num; ++i) {
		int val;
		cin >> val;
		if(val ==-1)root = i;
		P[i] = val;
		if(val == -1)continue;
		gh.addEdge(val-1, i);
	}
	dfsUtil(gh.array, num, root, A);
	cout << diffsal << endl;
    return 0;
}
