//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include "Mb3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Tango"
#pragma resource "*.dfm"
TAboutForm *AboutForm;
//---------------------------------------------------------------------------
__fastcall TAboutForm::TAboutForm(TComponent* Owner)
    : TForm(Owner)
{
    mFormColor = (TColor)0x00D8CD9C; // ���������������� ����
}
//---------------------------------------------------------------------------
void __fastcall
TAboutForm::PrepareForm()
{
    // ���� ������ ����
    AboutForm->Color = mFormColor;
    // ���� ������ "�������"
    btnCloseAbout->Color = mFormColor;
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::FormCreate(TObject *Sender)
{
    // �������������� �����
    PrepareForm();
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    // ��� ����������� ���� ����� ������� �����������
    // � ���� ������, ����� �� � ����� ��������������
    MbForm->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::btnCloseAboutClick(TObject *Sender)
{
    // ���� �����
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    // �����-�� ���
    const int SC_DRAGMOVE = 0xF012;
    // ����������� ��������� (���� � ��� �� ����))))
    ReleaseCapture();
    // � ��� ����� ��� ����� ������� (�����))))
    AboutForm->Perform(WM_SYSCOMMAND, SC_DRAGMOVE, 0);    
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::FormShow(TObject *Sender)
{
    // ����� ����������� ����
    lblMBv3->Caption        = MbForm->MB3_Interface.SeaBottleV3;
    lblCitySchool->Caption  = MbForm->MB3_Interface.CitySchool;
    lblAuthor->Caption      = MbForm->MB3_Interface.NovkoMichael;
    lblADD1->Caption        = MbForm->MB3_Interface.Info1;
    lblADD2->Caption        = MbForm->MB3_Interface.Info2;
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::Timer1Timer(TObject *Sender)
{

    // � ���� ���� ���������� ���� �������� ������
    static int R=128, G=255, B=0;
    static int Ri=1, Gi=0, Bi=1;

    if (R > 250)        Ri = 0;
    else if (R < 5)     Ri = 1;
    if (Ri == 1)        R += 5;
    else if (Ri == 0)   R -= 5;

    if (G > 250)        Gi = 0;
    else if (G < 5)     Gi = 1;
    if (Gi == 1)        G += 5;
    else if (Gi == 0)   G -= 5;

    if (B > 250)        Bi = 0;
    else if (B < 5)     Bi = 1;
    if (Bi == 1)        B += 5;
    else if (Bi == 0)   B -= 5;

    GlowLine->Color = (TColor)RGB(R,G,B);
}
//---------------------------------------------------------------------------

