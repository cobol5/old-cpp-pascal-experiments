#include<iostream>

using namespace std;

const int DefaultSize = 10;

// ������� ����� Animal ���
// �������� ������� ��������

class Animal
{
public:
	Animal(int);
	Animal();
	~Animal(){ }
	int GetWeight() const{ return m_Weight; }
	void Display() const{ cout<<m_Weight; }
private:
	int m_Weight;
};

Animal::Animal(int weight):
m_Weight(weight)
{ }

Animal::Animal():
m_Weight(0)
{ }

template <class T>	// ��������� ������ � ��������
class Array			// ����������������� �����
{
public:
	// ������������
	Array(int Size = DefaultSize);
	Array(const Array& rhs);
	~Array(){ delete[] pType; }

	// ���������
	Array& operator=(const Array&);
	T& operator[](int offSet){ return pType[offSet]; }
	const T& operator[](int offSet) const{ return pType[offSet]; }

	// ������ �������
	int GetSize() const{ return m_Size; }
private:
	T* pType;
	int m_Size;
};

// ���������� ...

// ��������� �����������
template <class T>
Array<T>::Array(int size):
m_Size(size)
{
	pType = new T[size];
	
	for(int i=0; i<size; i++)
		pType[i] = 0;
}

// ����������� �����������
template <class T>
Array<T>::Array(const Array& rhs)
{
	m_Size = rhs.GetSize();
	pType = new T[m_Size];
	for(int i=0; i<m_Size; i++)
		pType[i] = rhs[i];
}

// �������� ������������
template <class T>
Array<T>&
Array<T>::operator=(const Array& rhs)
{
	if(this == &rhs)
		return *this;

	delete[] pType;
	m_Size = rhs.GetSize();
	pType = new T[m_Size];
	for(int i=0; i<m_Size; i++)
		pType[i] = rhs[i];
	return *this;
}

// ����������� ��������� 
int
main()
{
	Array<int> theArray; // �����
	Array<Animal> theZoo; // ������ ���������
	Animal* pAnimal;

	// ��������� �������
	for(int i=0; i<theArray.GetSize(); i++)
	{
		theArray[i] = i*2;
		pAnimal = new Animal(i*3);
		theZoo[i] = *pAnimal;
		delete pAnimal;
	}
	for(i=0; i<theArray.GetSize(); i++)
	{
		cout<<"theArray[" <<i <<"]:\t";
		cout<<theArray[i] <<"\t\t";
		cout<<"theZoo[" <<i <<"]:\t";
		theZoo[i].Display();
		cout<<endl;
	}

	return 0;
}
