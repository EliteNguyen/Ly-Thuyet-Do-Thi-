/* Bui Phu Khuyen
16DTCH4 - 1611061839 */
///---Week 3: DEPTH FIRST SEARCH ALGORITHM---///

#include<stdio.h>
#define MAX 50
#define LinkInput "C:/File Test/Test_3.txt"

int Path[MAX];
int Visited[MAX];

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

int DFS(int v, Graph g) {
	Visited[v] = 1;
	for(int u = 0 ; u < g.n ; u++) {
		if(g.a[v][u] != 0 && Visited[u] == 0) {
			Path[u] = v;
			DFS(u,g);
		}
	}
	return 1;	
}

void DFS_Main(int S, int F, Graph g) {
	for(int i = 0 ; i < g.n ; i++) {
		Path[i] = -1;
		Visited[i] = 0;
	}
	DFS(S,g);
	int Reverse[MAX];
	if(Visited[F]==1) {
		printf("Path from %c to %c using DFS Algorithm:\n", S+'A', F+'A');
		int i = F;
		printf("%3c",F+'A');
		while(S != i) {	
			printf(" <-%2c",Path[i]+'A');
			i = Path[i];
		}
	}
	else {
		printf("No path from %c to %c!", S+'A', F+'A');
	}
}

int main() {
	Graph g;
	if(ReadFile(LinkInput,g) == 1) {
		printf("Receive from File is Success!\n");
		OutPutMatrix(g);
		DFS_Main(0,10,g);
	}
	return 0;
}
