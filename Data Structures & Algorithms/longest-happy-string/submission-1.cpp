class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>maxHeap;
        if(a>0)maxHeap.push({a,'a'});
        if(b>0)maxHeap.push({b,'b'});
        if(c>0)maxHeap.push({c,'c'});
        pair<int,char>prev={0,' '};
        string res="";
        while(!maxHeap.empty()||prev.first>0){
            if(prev.first>0&&maxHeap.empty()){
                return res;
            }
            auto[count,char_]=maxHeap.top();
            maxHeap.pop();
            if(count>1&&count>prev.first){
                count-=2;
                res+=char_;
                res+=char_;
                
            }else{
                count--;
                res+=char_;
            }
           
            if(prev.first>0)maxHeap.push(prev);
            prev={count,char_};
        }
        return res;
    }
};