// 20분 -> 해설 봄

// 플로이드-워셜 ver
// 간선 가중치 양수/음수 둘 다 일 때 가능
// n < 50 이하 작을 때 써야한다 => 다익스트라보다 구현 간단(4줄)
// + 모든 쌍의 최단 거리 구할 수 있다.

// 플로이드-워셜 기본 idea
// dp 쓰면서, 3중 for문
// i -> j로 갈 때, k를 거쳐가면 더 짧아지나?

// cf)
// 음수 사이클 = 어떤 알고리즘도 최단거리 못 구함 (답이 -INF라 정의 자체가 안 됨)
// -> 벨만포드, 플로이드는 "존재 여부 감지"만 가능함
//    플로이드: dist[i][i] < 0 이면 음수 사이클

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 7;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    // 거리 배열 초기화
    int dist[51][51]; // vector<vector<int>>(N+1, vector<int>(N+1, INF));
    for(int i = 0; i < 51; i++){
        for(int j = 0; j < 51; j++){
            if(i == j) dist[i][j] = 0; //자기 자신이면 0
            else dist[i][j] = INF;
        }
    }
    
    // 직접 연결된 도로부터 확인(양방향 체크)
    // 직행 계산하는거임
    for(int i = 0; i < road.size(); i++){ // 앞으론 의도적으로 for(auto& r : road) range-based로 쓰기
        int node_a = road[i][0], node_b = road[i][1], dist_cur = road[i][2];
        dist[node_a][node_b] = min(dist[node_a][node_b], dist_cur); 
        dist[node_b][node_a] = min(dist[node_b][node_a], dist_cur);
    }
    
    //3중 for문(3차원 dp) => 잘 생각해보기
    // k = 1 -> 1번 노드만 경유 가능: X, {1}
    // k = 2 -> 1,2번 노드만 경유 가능: X, {1}, {2}, {1,2} 
    //   실제 계산은 i -> k -> j 만 일어나지만 이미 이전 k = 1 에서 i -> 1 - > k(2), k(2) -> 1 -> j가 계산되어있음
    // k = N 까지 반복하다보면 결국 모든 경유지 거친 최소 거리 나옴
    for(int k = 1; k <= N; k++) //k -> 경유지 허용 범위
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    
    for(int i = 1; i <= N; i++) 
        if(dist[1][i] <= K) answer++;
    
    
    return answer;
}