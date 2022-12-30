#include "Arrays.h"
#include <iostream>
using namespace std;

Arrays::Arrays()
{
	count = 0;
	buffer = new char[bufferSize];
}

Arrays::~Arrays()
{
	// memset(buffer, 0, sizeof(T)*0); �̰͵� �����Ѱ�?
	Clear();
	delete[] buffer;
}

bool Arrays::PushFront(char data)
{
	if (IsFull()) {
		bufferSize *= 2;
		char* extansionBuffer = new char[bufferSize];
		memcpy(extansionBuffer, buffer, sizeof(char) * count);
		delete[] buffer;
		buffer = extansionBuffer;
	}

	memcpy(buffer + 1, buffer, sizeof(char) * count);
	buffer[0] = data;
	count++;
	return true;
}

bool Arrays::PushBack(char data)
{
	if (IsFull()) {
		bufferSize *= 2;
		char* extansionBuffer = new char[bufferSize];
		memcpy(extansionBuffer, buffer, sizeof(char) * count);
		delete[] buffer;
		buffer = extansionBuffer;
	}
	buffer[count] = data;	// count == maxIndex+1
	count++;
	return true;
}

bool Arrays::PopFront(char* out)
{
	if (IsEmpty()) {
		cout << "This Buffer Is Empty" << endl;
		return false;
	}

	*out = buffer[0];
	count--;
	memcpy(buffer, buffer + 1, sizeof(char) * count);	// �ּҸ� +1��ŭ �̵�
	return true;
}

bool Arrays::PopBack(char* out)
{
	if (IsEmpty()) {
		cout << "This Buffer Is Empty" << endl;
		return false;
	}
	//��ǻ�Ͱ��п����� ������ ������ '����'�̴�.
	count--;
	*out = buffer[count];	// count == maxIndex+1
	//memcpy(buffer, buffer, sizeof(char) * count);
	return true;
}

bool Arrays::Insert(int pos, char data)
{
	if (IsFull()) {
		bufferSize *= 2;
		char* extansionBuffer = new char[bufferSize];
		memcpy(extansionBuffer, buffer, sizeof(char) * count);
		delete[] buffer;
		buffer = extansionBuffer;
	}
	/*
	Before Memcpy - Example Pos = 4(5)
	������������������������������������������������������������������
	��char00��char01��char02��char03��char04��char05��char06��char07��
	������������������������������������������������������������������
	*/

	memcpy(buffer + pos + 1, buffer + pos, sizeof(char) * count);
	/*
	After Memcpy
									|<----------- Copied Buffer ----------->|
	��������������������������������������������������������������������������
	��char00��char01��char02��char03�� +POS ��char04��char05��char06��char07��
	��������������������������������������������������������������������������
	*/
	buffer[pos] = data;
	/*
	Insert Data At Pos
	��������������������������������������������������������������������������
	��char00��char01��char02��char03�� data ��char04��char05��char06��char07��
	��������������������������������������������������������������������������
	*/
	count++;
	return true;
}

bool Arrays::Remove(int pos, char* out)
{
	if (IsEmpty()) {
		cout << "This Buffer Is Empty" << endl;
		return false;
	}
	/*
	Before Memcpy - Example Pos = 4(5)
	��������������������������������������������������������������������������
	��char00��char01��char02��char03�� -POS ��char05��char06��char07��char08��
	��������������������������������������������������������������������������
	*/
	count--;
	*out = buffer[pos];
	memcpy(buffer + pos, buffer + pos + 1, sizeof(char) * count);
	/*
	After Memcpy
									|<------ Composed Buffer ------>|
	������������������������������������������������������������������
	��char00��char01��char02��char03��char05��char06��char07��char08��
	������������������������������������������������������������������
	*/
	return false;
}

char& Arrays::operator[](int idx)
{
	return buffer[idx];
}

void Arrays::PrintAll()
{
	cout << "[ ";
	for (int i = 0; i < count; i++)
	{
		cout << buffer[i] << " ";
	}
	cout << "] - Data Count : " << count << endl;
}

bool Arrays::IsEmpty()
{
	return count == 0;
}

bool Arrays::IsFull()
{
	return count == bufferSize;
}


bool Arrays::Clear()
{
	// Q1 : ��ǻ�Ͱ��п����� ������ ������ '����'�̴�. �̰͵� �ش�ǳ�?
	// Q2 : BufferSize�� Ȯ��� ���� �״�� �α�� �����, ������ ��������?
	count = 0;
	return true;
}

int Arrays::Count()
{
	return count;
}