#pragma once
class Arrays
{
private:
	int count;
	int bufferSize = 16;
	char data;

public:
	Arrays();
	~Arrays();
	
	bool PushFront(char data);
	bool PushBack(char data);

	bool PopFront(char* out);
	bool PopBack(char* out);

	bool Insert(int pos, char data);
	bool Remove(int pos, char* out);

	char& operator[](int idx);

	void PrintAll();
	bool IsEmpty();
	bool IsFull();
	bool Clear();
	int Count();
public:
	char* buffer;
};