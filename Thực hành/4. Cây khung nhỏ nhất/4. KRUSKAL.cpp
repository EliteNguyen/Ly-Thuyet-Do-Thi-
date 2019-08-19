/* Bui Phu Khuyen
16DTCH4 - 1611061839 */
///---Week 4: MINIMUM SPANNING TREE (MST) - KRUSKAL---///

#include<stdio.h>
#define MAX 50
#define LinkInput "C:/File Test/Test_4.txt"

typedef struct GRAPH {
	int n;
	int a[MAX][MAX];
}Graph;

typedef struct EDGE {
	int u;
	int v;
	int value;
}Edge;

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

void Swap(Edge E[MAX], int SumEdge) {
	Edge Temp;
	for(int i = 0 ; i < SumEdge - 1 ; i++) {
		for(int j = i + 1 ; j < SumEdge ; j++) {
			if(E[i].value > E[j].value) {
				Temp = E[i];
				E[i] = E[j];
				E[j] = Temp;
			}
		}	
	}
}

void Kruskal(Graph g) {
	Edge EList[MAX];
	int SumEdge = 0;
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = i + 1 ; j < g.n ; j++) {
			if(g.a[i][j] > 0) {
				EList[SumEdge].u = i;
				EList[SumEdge].v = j;
				EList[SumEdge].value = g.a[i][j];
				SumEdge++;
			}
		}
	}
	Swap(EList,SumEdge);
	int nT = 0;
	Edge E[MAX];
	int Label[MAX];
	for(int i = 0 ; i < g.n ; i++) {
		Label[i] = i;
	}
	int Edge = 0;
	while(nT < g.n && Edge < SumEdge) {
		if(Label[EList[Edge].u] != Label[EList[Edge].v]) {
			E[nT] = EList[Edge];
			nT++;
			int Value = Label[EList[Edge].v];
			for(int j = 0 ; j < g.n ; j++) {
				if(Label[j] == Value) 
					Label[j] = Label[EList[Edge].u];
			}
		}
		Edge++;	
	}
	if(nT != g.n - 1) {
		printf("\nGraph is not Theory!\n");	
	}
	else {
		int SumMST = 0;
		printf("MST using Kruskal Algorithm: \n");
		for(int i = 0 ; i < nT ; i++) {
			printf("(%c,%c)\t",E[i].u +'A',E[i].v+'A');
			SumMST += E[i].value;
		}
		printf("\nWeight of MST: %d",SumMST);
	}
}
int main() {
	Graph g;
	if(ReadFile(LinkInput,g) == 1) {
		printf("Receive from File is Success!\n");
		OutPutMatrix(g);
		Kruskal(g);
	}	
	return 0;
}

