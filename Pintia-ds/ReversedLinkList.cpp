#include<stdio.h>

int main()
{
    int Start, N, K;
    int Mem[100005], next[100005];
    int addr, data, nexta;
    scanf("%d%d%d", &Start, &N, &K);
    while (N--)
    {
        scanf("%d%d%d", &addr, &data, &nexta);
        Mem[addr] = data;
        next[addr] = nexta;
    }
    int flag = 1, head, cur_tail,last_tail, p, q, firstElem, t;
    last_tail = head = -1;
    p = q = Start;
    t = 0;
    while(1){
        cur_tail = p;
        for (int i = 0, cur = p; i < K; ++i)
        {
            if(cur == -1)
                flag = 0;
            cur = next[cur];
        }
        if(!flag){
            next[last_tail] = p;
            break;
        }
        for (int i = 0; i < K; ++i)
        {
            q = next[p];
            next[p] = head;
            head = p;
            p = q;
        }
        if(t++ == 0){
            firstElem = head;
        }
        else{
            next[last_tail] = head;
        }
        last_tail = cur_tail;
        head = -1;
    }
    int cur = firstElem;
    while(cur!=-1){
        if(next[cur] == -1){
            printf("%05d %d -1\n", cur, Mem[cur]);
        }else
            printf("%05d %d %05d\n", cur, Mem[cur], next[cur]);
        cur = next[cur];
    }
    return 0;
}
