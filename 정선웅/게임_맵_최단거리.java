import java.util.*;

class Solution {
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static boolean[][] visited;

    public boolean isValidIdx(int nx, int ny, int[][]graph) {
        if(nx >= 0 && nx < graph[0].length && ny >= 0 && ny < graph.length) {
            if(graph[ny][nx] == 1){
                return !visited[ny][nx];
            }
        }
        return false;
    }

    public boolean isGoal(int nx, int ny, int xLimit, int yLimit) {
        return nx==xLimit && ny==yLimit;
    }

    class Node {
        int x;
        int y;
        int count;

        public Node(int x, int y, int count) {
            this.x = x;
            this.y = y;
            this.count = count;
        }

        public int getCount() {
            return this.count;
        }

    }

    public int bfs(Node node, int[][] graph) {
        Queue<Node> queue = new LinkedList<>();
        visited[node.y][node.x] = true;
        queue.offer(node);
        while(!queue.isEmpty()) {
            Node newNode = queue.poll();
            for(int i=0; i<4; i++) {
                int nx = newNode.x + dx[i];
                int ny = newNode.y + dy[i];
                if(isValidIdx(nx,ny,graph)){
                    visited[ny][nx] = true;
                    if(isGoal(nx, ny, graph[0].length-1, graph.length-1))
                        return newNode.getCount()+1;
                    queue.offer(new Node(nx,ny, newNode.getCount()+1));
                }
            }
        }
        return -1;
    }

    public int solution(int[][] maps) {
        visited = new boolean[maps.length][maps[0].length];
        for(int i=0; i<maps.length; i++) {
            Arrays.fill(visited[i],false);
        }
        return bfs(new Node(0,0,1), maps);
    }
}