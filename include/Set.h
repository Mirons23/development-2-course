#pragma once

#ifndef __SET_H
#define __SET_H

#include "BitField.h"

using namespace std;

class Set
{
private: 
  int MaxPower;
  BitField BF;

public:
  Set(const Set&s);
  Set(int mp);
  Set(const BitField &bf);

  int GetMaxPower(void) const;
  void InsElem(const int n);
  void DelElem(const int n);
  int IsMember(const int n) const;

  int operator== (const Set &s);
  Set & operator=(const Set &s);
  Set operator+ (const Set &s);
  Set operator* (const Set &s);
  Set operator~ (void);
  friend istream& operator>>(istream& istr, Set &bf);
  friend ostream& operator<<(ostream& ostr, const Set &);
};

#endif