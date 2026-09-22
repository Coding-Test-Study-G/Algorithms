// https://school.programmers.co.kr/learn/courses/30/lessons/42628
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    multiset <int> mt;
    // priority_queue <int> pq1; // 최대
    // priority_queue <int, vector<int>, greater<int>> pq2; //최소
    
    for (int i=0; i<operations.size(); i++){
        string node = operations[i];
        string one = node.substr(0,1);
        if (one == "I"){
            int num = stoi(node.substr(2));
            mt.emplace(num);
        }
        else if (one == "D"){
            if (mt.size() == 0){
                continue;
            }
            string d = node.substr(2);
            if (d == "-1"){
                // int minone = *mt.begin();
                mt.erase(mt.begin());
            }
            else if (d == "1"){
                // int maxone = *mt.rbegin();
                mt.erase(--mt.end());
            }
            
        }
    }
    if (mt.size() == 0){
        answer[0] = 0;
        answer[1] = 0;
    }
    else if (mt.size() == 1){
        int one = *mt.rbegin();
        answer[0] = one;
        answer[1] = one;
        // if (one > 0){
        //     answer[0] = 0;
        //     answer[1] = one;
        // }else{
        //     answer[0] = one;
        //     answer[1] = 0;
        // }
    }
    else{
        answer[1] = *mt.begin();
        answer[0] = *mt.rbegin();
    }
    
    return answer;
}
