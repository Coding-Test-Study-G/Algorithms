import java.util.*;

class Solution {
    public int shiftUpDown(char c) {
        int num = (int) c;
        if(num <= 77) {
            return Math.abs(num - 65);
        } else {
            return Math.abs(91 - num);
        }
    }

    public int solution(String name) {
        int answer = 0;
        int length = name.length();

        // 기본 최대 이동 횟수는 그냥 오른쪽으로 끝까지 쭉 가는 경우
        int minMove = length - 1;

        for (int i = 0; i < length; i++) {
            // 1. 알파벳 변경 횟수 누적
            answer += shiftUpDown(name.charAt(i));

            // 2. 현재 위치 i 다음부터 연속된 'A'의 끝자리를 찾음
            int nextIdx = i + 1;
            while (nextIdx < length && name.charAt(nextIdx) == 'A') {
                nextIdx++;
            }

            // 3. 좌우 이동 최소 거리 계산 (3가지 경로 중 최솟값 비교)
            // i * 2 + (length - nextIdx) : 오른쪽 갔다가 빽해서 왼쪽으로
            // (length - nextIdx) * 2 + i : 왼쪽 먼저 갔다가 빽해서 오른쪽으로
            minMove = Math.min(minMove, i * 2 + (length - nextIdx));
            minMove = Math.min(minMove, (length - nextIdx) * 2 + i);
        }

        return answer + minMove;
    }
}
