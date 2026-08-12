class Solution {
    public String solution(String number, int k) {

        StringBuilder sb = new StringBuilder();
        char[] numArr = number.toCharArray();

        int idx = 0;
        for(int i=0; i<numArr.length-k; i++) {
            char max = '0';
            for(int j=idx; j<=i+k; j++) {
                if(max < numArr[j]) {
                    max = numArr[j];
                    idx = j+1;
                }
            }
            sb.append(max);
        }

        return sb.toString();
    }
}