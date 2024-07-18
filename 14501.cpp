#include <iostream>
#include <vector>

using namespace std;
vector<int> t;
vector<int> p;

int sum = 0;
int max_v = 0;

void func(int index){
  for(int i=index;i<t.size();i++){
    if(i+t[i] <= t.size()) {
      sum += p[i];
      func(i+t[i]);
      if(sum > max_v) max_v = sum;
      sum -= p[i];
    }
  }
  
}

int main() {
  int N;
  cin >> N;
  t.resize(N);
  p.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> t[i] >> p[i];
  }

  func(0);
  cout << max_v;
    
}
