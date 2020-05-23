#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
//부모노드 찾는 함수
int getParent(int parent[], int x) {
	if (parent[x] == x)//탈출조건
		return x;
	return parent[x] = getParent(parent, parent[x]);
}

//부모노드 합치는 함수
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);//부모를 받아와
	b = getParent(parent, b);

	if (a < b) parent[b] = a; // 더작은 쪽을 부모로 합침
	else parent[a] = b;
}

//같은 부모를 가지는지 확인= 같은 그래프에 속하는지
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);//부모를 받아와
	b = getParent(parent, b);

	if (a == b) return 1; // 더작은 쪽을 부모로 합침
	else return 0;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge &edge) { //비용이 적은지 확인
		return this->distance < edge.distance;
	}
};

int main() {
	/*int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));*/

	//////////////////kruskal Algo


	const int n = 7;
	int m = 11;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	// 간선의 비용으로 오름차순 정렬 
	sort(v.begin(), v.end());

	// 각 정점이 포함된 그래프가 어디인지 저장 
	int parent[n];
	for (int i = 0; i < 7; i++) {
		parent[i] = i;
	}

	// 거리의 합을 0으로 초기화 
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		// 동일한 부모를 가르키지 않는 경우, 즉 사이클이 발생하지 않을 때만 선택 
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	printf("%d\n", sum);
}
