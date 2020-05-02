class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,pair<int,int>>> p;

        for(int i=0;i<points.size();i++)
        {
            int dis=pow(points[i][0],2)+pow(points[i][1],2);
            if(k>0)
            {
                p.push(make_pair(dis,make_pair(points[i][0],points[i][1])));
                k--;
            }
            else if(k==0)
            {
                pair<int,pair<int,int>> temp=p.top();
                if(temp.first>dis)
                {
                    cout<<points[i][0]<<"-"<<points[i][1]<<endl;
                    p.pop();
                    p.push(make_pair(dis,make_pair(points[i][0],points[i][1])));
                }
            }
        }
        //cout<<p.size()<<" ";
        vector<vector<int>> v;
        pair<int,pair<int,int>> temp;
        while(!p.empty())
        {
            temp=p.top();
            p.pop();
            //cout<<p.size()<<" ";
            vector<int> v1;
            v1.push_back((temp.second).first);
            v1.push_back((temp.second).second);
            v.push_back(v1);
        }
        //cout<<p.size();
        return v;
    }
};
