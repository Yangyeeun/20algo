#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
int INF = 1000000000;

// 배열 초기화

	int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floyd() {
	//// 결과 그래프를 초기화 
	//int d[num][num]; //모든 v->모든v 최소비용 담는배열

	int **d = malloc(sizeof(int *) * 4);   // 이중 포인터에 (int 포인터 크기 * 세로 크기)만큼
										  // 동적 메모리 할당. 배열의 세로

	for (int i = 0; i < 4; i++)            // 세로 크기만큼 반복
	{
		d[i] = malloc(sizeof(int) * 4);    // (int 크기 * 가로 크기)만큼 동적 메모리 할당.
										   // 배열의 가로
	}
	

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			d[i][j] = a[i][j];
		}
	}
	//Point: 거쳐가는 노드k 중심
	for (int k = 0; k < 4; k++) { //k: 거쳐가는 노드
		for (int i = 0;i < 4; i++) { //i: 출발노드
			for (int j = 0; j < 4; j++) { //j:도착노드
				//i->j(출발-도착) VS i->k->j(출발-거쳐-도착)
				if (d[i][k] + d[k][j] < d[i][j]) //거쳐비용이 더 작으면 적은 비용으로 갱신
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d ", d[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 4; i++)    // 세로 크기만큼 반복
	{
		free(d[i]);                // 2차원 배열의 가로 공간 메모리 해제
	}

	free(d);    // 2차원 배열의 세로 공간 메모리 해제

}
int main(void) {
	floyd();
}