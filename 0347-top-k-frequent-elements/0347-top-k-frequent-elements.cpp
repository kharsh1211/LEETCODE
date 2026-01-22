struct Compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num : nums) mp[num]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        
        for(auto& p : mp) {
            pq.push({p.first, p.second});
        }
        
        vector<int> result;
        while(k-- > 0) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};
