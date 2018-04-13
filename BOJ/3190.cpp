#include <cstdio>
#include <cstring>
#include <list>

int N;
int K;
int L;
int count;
int movecount;
int map[102][102];
int copymap[102][102];
//moves[0] = 3, moves[1] = 15 ...
int moves[100];
//right 1, left 0
int chdir[100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

class snake {
public:
	std::list<std::pair<int, int>> l;
	int length;
	int dir;
	snake() {
		dir = 0;
		length = 0;
		l.push_back(std::make_pair(1, 1));
	}
	std::pair<int, int> last_visited_pos() {
		std::pair<int, int> p = l.back();
		return p;
	}
	void change_dir(int i) {
		//move right
		if (i)
			dir = (dir + 1) % 4;
		//move left
		else
			if (dir == 0)
				dir = 3;
			else
				dir -= 1;
	}
	void increase() {
		std::pair<int, int> p = l.back();
		l.push_back(std::make_pair(p.first + dy[dir], p.second + dx[dir]));
		length = l.size();
	}
	void decrease() {
		l.pop_front();
		length = l.size();
	}
	bool is_self_crashed() {
		std::pair<int, int> npos = l.back();
		bool c = false;
		int i = 0;
		for (std::list<std::pair<int, int>>::iterator it = l.begin(); i<l.size()-1 ; it++) {
			if (npos.first == it->first && npos.second == it->second) {
				c = true;
				break;
			}
			i++;
		}
		return c;
	}
	bool is_wall_crashed() {
		std::pair<int, int> npos = l.back();
		bool c = true;
		if (npos.first >= 1 && npos.first <= N && npos.second >= 1 && npos.second <= N)
			c = false;
		return c;
	}
	void printmap(){
		memcpy(copymap, map, sizeof(map));
		for (std::list<std::pair<int, int>>::iterator it = l.begin(); it != l.end(); it++)
			copymap[it->first][it->second] = 8;
		for(int i=0; i<= N+1; i++){
			for (int j = 0; j <= N+1; j++)
				printf("%d", copymap[i][j]);
			printf("\n");
		}
		printf("\n");
	}
};

void solve() {
	snake s = snake();
	//until snake reaches wall or itself move
	while (!s.is_self_crashed() && !s.is_wall_crashed()) {
		//s.printmap();
		//check moves and set new dir
		if (count == moves[movecount]) {
			s.change_dir(chdir[movecount]);
			movecount++;
		}
		//stretches itself and check crash
		s.increase();
		//term condition
		if (s.is_self_crashed()){
			count++;
			break;
		}
		std::pair<int, int> p = s.last_visited_pos();
		//if not apple, erase its tail
		if (map[p.first][p.second] != 1)
			s.decrease();
		//if apple, erase apple
		else
			map[p.first][p.second] = 0;
		//increase the counter
		count++;
	}
	printf("%d\n", count);
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &N);
	fscanf(fp, "%d", &K);
	for (int i = 0; i < K; i++) {
		int apple_x;
		int apple_y;
		fscanf(fp, "%d%d", &apple_x, &apple_y);
		map[apple_x][apple_y] = 1;
	}
	fscanf(fp, "%d", &L);
	for (int i = 0; i < L; i++) {
		char temp;
		fscanf(fp, "%d %c", &moves[i], &temp);
		if (temp == 'D')
			chdir[i] = 1;
		else
			chdir[i] = 0;
	}
	count = 0;
	movecount = 0;
	solve();
	*/
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int apple_x;
		int apple_y;
		scanf("%d%d", &apple_x, &apple_y);
		map[apple_x][apple_y] = 1;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		char temp;
		scanf("%d %c", &moves[i], &temp);
		if (temp == 'D')
			chdir[i] = 1;
		else
			chdir[i] = 0;
	}
	count = 0;
	movecount = 0;
	solve();
}