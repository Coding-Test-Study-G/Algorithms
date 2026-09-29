// Heap 사용법 알고 푸니깐 10분컷
// -> 꼭 외우자!

#include <string>
#include <vector>
#include <queue>
/*
heap으로 푸는 문제
heap 사용 법 암기하기
 최대 힙 (기본)
  priority_queue<int> maxHeap;
 최소 힙 — 이 한 줄은 통째로 외우기
  priority_queue<int, vector<int>, greater<int>> minHeap;

stack처럼 top(), pop(), size(), empty() 쓰면 된다.
*/


using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    // 최적화 3: int 말고 long long으로 했어야함
    // 운 좋게 통과한거임
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i = 0; i < scoville.size(); i++) minHeap.push(scoville[i]); // O(nlogn)
    // 최적화 1
    //minHeap(scoville.begin(), scoville.end()) -> O(n)
    
    
    if(minHeap.top() >= K) return 0; //이거 처리 안해줘서 한번 틀렸음 -> 항상 예외 생각
    
    while(!minHeap.empty() && (minHeap.top() < K)){
        // 최적화 2
        // 여기 안에서 size() < 2 검사하면 위쪽에서 예외처리 필요 없었다.
        int first = minHeap.top();
        minHeap.pop();
        if(minHeap.empty()) return -1;

        int second = minHeap.top();
        minHeap.pop();

        minHeap.push(first + second * 2);
        answer++;
        
        if(minHeap.top() >= K) return answer;
    }
    return -1;
}