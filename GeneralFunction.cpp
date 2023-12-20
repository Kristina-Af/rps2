#include "GeneralFunction.h"

using namespace std;

/// <summary>
/// �������� ����������������� ����� �����
/// </summary>
/// <returns></returns>
int CheckInt() {
	int tmp = 0;
	cin >> tmp;
	while (cin.fail()) {//������� � ����������� ���������� C++, ������� ��������� ��� ���������, ������� �� ������ ������ ������ �� ������������ �����
		cout << "������� ������������ ��������, ���������� ��� ���: ";
		cin.clear();  //������� ���� ������ � cin (����� ������� �������� �����-������ �������� ���������)
		cin.ignore(numeric_limits<streamsize> ::max(), '\n');  //������������� ������������ ���������� �������� ��� �������������. ('\n' - ������������ �������������)
		cin >> tmp;
	}
	cin.ignore(numeric_limits<streamsize> ::max(), '\n');
	return tmp;
}
 
/// <summary>
/// �������� �� ������ ���� ������.
/// </summary>
/// <returns></returns>
string ReadStringWithoutWhitespace() {
	string input;
	while (true) {
		getline(cin, input);  //����� ������� ��� ������, ����� ��������� ����� `getline()`. �� ��������� ��� ������� � `std::cin` � ����������, � ������� ���� ������� ������.
		istringstream iss(input);  //istringstream - ����� �����, ���������� � ��������.
		if (iss >> input && !isspace(input[0])) { //������� isspace ��������� �������� �haracter, �������� �� �� �������� �������.���� >> ��������� ��������� ������ �� ������ �� ���������� �������
			return input;
		}
		else {
			cout << "������: ������� ������ �� ������ ��������� ��������. ��������� ������� �����." << endl;
		}
	}
}

/// <summary>
/// �������� �����
/// </summary>
/// <param name="FileName"></param>
/// <returns></returns>
bool FileExists(string FileName) { //��������� ������������� ���������� ����� ��� �������� 
	const char* path = FileName.c_str();
	if (!_access(path, 0)) { //access - �������� ���� ������� � �����.
		return true;
	}
	else {
		return false;
	}
}

/// <summary>
/// ������ �� �����
/// </summary>
/// <param name="FileName"></param>
/// <returns></returns>
bool OnlyRead(string FileName) {
	const char* path = FileName.c_str(); //������� c_str () ���������� ��������� �� ���������� ������, ������� �������� ������ ������� ������ (string) � ��� ����, � ������� ��� ����������� ��, �� ���������� ��������� ����.
	if (_access(path, 2)) {
		return true;
	}
	else
		return false;
}

/// <summary>
/// �������� �� ���������� �����
/// </summary>
/// <param name="filename"></param>
/// <returns></returns>
bool IsValidFilename(const string& Filename) {
	static const regex pattern("^[a-zA-Z0-9_\\-\\.]+$");
	return regex_match(Filename, pattern);
}

/// <summary>
/// ���������� ����� �����
/// </summary>
/// <param name="path"></param>
/// <returns></returns>
string GetFilename(const string path) {
	size_t pos = path.find_last_of("\\"); // ���� ��������� ������ '/' ��� '\'
	if (pos != string::npos) { // ���� ������ ������
		return path.substr(pos + 1); // ���������� ��� ����� ����� ���������� �������
	}
	return path; // ���� ������ �� ������, ���������� �������� ����
}

/// <summary>
/// �������� �� ����������������� �����
/// </summary>
/// <param name="FileName"></param>
/// <returns></returns>
bool IsReservedFileName(string FileName) {
	const int quantityOfReservedNames = 22;
	string ReservedNames[quantityOfReservedNames] = { "con", "prn" , "aux" , "nul" , "com1" , "com2" , "com3" , "com4" , "com5" , "com6" , "com7" , "com8" , "com9" ,
	"lpt1", "lpt2", "lpt3", "lpt4", "lpt5", "lpt6", "lpt7", "lpt8", "lpt9" };

	size_t pos = FileName.find_first_of(".");
	if (pos != string::npos) { //string::npo - ��� ��������� ����� ������������ ��� ��������� ���������� ������� ������� ��� ��������� � ������.
		FileName = FileName.substr(0, pos); //��� ���������� �������� �� ������������ ������ - substr()
	}

	for (int i = 0; i < quantityOfReservedNames; i++) {
		if (_stricmp(FileName.c_str(), ReservedNames[i].c_str()) == 0) { //������� stricmp() ������������ ������������������ ��������� ���� �����, �������������� �������� ���������.
			return true;
		}
	}
	return false;
}

/// <summary>
/// ����������� �������
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
/// ������ �������
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