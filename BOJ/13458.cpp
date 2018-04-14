#include <cstdio>

int N;
long long needed = 0;
int takers[1000000];
bool covered[1000000];
int B; int C;

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &N);
	for(int i=0; i<N; i++)
		fscanf(fp, "%d", &takers[i]);
	fscanf(fp, "%d %d", &B, &C);
	//deploy main
	for (int i = 0; i < N; i++){
		takers[i] -= B;
		needed++;
		if (takers[i] <= 0)
			covered[i] = true;
	}
	//sub needed
	for(int i=0; i<N; i++)
		if (!covered[i])
			if (!(takers[i] % C))
				needed += (takers[i] / C);
			else
				needed += (takers[i] / C + 1);
	printf("%d\n", needed);
	*/
	scanf("%d", &N);
	for (int i = 0; i<N; i++)
		scanf("%d", &takers[i]);
	scanf("%d %d", &B, &C);
	//deploy main
	for (int i = 0; i < N; i++) {
		takers[i] -= B;
		needed++;
		if (takers[i] <= 0)
			covered[i] = true;
	}
	//sub needed
	for (int i = 0; i<N; i++)
		if (!covered[i])
			if (!(takers[i] % C))
				needed += (takers[i] / C);
			else
				needed += (takers[i] / C + 1);
	printf("%lld\n", needed);
}