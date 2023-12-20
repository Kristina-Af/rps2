#include "ISort.h"

using namespace std;

/// <summary>
/// Сортировка вставками
/// </summary>
/// <param name="array"></param>
/// <param name="rows"></param>
/// <param name="columns"></param>
void InsertSort::Sort(int** array, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns - 1; j++) {
			for (int k = j + 1; k > 0; k--) {
				if (array[i][k] < array[i][k - 1]) {
					swap(array[i][k], array[i][k - 1]);
				}
			}
		}
	}
}