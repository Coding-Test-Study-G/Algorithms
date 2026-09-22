//https://school.programmers.co.kr/learn/courses/30/lessons/12979#

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int ln = stations.size();
    int wifi[10001][2];
    sort(stations.begin(), stations.end());
    
    for (int j=0; j<stations.size(); j++){
        int st = stations[j];
        wifi[j][0] = max(st-w, 1);
        wifi[j][1] = min(st+w, n);
        
    }
    int start, end, num;
    double area = w*2+1;
    
    if (wifi[0][0] != 1){
        start =1;
        end = wifi[0][0];
        
        // int num = ceil((double)(end - start)/area);
        num = (end - start + area - 1) / area;
        answer += num;
    }
    
    // n이 2억
    for (int i=0; i<stations.size()-1; i++){
        start = wifi[i][1]+1;
        end = wifi[i+1][0];
        num = (end - start + area - 1) / area;
        answer += num;
    }
    
    start = wifi[stations.size()-1][1]+1;
    end = n+1;
    num = (end - start + area - 1) / area;
    answer += num;
    

    return answer;
}
