"""
어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return
"""

def solution(phone_book):
    phone_book.sort()
    for i, phone in enumerate(phone_book):
        if i == len(phone_book) - 1:
            return True
        if phone_book[i+1].startswith(phone):
            return False