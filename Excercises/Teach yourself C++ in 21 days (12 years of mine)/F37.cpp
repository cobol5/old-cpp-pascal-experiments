#include<iostream>

using namespace std;

class Dog // ������
{
public:
	void Speak()   const {	cout<<"Woof!\n";			  } // ������ ����
	void Move()    const {	cout<<"Walking to heel...\n"; } // ����/������
	void Eat()     const {	cout<<"Gobbling food...\n";	  } // ������
	void Growl()   const {	cout<<"Grrrrr!";			  } // �������
	void Whimper() const {	cout<<"Whining noises...\n";  } // ������
};

// ��� ��������� �� ������� ������ Dog - PDF
typedef void(Dog::*PDF)() const;

int
main()
{
	const int MaxFuncs = 5; // �������� �������
	PDF DogFunctions[MaxFuncs] = 

	// ������������� ������� ���������� �� �������
	{
		Dog::Speak,
		Dog::Move,
		Dog::Eat,
		Dog::Growl,
		Dog::Whimper
	};

	Dog* pDog =0;	// ��������� pDog �� ������ ������ Dog
	int Method;		// �����
	bool fQuit =false; // �������� ������

	while(!fQuit) // ���� �� ����� ������ �����
	{
		cout<<"(0)Quit (1)Speak (2)Move (3)Eat (4)Growl (5)Whimper: ";
		cin>>Method;
		if(Method==0 || Method>5)
			fQuit =true;
		else
		{
			pDog =new Dog;
			(pDog->*DogFunctions[Method-1])();
			delete pDog;
		}
	}
	return 0;
}