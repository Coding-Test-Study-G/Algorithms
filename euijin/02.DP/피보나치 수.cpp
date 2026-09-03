// DP: 이미 계산해둔 값을 사용한다.
// 재귀로 짜면 중복 계산(O(2^n)) -> 시간 초과
// DP로 O(N)

#include <string>
#include <vector>

using namespace std;


int solution(int n) {
    int answer = 0;
    
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }

    
    return dp[n];
}