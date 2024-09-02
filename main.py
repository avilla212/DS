s = "Hello"

count = {}
for char in range(len(s)):
    count[s[char]] = 1 + count.get(s[char], 0) 

print(count)