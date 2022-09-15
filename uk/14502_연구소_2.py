import time
import copy
from collections import deque
global start
global answer
answer=[]

def comb(idx,cnt,list,end):# 조합
    global answer
    if cnt == 3:
        answer.append(list)
        return
    for i in range(idx,end):
        comb(i+1,cnt+1,list+[i],end)


def solv(map):
    virus = []
    coll= []
    global answer

    dy=[1,-1,0,0]
    dx=[0,0,-1,1]
    for i in range(len(map)):
        for j in range(len(map[0])):
            if map[i][j]==0:
                coll.append([i,j])
            if map[i][j]==2:
                virus.append([i,j])

    comb(0,0,[],len(coll))#Find Combination


    max_val=0

    y_over=len(map)
    x_over=len(map[0])
    for x,y,z in answer:
        cnt =0
        c_map = [it[:] for it in map]

        ai,aj=coll[x]
        bi,bj=coll[y]
        ci,cj = coll[z]

        c_map[ai][aj] = 1
        c_map[bi][bj] = 1
        c_map[ci][cj] = 1
        q=deque()
        for i,j in virus:
            q.append([i,j])

        while(q):
            y,x=q.popleft()
            for i in range(4):
                g_y=y+dy[i]
                g_x=x+dx[i]

                if(g_y>=y_over or g_x >=x_over or g_y<0 or g_x < 0):
                    continue
                if c_map[g_y][g_x]==0:
                    c_map[g_y][g_x]=2
                    q.append([g_y,g_x])

        for i in range(y_over):
            for j in range(x_over):
                if c_map[i][j] == 0:
                    cnt+=1
        max_val=max(cnt,max_val)




    print(max_val)

if __name__=="__main__":
    global start
    #start = time.time()
    n,m= map(int,input().split())

    mp= [list(map(int,input().split())) for _ in range(n)]
    solv(mp)