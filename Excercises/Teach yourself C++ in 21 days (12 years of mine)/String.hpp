 /////////////////////////////////////////////
//											 //
//    ***********************************    //
//   ***********              ************   //
//  ********                      *********  //
// *****		  String.hpp		  ****** //
//  ********                      *********  //
//   ***********              ************   //
//    ***********************************    //
//											 //
 /////////////////////////////////////////////

#include<iostream>
#include<string>

using namespace std;

class String
{
public:
	// ������������
	String();
	String(const char* const);
	String(const String&);
	~String();

	// ������������� ���������
	char& operator[](int offset);
	char operator[](int offset) const;
	String operator+(const String&);
	void operator+=(const String&);
	String& operator=(const String&);

	friend ostream& operator<<(ostream&, String);

	// ����� ������ �������
	int GetLen() const{ return m_Len; }
	const char* GetString() const{ return m_String; }

	static int ConstructorCount;

private:
	String(int);
	char* m_String;
	unsigned short int m_Len;
};

// ����������� ������ String �� ��������� ������� ������ ������ 0 ����
String::String()
{
	m_String = new char[1];
	m_String[0] = '\0';
	m_Len =0;

	cout<<"\tDefault String constructor\n";
	ConstructorCount++;
}

// �������� �����������, ������������ ������
// �������� ������ ��� �������� ����� ������
// ���������� �������, ����������� ������
String::String(int len)
{
	m_String = new char[len+1];
	for(int i=0; i<=len; i++)
		m_String[i] = '\0';
	m_Len = len;

	cout<<"\tString(int) constructor\n";
	ConstructorCount++;
}

// ������������ ������ �������� � ������
String::String(const char* const cString)
{
	m_Len = strlen(cString);
	m_String = new char[m_Len+1];
	for(int i=0; i<m_Len; i++)
		m_String[i] = cString[i];
	m_String[m_Len] = '\0';

	cout<<"\tString(char*) constructor\n";
	ConstructorCount++;
}

// ����������� �����������
String::String(const String& rhs)
{
	m_Len = rhs.GetLen();
	m_String = new char[m_Len+1];
	for(int i=0; i<m_Len; i++)
		m_String[i] = rhs[i];
	m_String[m_Len] = '\0';

	cout<<"\tString(String&) constructor\n";
	ConstructorCount++;
}

// ���������� ���������� ������� ������
String::~String()
{
	delete[] m_String;
	m_Len = 0;
	
	cout<<"\tString destructor\n";
}

// ���� �������� ����������� ������, 
// � ����� �������� ������ � ������
String&
String::operator=(const String& rhs)
{
	if(this == &rhs)
		return *this;
	delete[] m_String;
	m_Len = rhs.GetLen();
	m_String = new char[m_Len+1];
	for(int i=0; i<m_Len; i++)
		m_String[i] = rhs[i];
	m_String[m_Len] = '\0';
	return *this;

	cout<<"\tString operator=\n";
}

// ������������� �������� ��������������,
// ������� ���������� ������ �� ������,
// ������� ����� ��������
char&
String::operator[](int offset)
{
	if(offset > m_Len)
		return m_String[m_Len+1];
	else
		return m_String[offset];
}

// ������������� �������� ��������������,
// ������������ ��� ����������� �������� (��. ����������� �����������)
char
String::operator[](int offset) const
{
	if(offset > m_Len)
		return m_String[m_Len-1];
	else
		return m_String[offset];
}

// ������� ����� ������,
// �������� ������� � rhs
String
String::operator+(const String& rhs)
{
	int totalLen = m_Len + rhs.GetLen();
	String temp(totalLen);
	int i, j;
	
	for(i=0; i<m_Len; i++)
		temp[i] = m_String[i];
	for(j=0; j<rhs.GetLen(); j++, i++)
		temp[i] = rhs[j];
	temp[totalLen] = '\0';
	
	return temp;
}

// �������� ������� ������, ������ �� ���������
void String::operator+=(const String& rhs)
{
	unsigned short rhsLen = rhs.GetLen();
	unsigned short totalLen = m_Len + rhsLen;
	String temp(totalLen);
	int i, j;

	for(i=0; i<m_Len; i++)
		temp[i] = m_String[i];

	for(j=0; j<rhs.GetLen(); j++, i++)
		temp[i] = rhs[i - m_Len];
	temp[totalLen] = '\0';

	*this = temp;
}

// ������������� �������� ������
ostream&
operator<<(ostream& theStream, String theString)
{
	theStream<<theString.m_String;
	return theStream;
}

// ������� ����� ������ String
// �� ���� �������� ������ String
/*

String
operator+(const String& lhs, const String& rhs)
{
	int totalLen = lhs.GetLen() + rhs.GetLen();
	String temp(totalLen);
	int i, j;

	for(i=0; i<lhs.GetLen(); i++)
		temp[i] = lhs[i];
	for(j=0, i=lhs.GetLen(); j<rhs.GetLen(); j++, i++)
		temp[i] = rhs[j];

	temp[totalLen] = '\0';

	return temp;
}

*/

int String::ConstructorCount = 0;

// End of File