#pragma once
#include "GeneralFunction.h"

using namespace std;


class ISort {
protected:
public:
	/// <summary>
	/// Сортировка вставками
	/// </summary>
	/// <param name="array"></param>
	/// <param name="rows"></param>
	/// <param name="columns"></param>
	virtual void Sort(int** array, int rows, int columns) = 0;
	virtual ~ISort() = default;
};

class InsertSort : public ISort {
public:
	/// <summary>
	/// Сортировка вставками
	/// </summary>
	/// <param name="array"></param>
	/// <param name="rows"></param>
	/// <param name="columns"></param>
	void Sort(int** array, int rows, int columns) override;
};