#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct DicTree;
DicTree*root;

inline bool allZero(int n,char*s){
    for(int i=0;i<n;++i)if(s[i]=='1')return false;
    return true;
}
struct DicTree
{
	DicTree *zero,*one;
	int occurence;
	DicTree():zero(NULL),one(NULL),occurence(0){}

	void insert(char*s){
		int i=0;
		DicTree *cur = root;
		while(s[i])++i;--i;
		while(i>=0){
			//parity condition
			if((s[i]-'0')%2){
				if(cur->one == NULL){
					cur->one = new DicTree();
				}
				cur = cur->one;
			}else{//even condition
				if(cur->zero == NULL){
					cur->zero = new DicTree();
				}
				cur = cur->zero;
			}
			--i;
		}
		cur->occurence++;
	}
	void remove(char*s){
		int i=0;
		DicTree *cur = root;
		while(s[i])++i;--i;
		while(i>=0){
			//parity condition
			if((s[i]-'0')%2){
				if(cur->one == NULL){
					cur->one = new DicTree();
				}
				cur = cur->one;

			}else{//even condition
				if(cur->zero == NULL){
					cur->zero = new DicTree();
				}
				cur = cur->zero;
			}
			--i;
		}
		cur->occurence--;
	}
	int query(char*s){
		int i=0;
		int res = 0;
		DicTree *cur = root;
		while(s[i])++i;--i;
		while(i>=0){
			//parity condition
			if((s[i]-'0')%2){
				if(cur->one == NULL){
					return 0;
				}
				cur = cur->one;
			}else{//even condition
				if(cur->zero == NULL){
					for(int j = 0;j<i;++j)if(s[j] == '1')return 0;
					while(cur){
						res+=cur->occurence;
						cur = cur->zero;
					}
					return res;
				}
				if(cur->occurence){
					if(allZero(i,s))res+=cur->occurence;
				}
				cur = cur->zero;
			}
			--i;
		}
		while(cur){
			res+=cur->occurence;
			cur = cur->zero;
		}
		return res;
	}
};

int main()
{
	int n,ans;
	char choice[5],number[20];
	root = new DicTree();
	cin>>n;
	while(n--){
		scanf("%s%s",choice,number);
		switch(choice[0]){
			case '+':root->insert(number);break;
			case '-':root->remove(number);break;
			case '?':
				ans = root->query(number);
				printf("%d\n",ans);
				break;
			default:break;
		}
	}
	return 0;
}
