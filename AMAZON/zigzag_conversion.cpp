
/*
6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

class Solution {
public:
    string convert(string s, int numRows) {
        
        if(s.size()==1 || numRows==1)
            return s;
        
        vector<string> v(numRows);
        bool flag=false;
        int temp=0;
        for(int i=0;i<s.size();i++)
        {
            v[temp]+=s[i];
            if(temp==0 || temp==numRows-1)
                flag=!flag;
            if(flag)
                temp++;
            else
                temp--;
        }
        string str;
        for(int i=0;i<v.size();i++)
            str+=v[i];
        return str;
    }
};