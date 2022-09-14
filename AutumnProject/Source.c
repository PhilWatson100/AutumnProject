#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node
{
	int PPSN;
	char firstName[30];
	char surnameName[30];
	int yearBorn;
	char gender[10];
	char email[30];
	char kin[30];
	char lastAppointment[30];
	float weight;
	float height;
	char allergies[10];
	int smoke; 

	struct node* NEXT;
}nodeT;

void addNewPatientEnd(struct node* top);
void addNewPatientStart(struct node** end);
void displayAllPatient(struct nodeT* top);
int search(nodeT* top, int searchVal);
void displaySearch(nodeT* top, int result);
void deletePatient(struct node* top, int location);
void updatePatient(struct node* top, int location);
void statistics(struct nodeT* top);
void outputToFile(struct node* top);
void passwordF();



void main() {
	float choice = 0;
	nodeT* headPtr = NULL;
	nodeT* newNode;
	nodeT* temp;
	int searchPPSN = 0;
	int result = 0;
	float option = 0;

	passwordF();


	printf("****************************************************************\n\n");
	printf("press 1 to add a patient to the list\n");
	printf("press 2 to display all patients to screen\n");
	printf("press 3 to search for a specific patient on screen\n");
	printf("press 4 to generate stats\n");
	printf("press 5 to print details into a report file\n");
	printf("press 6 to list a patient's last appointment\n");
	printf("-1 to exit\n");
	printf("\n****************************************************************\n");

	scanf("%f", &choice);

	while (choice != -1) {
		if (choice == 1) {

			if (headPtr == NULL) {
				addNewPatientStart(&headPtr);
			}


			else
			{
				addNewPatientEnd(headPtr);
			}

		}
		//displays all patients
		else if (choice == 2) {
			displayAllPatient(headPtr);
		}
		//this will search for a specific patient and give option to either delete, update or back to menu
		else if (choice == 3) {
			printf("Please enter the Patient's PPSN you wish to search for\n");
			scanf("%d", &searchPPSN);

			result = search(headPtr, searchPPSN);

			//to check if this ppsn is in the list
			if (result == -1) {
				printf("\n\nThis PPSN %s does not exist in the list\n\n", searchPPSN);
			}

			else {

				printf("This PPSN %d exist at location %d\n", searchPPSN, result);


				//displays patient details
				displaySearch(headPtr, result);


				//follow up question to either update or delete
				printf("would you like to update this patient? 1 - for update\nwould you like to delete this patient? 2 - for delete\nAnything else to exit");
				scanf("\n%f", &option);

				//delete
				if (option == 2) deletePatient(headPtr, result);

				//update
				else if (option == 1) updatePatient(headPtr, result);


			}

		}
		//this will generate stats
		else if (choice == 4) {
			statistics(headPtr);
		}
		else if (choice == 5) {
			outputToFile(headPtr);
		}


		printf("\n\n\****************************************************************\n\n");
		printf("press 1 to add a patient to the list\n");
		printf("press 2 to display all patients to screen\n");
		printf("press 3 to search for a specific patient on screen\n");
		printf("press 4 to generate stats\n");
		printf("press 5 to print details into a report file\n");
		printf("press 6 to list a patient's last appointment\n");
		printf("press -1 to exit\n");
		printf("\n****************************************************************\n");

		scanf("%f", &choice);
	}

}
void displaySearch(struct nodeT* top, int location) {
	struct node* temp = top;
	int patient = 0;
	int i;

	for (i = 0; i < location; i++) {
		temp = temp->NEXT;
	}

	printf("\n\nHere are the patient details...\n\n*******************************************************\n\n");

	printf("patient no. %d \npatient's firstName: %s \npatient's surename: %s \nPatient's Year born: %d \npatient's PPSN: %d \npatient's gender: %s \nPatient's weight in kgs : %f kg\nPatient's height in cm: %f \n Patient's allergies : % s \nPatient's next of kin: %s \nPatient's cigerettes smoke per day : %d\n",
		patient, temp->firstName, temp->surnameName, temp->yearBorn, temp->PPSN, temp->gender, temp->weight, temp->height, temp->allergies, temp->kin, temp->smoke);
	printf("patient's Email: %s \npatient's Location of last appointment: %s\n\n*******************************************************\n\n", temp->email, temp->lastAppointment);

}


//was unable to get this working
void statistics(struct nodeT* top) {
	struct node* temp = top;
	int i;
	int allPatient = 0;
	float bmi;
	float height;
	float weight;
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	float percentA = 0;
	float percentB = 0;
	float percentC = 0;
	float percentD = 0;


	while (temp->NEXT != NULL) {

		temp = temp->NEXT;
			height = temp->height;
			weight = temp->weight;
			bmi = (height / weight) * 10;

			if (bmi < 18.5) {
				A++;
			}
			else if (bmi < 25) {
				B++;
			}
			else if (bmi < 30) {
				C++;
			}
			else {
				D++;
			}

			allPatient++;
	}

	percentA = (A / allPatient) * 100;
	percentB = (B / allPatient) * 100;
	percentC = (C / allPatient) * 100;
	percentD = (D / allPatient) * 100;

	printf("A. %f % of patients with a BMI of less than 18.5 \n B. %f % of patients with a BMI of less than 25 \n C. %f % of patients with a BMI of less than 30 \n D. %f % of patients with a BMI of greater than 30", A, B, C, D);
}

void updatePatient(struct node* top, int location) {
	struct node* temp = top;
	int i;
	int option = 0;

	for (i = 0; i < location; i++) {
		temp = temp->NEXT;
	}

	printf("Please enter the patient's firstName and sureName\n");
	scanf("%s %s", temp->firstName, temp->surnameName);

	printf("Please enter the patient's PPSN Number and Email\n");
	scanf("%d %s", &temp->PPSN, temp->email);

	printf("Please enter the Year of the patient's birth and gender\n");
	scanf("%d %s", &temp->yearBorn, temp->gender);

	printf("Please enter the patient's next of kin and where was your last appointment\n");
	scanf("%s %s", temp->kin, temp->lastAppointment);

	printf("Please enter weight in kg and height in cm\n");
	scanf("%f %f", &temp->weight, &temp->height);

	printf("Do you have any allergies and how many packets do you smoke a day\n");
	scanf("%s %d", temp->allergies, &temp->smoke);
	

}

int search(nodeT* top, int searchVal)
{
	struct node* temp = top;
	int found = -1;
	int count = 0;

	

	while (temp != NULL)
	{
		if (temp->PPSN == searchVal)
		{
			found = count;
		}

		temp = temp->NEXT;
		count++;
	}

	return found;
}

void deletePatient(struct node* top, int location)
{
	struct node* temp = top;
	struct node* prev;
	int i;
	//goto location
	for (i = 0; i < location; i++)
	{
		temp = temp->NEXT;
	}
	//save this patient before deletion
	free(temp);

}

void displayAllPatient(struct nodeT* top) {
	struct node* temp;
	int patient = 0;
	temp = top;
	

	while (temp != NULL)
	{
		
		printf("\n\n*******************************************************\n\nPatient no. %d \npatient's firstName: %s \npatient's surename: %s \nPatient's Year born: %d \npatient's PPSN: %d \npatient's gender: %s \nPatient's weight in kgs : %f kg\nPatient's height in cm: %fcm\nPatient's allergies : %s \nPatient's next of kin: %s \nPatient's cigerettes smoke per day : %d",
			patient, temp->firstName, temp->surnameName, temp->yearBorn, temp->PPSN, temp->gender, temp->weight, temp->height, temp->allergies, temp->kin, temp->smoke);
		printf("\npatient's Email: %s \npatient's Location of last appointment: %s\n\n*******************************************************\n\n\n", temp->email, temp->lastAppointment);
		temp = temp->NEXT;

		patient++;
	}
}

void addNewPatientEnd(struct node* top) {

	struct node* temp = top;
	struct node* newNode;

	//Option 1
	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Please enter the patient's firstName and sureName\n");
	scanf("%s %s", newNode->firstName, newNode->surnameName);
	printf("Please enter the patient's PPSN Number and Email\n");
	scanf("%d %s", &newNode->PPSN, newNode->email);
	printf("Please enter the Year of the patient's birth and gender\n");
	scanf("%d %s", &newNode->yearBorn, newNode->gender);
	printf("Please enter the patient's next of kin and where was your last appointment\n");
	scanf("%s %s", newNode->kin, newNode->lastAppointment);
	printf("Please enter weight in kg and height in cm\n");
	scanf("%f %f", &newNode->weight, &newNode->height);
	printf("Do you have any allergies and how many cigs do you smoke a day\n");
	scanf("%s %d", newNode->allergies, &newNode->smoke);

	while (temp->NEXT != NULL)
	{
		temp = temp->NEXT;
	}

	newNode->NEXT = NULL;
	temp->NEXT = newNode;

}

void addNewPatientStart(struct node** top){
	struct node* newNode;

	//Option 1
	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Please enter the patient's firstName and sureName\n");
	scanf("%s %s", newNode->firstName, newNode->surnameName);
	printf("Please enter the patient's PPSN Number and Email\n");
	scanf("%d %s", &newNode->PPSN, newNode->email);
	printf("Please enter the Year of the patient's birth and gender\n");
	scanf("%d %s", &newNode->yearBorn, newNode->gender);
	printf("Please enter the patient's next of kin and where was your last appointment\n");
	scanf("%s %s", newNode->kin, newNode->lastAppointment);
	printf("Please enter weight in kgs and height in cm\n");
	scanf("%f %f", &newNode->weight, &newNode->height);
	printf("Do you have any allergies and how many cigs do you smoke a day\n");
	scanf("%s %d", newNode->allergies, &newNode->smoke);

	newNode->NEXT = *top;
	*top = newNode;

}

void outputToFile(struct node* top)
{
	struct node* temp = top;
	FILE* fp;
	int patient = 0;

	fp = fopen("Patient.txt", "w");

	while (temp != NULL)
	{
		if (fp != NULL)
		{
			fprintf(fp, "\n\n*******************************************************\n\nPatient no. %d \npatient's firstName: %s \npatient's surename: %s \nPatient's Year born: %d \npatient's PPSN: %d \npatient's gender: %s \nPatient's weight in kgs : %f kg\nPatient's height in cm: %fcm\nPatient's allergies : %s \nPatient's next of kin: %s \nPatient's cigerettes smoke per day : %d",
				patient, temp->firstName, temp->surnameName, temp->yearBorn, temp->PPSN, temp->gender, temp->weight, temp->height, temp->allergies, temp->kin, temp->smoke);
			fprintf(fp, "\npatient's Email: %s \npatient's Location of last appointment: %s\n\n*******************************************************\n\n\n", temp->email, temp->lastAppointment);
			
			patient++;
		}
		temp = temp->NEXT;
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}

void passwordF() {
	char userName[15];
	char password[6];
	FILE* fp;
	char fUser[15];
	char fPass[6];
	int userLen;
	int passLen;
	float incorrect = -1;

	fp = fopen("login.txt","r");
	

	if (fp == NULL) {
		fp = fopen("login.txt", "w");
		printf("Hello this is your first time opening this file...\nPlease input your username and passoword - (Your password must be 6 characters in lenth)\n");
		scanf("%s %s", userName, password);

		fprintf(fp, "%s\n%s", userName, password);
		fclose(fp);
	}
	else {
		//i could only get one pasword to work
		fgets(fUser, 30, fp);
		fgets(fPass, 6, fp);

		passLen = strlen(fPass) - 1;
        userLen = strlen(fUser) - 1;
		
		char ch;
		char chP;
		
		while (incorrect != 1) {
			int i = 0;

			printf("please enter your username\n");
			scanf("%s", userName);

			printf("please enter you password\n");
			while ((ch = _getch()) != 13) {
				password[i] = ch;
				printf("*");
				i++;
			}

				if (strncmp(fUser, userName, userLen) == 0  && strncmp(fPass, password, passLen) == 0 ) {

					printf("Username and password correct\n\n");

					fclose(fp);

					incorrect = 1;
				}
				else {

					printf("user name or password incorrect\n\n");

				}
			
		}
		
	}
}
