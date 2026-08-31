//n=20, 2^20 -> 완전 탐색 가능
//보통 n <= 25면 완전 탐색 고려해보기!!!

//경우의 수, 모든 조합이므로 DFS

// 재귀 기본 틀
// void 재귀(상태) {
//     if (더 못 내려감) {   // 1. 종료 조건 검사 —> 반드시 return
//         결과 처리;
//         return;
//     }
//     for (모든 선택지) {   // 2. 다음 상태 -> 단, 종료 조건으로 다가가기!!
//         재귀(다음 상태);
//     }
// }

#include <string>
#include <vector>

using namespace std;

// numbers는 읽기만 하니깐 const &
// answer도 &로 주기
void dfs(const vector<int>& numbers, int target, int idx, int sum, int& answer) {

    //1. 종료 조건 
    if(idx == numbers.size()){ // 마지막 숫자 도달?
        if(sum == target) answer++; //target 도달?
        return;
    }
    
    //2. 재귀 2갈래 (idx++ 로 넘기면 안된다!)
    dfs(numbers, target, idx + 1, sum + numbers[idx], answer); // +
    
    dfs(numbers, target, idx + 1, sum - numbers[idx], answer); // -
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, target, 0, 0, answer);
    
    return answer;
}