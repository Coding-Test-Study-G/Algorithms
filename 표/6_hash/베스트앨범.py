def solution(genres, plays):
    answer = []
    hash_table = {}
    hash_g = {}
    
    for i, (genre, play) in enumerate(zip(genres, plays)):
        if genre not in hash_table:
            hash_table[genre] = []
        hash_table[genre].append((i, play))
        if genre not in hash_g:
            hash_g[genre] = 0
        hash_g[genre] += play
    
    sorted_genres = sorted([(g, p) for g, p in hash_g.items()], key=lambda x: x[1], reverse=True)
    
    for genre, play in sorted_genres:
        sorted_songs = sorted(hash_table[genre], key=lambda x: (-x[1], x[0]))
        for num, p in sorted_songs[:2]:
            answer.append(num)
        
    return answer