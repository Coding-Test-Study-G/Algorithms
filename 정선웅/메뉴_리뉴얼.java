import java.util.*;
class Solution {

    static List<String> combi;
    public String[] solution(String[] orders, int[] course) {
        String[] answer = {};

        combi = new ArrayList<>();
        for(int i=0; i<orders.length; i++) {
            String[] one = orders[i].split("");
            Arrays.sort(one);

            for(int j=0; j< one.length-1; j++) {
                for(int k=0; k< course.length; k++) {
                    dfs(one, j, 1, course[k], one[j]);
                }
            }
        }

        Map<String , Integer> map = new HashMap<>();
        for(String menu : combi) {
            map.put(menu, map.getOrDefault(menu, 0)+1);
        }


        List<String> list = new ArrayList<>(map.keySet());
        Collections.sort(list, new Comparator<String>() {

            @Override
            public int compare(String o1, String o2) {
                return map.get(o2)-map.get(o1);
            }
        });


        List<String> res = new ArrayList<>();
        for(int i=0; i< course.length; i++) {
            int max =0;

            for(String courseMenu : list) {
                if(map.get(courseMenu)>1 && courseMenu.length() == course[i]) {
                    if(map.get(courseMenu) >= max) {
                        res.add(courseMenu);
                        max = map.get(courseMenu);
                    }
                }
            }
        }

        Collections.sort(res);

        answer = new String[res.size()];
        res.toArray(answer);


        return answer;
    }


    static void dfs(String[] one, int idx, int len, int courseLen, String str) {
        if(len == courseLen) {
            combi.add(str);
        }

        for(int i= idx+1; i<one.length; i++) {
            dfs(one, i, len+1, courseLen, str+one[i]);
        }
    }
}