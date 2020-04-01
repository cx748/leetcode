/*
给定一个只包括各种括号的字符串，判断字符串是否有效
*/

//借助栈的数据结构，碰到左括号则进栈，遇到右括号，则与栈顶元素比较，如果匹配则出栈
//否则return false
#include<string>
#include <stack>
using std::string;
using std::stack;
class Solution {
public:
    bool isValid(string s){
        if(s.length()%2 != 0) return false; //如果长度为奇数，false
        stack<char> mystack;
        for(char &c : s){
            if( c=='(' || c == '[' || c == '{')
                mystack.push(c); //压入栈中
            else{
                if(mystack.empty()) return false;
                if(c == ')' && mystack.top() != '(') return false;
                if(c == ']' && mystack.top() != '[') return false;
                if(c == '}' && mystack.top() != '{') return false;
                mystack.pop(); //匹配成功出栈
            }
        }
        return mystack.empty();
    }
};
