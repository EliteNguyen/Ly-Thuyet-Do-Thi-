/* Bui Phu Khuyen
16DTCH4 - 1611061839 */
///---Week 3: BREADTH FIRST SEARCH ALGORITHM---///

#include<stdio.h>
#define MAX 50
#define LinkInput "C:/File Test/Test_3.txt"

int Path[MAX];
int Visited[MAX];

typedef struct GRAPH {
	int n;
	int a[MAX][MAX];
}Graph;

typedef struct QUEUE {
	int size;
	int b[MAX];
}Queue;

int ReadFile(char FileName[100], Graph &g) {
	FILE * f = fopen(FileName, "rt");
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

void OutPutMaxtrix(Graph g) {
	printf("Graph Vertices is: %d\n", g.n);
	printf("Matrix is:\n");
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = 0 ; j < g.n ; j++) {
			printf("%3d",g.a[i][j]);
		}
		printf("\n");
	}
}

void iNit(Queue &q) {
	q.size = 0;
}

int Put_Back_Queue(Queue &q, int Value) {
	if(q.size + 1 >= MAX) {
		return 0;
	}
	q.b[q.size] = Value;
	q.size++;
return 1;
}

int Pop_Value_Queue(Queue &q, int &Value) {
	if(q.size <= 0) 
		return 0;
	Value = q.b[0];
	for(int i = 0 ; i < q.size - 1 ; i++) {
		q.b[i] = q.b[i+1];
	}
	q.size--;
return 1;	
}

int CheckQueueEmpty(Queue q) {
	if(q.size <= 0)
		return 1;
return 0;
}

void BFS(int v, Graph g) {
	Queue q;
	iNit(q);
	Put_Back_Queue(q,v);
	while(!CheckQueueEmpty(q)) {
		Pop_Value_Queue(q,v);
		Visited[v] = 1;
		for(int u = 0 ; u < g.n ; u++) {
			if(g.a[v][u] != 0 && Visited[u] == 0) {
				Put_Back_Queue(q,u);
				if(Path[u] == -1) {
					Path[u] = v;
				}
			}
		}
	}	
}

void BFS_Main(int S, int F, Graph g) {
	for(int i = 0 ; i < g.n ; i++) {
		Path[i] = -1;
		Visited[i] = 0;
	}
	BFS(S,g);
	if(Visited[F] == 1) {
		printf("Path from %c to %c using BFS Alogithm:", S+'A', F+'A');
		int i = F;
		printf("%3c",F+'A');
		while(S != i) {
			printf(" <-%2c",Path[i]+'A');
			i = Path[i];
		}
	}
	else {
		printf("No path from %c to %c!", S+'A',F+'A');
	}
}

int main() {
	Graph g;
	if(ReadFile(LinkInput,g) == 1) {
		printf("Receive Matrix From File is Success!\n");
		OutPutMaxtrix(g);
		BFS_Main(0,10,g);
	}
	return 0;
}
