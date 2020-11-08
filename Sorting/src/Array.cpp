#include "Array.h"
#include <cmath>
#include <time.h>

void Array::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

Array::Array()
	:m_State(State::None),
	m_Length(0)
{
	m_ArrOriginal = nullptr;
	m_ArrSorted = nullptr;

}

Array::~Array()
{
	if (m_ArrOriginal)
	{
		delete[] m_ArrOriginal;
	}
	if (m_ArrSorted)
	{
		delete[] m_ArrSorted;
	}
}

int Array::getLength() const
{
	return m_Length;
}

int Array::getSize() const
{
	return 0;
}

State Array::getState() const
{
	return m_State;
}


void Array::GenerateRandomData(int size)
{
	if (m_ArrOriginal)
	{
		delete[] m_ArrOriginal;
	}

	m_ArrOriginal = new int[size];
	
	srand((unsigned int)time(NULL));

	for (int i = 0; i < size; i++)
	{
		m_ArrOriginal[i] = rand() % size;
	}

	m_State = State::Random;
}

void Array::GenerateSortedData(int size)
{
	if (m_ArrOriginal)
	{
		delete[] m_ArrOriginal;
	}

	m_ArrOriginal = new int[size];

	for (int i = 0; i < size; i++)
	{
		m_ArrOriginal[i] = i;
	}

	m_State = State::Sorted;
}

void Array::GenerateReverseData(int size)
{
	if (m_ArrOriginal)
	{
		delete[] m_ArrOriginal;
	}

	m_ArrOriginal = new int[size];

	for (int i = 0; i < size; i++)
	{
		m_ArrOriginal[i] = size - 1 - i;
	}

	m_State = State::Reversed;
}

void Array::GenerateNearlySortedData(int size)
{
	if (m_ArrOriginal)
	{
		delete[] m_ArrOriginal;
	}

	m_ArrOriginal = new int[size];

	for (int i = 0; i < size; i++)
	{
		m_ArrOriginal[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % size;
		int r2 = rand() % size;
		swap(m_ArrOriginal[r1], m_ArrOriginal[r2]);
	}

	m_State = State::NearlySorted;
}
