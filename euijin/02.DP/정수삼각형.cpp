// 43분..
// DP 기본문제다.
// 아래부터 올라오면 더 편하다..(index outofbound 생각 덜 해도 됨) -> 방향도 한번 더 생각해보기


#include <string>
#include <vector>
#include <algorithm> //max있나 -> container 쓸때는 항상 iterator로 접근하는게 기본

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    
    if(n == 1) return triangle[0][0];
    
    //전체 높이 만큼 반봅
    for(int i = 0; i < n; i++){
    //한 열 개수 만큼 반복
        for(int j = 0; j < triangle[i].size(); j++){
        
            if(i == 0) continue;// 1열이면 skip    
            //1열이 아니라면, 이전 열이랑 더하기

            //근데 기존값이랑 비교해서 최댓값 뽑아야함
            //근데 또 이전 열의 좌/우에 값이 있는지 체크해야함
            if(j == 0){//오른쪽이랑만 더하기
                triangle[i][j] = max(triangle[i][j] + triangle[i-1][j], triangle[i][j]);
                continue;
            }
            if(j == triangle[i].size() - 1){//왼쪽이랑만 더하기
                triangle[i][j] = max(triangle[i][j] + triangle[i-1][j-1], triangle[i][j]);
                continue;
            }
            //위 두개 중에 큰것 선택해서 더하기       
            triangle[i][j] = triangle[i][j] + max(triangle[i-1][j], triangle[i-1][j-1]);
        }
        
    }
    
    //마지막열 돌면서 최댓값 찾기
    //그냥 max함수로도 가능? -> iterator로
    
    // 최적화 1. vector에 max 쓰기
    // answer = max(triangle[n-1].begin(), triangle[n-1].end);
    for(int i = 0; i < triangle[n-1].size(); i++){
        answer = max(answer, triangle[n-1][i]);
    }
    
    return answer;
}