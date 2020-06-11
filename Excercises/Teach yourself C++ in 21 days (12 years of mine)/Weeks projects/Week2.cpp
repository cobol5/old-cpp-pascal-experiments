// **************************************** //
//
// ��������		:	������ 2. ���������� ������
//
// ����			:	Week2.cpp
//
// ��������		:	������������ �������� � ������������� ���������� ������
//
// ������ :
//
//		Part - �������� ����������������� ����� ������
//			� ������������ ����������� ��������� ������ ������.
//
//		PartsList - ��������� �������� ���������� ����� � ������
//
//		PartNode - ������������� ��� ���� � PartsList
//
// **************************************** //

#include<iostream>

using namespace std;

// ************* Part ************* //

// ����������� ������� �����, ����� ��� ���� �������.
class Part
{
public:
	Part(): m_PartNumber(1){ }
	Part(int PartNumber): m_PartNumber(PartNumber){ }
	virtual ~Part(){ }
	int GetPartNumber() const{ return m_PartNumber; }
	virtual void Display() const =0; // ������ ���� ��������
private:
	int m_PartNumber; // ����� ������
};

// ����������� ����������� ������ ����������� �������.
void
Part::Display() const
{
	cout<<"\nNumber of Part: " <<m_PartNumber <<endl;
}

// ************* CarPart ************* //

// ������������� ������
class CarPart: public Part
{
public:
	CarPart(): m_ModelYear(94){ }
	CarPart(int Year, int PartNumber);
	virtual void Display() const
	{
		Part::Display();
		cout<<"Year of Part: " <<m_ModelYear <<endl;
	}
private:
	int m_ModelYear;
};

CarPart::CarPart(int Year, int PartNumber):
m_ModelYear(Year),
Part(PartNumber)
{ }

// ************* AirPlanePart ************* //

// ���������� ������
class AirPlanePart: public Part
{
public:
	AirPlanePart(): m_EngineNumber(1){ };
	AirPlanePart(int EngineNumber, int PartNumber);
	virtual void Display() const
	{
		Part::Display();
		cout<<"Number of Engine: " <<m_EngineNumber <<endl;
	}
private:
	int m_EngineNumber;
};

AirPlanePart::AirPlanePart(int EngineNumber, int PartNumber):
m_EngineNumber(EngineNumber),
Part(PartNumber)
{ }

// ************* PartNode ************* //

// ���� ������ �������
class PartNode
{
public:
	PartNode(Part*);
	~PartNode();
	void SetNext(PartNode* node){ m_Next = node; }
	PartNode* GetNext() const;
	Part* GetPart() const;
private:
	Part* m_Part;
	PartNode* m_Next;
};

PartNode::PartNode(Part* pPart):
m_Part(pPart),
m_Next(0)
{ }

PartNode::~PartNode()
{
	delete m_Part;
	m_Part =0;
	delete m_Next;
	m_Next =0;
}

// ������������� NULL, ���� ��� ���������� ���� PartNode
PartNode*
PartNode::GetNext() const
{
	return m_Next;
}

Part*
PartNode::GetPart() const
{
	if(m_Part)
		return m_Part;
	else
		return NULL; // ������
}

// ************* PartsList ************* //

// ������ �������
class PartsList
{
public:
	PartsList();
	~PartsList();
// ����������, ����� �����������-����������� � �������� ������������ 
// ��������������� ���� �����!
	Part*	Find(int& position, int PartNumber) const;
	int		GetCount() const{ return m_Count; }
	Part*	GetFirst() const;
	static	PartsList& GetGlobalPartsList()
	{
		return GlobalPartsList;
	}
	void	Insert(Part*);
	void	Iterate(void (Part::*f)() const) const;
	Part*	operator[](int) const;
private:
	PartNode* pHead;
	int m_Count;
	static PartsList GlobalPartsList;
};

PartsList
PartsList::GlobalPartsList;

PartsList::PartsList():
pHead(0),
m_Count(0)
{ }

PartsList::~PartsList()
{
	delete pHead;
}

Part*
PartsList::GetFirst() const
{
	if(pHead)
		return pHead->GetPart();
	else
		return NULL; // ������� ������
}

Part*
PartsList::operator[](int offSet) const
{
	PartNode* pNode = pHead;

	if(!pHead)
		return NULL; // ������� ������
	if(offSet > m_Count)
		return NULL;  // ������

	for(int i=0; i<offSet; i++)
		pNode = pNode->GetNext();

	return pNode->GetPart();
}

Part*
PartsList::Find(int& position, int PartNumber) const
{
	PartNode* pNode =0;
	for(pNode =pHead, position =0; pNode!=NULL;
		pNode =pNode->GetNext(), position++)
		{
			if(pNode->GetPart()->GetPartNumber() == PartNumber)
				break;
		}

		if(pNode == NULL)
			return NULL;
		else
			return pNode->GetPart();
}

void
PartsList::Iterate(void (Part::*func)() const) const
{
	if(!pHead)
		return;
	PartNode* pNode = pHead;

	do
	(pNode->GetPart()->*func)();
	while(pNode =pNode->GetNext());
}

void
PartsList::Insert(Part* pPart)
{
	PartNode* pNode = new PartNode(pPart);
	PartNode* pCurrent = pHead;
	PartNode* pNext =0;

	int New = pPart->GetPartNumber();
	int Next =0;
	m_Count++;
	
	if(!pHead)
	{
		pHead = pNode;
		return;
	}

	// ���� ��� �������� ������ ��������� ����,
	// �� ������� ���� ���������� ��������.
	if(pHead->GetPart()->GetPartNumber() > New)
	{
		pNode->SetNext(pHead);
		pHead = pNode;
		return;
	}

	for(;;)
	{
		// ���� ��� ����������, ����������� �������
		if(!pCurrent->GetNext())
		{
			pCurrent->SetNext(pNode);
			return;
		}

		// ���� ������� ������ �����������, �� ������ ����������, ��
		// ��������� �����.
		// ����� ����������� �������� ��������� Next
		pNext = pCurrent->GetNext();
		Next = pNext->GetPart()->GetPartNumber();
		
		if(Next > New)
		{
			pCurrent->SetNext(pNode);
			pNode->SetNext(pNext);
			return;
		}
		pCurrent = pNext;
	}
}

int
main()
{
	PartsList& pl = PartsList::GetGlobalPartsList();
	Part* pPart =0;
	int PartNumber;
	int value;
	int choice;

	while(1)
	{
		cout<<"(0)Quit (1)Car (2)Plane: ";
		cin>>choice;

		if(!choice)
			break;

		cout<<"New PartNumber?: ";
		cin>>PartNumber;

		if(choice == 1)
		{
			cout<<"Model Year?: ";
			cin>>value;
			pPart = new CarPart(value,PartNumber);
		}
		else

		{
			cout<<"Engine number?: ";
			cin>>value;
			pPart = new AirPlanePart(value,PartNumber);
		}

		pl.Insert(pPart);
	}
	void (Part::*pFunc)() const = Part::Display;
	pl.Iterate(pFunc);

	return 0;
}
