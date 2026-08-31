import java.util.*;

class Solution {

    public int[] parent;
    class Node {
        int a;
        int b;
        int edge;

        public Node(int nodeA, int nodeB, int edge) {
            this.a = nodeA;
            this.b = nodeB;
            this.edge = edge;
        }
    }

    public int find(int node) {
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    public boolean union(int a, int b) {
        int nA = find(a);
        int nB = find(b);

        if(nA == nB) return false;

        parent[nA] = nB;
        return true;
    }

    public int solution(int n, int[][] costs) {
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator
                .comparing(
                        node -> node.edge
                ));

        parent = new int[n+1];
        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }

        for(int[] cost : costs) {
            pq.offer(new Node(cost[0],cost[1],cost[2]));
        }

        int sum = 0;
        while(!pq.isEmpty()) {
            Node node = pq.poll();
            if(union(node.a, node.b)){
                sum += node.edge;
            }
        }
        return sum;
    }
}