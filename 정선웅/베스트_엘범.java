import java.util.*;

class Solution {
    class Song {
        int id;
        String genre;
        int plays;
        int sumPlays;

        public Song(int id, String genre, int plays, int sumPlays){
            this.id = id;
            this.genre = genre;
            this.plays = plays;
            this.sumPlays = sumPlays;
        }
    }

    public int[] solution(String[] genres, int[] plays) {
        PriorityQueue<Song> pq = new PriorityQueue<>(
                Comparator.<Song, Integer>comparing(s -> s.sumPlays)
                        .reversed()
                        .thenComparing(
                                Comparator.<Song, Integer>comparing(s-> s.plays).reversed())
                        .thenComparing(s -> s.id));

        Map<String, Integer> playsSum = new HashMap<>();

        for(int i=0; i<genres.length; i++) {
            playsSum.put(
                    genres[i], playsSum.getOrDefault(genres[i],0) + plays[i]
            );
        }

        for(int i=0; i<genres.length; i++) {
            Song song = new Song(i, genres[i], plays[i], playsSum.get(genres[i]));
            pq.offer(song);
        }

        List<Integer> result = new ArrayList<>();
        Map<String, Integer> genreCount = new HashMap<>();

        while (!pq.isEmpty()) {
            Song song = pq.poll();
            int count = genreCount.getOrDefault(song.genre, 0);
            if (count < 2) {
                result.add(song.id);
                genreCount.put(song.genre, count + 1);
            }
        }
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}