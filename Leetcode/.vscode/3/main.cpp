/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0, L = -1, R = 0, len = s.length();
        vector<int> exist(26, 0);
        exist[s[0] - 'a'] = 1;
        while (R < len){
            if (L == len-1) 
                return max_length; 
            if (L == -1) L++; else exist[s[L++] - 'a'] = 0;
            while (R+1<len && (!exist[s[R+1] - 'a'])) exist[s[++R] - 'a'] = 1;
            max_length = max(max_length, R-L+1);
        }
        return max_length;
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    Solution prob;
    string s;
    cin >> s;
    int ans = prob.lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}
// @lc code=end

