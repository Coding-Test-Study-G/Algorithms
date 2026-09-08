import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        PriorityQueue<String> pq = new PriorityQueue<>(
                (a, b) -> (b + a).compareTo(a+b)
        );

        for(int number : numbers) {
            pq.offer(String.valueOf(number));
        }

        StringBuilder sb = new StringBuilder();
        while(!pq.isEmpty()){
            sb.append(pq.poll());
        }

        if(sb.charAt(0) == '0') {
            return "0";
        }
        return sb.toString();
    }
}