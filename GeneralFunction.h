#pragma once
#include <iostream> //������ � ������ ������ ������
#include <fstream> //����������� ���������� �������, �������������� �������� iostreams ��� �������������������, ���������� �� ������� ������
#include <string> //������ �� ��������
#include <sstream> //��� ������ � Istringstream ���������� ���������� ������������ ���� <sstream>. 
#include <limits> //���������� � ��������� ��������������� �������� ����� ������
#include <io.h> //��� ������ � ������ � �������
#include <regex> //��� ������ � ����������� �����������, ��� ������� ������������ ��� ������ � ��������� ��������� ����������

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