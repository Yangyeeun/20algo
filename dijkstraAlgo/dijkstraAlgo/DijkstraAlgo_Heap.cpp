//���̿�-> �ִ밪, �ּڰ��� ��Ʈ�� ���� =>O(NlogN) 
//getMinIndex()�Լ� �ʿ���� N->logN���� ���డ��
#include <iostream>
#include <vector>
#include <queue> //�켱���� ť->���̿�
using namespace std;
int num = 6;
int INF = 1000000000;

vector<pair<int, int>> a[7]; //�������� �ڽŰ� ����Ǿ��ִ� ������ pair���·� ����
int d[7]; //�ּҺ��(�������)

void dijkstra(int start) {
	d[start] = 0; //�ڽ����� ���� ���=0
	priority_queue<pair<int, int>>pq;// ������
	//����� ������� ó���ϹǷ� ť�� ���
	while (!pq.empty()) {
		int cur = pq.top().first; //�ּҺ�� ��� 
		//maxHeap�� minHeap���� �������
		int dis = -pq.top().second;
		pq.pop();
		//�ִܰŸ��� �ƴѰ�� ��ŵ
		if (d[cur] < dis) continue;
		for (int i = 0; i < a[cur].size(); i++) {
			//���õ� ����� �������
			int next = a[cur][i].first;
			int nextDis = dis + a[cur][i].second;
			//���� �ּҺ�뺸�� �� ������ ����
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