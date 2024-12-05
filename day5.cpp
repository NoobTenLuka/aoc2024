
#include <bits/stdc++.h>

using namespace std;

unordered_map<int,vector<int>> rules; // prev -> vector<following>

bool correctRules(vector<int> &nums) {
    bool exclude = false;
    size_t wrong = 0;
    auto wrongF = nums.begin();
    for (size_t i = 0; i < nums.size(); i++) {
      for(auto x : rules[nums[i]]) {
	auto end = next(nums.begin(),i);
	auto f = find(nums.begin(), end, x);
	if(f != end) {
	  exclude = true;
	  wrong = i;
	  wrongF = f;
	  break;
	}
      }
      if(exclude) break;
    }

    if(exclude) {
      int wrongNum = nums[wrong];
      nums.erase(nums.begin() + wrong);
      nums.insert(wrongF, wrongNum);
    }

    return exclude;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  [[maybe_unused]] auto unused = freopen("inputs/d5.txt", "r", stdin);

  string s;

  int correct = 0;
  int full = 0;
  while(getline(cin, s)) {
    if(s.size() == 0) continue;

    if(s[2] == '|') {
      string prev = s.substr(0, 2);
      string follow = s.substr(3, 5);
      rules[stoi(prev)].push_back(stoi(follow));
      continue;
    }

    vector<int> nums;

    size_t pos = 0;
    int t;
    while ((pos = s.find(',')) != string::npos) {
      t = stoi(s.substr(0, pos));
      nums.push_back(t);
      s.erase(0, pos + 1);
    }
    nums.push_back(stoi(s));

    bool exclude = false;
    for (size_t i = 0; i < nums.size(); i++) {
      for(auto x : rules[nums[i]]) {
	auto end = next(nums.begin(),i);
	if(find(nums.begin(), end, x) != end) {
	  exclude = true;
	  break;
	}
      }
      if(exclude) break;
    }

    if(exclude) {
      while(correctRules(nums)) {
      }
      full += nums[nums.size()/2];
      continue;
    };

    correct += nums[nums.size()/2];
  }
  cout << "Part 1: " << correct << endl;
  cout << "Part 2: " << full << endl;
}
