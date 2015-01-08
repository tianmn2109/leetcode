class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        struct Node {
        int index;
        int value;
        /* previous wrong 
        Node(int i,int v):index(i),value(v){} // no default value cause compile error in vector<Node> v(size)
        bool operator < (const Node &n) {     // cause compile when lacking the 'const' at the  end
            return index < n.index;           // ordered by value not index
         */
        Node(int i = 0,int v = 0):index(i),value(v){}
        bool operator < (const Node &n) const {
            return value < n.value;
        }
    };

        int size = numbers.size();
        vector<int> ret(2);
        vector<Node> v(size);
        for (int i = 0; i < size; ++i){
            // v[i].index = i;          // the return index start from 1.     
            v[i].index = i + 1;              
            v[i].value = numbers[i];
        }
        sort(v.begin(),v.end());
        for (int i = 0, j = size - 1; i < j;){
            int sum = v[i].value + v[j].value;
            if (sum == target){
                if (v[i].index < v[j].index){
                    ret[0] = v[i].index;
                    ret[1] = v[j].index;
                }
                else {
                    ret[0] = v[j].index;
                    ret[1] = v[i].index;
                }
                return ret;
            }
            else if (sum > target) {
                -- j;
                continue;
            }
            else {
                ++ i;
                continue;
            }
        }
    }
};
