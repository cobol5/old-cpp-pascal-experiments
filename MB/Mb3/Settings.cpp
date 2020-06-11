//---------------------------------------------------------------------------
/*
        "���������� �������":
        
             3
          2[|||]1
             4

        ����� �������� �� ������ Label(1)
        �� ����� Label(2)
        �� ������� Label(3)
        �� ������ Label(4)
        � �������� CHEAT!

        !- ���� ������ ���� ����������!
        -- ���� ���������� ������� (1,2,3,4)
        -- �� �������� ������ ��� � ������!
*/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Settings.h"
#include "Mb3.h"
#include "Cheat.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "Tango"
#pragma resource "*.dfm"
TMbSettings *MbSettings;
//---------------------------------------------------------------------------
int Cheat1=0; // ����� )))
int Cheat2=0; // ���� ����� )))
int Cheat3=0; // � ��������� ������� ���� !!!
//---------------------------------------------------------------------------
__fastcall TMbSettings::TMbSettings(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::FormCreate(TObject *Sender)
{
    // ���� ��� �������� ���� �� ���������
    // ������� - �� ����� ���� ������ ���� "�� ������"
    rbRussianLang->Checked = true;
    // --����� ���������� ��������������� ������
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::FormShow(TObject *Sender)
{
    // ��������� �������� ��������
    SpinMaxShips->Value = MbForm->MB3_GameRulesAndData.MaxShips;
    // ��������� �������� ��������(��. ����)
    SpinMaxShips->Tag = SpinMaxShips->Value;

    // ��������� ������� ��������� ������ "�������" (���� ����������)
    restoreLang = rbRussianLang->Checked;

    // ��������� � ��������� ������� ��������� ������ "������"
    isMusic->Tag = (int)isMusic->Checked;
    isMusic->Checked = MbForm->MB3_GameRulesAndData.isMusic;
    // ��������� � ��������� ������� ��������� ������ "�����"
    isSounds->Checked = MbForm->MB3_GameRulesAndData.isSounds;
    isSounds->Tag = (int)isSounds->Checked;

    // ������������� ���� ����������
    MbSettings->Caption     = MbForm->MB3_Interface.SeaBottle;
    lblMaxShips->Caption    = MbForm->MB3_Interface.MaxShips;
    radioLanguage->Caption  = MbForm->MB3_Interface.Language;
    rbRussianLang->Caption  = MbForm->MB3_Interface.Russian;
    rbEnglishLang->Caption  = MbForm->MB3_Interface.English;
    Cancel->Caption         = MbForm->MB3_Interface.Cancel;
    isMusic->Caption        = MbForm->MB3_Interface.Music;
    isSounds->Caption       = MbForm->MB3_Interface.Sounds;
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    // ��� ����������� ���� ����� ������� �����������
    // � ���� ������, ����� �� � ����� ��������������
    MbForm->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::CancelClick(TObject *Sender)
{
    // ��������������� ����������� �������� ��������
    SpinMaxShips->Value = SpinMaxShips->Tag;

    // ��������������� ����������� ��������� ������ "�������"
    rbRussianLang->Checked = restoreLang;
    // ��������������� ����������� ��������� ������ "������"
    isMusic->Checked = (bool)isMusic->Tag;
    // ��������������� ����������� ��������� ������ "�����"
    isSounds->Checked = (bool)isSounds->Tag;

    // ��������������� ����������� �������� ������ "�������" - ��������
    // --���� ����. ��������� ����� 1 �� ��� ����� 0
    // --� ��������
    rbEnglishLang->Checked = !restoreLang;

    // ���� �����
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::OkClick(TObject *Sender)
{
    /* TODO: ��������� ��������� */
    
    if (rbRussianLang->Checked)
    // ���� ������ �������
    {
        // ��������� ������� ����
        MbForm->SetInterfaceLanguage("russian");
    }
    else
    if (rbEnglishLang->Checked)
    // ���� ������ ����������
    {
        // ��������� ���������� ����
        MbForm->SetInterfaceLanguage("english");
    }

    // ���������� - ������
    MbForm->MB3_GameRulesAndData.isMusic = isMusic->Checked;
    // ����� ����� �������� ����, ����� ��������/��������� ������
    if (isMusic->Checked)
    {
        MbForm->MediaBackSound->Play();
    }
    else
    {
        // ����� ��� ��������� ���������, ������ ���������� � ������
        MbForm->MediaBackSound->Pause();
        MbForm->MediaBackSound->Position = 0;        
    }
        
    // ���������� - �����
    MbForm->MB3_GameRulesAndData.isSounds = isSounds->Checked;

    // ���� ���� �� ������
    if (MbForm->MB3_GameRulesAndData.isGameStarted == false)
    {
        MbForm->Reset();
        // ��������� ����� �������� ��������
        MbForm->MB3_GameRulesAndData.MaxShips = SpinMaxShips->Value;
    }

    // ���� �����
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::rbRussianLangClick(TObject *Sender)
{
    // ���������/������ ������ ������ ������ �������/������������� ������
    rbEnglishLang->Checked = !rbRussianLang->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::rbEnglishLangClick(TObject *Sender)
{
    // ���������/������ ������ ������ ������ �������/������������� ������
    rbRussianLang->Checked = !rbEnglishLang->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::SpinMaxShipsClick(TObject *Sender)
{
    // � ����, ��� ��� Enabled == false ���� ��� �� ���������
    // �� ������ �� ����� ? � ������ ��� !
    if (!SpinMaxShips->Enabled)
        Beep(1000,100); // �������� :)))
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::SpinMaxShipsChange(TObject *Sender)
{
// �� ��� ������ ���� �����-���� ����� ������� ������� �� �����.
try
{
    // �� ��� ������ ���� ���-���� ����� �������
    if (SpinMaxShips->Value > SpinMaxShips->MaxValue)
        SpinMaxShips->Value = SpinMaxShips->MaxValue;
    else
    if (SpinMaxShips->Value < SpinMaxShips->MinValue)
        SpinMaxShips->Value = SpinMaxShips->MinValue;
}
// ���� ��� �� ����� ���� �� �����
catch(...) // �������� ��� :)-)-)-))
{
    SpinMaxShips->Value = SpinMaxShips->MinValue;
}
}
//---------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////
////----------------------- C H E A T -----------------------------------////
/////////////////////////////////////////////////////////////////////////////
void __fastcall TMbSettings::Label1Click(TObject *Sender)
{
    Cheat1 = 1; Cheat2 = 0; Cheat3 = 0;
}
void __fastcall TMbSettings::Label2Click(TObject *Sender)
{
    if (Cheat1 == 1){ Cheat1 = 0; Cheat2 = 1; Cheat3 = 0; }
    else { Cheat1 = 0; Cheat2 = 0; Cheat3 = 0; }
}
void __fastcall TMbSettings::Label3Click(TObject *Sender)
{
    if (Cheat2 == 1){ Cheat1 = 0; Cheat2 = 0; Cheat3 = 1; }
    else { Cheat1 = 0; Cheat2 = 0; Cheat3 = 0; }
}
void __fastcall TMbSettings::Label4Click(TObject *Sender)
{
    // CheatForm->Show - ��� ��������� �����!
    if (rbEnglishLang->Checked && Cheat3 == 1){ CheatForm->Show(); }
    Cheat1 = 0; Cheat2 = 0; Cheat3 = 0;
}
/////////////////////////////////////////////////////////////////////////////
////--------------End of--- C H E A T -----------------------------------////
/////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
