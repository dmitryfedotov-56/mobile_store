	/***********************************************************/
	/*                      Mobile Store       	 	           */
	/***********************************************************/

	#include <iostream>

	#include <stdio.h>
	#include <conio.h>
	#include "mobiles.h"

	using namespace std;

	/***********************************************************/
	/*              Mobile_Store Class Definition 	           */
	/***********************************************************/

	#define NMODELS	(unsigned)Model::END

	class Mobile_Store 
	{
	public:
		Mobile_Store();		// constructor

		void show();		// mobile list

		void add_Mobiles(Model model, unsigned number);	// add mobiles

		void get_Mobiles(Model model, unsigned number);	// get mobiles

		const char* model_Name(Model model);			// model name

		unsigned number_of_Mobiles(Model model);		// number of instances

	private:

		Mobile* sample[NMODELS];						// mobile samples

		unsigned stored[NMODELS];						// number of mobiles
	};

	/***********************************************************/
	/*              Mobile_Store Class Implementation          */
	/***********************************************************/

	Mobile_Store::Mobile_Store() 
	{
		for (unsigned i = 0; i < NMODELS; i++)
		{
			stored[i] = 1;
			sample[i] = create_Model((Model)i);
		};
	};

	/***********************************************************/

	void show_Bar()										// supplementary
	{
		printf(" ");
		for (short i = 0; i < 40; i++)printf("-");
		printf("\n");
	};

	/***********************************************************/

	void Mobile_Store::show()	// list of products
	{
		unsigned n;
		show_Bar();
		printf(" число  модель ЦП память экран тип    5G \n");
		       
		show_Bar();
		for (unsigned i = 0; i < NMODELS; i++) 
		{
			n = stored[i];
			printf(" ");
			printf("%-6d", n);
			show_Model(sample[i]);
			printf("\n");
		};
		show_Bar();
	};

	/***********************************************************/

	void Mobile_Store::add_Mobiles(Model model, unsigned number)
	{
		stored[(unsigned)model] += number;
	};

	/***********************************************************/

	void Mobile_Store::get_Mobiles(Model model, unsigned number)
	{
		unsigned n = (unsigned)model;
		if(stored[n] >= number)stored[n] -= number;
	};

	/***********************************************************/

	const char* Mobile_Store::model_Name(Model model) 
	{
		unsigned n = (unsigned)model;
		Mobile* mobile = sample[n];
		return mobile_Name(mobile);
	};

	/***********************************************************/

	unsigned Mobile_Store::number_of_Mobiles(Model model)
	{
		unsigned n = (unsigned)model;
		return stored[n];
	};

	/***********************************************************/
	/*                 Mobile Store Interface  	 	           */
	/***********************************************************/
/*
	IMPORTANT NOTE: NMODELS is assumednot to be not more than 10!
*/
	char get_Operation() 
	{
		show_Bar();									// show menu
		cout << " 0   : список" << endl;
		cout << " 1   : получить" << endl;
		cout << " 2   : пополнить" << endl;
		cout << " ESC : выход" << endl;
		show_Bar();
		cout << " операция : ";

		char c;
		while (true)								// get input
		{
			c = _getch();
			switch (c)
			{
			case '0': 
				cout << "список" << endl;
				return c;
			case '1': 
				cout << "получение" << endl;
				return c;
			case '2': 
				cout << "пополнение" << endl;
				return c;
			case 27 : 
				cout << "выход" << endl;
				return c;
			};
		};
	};

	/***********************************************************/

	Model get_Model(Mobile_Store& store)
	{
		for (unsigned i = 0; i < NMODELS; i++)		// show menu 
		{
			printf(" ");
			printf("%1d", i);
			printf(" : ");
			printf(store.model_Name((Model)i));
			printf("\n");
		};
		show_Bar();
		printf(" модель : ");

		char c;										// get input
		while (true)
		{
			c = _getch();
			unsigned n = c - 48;
			if (n < NMODELS)return (Model)n;
		};
	};

	/***********************************************************/

	void addition(Mobile_Store& store)
	{
		unsigned n;
		Model model = get_Model(store);
		cout << " число : ";
		cin >> n;
		store.add_Mobiles(model, n);
		cout << " склад пополнен" << endl;
	};

	/***********************************************************/

	void purchase(Mobile_Store& store)
	{
		unsigned n;
		Model model = get_Model(store);
		cout << " число : ";
		cin >> n;
		if (n > store.number_of_Mobiles(model)) 
		{
			cout << " на складе отсутствует заданное число" << endl;
			return;
		}
		store.get_Mobiles(model, n);
		cout << " товар получен" << endl;
	};

	/***********************************************************/

	int main()
	{
		setlocale(LC_ALL, "");

		Mobile_Store store;
		char c;
		while (true)
		{
			c = get_Operation();
			switch (c)
			{
			case '0': store.show();
				break;
			case '1': purchase(store);
				break;
			case '2': addition(store);
				break;
			case 27: return 0;
			};
		};
		return 0;
	};

	/***********************************************************/

