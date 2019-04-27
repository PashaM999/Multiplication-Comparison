#include "multiplicator.h"
#include <vector>
#include <fstream>

#define ll long long int

vector<pair<double, double>> v;

void Multiplicator::store() {
  ofstream out ("out.csv");
  for (ll i = 0; i < v.size(); ++i) {
    out << i+1 << ";" << v[i].first << ";" << v[i].second << "\n";
  }
}


void Multiplicator::experiment(Number& limit) {
  Multiplicator::test(limit);
  Multiplicator::store();
}

ll Multiplicator::PowerOfTwo(unsigned long Value) {
  int InitValue = 1;
  while (InitValue < Value)
    InitValue *= 2;
  if (InitValue == Value)
    return 0;
  return (InitValue);
}

Number Multiplicator::mul(Number& a, Number& b) {
  string zer = "";
  Number s("0");
  ll t = 0;
  for (ll i = a.GetStr().size()-1; i >= 0; --i) {
    string p; ll t = 0;
    for (ll j = b.GetStr().size()-1; j >= 0; --j) {
      if ( (a.GetStr()[i]-'0')*(b.GetStr()[j]-'0')+t < 10 ) {
        p += to_string((a.GetStr()[i]-'0')*(b.GetStr()[j]-'0')+t);
        t = 0;
      } else {
        p += to_string(((a.GetStr()[i]-'0')*(b.GetStr()[j]-'0')+t)%10);
        t = ( (a.GetStr()[i]-'0')*(b.GetStr()[j] - '0')+t)/10;
      }
    }
    if (t != 0)
      p =zer + p + to_string(t);
    else
      p = zer + p;
    zer += "0";
    reverse(p.begin(), p.end());
    Number temp(p);
    s += temp;
  }
  return s;
}

Number Multiplicator::DAC(Number& nn, Number& o) {
  if (nn.GetStr().size() <= 2 || o.size() <= 2)
    return Multiplicator::mul(nn, o);
  ll kk = max(Multiplicator::PowerOfTwo(nn.GetStr().size()), Multiplicator::PowerOfTwo(o.GetStr().size()) );
  string str1(nn.GetStr()), str2(o.GetStr());
  while (str1.size() < kk)
    str1 = "0" + str1;
  while (str2.size() < kk)
    str2 = "0" + str2;
  ll n = str1.size();
  ll x = n - (n/2);
  ll m = str2.size();
  ll y = m - (m/2);
  ll k = (m+n);
  Number a(str1.substr(0,x)); Number b(str1.substr(x,n/2));
  Number c(str2.substr(0,y)); Number d(str2.substr(y,m/2));
  Number yt(c.sum(d));
  Number tool(a.sum(b));
  Number p3( Multiplicator::DAC(tool , yt) );
  ll base = str1.size()/2; ll base2 = base*2;
  Number ac; ac = Multiplicator::DAC(a,c); Number bd; bd = Multiplicator::DAC(b,d);
  Number ac2(ac);
  for (ll i = 0; i < base2; ++i)
    ac2 += "0";
  Number cen; cen = (p3 - ac - bd);
  for (ll i = 0; i < base; ++i)
    cen += "0";
  string kkk = (ac2 + cen + bd).GetStr();
  while (kkk[0] == '0' && kkk.size() > 1)
    kkk.erase(kkk.begin());
  Number ans(kkk);
  return ans;
}

Number Multiplicator::ran(Number& a) {
  srand(clock());
  string out;
  Number counter("0");
  while (counter != a) {
    string temp = to_string(rand()%10);
    while (counter.GetStr() == "0") {
      if (temp != "0")
        break;
      temp = to_string(rand()%10);
    }
    out += temp;
    ++counter;
  }
  Number ans(out);
  return ans;
}

void Multiplicator::test(Number& limit) {
  Number zer("0");
  double ff(0), ss(0);
  for (Number i = zer; i != limit; ++i) {
    ff = 0; ss = 0;
    for (int j = 0; j < 3; ++j) {
      Number a(Multiplicator::ran(i));
      Number b(Multiplicator::ran(i));
      time_t at = clock();
      Multiplicator::mul(a,b);
      time_t bt = clock();
      ff += (double)(bt-at)/CLOCKS_PER_SEC;
      at = clock();
      Multiplicator::DAC(a,b);
      bt = clock();
      ss += (double)(bt-at)/CLOCKS_PER_SEC;
    }
    pair<double, double> ok;
    ok.first = ff/3.0; ok.second = ss/3.0;
    v.push_back(ok);
  }
}