/*
In a collection of elements, each element contains information about postgraduate students, such 
as student ID, last name, first name, middle name, home address, landline number, mobile number, 
and selected first-semester course.
- Write C code to represent a student record.
- Write C code to represent the set of students using an array of records.
- Use a pointer structure to access all students who have chosen a specific course.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct home_address{
	char area[20];
	char address[30];
	int street_number;
};

struct student{
    int am;
    char surname[20];
    char name[20];
    char fathers_name[20];
    struct home_address addr;
    char home_phone[15];
    char cell_phone[15];
    char optional_course[20];
    struct student *next;		// Pointer field, pointing to the next student with the same elective course
};
struct student *head[3];		// The beginning of each list

void course(int i){			// Traversal of the i list
    struct student *temp;
    temp=head[i];
    if(temp==NULL){
    	printf("Nobody!\n");
        return;
    }
    printf("*****************************************************\n");
    while (temp!=NULL){
        printf("Student: %s %s, with am:%d\n", temp->surname, temp->name, temp->am);
        temp=temp->next;
    }
    printf("*****************************************************\n");
}

int main(){
	int n, i, j;
	char s1[10] = "diakrita";
    char s2[10] = "eidika";
    char s3[10] = "prolog";
	printf("How many postgraduate students are?");
	scanf("%d", &n);
	struct student S[n];
	for (i = 0; i < n; i++){
		printf("Student%d\n",i + 1);
		printf("Enter am:");
    	scanf("%d", &S[i].am);
    	printf("Enter surname:");
    	scanf("%s", S[i].surname);
		printf("Enter name:");
    	scanf("%s", S[i].name);
    	printf("Enter father's name:");
    	scanf("%s", S[i].fathers_name);
    	printf("Student's address\n");
    	printf("Enter area:");
    	scanf("%s", S[i].addr.area);
    	printf("Enter address:");
    	scanf("%s", S[i].addr.address);
    	printf("Enter street number:");
    	scanf("%d", &S[i].addr.street_number);
    	printf("Enter home phone:");
    	scanf("%s", S[i].home_phone);
    	printf("Enter cell phone:");
    	scanf("%s", S[i].cell_phone);
    	printf("The elective courses of the first semester are %s, %s, %s.\n", s1, s2, s3);
    	printf("Enter optional_course:");
    	scanf("%s", S[i].optional_course);
	}

    for (i = 0; i < n; i++){
    	printf("Student%d: %s %s with am:%d, father's name:%s, address:%s %d, %s, home phone number:%s, mobile phone number: %s, optional_course:%s\n", i+1, S[i].surname, S[i].name, S[i].am, S[i].fathers_name, S[i].addr.address, S[i].addr.street_number, S[i].addr.area, S[i].home_phone, S[i].cell_phone, S[i].optional_course);
	}
	// Declaration of the list of students with distinct elements
	for (i = 0; i < n; i++){
		if (strcmp(S[i].optional_course, s1) == 0){
			head[0] = &S[i];
			break;
		}
	}
	for (i = 0; i < n; i++){
		if (strcmp(S[i].optional_course, s2) == 0){
			head[1] = &S[i];
			break;
		}
	}
	for (i = 0; i < n; i++){
		if (strcmp(S[i].optional_course, s3) == 0){
			head[2] = &S[i];
			break;
		}
	}
	//Creation of the lists.
	for (i = 0; i < n; i++){
		for (j = i + 1; j < n; j++){
			if (strcmp(S[i].optional_course, S[j].optional_course) == 0){
				break;
			}
		}
		if (j == n){
			S[i].next = NULL;
		}
		else {
			S[i].next = &S[j];
		}
	}
	while (1){			//Menu of options 
		int user_input;
		printf("1.%s\n", s1);
		printf("2.%s\n", s2);
		printf("3.%s\n", s3);
		printf("4.Exit\n");
		scanf("%d", &user_input);
		if (user_input == 1){
			printf("The students with elective course %s:\n", s1);
			course(user_input-1);
		}
		else if (user_input == 2){
			printf("The students with elective course %s:\n", s2);
			course(user_input-1);
		}
		else if (user_input == 3){
			printf("The students with elective course %s:\n", s3);
			course(user_input-1);
		}
		else if (user_input == 4){
			break;
		}
	}
	
	return 0;
}
