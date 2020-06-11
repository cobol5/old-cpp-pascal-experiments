//---------------------------------------------------------------------------
#ifndef Mb3H
#define Mb3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "Ship.h"
#include "Tango.h"
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <Graphics.hpp>
#include <MPlayer.hpp>
#include <jpeg.hpp>
#include <vector>

using namespace std;

//---------------------------------------------------------------------------
class TMbForm : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu;
    TMenuItem *mnuGame;
    TMenuItem *mnuNewGame;
    TMenuItem *mnuExitGame;
    TMenuItem *mnuHelp;
    TMenuItem *mnuAbout;
    TTango *btnExitGame;
    TTango *btnNewGame;
    TShip *MShip1;
    TShip *MShip2;
    TShip *MShip3;
    TShip *MShip4;
    TShip *MShip5;
    TShip *MShip6;
    TShip *MShip7;
    TShip *MShip8;
    TShip *MShip9;
    TShip *MShip10;
    TShip *MShip11;
    TShip *MShip12;
    TShip *MShip13;
    TShip *MShip14;
    TShip *MShip15;
    TShip *MShip16;
    TShip *MShip17;
    TShip *MShip18;
    TShip *MShip19;
    TShip *MShip20;
    TShip *MShip21;
    TShip *MShip22;
    TShip *MShip23;
    TShip *MShip24;
    TShip *MShip25;
    TShip *MShip26;
    TShip *MShip27;
    TShip *MShip28;
    TShip *MShip29;
    TShip *MShip30;
    TShip *MShip31;
    TShip *MShip32;
    TShip *MShip33;
    TShip *MShip34;
    TShip *MShip35;
    TShip *MShip36;
    TLabel *lblScore;
    TShip *FShip1;
    TShip *FShip2;
    TShip *FShip3;
    TShip *FShip4;
    TShip *FShip5;
    TShip *FShip6;
    TShip *FShip7;
    TShip *FShip8;
    TShip *FShip9;
    TShip *FShip10;
    TShip *FShip11;
    TShip *FShip12;
    TShip *FShip13;
    TShip *FShip14;
    TShip *FShip15;
    TShip *FShip16;
    TShip *FShip17;
    TShip *FShip18;
    TShip *FShip19;
    TShip *FShip20;
    TShip *FShip21;
    TShip *FShip22;
    TShip *FShip23;
    TShip *FShip24;
    TShip *FShip25;
    TShip *FShip26;
    TShip *FShip27;
    TShip *FShip28;
    TShip *FShip29;
    TShip *FShip30;
    TShip *FShip31;
    TShip *FShip32;
    TShip *FShip33;
    TShip *FShip34;
    TShip *FShip35;
    TShip *FShip36;
    TLabel *ScoreMan;
    TLabel *ScoreComputer;
    TLabel *lblYourShips;
    TLabel *lblMyShips;
    TImage *BgImage;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *mnuSettingsGame;
    TMediaPlayer *MediaBackSound;
    TMediaPlayer *MediaShotSound;
    TMediaPlayer *MediaExplodeSound;
    TMediaPlayer *MediaWinSound;
    TMediaPlayer *MediaLoseSound;
    void __fastcall mnuAboutClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall btnExitGameClick(TObject *Sender);
    void __fastcall mnuExitGameClick(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall btnNewGameClick(TObject *Sender);
    void __fastcall mnuNewGameClick(TObject *Sender);
    void __fastcall MShip36Click(TObject *Sender);
    void __fastcall FShip36Click(TObject *Sender);
    void __fastcall mnuSettingsGameClick(TObject *Sender);
    void __fastcall MediaBackSoundNotify(TObject *Sender);
private:
    // ��������� ���������� ������� ����������
    vector<TShip*> ComputerShips;
    // ��������� ���������� ������� ��������
    vector<TShip*> ManShips;
public:
    // �����, ���������� ������ � ����� ����������
    class Interface
    {
    public:
        AnsiString
        SeaBottle,
        Game,
        ExitGame,
        NewGame,
        Settings,
        Language,
        Russian,
        English,
        About,
        Score,
        YourShips,
        MyShips,
        MaxShips,
        Cancel,
        SeaBottleV3,
        CitySchool,
        NovkoMichael,
        Info1, Info2,
        YouWin,
        YouLose,
        Music,
        Sounds
        ;
    } MB3_Interface;

    // �����, ���������� ������ �� ����
    class GameRulesAndData
    {
    public:
    GameRulesAndData()
    {
        // ���������� ����� �� ���� (�������� ��� ����������)
        GlobalShipsQuantity = 36;
        MaxShips = 12;          // ��������� �������� - ����. ��������
        isMusic = true;         // ��������� �������� - ������
        isSounds = true;        // ��������� �������� - �����
        Reset();                // ����� �����
    }
    // ������ �����
    void Reset()
    {
        CurrentManShips = 0;      // ����� �������� ���������� �������� ��������
        CurrentComputerShips = 0; // ����� �������� ���������� �������� ����������
        ScoreMan = 0;           // ����� ����� ��������
        ScoreComputer = 0;      // ����� ����� ����������
        isGameStarted = false;  // ����� ��������� ���� (�� ������)
    }
        int
        MaxShips,               // ������������ ���������� ��������
        CurrentManShips,           // ������� ���������� �������� ��������
        CurrentComputerShips,   // ������� ���������� �������� ����������
        ScoreMan,               // ���� ��������
        ScoreComputer;          // ���� ����������
        // ���������� ����� �� ���� ������ ������
        int GlobalShipsQuantity;
        bool
        isMusic,                // ������
        isSounds,               // �����
        isGameStarted;          // ���� ������ ��� ���

        // TODO: ����������� �������.
    } MB3_GameRulesAndData;

    __fastcall TMbForm(TComponent* Owner);
    // �������� ���� ���������� (�������/����������)
    void __fastcall SetInterfaceLanguage(AnsiString="english");
    // ���������� ����
    void __fastcall Reset();
    // ���������� ���� � �������������� (���������� Reset())
    void __fastcall NewGame();
    // ����������� ������� ����������
    void __fastcall ComputerPrepare();
    // ������������ ��� �������� (�������� - �������, �� ������� ��������)
    void __fastcall ManStep(TShip*);
    // ��� ����������
    void __fastcall ComputerStep();
    // �����
    void __fastcall Tie();
    // ������� ��������
    void __fastcall ManWin();
    // ������� ����������
    void __fastcall ComputerWin();
    // ��������, �� �������/��������
    // ���������� 1 ���� ���-�� �������, ��� �����, else 0
    int __fastcall CheckWinOrLose();
    // ��������� ����
    void __fastcall UpdateScore();
};
//---------------------------------------------------------------------------
extern PACKAGE TMbForm *MbForm;
//---------------------------------------------------------------------------
#endif
