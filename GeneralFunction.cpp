#include "GeneralFunction.h"

using namespace std;

/// <summary>
/// Проверка пользовательского ввода числа
/// </summary>
/// <returns></returns>
int CheckInt() {
	int tmp = 0;
	cin >> tmp;
	while (cin.fail()) {//функция в стандартной библиотеке C++, которая позволяет нам проверить, успешно ли прошло чтение данных из стандартного ввода
		cout << "Введено некорректное значение, попробуйте еще раз: ";
		cin.clear();  //снимает флаг ошибки с cin (чтобы будущие операции ввода-вывода работали корректно)
		cin.ignore(numeric_limits<streamsize> ::max(), '\n');  //устанавливает максимальное количество символов для игнорирования. ('\n' - прекращается игнорирование)
		cin >> tmp;
	}
	cin.ignore(numeric_limits<streamsize> ::max(), '\n');
	return tmp;
}
 
/// <summary>
/// Проверка на пустой ввод строки.
/// </summary>
/// <returns></returns>
string ReadStringWithoutWhitespace() {
	string input;
	while (true) {
		getline(cin, input);  //Чтобы считать всю строку, можно применить метод `getline()`. Он принимает два объекта — `std::cin` и переменную, в которую надо считать строку.
		istringstream iss(input);  //istringstream - поток ввода, работающий с строками.
		if (iss >> input && !isspace(input[0])) { //Функция isspace проверяет параметр сharacter, является ли он символом пробела.знак >> позволяет извлекать данные из строки по указанному формату
			return input;
		}
		else {
			cout << "Ошибка: входные данные не должны содержать пробелов. Повторите попытку ввода." << endl;
		}
	}
}

/// <summary>
/// Проверка файла
/// </summary>
/// <param name="FileName"></param>
/// <returns></returns>
bool FileExists(string FileName) { //проверяет существование указанного файла или каталога 
	const char* path = FileName.c_str();
	if (!_access(path, 0)) { //access - Проверка прав доступа к файлу.
		return true;
	}
	else {
		return false;
	}
}

/// <summary>
/// Чтение из файла
/// </summary>
/// <param name="FileName"></param>
/// <returns></returns>
bool OnlyRead(string FileName) {
	const char* path = FileName.c_str(); //Функция c_str () возвращает указатель на символьный массив, который содержит строку объекта стринг (string) в том виде, в котором она размещалась бы, во встроенном строковом типе.
	if (_access(path, 2)) {
		return true;
	}
	else
		return false;
}

/// <summary>
/// Проверка на допустимые имена
/// </summary>
/// <param name="filename"></param>
/// <returns></returns>
bool IsValidFilename(const string& Filename) {
	static const regex pattern("^[a-zA-Z0-9_\\-\\.]+$");
	return regex_match(Filename, pattern);
}

/// <summary>
/// Полученние имени файла
/// </summary>
/// <param name="path"></param>
/// <returns></returns>
string GetFilename(const string path) {
	size_t pos = path.find_last_of("\\"); // Ищем последний символ '/' или '\'
	if (pos != string::npos) { // Если символ найден
		return path.substr(pos + 1); // Возвращаем имя файла после найденного символа
	}
	return path; // Если символ не найден, возвращаем исходный путь
}

/// <summary>
/// Проверка на зарезервированные имена
/// </summary>
/// <param name="FileName"></param>
/// <returns></returns>
bool IsReservedFileName(string FileName) {
	const int quantityOfReservedNames = 22;
	string ReservedNames[quantityOfReservedNames] = { "con", "prn" , "aux" , "nul" , "com1" , "com2" , "com3" , "com4" , "com5" , "com6" , "com7" , "com8" , "com9" ,
	"lpt1", "lpt2", "lpt3", "lpt4", "lpt5", "lpt6", "lpt7", "lpt8", "lpt9" };

	size_t pos = FileName.find_first_of(".");
	if (pos != string::npos) { //string::npo - Эта константа часто используется для индикации отсутствия позиции символа или подстроки в строке.
		FileName = FileName.substr(0, pos); //для извлечения подстрок из определенной строки - substr()
	}

	for (int i = 0; i < quantityOfReservedNames; i++) {
		if (_stricmp(FileName.c_str(), ReservedNames[i].c_str()) == 0) { //функция stricmp() осуществляет лексикографическое сравнение двух строк, оканчивающихся нулевыми символами.
			return true;
		}
	}
	return false;
}

/// <summary>
/// Копирование массива
/// </summary>
/// <param name="copyArray"></param>
/// <param name="array"></param>
/// <param name="strings"></param>
/// <param name="columns"></param>
void CopyArray(int** copyArray, int** array, int strings, int columns) {
	for (int i = 0; i < strings; i++) {
		for (int j = 0; j < columns; j++) {
			copyArray[i][j] = array[i][j];
		}
	}
}

/// <summary>
/// Печать массива
/// </summary>
/// <param name="array"></param>
/// <param name="strings"></param>
/// <param name="columns"></param>
void PrintArray(int** array, int strings, int columns) {
	for (int i = 0; i < strings; i++) {
		for (int j = 0; j < columns; j++) {
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
}