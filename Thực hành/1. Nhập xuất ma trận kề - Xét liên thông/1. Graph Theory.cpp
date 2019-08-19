/* Bui Phu Khuyen
16DTCH4 - 1611061839 */
///---Week 1: GRAPH THEORY---///

#include<stdio.h>
#define MAX 50
#define LinkFile "C:/File Test/Test_1.txt"

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

void FindTheory(int i, int Label[MAX], Graph g) {
	for(int j = 0 ; j < g.n ; j++) {
		if(g.a[i][j] != 0 && Label[j] != Label[i]) {
			Label[j] = Label[i];
			FindTheory(j,Label,g);
		}
	}
}

void GraphTheory(Graph g) {
	int Label[MAX];
	int CountTheory = 0;
	for(int i = 0; i < g.n ; i++) {
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
	printf("Number of Graph Theory is: %d", CountTheory);
	for(int i = 1 ; i <= CountTheory ; i++) {
		printf("\nGraph Thery %d Include Vertices:",i);
		for(int j = 0 ; j < g.n ; j++) {
			if(Label[j] == i)
				printf("%3c", j + 'A');
		}
	}
}

int main() {
	Graph g;
	if(ReadFile(LinkFile,g) == 1) {
		printf("Receive from File is Success!\n");
		OutPutMatrix(g);
		GraphTheory(g);
	}	
return 0;
}

