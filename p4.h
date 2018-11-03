//#include "/ee259/tools/pro_4/sample_p3.h" // implementation of base class
#include <string.h>
#include "/ee259/tools/pro_4/sample_p3.h" // implementation of base class

using namespace std;

  class OVERLOADED_BURSAR:public BURSAR_INFO{

   public:      // public methods for this class

        OVERLOADED_BURSAR(char *, int, int);  // constructor 1:
			// Example: OVERLOADED_BURSAR B("ObjName1", x, y);
                        // instantiate object B of class OVERLOADED_BURSAR 
			// with nam ObjName1, x students and y exams;

        OVERLOADED_BURSAR(char *);  // constructor 2:
			// Example: OVERLOADED_BURSAR B;
                        // instantiate object B of class OVERLOADED_BURSAR
			// there are 0 students;

	void PRINT_IDS(void); // Example: b.PRINT_IDS();
                        // method prints student ids;
                        // returns no values;

	void ADD_STUDENT(char *, char *, int); 
			// Example: B.ADD_STUDENT("PEGGY", "HEIDI", 1234);
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

OVERLOADED_BURSAR::OVERLOADED_BURSAR(char * ObjN, int x, int y)
	: BURSAR_INFO(x, y)
{
	strcpy(objectName, ObjN);
	// your code goes below:
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR: " << endl;
	output_file_p4 << "++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF " << objectName <<  " IS CREATED." << endl;
	output_file_p4 << "++++++++ P4 END ++++" << endl;
}

OVERLOADED_BURSAR::OVERLOADED_BURSAR(char * ObjN)
	: BURSAR_INFO(0, 0)
{
	// no output is generated; base classes assign n=0 and p=0 and do not generate outputs; 
	strcpy(objectName, ObjN);
}

void 
OVERLOADED_BURSAR::PRINT_IDS()
{
	// your code goes below:
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT " << objectName << ":" << endl;
	LIST_IDS();
	output_file_p4 << "++++++++ P4 END ++++" << endl;
}

void 
OVERLOADED_BURSAR::ADD_STUDENT(char * F, char *L, int x)
{
	// your code goes below:
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM ADD_STUDENT METHOD FOR OBJECT " << objectName << ":" << endl;
	int indexOfLastStudent = n - 1;
	int arrayLength = sizeof(ids) / sizeof(ids[0]); //For future compatibility to change the size of the ids array.
	if (n < arrayLength && x > 0 && x < 10000) { //Add Names Illegal Input!
		ids[indexOfLastStudent + 1] = x; //Sets the position of the last student to be add a new student above that.
		strcpy(LastName[indexOfLastStudent + 1], L);
		strcpy(FirstName[indexOfLastStudent + 1], F);
		for (int i = 0; i < p; i++) {
			grades[indexOfLastStudent + 1][i] = 0;
		}
		output_file_p4 << "++++++++ P4 STUDENT " << L << ", " << F << " WITH ID " << x << "IS ADDED." << endl;
		n = n + 1;
		output_file_p4 << "++++++++ P4 NOW THERE ARE " << n << " STUDENTS." << endl;
	}
	else {
		output_file_p4 << "++++++++ P4 INPUT ERROR." << endl;
	}
	output_file_p4 << "++++++++ P4 END ++++" << endl;
}

void 
OVERLOADED_BURSAR::DELETE_STUDENT(char * F, char *L, int x)
{
	// your code goes below:
	int FOUND = 0, FOUND_POS;
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM DELETE_STUDENT METHOD FOR OBJECT " << objectName << ":" << endl;
	if (x > 0 && x < 10000){ //Add Names Illegal Inputs!
		for (int i = 0; i < n && FOUND == 0; i++){
			if(x == ids[i]){
				FOUND = 1;
				FOUND_POS = i;
			}
		}
		if (strcmp(LastName[FOUND_POS], L) == 0 && strcmp(FirstName[FOUND_POS], F) == 0 && FOUND == 1){
			for (int i = FOUND_POS + 1; i < n; i++){
				ids[i - 1] = ids[i];
				strcpy(LastName[i-1], LastName[i]);
				strcpy(FirstName[i-1], FirstName[i]);
				for(int j = 0; j < p; j++){
					grades[i-1][j] = grades[i][j];
				}
			}
			output_file_p4 << "++++++++ P4 STUDENT " << L << ", " << F << " WITH ID " << x << " IS DELETED." << endl;
			n = n-1;
			output_file_p4 << "++++++++ P4 NOW THERE ARE " << n << " STUDENTS." << endl;
		}
		else if ((strcmp(LastName[FOUND_POS], L) != 0 || strcmp(FirstName[FOUND_POS], F) != 0 )&& FOUND == 1){
		output_file_p4 << "++++++++ P4 NO SUCH STUDENT " << L << ", " << F << " WITH ID " << x << " IS FOUND." << endl;
		
		}
		else if (FOUND = 0)
		output_file_p4 << "++++++++ P4 NO SUCH STUDENT " << L << ", " << F << " WITH ID " << x << " IS FOUND." << endl;
	}
	else{
		output_file_p4 << "++++++++ P4 INPUT ERROR." << endl;
	}
	output_file_p4 << "++++++++ P4 END ++++" << endl;
}

int 
OVERLOADED_BURSAR::operator == (OVERLOADED_BURSAR Obj)
{
	// your code goes below:
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT " << objectName << ": " << endl;
	output_file_p4 << "++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN " << objectName << " AND " << Obj.objectName << " ARE EQUAL:" << endl;
	if (n ==  Obj.n){
		output_file_p4 << "++++++++ P4 RETURNS TURE." << endl;
		output_file_p4 << "++++++++ P4 END ++++" << endl;
		return 1;
	}else{
		output_file_p4 << "++++++++ P4 RETURNS FALSE." << endl;
		output_file_p4 << "++++++++ P4 END ++++" << endl;
		return 0;
	}
}

int 
OVERLOADED_BURSAR::operator == (int x)
{
	// your code goes below:
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT " << objectName << ":" << endl;
	output_file_p4 << "++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN " << objectName << " IS EQUAL TO " << x << ":"  << endl;
	if (n ==  x){
		output_file_p4 << "++++++++ P4 RETURNS TRUE." << endl;
		output_file_p4 << "++++++++ P4 END ++++" << endl;
		return 1;
	}
	else{
		output_file_p4 << "++++++++ P4 RETURNS FALSE." << endl;
		output_file_p4 << "++++++++ P4 END ++++" << endl;
		return 0;
	}
	return 1; // modify this
}

int 
OVERLOADED_BURSAR::operator > (OVERLOADED_BURSAR Obj)
{
	// your code goes below:
	int max, max_pos = 0, tempo;
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR > METHOD FOR OBJECT " << objectName << ":" <<  endl;
	output_file_p4 << "++++++++ P4 CHECKING IF MAX IN " << objectName << " > MAX IN " << Obj.objectName << ":" << endl;
	for(int i = 0; i < n; i++) {
		max = grades[i][0];
		for(int j = 0; j < p; j++){
			if (max < grades[i][j]){
				max = grades[i][j];
				max_pos = j;
			}
		}
		tempo = grades[i][max_pos];
		grades[i][max_pos] = grades[i][0];
		grades[i][0] = tempo;
	}
	max = grades[0][0];
	for(int i = 0; i < n; i++){
		if(max < grades[i][0]){
			max = grades[i][0];
			max_pos = i;
		}
	}
	tempo = grades[max_pos][0];
	grades[max_pos][0] = grades[0][0];
	grades[0][0] = tempo;
	//MAX FOR FIRST OBJECT IS grades[0][0];
	//NOW FIND MAX FOR SECOND OBJECT.
	for(int i = 0; i < Obj.n; i++) {
		max = Obj.grades[i][0];
		for(int j = 0; j < Obj.p; j++){
			if (max < Obj.grades[i][j]){
				max = Obj.grades[i][j];
				max_pos = j;
			}
		}
		tempo = Obj.grades[i][max_pos];
		Obj.grades[i][max_pos] = Obj.grades[i][0];
		Obj.grades[i][0] = tempo;
	}
	max = Obj.grades[0][0];
	for(int i = 0; i < Obj.n; i++){
		if(max < Obj.grades[i][0]){
			max = Obj.grades[i][0];
			max_pos = i;
		}
	}
	tempo = Obj.grades[max_pos][0];
	Obj.grades[max_pos][0] = Obj.grades[0][0];
	Obj.grades[0][0] = tempo;
	if (grades[0][0] > Obj.grades[0][0]){
		output_file_p4 << "++++++++ P4 RETURNS TRUE." << endl;
		output_file_p4 << "++++++++ P4 END ++++" << endl;
		return 1;
	}
	else {
		output_file_p4 << "++++++++ P4 RETURNS FALSE." << endl;
		output_file_p4 << "++++++++ P4 END ++++" << endl;
	}
}

void 
OVERLOADED_BURSAR::operator = (OVERLOADED_BURSAR Obj)
{
	// your code goes below:
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR = METHOD FOR OBJECT " << objectName << ":" << endl;
	output_file_p4 << "++++++++ P4 CONTENTS OF OBJECT " << Obj.objectName << " IS ASSIGNED TO OBJECT " << objectName << "." << endl;
	n = Obj.n;
	p = Obj.p;
	strcpy(objectName, Obj.objectName);
	for(int i = 0; i < Obj.n; i++){
		ids[i] = Obj.ids[i];
		strcpy(LastName[i], Obj.LastName[i]);
		strcpy(FirstName[i], Obj.FirstName[i]);
	}
	for(int i = 0; i < Obj.n; i++){
		for(int j = 0; j < Obj.p; j++) {
			grades[i][j] = Obj.grades[i][j];
		}
	}
	output_file_p4 << "++++++++ P4 END ++++" << endl;
}

OVERLOADED_BURSAR 
OVERLOADED_BURSAR::operator + (OVERLOADED_BURSAR Obj)
{
	OVERLOADED_BURSAR TEMP("TempObj"); // create a temp object
	strcpy(TEMP.objectName, "TempObj");
	// your code goes below:
	int arrayLength = sizeof(ids) / sizeof(ids[0]); //For future compatibility to change the size of the ids array.
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR + METHOD FOR OBJECT " << objectName << ":" << endl;
		
	if (n + Obj.n > arrayLength || p != Obj.p){
		cout << n + Obj.n << endl;
		cout << p << " " << Obj.p << endl;
		output_file_p4 << "++++++++ P4 INPUT ERROR." << endl;
		output_file_p4 << "++++++++ P4 END ++++" << endl;
		return TEMP;
	}
	//TEMP = *this;

	TEMP.n = n;
	for(int i = 0; i < n; i++){
		TEMP.ids[i] = ids[i];
		strcpy(TEMP.LastName[i], LastName[i]);
		strcpy(TEMP.LastName[i], LastName[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < p; j++){
			TEMP.grades[i][j] = grades[i][j];
		}
	}

	TEMP.n = TEMP.n + Obj.n;
	for (int i = 0; i < Obj.n; i++){
		TEMP.ids[n + i] = Obj.ids[i];
		strcpy(LastName[n+i],Obj.LastName[i]);
		strcpy(FirstName[n+i],Obj.FirstName[i]);
	}

	for(int i = 0; i < Obj.n; i++){
		for(int j = 0; j < p; j++){
			TEMP.grades[n + i][j] = Obj.grades[i][j];
		}
	}
	output_file_p4 << "++++++++ P4 INFORMATION FROM " << objectName << " AND " << Obj.objectName << " HAVE BEEN ADDED." << endl; 
	output_file_p4 << "++++++++ P4 END ++++" << endl;

	return  TEMP;
}

