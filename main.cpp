#include<iostream>
#include "Reservoir.h"
#include<time.h>

void draw(int counter);

int main () {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);// #include <Windows.h>
	SetConsoleOutputCP(1251); // #include <Windows.h>
	std::cout << "\t\tHome Work № 5. Reservoirs "<< std::endl << std::endl;
	draw(80);

// Count of reservoirs
	int countreservoir = 4;

// Count of country
	int countrountry = 1;

// ID of reservoir
	int number = 1;

// Number of menu
	int number_menu = 0;

// Filling in the database
Reservoir* vodoem = new Reservoir[countreservoir]
{
	{number++, 1001, "Аслыкуль",3.31, 7.1, 8, "озеро", "Село Давлеканово, республика Башкортостан"},
	{number++, 2001, "Юмагузинское водохранилище", 0.4, 124, 26, "водохранилище","село Юмагузино, республика Башкортостан"},
	{number++, 4100, "Азовское море", 20, 180, 7.4, "море", "Краснодарский край"},
	{number++, 3405, "Черное море", 100, 310, 25, "море", "Краснодарский край"}
};

Country* cname = new Country[countrountry]
{
	{countrountry++, "Russia"},
};
do {
	std::cout << "\tSelect an action\n";
	std::cout << "\t1: List of reservoirs" << std::endl;
	std::cout << "\t2: Adding of reservoirs. " << std::endl;
	std::cout << "\t3: Deleting an reservoirs " << std::endl;
	std::cout << "\t4: Calculation of the volume of the reservoir " << std::endl;
	std::cout << "\t5: Determination of the water surface area (Square)" << std::endl;
	std::cout << "\t6: Checking the type of reservoir" << std::endl;
	std::cout << "\t7: Comparison of the water surface area" << std::endl;
	std::cout << "\t8: Exit of program" << std::endl;
	std::cout << "\t ==>";
	std::cin >> number_menu;
	switch (number_menu)
	{
	case 1: {
		draw(80);
		std::cout << "\tReservoir's List\n\n";
		cname->Show_Country();
		std::cout << std::endl;

		std::cout << "+-------+----------------------------+------------+-----------+------------+-----------------+-------------------------------------------------+\n";
		std::cout << "|Code   | Name                       | Width, km  | Length, km| Depth, m   | Type            | Additional information                          |\n";
		std::cout << "+-------+----------------------------+------------+-----------+------------+-----------------+-------------------------------------------------+\n";

		for (size_t i = 0; i < countreservoir; i++)
		{
			vodoem[i].Show_Reservoir();

		}
		std::cout << " +-------+----------------------------+------------+-----------+------------+-----------------+-------------------------------------------------+\n";
		_getch();
		break;
	}
	case 2:
		vodoem->AddReservoir(vodoem, &countreservoir, &number);
		_getch;
		break;
	case 3:
		vodoem->DeleteReservoir(vodoem, &countreservoir, &number);
		_getch;
		break;
	case 4: {
		int _code;
		int idarray = NULL;
		int check = 0;

		std::cout << "Calculation of the volume of the reservoir\n";
		std::cout << "Enter the cadastral number of the reservoir: ";
		std::cin >> _code;
		vodoem->SearchVolume(vodoem, countreservoir, _code, &idarray, &check);
		if (check)
		{
			std::cout << "Volume of the reservoir :";
			vodoem[idarray].Show_One_Reservoir();
			std::cout << " = " << vodoem[idarray].Getvolume() << " km3\n";
		}
		else
			std::cout << "Nothing was found for the query...";
		_getch();
		break;
	}
	case 5:{
		int _code;
		int idarray = NULL;
		int check = 0;
		std::cout << "Determination of the water surface area\n";
		std::cout << "Enter the cadastral number of the reservoir: ";
		std::cin >> _code;
		vodoem->SearchArea(vodoem, countreservoir, _code, &idarray, &check);
		if (check)
		{
			std::cout << "The area of the reservoir : ";
			vodoem[idarray].Show_One_Reservoir();
			std::cout << " = " << vodoem[idarray].Getarea() << " km2.\n";
		}
		else
			std::cout << "Nothing was found for the query...";
		_getch();
		break;
	}
	case 6: {
		bool checktip = 0;
		int code1;
		int code2;
		int idarray1 = NULL;
		int idarray2 = NULL;
		int checkcode1 = 0;
		int checkcode2 = 0;

		std::cout << "Checking whether reservoirs belong to the same type\n";
		std::cout << "Enter the cadastral number of the first reservoir: ";
		std::cin >> code1;
		std::cout << "Enter the cadastral number of the second reservoir: ";
		std::cin >> code2;

		//check for the presence of reservoirs in the database

		for (int k = 0; k < countreservoir; k++)
		{
			if (vodoem[k].Getcode() == code1)
			{
				checkcode1++;
			}
		}
		if (checkcode1)
		{
			std::cout << "The first reservoir was found in the database\n";
		}
		else
		{
			std::cout << "The first reservoir was not found in the database\n";
		}

		for (size_t k = 0; k < countreservoir; k++)
		{
			if (vodoem[k].Getcode() == code2)
			{
				checkcode2++;
			}
		}

		if (checkcode2)
		{
			std::cout << "The second reservoir was found in the database\n";
		}

		else
		{
			std::cout << "The second reservoir was not found in the database\n";
		}

		if (checkcode1 && checkcode2)
		{
			std::cout << "Both reservoirs were found in the database\n";
			std::cout << "We are starting to compare the types of reservoirs\n\n";

			checktip = vodoem->CheckTip(vodoem, countreservoir, code1, code2, &idarray1, &idarray2);

			if (checktip)
			{
				std::cout << "Reservoirs ";
				vodoem[idarray1].Show_One_Reservoir();
				std::cout << " and ";
				vodoem[idarray2].Show_One_Reservoir();
				std::cout << " they have a common type - ";
				vodoem[idarray1].Show_Tip();
			}

			else
			{
				std::cout << "Reservoirs have different types\n";
				vodoem[idarray1].Show_One_Reservoir();
				std::cout << " type - ";
				vodoem[idarray1].Show_Tip();
				std::cout << std::endl;
				vodoem[idarray2].Show_One_Reservoir();
				std::cout << " type - ";
				vodoem[idarray2].Show_Tip();
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << "Enter the correct data and repeat your request...\n";
		}
		_getch();
		break;
	}
	case 7: {

		std::cout << "Comparison of the water surface area of reservoirs of the same type..\n";
		vodoem->AutoSearchArea(vodoem, countreservoir);
		std::cout << "Automatic updating of the area for all reservoirs is completed\n";
		std::cin.ignore();
		char charsearch[30] = "";
		std::cout << "Enter the type of reservoir to compare:";
		std::cin.getline(charsearch, 30);
		vodoem->SearchAreaTip(vodoem, charsearch, countreservoir);
		_getch();
		break;
	}
	case 8: {
		delete[] vodoem;
		std::cout << "\tExit from program...." << std::endl;
		_getch;
		return 0;
		break;
	}
	default:
		std::cout << "\tChoose correctly !!!" << std::endl;
	}
} while (number_menu != 8);

return 0;
};

void draw(int counter) {
	std::cout << "\t";
	for (int i = 0; i < counter; i++) {
		std::cout << "*";
	}
	std::cout << '\n';
}