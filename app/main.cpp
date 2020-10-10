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
    cout << "ÒÅÑÒÈÐÎÂÀÍÈÅ ÏÐÎÃÐÀÌÌÛ, ÐÀÁÎÒÀÞÙÅÉ Ñ ÌÍÎÆÅÑÒÂÀÌÈ" << endl;
    cout << "ÍÀ ÏÐÈÌÅÐÅ ÐÀÑÑÌÎÒÐÅÍÎ " << "'" << "ÐÅØÅÒÎ ÝÐÀÒÎÑÔÅÍÀ" << "'" << endl << endl;
    cout << "       Ââåäèòå ãðàíèöó çíà÷åíèé: ";
    cin >> n;
    if (n < 2) {
      do {
        cout << "Ââåäèòå çíà÷åíèå áîëüøå èëè ðàâíîå 2" << endl;
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
    cout << "       Ïðîñòûå ÷èñëà äî " << n << endl;
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

    cout << " Â ÷èñëàõ äî " << n << " ñîäåðæèòñÿ " << count << " ïðîñòûõ ÷èñëà" << endl;

    cout << "\n\nÌåíþ:\n- ââåäèòå 1, ÷òîáû âûéòè èç ïðîãðàììû;";
    cout << "\n- ââåäèòå 0 äëÿ ââîäà íîâîãî çíà÷åíèÿ;\nÂâîä: ";
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