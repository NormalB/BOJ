#include <cstdio>
#include <cstring>

#define MAX_LEN 50

char* strings[20000];
char* sorted[20000];
int counts[27];
int N;

//return nth character of str from rightest position
//starting idx = 0
int getNthChar(char *string, int n) {
	int len = strlen(string);
	if (n >= len) return 0;
	return string[len-1-n] - 'a' + 1;
}

void radixSort(int max_len, int num_strings) {
	for (int d = 0; d < max_len; d++) {
		//init counts
		memset(counts, 0, sizeof(counts));
		for (int i = 0; i < num_strings; i++) {
			counts[getNthChar(strings[i], d)]++;
		}
		for (int j = 0; j < 26; j++)
			counts[j + 1] += counts[j];
		for(int i= num_strings - 1; i>=0; i--)
			sorted[--counts[getNthChar(strings[i], d)]] = strings[i];
		//copy sorted to strings
		memcpy(strings, sorted, sizeof(sorted));
	}
}

int main(void) {
	/*
	FILE *fd = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fd, "%d", &N);
	for (int i = 0; i < N; i++){
		char *buf = new char[51];
		fscanf(fd, "%s", buf);
		strings[i] = buf;
	}
	radixSort(MAX_LEN, N);
	for (int i = 0; i < N; i++){
		if(i == 0 || strcmp(sorted[i], sorted[i-1]))
			printf("%s\n", sorted[i]);
	}
	*/
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char *buf = new char[51];
		scanf("%s", buf);
		strings[i] = buf;
	}
	radixSort(MAX_LEN, N);
	for (int i = 0; i < N; i++){
		if(i == 0 || strcmp(sorted[i], sorted[i-1]))
			printf("%s\n", sorted[i]);
	}
	
}