/* Bui Phu Khuyen
16DTCH4 - 1611061839 */
///---Week 1: INPUT/OUTPUT MATRIX FROM FILE - CHECK MATRIX---///

#include<stdio.h>
#define MAX 50
#define LinkInput "C:/File Test/Test.txt"

typedef struct GRAPH {
	int n;
	int a[MAX][MAX];
}Graph;

typedef struct STACK {
	int size;
	int b[MAX];
}Stack;

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

int CheckMatrix(Graph g) {
	for(int i = 0 ; i < g.n ; i++) {
		if(g.a[i][i] != 0)
			return 0;
	}
	return 1;
}

int CheckScalarGraph(Graph g) {
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = 0 ; j < g.n ; j++) {
			if(g.a[i][j] != g.a[j][i])
				return 0;
		}
	}
return 1;
}

int main() {
	Graph g;
	if(ReadFile(LinkInput,g) == 1) {
		printf("Receive from File is Success!\n");
		OutPutMatrix(g);
		if(CheckMatrix(g) == 1) 
			printf("Graph is Valid!\n");
	else
		printf("Graph is inValid\n");	
	if(CheckScalarGraph(g) == 1) 
		printf("Scalar Graph.\n");
	else
		printf("Direction Graph.\n");	
	}	
return 0;
}

