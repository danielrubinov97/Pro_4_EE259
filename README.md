# Pro_4 OUTLINE FROM EE259 COURSE
## My Solution: Daniel Rubinov
###	\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_
###	\_                                                                    \_
###	\_   THE CITY COLLEGE OF NEW YORK, ELECTRICAL ENGINEERING DEPARTMENT  \_
###	\_                EE259, DAY-EVENING SECTIONS, FALL 2018              \_
###	\_                                                                    \_
###	\_                              PROJECT 4                             \_
###	\_                                                                    \_
###	\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

PROJECT 4 DESCRIPTION:

Write a C++ class definition called OVERLOADED_BURSAR which will 
perform the following tasks. OVERLOADED_BURSAR class will inherit from
BURSAR_INFO class, which in turn will inherit from SORT_INFO, 
STUDENT_GRADE and STUDENT_ID classes.

The prototype for OVERLOADED_BURSAR class is defined as follows:

  class OVERLOADED_BURSAR:public BURSAR_INFO{

   public:      // public methods for this class

        OVERLOADED_BURSAR(char *, int, int);  // constructor 1:
			// Example: OVERLOADED_BURSAR B("ObjName1", x, y);
                        // instantiate object B of class OVERLOADED_BURSAR 
			// with nam ObjName1, x students and y exams;

        OVERLOADED_BURSAR(void);  // constructor 2:
			// Example: OVERLOADED_BURSAR B;
                        // instantiate object B of class OVERLOADED_BURSAR
			// there are 0 students;

	void PRINT_IDS(void); // Example: B.PRINT_IDS();
                        // method prints student ids;
                        // returns no values;

	void ADD_STUDENT(char *, char *, int); 
			// Example: B.ADD_STUDENT("PEGGY", "HEIDI" 1234);
			// Add student to object B;
			// Set all exam grades to 0;
			// returns no values;

	void DELETE_STUDENT(char *, char *, int); 
			// Example: B.DELETE_STUDENT("PEGGY", "HEIDI", 1234);
			// Delete student from object B;
			// returns no values;

        int operator == (OVERLOADED_BURSAR); // Example: if (B1 == B2)
                        // returns 1 if the number of students in B1
                        // and B2 are equal;
                        // returns 0 otherwise;

        int operator == (int); // Example: if (B1 == 4)
                        // returns 1 if the number of students in B1
                        // is equal to 4;
                        // returns 0 otherwise;

        int operator > (OVERLOADED_BURSAR); // Example: if (B1 > B2)
                        // returns 1 if the maximum grade of students
			// received in all exams in B1 is greater than in B2;
                        // returns 0 otherwise;

	void operator = (OVERLOADED_BURSAR); // Example: B1 = B2;
			// assign student ids and exam grades of B2 to B1; 
			// B2 remains unchanged;
			// returns no values;

        OVERLOADED_BURSAR operator + (OVERLOADED_BURSAR); // Example: B1 + B2;
                        // create a TEMP object; 
			// copy the student ids, names and exams of B1 to TEMP
			// and then append B2 elements to TEMP;
			// return TEMP object;
                        // for simplicity, assume all students are unique;
	protected:
		char objectName[12]; // name for this object; max 11 chars
   };

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

An example use of the constructor 1 for this class is as follows:

        OVERLOADED_BURSAR X(ObjN, w, z); 

which instantiates an object X of class OVERLOADED_BURSAR.  Character array
ObjN is to be copied to objectName, whereas the integers w and z represent 
the number of students and exams, respectively. This constructor will call 
the constructor of the base class BURSAR_INFO.

The output to out.4.txt file is:

	++++++++ P4 START ++++
	++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR:
	++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF ObjN IS CREATED.
	++++++++ P4 END ++++

Note that the constructors for SORT_INFO, STUDENT_GRADE and STUDENT_ID 
will also generate their own outputs automatically as they are called 
by the constructors.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

An example use of the constructor 2 for this class is as follows:

        OVERLOADED_BURSAR X(ObjN); 

which instantiates an object X of class OVERLOADED_BURSAR.  Character 
array ObjN is to be copied to objectName. This constructor will call the 
constructor of the base class BURSAR_INFO.  The protected variables of 
n and p will be set to 0.

There is no output to out.4.txt file. Note that the constructors for the 
base classes are modified in sample solutions so that they will not generate 
an output if n is 0.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

The definition of PRINT_STUDENTS method is as follows:

	B.PRINT_IDS();

where B is a object of class OVERLOADED_BURSAR.  
This method prints the student ids by invoking LIST_IDS method defined 
in STUDENT_GRADE class. The output to out.4.txt file is as follows:

	++++++++ P4 START ++++
	++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjName: 
	++ P1 START ++
	++ P1 OUTPUT FROM LIST_IDS METHOD:
	+ P0 START +
	+ P0 OUTPUT FROM LIST_ID METHOD:
	+ P0 STUDENT IDS FOR z STUDENTS:
	+ P0 id_0
	...
	+ P0 id_n-1
	+ P0 END +
	++ P1 END ++
	++++++++ P4 END ++++

where ObjName is the name of the object defined by constructor 1.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

The definition of ADD_STUDENT method is as follows:

	B.ADD_STUDENT(F, L, x);

where B is a object of class OVERLOADED_BURSAR, F and L are character 
arrays for first and last names, respectively, and x is an integer
for id.  

If the total number of students will not be more than 20, this method 
appends this new student to the list of students in protected data.
It sets project grades to 0 and increments the number of students 
by one.  The output to out.4.txt file is as follows:

	++++++++ P4 START ++++
	++++++++ P4 OUTPUT FROM ADD_STUDENT METHOD FOR OBJECT objName1: 
	++++++++ P4 STUDENT L, F WITH ID x IS ADDED.
	++++++++ P4 END ++++

If F, L and/or x has illegal values, the output to out.4.txt is:

	++++++++ P4 START ++++
	++++++++ P4 OUTPUT FROM ADD_STUDENT METHOD FOR objName1: 
	++++++++ P4 INPUT ERROR.
	++++++++ P4 END ++++

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

The definition of DELETE_STUDENT method is as follows:

	B.DELETE_STUDENT(F, L, x);

where B is a object of class OVERLOADED_BURSAR, F and L are character 
arrays for first and last names, respectively, and x is an integer
for id.  

If there is such a student, this method deletes this student from
protected data of B. The output to out.4.txt file is as follows:

	++++++++ P4 START ++++
	++++++++ P4 OUTPUT FROM DELETE_STUDENT METHOD FOR OBJECT objName1: 
	++++++++ P4 STUDENT L, F WITH ID x IS DELETED.
	++++++++ P4 NOW THERE ARE n STUDENTS.
	++++++++ P4 END ++++

where n has the decremented value.

If there is no such a student, the output to out.4.txt file is:

	++++++++ P4 START ++++
	++++++++ P4 OUTPUT FROM DELETE_STUDENT METHOD FOR OBJECT objName1: 
	++++++++ P4 NO SUCH STUDENT L, F WITH ID x IS FOUND.
	++++++++ P4 END ++++

If F, L and/or x has illegal values, the output to out.4.txt is:

	++++++++ P4 START ++++
	++++++++ P4 OUTPUT FROM DELETE_STUDENT METHOD FOR OBJECT objName1: 
	++++++++ P4 INPUT ERROR.
	++++++++ P4 END ++++

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

An example use of overloaded operator == is as follows:

        if(B1 == B2)

where B1 and B2 are objects of class OVERLOADED_BURSAR.  This overloaded
operator checks if the number of students in B1 are equal to that in B2.

If true, it returns 1 with the following output to out.4:

	++++++++ P4 START ++++
        ++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT objName1:
        ++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN ObjName1 AND ObjName2 ARE EQUAL: 
        ++++++++ P4 RETURNS TRUE.
	++++++++ P4 END ++++

where ObjName1 and ObjName2 are the names of B1 and B2 objects as defined
by constructor 1.

Otherwise, it returns 0 with the following output to out.4:

	++++++++ P4 START ++++
        ++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT objName1:
        ++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN ObjName1 AND ObjName2 ARE EQUAL: 
        ++++++++ P4 RETURNS FALSE.
	++++++++ P4 END ++++

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

An example use of overloaded operator == is as follows:

        if(B1 == x)

where B1 is an object of class OVERLOADED_BURSAR and x is an integer.  
This operator checks if the number of students in B1 is equal to x.

If true, it returns 1 with the following output to out.4:

	++++++++ P4 START ++++
        ++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT objName1:
        ++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN ObjName1 IS EQUAL TO x: 
        ++++++++ P4 RETURNS TRUE.
	++++++++ P4 END ++++

where ObjName1 and ObjName2 are the names of B1 and B2 objects as defined
by constructor 1.

Otherwise, it returns 0 with the following output to out.4:

	++++++++ P4 START ++++
        ++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT objName1:
        ++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN ObjName1 IS EQUAL TO x: 
        ++++++++ P4 RETURNS FALSE.
	++++++++ P4 END ++++

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

An example use of overloaded operator > is as follows:

        if(B1 > B2)

where B1 and B2 are OVERLOADED_BURSAR objects. This overloaded
operator checks if the maximum grade of all students received 
in all exams in B1 is greater than of that in B2.

If true, it returns 1 with the following output to out.4:

	++++++++ P4 START ++++
        ++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR > METHOD FOR OBJECT objName1:
        ++++++++ P4 CHECKING IF MAX IN ObjName1 > MAX IN ObjName2: 
        ++++++++ P4 RETURNS TRUE.
	++++++++ P4 END ++++

where ObjName1 and ObjName2 are the names of B1 and B2 objects as defined
by constructor 1.

Otherwise, it returns 0 with the following output to out.4:

	++++++++ P4 START ++++
        ++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR > METHOD FOR OBJECT objName1:
        ++++++++ P4 CHECKING IF MAX IN ObjName1 > MAX IN ObjName2: 
        ++++++++ P4 RETURNS FALSE.
	++++++++ P4 END ++++

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

An example use of overloaded operator > is as follows:

        B1 = B2;

where B1 and B2 are OVERLOADED_BURSAR objects.  This overloaded operator 
copies the student ids, first names, last names and exam grades from 
B2 to B1, while B2 remains unchanged.  The output to out.4.txt is:

	++++++++ P4 START ++++
	++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR = METHOD FOR OBJECT objName1:
	++++++++ P4 CONTENTS OF OBJECT Obj2 IS ASSIGNED TO OBJECT Obj1.
	++++++++ P4 END ++++

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

An example use of overloaded operator + is as follows:

        B1 + B2;

where B1 and B2 are OVERLOADED_BURSAR objects.  This overloaded operator 
first creates a TEMP object with 0 elements, and copies the data of B1
into TEMP. Then it appends the data of B2 to TEMP and returns the TEMP
object. B1 and B2 remains unchanged. The output to out.4.txt is:

	++++++++ P4 START ++++
	++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR + METHOD FOR OBJECT objName1:
        ++++++++ P4 INFORMATION FROM objName1 AND objName2 HAVE BEEN ADDED.
	++++++++ P4 END ++++

where objName1 and objName2 are the names for B1 and B2 objects, respectively.
For simplicity, all names and ids are assumed to be unique.

The total number of students in TEMP should not exceed 20. Also the number
of projects in B1 and B2 must match. If not, the output to out.4.1 is:

If total number of students after adding is less than 11,
then it prints the following output to out.4:

	++++++++ P4 START ++++
	++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR + METHOD FOR OBJECT objName1:
        ++++++++ P4 INPUT ERROR.
	++++++++ P4 END ++++

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

:::::::::::::: EXAMPLE 1 ::::::::::::::::::::: 
---------CONTENTS OF main4_1.cc FILE:-----------
#include "p4.h"
// example program: main4_1.cc
int main ()
{
        OVERLOADED_BURSAR B1("ObjB1", 5, 4); // instantiate an object B1 of 
			// class SORT_INFO with a name ObjB1 with 5 students,
			// each with 4 exams;

	B1.PRINT_IDS();

	return 0;
}
---------CONTENTS OF studentName.txt FILE:---------------
BUSH    ROB    
PAPA	JOE   
LEE     MARIA  
WONG	ANITA  
CARTER  SHAOYI 
---------CONTENTS OF studentGrade.txt FILE:---------------
81 91 61 71 
83 93 63 73
82 92 62 72
85 95 65 75
84 94 64 74
---------CONTENTS OF studentId.txt FILE:---------------
1111
3333
2222
5555
4444
---------EXPECTED CONTENTS OF out.4.txt FILE:-----
+ P0 START +
+ P0 OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ P0 INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 5 STUDENT IDS.
+ P0 END +
++ P1 START ++
++ P1 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++ P1 AN OBJECT OF STUDENT_GRADE IS CREATED WITH 5 STUDENTS AND 4 EXAMS EACH.
++ P1 END ++
++++ P2 START ++++
++++ P2 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++++ P2 AN OBJECT OF SORT_INFO IS CREATED.
++++ P2 END ++++
++++++ P3 START ++++
++++++ P3 OUTPUT FROM BURSAR_INFO CONSTRUCTOR:
++++++ P3 AN OBJECT OF BURSAR_INFO IS CREATED.
++++++ P3 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR:
++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF ObjB1 IS CREATED.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB1:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 5 STUDENTS:
+ P0 1111
+ P0 3333
+ P0 2222
+ P0 5555
+ P0 4444
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
:::::::::::::: EXAMPLE 2 ::::::::::::::::::::: 
---------CONTENTS OF main4_2.cc FILE:-----------
#include "p4.h"
// example program: main4_2.cc
int main ()
{
        OVERLOADED_BURSAR B1("ObjB1", 5, 4); // instantiate an object B1 of 
			// class SORT_INFO with a name ObjB1 with 5 students,
			// each with 4 exams;
        OVERLOADED_BURSAR B2("ObjB2", 2, 4); // instantiate an object B2 of 
			// class SORT_INFO with a name ObjB2 with 2 students,
			// each with 3 exams;
	if (B1 > B2)
	{
		B1.PRINT_IDS(); // this should print
	}
	else
	{
		B2.PRINT_IDS();
	}

	if (B2 == 2)
	{
		B2.PRINT_IDS(); // this should print
	}
	else
	{
		B1.PRINT_IDS();
	}
	return 0;
}
---------CONTENTS OF studentName.txt FILE:---------------
BUSH    ROB    
PAPA	JOE   
LEE     MARIA  
WONG	ANITA  
CARTER  SHAOYI 
---------CONTENTS OF studentGrade.txt FILE:---------------
81 91 61 71 
83 93 63 73
82 92 62 72
85 95 65 75
84 94 64 74
---------CONTENTS OF studentId.txt FILE:---------------
1111
3333
2222
5555
4444
---------EXPECTED CONTENTS OF out.4.txt FILE:-----
+ P0 START +
+ P0 OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ P0 INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 5 STUDENT IDS.
+ P0 END +
++ P1 START ++
++ P1 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++ P1 AN OBJECT OF STUDENT_GRADE IS CREATED WITH 5 STUDENTS AND 4 EXAMS EACH.
++ P1 END ++
++++ P2 START ++++
++++ P2 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++++ P2 AN OBJECT OF SORT_INFO IS CREATED.
++++ P2 END ++++
++++++ P3 START ++++
++++++ P3 OUTPUT FROM BURSAR_INFO CONSTRUCTOR:
++++++ P3 AN OBJECT OF BURSAR_INFO IS CREATED.
++++++ P3 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR:
++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF ObjB1 IS CREATED.
++++++++ P4 END ++++
+ P0 START +
+ P0 OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ P0 INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 2 STUDENT IDS.
+ P0 END +
++ P1 START ++
++ P1 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++ P1 AN OBJECT OF STUDENT_GRADE IS CREATED WITH 2 STUDENTS AND 4 EXAMS EACH.
++ P1 END ++
++++ P2 START ++++
++++ P2 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++++ P2 AN OBJECT OF SORT_INFO IS CREATED.
++++ P2 END ++++
++++++ P3 START ++++
++++++ P3 OUTPUT FROM BURSAR_INFO CONSTRUCTOR:
++++++ P3 AN OBJECT OF BURSAR_INFO IS CREATED.
++++++ P3 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR:
++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF ObjB2 IS CREATED.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR > METHOD FOR OBJECT ObjB1:
++++++++ P4 CHECKING IF MAX IN ObjB1 > MAX IN ObjB2:
++++++++ P4 RETURNS TRUE.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB1:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 5 STUDENTS:
+ P0 1111
+ P0 3333
+ P0 2222
+ P0 5555
+ P0 4444
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT ObjB2:
++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN ObjB2 IS EQUAL TO 2:
++++++++ P4 RETURNS TRUE.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB2:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 2 STUDENTS:
+ P0 1111
+ P0 3333
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
:::::::::::::: EXAMPLE 3 ::::::::::::::::::::: 
---------CONTENTS OF main4_3.cc FILE:-----------
#include "p4.h"
// example program: main4_3.cc
int main ()
{
        OVERLOADED_BURSAR B1("ObjB1", 5, 4); // instantiate an object B1 of 
			// class SORT_INFO with a name ObjB1 with 5 students,
			// each with 4 exams;
        OVERLOADED_BURSAR B2("ObjB2", 2, 4); // instantiate an object B2 of 
			// class SORT_INFO with a name ObjB2 with 2 students,
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
---------CONTENTS OF studentName.txt FILE:---------------
BUSH    ROB    
PAPA	JOE   
LEE     MARIA  
WONG	ANITA  
CARTER  SHAOYI 
---------CONTENTS OF studentGrade.txt FILE:---------------
81 91 61 71 
83 93 63 73
82 92 62 72
85 95 65 75
84 94 64 74
---------CONTENTS OF studentId.txt FILE:---------------
1111
3333
2222
5555
4444
---------EXPECTED CONTENTS OF out.4.txt FILE:-----
+ P0 START +
+ P0 OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ P0 INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 5 STUDENT IDS.
+ P0 END +
++ P1 START ++
++ P1 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++ P1 AN OBJECT OF STUDENT_GRADE IS CREATED WITH 5 STUDENTS AND 4 EXAMS EACH.
++ P1 END ++
++++ P2 START ++++
++++ P2 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++++ P2 AN OBJECT OF SORT_INFO IS CREATED.
++++ P2 END ++++
++++++ P3 START ++++
++++++ P3 OUTPUT FROM BURSAR_INFO CONSTRUCTOR:
++++++ P3 AN OBJECT OF BURSAR_INFO IS CREATED.
++++++ P3 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR:
++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF ObjB1 IS CREATED.
++++++++ P4 END ++++
+ P0 START +
+ P0 OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ P0 INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 2 STUDENT IDS.
+ P0 END +
++ P1 START ++
++ P1 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++ P1 AN OBJECT OF STUDENT_GRADE IS CREATED WITH 2 STUDENTS AND 4 EXAMS EACH.
++ P1 END ++
++++ P2 START ++++
++++ P2 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++++ P2 AN OBJECT OF SORT_INFO IS CREATED.
++++ P2 END ++++
++++++ P3 START ++++
++++++ P3 OUTPUT FROM BURSAR_INFO CONSTRUCTOR:
++++++ P3 AN OBJECT OF BURSAR_INFO IS CREATED.
++++++ P3 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR:
++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF ObjB2 IS CREATED.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT ObjB1:
++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN ObjB1 AND ObjB2 ARE EQUAL: 
++++++++ P4 RETURNS FALSE.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB2:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 2 STUDENTS:
+ P0 1111
+ P0 3333
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
:::::::::::::: EXAMPLE 4 ::::::::::::::::::::: 
---------CONTENTS OF main4_4.cc FILE:-----------
#include "p4.h"
// example program: main4_4.cc
int main ()
{
        OVERLOADED_BURSAR B1("ObjB1", 5, 4); // instantiate an object B1 of 
			// class SORT_INFO with a name ObjB1 with 5 students,
			// each with 4 exams;
        OVERLOADED_BURSAR B2("ObjB2", 2, 4); // instantiate an object B2 of 
			// class SORT_INFO with a name ObjB2 with 2 students,
			// each with 4 exams;
	B1.PRINT_IDS();
	B2.PRINT_IDS();
	B1 = B2;
	B1.PRINT_IDS();
	B2.PRINT_IDS();

	return 0;
}
---------CONTENTS OF studentName.txt FILE:---------------
BUSH    ROB    
PAPA	JOE   
LEE     MARIA  
WONG	ANITA  
CARTER  SHAOYI 
---------CONTENTS OF studentGrade.txt FILE:---------------
81 91 61 71 
83 93 63 73
82 92 62 72
85 95 65 75
84 94 64 74
---------CONTENTS OF studentId.txt FILE:---------------
1111
3333
2222
5555
4444
---------EXPECTED CONTENTS OF out.4.txt FILE:-----
+ P0 START +
+ P0 OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ P0 INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 5 STUDENT IDS.
+ P0 END +
++ P1 START ++
++ P1 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++ P1 AN OBJECT OF STUDENT_GRADE IS CREATED WITH 5 STUDENTS AND 4 EXAMS EACH.
++ P1 END ++
++++ P2 START ++++
++++ P2 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++++ P2 AN OBJECT OF SORT_INFO IS CREATED.
++++ P2 END ++++
++++++ P3 START ++++
++++++ P3 OUTPUT FROM BURSAR_INFO CONSTRUCTOR:
++++++ P3 AN OBJECT OF BURSAR_INFO IS CREATED.
++++++ P3 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR:
++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF ObjB1 IS CREATED.
++++++++ P4 END ++++
+ P0 START +
+ P0 OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ P0 INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 2 STUDENT IDS.
+ P0 END +
++ P1 START ++
++ P1 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++ P1 AN OBJECT OF STUDENT_GRADE IS CREATED WITH 2 STUDENTS AND 4 EXAMS EACH.
++ P1 END ++
++++ P2 START ++++
++++ P2 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++++ P2 AN OBJECT OF SORT_INFO IS CREATED.
++++ P2 END ++++
++++++ P3 START ++++
++++++ P3 OUTPUT FROM BURSAR_INFO CONSTRUCTOR:
++++++ P3 AN OBJECT OF BURSAR_INFO IS CREATED.
++++++ P3 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR:
++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF ObjB2 IS CREATED.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB1:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 5 STUDENTS:
+ P0 1111
+ P0 3333
+ P0 2222
+ P0 5555
+ P0 4444
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB2:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 2 STUDENTS:
+ P0 1111
+ P0 3333
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR = METHOD FOR OBJECT ObjB1:
++++++++ P4 CONTENTS OF OBJECT ObjB2 IS ASSIGNED TO OBJECT ObjB2.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB2:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 2 STUDENTS:
+ P0 1111
+ P0 3333
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB2:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 2 STUDENTS:
+ P0 1111
+ P0 3333
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
:::::::::::::: EXAMPLE 5 ::::::::::::::::::::: 
---------CONTENTS OF main4_5.cc FILE:-----------
#include "p4.h"
// example program: main4_5.cc
int main ()
{
        OVERLOADED_BURSAR B1("ObjB1", 3, 4); // instantiate an object B1 of 
			// class OVERLOADED_BURSAR with a name ObjB1 with 3 students,
			// each with 4 exams;
        OVERLOADED_BURSAR B2("ObjB2", 1, 4); // instantiate an object B1 of 
			// class OVERLOADED_BURSAR with a name ObjB1 with 1 student,
			// with 4 exams;
	OVERLOADED_BURSAR B3("ObjB3"); // B3 is an empty object of OVERLOADED_BURSAR

	B1.PRINT_IDS();
	B2.PRINT_IDS();
	B3.PRINT_IDS();
	B2.DELETE_STUDENT("ROB", "BUSH", 1111);
	B2.ADD_STUDENT("PEGGY", "HEIDI", 1234);
	B2.PRINT_IDS();
	B3 = B1 + B2;
	B1.PRINT_IDS();
	B2.PRINT_IDS();
	B3.PRINT_IDS();

	return 0;
}
---------CONTENTS OF studentName.txt FILE:---------------
BUSH    ROB    
PAPA	JOE   
LEE     MARIA  
WONG	ANITA  
CARTER  SHAOYI 
---------CONTENTS OF studentGrade.txt FILE:---------------
81 91 61 71 
83 93 63 73
82 92 62 72
85 95 65 75
84 94 64 74
---------CONTENTS OF studentId.txt FILE:---------------
1111
3333
2222
5555
4444
---------EXPECTED CONTENTS OF out.4.txt FILE:-----
+ P0 START +
+ P0 OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ P0 INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 3 STUDENT IDS.
+ P0 END +
++ P1 START ++
++ P1 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++ P1 AN OBJECT OF STUDENT_GRADE IS CREATED WITH 3 STUDENTS AND 4 EXAMS EACH.
++ P1 END ++
++++ P2 START ++++
++++ P2 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++++ P2 AN OBJECT OF SORT_INFO IS CREATED.
++++ P2 END ++++
++++++ P3 START ++++
++++++ P3 OUTPUT FROM BURSAR_INFO CONSTRUCTOR:
++++++ P3 AN OBJECT OF BURSAR_INFO IS CREATED.
++++++ P3 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR:
++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF ObjB1 IS CREATED.
++++++++ P4 END ++++
+ P0 START +
+ P0 OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ P0 INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 1 STUDENT IDS.
+ P0 END +
++ P1 START ++
++ P1 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++ P1 AN OBJECT OF STUDENT_GRADE IS CREATED WITH 1 STUDENTS AND 4 EXAMS EACH.
++ P1 END ++
++++ P2 START ++++
++++ P2 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:
++++ P2 AN OBJECT OF SORT_INFO IS CREATED.
++++ P2 END ++++
++++++ P3 START ++++
++++++ P3 OUTPUT FROM BURSAR_INFO CONSTRUCTOR:
++++++ P3 AN OBJECT OF BURSAR_INFO IS CREATED.
++++++ P3 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR:
++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF ObjB2 IS CREATED.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB1:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 3 STUDENTS:
+ P0 1111
+ P0 3333
+ P0 2222
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB2:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 1 STUDENTS:
+ P0 1111
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB3:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 0 STUDENTS:
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM DELETE_STUDENT METHOD FOR OBJECT ObjB2:
++++++++ P4 STUDENT BUSH, ROB WITH ID 1111 IS DELETED.
++++++++ P4 NOW THERE ARE 0 STUDENTS.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM ADD_STUDENT METHOD FOR OBJECT ObjB2:
++++++++ P4 STUDENT HEIDI, PEGGY WITH ID 1234 IS ADDED.
++++++++ P4 NOW THERE ARE 1 STUDENTS.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB2:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 1 STUDENTS:
+ P0 1234
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR + METHOD FOR OBJECT ObjB1:
++++++++ P4 INFORMATION FROM ObjB1 AND ObjB2 HAVE BEEN ADDED.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR = METHOD FOR OBJECT ObjB3:
++++++++ P4 CONTENTS OF OBJECT TempObj IS ASSIGNED TO OBJECT TempObj.
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB1:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 3 STUDENTS:
+ P0 1111
+ P0 3333
+ P0 2222
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT ObjB2:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 1 STUDENTS:
+ P0 1234
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
++++++++ P4 START ++++
++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT TempObj:
++ P1 START ++
++ P1 OUTPUT FROM LIST_IDS METHOD:
+ P0 START +
+ P0 OUTPUT FROM LIST_ID METHOD:
+ P0 STUDENT IDS FOR 4 STUDENTS:
+ P0 1111
+ P0 3333
+ P0 2222
+ P0 1234
+ P0 END +
++ P1 END ++
++++++++ P4 END ++++
