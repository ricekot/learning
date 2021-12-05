#include <bits/stdc++.h>

using namespace std;

long find_rating(vector<string>, char);
char most_common_bit(vector<string>, int);

int main(int argc, char *argv[]) {
  if (argc < 2)
    return 1;
  ifstream is(argv[1]);
  istream_iterator<string> start(is), end;
  vector<string> numbers(start, end);
  cout << find_rating(numbers, '1') * find_rating(numbers, '0') << '\n';
  return 0;
}

long find_rating(vector<string> numbers, char main_bit) {
  for (int i = 0; i < numbers[0].length() && numbers.size() > 1; i++) {
    char common = most_common_bit(numbers, i);
    if (main_bit == '0') {
      common = common == '1' ? '0' : '1';
    }
    for (int j = 0; j < numbers.size(); ++j) {
      if (numbers[j][i] != common) {
        numbers.erase(numbers.begin() + j);
        j--;
      }
    }
  }
  return stoul(numbers[0], NULL, 2);
}

char most_common_bit(vector<string> numbers, int pos) {
  int sum_of_1s = 0;
  for (string number : numbers) {
    if (number[pos] == '1')
      sum_of_1s++;
  }
  if (numbers.size() % 2 == 0 && sum_of_1s == numbers.size() / 2) {
    return '1';
  }
  return sum_of_1s > numbers.size() / 2 ? '1' : '0';
}
