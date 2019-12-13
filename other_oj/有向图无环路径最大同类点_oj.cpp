#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node(int da) { data = da; next = NULL; }
};

enum color{WHITE, GRAY, BLACK};
color *vertex_color;

string coin;
Node** table;             
int **v_coin;
int* indegree;           
int *sta_time;
int *end_time;
int times = 1;
int maxs = 0;

bool circle = 0;
void dfs_circle(int index){
	vertex_color[index] = GRAY;
	Node *temp = table[index];
	while(temp->next != NULL){
		if(vertex_color[temp->next->data] == WHITE){
			dfs_circle(temp->next->data); 
            if(circle == 1) return;
		}else if(vertex_color[temp->next->data] == GRAY){
            circle = 1; return;
        }
		temp = temp->next;
	}
	vertex_color[index] = BLACK;
    end_time[index] = times++;
}

void init(int N){
    v_coin = new int*[N + 3];
	indegree = new int[N + 3];
	end_time = new int[N + 3];
	sta_time = new int[N + 3];
	indegree = new int[N + 3];
	table = new Node *[N + 3];
	vertex_color = new color[N + 3];
	for (int i = 0; i <= N; i++) {
        v_coin[i] = new int[256];
        for(int j = 'a';j <= 'z';j++) v_coin[i][j] = 0;
        end_time[i] = 0;
        sta_time[i] = i;
		table[i] = new Node(i);
		indegree[i] = 0;
        vertex_color[i] = WHITE;
	}
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
		indegree[b]++;               //b的入度++
		Node* newnode = new Node(b);
		newnode->next = table[a]->next;
		table[a]->next = newnode;   //a的出边表添加b结点
	}
}

bool cmp(int a, int b){
	return end_time[a] > end_time[b];
}

void max_coin(int *a, int *b){
    for(int i = 'a';i <= 'z';i++){
        if(b[i] > a[i]) a[i] = b[i];
    }
}

int main() {
	int N, M;
	cin >> N >> M >> coin; 
    coin = "0" + coin; //点的序号从1开始

	init(N);

    // dfs, topological sorting
	for(int i = N;i >= 1;i--){
        if(vertex_color[i] == WHITE){
            dfs_circle(i);
            if(circle) { cout << -1 << endl; return 0; }
        }
	}

    // sort
    for(int i = N;i > 0;i--){
        for(int j = 1;j < i;j++){
            if(!cmp(sta_time[j], sta_time[j+1])){
                int t = sta_time[j];
                sta_time[j] = sta_time[j+1];
                sta_time[j+1] = t;
            }
        }
    }

    // my algorithm
    for(int i = N;i > 0;i--){
        int ind = sta_time[i];
        Node *temp = table[ind];
        while(temp->next != NULL){
            max_coin(v_coin[ind], v_coin[temp->next->data]);
            temp = temp->next;
        }
        v_coin[ind][coin[ind]]++;
    }

    // find max
	for(int i = N;i > 0;i--){
        for(int j = 'a';j <= 'z';j++){
            if(maxs < v_coin[i][j]) maxs = v_coin[i][j];
        }
	}

	cout << maxs << endl;
	return 0;
}