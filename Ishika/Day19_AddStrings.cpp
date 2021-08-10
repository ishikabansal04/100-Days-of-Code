// Problem Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3875/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size()-1;
        int len2 = num2.size()-1;
        int i=len1, j=len2;
        int curr = 0;
        int carry = 0;
        string res="";
        while(i>=0 && j>=0){
            curr += num1[i]-'0';
            curr += num2[j]-'0';
            curr += carry;
            carry = carry/10;
            carry+= curr/10;
            curr = curr%10;
            res += to_string(curr);
            curr = 0;
            i--;
            j--;
        }
        while(i>=0){
            curr += num1[i]-'0';
            curr += carry;
            carry = carry/10;
            carry+= curr/10;
            curr = curr%10;
            res += to_string(curr);
            curr = 0;
            i--;
        }
        while(j>=0){
            curr += num2[j]-'0';
            curr += carry;
            carry = carry/10;
            carry+= curr/10;
            curr = curr%10;
            res += to_string(curr);
            curr = 0;
            j--;
        }
        while(carry){
            res+= to_string(carry%10);
            carry/=10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};