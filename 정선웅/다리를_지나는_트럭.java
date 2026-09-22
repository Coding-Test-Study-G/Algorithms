import java.util.*;

class Solution {
    class Truck {
        int weight;
        int moveLength;

        public Truck(int weight){
            this.weight = weight;
            this.moveLength = 1;
        }

        public void move() {
            this.moveLength++;
        }
    }

    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<Truck> waitQueue = new LinkedList<>();
        Queue<Truck> crossQueue = new LinkedList<>();

        int curWeightSum = 0;
        int time = 0;

        for(int truck_weight : truck_weights) {
            waitQueue.offer(new Truck(truck_weight));
        }

        while(!waitQueue.isEmpty() || !crossQueue.isEmpty()) {

            time++;

            if(crossQueue.isEmpty()) {
                Truck truck = waitQueue.poll();
                crossQueue.offer(truck);
                curWeightSum += truck.weight;
                continue;
            }

            for(Truck crossTruck : crossQueue) {
                crossTruck.move();
            }

            if(crossQueue.peek().moveLength > bridge_length) {
                Truck t = crossQueue.poll();
                curWeightSum -= t.weight;
            }

            if(!waitQueue.isEmpty() &&
                    curWeightSum + waitQueue.peek().weight <= weight) {
                Truck truck = waitQueue.poll();
                crossQueue.offer(truck);
                curWeightSum += truck.weight;
            }

        }
        return time;
    }
}