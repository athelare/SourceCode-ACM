#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;
int main()
{
    int n,i;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        for (i = 0; i < s.length();++i){
            if(s[i] == '?'){
                if(i>0 && s[i-1] == '0'){
                    s[i] = '+';
                    for (int j = i - 1; j >= 0&& s[j]!='+'&& s[j]!='*'; --j)
                    {
                        if(s[j]>='1'&&s[j]<='9'){
                            s[i] = '1';
                            break;
                        }
                    }
                }
                else s[i] = '1';
            }
        }
        bool flag = true;
        if(s[0]=='+' || s[0] == '*' || s[s.length()-1]=='+'||s[s.length()-1]=='*' )
            flag = false;
        i = 0;

        while(i<s.length() && flag){
            if(isdigit(s[i]) && s[i] != '0'){
                while(isdigit(s[i]))
                    i++;
            }
            if(s[i]=='0' &&i<s.length()-1 && s[i+1]>='0'&&s[i+1]<='9'){
                flag = false;
                break;
            }else if(i<s.length()-1 && (s[i] == '+' || s[i] =='*')&&(s[i+1] == '+' || s[i+1] =='*')){
                flag = false;
                break;
            }
            ++i;
        }
        if(flag)
            cout << s << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}