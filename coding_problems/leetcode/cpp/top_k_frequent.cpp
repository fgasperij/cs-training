#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> counts;
  int max_count = 0;
  for (int i = 0; i < nums.size(); ++i) 
    max_count = max(max_count, ++counts[nums[i]]);

  vector<int> buckets(max_count+1, 0);
  auto it = counts.begin();
  while (it != counts.end()) ++buckets[(*(it++)).second];

  int min_count = max_count, number_of_mins = k;
  while (min_count >= 0) {
    if (buckets[min_count] >= number_of_mins) break;
    number_of_mins -= buckets[min_count--];
  }

  it = counts.begin();
  vector<int> top_k;
  while (it != counts.end()) {
    if ((*it).second >= min_count || ((*it).second == min_count  && number_of_mins > 0))
      top_k.push_back((*it).first);

    if ((*it).second == min_count) --number_of_mins;
    ++it;
  }

  return top_k;


}
