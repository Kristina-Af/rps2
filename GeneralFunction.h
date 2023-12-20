#pragma once
#include <iostream> //чтение и запись потока данных
#include <fstream> //определение нескольких классов, поддерживающих операции iostreams дл€ последовательностей, хран€щихс€ во внешних файлах
#include <string> //работа со строками
#include <sstream> //ƒл€ работы с Istringstream необходимо подключить заголовочный файл <sstream>. 
#include <limits> //информаци€ о различных характеристиках числовых типов данных
#include <io.h> //дл€ работы с вводом и выводом
#include <regex> //дл€ работы с регул€рными выражени€ми, это шаблоны используемые дл€ поиска и обработки текстовой информации

using namespace std;

int CheckInt();
string ReadStringWithoutWhitespace();
bool FileExists(string FileName);
bool OnlyRead(string FileName);
bool IsValidFilename(const string& Filename);
string GetFilename(const string path);
bool IsReservedFileName(string FileName);
void CopyArray(int** copyArray, int** array, int rows, int columns);
void PrintArray(int** array, int rows, int columns);