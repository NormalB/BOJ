#include <cstdio>
#include <cstring>

class Node {
public:
	int n;
	int c;
	Node(int node_num, int node_cost) {
		n = node_num;
		c = node_cost;
	}
};

class minHeap {
public:
	int length;
	Node* heaparr[16000];
	void init() {
		for (int i = 0; i < 16000; i++)
			heaparr[i] = NULL;
		length = 0;
	}
	void insert(Node *np) {
		heaparr[++length] = np;
		int i = length;
		while (i > 1 && heaparr[i / 2]->c > heaparr[i]->c) {
			Node *temp = heaparr[i];
			heaparr[i] = heaparr[i/2];
			heaparr[i / 2] = temp;
			i /= 2;
		}
	}
	Node* extract_min(void) {
		if (!length) return NULL;
		Node *to_return = heaparr[1];
		heaparr[1] = heaparr[length--];
		int i = 1;
		while (2 * i <= length) {
			int child;
			if (2 * i == length)
				child = 2 * i;
			else
				child = heaparr[2 * i]->c < heaparr[2 * i + 1]->c ? 2 * i : 2 * i + 1;
			if (heaparr[i]->c < heaparr[child]->c) break;
			Node *temp = heaparr[i];
			heaparr[i] = heaparr[child];
			heaparr[child] = temp;
			i = child;
		}
		return to_return;
	}
};

int N = 1;
int board[125][125];
int dist[125][125];
bool visited[125][125];
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	int cnt = 1;
	while (true) {
		fscanf(fp, "%d", &N);
		if (!N) break;
		//init variables
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dist[i][j] = 1000000000;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				fscanf(fp, "%d", &board[i][j]);
		minHeap mh;
		mh.init();
		//insert start point
		mh.insert(new Node(0, board[0][0]));
		dist[0][0] = board[0][0];
		while (!visited[N-1][N-1]) {
			Node *node = mh.extract_min();
			int i = node->n / N;
			int j = node->n % N;
			//if visited, continue
			if (visited[i][j]) {
				delete node;
				continue;
			}
			//check visited
			visited[i][j] = true;
			dist[i][j] = node->c;
			//add adjacent node
			for (int k = 0; k < 4; k++) {
				if (i + dy[k] >= 0 && i + dy[k] < N && j + dx[k] >= 0 && j + dx[k] < N)
					mh.insert(new Node((i + dy[k])*N + j + dx[k], dist[i][j] + board[i + dy[k]][j + dx[k]]));
			}
			//delete current node
			delete node;
		}
		printf("Problem %d: %d\n", cnt, dist[N - 1][N - 1]);
		cnt++;
	}
	*/

	int cnt = 1;
	while (true) {
		scanf("%d", &N);
		if (!N) break;
		//init variables
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dist[i][j] = 1000000000;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &board[i][j]);
		minHeap mh;
		mh.init();
		//insert start point
		mh.insert(new Node(0, board[0][0]));
		dist[0][0] = board[0][0];
		while (!visited[N - 1][N - 1]) {
			Node *node = mh.extract_min();
			int i = node->n / N;
			int j = node->n % N;
			//if visited, continue
			if (visited[i][j]) {
				delete node;
				continue;
			}
			//check visited
			visited[i][j] = true;
			dist[i][j] = node->c;
			//add adjacent node
			for (int k = 0; k < 4; k++) {
				if (i + dy[k] >= 0 && i + dy[k] < N && j + dx[k] >= 0 && j + dx[k] < N)
					mh.insert(new Node((i + dy[k])*N + j + dx[k], dist[i][j] + board[i + dy[k]][j + dx[k]]));
			}
			//delete current node
			delete node;
		}
		printf("Problem %d: %d\n", cnt, dist[N - 1][N - 1]);
		cnt++;
	}
	
}