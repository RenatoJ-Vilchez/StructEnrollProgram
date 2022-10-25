//This is a two Struct program that lets the user act register students for a CSIT class. The comments will go along of the explantion of the program//
#include <stdio.h>
#include <stdlib.h>
#define MAX 6
//MAX determines the limit of students able to enroll in a class, set at 6//

typedef struct{ //Declare struct//
char first[30];  char last[30];   float gpa;  char major[30];  //char declartion used for first name, last name, GPA, and major in 'student'.//
} Student; //One struct type is created, which is for student//

typedef struct{ //Another struct type is created//
Student roster[10];   char titleOfCourse [30]; int numberOfStudents;  
} Course; //This time for course//

int main(void) {
Course *ArrayforCourse;  int numOfCourses;  char FirstName[30];  char LastName[30]; float studentGPA;  
char studentmajor[30];  char answer[10]; // array objects are declared for the 'Course' struct which inculde FirstName,LastName, student GPA, student Major, and answer. //
printf("Enter the number of courses to register for: "); //Instruction to the user to enter the amount of courses they wish to register for//
scanf("%d",&numOfCourses); //In order for the program to properly know how many courses will be taken for registration, a scanf function will ready it out for the console as the result//
printf("-------------------------------------------------------\n"); //A extended line is used to add neatness to the console or output adter declaring how many courses//
ArrayforCourse = (Course *) malloc(numOfCourses*sizeof( Course)); //Malloc is used to allocate memorory for the number of courses//

for (int i=0; i< numOfCourses; i++)
{
printf("Enter the name of the course: ", i+1); //Instruction to the user to enter the name of the course they wish to take//
//NOTE : When entering the name of the course, the full name of the course must be entered without any spacing. For example : 'CSIT430' is acceptable.  'CSIT 430' is not acceptable and the program will not respond well//
scanf("%s", (ArrayforCourse+i)->titleOfCourse); //Scanf function will ready the command for the course title//
 
   
(ArrayforCourse+i)->numberOfStudents = 0;
printf("Yes or No to enter the information of student?: "); //An instruction for the user to enter the student information. If a user selects 'Yes', then student information can be added. If 'No', then either the user can add the next course or find out how many students are in a class and their GPAs//

scanf("%s", answer); //For a response of 'Yes' or 'No', a scanf will present the user the option to answer. Without it, the user will not able to answer and the code can not go on to run//
    
  
while (strcmp(answer, "Yes" )==0 ||strcmp(answer, "yes")==0 )  //With an answer of 'Yes' entered by the user, it will go on to proceed//
{
if ((ArrayforCourse +i )->numberOfStudents < MAX) //From what was entered eariler with the integer command and 'numberOfStudent', it will keep in mind of what was set in MAX of 6 students to be registered//
{
//Now it is time to add printf commoands for the user to add information of the student//
printf("Enter first name of student: \n"); //User enters first name of student//
scanf("%s", FirstName); //Scanf will recongize request of user through FirstName item from array//

printf("Enter last name of student: \n "); //User enters last name of student//
scanf("%s", LastName); //Likewise with FirstName item, scanf will recongize the LastName request//

printf("Enter the GPA of the student: \n"); //User enters GPA of student//
scanf("%f.2", &studentGPA); //Scanf will recongize request of GPA that was entered by the user//

printf("Enter the major of the student: \n "); //User enters the class major of the studnet//
gets (studentmajor);
gets (studentmajor);
//Gets command recognize the name of the major selected by student//
if (studentGPA >= 2.5 && strcmp (studentmajor, "Computer Science") == 0 ) //Computer Science is the requirement for a student to register for a CSIT course, as per requirements of the assignment. Also, right by studentGPA is a GPA requirement set up at 2.5. Anything below that will not allow a student to register for the class//    
//NOTE: To register, the student MUST be a Computer Science major. The student can not be from any other major//
{ 
printf("The student has been accepted to the course. \n"); //Message that indicates the student has passed the requirements to be registered// 
(ArrayforCourse+i)-> roster [(ArrayforCourse+i)->numberOfStudents].gpa = studentGPA; 
strcpy((ArrayforCourse+i) -> roster [(ArrayforCourse+i)->numberOfStudents].first, FirstName);
strcpy((ArrayforCourse+i) -> roster [(ArrayforCourse+i)->numberOfStudents].last, LastName);
strcpy((ArrayforCourse+i) -> roster[(ArrayforCourse+i)->numberOfStudents].major, studentmajor); 
((ArrayforCourse+i) -> numberOfStudents) ++;
}
else
printf("The student is not eligilbe for the course \n");
//If the student does not meet the requirments, the student will be denied to be eligilbe for the course//
printf("Do you want to continue to enter student info for this course? Yes or No?: "); //If the user wants to keep on adding more students to the course, they can select 'Yes'. If 'No', then either they can go to the next course or finish to see the list of students in the courses//
scanf("%s", answer); //For the reply of the user to be recorded, a scanf for the answer item will make sure it goes through"
printf("----------------------------------------------------\n");
}

else  
{
printf("The course is full. No more students can enroll in the course. \n"); //The user can not add any more students to the course because it has reached MAX capacity//
break; //The loop has been terminated//
}
    
} 
          
} 
printf("---------------------------------------------------\n");
printf("Here are the courses and the students that are enrolled: \n"); //Once there are no more courses to register for, the console will display a list that recpas the courses that were registered for and the information of the students//
printf("---------------------------------------------------\n");
for (int i=0; i< numOfCourses; i++)
{
printf("Course %s has %d students enrolled:\n",  
(ArrayforCourse+i)->titleOfCourse,(ArrayforCourse+i)-> numberOfStudents);
printf("---------------------------------------------------\n");
//By this point, the console displays a list of the students information and to know they are in the course//
for (int j = 0; j<(ArrayforCourse+i )->numberOfStudents; j++)
{
printf("Name of student is %s %s \n", (ArrayforCourse+i)->roster[j].first, (ArrayforCourse+i)->roster[j].last);
printf("Student GPA is %0.2f\n", (ArrayforCourse+i)->roster[j].gpa);
printf("Student Major is %s\n",(ArrayforCourse+i)->roster[j].major);
printf("\n"); //The printf statemnts displays all information of the student in the console//
}
       
}
free(ArrayforCourse);
printf("-------------------------------------------\n");
printf("\n End of the struct program. Program is finished \n"); //To let the user know that the program has finished, a message is display to let them know//
return 0;
}
// Program and insturctions are done //
