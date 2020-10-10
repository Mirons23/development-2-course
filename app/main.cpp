#pragma hdrstop
#include <iomanip>
#include <conio.h>
#include "BitField.h"
#include "Set.h"
#include <stdio.h> 
#include <stdlib.h> 

using namespace std;

int main() {
  int work = 1;
  while (work) {
    setlocale(LC_ALL, "Russian");
    int n, m, k, count;
    cout << "������������ ���������, ���������� � �����������" << endl;
    cout << "�� ������� ����������� " << "'" << "������ ����������" << "'" << endl << endl;
    cout << "       ������� ������� ��������: ";
    cin >> n;
    if (n < 2) {
      do {
        cout << "������� �������� ������ ��� ������ 2" << endl;
        cin >> n;
      } while (n < 2);
    }
    Set s(n + 1);
    for (m = 2; m <= n; m++)
      s.InsElem(m);
    for (m = 2; m <= n; m++)
      if (s.IsMember(m))
        for (k = m * 2; k <= n; k += m)
          if (s.IsMember(k)) s.DelElem(k);
    cout << endl;
    cout << "       ������� ����� �� " << n << endl;
    count = 0;
    k = 1;
    for (m = 2; m <= n; m++)
      if (s.IsMember(m)) {
        count++;
        cout << setw(4) << m << " ";
        if (k++ % 10 == 0)
          cout << endl;
      }
    cout << endl << endl;

    cout << " � ������ �� " << n << " ���������� " << count << " ������� �����" << endl;

    cout << "\n\n����:\n- ������� 1, ����� ����� �� ���������;";
    cout << "\n- ������� 0 ��� ����� ������ ��������;\n����: ";
    int stop = 1;
    cin >> stop ;
    cout << endl;
    if (stop)
    {
      work = 0;
    }
  }

  system("pause");
  return 0;
}