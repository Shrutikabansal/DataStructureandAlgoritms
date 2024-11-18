class MedianFinder {
public:

    priority_queue<int> pqMax;
    priority_queue<int, vector<int> , greater<int> > pqMin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(pqMin.size() == pqMax.size()){
            if(!pqMin.empty() && num > pqMin.top() ){
                pqMax.push(pqMin.top());
                pqMin.pop();
                pqMin.push(num);
            }else{
                pqMax.push(num);
            }
        }else{
            if(num > pqMax.top()){
                // pqMax.push(pqMin.top());
                // pqMin.pop();
                pqMin.push(num);
            }else{

                pqMin.push(pqMax.top());
                pqMax.pop();
                pqMax.push(num);

            }
        }
        
    }
    
    double findMedian() {

       int n = pqMin.size() + pqMax.size();
       cout<< n << endl;

    //    auto pqMinCopy = pqMin;
    //    auto pqMaxCopy = pqMax;

    //    while(!pqMinCopy.empty()){
    //     cout<< pqMinCopy.top()<< " ";
    //     pqMinCopy.pop();
    //    }
    //    cout<<endl;

    //     while(!pqMaxCopy.empty()){
    //     cout<< pqMaxCopy.top()<< " ";
    //     pqMaxCopy.pop();
    //    }
    //    cout<<endl;

    //    cout<< pqMax.top() << " " << pqMin.top()<< endl;

       double median = 0.0;
       if(n%2 != 0){
        cout<< " i am here "<<endl;
        median = pqMax.top();
       }else{
        // cout<< " i am here 2"<<endl;

        median = (double(pqMax.top() + pqMin.top()))/2;
       }
    //    cout<< endl;

       return median;
       
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */