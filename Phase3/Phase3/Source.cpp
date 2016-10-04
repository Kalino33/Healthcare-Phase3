#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class phaseIII {

public:
	// List All Functions
	int phaseIII::menu();
	int phaseIII::Begin_Program1();
	int phaseIII::Begin_Program2();
	void phaseIII::Modify_Patient();
	void phaseIII::Modify_Surgery();
	void phaseIII::Report_Section();
	void phaseIII::Stop();

private:
	int choice;
	int pCount;
	int sCount;
	int repChoice;
	int mPatChoice;
	int delPatNum;
	int delPatPosition;
	int modPatNum;
	int modPatMenuSel;
	int mPatPosition;
	int mSurgeryChoice;
	int surPatHold;
	int patSurgId;
	string searchDoc, searchDiagnosis, searchDateStart, searchDateEnd, docIn;

	ifstream infile;
	ofstream outfile;
	ifstream surInfile;
	ofstream surOutfile;

	// Parallel Arrays for Patient Data File
	int patientNum[100];
	string pName[100], pDoc[100], addDate[100], diagnosis[100];

	// Parallel arrays for Surgery Data File
	int surPatNum[100];
	string surDate[100], surLocation[100];
	double surCost[100];

};

int main() {
	int choice = 0;
	phaseIII value;

	// Beginning Functions
	value.Begin_Program1();
	value.Begin_Program2();

	choice = value.menu();
	while (choice != 4) {
		if (choice == 1){
			value.Modify_Patient();
		}
		if (choice == 2){
			value.Modify_Surgery();
		}
		if (choice == 3){
			value.Report_Section();
		}
		choice = value.menu();
	}
	value.Stop();
	system("pause");
	return 0;
}

int phaseIII::menu() {
	choice = 0;
	// Verify Value Entry
	do {
		cout << endl;
		cout << "ACME Health System" << endl << endl;
		cout << "1. Add/Modify Patient Information." << endl;
		cout << "2. Add/Modify Surgery Information." << endl;
		cout << "3. Report Section." << endl;
		cout << "4. Exit Health System." << endl << endl;
		cout << "Please make your selection: ";
		cin >> choice;
	} while ((choice < 1) || (choice > 4));
	return choice;
}

void phaseIII::Modify_Patient() {
	mPatChoice = 0;
	// Verify entry
	do {
		cout << endl;
		cout << " Add/Modify Patient Information" << endl << endl;
		cout << "1. Add Patient" << endl;
		cout << "2. Delete Patient" << endl;
		cout << "3. Modify Patient Information" << endl << endl;
		cout << "Please enter your selection: ";
		cin >> mPatChoice;
	} while ((mPatChoice < 1) || (mPatChoice > 3));

	// Add Patient
	if (mPatChoice == 1) {
		pCount += 1;
		cout << "Enter Patient Number: ";
		cin >> patientNum[pCount];
		cout << endl << "Enter Patient Name(use _ for space between first and last name): ";
		cin >> pName[pCount];
		cout << endl << "Enter Patient's Doctor(Last Name Only): ";
		cin >> pDoc[pCount];
		cout << endl << "Enter Patient's Date of Admission(MM/DD/YY): ";
		cin >> addDate[pCount];
		cout << endl << "Enter Patient's Diagnosis(use _ for spaces): ";
		cin >> diagnosis[pCount];
	}

	// Delete Patient
	if (mPatChoice == 2){
		delPatNum = 0;
		delPatPosition = 0;
		
		cout << "Enter the Patient Number for Deletion: ";
		cin >> delPatNum;

		for (int i = 0; i <= pCount; i++){
			if (patientNum[i] == delPatNum){
				delPatPosition = i;
				for (int i = delPatPosition; i <= (pCount - 1); i++){
					patientNum[i] = patientNum[i + 1];
					pName[i] = pName[i + 1];
					pDoc[i] = pDoc[i + 1];
					addDate[i] = addDate[i + 1];
					diagnosis[i] = diagnosis[i + 1];
				}
			}
		}
	}

	// Modify Patient
		if (mPatChoice == 3){
		cout << "Enter Patient Number to Search: ";
		cin >> modPatNum;
		for (int i = 0; i <= pCount; i++){
			if (modPatNum == patientNum[i]){
				do {
					modPatMenuSel = 0;
					cout << endl << "1. Change Patient Name" << endl;
					cout << "2. Change Patient Doctor" << endl;
					cout << "3. Change Admission Date" << endl;
					cout << "4. Change Diagnosis" << endl;
					cout << endl;
					cout << "Please enter your selection: ";
					cin >> modPatMenuSel;
				} while ((modPatMenuSel < 1) || (modPatMenuSel > 4));
				
				if (modPatMenuSel == 1) {
					cout << endl << "Enter New Patient Name(use _ for space bewteeen first and last name): ";
					cin >> pName[i];
				}

				if (modPatMenuSel == 2){
					cout << endl << "Enter New Patient Doctor's Name(last name only): ";
					cin >> pDoc[i];
				}

				if (modPatMenuSel == 3){
					cout << endl << " Enter New Admission Date(MM/DD/YY): ";
					cin >> addDate[i];
				}

				if (modPatMenuSel == 4){
					cout << endl << "Enter New Patient Diagnosis(use _ for spaces): ";
					cin >> diagnosis[i];
				}
			}
		}
	}
}

void phaseIII::Modify_Surgery() {
	cout << endl << "Modify Surgery Executed." << endl;
}

int phaseIII::Begin_Program1(){
	// Read in patientc.dat information and store in parallel arrays
	infile.open("patientc.dat");
	while (!infile.eof() && !infile.fail()) {
		pCount += 1;
		infile >> patientNum[pCount] >> pName[pCount] >> pDoc[pCount] >> addDate[pCount] >> diagnosis[pCount];
	}
	infile.close();
	return pCount;
}

int phaseIII::Begin_Program2() {
	// Read in surgeryc.dat information and store in parallel arrays
	surInfile.open("surgeryc.dat");
	while (!surInfile.eof() && !surInfile.fail()) {
		sCount += 1;
		surInfile >> surPatNum[sCount] >> surDate[sCount] >> surLocation[sCount] >> surCost[sCount];
	}
	surInfile.close();
	return sCount;
}

void phaseIII::Report_Section(){
		
	// Verify correct value entered
	do {
		cout << endl;
		cout << "ACME Health System Report Section" << endl;
		cout << endl;
		cout << "1. All Patient Info" << endl;
		cout << "2. All patients who have a specific Doctor" << endl;
		cout << "3. All patients who have a specific Diagnosis" << endl;
		cout << "4. All patients admitted between specific Dates" << endl;
		cout << "5. All Surgery Info" << endl;
		cout << "6. All Patients Surgery Info" << endl;
		cout << "7. All Surgery for Specific Patient" << endl;
		cout << "8. All Info for Specific Doctor" << endl;
		cout << "9. Exit Report Menu" << endl;
		cout << endl;
		cout << "Please make your selection (1 through 9 only) > ";
		cin >> repChoice;
	} while ((repChoice < 1) || (repChoice > 9));

	while (repChoice != 9){
		
		// Print out all patient information
		if (repChoice == 1) {
			cout << endl;
			cout << "ALL PATIENT INFO" << endl;
			cout << "-----------------" << endl << endl;
			for (int i = 1; i <= pCount; i++) {
				cout << patientNum[i] << " " << pName[i] << " " << pDoc[i] << " " << addDate[i] << " " << diagnosis[i] << endl;
			}
			cout << endl << endl;
			system("pause");
		}

		// Doctor's name search
		if (repChoice == 2) {
			cout << endl << "Enter the Doctor's name: ";
			cin >> searchDoc;
			cout << endl;

			for (int i = 0; i <= pCount; i++){
				if (searchDoc == pDoc[i]){
					cout << patientNum[i] << " " << pName[i] << " " << addDate[i] << " " << diagnosis[i] << endl;
				}
			}
			cout << endl;
			system("pause");
		}

		// Diagnosis search
		if (repChoice == 3) {
			cout << endl;
			cout << "Enter the Diagnosis you are looking for: ";
			cin >> searchDiagnosis;
			cout << endl;

			for (int i = 0; i <= pCount; i++) {
				if (searchDiagnosis == diagnosis[i]){
					cout << patientNum[i] << " " << pName[i] << " " << pDoc[i] << " " << addDate[i] << endl;
				}
			}
			cout << endl;
			system("pause");
		}

		// Date Range Search
		if (repChoice == 4){
			cout << endl << "Enter the beginning date for the range(MM/DD/YY): ";
			cin >> searchDateStart;
			cout << endl << "Enter the ending date for the range(MM/DD/YY): ";
			cin >> searchDateEnd;
			cout << endl;

			for (int i = 0; i <= pCount; i++){
				if ((addDate[i] >= searchDateStart) && (addDate[i] <= searchDateEnd)){
					cout << patientNum[i] << " " << pName[i] << " " << pDoc[i] << " " << addDate[i] << " " << diagnosis[i] << endl;
				}
			}
			cout << endl;
			system("pause");
		}

		// Print All Surgery Information
		if (repChoice == 5) {
			cout << endl;
			cout << "ALL SURGERY INFO" << endl;
			cout << "----------------" << endl;
			cout << endl;
			for (int i = 1; i <= sCount; i++){
				cout << surPatNum[i] << " " << surDate[i] << " " << surLocation[i] << " " << surCost[i] << endl;
			}
			cout << endl;
			system("pause");
		}

		if (repChoice == 6) {
			cout << endl << "ALL PATIENTS WITH SURGERY";
			cout << endl << "-------------------------";
			cout << endl << endl;
			for (int i = 1; i <= sCount; i++){
				surPatHold = surPatNum[i];
				for (int x = 1; x <= pCount; x++){
					if ((surPatHold == patientNum[x]) && (surPatHold > 0)) {
						cout << surPatNum[x] << " " << pName[x] << " " << pDoc[x] << " " << surDate[x] << " " << surCost[x] << endl << endl;
					}
				}
			}
		}

		if (repChoice == 7) {
			patSurgId = 0;
			cout << endl << "Enter Patient Number: ";
			cin >> patSurgId;
			for (int i = 0; i <= pCount; i++){
				if (patSurgId == patientNum[i]){
					cout << patientNum[i] << " " << pName[i] << " " << pDoc[i] << " " << addDate[i] << " " << diagnosis[i];
					if (patSurgId == surPatNum[i]){
						cout << " " << surDate[i] << " " << surLocation[i] << " " << surCost[i] << endl;
					}
					cout << endl;
				}
				
			}

		}

		if (repChoice == 8) {
			cout << endl << "Enter Doctor's Name(last name only): ";
			cin >> docIn;
			for (int i = 0; i <= pCount; i++){
				if (docIn == pDoc[i]){
					cout << endl << patientNum[i] << " " << pName[i] << " " << addDate[i] << " " << diagnosis[i];
					for (int s = 0; s <= sCount; s++){
						if (patientNum[i] == surPatNum[s]){
							cout << " " << surDate[s] << " " << surLocation[s] << " " << surCost[s];
						}
					}
					cout << endl;
				}
			}
		}
		
		cout << endl;
		cout << "ACME Health System Report Section" << endl;
		cout << endl;
		cout << "1. All Patient Info" << endl;
		cout << "2. All patients who have a specific Doctor" << endl;
		cout << "3. All patients who have a specific Diagnosis" << endl;
		cout << "4. All patients admitted between specific Dates" << endl;
		cout << "5. All Surgery Info" << endl;
		cout << "6. All Patients Surgery Info" << endl;
		cout << "7. All Surgery for Specific Patient" << endl;
		cout << "8. All Info for Specific Doctor" << endl;
		cout << "9. Exit Report Menu" << endl;
		cout << endl;
		cout << "Please make your selection (1 through 9 only) > ";
		cin >> repChoice;
	}
}

void phaseIII::Stop(){

	cout << endl << "Stop Executed." << endl;
	
	// Write All Information Back To patientc.dat
	outfile.open("patientc.dat");
	for (int i = 1; i <= pCount; i++){
		if (i == pCount){
			outfile << patientNum[i] << " " << pName[i] << " " << pDoc[i] << " " << addDate[i] << " " << diagnosis[i];
		}
		else {
			outfile << patientNum[i] << " " << pName[i] << " " << pDoc[i] << " " << addDate[i] << " " << diagnosis[i] << endl;
		}

	}
	outfile.close();
	cout << endl << "Patient data written back to patientc.dat." << endl;

	// Write All Information Back To surgeryc.dat
	surOutfile.open("surgeryc.dat");
	for (int i = 1; i <= sCount; i++){
		if (i == sCount)
			surOutfile << surPatNum[i] << " " << surDate[i] << " " << surLocation[i] << " " << surCost[i];		
			else 
				surOutfile << surPatNum[i] << " " << surDate[i] << " " << surLocation[i] << " " << surCost[i] << endl;		
	}
	surOutfile.close();
	cout << "Surgery data written back to surgeryc.dat." << endl << endl;
}