# Построение кучи

size = int(input())
H = [int(x) for x in input().split()]
ans = []


def siftDown(i):
    max_index = i

    left = 2 * i + 1
    if left < size and H[left] < H[max_index]:
        max_index = left

    right = 2 * i + 2
    if right < size and H[right] < H[max_index]:
        max_index = right

    if i != max_index:
        H[i], H[max_index] = H[max_index], H[i]

        ans.append({i, max_index})
        siftDown(max_index)


for j in range((size - 1) // 2, -1, -1):
    siftDown(j)

print(len(ans))
for f, s in ans:
    print(f, s)
