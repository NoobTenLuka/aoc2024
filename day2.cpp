
#include <bits/stdc++.h>

using namespace std;

bool checkWithout(vector<int> v, size_t without) {
    bool increasing = true;
    size_t start = 1;
    if(without == 0) {
      if(v[1] > v[2]) increasing = false;
      start = 2;
    } else if(without == 1) {
      if(v[0] > v[2]) increasing = false;
    } else {
      if(v[0] > v[1]) increasing = false;
    }
    for (size_t i = start; i < v.size(); i++) {
      if (i == without) continue;
      size_t other = i-1;
      if(other == without) other = i-2;

      int diff = abs(v[other] - v[i]);
      if((diff > 3 || diff == 0) ||
	  (v[other] > v[i] && increasing) ||
	  (v[other] < v[i] && !increasing)) {
	return false;
      }
    }

    return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  [[maybe_unused]] auto unused = freopen("inputs/d2.txt", "r", stdin);

  string s;
  regex r("(\\d+)");
  int safes = 0;
  int p2safes = 0;
  while(getline(cin, s)) {
    // Part 1
    vector<int> v;
    for(smatch sm; regex_search(s, sm, r);) {
      v.push_back(stoi(sm.str()));
      s = sm.suffix();
    }
    bool increasing = true;
    if(v[0] > v[1]) increasing = false;
    bool safe = true;
    int unsafe = 0;
    for (size_t i = 1; i < v.size(); i++) {
      int diff = abs(v[i-1] - v[i]);
      if((diff > 3 || diff == 0) ||
	  (v[i-1] > v[i] && increasing) ||
	  (v[i-1] < v[i] && !increasing)) {
	safe = false;
	unsafe = i;
	break;
      }
    }

    if(!safe) {
      if(checkWithout(v, unsafe) || checkWithout(v, unsafe-1) || checkWithout(v, 0)) {
	p2safes += 1;
      }
    } else {
      safes += 1;
    }
  }

  cout << "Part 1: " << safes << endl;

  cout << "Part 2: " << safes + p2safes << endl;
}
