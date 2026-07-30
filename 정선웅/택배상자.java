import java.util.*;

class Solution {
    public int solution(int[] order) {
        Stack<Integer> temporaryBelt = new Stack<>();
        int count =0;

        for(int box=1; box <= order.length; box++) {
            temporaryBelt.push(box);

            while(!temporaryBelt.isEmpty() && temporaryBelt.peek() == order[count]) {
                temporaryBelt.pop();
                count++;
            }
        }
        return count;
    }
}