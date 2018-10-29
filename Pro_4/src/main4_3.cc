#include "p4.h"
// example program: main4_3.cc
int main ()
{
        OVERLOADED_BURSAR B1("Obj1", 5, 4); // instantiate an object B1 of 
			// class SORT_INFO with a name Obj1 with 5 students,
			// each with 4 exams;
        OVERLOADED_BURSAR B2("Obj2", 2, 4); // instantiate an object B2 of 
			// class SORT_INFO with a name Obj2 with 2 students,
			// each with 4 exams;
	if (B1 == B2)
	{
		B1.PRINT_IDS();
	}
	else
	{
		B2.PRINT_IDS();
	}

	return 0;
}
