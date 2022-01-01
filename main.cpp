#include <iostream>
#include "multiplicator.h"

using namespace std;

#define ll long long int

int main() {
  string num;
  cout << "Insert max number of digits: ";
  cin >> num;
  Number limit(num);
  Multiplicator::experiment(limit);
  cout << "End of testing.";
}
