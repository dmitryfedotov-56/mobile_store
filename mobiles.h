	#pragma once
	/***********************************************************/
	/*                          Mobiles        	 	           */
	/***********************************************************/

	enum class Model { M01, M02, M03, M04, END };

	class Mobile;

	Mobile* create_Model(Model model);

	void show_Model(Mobile* mobile);

	const char* mobile_Name(Mobile* mobile);

	/***********************************************************/


