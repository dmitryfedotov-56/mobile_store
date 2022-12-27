	/***********************************************************/
	/*                          Mobiles        	 	           */
	/***********************************************************/

	#include <stdio.h>

	using namespace std;

	#include "mobiles.h"

	#define NMODELS	(unsigned)Model::END

	/***********************************************************/
	/*                          Mobile     	  	               */
	/***********************************************************/

	class Mobile 
	{
	public:

		Mobile() {};					// default constructor

		Mobile(Model model_type,		// general constructor
			const char* model_name, 
			unsigned cpu_number,
			float ram_size,
			float screen_size)
		{ 
			model = model_type;
			name = model_name;
			cpu = cpu_number;
			ram = ram_size;
			screen = screen_size;
		};

		const char* Name() { return name; };

		virtual void show() = 0;		// virtual display method

		void show_Mobile()				// general display method
		{ 
			printf(" ");
			printf("%-7s", name);
			printf("%-3d", cpu);
			printf("%-7.1f", ram);
			printf("%-6.1f", screen);
		};

	private:							// private part
		Model model = Model::END;
		const char* name = nullptr;
		unsigned cpu = 0;
		float ram = 0;
		float screen = 0;
	};

	/***********************************************************/

	class Mobile_IPS : public virtual Mobile	// IPS screen
	{
	public:

		Mobile_IPS() : Mobile() {};

		void show_IPS() 
		{
			printf("%-6s", "IPS    ");
		};

		void show_Mobile_IPS() 
		{ 
			show_Mobile(); 
			show_IPS(); 
		};

		virtual void show() { show_Mobile_IPS(); };
	};

	/***********************************************************/

	class Mobile_OLED : public virtual Mobile	// OLED screen
	{
	public:

		Mobile_OLED() : Mobile() {};

		void show_OLED()
		{
			printf("%-6s", "OLED   ");
		};

		void show_Mobile_OLED()
		{
			show_Mobile();
			show_OLED();
		};

		virtual void show() { show_Mobile_OLED(); };
	};

	/***********************************************************/

	class Mobile_5G : public virtual Mobile		// 5G support
	{
	public:

		Mobile_5G() : Mobile() {};

		void show_5G()
		{
			printf("%-6s", "5G");
		};

		void show_Mobile_5G() 
		{ 
			show_Mobile(); 
			show_5G(); 
		};

		virtual void show() { show_Mobile_5G(); };

	};

	/***********************************************************/

	class Mobile_IPS_5G : public Mobile_IPS, public Mobile_5G 
	{
	public:

		Mobile_IPS_5G() : Mobile(), Mobile_IPS(), Mobile_5G() {};

		void show_Mobile_IPS_5G() 
		{
			show_Mobile_IPS(); 
			show_5G();
		};

		virtual void show() { show_Mobile_IPS_5G(); };
	};

	/***********************************************************/

	class Mobile_OLED_5G : public Mobile_OLED, public Mobile_5G
	{
	public:

		Mobile_OLED_5G() : Mobile(), Mobile_OLED(), Mobile_5G() {};

		void show_Mobile_OLED_5G()
		{
			show_Mobile_OLED();
			show_5G();
		};

		virtual void show() { show_Mobile_OLED_5G(); };
	};

	/***********************************************************/

	class M01 : public Mobile_IPS
	{
	public:
		M01() : Mobile(Model::M01, "M01", 4, 6.8, 6.6), Mobile_IPS() {};
	};

	/***********************************************************/

	class M02 : public Mobile_OLED
	{
	public:
		M02() : Mobile(Model::M02,"M02", 4, 4.6, 6.7), Mobile_OLED(){};
	};

	/***********************************************************/

	class M03 : public Mobile_IPS_5G
	{
	public:
		M03() : Mobile(Model::M03, "M03", 8, 6.8, 6.6), Mobile_IPS_5G() {};
	};

	/***********************************************************/

	class M04 : public Mobile_OLED_5G
	{
	public:
		M04() : Mobile(Model::M04, "M04", 8, 8.0, 6.7), Mobile_OLED_5G() {};
	};

	/***********************************************************/

	Mobile* create_Model(Model model) 
	{
		switch (model) 
		{
		case Model::M01:return new M01();
		case Model::M02:return new M02();
		case Model::M03:return new M03();
		case Model::M04:return new M04();
		};
		return nullptr;
	};

	/***********************************************************/

	void show_Model(Mobile* mobile) { mobile-> show(); };

	const char* mobile_Name(Mobile* mobile) { return mobile -> Name();  };

	/***********************************************************/
