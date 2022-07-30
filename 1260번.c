#include <stdio.h>
#include <stdlib.h> /* malloc */
#include <string.h> /* memset */

int queue[1001]; 
int N;			 
int M;			 

/* DFS */
void DFS(int start, int** arr, int* visited)
{
	visited[start] = 1;
	printf("%d ", start); /* 방문한점 출력 */
	int idx;
	idx = 1;
	while (idx <= N)
	{
		if (arr[start][idx] == 1 && visited[idx] == 0)
		{
			DFS(idx, arr, visited);
		}
		idx++;
	}
}

/* BFS */
void BFS(int start, int** arr, int* visited)
{
	visited[start] = 1;
	printf("%d ", start);
	int idx;
	int front;
	int rear;
	int pop;
	front = 0;
	rear = 1;
	queue[front] = start;
	while (front < rear)
	{
		pop = queue[front];
		idx = 0;
		while (idx <= N)
		{
			if (arr[pop][idx] == 1 && visited[idx] == 0)
			{
				visited[idx] = 1;
				printf("%d ", idx);
				queue[rear] = idx;
				rear++;
			}
			idx++;
		}
		front++;
	}
}

int main()
{
	int V; /* 시작정점 번호 */
	int idx;
	int n;
	int v;
	scanf("%d %d %d", &N, &M, &V);

	/* 인접행렬 동적할당 & 초기화 - 메모리크기를 정해주고 선언해야하는 배열에 비해 메모리 낭비를 줄일 수 있다.*/
	int **  arr = (int **) malloc(sizeof(int)*(N+1));
	idx = 0;
	while (idx <= N)
	{
		arr[idx] = (int *)malloc(sizeof(int*)*(N+1));
		int idx2 = 1;
		while (idx2 <= N)
		{
			arr[idx][idx2] = 0;
			idx2++;
		}
		idx++;
	}

	int * visited = (int*) malloc(sizeof(int)*(N+1));
	memset(visited, 0, sizeof(int)*(N+1));

	/* 요소 입력 */
	idx = 1;
	while (idx <= M)
	{
		scanf("%d %d", &n, &v);
		arr[n][v] = 1;
		arr[v][n] = 1;
		idx++;
	}

	/* DFS로 탐색 */
	DFS(V, arr, visited);
	/* 초기화 */
	memset(visited, 0, sizeof(int)*(N+1));
	printf("\n");
	/* BFS로 탐색 */
	BFS(V, arr, visited);

	/* 동적할당 해제 */
	/*idx = 0;
	while (idx < N)
	{
		free(arr[idx]);
		idx++;
	}*/
	free(arr);
	free(visited);
}
