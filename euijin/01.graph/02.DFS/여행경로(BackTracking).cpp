// 못 풂(30분 정도 고민)
// 도시는 여러 번 방문 가능 -> visited 기준을 티켓으로 해야함

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//모든 조합 -> DFS
//n = 10^4 -> DFS 가능?
//근데 알파벳 순 정렬 -> DFS하면 딱인 문제긴 하다.

// 일단 하나 잡고 쭉 끝까지 해보는거임(DFS니깐)
// 1. 모든 티켓 쓰면 된다.
// 2. 몇 갈래든 생기면 문자열 앞인 것 부터 방문(티켓을 미리 정렬해 놓으면 되긴 함)
// 3. 처음 종료되는게 있으면 그게 정답


// 전역으로 선언할만한거 전역으로 선언했던거 기억하기!!!!!
int n;
vector<string> path;
vector<bool> used; //visited계열은 최단거리 문제 아니면 bool 처리


// 정렬 시켜놓고
// 1. 종료 조건: 모든 ticket 방문(used)
// 2. 갈 수 있는 모든 경로 알파벳순으로 내려가면서 쭉쭉 방문

//return bool해야한다 -> 그래야 if 조건안에 DFS함수 걸고 빠르게 탈출 !!!!!
//path는 전역변수로 해놨으니깐 인자로 전달할 필요 없다.
bool dfs(const vector<vector<string>>& tickets, string cur){
    
    // 1. 종료(return) 조건: 티켓 다 썻는지 여부
    if(path.size() == n + 1){ //종료조건 n+1 이다 -> INC는 넣고 처음 DFS 시작했으니깐
        return true;
    }
    
    // 2. 반복하면서 다음 지역 확인(모든 티켓 돌면서)
    for(int i = 0; i < n; i++){
        if(used[i]) continue; // 그냥 map 이딴거 없이 i번째 도시 돌았냐로 판단!!!!!!!!!!!!!!!
        if(cur != tickets[i][0]) continue; //i번째 도시가 출발지가 아니면 pass
        
        
        used[i] = true; //티켓 쓰고
        path.push_back(tickets[i][1]); //path에 넣고
        
        
        //true면 true로 넘긴다?
        if(dfs(tickets, tickets[i][1])) return true;
        
        //실패했으면 path에서 빼기 <- *****백트래킹 핵심*****
        path.pop_back();
        used[i] = false; //방문 안했다는 처리는 두 개 해줘야함
        //pathd에서도 지우고 used에서도 지우고
    }
    
    return false; //이 갈래로 갈 수 있는 길이 다 실패
}



vector<string> solution(vector<vector<string>> tickets) {
    n = tickets.size(); 
    used.assign(n, false); //used 배열 초기화
    path.clear();// path도 초기화
    
    sort(tickets.begin(), tickets.end()); //정렬해서 알파벳순 보장
    
    path.push_back("ICN"); //일단 무조건 INC 시작이니깐 pathdp sjgrh
    dfs(tickets, "ICN"); //dfs 돌리기
    
    return path;
}