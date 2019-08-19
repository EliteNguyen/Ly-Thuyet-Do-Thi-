/* Bui Phu Khuyen
16DTCH4 - 1611061839 */
///---Week 2: EULER---///

#include<stdio.h>
#define MAX 20
#define LinkFile "C:/File Test/Test_2A.txt"
#define LinkFile2 "C:/File Test/Test_2B.txt"

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

void iNit(Stack &s) {
	s.size = 0;
}

void Put_Back_Stack(Stack &s, int Value) {
	if(s.size + 1 >= MAX) {
		return;
	}	
	s.b[s.size] = Value;
	s.size++;
}

int Start_Point(Graph g) {
	int Rank;
	for(int i = 0 ; i < g.n ; i++) {
		Rank = 0;
		for(int j = 0 ; j < g.n ; j++) {
			if(g.a[i][j] != 0) {
				Rank++;
			}
		}
		if(Rank%2 != 0) {
			return -1;
		}
	}
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = 0 ; j < g.n ; j++) {
			if(g.a[i][j] != 0) {
				return i;
			}
		}
	}
return -1;	
}

int Start_EvenPoint(Graph g) {
	int Rank, Count = 0;
	for(int i = 0 ; i < g.n ; i++) {
		Rank = 0;
		for(int j = 0 ; j < g.n ;j++) {
			if(g.a[i][j] != 0) {
				Rank++;
			}	
		}
		if(Rank%2 != 0) {
			Count++;
		}
		if(Count == 2) {
			return i; 
		} 
	}
return -1;
}

void FindWay(int i, Graph &g, Stack &s) {
	for(int j = 0 ; j < g.n ; j ++) {
		if(g.a[i][j] != 0) {
			g.a[i][j] = g.a[j][i] = 0;
			FindWay(j,g,s);
		}
	}
	Put_Back_Stack(s,i);
}

int CheckEuler(Graph g) {
	Graph Temp = g;
	Stack s;
	iNit(s);
	int x = Start_Point(Temp);
	if(x == -1)
		return 0;
	FindWay(0, Temp, s);
	
	for(int i = 0 ; i < Temp.n ; i++) {
		for(int j = 0 ; j < Temp.n ; j++) {
			if(Temp.a[i][j] != 0) {
				return 0;
			}
		}
	}
	
	if(s.b[0] != s.b[s.size-1]) {
		return 0;
	}
	
	printf("Euler is:\n");
	printf(" %2c ",s.b[s.size - 1] + 'A');	
	for(int i = s.size - 2 ; i >= 0 ; i--) {
		printf("->%2c ",s.b[i] + 'A');
	}
return 1;
}

int CheckEulerWay(Graph g) {
	Graph Temp = g;
	Stack s;
	iNit(s);
	int x = Start_EvenPoint(Temp);
	if(x == -1) 
		return 0;
	FindWay(0,Temp,s);
	
	for(int i = 0 ; i < Temp.n ; i++) {
		for(int j = 0 ; j < Temp.n ; j++) {
			if(Temp.a[i][j] != 0) {
				return 0;
			}
		}
	}
	
	if(s.b[0] == s.b[s.size-1]) {
		return 0;
	}
	printf("Euler Way is:\n");
	printf("%3c ",s.b[s.size - 1]+'A');
	for(int i = s.size - 2 ; i >= 0 ; i--) {
		printf(" ->%3c",s.b[i]+'A');
	}
return 1;
}

int main() {
	Graph g;
	if(ReadFile(LinkFile2,g) == 1) {
		printf("Receive from File is Success!\n");
		OutPutMatrix(g);
		if(CheckEuler(g) != 1) {
			printf("Not Euler!\n");
			if(CheckEulerWay(g)!=1) {
				printf("Not Euler Way");
			}
		}
	}	
	return 0;
}
