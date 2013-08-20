//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit_Massiv_Dopsvjaz.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Massiv_DopSv::Massiv_DopSv(int n)
{
Konez_Mas=n;
Dop_Massiv= new CElement *[Konez_Mas];
for (int k=0; k<Konez_Mas; k++)
Dop_Massiv[k]=NULL;
pr=NULL;
}

Massiv_DopSv::~Massiv_DopSv()
{
for (int i=0; i<Konez_Mas; i++)
Dop_Massiv[i]=NULL;
delete Dop_Massiv; Dop_Massiv=NULL;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
Node_DopMas::Node_DopMas()
{
count_M=0;
End=NULL;
First=NULL;
Pnew=NULL;
Pold=NULL;
count_M=0;
}

/*Node_DopMas::Node_DopMas(int N_znach)
{
Pnew = new Massiv_DopSv(N_znach);
First=Pnew;
/*if(count_M!=0)
 {
 Pnew->pr=Pold;
 Pnew = new Massiv_DopSv(N_znach);
 }
else {Pnew = new Massiv_DopSv(N_znach);
      First=Pnew;}
count_M++;
} */

Node_DopMas::~Node_DopMas()
{
Pnew=First;
while(Pnew!=NULL)
 {
 Pold=Pnew;
 Pnew=Pnew->pr;
 delete Pold; Pold=NULL;
 }
count_M=0;
}


void Node_DopMas::Add_DopMas(int N_znach)
{
if(First!=NULL)
Pnew=End;
if(count_M>0)
 {
 Pold=Pnew;
 Pnew=NULL;
 Pnew = new Massiv_DopSv(N_znach);
 Pold->pr=Pnew;
 End=Pnew;
 }
else {Pnew = new Massiv_DopSv(N_znach);
      First=Pnew; End=Pnew;}
count_M++;
}

void Node_DopMas::Add_Nachalo_Massiv(Node_DopMas* nachalo)
{
Node_DopMas* Vspomog_m = new Node_DopMas;
Pnew=First;
while(Pnew!=NULL)
 {
 Vspomog_m->Add_DopMas(Pnew->Konez_Mas);
 for(int i=0;i<Pnew->Konez_Mas;i++)
 Vspomog_m->Pnew->Dop_Massiv[i]=Pnew->Dop_Massiv[i];
 Pnew=Pnew->pr;
 }
this->~Node_DopMas();
count_M=0;
End=NULL;
First=NULL;
Pnew=NULL;
Pold=NULL;
count_M=0;
if(nachalo->First!=NULL)
 {
 nachalo->Pnew=nachalo->First;
 while(nachalo->Pnew!=NULL)
  {
  this->Add_DopMas(nachalo->Pnew->Konez_Mas);
   for(int i=0;i<nachalo->Pnew->Konez_Mas;i++)
   {
   this->Pnew->Dop_Massiv[i]=nachalo->Pnew->Dop_Massiv[i];
   }
   nachalo->Pnew=nachalo->Pnew->pr;
  }
 }

 if(Vspomog_m->First!=NULL)
 {
  Vspomog_m->Pnew=Vspomog_m->First;
  while(Vspomog_m->Pnew!=NULL)
   {
    this->Add_DopMas(Vspomog_m->Pnew->Konez_Mas);
    for(int i=0;i<Vspomog_m->Pnew->Konez_Mas;i++)
    {
     this->Pnew->Dop_Massiv[i]=Vspomog_m->Pnew->Dop_Massiv[i];
    }
    Vspomog_m->Pnew=Vspomog_m->Pnew->pr;
   }
 }
 delete Vspomog_m; Vspomog_m=NULL;
}

void Node_DopMas::Add_Konez_Masssiv(Node_DopMas* mas)
{

mas->Pnew=mas->First;
while(mas->Pnew!=NULL)
{
this->Add_DopMas(mas->Pnew->Konez_Mas);
    for(int i=0;i<mas->Pnew->Konez_Mas;i++)
    {
     this->Pnew->Dop_Massiv[i]=mas->Pnew->Dop_Massiv[i];
    }
mas->Pnew=mas->Pnew->pr;
}
}