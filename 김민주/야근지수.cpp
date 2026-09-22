// https://school.programmers.co.kr/learn/courses/30/lessons/12927

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue <int> pq;
    for (int i=0; i<works.size(); i++){
        pq.push(works[i]);
    }
    int j = n;
    while(!pq.empty() && j>0){
        int node = pq.top();
        pq.pop();
        if (node >= 1){
            node -= 1;
            j -= 1;
            pq.push(node);
        }
    }
    
    while(!pq.empty()){
        int node = pq.top();
        answer += node * node;
        pq.pop();
    }
    
    return answer;
}
