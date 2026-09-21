/*
[접근]

1. 객체({})로 장르별 총 재생 수(genreTotal)랑 [고유번호, 재생수] 배열(playList)에 담기
2. 총 재생 수 큰 장르순으로 정렬 (내림차순)
3. 장르별로 곡 정렬
   - 재생수 다르면 재생수 큰 순
   - 재생수 같으면 고유번호 작은 순
4. slice(0, 2)로 2개씩만 잘라서 answer에 고유번호 push
*/

function solution(genres, plays) {
  var answer = [];

  const genreTotal = {};
  const playList = {};

  genres.forEach((genre, index) => {
    if (!genreTotal[genre]) {
      genreTotal[genre] = 0;
      playList[genre] = [];
    }
    genreTotal[genre] += plays[index];
    playList[genre].push([index, plays[index]]);
  });

  // 장르 => 재생 횟수 기준 내림차순 정렬
  const sortedGenres = Object.keys(genreTotal).sort((a, b) => genreTotal[b] - genreTotal[a]);

  // 정렬된 장르 => 곡 정렬 & 상위 2개 추출
  sortedGenres.forEach((genre) => {
    const songs = playList[genre];

    // 곡 정렬: 재생수 내림차순, 같다면 고유번호 오름차순
    songs.sort((a, b) => {
      if (b[1] !== a[1]) {
        return b[1] - a[1];
      }
      return a[0] - b[0];
    });

    // 상위 최대 2개의 고유번호 push
    songs.slice(0, 2).forEach((song) => {
      answer.push(song[0]);
    });
  });

  return answer;
}
