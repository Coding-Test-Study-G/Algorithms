// 이분 탐색 문제란걸 알아도 설계 못 했음
// 힌트 봄: 시간을 기준으로 최소, 최대 만든 뒤 parametric seach
// 힌트 봐도 틀 -> int overflow문제 -> casting해줬어야했음 => 숫자 좀 큰 것 같으면 싹다 long long으로 선언하기
// 38분

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long l, r, mid;

//해당 시간 안에 가능 한가?
//가능: T
//불가능: F
//최적이면 return해버리기
bool Opt_min(long long mid, vector<int>& times, int& n){
    long long can_handle = 0;
    
    for(int i = 0; i < times.size(); i++){
        can_handle += mid / times[i]; 
    }
    
    if(can_handle >= n) return true;
    else return false;
}


long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    l = 1;
    int max_time_idx = max_element(times.begin(), times.end()) - times.begin();;
    r = (long long)n * times[max_time_idx]; //여기 곱셈하면서 overflow 났음 -> longlong casting해줘야 계산 과정에서 overflow안남
    // int * int 는 결과가 int로 계산된 뒤 long long에 대입됨 -> 대입 전에 이미 넘침
    // 변수를 long long으로 선언하는 것만으론 부족. 곱셈 자체를 (long long)으로 캐스팅
    
    
    while(l <= r){ // <= 여야 함. l == r인 마지막 값도 검사 필요
        mid = (l + r) / 2;
        
        if(Opt_min(mid, times, n)){
            answer = mid; // 가능하니깐 일단 후보로 저장
            r = mid - 1; // 더 작은 부분도 되는지 확인
        }
        else{
            l = mid + 1; //시간 부족 -> 늘려야함
        }
    }
    return answer;
}