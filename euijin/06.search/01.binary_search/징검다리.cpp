// 좋은 문제!
// 아예 틀(1시간 30분) -> 꼭 다시 풀어보기

// Greedy로 풀려다가 실패
// 이분 탐색으로 풀어야함

// 전체: 0 [2 11 14 17 21] 25 -> 돌은 5개
// 사잇값: 2 9 3 3 4 4 -> interval 6개
// n개 고르기()

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//가능하면 T, 안되면 F
//n: 제거 가능한 바위 개수
bool can_make(int mid, vector<int> rocks, const int& n, int distance){
    int eliminate = 0;
    int prev_rock = 0;
    
    // 1바퀴만 돌아야한다.
    for(int i = 0; i < rocks.size(); i++){
        if(rocks[i] - prev_rock < mid) eliminate++;
        else prev_rock = rocks[i];     
    }
    
    // 이거 잘 생각해보기
    if(distance - prev_rock < mid) eliminate++;
    // while일 필요 X
    // 이미 앞 기준점까지는 mid 이상이었음
    // 최종 목적지랑 거리가 mid 이하면 하나만 제거해도 mid 이상임이 보장된다.
    // -> 반복할 필요 X
    
    return eliminate <= n;

}


int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    long long l = 0, r = distance;
    
    
    while(l <= r){
        long long mid = (distance / 2);
        
        if(can_make(mid, rocks, n, distance)){
            answer = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return answer;
}