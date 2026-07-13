#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
  vector<int>price = {100, 80, 60, 70, 60, 75, 85};
  vector<int> ans;
  stack<int> s;

  for(int i = 0; i < price.size();i++ ) {
    while(s.size() > 0 && price[s.top()] <= price[i]) {
      s.pop();
    }
    if(s.size() == 0) {
      ans.push_back(i + 1);
    } else {
      ans.push_back(i - s.top());
    }
    s.push(i);
  }

  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

}