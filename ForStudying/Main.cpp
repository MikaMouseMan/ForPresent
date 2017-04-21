//#include "math.h"
#include "iostream"

using namespace std;

//f(x) (x-2)^2;


void DeleniePopolamMetod()
{
	int chekCount = 0;
	bool answer = false;
	float e = 1, a, b, l, Xtemp, fXtemp, fx1, fx2, x1, x2;
// Зададим точность
	cout << "input accurancy e=";
	cin >> e;
	cout << endl;
//Зададим промежуток
	cout << "input point a=";
	cin >> a;
	cout << "input point b=";
	cin >> b;

	do
	{

		Xtemp = (a + b) / 2;
		l = b - a;

		fXtemp = (Xtemp - 2)*(Xtemp - 2);

		x1 = a + (l / 4); x2 = b - (l / 4);
		fx1 = (x1 - 2)*(x1 - 2);
		fx2 = (x2 - 2)*(x2 - 2);

		if (fx1 < fXtemp)
		{
			b = Xtemp; Xtemp = x1;
		}
		else if (fx2 < fXtemp)
		{
			a = Xtemp; Xtemp = x2;
		}
		else { a = x1; b = x2; }

		l = b - a;
		chekCount++;

		if (l < e) { answer = true; }
		else { answer = false; }
	} while (answer == false);

	cout << "Answer is " << Xtemp << endl;
	cout << "chek " << chekCount << " times." << endl;

}

void NewtonMetod()
{
	bool answer = false;
	float x0, x1, fx, fcx, e, fcxtemp, fxtemp;
	int k = 0;


	cout << "input accurancy e=";
	cin >> e;
	cout << "input start point x0=";
	cin >> x0;

	fx = (x0 - 2)*(x0 - 2);
	fcx = (fx - 2)*(fx - 2);
	fcxtemp= fcx+1;
	fxtemp = fx + 1;

	do
	{
		k++;
		fx = (x0 - 2)*(x0 - 2);
		x1 = x0 - (fx / fcx);
		fcx = (x1 - 2)*(x1 - 2);


		if (fcx <= e) { answer = true; }
		else if (fx < fcx) { x1++; x0 = x1; }
		else if (fcx > fcxtemp) { x1 += e; x0 = x1; }
		else { x0 = x1; }
		fcxtemp = fcx;
		fxtemp = fx;

	} while (answer==false);
	cout << "Answer is x=" << x1 << " Step count k=" << k << endl;
}

void GoldenSectionMetod()
{
	bool answer = false;

	float a, b, e, k1, k2, x1, x2, f1, f2, xmin, fmin;

	cout << "input accurancy e=";
	cin >> e;
	cout << "input point a=";
	cin >> a;
	cout << "input point b=";
	cin >> b;

	k1 = (3 - (sqrt(5))) / 2;
	k2 = (sqrt(5) - 1) / 2;

	x1 = a + k1*(b - a);
	x2 = a + k2*(b - a);

	f1 = (x1 - 2)*(x1 - 2);
	f2 = (x2 - 2)*(x2 - 2);


	do
	{
		if (b - a < e)
		{
			xmin = (a + b) / 2;
			fmin = (xmin - 2)*(xmin - 2);
			answer = true;
		}
		else if (f1 < f2)
		{
			b = x2;
			x2 = x1;
			x1 = a + k1*(b - a);
			f2 = f1;
			f1 = (x1 - 2)*(x1 - 2);
		}
		else
		{
			a = x1;
			x1 = x2;
			x2 = a + k2*(b - a);
			f1 = f2;
			f2 = (x2 - 2)*(x2 - 2);
		}
	} while (answer == false);

	cout << "Xmin=" << xmin << endl;
}

void DichotomiiMetod()
{
	bool answer = false;
	float a, b, e, d, x1, x2, fx1, fx2, xmin, fmin;

	cout << "input acurancy e=";
	cin >> e;
	cout << "input point a=";
	cin >> a;
	cout << "input pount b=";
	cin >> b;
	cout << "input step lenght d=";
	cin >> d;

	do
	{
	x1 = (a + b - d) / 2;
	x2 = (a + b + d) / 2;

	fx1 = (x1 - 2)*(x1 - 2);
	fx2 = (x2 - 2)*(x2 - 2);

		if (fx1 >= fx2)
		{
			if(a==x1)
			{
				answer = true;
			}
			a = x1;
		}
		else { b = x2; }

		if (b - a <= e)
		{
			answer = true;
		}
	} while (answer == false);
			xmin = (a + b) / 2;
			fmin = (xmin - 2)*(xmin - 2);

	cout << "Xmin=" << xmin << " f(X)=" << fmin << endl;
}

void showMenu()
{
	cout << "Choise metod" << endl;
	cout << "1) DeleniePopolam" << endl;
	cout << "2) Newton" << endl;
	cout << "3) Golden section" << endl;
	cout << "4) Dichotomii" << endl;

	int choise = 0;

	cout << "You choise is ";

	cin >> choise;

	system("cls");

	switch (choise)
	{
	case 1: {DeleniePopolamMetod(); break; }
	case 2: {NewtonMetod(); break; }
	case 3: {GoldenSectionMetod(); break; }
	case 4: {DichotomiiMetod(); break; }
	}

}

int main()
{
	showMenu();

	getchar();
	getchar();



	return 0;
}