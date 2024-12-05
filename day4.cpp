
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> coords;

// Hash function  
struct hashFunction 
{ 
  size_t operator()(const pair<int ,  
                    int> &x) const
  { 
    return x.first ^ x.second; 
  } 
};

unordered_set<coords, hashFunction> xset;
unordered_set<coords, hashFunction> mset;
unordered_set<coords, hashFunction> aset;
unordered_set<coords, hashFunction> sset;

bool checkDir(int row, int col, int rowMax, int colMax, char c, int dirRow, int dirCol);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  [[maybe_unused]] auto unused = freopen("inputs/d4.txt", "r", stdin);

  string s;

  int row = 0;
  int colMax = 0;
  while(getline(cin, s)) {
    for (size_t col = 0; col < s.length(); col++) {
      switch (s[col]) {
	case 'X': 
	  xset.insert(make_pair(row, col));
	  break;
	case 'M': 
	  mset.insert(make_pair(row, col));
	  break;
	case 'A': 
	  aset.insert(make_pair(row, col));
	  break;
	case 'S': 
	  sset.insert(make_pair(row, col));
	  break;
      	default:
      	  break;
      }
      colMax = col;
    }
    row++;
  }

  int xmas = 0;
  for(auto x : xset) {
    for (int rowDir = -1; rowDir <= 1; rowDir++) {
      for (int colDir = -1; colDir <= 1; colDir++) {
        if (colDir == 0 && rowDir == 0)
          continue;

        if (checkDir(x.first + rowDir, x.second + colDir, row, colMax, 'M', rowDir, colDir))
        {
          xmas++;
        };
      }
    }
  }

  cout << "Part 1: " << xmas << endl;

  int crossmas = 0;
  for(auto a : aset) {
    int mSum = 0;
    int sSum = 0;
    for (int row = -1; row < 2; row++) {
      if (row == 0) continue;
      for (int col = -1; col < 2; col++) {
        if(col == 0) continue;
        coords p = make_pair(a.first + row, a.second + col);
        if(mset.count(p)) {
          mSum++;
        } else if(sset.count(p)) {
          sSum++;
        }
      }
    }
    if(mSum == 2 && sSum == 2 && mset.count(make_pair(a.first-1,a.second-1)) !=
    mset.count(make_pair(a.first+1,a.second+1))) crossmas++;
  }

  cout << "Part 2: " << crossmas << endl;
}

bool checkDir(int row, int col, int rowMax, int colMax, char c, int dirRow, int dirCol) {
  if(row < 0 || col < 0 || row > rowMax || col > colMax) return false;

  if(c == 'M') {
    if(mset.count(make_pair(row,col))) {
      return checkDir(row + dirRow, col + dirCol, rowMax, colMax, 'A', dirRow, dirCol);
    }
    return false;
  }

  if(c == 'A') {
    if(aset.count(make_pair(row,col))) {
      return checkDir(row + dirRow, col + dirCol, rowMax, colMax, 'S', dirRow, dirCol);
    }
    return false;
  }

  if(c == 'S') {
    if(sset.count(make_pair(row,col))) {
      return true;
    }
    return false;
  }

  return false;
}
