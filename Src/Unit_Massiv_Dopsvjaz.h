//---------------------------------------------------------------------------

#ifndef Unit_Massiv_DopsvjazH
#define Unit_Massiv_DopsvjazH
#include "Els.h"
//---------------------------------------------------------------------------
class Massiv_DopSv
{
public:
Massiv_DopSv(int n);
~Massiv_DopSv();
int Konez_Mas;
CElement **Dop_Massiv;
Massiv_DopSv *pr;   //последующий узел
};

class Node_DopMas
{
public:
Node_DopMas();
void Add_DopMas(int N_znach);
void Add_Nachalo_Massiv(Node_DopMas*);
void Add_Konez_Masssiv(Node_DopMas*);
//void Add_Nachalo_Massiv2(Node_DopMas*);
//void Add_Nachalo_Massiv3(Node_DopMas*);
~Node_DopMas();
Massiv_DopSv* First;
Massiv_DopSv* End;
Massiv_DopSv* Pnew;
Massiv_DopSv* Pold;
int count_M;
};



#endif
