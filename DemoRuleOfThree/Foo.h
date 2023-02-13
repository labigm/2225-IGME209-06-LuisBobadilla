#pragma once
#include <iostream>
class Foo
{
public:
	int* m_pContentList = nullptr;
	int m_iListSize = 0;
public:
	Foo(int a_iSize)
	{
		m_iListSize = a_iSize;
		m_pContentList = new int[m_iListSize];
		for (int i = 0; i < m_iListSize; i++)
		{
			m_pContentList[i] = i;
		}
	}
	Foo(Foo& a_other)
	{
		this->m_iListSize = a_other.m_iListSize;

		//shallow copy (copy address)
		this->m_pContentList = a_other.m_pContentList; 

		//full copy (copy contents)
		//m_pContentList = new int[m_iListSize];
		//for (int i = 0; i < m_iListSize; i++)
		//{
		//	m_pContentList[i] = a_other.m_pContentList[i];
		//}
	}
	void Print(void)
	{
		for (int i = 0; i < m_iListSize; i++)
		{
			std::cout << m_pContentList[i];
			std::cout << ", ";
		}
		std::cout << "\n";
	}
	~Foo()
	{
		if (m_pContentList != nullptr)
		{
			delete[] m_pContentList;
			m_pContentList = nullptr;
		}
	}
};