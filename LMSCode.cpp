#include <iostream.h> // Input-output operations
#include<conio.h> // Console input/output operations
#include<iomanip.h> // Input-output manipulator
#include<stdlib.h>  // Standard library for general utilities
#include<string.h> // String manipulation functions
#include<stdio.h> // Standard input-output operations
#include<fstream.h> // File handling operations

// Class for managing book records
class book {
	char bno[6]; // Book number
	char bname[50]; // Book name
	char aname[20]; // Author name
public:
	// Function to create a new book entry
	void createbook() {
		cout<<"\nNEW BOOK ENTRY...\n";
		cout<<"\nENTER BOOK NO.";
		cin>>bno;
		cout<<"\nENTER BOOK NAME";
		gets(bname); // Enables enter with space
		cout<<"\nENTER AUTHOR NAME";
		gets(aname);
		cout<<"\n\n\nBook Created..";
	}

	// Function to display book details
	void showbook() {
		cout<<"\nBook Number: "<<bno;
		cout<<"\nBook Name: ";
		puts(bname);
		cout<<"\nBook Author Name: ";
		puts(aname);
	}

	// Function to modify book details
	void modifybook() {
		cout<<"\nBook Number: "<<bno;
		cout<<"\nModify Book Name :";
		gets(bname);
		cout<<"\nModify Author's Name :";
		gets(aname);
	}

	// Function to return book number
	char* retbno() { // String return
		return bno;
	}

	// Function to display book report
	void report() {
		cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
	}
};

// Class for managing student records
class student {
	char admno[6]; // Admission number
	char name[20]; // Student name
	char stbno[6]; // Student book number 
	int token; // Total book of student
public:
	// Function to create a new student entry
	void createstudent() {
		clrscr();
		cout<<"\nNEW STUDENT ENTRY...\n";
		cout<<"\nEnter The Admission No. ";
		cin>>admno;
		cout<<"Enter The Student Name ";
		gets(name);
		token=0;
		stbno[0]='\0';
		cout<<"\n\nStudent Record Created...";
	}

	// Function to display student details
	void showstudent() {
		cout<<"\nAdmission Number : "<<admno;
		cout<<"\nStudent Name : ";
		puts(name);
		cout<<"\nNo of Book Issued : "<<token;
		if(token==1) {
			cout<<"\nBook Number "<<stbno;
		}
	}

	// Function to modify student details
	void modifystudent() {
		cout<<"\nAdmission No. "<<admno;
		cout<<"\nModify Student Name : ";
		gets(name);
	}

	// Function to return admission number
	char* retadmno() {
		return admno;
	}

	// Function to return student book number
	char* retstbno() {
		return stbno;
	}

	// Function to return token
	int rettoken() {
		return token;
	}

	// Function to add a token
	void addtoken() {
		token=1;
	}

	// Function to reset token
	void resettoken() { 
		token=0;
	}

	// Function to set student book number
	void getstbno(char t[]) {
		strcpy(stbno,t);
	}

	// Function to display student report
	void report() {
		cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl ;
	}
};

fstream fp,fp1; // File stream objects
book bk; // Book class object
student st; // Student class object

// Function to write book records to file
void writebook() {
	char ch;
	fp.open("book.dat",ios::out|ios::app); // Write and append data
	do {
		clrscr();
		bk.createbook();
		fp.write((char*)&bk,sizeof(book)); // Size of class
		cout<<"\n\nDo you want to add more record...(y/n?) ";
		cin>>ch;
	} while(ch=='y'||ch=='Y');
	fp.close();
}

// Function to write student records to file
void writestudent() {
	char ch;
	fp.open("student.dat",ios::out|ios::app); // Write and append data
	do {
		clrscr();
		st.createstudent();
		fp.write((char*)&st,sizeof(student)); // Size of class
		cout<<"\n\nDo you want to add more record...(y/n?) ";
		cin>>ch;
	} while(ch=='y'||ch=='Y');
	fp.close();
}

// Function to display specific book details
void displayspb(char n[]) {
	cout<<"\nBOOK DETAILS\n";
	int flag=0; // Book not found
	fp.open("book.dat",ios::in); // Read data
	while(fp.read((char *)&bk,sizeof(book))) {
		if(strcmpi(bk.retbno(),n)==0) { // Case-insensitive comparison
			bk.showbook();
			flag=1;
		}
	}
	fp.close();
	if(flag==0) { // Book not found
		cout<<"\n\nBook does not exist";
	}
	getch();
}

// Function to display specific student details
void displaysps(char n[]) {
	cout<<"\nSTUDENT DETAILS\n";
	int flag=0; // Student not found
	fp.open("student.dat", ios::in); // Read data
	while(fp.read((char *)&st,sizeof(student))) {
		if(strcmpi(st.retadmno(),n)==0) { // Case-insensitive comparison
			st.showstudent();
			flag=1;
		}
	}
	fp.close();
	if(flag==0) { // Student not found
		cout<<"\n\nStudent does not exist";
	}
	getch();
}

// Function to modify book record
void modifybook() {
	char n[6];
	int found=0; // Search book of given data
	clrscr();
	cout<<"\n\nMODIFY BOOK RECORD...";
	cout<<"\n\nEnter the book no. ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book)) && found==0) {
		if(strcmpi(bk.retbno(),n)==0) {
			bk.showbook();
			cout<<"\nEnter the new details book";
			bk.modifybook();
			int pos=-1*sizeof(bk);
			fp.seekp(pos,ios::cur); // Move back from current position
			fp.write((char *)&bk,sizeof(book));
			cout<<"\n\nRecord Updated";
			found=1;
		}
	}
	fp.close();
	if(found==0) {
		cout<<"\n\nRecord Not Found";
	}
	getch(); // Press key to exit
}

// Function to modify student record
void modifystudent() {
	char n[6];
	int found=0; // Search book of given data
	clrscr();
	cout<<"\n\nMODIFY STUDENT RECORD...";
	cout<<"\n\nEnter the Admission no. ";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0) {
		if(strcmpi(st.retadmno(),n)==0) {
			st.showstudent();
			cout<<"\nEnter the new details of student";
			st.modifystudent();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur); // Move back from current position
			fp.write((char *)&st,sizeof(student)); 
			cout<<"\n\nRecord Updated";
			found=1;
		}
	}
	fp.close();
	if(found==0) {
		cout<<"\n\nRecord Not Found";
	}
	getch(); // Press key to exit
}

// Function to delete student record
void deletestudent() {
	char n[6];
	int flag=0;
	clrscr();
	cout<<"\n\n\n\tDELETE STUDENT...";
	cout<<"\n\nEnter the Admission no. : ";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&st,sizeof(student))) {
		if(strcmpi(st.retadmno(),n)!=0) {
			fp2.write((char*)&st,sizeof(student));
		}
		else {
			flag=1; // Student found
		}
	} 
	fp2.close();
	fp.close();
	remove("student.dat");
	rename("temp.dat","student.dat"); // Data after deletion moved to temp
	if(flag==1) {
		cout<<"\n\n\tRecord Deleted..";
	}
	else {
		cout<<"\n\nRecord not Found"; 
	}
	getch();
}

// Function to delete book record
void deletebook() {
	char n[6]; // Book no.
	int flag=0;
	clrscr();
	cout<<"\n\n\n\tDELETE BOOK...";
	cout<<"\n\nEnter the Book no. : ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2; // New object
	fp2.open("Temp.dat",ios::out); // Temp file having data else than that to be deleted
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book))) {
		if(strcmpi(bk.retbno(),n)!=0) {
			fp2.write((char*)&bk,sizeof(book));
		}
		else {
			flag=1; // Book found
		}
	} 
	fp2.close();
	fp.close();
	remove("book.dat");
	rename("Temp.dat","book.dat"); // Data after deletion moved to temp
	if(flag==1) {
		cout<<"\n\n\tRecord Deleted... ";
	}
	else {
		cout<<"\n\nRecord not Found"; 
	}
	getch();
}

// Function to display all student records
void displayalls() {
	clrscr();
	fp.open("student.dat",ios::in); // Read mode
	if(!fp) {
		cout<<"File Could Not Be Open";
		getch();
		return; // Press any key and return
	}
	cout<<"\n\n\t\tStudent List\n\n";
	cout<<"==================================================================\n";
	cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
	cout<<"==================================================================\n";
	while(fp.read((char*)&st,sizeof(student))) {
		st.report();
	}
	fp.close();
	getch();
}

// Function to display all book records
void displayallb() {
	clrscr();
	fp.open("book.dat",ios::in); // Read mode
	if(!fp) {
		cout<<"File Could Not Be Open";
		getch();
		return; // Press any key and return
	}
	cout<<"\n\n\t\tBook List\n\n";
	cout<<"==================================================================\n";
	cout<<"\tBook No."<<setw(20)<<"Book Name"<<setw(25)<<"Book Author\n";
	cout<<"==================================================================\n";
	while(fp.read((char*)&bk,sizeof(book))) {
		bk.report();
	}
	fp.close();
	getch();
}

// Function for book issue
void bookissue() {
	char sn[6],bn[6];
	int found=0,flag=0;
	clrscr();
	cout<<"\n\nBOOK ISSUE...";
	cout<<"\n\n\tEnter Admission no.";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student))&& found==0) {
		if(strcmpi(st.retadmno(),sn)==0) { // Compare admission no.
			found=1;
			if(st.rettoken()==0) { // If book not issued
				cout<<"\n\n\tEnter The Book No.";
				cin>>bn;
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0) {
					if(strcmpi(bk.retbno(),bn)==0) { // Compare book no.
						flag=1;
						st.addtoken();
						st.getstbno(bk.retbno()); // Pass book no.
						int pos=-1*sizeof(st);
						fp.seekg(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\n\tBook Issued Successfully\n\n Please Note The Book Issue Date On Backside Of Your Book And Return Book Within 15 Days, Otherwise Fine Of 15 Rs Per Day";
					}
				}
				if(flag==0) {
					cout<<"Book No. Does Not Exists";
				}
			} 
			else {
				cout<<"You Have Not Returned The Last Book";
			}
		}
	}
	if(found==0) {
		cout<<"Student Record Not Exists...";
	}
	getch();
	fp.close();
	fp1.close();
}

// Function for book deposit
void bookdeposit() {
	char sn[6],bn[6];
	int found=0,flag=0,day,fine;
	clrscr();
	cout<<"\n\nBOOK DEPOSIT...";
	cout<<"\n\n\tEnter Admission no. Of Student";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0) {
		if(strcmpi(st.retadmno(),sn)==0) { // Compare admission no.
			found=1;
			if(st.rettoken()==1) { // If book issued
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0) {
					if(strcmpi(bk.retbno(),st.retstbno())==0) { // Compare book no.
						bk.showbook();
						flag=1;
						cout<<"\n\nBook Deposited In No. Of Days";
						cin>>day;
						if(day>15) { // If book deposited after 15 days
							fine=(day-15)*15;
							cout<<"\n\nFine Has To Deposited Rs. "<<fine;
						}
						st.resettoken();
						int pos=-1*sizeof(st);
						fp.seekg(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\n\t Book Deposited Successfully";
					}
				}
				if(flag==0) {
					cout<<"Book No. Does Not Exist";
				}
			} 
			else {
				cout<<"No Book Is Issued..Please Check!!";
			}
		}
	}
	if(found==0) {
		cout<<"Student Record Not Exists...";
	}
	getch();
	fp.close();
	fp1.close();
}

// Function for admin menu
void admin_menu() {
	clrscr();
	int ch2;
	cout<<"\n\n\n\tADMINISTRATOR MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
	cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.CREATE BOOK ";
	cout<<"\n\n\t7.DISPLAY ALL BOOKS ";
	cout<<"\n\n\t8.DISPLAY SPECIFIC BOOK ";
	cout<<"\n\n\t9.MODIFY BOOK ";
	cout<<"\n\n\t10.DELETE BOOK ";
	cout<<"\n\n\t11.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-11) ";
	cin>>ch2;
	switch(ch2) {
		case 1: clrscr();
			writestudent();break;
		case 2: displayalls();break;
		case 3:
			char num[6];
			clrscr();
			cout<<"\n\n\tPlease Enter The Admission No. ";
			cin>>num;
			displaysps(num);
			break;
		case 4: modifystudent();break;
		case 5: deletestudent();break;
		case 6: writebook();break;
		case 7: displayallb();break;
		case 8: {
			char num[6];
			clrscr();
			cout<<"\n\n\tPlease Enter The book No. ";
			cin>>num;
			displayspb(num);
			break;
		}
		case 9: modifybook();break;
		case 10: deletebook();break;
		case 11: return;
		default:cout<<"\a"; // Alert beep
	}
	admin_menu();
}

// Function to issue or deposit books
void mainmenu() {
	int ch;
	clrscr();
	cout<<"\n\n\n\tMAIN MENU";
	cout<<"\n\n\t01. BOOK ISSUE";
	cout<<"\n\n\t02. BOOK DEPOSIT";
	cout<<"\n\n\t03. ADMINISTRATOR MENU";
	cout<<"\n\n\t04. EXIT";
	cout<<"\n\n\tPlease Select Your Option (1-4) ";
	cin>>ch;
	switch(ch) {
		case 1: clrscr();
			bookissue();
			break;
		case 2: bookdeposit();
			break;
		case 3: admin_menu();
			break;
		case 4: exit(0);
		default :cout<<"\a"; // Alert beep
	}
}

// Main function
void main() {
	char ch;
	clrscr();
	cout<<"\n\n\n\tLIBRARY MANAGEMENT SYSTEM";
	cout<<"\n\n\n\n\tMADE BY : GeovannyH";
	cout<<"\n\n\tInstitute : UW";
	getch(); // Press key to continue
	mainmenu();
	getch();
}
