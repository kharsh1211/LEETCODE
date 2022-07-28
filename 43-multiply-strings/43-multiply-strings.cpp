class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 =="0" ) return "0";
        int n1 = num1.size(), n2 = num2.size(), n = n1+n2;
        string ans(n, '0');
        for(int p2 = n2-1; p2 >= 0; p2--){
            int d2 = num2[p2] - '0';
            for(int p1 = n1-1; p1 >= 0; p1--){
                int d1 = num1[p1] - '0', p = p1 + p2 + 1, c = ans[p] - '0', m = d1 * d2 + c;
                ans[p] = (m % 10) + '0';
                ans[p-1] += (m / 10);
            }
        }
        if(ans.front() == '0') ans.erase(ans.begin());
        return ans;
    }
};