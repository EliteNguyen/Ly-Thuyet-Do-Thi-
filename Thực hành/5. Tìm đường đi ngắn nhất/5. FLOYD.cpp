/* Bui Phu Khuyen
16DTCH4 - 1611061839 */
///---Week 5: FIND SHORTEST PATH - FLOYD---///

#include<stdio.h>
#define MAX 50
#define INF 1e9
#define LinkInput "C:/File Test/Test_5.txt"

int After_Node[MAX][MAX];
int L[MAX][MAX];

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

void Floyd(int S, int F, Graph g) {
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = 0 ; j < g.n ; j++) {
			if(g.a[i][j] > 0) {
				After_Node[i][j] = j;
				L[i][j] = g.a[i][j];
			}
			else {
				After_Node[i][j] = -1;
				L[i][j] = INF;
			}
			
		}
	}
	
	for(int k = 0 ; k < g.n ; k++) {
		for(int i = 0 ; i < g.n ; i++) {
			for(int j = 0 ; j < g.n ; j++) {
				if(L[i][j] > L[i][k] + L[k][j]) {
					L[i][j] = L[i][k] + L[k][j];
					After_Node[i][j] = After_Node[i][k];	
				}
			}
		}
	}
	
	if(After_Node[S][F] == -1) {
		printf("Not path from %c to %c!",S+'A',F+'A');
	}
	else {
		printf("Shortest Path from %c to %c using Floyd Algorithm: ", S+'A',F+'A');
		printf("%c",S+'A');
		int u = S;
		while(After_Node[u][F] != F) {
			u = After_Node[u][F];
			printf(" -> %c",u+'A');
		}
		printf(" -> %c",F+'A');
		printf("\nWeight of Path: %d",L[S][F]); 
	}
}

int main() {
	Graph g;
	if(ReadFile(LinkInput,g) == 1) {
		printf("Receive from File is Success!\n");
		OutPutMatrix(g);
		Floyd(0,10,g);
	}		
	return 0;
}

