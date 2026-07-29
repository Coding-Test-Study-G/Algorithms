import java.util.*;

class Solution {
    boolean solution(String s) {
        char[] arr = s.toCharArray();
        Stack<Character> stack = new Stack<>();
        for(char str : arr) {
            if(str == ')') {
                if(stack.isEmpty()) {
                    return false;
                } else {
                    stack.pop();
                }
            } else {
                stack.push(str);
            }
        }
        if(!stack.isEmpty()) {
            return false;
        }
        return true;
    }
}