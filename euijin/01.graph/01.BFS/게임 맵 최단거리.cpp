// 최단거리 & 가중치 X -> BFS
#include<vector>
#include<queue>
using namespace std;

// 큐 생성 → 시작점 push + 방문표시
// while(큐 안 빔):
//     front 꺼내고 pop
//     4방향 반복:
//         범위 체크 → 벽/조건 체크 → 방문 체크
//         방문표시 + push

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

//배열은 읽기만 할거니깐 const &
int bfs(const vector<vector<int>>& maps, int sx, int sy, int ex, int ey){
    int n = maps.size(), m = maps[0].size();
    
    //dist가 최단 거리의 핵심 추가 배열
    //dist로 visted + distance 저장까지
    vector<vector<int>> dist(n, vector<int>(m, 0)); // 0으로 초기화까지 하는 방법
    
    queue<pair<int,int>> q; //BFS queue
    q.push({sx, sy}); // 출발지 push, 이젠 make_pair 안써도 된다 {}로 가능
    dist[sx][sy] = 1; // 시작칸도 1임 -> 시작칸 포함 여부 항상 체크하기
    
    while(!q.empty()){
        int x = q.front().first; //현재 지점
        int y = q.front().second;
        q.pop(); //현재 지점 뽑고 pop()
        
        //현재 목표 지점이라면 바로 return
        if(x == ex && y == ey) return dist[x][y];
        // 목표 지점 체크를 pop()후 하고 있음
        // 이 문제에서는 push 시점에 하는게 살짝 더 빠르긴한데, 나중에 다른 개념들 들어오면 이게 정석
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // continue!!!!! (break아님 다음 지점 체크 해야하니깐)
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue; // 범위 밖
            if(dist[nx][ny] != 0) continue; // 이미 방문 함
            if(maps[nx][ny] == 0) continue; // 벽
            
            dist[nx][ny] = dist[x][y] + 1; //visited, 거리 측정 하면서 
            q.push({nx, ny}); // 넣기
        }
    }
    return -1;    //큐가 비었는데 도착 못 함
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size(), m = maps[0].size();

    return bfs(maps, 0, 0, n - 1, m - 1); //배열과 시작 지점, 종료 지점 보내기
}