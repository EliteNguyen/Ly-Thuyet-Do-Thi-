/* Bui Phu Khuyen
16DTCH4 - 1611061839 */
///---Week 4: MINIMUM SPANNING TREE (MST) - PRIM---///

#include<stdio.h>
#define MAX 50
#define LinkInput "C:/File Test/Test_4.txt"

int Visited[MAX];

typedef struct GRAPH {
	int n;
	int a[MAX][MAX];
}Graph;

typedef struct EDGE {
	int u;
	int v;
	int value;
}Edge;

Edge E[MAX];

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

int FindTheory(int i, int Label[MAX], Graph g) {
	for(int j = 0 ; j < g.n ; j++) {
		if(g.a[i][j] != 0 && Label[j] == 0) {
			Label[j] = Label[i];
			FindTheory(j,Label,g);
		}
	}
	return 1;
}

int GraphTheory(Graph g) {
	int Label[MAX];
	int CountTheory = 0;
	for(int i = 0 ;i < g.n ; i++) {
		Label[i] = 0;
	}
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = 0 ; j < g.n ; j++) {
			if(Label[i] == 0) {
				CountTheory++;
				Label[i] = CountTheory;
				FindTheory(i,Label,g);
			}
		}
	}
	return CountTheory;
}

void Prim(Graph g) {
	if(GraphTheory(g) != 1)
	{
		printf("Graph is not Theory!");
		return;
	}
	int nT;
	for(int i = 0 ; i < g.n ; i++) {
		Visited[i] = 0;
	}
	Visited[0] = 1;
	while(nT < g.n - 1) {
		Edge eMin;
		int minValue = MAX;
		for(int i = 0 ; i < g.n ; i++) {
			if(Visited[i] == 1) {
				for(int j = 0 ; j < g.n ; j++) {
					if(Visited[j] == 0 && g.a[i][j] != 0 && minValue > g.a[i][j]) {
						eMin.u = i;
						eMin.v = j;
						eMin.value = g.a[i][j];
						minValue = g.a[i][j];
					}
				}
			}
		}
		E[nT] = eMin;
		nT++;
		Visited[eMin.v] = 1;
	}
	
	int SumMST = 0;
	printf("MST using Prim Algorithm:\n");
	for(int i = 0 ; i <= nT - 1 ; i++) {
		printf("(%c,%c)\t",E[i].u +'A',E[i].v+'A');
		SumMST += E[i].value;
	}
	printf("\nWeight of MST: %d",SumMST);
		
}
int main() {
	Graph g;
	if(ReadFile(LinkInput,g) == 1) {
		printf("Receive from File is Success!\n");
		OutPutMatrix(g);
		Prim(g);
	}
	return 0;
}
