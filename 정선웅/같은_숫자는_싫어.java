import java.util.*;

public class Solution {

    public int[] ListToArray(List<Integer> result) {
        int[] answer = new int[result.size()];
        for(int i=0; i<result.size(); i++) {
            answer[i] = result.get(i);
        }
        return answer;
    }

    public List<Integer> solution(int[] arr) {
        List<Integer> result = new ArrayList<>();

        int preNum = 10;
        for(int i=0; i<arr.length; i++) {
            if(arr[i] != preNum) {
                result.add(arr[i]);
            }
            preNum = arr[i];
        }

        int[] answer = ListToArray(result);

        return result;
    }
}