#include <cstdio>
#include <cstring>

int N;
bool merged[20][20];
int **map;
int global_max = 0;

int** mapcopy(int **oldp) {
	int **newmap = new int*[N];
	for (int i = 0; i < N; i++)
		newmap[i] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			newmap[i][j] = oldp[i][j];
	return newmap;
}

void solve(int iter, int **mapp) {
	if (iter == 5) {
		int max = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (max < mapp[i][j])
					max = mapp[i][j];
		if (global_max < max)
			global_max = max;
		return;
	}
	//four direction
	//move right
	// init merged
	memset(merged, 0, sizeof(merged));
	int ** nm1 = mapcopy(mapp);
	//for every row
	for (int i = 0; i < N; i++) {
		//from rightest to leftest
		for(int j=N-1; j>=0; j--)
			if (nm1[i][j]) {
				//erase old pos
				int temp = nm1[i][j];
				nm1[i][j] = 0;
				int k = j;
				//get new pos
				while (k + 1 < N) {
					//collision
					if (nm1[i][k+1])
						//if values are same and not merged
						if (temp == nm1[i][k+1] && !merged[i][k+1]) {
							temp *= 2;
							merged[i][k+1] = true;
							k++;
							break;
						}
						else{
							//can not merge two block
							break;
						}
					k++;
				}
				//mark new pos
				nm1[i][k] = temp;
			}
	}
	solve(iter + 1, nm1);

	//move left
	// init merged
	memset(merged, 0, sizeof(merged));
	int ** nm2 = mapcopy(mapp);
	//for every row
	for (int i = 0; i < N; i++) {
		//from leftest to rightest
		for (int j = 0; j < N; j++)
			if (nm2[i][j]) {
				//erase old pos
				int temp = nm2[i][j];
				nm2[i][j] = 0;
				int k = j;
				//get new pos
				while (k - 1 >= 0) {
					//collision
					if (nm2[i][k-1])
						//if values are same and not merged
						if (temp == nm2[i][k-1] && !merged[i][k-1]) {
							temp *= 2;
							merged[i][k-1] = true;
							k--;
							break;
						}
						else {
							//can not merge two block
							break;
						}
						k--;
				}
				//mark new pos
				nm2[i][k] = temp;
			}
	}
	solve(iter + 1, nm2);

	//move up
	// init merged
	memset(merged, 0, sizeof(merged));
	int ** nm3 = mapcopy(mapp);
	//for every col
	for (int j = 0; j < N; j++) {
		//from up to down
		for (int i = 0; i < N; i++)
			if (nm3[i][j]) {
				//erase old pos
				int temp = nm3[i][j];
				nm3[i][j] = 0;
				int k = i;
				//get new pos
				while (k - 1 >= 0) {
					//collision
					if (nm3[k-1][j])
						//if values are same and not merged
						if (temp == nm3[k-1][j] && !merged[k-1][j]) {
							temp *= 2;
							merged[k-1][j] = true;
							k--;
							break;
						}
						else {
							//can not merge two block
							break;
						}
						k--;
				}
				//mark new pos
				nm3[k][j] = temp;
			}
	}
	solve(iter + 1, nm3);

	//move down
	// init merged
	memset(merged, 0, sizeof(merged));
	int ** nm4 = mapcopy(mapp);
	//for every col
	for (int j = 0; j < N; j++) {
		//from down to up
		for (int i = N-1; i >= 0; i--)
			if (nm4[i][j]) {
				//erase old pos
				int temp = nm4[i][j];
				nm4[i][j] = 0;
				int k = i;
				//get new pos
				while (k + 1 < N) {
					//collision
					if (nm4[k+1][j])
						//if values are same and not merged
						if (temp == nm4[k+1][j] && !merged[k+1][j]) {
							temp *= 2;
							merged[k+1][j] = true;
							k++;
							break;
						}
						else {
							//can not merge two block
							break;
						}
						k++;
				}
				//mark new pos
				nm4[k][j] = temp;
			}
	}
	solve(iter + 1, nm4);
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &N);
	//init map
	map = new int*[N];
	for (int i = 0; i < N; i++)
		map[i] = new int[N];
	//fill values
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			fscanf(fp, "%d", &map[i][j]);
	int** newmap = mapcopy(map);
	solve(0, newmap);
	printf("%d\n", global_max);
	*/
	scanf("%d", &N);
	//init map
	map = new int*[N];
	for (int i = 0; i < N; i++)
		map[i] = new int[N];
	//fill values
	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			scanf("%d", &map[i][j]);
	int** newmap = mapcopy(map);
	solve(0, newmap);
	printf("%d\n", global_max);
}