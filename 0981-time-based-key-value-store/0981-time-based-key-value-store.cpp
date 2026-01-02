class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<string,int>>>mp;
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }
        vector<pair<string,int>>& arr=mp[key];
        int l=0;
        int r = arr.size() - 1;
        string ans = "";
        while(l<=r){
            int mid=l+(r-l)/2;
            string value=arr[mid].first;
            int time=arr[mid].second;
            if(time<=timestamp){
                ans=value;
                l=mid+1;
            } 
            else r=mid-1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */