#include <cstdio>

int T; int W;
int arr[1001];
int dp[30][1001];

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d%d", &T, &W);
	for (int i = 1; i <= T; i++)
		fscanf(fp, "%d", &arr[i]);
	//init dp
	for (int i = 1; i <= T; i++)
		if (arr[i] == 1)
			dp[0][i] = dp[0][i - 1] + 1;
		else
			dp[0][i] = dp[0][i - 1];
	//fill dp
	for(int i=1; i<=W; i++){
		int idx = i % 2 + 1;
		for (int j = 1; j <= T; j++) {
			if (arr[j] == idx)
				dp[i][j] = (dp[i][j - 1] + 1 >= dp[i - 1][j] ? dp[i][j - 1] + 1 : dp[i - 1][j]);
			else
				dp[i][j] = (dp[i][j - 1] >= dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j]);
		}
	}
	printf("%d\n", dp[W][T]);
	*/
	scanf("%d%d", &T, &W);
	for (int i = 1; i <= T; i++)
		scanf("%d", &arr[i]);
	//init dp
	for (int i = 1; i <= T; i++)
		if (arr[i] == 1)
			dp[0][i] = dp[0][i - 1] + 1;
		else
			dp[0][i] = dp[0][i - 1];
	//fill dp
	for (int i = 1; i <= W; i++) {
		int idx = i % 2 + 1;
		for (int j = 1; j <= T; j++) {
			if (arr[j] == idx)
				dp[i][j] = (dp[i][j - 1] + 1 >= dp[i - 1][j] ? dp[i][j - 1] + 1 : dp[i - 1][j]);
			else
				dp[i][j] = (dp[i][j - 1] >= dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j]);
		}
	}
	printf("%d\n", dp[W][T]);
}