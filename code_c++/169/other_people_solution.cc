// 1
public class Solution {
    public int majorityElement(int[] num) {

        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;

        }
        return major;
    }
}

// 2
int majorityElement(vector<int> &num) {

    int vote = num[0];
    int count = 1;
    int size = num.size();
    //vote from the second number
    for( int i = 1; i < size; i++ )
    {
        if( count == 0 ) { vote = num[i]; count++; }
        else if( vote == num[i] )   count++;
        else count--;
    }
    return vote;
    }

// 3
This can be solved by Moore's voting algorithm. Basic idea of the algorithm is if we cancel out each occurrence of an element e with all the other elements that are different from e then e will exist till end if it is a majority element. Below code loops through each element and maintains a count of the element that has the potential of being the majority element. If next element is same then increments the count, otherwise decrements the count. If the count reaches 0 then update the potential index to the current element and sets count to 1.

int majorityElement(vector<int> &num) {
    int majorityIndex = 0;
    for (int count = 1, i = 1; i < num.size(); i++) {
        num[majorityIndex] == num[i] ? count++ : count--;
        if (count == 0) {
            majorityIndex = i;
            count = 1;
        }
    }

    return num[majorityIndex];
}
