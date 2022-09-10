# Поиск образца в тексте

pattern, text = input(), input()
p = len(pattern)
needed, current = sum(ord(c) for c in pattern), sum(ord(c) for c in text[:p])
for i in range(len(text) - p + 1):
    if needed == current and pattern  == text[i:i+p]:
        print(i, sep=' ')
    current += ord(text[(i+p) % len(text)]) - ord(text[i])
