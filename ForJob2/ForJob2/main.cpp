#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;
//Sales: Id, ProductId, CustomerId, DateCreated.
struct Result
{
	int ProductID;
	int ClientID;
	time_t CreateDate;
};

struct DataBase
{
	int ID;
	int ProductID;
	int ClientID;
	time_t CreateData;
};
const int ProductCount = 30;
const int ClientCount = 300;

int AskProdukt(int, Result*,int);
void AskMenu(Result*,int);



int main()
{
	srand(time(0));
	char Buff[50];
	time_t TempTime;
	//Generate DataBase
	int TempNumber; 
	int ArrSize = rand() % (ClientCount*ProductCount) + (ClientCount + ProductCount);
	DataBase* Base = new DataBase[ArrSize];
	for (int i = 0; i < ArrSize; i++)
	{
		Base[i].ID = i;
		Base[i].ProductID = rand() % ProductCount;
		Base[i].ClientID = rand() % ClientCount;
		Base[i].CreateData = rand() % time(0);
	}
	//Write in data file
	ofstream DocWriteTXT("DataBase.txt");
	DocWriteTXT << ArrSize << "	" << "Id" << "	" << "ProductId" << "	" << "CustomerId" << "		" << "DateCreated" << endl;
	for (int i = 0; i < ArrSize; i++)
	{
		DocWriteTXT << "	" << Base[i].ID << "	" << Base[i].ProductID << "	" << Base[i].ClientID << "	" << Base[i].CreateData << endl;
	}
	DocWriteTXT.close();
	delete[]Base;//Clear memory
	//------------------------------------------------------------------------------------
	//Read from file
	ifstream DocReadTXT("DataBase.txt");

	DocReadTXT >> Buff;
	ArrSize = atoi(Buff);

	Result* ResultBase = new Result[ArrSize];
	DocReadTXT.getline(Buff,50);
	
	for (int i = 0; i < ArrSize; i++)
	{
		DocReadTXT >> Buff;
		DocReadTXT >> Buff;
		TempNumber = atoi(Buff);
		ResultBase[i].ProductID = TempNumber;
		DocReadTXT >> Buff;
		TempNumber = atoi(Buff);
		ResultBase[i].ClientID = TempNumber;
		DocReadTXT >> Buff;
		TempTime = (time_t)atoi(Buff);
		ResultBase[i].CreateDate = TempTime;
	}
	DocReadTXT.close();
	
	AskMenu(ResultBase, ArrSize);

	delete[]ResultBase;
	return 0;
}


void AskMenu(Result* DataBlock,int size)
{
	int ProdID;
	do
	{
		system("cls");
		cout << "Input produkt ID ";
		cin >> ProdID;
		system("cls");
		cout << "Produkt ID " << ProdID << ". Client from product " << AskProdukt(ProdID, DataBlock,size) << endl
			<< endl
			<< "For another produkt press any key. Input 'q' for out.";
		getchar();
	} while (getchar()!='q');


}

int AskProdukt(int ProdID,Result *DataBlock,int size)
{
	int Count=0, CBi=0;
	bool CopyClient;
	int ClientBase[ClientCount];
	Result ProductTemp;
	for (int i = 0; i < size; i++)
	{
		if (DataBlock[i].ProductID == ProdID)
		{
			for (int j = 0; j < ClientCount; j++)
			{
				if (ClientBase[j] == DataBlock[i].ClientID)
				{
					CopyClient = false;
					break;
				}
				else { CopyClient = true; }
			}
			if (CopyClient == true)
			{
				ClientBase[CBi] = DataBlock[i].ClientID;
				CBi++;
				Count++;
				ProductTemp = DataBlock[i];
				for (int k = i; k < size; k++)
				{
					if (ProductTemp.ClientID == DataBlock[k].ClientID&&ProductTemp.ProductID == DataBlock[k].ProductID&&ProductTemp.CreateDate >= DataBlock[k].CreateDate)
					{
						ProductTemp.CreateDate = DataBlock[k].CreateDate;
					}
				}
			}
		}
	}






	return Count;
}