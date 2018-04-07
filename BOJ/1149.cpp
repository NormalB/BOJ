#include <cstdio>

int N;
int arr[1000][3];
int dp[1000][3];
int answer;

int solve(void) {
	for (int i = 1; i <= N; i++) {
		dp[i][0] = (dp[i - 1][1] > dp[i - 1][2] ? dp[i - 1][2] : dp[i - 1][1]) + arr[i][0];
		dp[i][1] = (dp[i - 1][0] > dp[i - 1][2] ? dp[i - 1][2] : dp[i - 1][0]) + arr[i][1];
		dp[i][2] = (dp[i - 1][0] > dp[i - 1][1] ? dp[i - 1][1] : dp[i - 1][0]) + arr[i][2];
	}
	answer = dp[N][0];
	for (int i = 1; i < 3; i++) {
		if (answer > dp[N][i])
			answer = dp[N][i];
	}
	return answer;
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &N);
	for (int i = 0; i < N; i++)
		fscanf(fp, "%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	printf("%d", solve());
	*/
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	printf("%d", solve());
}