#pragma once
#include <iostream>
class Foo
{
public:
	int* m_pContentList = nullptr;
	int m_iListSize = 0;
public:
	Foo(int a_iSize);
	Foo(Foo& a_other);
	void Print(void);
	~Foo();
	Foo& operator=(Foo& a_other);
	void Release(void);
};