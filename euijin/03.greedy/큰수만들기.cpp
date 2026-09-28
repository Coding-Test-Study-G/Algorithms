// 25분
// 앞쪽에 무조건 큰 수가 나와야한다.

#include <string>
#include <vector>
#include <stack>


using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int removed = 0;
    
    // 한바퀴 다 돌면서 answer에 넣기
    // string을 stack처럼 쓰기
    for(int i = 0; i < number.size(); i++){
        
        while(!answer.empty() && answer.back() < number[i] && removed < k){
            answer.pop_back();
            removed++;
        }
        answer.push_back(number[i]);
    }
    
    //만약 k개만큼 제거 못 했으면, 맨 뒤에서 자르기
    while(removed < k){
        answer.pop_back();
        removed++;
    }
    
    
    return answer; //answer는 string;
}