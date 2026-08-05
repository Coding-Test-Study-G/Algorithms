import java.util.*;

class Solution {
    boolean[] usedTickets;
    PriorityQueue<String> nodes = new PriorityQueue<>(Comparator.naturalOrder());
    String[] results;
    public void dfs(int depth, String from, String[][] tickets, String course) {
        if(tickets.length == depth){
            nodes.offer(course);
            return;
        }

        for(int i=0; i<tickets.length; i++) {
            if(!usedTickets[i] && tickets[i][0].equals(from)) {
                usedTickets[i] = true;
                dfs(depth + 1, tickets[i][1], tickets, course+ " " + tickets[i][1]);
                usedTickets[i] = false;
            }
        }
    }

    public String[] solution(String[][] tickets) {
        usedTickets = new boolean[tickets.length];
        dfs(0, "ICN", tickets, "ICN");
        String s = nodes.poll();
        results = s.split(" ");
        return results;
    }
}