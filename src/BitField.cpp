#include "BitField.h"
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

BitField::BitField(int len) : BitLen(len) {
  double tmp;
  tmp = len / 32.0; 
  MemLen = ceil(tmp);
  pMem = new UI[MemLen];
  if (pMem != NULL)
    for (int i = 0; i < MemLen; i++) 
      pMem[i] = 0;
}

BitField::BitField(const BitField &bf) { 
  BitLen = bf.BitLen;
  MemLen = bf.MemLen;
  pMem = new UI[MemLen];
  if (pMem != NULL)
    for (int i = 0; i < MemLen; i++)
      pMem[i] = bf.pMem[i];
}

BitField :: ~BitField() { // деструктор 
  delete pMem;
  pMem = NULL;
}

int BitField::GetMemIndex(const int n) const { 
  return n >> 4;
}

UI BitField::GetMemMask(const int n) const { 
  return 1 << (n & 15);
}

int BitField::GetLength(void) const {  // возвращает длину поля
  return BitLen;
}

void BitField::SetBit(const int n) {  
  if ((n > -1) && (n < BitLen))
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void BitField::ClrBit(const int n) {
  if ((n > -1) && (n < BitLen))
    pMem[GetMemIndex(n)] &=~GetMemMask(n);
}

int BitField::GetBit(const int n) const {
  if ((n > -1) && (n < BitLen))
   return pMem[GetMemIndex(n)] & GetMemMask(n);
  return 0; 
}

// битовые операции

BitField & BitField :: operator=(const BitField &bf) {
  BitLen = bf.BitLen;
  if (MemLen != bf.MemLen) {
    MemLen = bf.MemLen;
    if (pMem != NULL) delete pMem;
    pMem = new UI[MemLen];
  }
  if (pMem != NULL)
    for (int i = 0; i < MemLen; i++) pMem[i] = bf.pMem[i];
  return *this;
}

int BitField :: operator==(const BitField &bf) {
  int res = 1;
  if (BitLen != bf.BitLen) 
    res = 0;
  else 
    for ( int i=0; i<MemLen; i++)
      if (pMem[i] != bf.pMem[i]) {
        res = 0;
        break;
      }
  return res;
}

BitField & BitField :: operator| (const BitField &bf) {
  int i, len = BitLen;
  if (bf.BitLen > len)
    len = bf.BitLen;
  BitField temp(len);
  for (int i = 0; i < MemLen; i++)
    temp.pMem[i] = pMem[i];
  for (i = 0; i < bf.MemLen; i++)
    temp.pMem[i] |= bf.pMem[i];
  return temp;
}



BitField & BitField :: operator& (const BitField &bf) {
  int i, len = BitLen;
  if (bf.BitLen > len)
    len = bf.BitLen;
  BitField temp(len);
  for (int i = 0; i < MemLen; i++)
    temp.pMem[i] = pMem[i];
  for (i = 0; i = bf.MemLen; i++)
    temp.pMem[i] &= bf.pMem[i];
  return temp;
}

BitField & BitField :: operator~ (void) {
  int i, len = BitLen;
  BitField temp(len);
  for (int i = 0; i < MemLen; i++)
    temp.pMem[i] = ~pMem[i];
  return temp;
}

istream& operator>> (istream &istr, BitField &bf) {
  int i = 0; 
  char ch;
  do {
    istr >> ch;
  } while (ch != ' ');
  while (1) {
    istr >> ch;
    if (ch == '0')
      bf.ClrBit(i++);
    else
      if (ch == '1')
        bf.SetBit(i++);
      else
        break;
  }
  return istr;
}

ostream& operator<< (ostream &ostr, const BitField &bf) {
  int len = bf.GetLength();
  for (int i = 0; i < len; i++)
    if (bf.GetBit(i))
      ostr << '1';
    else
      ostr << '0';
  return ostr;
}


















