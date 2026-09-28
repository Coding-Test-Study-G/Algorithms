// 1시간 18분 
// n이 작으면 그냥 조건 나누지 말자 -> 완전 탐색으로
// 좌우 이동 계산할 때 1시간 썼음(좌우는 greedy로 안됨)
 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//위 아래 이동 함수 만들기
//좌 우 이동 함수 만들기

int move_updown(char cur){
    //ABCDEFGHIJKLM A=65
    //NOPQRSTUVWXYZ N=78
    
    //N보다 낮으면
    if(cur < 'N') return (int)cur - 65;
    //N보다 크면
    else return (int)'Z' + 1 - (int)cur;
    
}


int solution(string name) {
    int answer = 0;
    int len = name.size();
    
    //1. 좌우 파악
    //n = 20이니깐 다 해보기
    int lr = len - 1;
    for(int i = 0; i < len; i++){
        //i만나면 돌아오는거임
        
        //i뒤의 연속된 A 개수 파악
        int A_series = i + 1;
        while(A_series < len && name[A_series] == 'A') A_series++;
        
        //왼쪽 두번
        int left_back = i * 2 + (len - A_series);
        //오른쪽 두번
        int right_back = i + (len - A_series) * 2;
        
        lr = min(lr, min(left_back,right_back));    
    }
    answer += lr;
    
    //2. 각 알파벳당 조정 횟수 파악
    for(int i = 0; i < name.size(); i++){
        answer += move_updown(name[i]);
    }
    
    return answer;
}