#include "number.h"

using namespace std;
#define ll long long int

void Number::print() {
  cout << str << endl;
}

bool Number::operator != (Number & b) {
  return (str != b.str);
}

string Number::GetStr() {
  return str;
}

Number Number::operator + (Number & another) {
  time_t at = clock();
  string a, b, c;
  if (str.size() > another.str.size()) {
    a = str;
    b = another.str;
  } else {
    a = another.str;
    b = str;
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  ll t = 0;
  for (ll i = 0; i < b.size(); ++i) {
    if ((a[i] + b[i] - '0' - '0' + t) < 10) {
      c += (a[i] + b[i] - '0' - '0' + t) + '0';
      t = 0;
    } else {
      c += to_string((a[i] + b[i] - '0' - '0' + t) % 10);
      t = (a[i] + b[i] - '0' - '0' + t) / 10;
    }
  }

  if (b.size() == a.size()) {
    if (t != 0)
      c += to_string(t);
  } else {
    for (ll i = b.size(); i < a.size(); ++i) {
      if ((a[i] - '0' + t) < 10) {
        c += to_string(a[i] - '0' + t);
        t = 0;
      } else {
        c += to_string((a[i] - '0' + t) % 10);
        t = (a[i] - '0' + t) / 10;
      }
    }
    if (t != 0)
      c += to_string(t);
  }
  reverse(c.begin(), c.end());
  Number out(c);
  time_t bt = clock();
  //cout << "Basic addition time: " << (double)(bt-at)/CLOCKS_PER_SEC << endl;
  return out;
}

void Number::operator = (const Number & b) {
  str = b.str;
}

void Number::operator += (const string& b) {
  str += b;
}

void Number::operator++() {
  for (ll i = str.size() - 1; i >= 0; --i) {
    if (i == 0 && str[i] == '9') {
      str[i] = '0';
      str = "1" + str;
      return;
    }
    if (str[i] != '9') {
      str[i] = ((str[i] - '0') + 1) + '0';
      return;
    } else {
      str[i] = '0';
    }
  }
}

Number Number::sum(Number & b) {
  return ( * this + b);
}

void Number::operator += (Number & b) {
  Number temp(str);
  str = (temp.sum(b)).str;
}

ll Number::size() {
  return str.size();
}

Number Number::operator - (Number & b) {
  bool dot = false;
  string s(str), ss(b.str), ans("");
  reverse(s.begin(), s.end());
  reverse(ss.begin(), ss.end());
  ll i;
  for (i = 0; i < s.size(); ++i) {
    if (i >= ss.size()) {
      break;
    }
    if (dot) {
      s[i] = (s[i] - '0') - 1 + '0';
    }
    if (((s[i] - '0') - (ss[i] - '0')) < 0) {
      ans += ((s[i] - '0') + 10 - (ss[i] - '0')) + '0';
      dot = true;
    } else {
      ans += ((s[i] - '0') - (ss[i] - '0')) + '0';
      dot = false;
    }
  }
  for (ll j = i; j < s.size(); ++j) {
    if (dot) {
      if (s[j] != '0') {
        ans += (s[j] - '0' - 1) + '0';
        dot = false;
      } else
        ans += '9';
    } else {
      ans += s[j];
    }
  }
  reverse(ans.begin(), ans.end());
  while (ans[0] == '0' && ans.size() > 1)
    ans.erase(ans.begin());
  Number answ(ans);
  return answ;
}