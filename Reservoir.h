#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <iomanip>


class Reservoir
{
private:

	int id; 
	int code;
	char* Reservoir_Name = nullptr;
	double width;
	double length;
	double depth;
	char* Dop_Info = nullptr;
	char* Tip = nullptr;
	long double area;
	long double volume;

public:

	Reservoir();
	//Reservoir(Reservoir*& vodoem, int* countreservoir, int* _number);
	Reservoir(int _id, int _code, const char* _name, double _width, double _length, double _depth, const char* _tip, const char* _info);

	//copy constructor
	Reservoir(const Reservoir& obj);

	void DeleteReservoir(Reservoir*& vodoem, int* countreservoir, int* _number);

	void AddReservoir(Reservoir*& vodoem, int* countreservoir, int* _number);

	// manual calculation of the area by the cadastral number of water S = a * b, where S is the area; a is the length and b is the width.
	 //used manually, after changing the data for a single position
	long double SearchArea(Reservoir* vodoem, const int countreservoir, int _code, int* _idarray, int* check);

	// automatic calculation of the area (if the base is large, it may take time)
	void AutoSearchArea(Reservoir* vodoem, const int countreservoir);


	//search for comparing the area of reservoirs of the same type (the search is case-sensitive)
	//if you enter one letter "p", all types with this letter will be included in the result
	void SearchAreaTip(Reservoir* vodoem, char const* charsearch, int const countreservoir);


	// calculation of the water volume (Q = width * length * depth, where Q is the volume; width * length * depth — width, length and depth)
	long double SearchVolume(Reservoir* vodoem, const int countreservoir, int _code, int* _idarray, int* check);

	bool CheckTip(Reservoir* vodoem, int const countreservoir, int _code1, int _code2, int* _idarray1, int* _idarray2);

	//output of the reservoir type
	void Show_Tip();

	//displaying reservoirs on the screen
	void Show_Reservoir();

	//displaying one reservoir on the screen
	void Show_One_Reservoir();

	~Reservoir();

	//getters

	int Getid();
	int Getcode();
	char* GetReservoir_Name();
	double Getwidth();
	double Getlength();
	double Getdepth();
	char* GetDop_Info();
	char* GetTip();
	long double Getarea();
	long double Getvolume();

	//setter
	void Setid(int _id);
	void Setcode(int _code);
	void SetReservoir_Name(char* _Reservoir_Name);
	void Setwidth(double _width);
	void Setlength(double _length);
	void Setdepth(double _depth);
	void SetDop_Info(char* _Dop_Info);
	void SetTip(char* _Tip);
	void Setarea(long double _area);
	void Setvolume(long double _volume);

};

//the Country class was created to scale the project to the level of reservoirs of different countries
// it is supposed to copy the names of reservoirs to the variable of the Reservoir * Name class
//with subsequent comparison of country-reservoirs

class Country
{
private:

	int cid;
	char* Country_Name = nullptr;
	Reservoir* Name = nullptr;

public:

	Country();
	Country(int _cid, const char* _name);

	Country(const Country& obj);

	void Show_Country();

	~Country();
};
