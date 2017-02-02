#include <iostream>
#include <time.h>
#include <string>

using namespace std;

struct Card
{
	string To;
	//int ToNumber;
	string From;
	//int FromNumber;
};

char *Sitys[] =
{
	"Moscow", "StPetersburg", "Novosibirsk", "Nizhninovgorod", "Yekaterinburg", "Samara", "Omsk", "Kazan", "Chelyabinsk", "RostovonDon", "Ufa", "Perm",
	"Volgograd", "Krasnoyarsk", "Voronezh", "Saratov", "Tolyatti", "Krasnodar", "Izhevsk", "Yaroslavl", "Ulyanovsk", "Barnaul", "Irkutsk", "Khabarovsk", "Tyumen", "Vladivostok", "Novokuznetsk", "Orenburg", "Kemerovo", "Lipetsk", "NaberezhnyeChelny", "Ryazan", "Tomsk", "Penza", "Astrakhan"
};

const int SityCount = 34;



int main()
{
	srand(time(0));
	int r, rStart;
	int SityCoeff[SityCount];
	bool FSity = false, TSity = false;
	do
	{
		system("cls");

		for (int i = 0; i < SityCount; i++)
		{
			SityCoeff[i] = 3;
		}
		//Generate cards
		Card* Cards = new Card[SityCount];
		rStart = rand() % SityCount;
		for (int i = 0; i < SityCount; i++)
		{
			do
			{
				r = rand() % SityCount;
				FSity = false;
				if (i == rStart)
				{
					Cards[i].From = ""; FSity = true;
				}
				else if (SityCoeff[r] == 3)
				{
					Cards[i].From = Sitys[r];
					SityCoeff[r] = 1;
					FSity = true;
				}
				else if (SityCoeff[r] == 2)
				{
					Cards[i].From = Sitys[r];
					SityCoeff[r] = 0;
					FSity = true;
				}
				else { /*cout << "From sity error" << endl;*/ } //for control

			} while (FSity == false);

			do
			{
				r = rand() % SityCount;
				TSity = false;
				if (Cards[i].From == Sitys[r])
				{
					TSity = false;
				}
				else if (SityCoeff[r] == 3)
				{
					Cards[i].To = Sitys[r];
					SityCoeff[r] = 2;
					TSity = true;
				}
				else if (SityCoeff[r] == 1)
				{
					Cards[i].To = Sitys[r];
					SityCoeff[r] = 0;
					TSity = true;
				}
				else if (SityCoeff[r] == 2 && i >= SityCount - 2)//Need fix
				{
					Cards[i].To = Sitys[r];
					SityCoeff[r] = 0;
					TSity = true;
				}
				else { /*cout << "To sity error" << endl;*/ } //for control
			} while (TSity == false);
		}
		//Print what hawe
		for (int i = 0; i < SityCount; i++)
		{
			cout << Cards[i].From << "->" << Cards[i].To << endl;
		}
		//Try to found start card
		Card TempCard;
		for (int i = 0; i < SityCount; i++)
		{
			if (Cards[i].From == "")
			{
				TempCard = Cards[i];
				Cards[i] = Cards[0];
				Cards[0] = TempCard;
			}
		}

		//Sort
		for (int i = 0; i < SityCount; i++)
		{
			if (i == SityCount - 1) { cout << "-------------------------" << endl; break; }
			for (int k = 0; k < SityCount; k++)
			{
				if (Cards[i].To == Cards[k].From)
				{
					TempCard = Cards[i + 1];
					Cards[i + 1] = Cards[k];
					Cards[k] = TempCard;
				}
			}
		}




		//Print sort
		for (int i = 0; i < SityCount; i++)
		{
			if(i>=SityCount-1){}//arr end
			else if (Cards[i].To == Cards[i + 1].From)
			{
				cout << Cards[i].From << "->" << Cards[i].To << ",";
			}
			else
			{
				//cout << Cards[i].From << "->" << Cards[i].To << endl; 
			}
		}

		cout << endl;
		cout << endl;
		cout << "Press enter to repit. 'q' to out." << endl;
		delete[]Cards;
	}while (getchar() != 'q');

	return 0;
}

