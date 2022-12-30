#include <iostream>
#include "Arrays.h"

using namespace std;

int main()
{
	Arrays ars;
	char out;
	for (int i = 0; i < 26; i++)
	{
		/*
			ars.PushBack('Z');		//0 ( 1)
			ars.PushBack('Y');		//1 ( 2)
			ars.PushBack('X');		//2 ( 3)
			ars.PushBack('W');		//3 ( 4)
			ars.PushBack('V');		//4 ( 5)
			ars.PushBack('U');		//5 ( 6)
			ars.PushBack('T');		//6 ( 7)
			ars.PushBack('S');		//7 ( 8)
			(...)
			ars.PushBack('A');		//25(26)
		*/
		//ars.PushFront(65 + i);
		/*
			ars.PushBack('A');		//0 ( 1)
			ars.PushBack('B');		//1 ( 2)
			ars.PushBack('C');		//2 ( 3)
			ars.PushBack('D');		//3 ( 4)
			ars.PushBack('E');		//4 ( 5)
			ars.PushBack('F');		//5 ( 6)
			ars.PushBack('G');		//6 ( 7)
			ars.PushBack('H');		//7 ( 8)
			(...)
			ars.PushBack('Z');		//25(26)
		*/
		ars.PushBack(65 + i);
	}

	ars.PrintAll();

	// (...)Q R S T U(...) >>> (...)Q R [J] S T U(...)
	ars.Insert(18, 'J');

	ars.PrintAll();

	// 'H'
	// (...)F G [H] I J K(...) >>> (...)F G I J K(...)
	ars.Remove(7, &out);

	ars.PrintAll();

	int currentCount = ars.Count();
	cout << "POP DATA : [ ";
	for (int i = 0; i < currentCount; i++)
	//for (int i = 0; i < ars.Count(); i++)
	//* 이렇게하면 갯수가 i최대 값이 같이 줄어들어 절반만 출력한다.
	{
		ars.PopFront(&out);
		//ars.PopBack(&out);
		cout << out << " ";
	}
	cout << "]" << endl;

	ars.PrintAll();

	return 0;
}