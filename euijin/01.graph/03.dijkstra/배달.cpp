// 40분

/*
가중치가 있는 간선이 있다 -> 다익스트라
가중치가 있는데 음수 가중치도 있다 -> 플로이드 워셜 or 벨만 포드
=> 사실 이게 주된 선택 이유는 아님

모든 쌍의 최단거리가 필요 할 때 -> 플로이드 워셜
n이 작아서(400이하) 코드 짧은게 나을 때 -> 플로이드 워셜

다익스트라는 시작점과 다른 정점간의 최단거리를 구함
(벨만 포드도 시작점과 다른 정점간의 최단거리를 구한다.)
*/


// 다익스트라 3요소 (이 틀 그대로 외우기)
// 1. 인접리스트 만들기 (양방향이면 양쪽 다) <- 이거 안 하면 매번 전체 간선 훑음
// 2. pq에서 꺼내자마자 pop + if(d > dist[cur]) continue  <- 옛날 정보 거르기
// 3. 더 짧아질 때만 dist 갱신 후 push

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    // 최소 힙: priority_queue<담을 타입, vector<담을 타입>, greater<>>
    // 중요: {거리, 정점} -> 순서 바뀌면 안됨(heap이 first로 비교하니깐 거리가 앞에 와야함)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // 다익스트라에서는 pair로 넣어야한다.
    
    

    // 최적화 3
    // const int INF = 1e9;
    // vector<int> dist(N + 1, INF);
    // dist[1] = 0;
    int dist[51] = {0, };
    for(int i = 2; i <= N; i++) dist[i] = 1e9;
    //int        약 ±21억          (10자리) => 1e9 //10억
    //long long  약 ±9.2 × 10^18   (19자리) => 1e18
    
    
    pq.push({0, 1});
    while(!pq.empty()){
        int cur_node = pq.top().second;
        // 최적화 1: 다익스트라 기본 구조
        // int d = pq.top().fisrt; -> 현재 거리 읽어오기
        // pq.pop(); => 읽자 마자 pop하는게 좋음
        // if(d > dist[cur_node]) continue; -> 옛날 정보면 버림
        // 지금은 밑에 dist 조건 검사로 걸러주긴 하지만, 이렇게 미리 한번 검사하는게 기본 구조임(pop도 읽자마자하는게 기본)
        


        // 최적화 2: 인접 리스트 만들어 놓기
        // 지금은 이중 for문으로 정점 하나 꺼낼때마다 도로 2000개 다 확인함 & 양방향 분기도 함
        // 미리 인접리스트 만들어 놓으면 -> 복잡도 O(V * E) -> O(E logV)

        /*
        인접 리스트 만들기
        vector<vector<pair<int,int>>> adj(N + 1);   // adj[정점] = {이웃, 비용}들

        for(auto& r : road){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});      // 양방향 처리는 여기서 한 번만
        }


        루프 변경 -> 분기 검사도 할 필요 X
        for(auto& e : adj[cur_node]){
            int next = e.first;
            int cost = e.second;
            
            if(dist[cur_node] + cost < dist[next]){
                dist[next] = dist[cur_node] + cost;
                pq.push({dist[next], next});
            }
        }
        */
        for(int i = 0; i < road.size(); i++){
            if(cur_node == road[i][0] && (dist[cur_node] + road[i][2] < dist[road[i][1]])){
                
                dist[road[i][1]] = dist[cur_node] + road[i][2];
                
                pq.push({dist[road[i][1]], road[i][1]});
                
            }
            
            else if(cur_node == road[i][1] && (dist[cur_node] + road[i][2] < dist[road[i][0]])){
                
                dist[road[i][0]] = dist[cur_node] + road[i][2];
                
                pq.push({dist[road[i][0]], road[i][0]});
            }
        }
        pq.pop(); //위쪽 최적화 1의 일부
    }    
    
    for(int i = 1; i <= N; i++){
        if(dist[i] <= K) answer++;
    }

    return answer;
}