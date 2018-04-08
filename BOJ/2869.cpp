#include <cstdio>

int A, B, V;
int answer;

void solve() {
	int C = V - A;
	int D = A - B;
	int q = C / D;
	int r = C % D;

	if (!r) answer = q + 1;
	else answer = q + 2;
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d%d%d", &A, &B, &V);
	*/
	scanf("%d%d%d", &A, &B, &V);
	solve();
	printf("%d", answer);
}