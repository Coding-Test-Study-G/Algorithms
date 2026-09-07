// 8분
// n = 50,000 -> 완전 탐색, DP 불가능한 크기

// DP가 불가능한 크기 + 정렬하면 규칙이 보임 -> Greedy 정석 흐름
// Greedy + Two Pointer
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int r = people.size() - 1;
    
    // 일단 정렬
    sort(people.begin(), people.end());
    
    // 가장 큰사람 + 가장 작은사람 비교해보고, limit보다 크면 큰사람만 보내기
    
    // while문이 자연스럽긴 하다.
    for(int l = 0; l <= r; ){
        
        if(people[l] + people[r] <= limit){
            l++;
            r--;
        }
        
        else{
            r--;
        }
        answer++;
    }    
    
    return answer;
}