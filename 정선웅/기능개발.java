import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<>();
        int[] days = new int[100];
        int day = 1;
        for(int j=0; j<progresses.length; j++) {
            while(day <= 100) {
                if(progresses[j] + speeds[j]*day >= 100) {
                    days[day]++;
                    break;
                }
                day++;
            }
        }

        for(int num: days) {
            if(num !=0) {
                answer.add(num);
            }
        }

        int[] result = new int[answer.size()];

        for(int i=0; i<answer.size(); i++) {
            result[i] = answer.get(i);
        }
        return result;
    }
}