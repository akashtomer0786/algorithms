//O(log(n)) insert and O(1) Query
class MedianFinder {
public:
    /** initialize your data structure here. */
        ///max queue
    priority_queue<int> small;
    ///min  queue
    priority_queue<int,vector<int>,greater<int>> large;

    
    void addNum(int num) {
                if(small.empty()||small.top()>num){
            small.push(num);
        }
        else{
            large.push(num);
        }
        if(small.size()>large.size()+1){
            large.push(small.top());
            small.pop();
        }
        if(large.size()>small.size()+1){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
            if(small.size()==large.size()){
             return 1.0*(small.top()+large.top())/2;
            }
         else{
             return small.size()>large.size()?small.top():large.top();
         }
    }
};
