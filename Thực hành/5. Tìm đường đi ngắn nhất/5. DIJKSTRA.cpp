/* Bui Phu Khuyen
16DTCH4 - 1611061839 */
///---Week 5: FIND SHORTEST PATH - DIJKSTRA---///

#include<stdio.h>
#define MAX 50
#define INF 1e9
#define LinkInput "C:/File Test/Test_5.txt"

int Path[MAX];
int Visited[MAX];
int Dist[MAX];

typedef struct GRAPH {
	int n;
	int a[MAX][MAX];
}Graph;

int ReadFile(char FileName[100], Graph &g) {
	FILE * f = fopen(FileName,"rt");
	if(f == NULL) {
		printf("Opening File Error!");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = 0 ; j < g.n ; j++) {
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;
}

void OutPutMatrix(Graph g) {
	printf("Graph Vertices is: %d\n",g.n);
	printf("Adjacency Matrix:\n");
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = 0 ; j < g.n ; j++) {
			printf("%3d",g.a[i][j]);
		}
		printf("\n");
	}
}

int FindWay(Graph g) {
	int li = -1;
	float p = INF;
	for(int i = 0 ; i < g.n ; i++) {
		if(Visited[i] == 0 && Dist[i] < p) {
			p = Dist[i];
			li = i;
		}
	}
	return li; 
}

void UpdateWay(int u, Graph g) {
	Visited[u] = 1;
	for(int v = 0 ; v < g.n ; v++) {
		if(g.a[u][v]!=0 && Visited[v] == 0 && g.a[u][v] < INF) {
			if(Dist[v] > Dist[u] + g.a[u][v]) {
				Dist[v] = Dist[u] + g.a[u][v];
				Path[v] = u;
			}
		}
	}
}

void Dijkstra(int S, int F, Graph g) {
	for(int i = 0 ; i < g.n ; i++) {
		Path[i] = -1;
		Visited[i] = 0;
		Dist[i] = INF;
	}
	Dist[S] = 0;
	while(Visited[F] == 0) {
		int u = FindWay(g);
		if(u == -1) break;
		UpdateWay(u,g);
	}
	if(Visited[F] == 1) {
		printf("Shortest Path from %c to %c using Dijkstra Algorithm:",S+'A',F+'A');
		int i = F;
		printf("%3c",F+'A');
		while(Path[i] != S) {
			printf(" <-%2c",Path[i]+'A');
			i = Path[i];
		}
		printf(" <-%2c",Path[i]+'A');
		printf("\nWeight of Path: %d",Dist[F]);
	}
	else {
		printf("No path from %c to %c\n",S+'A', F+'A');
	}
}

int main() {
	Graph g;
	if(ReadFile(LinkInput,g) == 1) {
		printf("Receive from File is Success!\n");
		OutPutMatrix(g);
		Dijkstra(0,10,g);
	}	
	return 0;
}


