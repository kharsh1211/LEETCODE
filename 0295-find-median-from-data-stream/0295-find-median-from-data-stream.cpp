class MedianFinder {
public:
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
    MedianFinder() {
        return;
    }
    
    void addNum(int num) {
        if(pq1.empty()) pq1.push(num);
        else if(num<pq1.top()) pq1.push(num);
        else pq2.push(num);

        if(pq2.size()>pq1.size()){
            int temp=pq2.top();
            pq2.pop();
            pq1.push(temp);
        }
        else if(pq1.size()>pq2.size()+1){
            int temp=pq1.top();
            pq1.pop();
            pq2.push(temp);
        }
    }
    
    double findMedian() {
        if((pq1.size()+pq2.size())%2!=0){
            return pq1.top();
        }
        else{
            return double(pq1.top()+pq2.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */