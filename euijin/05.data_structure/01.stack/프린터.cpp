// n 100이하 -> n * n으로 해도 됨
// 25분
// Priority Queue로 푸는게 일반적인데 리팩터링은 나중에..

#include <string>
#include <vector>

using namespace std;

int p_num[10] = {0, };

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    //벡터 큐처럼 쓰기
    vector<pair<int,int>> v;
    
    
    
    //일단 큐에 넣기
    for(int i = 0; i < priorities.size(); i++){
        v.push_back({i , priorities[i]});
        
        p_num[priorities[i]]++; 
    }
    
    //앞에거 꺼내고, 
    
    
    int cur_priorities = 9;
    int before_idx = 0;
    int cur_idx = 0;
    while(true){
        //오류 확인용
        if(cur_priorities == 0) return -100;
        
        cur_idx = before_idx;
        
        for(int t = 0; t < priorities.size(); t++){
            //이번 우선순위 없으면
            
            if(cur_idx > priorities.size()) cur_idx = 0;
            
            if(p_num[cur_priorities] == 0){
                before_idx = cur_idx;
                cur_priorities--;
                break;
            }
            
            if(v[cur_idx].second == cur_priorities){
                p_num[cur_priorities]--;
                answer++;
                
                if(v[cur_idx].first == location)
                    return answer;
                
            }
            
            cur_idx++;
            
            
        }
        
        
    }
    
    
    
    
    
    return answer;
}