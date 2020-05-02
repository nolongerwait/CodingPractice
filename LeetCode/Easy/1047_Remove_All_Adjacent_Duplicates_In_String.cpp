class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> tmp;
        for(auto chr:S) {
            if(tmp.empty()) {
                tmp.push(chr);
            }
            else {
                if(chr == tmp.top()) {
                    tmp.push(chr);
                    tmp.pop();
                    tmp.pop();
                }
                else {
                    tmp.push(chr);
                }
            }
        }
        string res = "";
        while(!tmp.empty()) {
            res += tmp.top();
            tmp.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};