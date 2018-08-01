#include<cstdio>
void getNext(char *pattern,int *next){
	next[0] = -1;
	int k=-1,j=0;
	while(pattern[j]){
		if(k==-1 || pattern[k] == pattern[j]){
			j++,k++;
			next[j] = k;
		}else{k=next[k];}
	}
}
int main()
{
	char pattern[] = "ababc";
	int next[20];
	getNext(pattern,next);
	for(int i=0;pattern[i];++i)
		printf("%d ", next[i]);
	char str[] = "abeababcdaabcaaabaaccdaabababacda";
	int j(0),k(0);
	while(pattern[k]&&str[j]){
		if(next[k] == -1 || pattern[k] == str[j]){
			k++,j++;
		}else{
			k = next[k];
		}
	}
	if(!pattern[k]){
		printf("\n%d\n",j-k);
	}else{
		printf("0\n");
	}
}
