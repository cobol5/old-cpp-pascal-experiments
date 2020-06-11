//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Mb3.h"
#include "About.h"
#include "Settings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Ship"
#pragma link "Tango"
#pragma resource "*.dfm"
TMbForm *MbForm;
//---------------------------------------------------------------------------
__fastcall TMbForm::TMbForm(TComponent* Owner)
    : TForm(Owner)
{
    // ����������� ��������� �������� ��������
    ManShips.push_back(MShip1);
    ManShips.push_back(MShip2);
    ManShips.push_back(MShip3);
    ManShips.push_back(MShip4);
    ManShips.push_back(MShip5);
    ManShips.push_back(MShip6);
    ManShips.push_back(MShip7);
    ManShips.push_back(MShip8);
    ManShips.push_back(MShip9);
    ManShips.push_back(MShip10);
    ManShips.push_back(MShip11);
    ManShips.push_back(MShip12);
    ManShips.push_back(MShip13);
    ManShips.push_back(MShip14);
    ManShips.push_back(MShip15);
    ManShips.push_back(MShip16);
    ManShips.push_back(MShip17);
    ManShips.push_back(MShip18);
    ManShips.push_back(MShip19);
    ManShips.push_back(MShip20);
    ManShips.push_back(MShip21);
    ManShips.push_back(MShip22);
    ManShips.push_back(MShip23);
    ManShips.push_back(MShip24);
    ManShips.push_back(MShip25);
    ManShips.push_back(MShip26);
    ManShips.push_back(MShip27);
    ManShips.push_back(MShip28);
    ManShips.push_back(MShip29);
    ManShips.push_back(MShip30);
    ManShips.push_back(MShip31);
    ManShips.push_back(MShip32);
    ManShips.push_back(MShip33);
    ManShips.push_back(MShip34);
    ManShips.push_back(MShip35);
    ManShips.push_back(MShip36);

    // ����������� ��������� �������� ����������
    ComputerShips.push_back(FShip1);
    ComputerShips.push_back(FShip2);
    ComputerShips.push_back(FShip3);
    ComputerShips.push_back(FShip4);
    ComputerShips.push_back(FShip5);
    ComputerShips.push_back(FShip6);
    ComputerShips.push_back(FShip7);
    ComputerShips.push_back(FShip8);
    ComputerShips.push_back(FShip9);
    ComputerShips.push_back(FShip10);
    ComputerShips.push_back(FShip11);
    ComputerShips.push_back(FShip12);
    ComputerShips.push_back(FShip13);
    ComputerShips.push_back(FShip14);
    ComputerShips.push_back(FShip15);
    ComputerShips.push_back(FShip16);
    ComputerShips.push_back(FShip17);
    ComputerShips.push_back(FShip18);
    ComputerShips.push_back(FShip19);
    ComputerShips.push_back(FShip20);
    ComputerShips.push_back(FShip21);
    ComputerShips.push_back(FShip22);
    ComputerShips.push_back(FShip23);
    ComputerShips.push_back(FShip24);
    ComputerShips.push_back(FShip25);
    ComputerShips.push_back(FShip26);
    ComputerShips.push_back(FShip27);
    ComputerShips.push_back(FShip28);
    ComputerShips.push_back(FShip29);
    ComputerShips.push_back(FShip30);
    ComputerShips.push_back(FShip31);
    ComputerShips.push_back(FShip32);
    ComputerShips.push_back(FShip33);
    ComputerShips.push_back(FShip34);
    ComputerShips.push_back(FShip35);
    ComputerShips.push_back(FShip36);
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::FormCreate(TObject *Sender)
{
    SetInterfaceLanguage("russian");
    // ��������� ������� ������
    MediaBackSound->FileName = "Sounds\\Bg.wma";
    MediaBackSound->Open();
    // ����������� ������� ������ 
    MediaBackSound->Play();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::SetInterfaceLanguage(AnsiString value)
{
    bool is = (value == "english");

    MB3_Interface.SeaBottle     = is ? ("Sea Bottle"        ):("������� ���"       );
    MB3_Interface.Game          = is ? ("Game"              ):("����"              );
    MB3_Interface.ExitGame      = is ? ("Exit"              ):("�����"             );
    MB3_Interface.NewGame       = is ? ("New Game"          ):("����� ����"        );
    MB3_Interface.Settings      = is ? ("Settings ..."      ):("��������� ..."     );
    MB3_Interface.Language      = is ? ("Language"          ):("����"              );
    MB3_Interface.Russian       = is ? ("Russian"           ):("�������"           );
    MB3_Interface.English       = is ? ("English"           ):("����������"        );
    MB3_Interface.About         = is ? ("About ..."         ):("� ��������� ..."   );
    MB3_Interface.Score         = is ? ("Score"             ):("����"              );
    MB3_Interface.YourShips     = is ? ("Man"               ):("�������"           );
    MB3_Interface.MyShips       = is ? ("Computer"          ):("���������"         );
    MB3_Interface.MaxShips      = is ? ("Max Ships"         ):("����. ��������"    );
    MB3_Interface.Cancel        = is ? ("Cancel"            ):("������"            );
    MB3_Interface.SeaBottleV3   = is ? ("Sea Bottle v3.0"   ):("������� ��� v3.0"  );
    MB3_Interface.CitySchool    = is ? ("c.Kharkov"         ):("�.�������"         );
    MB3_Interface.NovkoMichael  = is ? ("Novko Michael"     ):("����� ������"      );
    MB3_Interface.Info1         = is ? ("If you have some suggestions, wishes"):
                                       ("���� �����������, ������� � ���������");
    MB3_Interface.Info2         = is ? ("and questions email to: "):
                                       ("������ ���, �� e-mail: ");
    MB3_Interface.YouWin        = is ? ("You Win !!!"       ):("�� ������� !!!"    );
    MB3_Interface.YouLose       = is ? ("You Lose !!!"      ):("�� �������� !!!"   );
    MB3_Interface.Music         = is ? ("Music"             ):("������"            );
    MB3_Interface.Sounds        = is ? ("Sounds"            ):("�����"             ); 

    MbForm->Caption             = MB3_Interface.SeaBottle;
    btnNewGame->Caption         = MB3_Interface.NewGame;
    btnExitGame->Caption        = MB3_Interface.ExitGame;
    mnuGame->Caption            = MB3_Interface.Game;
    mnuNewGame->Caption         = MB3_Interface.NewGame;
    mnuExitGame->Caption        = MB3_Interface.ExitGame;
    mnuSettingsGame->Caption    = MB3_Interface.Settings;
    mnuAbout->Caption           = MB3_Interface.About;
    lblScore->Caption           = MB3_Interface.Score;
    lblYourShips->Caption       = MB3_Interface.YourShips;
    lblMyShips->Caption         = MB3_Interface.MyShips;
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::mnuNewGameClick(TObject *Sender)
{
    NewGame();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::btnNewGameClick(TObject *Sender)
{
    NewGame();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::mnuSettingsGameClick(TObject *Sender)
{
    MbSettings->Show();
    MbForm->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::mnuAboutClick(TObject *Sender)
{
    AboutForm->Show();
    MbForm->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::btnExitGameClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::mnuExitGameClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    if (Application->MessageBox(MB3_Interface.ExitGame.c_str(),
    MB3_Interface.SeaBottle.c_str(), MB_OKCANCEL)== IDCANCEL)
        CanClose = false;
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::Reset()
{
    ///////////////////////////////////////////////////////////
    // TODO: �������� ���, �������������� ������ ����� ����. //
    ///////////////////////////////////////////////////////////

    // ����� ��������� ���� (����, ������� ���-�� ��������, ...)
    MB3_GameRulesAndData.Reset();
    // ����� ��������� �������� � ����������
    // --��� ������ ����, ������� "������������ ���������� ��������"
    // --������ ��������
    MbSettings->SpinMaxShips->Enabled = true;

    // ������������ ��������� �������� ��������
    for (int i=0; i<MB3_GameRulesAndData.GlobalShipsQuantity; ++i)
        ManShips.at(i)->State = ssInvisible;

    // ������������ ��������� �������� ����������
    for (int i=0; i<MB3_GameRulesAndData.GlobalShipsQuantity; ++i)
        ComputerShips.at(i)->State = ssInvisible;
        
    UpdateScore();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::NewGame()
{
    if(Application->MessageBox(MB3_Interface.NewGame.c_str(),
    MB3_Interface.SeaBottle.c_str(), MB_OKCANCEL)== IDCANCEL)
        return;

    Reset();
}
//---------------------------------------------------------------------------
// ����������� �������� ����������
void __fastcall TMbForm::ComputerPrepare()
{
    Randomize();
    int Place;  // �����, ���� ����� ��������� �������

        // ����, � ���������� ��������� ��������� �������� �����
        // ��� ���� ����� � ������ ���������� ������ �������
        // �� ���������� ��������
    for (MB3_GameRulesAndData.CurrentComputerShips = 0;
         MB3_GameRulesAndData.CurrentComputerShips < MB3_GameRulesAndData.MaxShips;)
    {
        if (ComputerShips.at(Place = random(MB3_GameRulesAndData.GlobalShipsQuantity))
            ->State != ssHidden)
        // ���� ��� ����� ��� �� ���� �������
        {
            // ��������� ������� �����
            ComputerShips.at(Place)->State = ssHidden;
            // ������� � ��������� ��������
            ++MB3_GameRulesAndData.CurrentComputerShips;
            // continue;
        }
        else
        // ���� ��� ����� ��� ���� �������
        {
            // ������ �������� �������
            continue;
        }
    }
}
//---------------------------------------------------------------------------
// �����
void __fastcall TMbForm::Tie()
{
    AnsiString WMes = "�����!\nTie!";
    WMes += "\n\n";
    WMes += MB3_Interface.Score;
    WMes += " - ";
    WMes += MB3_GameRulesAndData.ScoreMan;
    WMes += ":";
    WMes += MB3_GameRulesAndData.ScoreComputer;

    Application->MessageBox(WMes.c_str(), MB3_Interface.SeaBottle.c_str(), 0);
    Reset();
}
//---------------------------------------------------------------------------
// ������ ��������
void __fastcall TMbForm::ManWin()
{
    AnsiString WMes = MB3_Interface.YouWin;
    WMes += "\n\n";
    WMes += MB3_Interface.Score;
    WMes += " - ";
    WMes += MB3_GameRulesAndData.ScoreMan;
    WMes += ":";
    WMes += MB3_GameRulesAndData.ScoreComputer;

    Application->MessageBox(WMes.c_str(), MB3_Interface.SeaBottle.c_str(), 0);
    Reset();
}
//---------------------------------------------------------------------------
// ������ ����������
void __fastcall TMbForm::ComputerWin()
{
    AnsiString WMes = MB3_Interface.YouLose;
    WMes += "\n\n";
    WMes += MB3_Interface.Score;
    WMes += " - ";
    WMes += MB3_GameRulesAndData.ScoreComputer;
    WMes += ":";
    WMes += MB3_GameRulesAndData.ScoreMan;

    Application->MessageBox(WMes.c_str(), MB3_Interface.SeaBottle.c_str(), 0);
    Reset();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::MShip36Click(TObject *Sender)
// ����� ������� ��������� ������� �� �������� ��������
{
    // ��������� ����� ������, ������� �����
    // �������������� � �������� ������������.
    static TShip* _ship_;

    // Sender ���������� � ���� TShip*
    // ������ ����� ������������ _ship_
    // ��� Sender � ���� TShip.
    _ship_ = dynamic_cast<TShip*>(Sender);
    // ������ ����� ������������ _ship_
    // � �������� ������������

    if (MB3_GameRulesAndData.isGameStarted) // ���� ���� ������
    {
        Beep(1000,100); // �������� :)))
    }
    else // ���� ���� �� ������
    {
        // ���� ���� ������� ���������
        if (_ship_->State != ssLive)
        { // ���� ��� ����� ������� �������

            // ��������� ������� ���������� �������� ��������
            ++MB3_GameRulesAndData.CurrentManShips;
            _ship_->State = ssLive;

        }
        else
        {
            // � �������� ����� CurrentShips ������� �� ������ 0.
            --MB3_GameRulesAndData.CurrentManShips;
            _ship_->State = ssInvisible;
        }
        if (MB3_GameRulesAndData.CurrentManShips == MB3_GameRulesAndData.MaxShips)
        { // ���� �������� ��������
            // ������ ����
            MB3_GameRulesAndData.isGameStarted = true;
            // ��������� ��������� �������� � ����������
            MbSettings->SpinMaxShips->Enabled = false;
            Beep(1000,100); // �������� :)))
            ComputerPrepare();
        }
    }
//    delete _ship_; // ��������, ��� ������ ������� (static)
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::FShip36Click(TObject *Sender)
// ����� ������� ��������� ������� �� �������� ����������
{
    // ��������� ����� ������, ������� �����
    // �������������� � �������� ������������.
    static TShip* _ship_;

    // Sender ���������� � ���� TShip*
    // ������ ����� ������������ _ship_
    // ��� Sender � ���� TShip.
    _ship_ = dynamic_cast<TShip*>(Sender);
    // ������ ����� ������������ _ship_
    // � �������� ������������

    if (MB3_GameRulesAndData.isGameStarted) // ���� ���� ������
    {
        ManStep(_ship_);    // ���������� ��� ��������
        ComputerStep();     // �������� ����������
    }
    else // ���� ���� �� ������
    {
        Beep(1000,100); // �������� :)))
    }

//    delete _ship_; // ��������, ��� ������ ������� (static)
}
//---------------------------------------------------------------------------
void __fastcall
TMbForm::ManStep(TShip* Target)
{
    // TODO: ���������� ��� ��������,

    if (Target->State == ssHidden) // ���� ���� ��������
    {
        if (MB3_GameRulesAndData.isSounds)
        // ���� ����� ���������
        {
            // ���������� ����� �� ������ �����
            MediaShotSound->Position = 0;
            MediaExplodeSound->Position = 0;
            // ��������� ���� ��������, � ������
            MediaShotSound->Play();
            MediaExplodeSound->Play();
        }
        else // ���� ����� ���������
        {
            // ���������� )))
        }
        Target->State = ssDied; // �������� ���������� �������
        ++MB3_GameRulesAndData.ScoreMan;
        UpdateScore();
    }
    else // ���� ���� �� ��������
    {
        if (MB3_GameRulesAndData.isSounds)
        // ���� ����� ���������        
        {
            // ���������� ����� �� ������ �����
            MediaShotSound->Position = 0;            
            // ��������� ���� ��������, [� �������]
            MediaShotSound->Play();
        }
        else // ���� ����� ���������
        {
            // ���������� )))
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall
TMbForm::ComputerStep()
{
    // TODO: ���������� ��� ����������,

    Randomize();
    int Place; // ����

    for (;;)  //// ����������� ���� ������� ����� goto
    {
        Place = random(MB3_GameRulesAndData.GlobalShipsQuantity); // ����

        if (ManShips.at(Place)->State == ssLive)
        // ���� ����� ����� �������
        {
            // ����� ���
            ManShips.at(Place)->State = ssDied;
            // ��������� ����
            ++MB3_GameRulesAndData.ScoreComputer;
            UpdateScore();
            CheckWinOrLose(); //// ���������, ������� �� ��� ������
            break;
        }
        else
        if (ManShips.at(Place)->State == ssInvisible)
        // ���� ����� ��� �������
        {
            // �������� ����
            ManShips.at(Place)->State = ssWater;
            CheckWinOrLose(); //// ���������, ������� �� ��� ������            
            break;
        }
        else
        if (ManShips.at(Place)->State == ssDied)
        // ���� ����� ������ �������
        {
            // ������� ������ ����
            if (CheckWinOrLose()) break; //// ������ �� ������������ �����
            continue;
        }
        else
        if (ManShips.at(Place)->State == ssWater)
        // ���� � ��� ����� ��� ��������
        {
            // ������� ������ ����
            if (CheckWinOrLose()) break; //// ������ �� ������������ �����
            continue;
        }
    }
}
//---------------------------------------------------------------------------
int __fastcall
TMbForm::CheckWinOrLose()
{
    // TODO: ���������, ������� �� ��� ������

    if ((MB3_GameRulesAndData.ScoreMan == MB3_GameRulesAndData.MaxShips) &&
        (MB3_GameRulesAndData.ScoreComputer == MB3_GameRulesAndData.MaxShips))
        {   // ���� �����
            // ���������� ��������� ����� �� ������
            MediaWinSound->Position = 0;
            MediaLoseSound->Position = 0;
            // ��������� �����
            MediaWinSound->Play();
            MediaLoseSound->Play();
            
            Tie();
            return 1;
        }
    else
    if (MB3_GameRulesAndData.ScoreMan == MB3_GameRulesAndData.MaxShips)
    {
        // ������� �������
        // ���������� �������� ���� �� ������
        MediaWinSound->Position = 0;
        // ��������� ����
        MediaWinSound->Play();

        ManWin();
        return 1;
    }
    else
    if (MB3_GameRulesAndData.ScoreComputer == MB3_GameRulesAndData.MaxShips)
    {
        // ������� ���������
        // ���������� �������� ���� �� ������
        MediaLoseSound->Position = 0;
        // ��������� ����
        MediaLoseSound->Play();

        ComputerWin();
        return 1;
    }
    return 0;
}
//---------------------------------------------------------------------------
void __fastcall
TMbForm::UpdateScore()
{
    // �������� ����, �� Label'��
    ScoreMan->Caption = MB3_GameRulesAndData.ScoreMan;
    ScoreComputer->Caption = MB3_GameRulesAndData.ScoreComputer;
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::MediaBackSoundNotify(TObject *Sender)
{// ���� ������ �����������, ������ � ������
    // ����������� �� ������ ����� (������)
    if (MediaBackSound->Position == MediaBackSound->Length)
    {
        MediaBackSound->Position = 0;
        MediaBackSound->Play(); // �����������
    }
}
//---------------------------------------------------------------------------
