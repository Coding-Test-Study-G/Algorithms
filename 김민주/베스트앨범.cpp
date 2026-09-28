// https://school.programmers.co.kr/learn/courses/30/lessons/42579?language=cpp
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map <string, int> cnt;
    unordered_map <string, vector<pair<int, int>>> each;
    int ln = genres.size();
    
    for (int i=0; i<ln; i++){
        cnt[genres[i]] += plays[i];
        // plays, idx
        each[genres[i]].push_back({plays[i], i});
    }
    // map -> vc 1
    vector <pair <string, int>> vcCnt (cnt.begin(), cnt.end());
    sort(vcCnt.begin(), vcCnt.end(), [](auto& a, auto& b){
        return a.second > b.second;
    });
    
    
    // 장르 1,2위
    for (int i=0; i<vcCnt.size(); i++){
        auto g = vcCnt[i].first;
        vector<pair<int, int>> vc = each[g];
        sort(vc.begin(), vc.end(), [](auto& a, auto& b){
            if (a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        
        // 답 저장
        answer.push_back(vc[0].second);
        if (vc.size() < 2){
            continue;
        }
        answer.push_back(vc[1].second);
    }
    
    return answer;
}
