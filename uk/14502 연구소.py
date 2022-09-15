from collections import deque

global max_val
max_val = 0


def find_max(x, y):
    if x > y:
        return x
    else:
        return y


def virus(map, v_pos):
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    dq = deque()
    cp_map = [[0] * len(map[0]) for _ in range(len(map))]
    cnt = 0
    for i in range(len(map)):
        for j in range(len(map[0])):
            cp_map[i][j] = map[i][j]

    for i in range(len(v_pos)):
        dq.append([v_pos[i][0], v_pos[i][-1]])
    while (dq):
        vi_pos = dq.popleft()
        for i in range(4):
            go_y = vi_pos[0] + dy[i]
            go_x = vi_pos[1] + dx[i]

            if (go_y >= len(map) or go_x >= len(map[0])):
                continue
            if (go_y < 0 or go_x < 0):
                continue
            # print('{} {}'.format(go_y,go_x))
            if (cp_map[go_y][go_x] == 0):
                cp_map[go_y][go_x] = 2
                dq.append([go_y, go_x])
    for i in range(len(map)):
        for j in range(len(map[0])):
            if cp_map[i][j] == 0:
                cnt += 1

    return cnt


def gid(v_pos, map, cnt):
    # 2-d dfs? how? idx?1차원 idx?
    global max_val
    # dfs 3개찾으면됨 nC3
    if cnt == 3:
        # print('------------------------')
        # for i in range(7):
        versus = virus(map, v_pos)
        max_val = find_max(max_val, versus)

        return
    for i in range(len(map)):
        for j in range(len(map[0])):
            if map[i][j] == 0:
                map[i][j] = 1
                gid(v_pos, map, cnt + 1)
                map[i][j] = 0

    # virus bfs


def solve(map, v_pos):
    global max_val
    gid(v_pos, map, 0)
    # 다퍼진 바이러스나오고 찾아보자~
    print(max_val)


if __name__ == "__main__":
    n, m = map(int, input().split())
    map = [list(map(int, input().split())) for _ in range(n)]
    v_pos = []
    for i in range(len(map)):
        for j in range(len(map[0])):
            if map[i][j] == 2:
                v_pos.append([i, j])

    solve(map, v_pos)
