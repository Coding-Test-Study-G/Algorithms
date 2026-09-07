// 30분 풂 틀림

// DFS(재귀) 종료 조건 처리는 일단 맨 위로 고정한다.
// 백트래킹 구조 느낌
// void dfs(상태){
//     if(종료 조건) { 처리; return; }   // ① 항상 맨 위
    
//     for(선택지){                    // ② 그 다음
//         if(불가능) continue;        //    가지치기
//         쓰고; dfs(다음); 지우고;      //    3단 구조
//     }
// }

// 쓰고, dfs, 지우고 -> 고정 기억하기!!!!!!!!


#include <string>
#include <vector>

using namespace std;

int board[12][12] = {0, };
int answer = 0;

// 일단 행단위 기준으로 내려가기
// 한 행에서 모든 열 하나씩 돌면서
// 같은 열에 퀸 있거나, 대각선에 퀸 있으면 continue -> 다음 후보 탐색이니깐
// 놓을 수 있다면 놓기
// 다음 열로 넘기기 DFS 재귀
// 놓은거 복구



// 최적화 1. 좌측 아래 대각선, 우측 아래 대각선은 확인 할 필요 X -> 어차피 안놨으니깐
int dx[4] = {-1, 1, -1, 1};
int dy[4] = {-1, -1, 1, 1};


void dfs(int n, int cur_row){
    // 종료 조건. 마지막 줄에 놨으면(마지막 줄까지 통과 했다면)
    if(cur_row == n){answer++; return;}
    
    
    // 이번 row에서 순회하기
    for(int i = 0; i < n; i++){
        //세로에 있다면 continue
        bool pass = false;
        
        for(int j = 0; j < cur_row; j++){
            if(board[j][i] != 0) {pass = true; break;}
        }
        if(pass) continue; //이번 열은 패스하고 다음 열 보기
        
        //대각에 있다면 pass true하고 다음 열 찾기
        for(int j = 0; j < 4; j++){
            int tmp = 1;
            while(true){
                int nx = cur_row + dx[j] * tmp;
                int ny = i + dy[j] * tmp;
                
                //벽이면 break
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                //만나면 pass=true하고 break
                if(board[nx][ny] != 0){pass = true; break;}
                tmp++;    
            }
        }
        if(pass) continue;
        
        
        
        //세로 대각선 다 없으니깐 드디어 놓기
        board[cur_row][i] = 1;
        
        //다음 DFS 보내기
        dfs(n, cur_row + 1);
        
        //복구 코드
        board[cur_row][i] = 0; //내가 아까 놨던걸 지운다.
        
    }
    

}


int solution(int n) {

    dfs(n, 0);
    
    return answer;
}