//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cheat.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCheatForm *CheatForm;
//---------------------------------------------------------------------------
__fastcall TCheatForm::TCheatForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCheatForm::Image1Click(TObject *Sender)
{
    // ��������� - ���� ��� ����� ������ ���������� ? :)))))
    Close();    
}
//---------------------------------------------------------------------------