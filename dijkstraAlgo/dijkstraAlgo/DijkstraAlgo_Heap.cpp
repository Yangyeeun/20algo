//힙이용-> 최대값, 최솟값이 루트에 존재 =>O(NlogN) 
//getMinIndex()함수 필요없이 N->logN으로 단축가능
#include <iostream>
#include <vector>
#include <queue> //우선순위 큐->힙이용
using namespace std;
int num = 6;
int INF = 1000000000;

vector<pair<int, int>> a[7]; //간선마다 자신과 연결되어있는 노드들을 pair형태로 저장
int d[7]; //최소비용(간선비용)

void dijkstra(int start) {
	d[start] = 0; //자신으로 가는 비용=0
	priority_queue<pair<int, int>>pq;// 힙구조
	//가까운 순서대로 처리하므로 큐를 사용
	while (!pq.empty()) {
		int cur = pq.top().first; //최소비용 노드 
		//maxHeap을 minHeap으로 만들어줌
		int dis = -pq.top().second;
		pq.pop();
		//최단거리가 아닌경우 스킵
		if (d[cur] < dis) continue;
		for (int i = 0; i < a[cur].size(); i++) {
			//선택된 노드의 인접노드
			int next = a[cur][i].first;
			int nextDis = dis + a[cur][i].second;
			//기존 최소비용보다 더 작으면 갱신
			if (nextDis < d[next]) {
				d[next] = nextDis;
				pq.push(make_pair(next, -nextDis));
			}
		}
	}
}

int main() {
	for (int i = 1; i <= num; i++) {
		d[i] = INF;
	}

	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	dijkstra(1);

	for (int i = 1; i <= num; i++) {
		printf("%d", d[i]);
	}

}