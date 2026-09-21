// 구현 1시간 -> 디버깅 30분 -> 실패
// 1. substr 사용법 -> 2번째 인자는 끝 인덱스가 아니라 길이다!
// 2. 문제 이해 자체를 잘 못 했다. -> 같은 차량이 여러 번 입출차하면 누적 시간을 다 더한 뒤 요금을 한 번 계산한다.
//      => 통념이랑 다르다........

// 추가 수정에 20분

// Simulation 문제
// 1. 시간 계산은 무조건 분 단위로 통일하고 시작 -> 계산 편함
// 2. Key로 찾아야 하면 vector 선형탐색 말고 map -> 정렬까지 자동으로 됨(정렬 필요없을 땐, unordered_map)
// 3. 올림 나눗셈 편하게: (a + b - 1) / b
// 4. 함수화 잘 하는게 중요


// 일단 총 기록이 1000개 이하다 -> 그냥 완전탐색 돌려도 될듯


// 동일  차량 번호가 여러 번 입출차 한 경우, 한번만 반환해야한다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// idx 0 -> 시, 1 -> 분, 2 -> 차량 번호, 3 -> OUT 이면 1
int sub(string str, int idx){
    if(idx == 0) return stoi(str.substr(0,2));
    if(idx == 1) return stoi(str.substr(3,2));
    if(idx == 2) return stoi(str.substr(6,4));
    if(idx == 3){
        if(str.substr(11,3) == "OUT") return 1;
        else return 0;
        // str.substr(11, 3) == "OUT" ? 1 : 0; -> 이렇게 하면 한 줄로 깔끔
        
    }
    return -1;
}


vector<pair<int, int>> num_time;
vector<int> answer;


void put_num_time(int number, int time){
    int len = num_time.size();
    
    for(int i = 0; i < num_time.size(); i++){
        if(num_time[i].first == number){
            num_time[i].second += time;
            return;
        }
    }
    
    num_time.push_back({number, time});
    return;
}



vector<int> solution(vector<int> fees, vector<string> records) {
    // fee가 요금 표
    // records가 정산 표
    int n = records.size();
    bool out[1010] = {false, };
    
    int number, hour, min, fare, total_min;
    
    
    // 출차 된거 처리
    // 일단 vector로 하나씩 앞으로 간다
    for(int i = 0; i < n; i++){
        // out을 만나면 뒤로 하나씩 간다.
        if(sub(records[i], 3)){
            // 일단 out 처리
            for(int j = i - 1; j >= 0; j--){
                if(sub(records[j], 2) == sub(records[i], 2)){
                    out[i] = true;
                    out[j] = true;
            
                    number = sub(records[i], 2);
                    
                    hour = sub(records[i], 0) - sub(records[j], 0);
                    min = sub(records[i], 1) - sub(records[j], 1);
                    
                    total_min = hour * 60 + min;
                    
                    put_num_time(number, total_min);
                    break;
                }
            }
            
            
            
        }
        
        
    }
    // 출차 안된거 처리
    // out 배열을 하나 만들어서 정상적으로 out 되었는지 체크한다(visited 느낌으로)
    for(int i = 0; i < n; i++){
        if(out[i] == false){
            out[i] = true;
            
            number = sub(records[i], 2);
                    
            hour = 23 - sub(records[i], 0);
            min = 59 - sub(records[i], 1);

            total_min = hour * 60 + min;

            put_num_time(number, total_min);
        }
    }
    
    int tmp = 0, tmp_total_fee;
    for(int i = 0; i < num_time.size(); i++){
        tmp = num_time[i].second;
        
        if(tmp > fees[0]){
            tmp_total_fee = fees[1];
            tmp -= fees[0];
            
            tmp_total_fee += (tmp / fees[2]) * fees[3];
            if(tmp % fees[2]) tmp_total_fee += fees[3];
        }
        else tmp_total_fee = fees[1];
        
        
        num_time[i].second = tmp_total_fee;
    }
    
    
    sort(num_time.begin(), num_time.end());
    
    for(int i = 0; i < num_time.size(); i++){
        answer.push_back(num_time[i].second);
    }
    
    return answer;
}