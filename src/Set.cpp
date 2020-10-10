#include "Set.h"
#include "BitField.h"
#include "Set.h"

using namespace std;

Set::Set(int mp) : 
  MaxPower(mp), BF(mp) {
}

Set::Set(const Set&s) :
  MaxPower(s.MaxPower), BF(s.BF) {
}

Set :: Set(const BitField &bf) : 
  MaxPower(bf.GetLength()), BF(bf) {
}

int Set::GetMaxPower(void) const {
  return MaxPower;
}

int Set:: IsMember(const int Elem) const {
  return BF.GetBit(Elem);
}

void Set::InsElem(const int Elem) {
  BF.SetBit(Elem);
}

void Set::DelElem(const int Elem) {
  BF.ClrBit(Elem);
}

Set & Set ::operator= (const Set &s) {
  BF = s.BF;
  MaxPower = s.GetMaxPower();
  return *this;
}

int Set :: operator== (const Set &s) {
  return BF == s.BF;
}

Set Set :: operator+ (const Set &s) {
  Set temp(BF | s.BF);
  return temp;
}

Set Set :: operator* (const Set &s) {
  Set temp(BF & s.BF);
  return temp;
}

Set Set :: operator~ ( void ) {
  Set temp(~BF);
  return temp;
}

istream& operator>> (istream &istr, Set &s) {
  int temp;
  char ch;
  do { istr >> ch; } while (ch != '{');
  do { istr >> temp;
  s.InsElem(temp);
  do { istr >> ch; } while ((ch != ',') && (ch != '}'));
  } while (ch != '}');
  return istr;
}

ostream& operator<< (ostream &ostr, const Set &s) {
  int i, n; char ch = ' ';
  ostr << "{";
  n = s.GetMaxPower();
  for (i = 0; i < n; i++) {
    if (s.IsMember(i)) {
      ostr << ch << ' ' << i;
      ch = ','; 
    }
  }
    ostr << " }";
    return ostr;
}