// 45분 -> 실패
// 문제 이해 잘 못함 -> 괄호 관련 문제면 스택인건 대충 알았는데
// -> [(]) 이것도 올바른 괄호인 줄 알고 구현했음
// 문제 잘 읽자..
// 오히려 더 어렵게 풀려고 한 문제..;

// 최적화
// 이런 회전 문제 vector보다 deque쓰는게 front에서 빼는게 O(1)이라 더 좋긴함
// 이 문제는 n = 1000이라 크게 차이 X
#include <string>
#include <vector>
#include <stack>
using namespace std;

// 판정 로직 함수로 빼버리기
// 올바른 괄호 문자열인지 판정
bool isValid(const vector<char>& v){
    stack<char> st;
    
    for(int i = 0; i < v.size(); i++){
        char c = v[i];
        
        // 여는 괄호면 그냥 push
        if(c == '(' || c == '[' || c == '{'){
            st.push(c);
            continue;
        }
        
        // 닫는 괄호인데 스택이 비었다 -> 바로 false
        if(st.empty()) return false;
        
        
        // top이랑 짝이 맞는지 확인
        char top = st.top();
        if(c == ')' && top != '(') return false;
        if(c == ']' && top != '[') return false;
        if(c == '}' && top != '{') return false;
        
        // 짝 맞으면 빼기
        st.pop();
    }
    
    
    // 다 돌았는데 남아있으면 안닫힌 게 있음
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    int s_length = s.size();
    vector<char> v;
    
    int A = 0, B = 0, C = 0;
    
    // 일단 벡터에 넣으면서 개수 세기
    for(int i = 0; i < s_length; i++){
        v.push_back(s[i]);
        if(v[i] == '(') A++;
        else if(v[i] == ')') A--;
        else if(v[i] == '[') B++;
        else if(v[i] == ']') B--;
        else if(v[i] == '{') C++;
        else if(v[i] == '}') C--;
    }
    
    // 개수부터 안 맞으면 바로 false
    if(A != 0) return 0;
    if(B != 0) return 0;
    if(C != 0) return 0;
    
    // s_length번 회전하면서 매번 판정
    for(int i = 0; i < s_length; i++){
        if(isValid(v)) answer++;
        
        // 왼쪽으로 한 칸 회전?
        // 맨 앞 빼서 맨 뒤로 넣기
        v.push_back(v[0]);
        v.erase(v.begin());
    }
    
    return answer;
}