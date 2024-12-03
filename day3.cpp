
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  [[maybe_unused]] auto unused = freopen("inputs/d3.txt", "r", stdin);

  string s = "a";
  regex r("do\\(\\)|don't\\(\\)|mul\\((\\d+),(\\d+)\\)", regex_constants::ECMAScript);
  int sum = 0;
  int p2sum = 0;
  bool enabled = true;
  while(getline(cin, s)) {
    // Part 1
    vector<int> v;
    for(std::smatch sm; regex_search(s, sm, r);) {
      if(sm.str() == "do()") enabled = true; else
      if(sm.str() == "don't()") enabled = false; else {
        sum += stoi(sm[1]) * stoi(sm[2]);
        if(enabled) p2sum += stoi(sm[1]) * stoi(sm[2]);
      }
      s = sm.suffix();
    }
    }

  cout << "Part 1: " << sum << endl;
  cout << "Part 2: " << p2sum << endl;
}
