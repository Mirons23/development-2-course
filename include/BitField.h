#pragma once

#ifndef __BITFIELD_H
#define __BITFIELD_H

using namespace std;

#include <iostream>
#include <stdlib.h>

typedef unsigned int UI; // unsigned int == UI

class BitField
{
private:
  int BitLen;    // dlinna bitovogo polya
  UI *pMem;  // videleni dinamicheskoi pamyati
  int MemLen;  // kol-vo elementov bitovogo polya
  
  int GetMemIndex (const int n) const;
  UI GetMemMask (const int n) const;

public:
  BitField(int len);
  BitField(const BitField &bf);
  ~BitField();

  int GetLength (void) const;
  void SetBit(const int n);
  void ClrBit(const int n);
  int GetBit(const int n) const;

  int operator== (const BitField &bf);
  BitField & operator=(const BitField &bf);
  BitField & operator|(const BitField &bf);
  BitField & operator&(const BitField &bf);
  BitField & operator~(void);
  friend istream& operator>> (istream &istr, BitField &bf);
  friend ostream& operator<< (ostream &ostr, const BitField &bf);
};

#endif