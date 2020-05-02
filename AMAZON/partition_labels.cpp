//Commented code is the first attempt given to the code which is a little bit slow.
// Second code works like a charm.

class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        /*
        
        vector<int> v;
        if(S.size()==1)
      
        {
            v.push_back(1);
            return v;
        }
        unordered_map<char,pair<int,int>> m;
        for(int i=0;i<S.size();i++)
        {
            auto it=m.find(S[i]);
            if(it==m.end())
                m[S[i]]={i,i};
            else
                it->second.second=i;
        }
        
        pair<int,int> temp;
        pair<int,int> range;
        
        for(int i=0;i<S.size();i++)
        {
            auto it=m.find(S[i]);
            if(it==m.end()) continue;
            if(i==0)
            {
                cout<<it->first<<"-"<<it->second.first<<","<<it->second.second<<endl;
                range.first=it->second.first;
                range.second=it->second.second;
                m.erase(it);
            }
            else if(i!=0 && it!=m.end())
            {
                cout<<it->first<<"-"<<it->second.first<<","<<it->second.second<<endl;
                temp.first=it->second.first;
                temp.second=it->second.second;
                if(temp.first>range.second)
                {
                    v.push_back(range.second-range.first+1);
                    range=temp;
                }
                else if(temp.first>range.first && temp.second<range.second)
                    continue;
                else if(temp.second>range.second && temp.first <range.second)
                    range.second=temp.second;
                
                 m.erase(it);
            }
        }
        v.push_back(range.second-range.first+1);
        return v;
        
        */
        
         vector<int> charIdx(26, 0);
        for(int i = 0; i < S.size(); i++){
            charIdx[S[i]-'a'] = i;          // storing the last occurance of each character'
        }
        
        vector<int> results;
        
        int maxIdx = -1, lastIdx = 0;
        for(int i = 0; i < S.size(); i++){
            maxIdx = max(maxIdx, charIdx[S[i]-'a']);  // we know the ast occurance of each character
            if(i == maxIdx) {                  
                results.push_back(maxIdx - lastIdx + 1);
                lastIdx = i+1;
            }
        }
        return results;
    }
};
