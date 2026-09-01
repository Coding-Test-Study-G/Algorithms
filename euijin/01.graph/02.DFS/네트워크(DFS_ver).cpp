// DFS ver
// BFS도 가능
// 8분
#include <string>
#include <vector>
#include <queue>
using namespace std;

// 최적화 1. visited 배열 bool로 선언
// 최적화 2. 시작 노드 방문처리 안했음 -> 이 문제는 운 좋아서 할 필요 없었던거임

//computers는 읽기만
void DFS(int start_node, int visited[], const vector<vector<int>>& computers, int n){
    for(int i = 0; i < n; i++){
        //연결 안되면 넘기기
        if(computers[start_node][i] == 0) continue;
            
        //방문 했으면 넘기기
        if(visited[i] == 1)continue;
        
        //새로운 놈이면 visited 체크하고, DFS 넘기기
        visited[i] = 1;
        DFS(i, visited, computers, n);
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int visited[200] = {0,};
    
    //모든 노드 DFS에 넣어버리기
    for(int i = 0; i < n; i++){
        if(visited[i] == 1) continue; //이미 방문 노드 skip
        
        DFS(i, visited, computers, n);
        answer++; //DFS 한번 돌았으니깐 네트워크 하나 생긴겨
    }
    
    return answer;
}