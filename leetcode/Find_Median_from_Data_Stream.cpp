// ────────────────────────────────────────────────────────────
// Problem : Find Median from Data Stream
// Platform: LeetCode
// URL     : https://leetcode.com/problems/find-median-from-data-stream/submissions/2068696178/
// Language: cpp
// Date    : 7/15/2026, 7:39:55 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(??)
// Space Complexity: O(??)
// ────────────────────────────────────────────────────────────

class MedianFinder {
public:
priority_queue<int> left_max_heap;
priority_queue<int,vector<int>,greater<int>> ryt_min_heap;
    MedianFinder() {
    }
    void addNum(int num) {
        if(left_max_heap.empty()||num<left_max_heap.top()){
            left_max_heap.push(num);
        }
        else{
            ryt_min_heap.push(num);
        }
        //left can b 1 more than ryt 
        if(abs((int)left_max_heap.size()-(int)ryt_min_heap.size())>1){
            ryt_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
        else if(left_max_heap.size()<ryt_min_heap.size()){
            left_max_heap.push(ryt_min_heap.top());
            ryt_min_heap.pop();
        }
    }
    
    double findMedian() {
        if(left_max_heap.size()==ryt_min_heap.size()){
            double mean=(left_max_heap.top()+ryt_min_heap.top())/2.0;
            return mean;
        }else{
            return left_max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */