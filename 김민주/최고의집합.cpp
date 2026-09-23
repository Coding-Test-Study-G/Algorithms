// https://school.programmers.co.kr/learn/courses/30/lessons/12938#

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer(1);
    vector<int> vc(n);
    
    int flag = s/n;
    if (flag < 1){
        answer[0] = -1;
        return answer;
    }
    
    // 첫번째, 공평하게 분배
    int summ =0;
    for (int i=0; i<n; i++){
        vc[i] = flag;
    }
    
    // 두번째, 나머지를 분배
    int flag2 = s%n;
    int j=n-1;
    while (j >= 0 && flag2 > 0){
        vc[j] += 1;
        flag2 -= 1;
        j -=1;
    }
    return vc;
}
