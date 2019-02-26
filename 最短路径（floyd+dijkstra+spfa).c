

void floyd(int **fl) {
	int i, j, k;
	for (k = 0; k<N; k++) {
		for (i = 0; i<N; i++) {
			for (j = 0; j<N; j++) {
				if (fl[i][j]>fl[i][k] + fl[k][j]) {
					fl[i][j] = fl[i][k] + fl[k][j];
				}
			}
		}
	}
}

void SPFA(int *dis, int **fl, int *path) {
	int *queue = (int*)malloc(sizeof(int)*N),*vis=(int*)malloc(sizeof(int)*N);
	int front = 0, rear = 0, i, size=N;
	for (i = 0; i < N; i++) {
		vis[i] = 0;
	}
	queue[rear++] = 0;
	dis[0] = 0;
	path[0] = -1;
	vis[0] = 1;
	while (front != rear) {
		int tmp = queue[front++], i;
		vis[tmp] = 0;
		for (i = 0; i < N + 1; i++) {
			if (fl[tmp][i] != inf) {
				if (dis[i] < dis[tmp] + fl[tmp][i]) {
					dis[i] = dis[tmp] + fl[tmp][i];
					path[i] = tmp;
					if (!vis[i]) {
						queue[rear++] = i;
						vis[i] = 1;
					}
					if (rear == size) {
						queue = (int*)realloc(queue, sizeof(int)*size * 2);
						size *= 2;
					}
				}
			}
			
		}
	}
}