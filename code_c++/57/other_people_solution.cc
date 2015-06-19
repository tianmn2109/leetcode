// 1
class Solution {
public:
  std::vector<Interval> insert(std::vector<Interval> &intervals, Interval newInterval) {

    auto partial_order =[](const Interval & a, const Interval & b){
      return a.end < b.start;
    };

    auto less = std::lower_bound(intervals.begin(), intervals.end(), newInterval, partial_order);

    auto greater = std::upper_bound(intervals.begin(), intervals.end(), newInterval, partial_order);
    //printf("The index position: %d %d\n", less - intervals.begin(), greater - intervals.begin());
    std::vector<Interval> answer; 

    answer.insert(answer.end(), intervals.begin(), less);
    answer.push_back(mergeEqual(less, greater, newInterval));
    answer.insert(answer.end(), greater, intervals.end());
    return answer;
  }

private:

  // Merge the new interval with an array of intervals, all intervals in the 
  // array equal with the new interval in terms of the partial order we 
  // defined.
  // In other words all of them are overlapped with the new interval.

  Interval mergeEqual(const std::vector<Interval>::iterator & first, const std::vector<Interval>::iterator & last, const Interval &target){

    Interval answer(target);
    if(first < last){
      answer = merge(answer, *first);
      answer = merge(answer, *(last-1));
    }
    return answer;
  }
  // Merge two overlapped intervals.
  Interval merge(const Interval & a, const Interval & b) {
    return Interval(std::min(a.start, b.start), std::max(a.end, b.end));
  }
};


