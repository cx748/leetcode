/*
给你一个有效括号字符串 seq，请将其分成两个不相交的有效括号字符串 A 和 B，并且
使这两个字符串的深度最小。

不相交：每个 seq[i] 只能分给 A 和 B 二者中的一个，不能既属于 A 也属于 B 。
A 或 B 中的元素在原字符串中可以不连续。
A.length + B.length = seq.length
max(depth(A), depth(B)) 的可能取值最小。
划分方案用一个长度为 seq.length 的答案数组 answer 表示，编码规则如下：

answer[i] = 0，seq[i] 分给 A 。
answer[i] = 1，seq[i] 分给 B 。
如果存在多个满足要求的答案，只需返回其中任意 一个 即可。

*/

//题目要求max(depth(A), depth(B)) 的可能取值最小。实际上是相当于让A的字符串和B的字符串
//的depth尽可能的接近，因为seq对应的栈上，每个括号都有一个深度，问这个左括号，要么是A的
//要么是B的，所以栈上的左括号只要平分给AB就行,我们可以采取奇数分配。
#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution{
public:
    vector<int> maxDepthAfterSpilt(string seq){
        int d = 0;
        vector<int> ans;
        for(char& c : seq){
            if (c == '('){
                ++d;
                ans.push_back(d % 2);
            }
            else{
                ans.push_back(d % 2);
                --d;
            }
        }
        return ans;
    }
};