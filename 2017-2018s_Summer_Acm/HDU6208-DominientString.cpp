#include<string>
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> >Next;
vector<int>mxi;
int mxlen;
int N;

void getNext(string pat,vector<int>& nex){
    int k=-1,j=0,lens = pat.size();
    nex.push_back(-1);
    while(j<lens && k<lens){
        if(k == -1 || pat[k] == pat[j]){
            ++k,++j;
            nex.push_back(k);
        }else{
            k = nex[k];
        }
    }
}
bool kmp(string s,string p,vector<int> nex){
    int lens =  s.length(),lenp = p.length(),i=0,j=0;
    while(i<lens && j<lenp){
        if(j == -1 || s[i] == p[j]){
            j++,i++;
        }else{
            j = nex[j];
        }
    }
    return j == lenp;
}
void solve(const vector<string>& text)
{
    bool flag;
    for(int i=0;i<N;++i)getNext(text[i],Next[i]);
    for(vector<int>::iterator it = mxi.begin();it != mxi.end();++it){
        flag =true;
        for(int i=0;flag && i<N;++i){
            if(i == *it)continue;
            flag = kmp(text[*it],text[i],Next[i]);
        }
        if(flag){
            cout<<text[*it]<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>N;
        vector<string>Text (N);
        Next.resize(N+1);
        mxlen = 0;
        for(int i=0;i<N;++i){
            cin>>Text[i];
            
            if(Text[i].length()>mxlen){
                mxlen = Text[i].length();
                mxi.clear();
                mxi.push_back(i);
            }else if(Text[i].length() == mxlen){
                mxi.push_back(i);
            }
        }
        solve(Text);
        Text.clear();
        Next.clear();
        mxi.clear();
    }
    return 0;
}