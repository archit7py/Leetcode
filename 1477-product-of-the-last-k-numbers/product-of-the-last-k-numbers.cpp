class ProductOfNumbers {
public:
vector<int>res;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0){
            res.clear();
        }
        else if(res.empty()){
            res.push_back(num);
        }
        else {
            res.push_back(res.back() * num);
        }
        


         
        
    }
    
    int getProduct(int k) {
        if(k > res.size()) {
        return 0;
        }
        if(k == res.size()){
            return res.back();
        }
        int last  = res.size()-1;
        int previous = last - k;

        return res[last]/res[previous];
       

        

        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */