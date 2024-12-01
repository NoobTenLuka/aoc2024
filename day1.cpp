
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  [[maybe_unused]] auto unused = freopen("inputs/d1.txt", "r", stdin);

  int x;
  int y;
  vector<int> first;
  vector<int> last;
  while(cin >> x >> y) {
    first.push_back(x);
    last.push_back(y);
  }

  sort(first.begin(), first.end());
  sort(last.begin(), last.end());

  // Part 1

  int total = 0;
  for (size_t i = 0; i < first.size(); i++) {
    total += abs(first[i] - last[i]);
  }

  cout << "Part 1: " << total << '\n';

  // Part 2
  
  unordered_map<int, int> m;
  for(auto x : last) {
    m[x] += 1;
  }

  int score = 0;
  for(auto x : first) {
    score += x * m[x];
  }

  cout << "Part 2: " << score << '\n';
}
