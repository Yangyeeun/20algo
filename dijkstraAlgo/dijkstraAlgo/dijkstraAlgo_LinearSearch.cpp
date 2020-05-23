#include <stdio.h>
//선형탐색 => 시간복잡도 O(n^2)
//for (int i = 0; i < numV; i++){ for (int i = 0; i < numV - 2; i++) }
//특히 v가 많은데 비해 E가 얼마 없을 때 비효율 (모든 V를 N^2번 탐색)

int numV = 6;
int INF = 1000000000;

//전체그래프 초기화
int a[6][6] = {
{0,2,5,1,INF,INF},
{2,0,3,2,INF,INF},
{5,3,0,3,1,5},
{1,2,3,0,1,INF},
{INF,INF,1,1,0,2},
{INF,INF,5,INF,2,0},};

bool v[6]; //방문한 노드인지 check
int d[6]; //최단거리 저장

//가장 최소거리를 가지는 정점을 반환 -> 선형탐색O(n)
int getMinIndex() {
	int min = INF;
	int index = 0; //최소거리를 가져오는 index
	for (int i = 0; i < numV; i++) {
		if (!v[i] && d[i] < min) { //방문하지 않은 노드중 최소거리보다 더 작은 거리면
			min = d[i]; //최소거리갱신
			index = i; //그위치 기억
		}
	}
	return index;
}

//다익스트라를 수행하는 함수(시작V에서 다른 모든 정점으로 가는 최소비용 구함)
void dijkstra(int start) {
	for (int i = 0; i < numV; i++) {
		d[i] = a[start][i]; //시작점으로부터 i까지 경로의 비용
	}
	v[start] = true;
	for (int i = 0; i < numV - 2; i++) { //->O(n) => 시간복잡도 O(n^2)
		int cur = getMinIndex(); //최소비용인덱스
		v[cur] = true;
		for (int j = 0; j < 6; j++) {// 최소cur점과 인접한 정점을 확인
			if (!v[j]) { //방문하지않은 점이라면 
				if (d[cur] + a[cur][j] < d[j]) { 
					//cur까지 최소비용+ cur울 거쳐 인접노드로 가는비용< 인접노드로 가는 비용
					//*최소거리V를 거쳐가는 비용이 직통으로가는 비용보다 작다면 갱신해주자
					d[j] = d[cur] + a[cur][j];
				}
			}
		}
	}
}

int main() {
	dijkstra(0);
	for (int i = 0; i < numV; i++) {
		printf("%d", d[i]);
	}
}