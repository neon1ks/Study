n = int(input())
possible = set(range(1, n + 1))
s = input().strip()
while s != 'HELP':
    nums = set(map(int, s.split()) 
    s = input().strip()
    if s == 'YES':
        possible.intersection_update(nums)
    else:
        possible.difference_update(num)
    s = input().strip()
print(possible)
#dd
