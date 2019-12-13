#include <stdio.h> 
#include <string.h>
#include <iostream>
#include<algorithm>
using namespace std;

//结构体定义，储存图的顶点
struct Edge {
	int from; //边的起始顶点
	int to;   //边的终止顶点
	int cost; //边的权值
	Edge() : from(-1), to(-1), cost(-1) { }
};

struct Vet {
	int tag;  //对应的点
	int cost; //点的权值
};

int nodeNum;  //顶点数;
int edgeNum;  //边数;
bool flag = true;

int minCost = 0;
Vet vet[10000 + 100];
Edge edge[110000 + 100];
int unionVet[10000 + 100];//并查集集合

void init(int n) {       //并查集初始化
	for (int i = 0; i <= n; i++) {
		unionVet[i] = i;
	}
	minCost = 0;
}

int unionFind(int index) {
	int t = index;
	while (index != unionVet[index])
		index = unionVet[index];

	int next = 0;//这个可以优化并查集。
	while (t != unionVet[t]) { //使所有中间节点都直接指向根
		next = unionVet[t];
		unionVet[t] = index;
		t = next;
	}
	return index;
}


void sort(int begin, int end) {  //快速排序
	int i = begin, j = end;
	int index = i;
	if (i >= j)
		return;
	while (i < j) {
		while (i < j && edge[index].cost <= edge[j].cost)  //右边起遍历找第一个小于target的
			j--;
		if (i >= j)
			break;
		if (edge[index].cost > edge[j].cost) {
			Edge temp = edge[j];
			edge[j] = edge[index];
			edge[index] = temp;
			index = j;
		}
		while (i < j && edge[i].cost <= edge[index].cost) //左边起找第一个大于target的
			i++;
		if (i >= j)
			break;
		if (edge[i].cost > edge[index].cost) {
			Edge temp = edge[index];
			edge[index] = edge[i];
			edge[i] = temp;
			index = i;
		}
	}
	if (index - 1 > begin)
		sort(begin, index - 1);
	if (index + 1 < end)
		sort(index + 1, end);
}

void save_point(){       //存储数据
	cin >> nodeNum >> edgeNum;
	for (int i = 0; i < edgeNum; i++) {
		cin >> edge[i].from >> edge[i].to >> edge[i].cost;
	}
	sort(0, edgeNum - 1);
	for (int i = 0; i < nodeNum; i++) {
		cin >> vet[i].cost;
		vet[i].tag = i + 1;
	}
}

void kruskal(){
	init(nodeNum);
	int v1 = 0, v2 = 0;
	for (int i = 0; i < edgeNum; i++) {
		v1 = unionFind(edge[i].from); //并查集搜索
		v2 = unionFind(edge[i].to);   //并查集搜索
		if (edge[i].cost <= 0 || v1 != v2) { //如果边权为负或者两点不连通
			minCost += edge[i].cost;
			if (v1 != v2)
				unionVet[v1] = v2;
		}
	}
}

void judges(){           //判断是否为联通图
	for(int i = 1;i < nodeNum;i++){
		if(unionFind(unionVet[i]) != unionFind(unionVet[i + 1])){
			flag = 0; 
			break;
		}
	}
}

int main() {
	int rem;
	save_point(); //存储边点信息    
	kruskal();    //算法执行
	judges();
	rem = minCost;  

	//添加一个虚拟点0，可以看成是河流，点权可以转化为和这一条边的边权
	for (int i = 0; i < nodeNum; i++) {
		if (vet[i].cost > 0) {
			edge[edgeNum].from = 0;
			edge[edgeNum].to = vet[i].tag;
			edge[edgeNum].cost = vet[i].cost;
			edgeNum++;
		}
	} 
	sort(0, edgeNum - 1);
	kruskal();    //算法执行
	if (flag)
		minCost = minCost < rem ? minCost : rem;
	cout << minCost << endl;
	return 0;
}