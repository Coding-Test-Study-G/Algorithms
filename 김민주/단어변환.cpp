//https://school.programmers.co.kr/learn/courses/30/lessons/43163

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
int wln;

void func(string b, string w,
         unordered_map <string, vector <string>>& vc, 
         unordered_map <string, bool>& visited){
    int flag =0;
    for (int j=0; j<wln; j++){
        if (b[j]  == w[j]){
            flag += 1;
        }
    }
    if (flag == wln-1){
        vc[b].push_back(w);
        vc[w].push_back(b);
    }
    
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int ln = words.size();
    wln = begin.size();
    unordered_map <string, vector <string>> vc(ln);
    unordered_map <string, bool> visited(ln);
    
    for (string w : words){
        func(begin, w, vc, visited);
    }
    
    for (string b : words){
        for (string w : words){
            func(b, w, vc, visited);
        }
    }
    int cnt =0;

    queue <pair<string, int>> q;
    q.push({begin, 0});
    visited[begin] = true;
    // auto now;
    
    while(!q.empty()){
        // nowpair = q.front();
        // now = nowpair.first;
        // cnt = nowpair.second;
        auto [now, cnt] = q.front();
        q.pop();
        
        if (now == target){
            return cnt;
            break;
        }
        visited[now] = true;
        
        
        for (string node: vc[now]){
            if (!visited[node]){
                q.push({node, cnt+1});
                visited[node] = true;
            }
        }
    }
    
    return cnt;
}
