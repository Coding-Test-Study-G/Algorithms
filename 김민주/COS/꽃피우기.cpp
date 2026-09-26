// https://school.programmers.co.kr/learn/courses/11114/lessons/70743
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> garden) {
    int x[] = {0, 0, 1, -1};
    int y[] = {1, -1, 0, 0};
    int ln = garden.size();
    int answer =0;
    int cnt =0;
    int flag =1;
    queue <pair <int, int>> q;
    
    for (int i = 0; i < ln; i++) {
        for (int j = 0; j < ln; j++) {
            if (garden[i][j] == 1){
                q.push({i,j});
            }
        }
    }
    
    while (!q.empty()){
        auto [nowi, nowj] = q.front();
        q.pop();
        // cout << nowi << nowj << endl;
        for (int k = 0; k<4; k++){
            int newi = nowi + x[k];
            int newj = nowj + y[k];
            if ((0<= newi && newi < ln && 0<= newj && newj < ln)
                &&(garden[newi][newj] == 0)){
                garden[newi][newj] = garden[nowi][nowj]+1;
                answer = garden[nowi][nowj];
                q.push({newi, newj});
            }
        }
        
    }
    return answer;
    
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<vector<int>> garden1 = {{0, 0, 0}, {1, 0, 0}, {0, 0, 0}};
    int ret1 = solution(garden1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;
    
    vector<vector<int>> garden2 = {{1, 1}, {1, 1}};
    int ret2 = solution(garden2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}
