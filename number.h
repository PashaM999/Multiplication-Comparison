#include <ctime>
#include <string>
#include <algorithm>
#include <iostream>
#define ll long long int
using namespace std;

class Number {
  public:
    string str;

    Number() : str(""){}

    Number(string k) : str(k){}

    Number (const Number& b) : str(b.str){}

    string GetStr();

    void print();

    bool operator!= (Number& b);

    Number operator+ (Number& another);

    void operator= (const Number& b);

    void operator++ ();

    Number sum(Number& b);

    void operator+= (Number& b);

    void operator+= (const string& b);

    ll size();

    Number operator- (Number& b);
};