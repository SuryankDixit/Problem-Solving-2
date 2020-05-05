
/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

*/
class Solution {
public:
    string defangIPaddr(string address) {
        string s="";
        for(int i=0;i<address.size();i++)
        {
            if(address[i]=='.')
            {
                s=s+"[.]";
            }
            else
                s=s+address[i];
        }
        return s;
        //return regex_replace(address, regex("[.]"), "[.]");
        // regex method is slower and i need to learn about regexe.
    }
};