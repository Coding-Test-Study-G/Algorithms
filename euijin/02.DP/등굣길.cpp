// 47분
// 문제에서 행, 열 뒤집어서 줘서 한참 걸렸다.
// 문제에서 [4,3] 이라고 함. 근데 행렬은 [3,4]임 -> 뒤집어서 생각했어야함
// 좌표 나오면 이거 순서 맞는지부터 체크해야한다!

// 웅덩이 0으로 했으면, 분기할 필요 없었다........(좌, 우 웅덩이일때 분기 필요없고, 0행 & 0열 1로 초기화도 필요 없었음)


// 최단 경로의 개수
// 1행, 1열 1넣고
// 왼쪽 + 위 더하면 됨

// 경우의 수 나오면 DP 의심
// 나눈 나머지 나오면 DP 의심


#include <string>
#include <vector>

using namespace std;



int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    int route[101][101] = {0, };
    route[0][0] = 1; //시작 점
    
    
    // 웅덩이 위치 미리 체크
    for(int i = 0; i < puddles.size(); i++){
        route[puddles[i][1] - 1][puddles[i][0] - 1] = -1;    
    }
    
    // 0행에 1 넣기
    for(int i = 0; i < m; i++){
        if(route[0][i] == -1) break;
        route[0][i] = 1;
    }
    // 0열에 1 넣기
    for(int j = 0; j < n; j++){
        if(route[j][0] == -1) break;
        route[j][0] = 1;
    }
    
    // 한 행씩 내려가면서 계산
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(route[i][j] == -1) continue; //웅덩이면 pass
        
            // 위 아래 다 넣을거임   
            // 좌가 웅덩이라면
            if(route[i][j-1] == -1){
                route[i][j] = route[i-1][j];
                continue;
            }
            // 위가 웅덩이라면
            if(route[i-1][j] == -1){
                route[i][j] = route[i][j-1];
                continue;
            }
            route[i][j] = (route[i-1][j] + route[i][j-1]) % 1000000007;
        }
    }
    
    return route[n-1][m-1];
}