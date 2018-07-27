#include<cstdio>
int main(){
    char name[20];
    int n,count;
    while(~scanf("%d",&n)){
        count = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", name);
            switch(name[0]){
                case 'T':
                    count += 4;
                    break;
                case 'C':
                    count += 6;
                    break;
                case 'O':
                    count += 8;
                    break;
                case 'D':
                    count += 12;
                    break;
                case 'I':
                    count += 20;
                    break;
                    }
        }
        printf("%d", count);
    }
    return 0;
}
