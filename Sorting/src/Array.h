#pragma once
#include "Data.h"
class Array
{
private:
	int* m_ArrOriginal;
	int* m_ArrSorted;
	int m_Length;
	int m_Size;
	State m_State;

private:
	void swap(int& a, int& b);
	
public:
	Array();
	~Array();

public:
	int getLength() const;
	int getSize() const;
	State getState() const;

public:
	void GenerateRandomData(int size);
	void GenerateSortedData(int size);
	void GenerateReverseData(int size);
	void GenerateNearlySortedData(int size);
};

