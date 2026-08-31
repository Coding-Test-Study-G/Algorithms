// BFS ver 17분
// DFS도 가능 -> DFS로도 풀어보기

// 주의! 이 문제 시간복잡도 n^2이다. n^3인줄 알았음 -> 잘 생각해보기

#include <string>
#include <vector>
#include <queue>
using namespace std;


// 최적화 1: const &로 읽기
// 최적화 2: visited를 bool로 만들기
int bfs(const vector<vector<int>>& computers, int s, int visited[], int n){
    
    queue<int> q;//큐 만들기
    q.push(s);//시작 넣기
    visited[s] = 1;//visited
    
    //반복
    while(!q.empty()){
        //front 꺼내기
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < n; i++){
            // 0 아닌지 체크
            if(computers[cur][i] == 0) continue;
            // 미방문인지 체크
            if(visited[i] == 1) continue;
            // 통과하면 큐 넣고 visited
            q.push(i);
            visited[i] = 1;
        }
    }
    // 최적화 3: return 1이 아니라 그냥 solution함수에서 bfs한번 끝나면 answer++로 해도 좋음
    return 1;
}
    

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int visited[200] = {0,};
    
    // i개 노드 모두 넣기
    for(int i = 0; i < n; i++){
        if(visited[i] == 1) continue; 
        answer += bfs(computers, i, visited, n);
    }
    
    return answer;
}