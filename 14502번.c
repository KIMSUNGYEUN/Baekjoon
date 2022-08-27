#if 1

#include<stdio.h>

#define SZ 9
#define QUE_SZ 65

int N, M;
int map[SZ][SZ];
int map_for_bfs[SZ][SZ];
int map_for_wall[SZ][SZ];

int max_ans = 0;

int vectX[4] = { 0, 0, 1, -1 };
int vectY[4] = { 1, -1, 0, 0 };

struct node {
	int x;
	int y;
};
struct node queue[QUE_SZ];
int tail = 0;
int head = 0;

int isQueEmpty() {
	return (tail == head) ? 1 : 0;
}

void enque(int a, int b) {
	struct node temp;
	temp.x = a; temp.y = b;
	queue[tail] = temp;
	tail = (tail + 1) % QUE_SZ;
}

struct node deque() {
	struct node temp = queue[head];
	head = (head + 1) % QUE_SZ;
	return temp;
}


void do_bfs() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map_for_bfs[i][j] = map_for_wall[i][j];
			if (map_for_bfs[i][j] == 2) {
				enque(i, j);
			}
		}
	}

	while (isQueEmpty() == 0) {
		struct node temp = deque();
		int nextX; int nextY;
		for (int i = 0; i < 4; i++) {
			nextX = temp.x + vectX[i];
			nextY = temp.y + vectY[i];
			if (nextX >= 0 && nextY >= 0 && nextX < N && nextY < M) {
				if (map_for_bfs[nextX][nextY] == 0) {
					map_for_bfs[nextX][nextY] = 2;
					enque(nextX, nextY);
				}
			}
		}
	}


	// 바이러스가 다 퍼지고 0의 개수 카운팅 
	int temp_ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map_for_bfs[i][j] == 0) {
				temp_ans++;
			}
		}
	}

	if (temp_ans > max_ans) {
		max_ans = temp_ans;
	}

}

void build_wall(int wall_cnt) {
	if (wall_cnt == 3) {
		do_bfs();
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map_for_wall[i][j] == 0) {
					map_for_wall[i][j] = 1;
					build_wall(wall_cnt + 1);
					map_for_wall[i][j] = 0;
				}
			}
		}
	}

}

void solution() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				for (int a = 0; a < N; a++) {
					for (int b = 0; b < M; b++) {
						map_for_wall[a][b] = map[a][b];
					}
				}
				map_for_wall[i][j] = 1;
				build_wall(1);
				map_for_wall[i][j] = 0;
			}
		}
	}

}


int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}


	solution();

	printf("%d", max_ans);
}

#endif
