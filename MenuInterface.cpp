#include "MenuInterface.h"
#include "ModuleTests.h"

using namespace std;

void ShowGreeting()
{
	system("cls");
	cout << "\t" << endl
		<< "���������� �������� ������������� � ��������� ����� ���������" << endl
		<< "425 ������, 2 ����" << endl
		<< "�������: 14 ���������� ��������� / Insertion sort" << endl
		<< "------------------------------------------------------------------" << endl;
	cout << "������� ������������ ��� �����:" << endl << "1 - ������ ������ ���������." << endl << "2 - ��������� ��������� �����." << endl
		<< "3 - ��������� ������ ���������" << endl << ">> ";
}


void InputMethodMenu() {
	bool fileIsCorrect = true;
	int strings = 0;
	int columns = 0;
	int input = 0;
	int intTmp;
	string temp;
	string path;
	string value;
	int* tmp = nullptr; //nullptr - ��������� �������� ���������
	int** array = nullptr;
	ifstream file;
	int choseMethod = 0;

	do {
		cout << "�������� ������ ����� ������:" << endl << "1 - ���������� ������� �� �����." << endl
			<< "2 - ���������� ������� �������." << endl << "3 - ���������� ������� ���������� ������� � ��������� �� -100 �� 100." << endl
			<< "4 - ����� � ������� ���� ���������." << endl << ">> ";
		choseMethod = CheckInt();

		switch (choseMethod) {
		case FromFile:
			cout << "������� ���� �����:" << endl << ">> ";
			path = ReadStringWithoutWhitespace();

			while (!FileExists(path)) {
				cout << "������ ��� �������� �����! ���������� ������ ���� �����." << endl << "> ";
				path = ReadStringWithoutWhitespace();
			}

			file.open(path);
			cout << "���� ������� ������!" << endl;

			if (file.peek() == ifstream::traits_type::eof()) { //traits_type - ���� ����������� ��������� � ��������������� �������� �����, eof - ����� ������, ���� ���� ����, � ���� ���� �� ����, �� ������� ����
				cout << "���� ����. ��������� ���� � ���������� ��� ���." << endl;
			}
			else {
				while (!file.eof()) {
					file >> intTmp;
					if (file.fail()) { //�������� ������ ��� ������ �����
						file.clear();
						fileIsCorrect = false;
						break;
					}
				}

				file.clear();
				file.seekg(0);

				while (!file.eof()) {
					if ((input = file.get()) == '\n' || input == EOF) { strings += 1; } //eof - ���������� ��������� ��������
				}

				file.clear();
				file.seekg(0); //file.seekg - ��������� ������ ������������ ������� � �����.
				tmp = new int[strings];

				for (int i = 0; i < strings; i++) {
					tmp[i] = 0; 
					getline(file, temp);
					istringstream stream(temp); //istringstream - �������������� ����� � ����� ������

					while (stream >> value) {
						tmp[i]++;
					}

					columns = tmp[i];
				}

				file.clear();
				file.seekg(0);

				for (int i = 0; i < strings - 1; i++) {
					if (tmp[i] != tmp[i + 1]) {
						 fileIsCorrect = false;
					}
				}

				delete[] tmp;
				tmp = nullptr;

				if (!fileIsCorrect) {
					cout << "� ����� ���������� ����������� ����������� �������. ��������� ���� � ���������� ��� ���." << endl;
					file.close();
					choseMethod = ReturnMenu;
					break;
				}

				array = new int* [strings];

				for (int i = 0; i < strings; i++) {
					array[i] = new int[columns];
				}

				for (int i = 0; i < strings; i++) {
					for (int j = 0; j < columns; j++) {
						file >> array[i][j];
					}
				}

				CompleteControlWork(array, strings, columns);
			}

			file.close();
			choseMethod = ReturnMenu;
			break;

		case ManualMethod:
			cout << "������� ������ �������: ";
			strings = CheckInt();
			while (strings < 1) {
				cout << "���������� ����� �� ����� ���� ������ ����. ���������� ������ ������ �����." << endl;
				strings = CheckInt();
			}
			columns = strings;

			array = new int* [strings];
			for (int i = 0; i < strings; i++) {
				array[i] = new int[columns];
			}

			for (int i = 0; i < strings; i++) {
				for (int j = 0; j < columns; j++) {
					cout << "���� " << i + 1 << " ������ " << j + 1 << " �������." << endl;
					array[i][j] = CheckInt();
				}
			}

			CompleteControlWork(array, strings, columns);
			choseMethod = ReturnMenu;
			break;

		case RandomMethod:
			cout << "������� ���������� ����� �������: ";
			strings = CheckInt();

			while (strings < 1) {
				cout << "���������� ����� �� ����� ���� ������ ����. ���������� ������ ������ �����." << endl;
				strings = CheckInt();
			}

			cout << "������� ���������� �������� �������: ";
			columns = CheckInt();

			while (columns < 1) {
				cout << "���������� �������� �� ����� ���� ������ ����. ���������� ������ ������ �����." << endl;
				columns = CheckInt();
			}

			array = new int* [strings];
			for (int i = 0; i < strings; i++) {
				array[i] = new int[columns];
			}

			for (int i = 0; i < strings; i++) {
				for (int j = 0; j < columns; j++) {
					array[i][j] = -100 + rand() % 201;
				}
			}
			CompleteControlWork(array, strings, columns);
			choseMethod = ReturnMenu;
			break;

		case ReturnMenu:
			break;

		default:
			cout << "������ ������ ��� � ����, ���������� ��� ���" << endl;
			break;
		}
		if (choseMethod != ReturnMenu) system("pause");
	} while (choseMethod != ReturnMenu);
}

void CompleteControlWork(int** array, int strings, int columns) {
	int** copyArray = nullptr; //�������� ���������� ������� � �������
	copyArray = new int* [strings];

	for (int i = 0; i < strings; i++) {
		copyArray[i] = new int[columns];
	}

	cout << endl << "�������� ������:" << endl;
	PrintArray(array, strings, columns);

	cout << endl << "���������� ���������:" << endl;
	CopyArray(copyArray, array, strings, columns);

	InsertSort c;
	c.Sort(copyArray, strings, columns);
	PrintArray(copyArray, strings, columns);
	cout << endl;
}


void StartProgram() {
	setlocale(LC_ALL, "RU");
	srand(static_cast<unsigned int>(time(NULL)));
	int userChoise = 0;
	do {
		system("cls");
		ShowGreeting();
		userChoise = CheckInt();
		switch (userChoise) {

			case StartProgramm:
				InputMethodMenu();
				break;

			case StartModuleTests:
				CompleteModuleTests();
				break;

			case StopProgramm:
				break;

			default:
				cout << "������ ������ ��� � ����, ���������� ��� ���" << endl;
				break;
		}
		if (userChoise != StopProgramm)	system("pause");
	} while (userChoise != StopProgramm);
}