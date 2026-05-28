class MedianFinder {
private:
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
public:
    MedianFinder() = default;
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top()+minHeap.top())/2.0;
        
    }
};
