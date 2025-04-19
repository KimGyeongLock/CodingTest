def find(a) :
    if a != parent[a] :
        parent[a] = find(parent[a])
    return parent[a]

def union(a, b) :
    a = find(a)
    b = find(b)
    if (a != b) :
        parent[b] = a

n, m = map(int, input().split())
parent = [i for i in range(n + 1)]

for _ in range(m) :
    cmd, a, b = map(int, input().split())
    if cmd == 0 :
        union(a, b)
    elif cmd == 1 :
        if find(a) == find(b) :
            print("YES")
        else :
            print("NO")