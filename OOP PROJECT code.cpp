#include <iostream> // For input/output operations
#include <string>     // For string handling
#include <fstream>    // For file handling
#include <vector>     // For using vectors
#include <sstream> 
using namespace std;
void mainmenu();
class registration
{
	string password;
	string  username;

public:
	registration()
	{

	}
	void setPassword(string p) {
		this->password = p;
	}
	void setUsername(string u) {
		this->username = u;
	}
	string getPassword() const
	{
		return password;
	}

	string getUsername() const
	{
		return username;
	}



	friend istream& operator>>(istream& is, registration& obj);
};
istream& operator>>(istream& is, registration& obj) {
    try {
        string password;
        string username;

        cout << "PLEASE ENTER YOUR USERNAME: ";
        cin.ignore();
        getline(is, username);
        if (username.empty()) {
            throw invalid_argument("Username cannot be empty.");
        }
        obj.setUsername(username);

        cout << "PLEASE ENTER YOUR PASSWORD: ";
        cin >> password;
        if (password.empty()) {
            throw invalid_argument("Password cannot be empty.");
        }
        obj.setPassword(password);
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        throw; 
    }
    return is;
}

class String
{
	char* firstname;
	char* secondname;
	char* fathername;
	char* occupation;
	char* gender;
	int age;
	string CNIC;
	string number;
	char* nationality;
	char* address;
public:
	String()
	{
		firstname = new char[20];
		secondname = new char[20];
		fathername = new char[20];
		occupation = new char[20];
		nationality = new char[25];
		gender = new char[10];


		address = new char[150];


	}
	void setfirstname(string firstname)
	{
		strcpy_s(this->firstname, 20, firstname.c_str());
		return;
	}
	void setsecondname(string secondname)
	{
		strcpy_s(this->secondname, 20, secondname.c_str());
		return;
	}
	void setfathername(string fathername)
	{
		strcpy_s(this->fathername, 20, fathername.c_str());
		return;
	}
	void setoccupation(string occupation)
	{
		strcpy_s(this->occupation, 20, occupation.c_str());
		return;
	}
	void setnationality(string nationality)
	{
		strcpy_s(this->nationality, 25, nationality.c_str());
		return;
	}
	void setgender(string gender)
	{


		strcpy_s(this->gender, 10, gender.c_str());
		return;
	}
	void setage(int age)
	{
		this->age = age;
		return;

	}
	void setcnic(string cnic)
	{
		this->CNIC = cnic;
		return;
	}
	void setnumber(string number)
	{

		this->number = number;

	}

	void setaddress(string address)
	{
		strcpy_s(this->address, 150, address.c_str());
		return;
	}
	const char* getfirstname() const
	{
		return firstname;
	}
	const char* getsecondname() const
	{
		return secondname;
	}
	const char* getfathername() const
	{
		return fathername;
	}
	const char* getoccupation() const
	{
		return occupation;
	}
	const char* getnationality() const
	{
		return nationality;
	}
	const char* getgender() const
	{
		return gender;
	}
	int getage() const
	{
		return age;
	}
	string getcnic() const
	{
		return CNIC;
	}
	string getnumber() const
	{
		return number;
	}

	const char* getaddress() const
	{
		return address;
	}
	friend istream& operator>>(istream& is, String& obj);
	~String() {
		delete[] firstname;
		delete[] secondname;
		delete[] fathername;
		delete[] occupation;
		delete[] nationality;
		delete[] gender;
		delete[] address;
	}
};
istream& operator>>(istream& is, String& obj) {
    try {
        string firstname;
        cout << "PLEASE ENTER THE FIRST NAME: ";
        cin.ignore();
        getline(is, firstname);
        if (firstname.empty()) {
            throw invalid_argument("First name cannot be empty.");
        }
        obj.setfirstname(firstname);

        string secondname;
        cout << "PLEASE ENTER THE SECOND NAME: ";
        cin >> secondname;
        if (secondname.empty()) {
            throw invalid_argument("Second name cannot be empty.");
        }
        obj.setsecondname(secondname);

        string fathername;
        cout << "PLEASE ENTER YOUR FATHER'S NAME: ";
        cin >> fathername;
        if (fathername.empty()) {
            throw invalid_argument("Father's name cannot be empty.");
        }
        obj.setfathername(fathername);

        int gen;
        string gender;
        cout << "PLEASE SELECT YOUR GENDER (1-MALE, 2-FEMALE): ";
        cin >> gen;
        if (gen != 1 && gen != 2) {
            throw invalid_argument("Invalid gender selection.");
        }
        gender = (gen == 1) ? "MALE" : "FEMALE";
        obj.setgender(gender);

        string occupation;
        cout << "PLEASE ENTER YOUR OCCUPATION: ";
        cin >> occupation;
        if (occupation.empty()) {
            throw invalid_argument("Occupation cannot be empty.");
        }
        obj.setoccupation(occupation);

        int age;
        cout << "PLEASE ENTER YOUR AGE: ";
        cin >> age;
        if (age <= 0) {
            throw invalid_argument("Age must be positive.");
        }
        obj.setage(age);

        string address;
        cout << "PLEASE ENTER YOUR ADDRESS: ";
        cin.ignore();
        getline(is, address);
        if (address.empty()) {
            throw invalid_argument("Address cannot be empty.");
        }
        obj.setaddress(address);

        string cnic;
        cout << "PLEASE ENTER YOUR CNIC OR SMART CARD NUMBER WITHOUT DASHES: ";
        cin >> cnic;
        if (cnic.size() != 13) {
            throw invalid_argument("Invalid CNIC length.");
        }
        obj.setcnic(cnic);

        string number;
        cout << "PLEASE ENTER YOUR PHONE NUMBER: ";
        cin >> number;
        if (number.size() != 11) {
            throw invalid_argument("Invalid phone number length.");
        }
        obj.setnumber(number);

        string nationalty;
        cout << "PLEASE ENTER YOUR NATIONALITY: ";
        cin >> nationalty;
        if (nationalty.empty()) {
            throw invalid_argument("Nationality cannot be empty.");
        }
        obj.setnationality(nationalty);
        
        // Prompt user to end or return to main menu
        char choice;
        cout << "Do you want to end (E) or return to the main menu (M)? ";
        cin >> choice;
        if (choice == 'E' || choice == 'e') {
            cout << "Ending input process." << endl;
            return is;
        } else if (choice == 'M' || choice == 'm') {
            mainmenu();
        } else {
            throw invalid_argument("Invalid choice. Please enter 'E' or 'M'.");
        }
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        throw; 
    }

    return is;
}



class membership
{

	char* game;
	char* instructor;
	double amount;
	string time;
	static int instructorset;
public:
	membership() {
		game = new char[20];
		instructor = new char[20];

	}
	void setGame(string& newGame) {
		strcpy_s(game, 20, newGame.c_str());
	}
	void setinstructorset(int i)
	{
		instructorset += i;
	}
	void setinstructorset(int i, int j)
	{
		instructorset = j;
	}
	void setamount(double a)
	{
		amount = a;
	}
	void settime(string time)
	{
		this->time = time;
	}
	string gettime()
	{
		return time;
	}
	static int getinstructorset()
	{
		return instructorset;
	}
	void setInstructor(string& newInstructor) {
		strcpy_s(instructor, 20, newInstructor.c_str());
	}


	const char* getGame() const {
		return game;
	}

	const char* getInstructor() const {
		return instructor;
	}

	double getAmount() const {
		return amount;
	}


	~membership() {
		delete[] game;
		delete[] instructor;

	}

};
int membership::instructorset = 0;
class User
{
protected:
	String details;
	registration reg;
	membership member;
public:


	void setmembership()
	{
		int choice;
		double cost;
		string gender;
		string TIME;
		string instructors1[28];
		string instructors2[28];
		string a, b;
		int x = 0;
		int y = 0;
		ifstream ifile1("instructors1.txt");
		ifstream ifile2("instructors2.txt");

		while (ifile1 >> a)
		{
			instructors1[x] = a;
			x++;

		}
		ifile1.close();

		while (ifile2 >> b)
		{
			instructors2[y] = b;
			y++;

		}
		ifile1.close();

		int age = details.getage();
		gender = details.getgender();
		vector<string> games{ "TENNIS","FOOTBALL","CRICKET","HOCKEY","SQUASH","BADMINTON","SWIMMING" };








		vector<string>TENNIS1 = { instructors1[0],instructors1[1], instructors1[2], instructors1[3] };
		vector<string>FOOTBALL1 = { instructors1[4],instructors1[5], instructors1[6], instructors1[7] };
		vector<string>CRICKET1 = { instructors1[8],instructors1[9], instructors1[10], instructors1[11] };
		vector<string>HOCKEY1 = { instructors1[15],instructors1[14], instructors1[13], instructors1[12] };
		vector<string>SQUASH1 = { instructors1[16],instructors1[17], instructors1[18], instructors1[19] };
		vector<string>BADMINTON1 = { instructors1[20],instructors1[21], instructors1[22], instructors1[23] };
		vector<string>SWIMMING1 = { instructors1[27],instructors1[26], instructors1[25], instructors1[24] };

		vector <string> TENNIS2 = { instructors2[0], instructors2[1], instructors2[2], instructors2[3] };
		vector<string> FOOTBALL2 = { instructors2[4], instructors2[5], instructors2[6], instructors2[7] };
		vector<string> CRICKET2 = { instructors2[8], instructors2[9], instructors2[10], instructors2[11] };
		vector<string> HOCKEY2 = { instructors2[12], instructors2[13], instructors2[14], instructors2[15] };
		vector<string> SQUASH2 = { instructors2[16], instructors2[17], instructors2[18], instructors2[19] };
		vector<string> BADMINTON2 = { instructors2[20], instructors2[21], instructors2[22], instructors2[23] };
		vector<string> SWIMMING2 = { instructors2[24], instructors2[25], instructors2[26], instructors2[27] };


		for (int i = 0; i < 7; i++)
		{
			cout << "PRESS " << i + 1 << " for " << games[i] << endl;
		}
		cin >> choice;
		if (choice >= 1 && choice <= 7)
		{
			member.setGame(games[choice - 1]);
			if (choice == 1)
			{
				member.setinstructorset(0);
			}
			else if (choice == 2)
			{
				member.setinstructorset(4);
			}
			else if (choice == 3)
			{
				member.setinstructorset(8);
			}
			else if (choice == 4)
			{
				member.setinstructorset(12);
			}
			else if (choice == 5)
			{
				member.setinstructorset(16);
			}
			else if (choice == 6)
			{
				member.setinstructorset(20);
			}
			else if (choice == 7)
			{
				member.setinstructorset(24);
			}


		}

		else {

			setmembership();
		}

		if (age >= 10 || age <= 22)
		{
			member.setamount(4000);
			TIME = "16:00";
			member.settime(TIME);

			if (gender == "MALE")
			{
				member.setInstructor(instructors1[member.getinstructorset()]);
			}
			else if (gender == "FEMALE")
			{
				member.setInstructor(instructors2[member.getinstructorset()]);
			}
		}
		else if (age >= 23 || age <= 35)
		{
			TIME = "17:00";
			member.settime(TIME);
			member.setamount(6000);
			member.setinstructorset(1);
			if (gender == "MALE")
			{
				member.setInstructor(instructors1[member.getinstructorset()]);
			}
			else if (gender == "FEMALE")
			{
				member.setInstructor(instructors2[member.getinstructorset()]);
			}
		}
		else if (age >= 36 || age <= 45)
		{
			TIME = "18:00";
			member.settime(TIME);
			member.setamount(8000);
			member.setinstructorset(2);
			if (gender == "MALE")
			{
				member.setInstructor(instructors1[member.getinstructorset()]);
			}
			else if (gender == "FEMALE")
			{
				member.setInstructor(instructors2[member.getinstructorset()]);
			}
		}
		else if (age >= 46 || age <= 60)
		{
			TIME = "19:00";
			member.settime(TIME);
			member.setamount(10000);
			member.setinstructorset(3);
			if (gender == "MALE")
			{
				member.setInstructor(instructors1[member.getinstructorset()]);
			}
			else if (gender == "FEMALE")
			{
				member.setInstructor(instructors2[member.getinstructorset()]);
			}
		}
        else if(age<10 || age>60)
        {
        	cout<<"THE AGE RANGE IS NOT SUPPORTED "<<endl;
        	exit(0);
		}

	}
};


class menu :public User
{

public:
	void REGISTRATIONSINGLE()
{
    // Input username and password
    cin >> details;
    setmembership();
    cin >> reg;
    
    // Check if the username and password already exist in the DBMS
    ifstream infile("DBMS.txt");
    string line;
    bool exists = false;
    while (getline(infile, line)) {
        stringstream ss(line);
        string username, password;
        ss >> username >> password;
        if (username == reg.getUsername() && password == reg.getPassword()) {
            exists = true;
            break;
        }
    }
    infile.close();

    // If the username and password combination already exists, notify the user and return
    if (exists) {
        cout << "Username and password combination already exists. Registration failed." << endl;
        return;
    }

    // If the combination does not exist, proceed with registration
    ofstream outfile("DBMS.txt", ios::app);
    outfile << reg.getUsername() << "  " << reg.getPassword() << "  " << details.getfirstname() << "  " << details.getsecondname() << " " << details.getfathername() << " " << details.getage() << " " << details.getaddress() << " " << details.getnationality() << " " << details.getcnic() << " " << details.getnumber() << " " << details.getoccupation() << " " << member.getGame() << " " << member.getInstructor() << " " << member.getAmount() << " " << member.gettime() << endl;
    outfile.close();
}

void USERLOGIN() {
    system("cls"); // Clear the screen
    string username, password, fname, lastname, fathername, age, address, NationalitY, CNic, num, job, sport, teacher, cOst, TiMe;
    string a, b;

    cin >> reg;
    a = reg.getUsername();
    b = reg.getPassword();
    ifstream ifile("DBMS.txt");
    string line;
    while (getline(ifile, line)) {
        stringstream ss(line);
        ss >> username >> password >> fname >> lastname >> fathername >> age >> address >> NationalitY >> CNic >> num >> job >> sport >> teacher >> cOst >> TiMe;
        if (username == a && password == b) {
            cout << "" << endl;
            cout << "*             USER PROFILE                *" << endl;
            cout << "" << endl << endl;
            cout << "LOGIN SUCCESSFUL!" << endl << endl;
            cout << "Name: " << fname << " " << lastname << endl;
            cout << "Age: " << age << endl;
            cout << "Address: " << address << endl;
            cout << "Nationality: " << NationalitY << endl;
            cout << "CNIC: " << CNic << endl;
            cout << "Contact Number: " << num << endl;
            cout << "Occupation: " << job << endl;
            cout << "Game: " << sport << endl;
            cout << "Instructor: " << teacher << endl;
            cout << "Fee: " << cOst << endl;
            cout << "Timings: " << TiMe << endl << endl;
            return;
        }
    }

    cout << "DATA NOT FOUND!" << endl;
    exit(0);
}

void INSTRUCTORLOGIN() {
    system("cls"); // Clear the screen
    string username, password, fname, lastname, fathername, age, address, NationalitY, CNic, num, job, sport, teacher, cOst, TiMe;
    string a, b, c, d, e;
    string line;
    cin >> reg;
    d = reg.getUsername();
    e = reg.getPassword();
    ifstream ifile("instructors.txt");
    while (getline(ifile, a)) {
        stringstream SS(a);
        SS >> b >> c;
        if (b == d && c == e) {
            cout << "" << endl;
            cout << "*             INSTRUCTOR'S DASHBOARD             *" << endl;
            cout << "" << endl << endl;
            cout << "Welcome, " << b << "!" << endl << endl;

            ifstream ifile3("DBMS.txt");
            if (!ifile3) {
                cerr << "ERROR IN FETCHING DATA." << endl;
            } else {
                while (getline(ifile3, line)) {
                    stringstream ss(line);
                    ss >> username >> password >> fname >> lastname >> fathername >> age >> address >> NationalitY >> CNic >> num >> job >> sport >> teacher >> cOst >> TiMe;
                    if (d == teacher) {
                        cout << "Name: " << fname << " " << lastname << endl;
                        cout << "Game: " << sport << endl;
                        cout << "Age: " << age << endl;
                        cout << "Timings: " << TiMe << endl << endl;
                    }
                }
                ifile3.close();
            }
        }
    }
    ifile.close();
}


void ADMIN()
{
    system("cls"); // Clear the screen
    string username, password, fname, lastname, fathername, age, address, NationalitY, CNic, num, job, sport, teacher, cOst, TiMe;
    int choicE;
    cin >> reg;
    string a, b;
    string fn, ln;
    ifstream ifile4("admin.txt", ios::app);
    while (ifile4 >> a >> b)
    {
        if (reg.getUsername() == a && reg.getPassword() == b)
        {
            cout << "" << endl;
            cout << "*            IRONCLADS ADMINISTRATOR PANEL       *" << endl;
            cout << "" << endl << endl;
            cout << "Welcome, Administrator!" << endl << endl;
            cout << "PLEASE SELECT AN OPTION:" << endl;
            cout << "1- Delete a Member" << endl;
            cout << "2- Update an Instructor" << endl;
            cout << "0- Exit" << endl;

            cin >> choicE;
            system("cls"); // Clear the screen
            switch (choicE)
            {
            case 1:
            {
                cout << "" << endl;
                cout << "*              DELETE A MEMBER                   *" << endl;
                cout << "" << endl << endl;
                cout << "Please enter the first name of the member: ";
                cin >> fn;
                cout << "Last name: ";
                cin >> ln;
                ifstream ifile("DBMS.txt");
                ofstream ofile9("TEMP.txt", ios::app);
                string line;
                while (getline(ifile, line)) {
                    stringstream ss(line);
                    ss >> username >> password >> fname >> lastname >> fathername >> age >> address >> NationalitY >> CNic >> num >> job >> sport >> teacher >> cOst >> TiMe;
                    if (fn != fname && ln != lastname)
                    {
                        ofile9 << username << " " << password << " " << fname << " " << lastname << " " << fathername << " " << age << " " << address << " " << NationalitY << " " << CNic << " " << num << " " << job << " " << sport << " " << teacher << " " << cOst << " " << TiMe << endl;
                    }
                }
                ifile.close();
                ofile9.close();

                if (remove("DBMS.txt") != 0) {
                    cerr << "Error deleting file." << endl;
                    return;
                }
                if (rename("TEMP.txt", "DBMS.txt") != 0) {
                    cerr << "Error renaming file." << endl;
                    return;
                }

                cout << "Member deleted successfully." << endl;
                break;
            }
          
           case 2:
 {
    string newpass, newuser;
    string oldpass, olduser;
    string a, b;
    cout << "" << endl;
    cout << "*            UPDATE INSTRUCTOR LOGIN             *" << endl;
    cout << "" << endl << endl;

    cout << "Enter the old username: ";
    cin >> olduser;
    cout << "Enter the old password: ";
    cin >> oldpass;
    cout << "Enter the new username: ";
    cin >> newuser;
    cout << "Enter the new password: ";
    cin >> newpass;

    // Update usernames in instructors.txt
    ifstream ifile1("instructors.txt");
    ofstream ofile1("tempins.txt", ios::app);
    if (!ofile1 || !ifile1) {
        cout << "ERROR" << endl;
    } else {
        string line;
        while (getline(ifile1, line)) {
            istringstream iss(line);
            iss >> a >> b;
            if (olduser == a && oldpass == b) {
                ofile1 << newuser << " " << newpass << endl;
            } else {
                ofile1 << a << " " << b << endl;
            }
        }
        ifile1.close();
        ofile1.close();

        if (remove("instructors.txt") != 0) {
            cout << "Error deleting file." << endl;
            return;
        }

        if (rename("tempins.txt", "instructors.txt") != 0) {
            cout << "Error renaming file." << endl;
            return;
        }

        cout << "Instructor's username and password updated successfully." << endl;
    }

    // Update usernames in instructors1.txt
    ifstream ifile2("instructors1.txt");
    ofstream ofile2("tempinst1.txt", ios::app);
    if (!ifile2 || !ofile2) {
        cout << "error" << endl;
    } else {
        while (ifile2 >> a) {
            if (olduser == a) {
                ofile2 << newuser << endl;
            } else {
                ofile2 << a << endl;
            }
        }
        ifile2.close();
        ofile2.close();

        if (remove("instructors1.txt") != 0) {
            cout << "Error deleting file." << endl;
            return;
        }

        if (rename("tempinst1.txt", "instructors1.txt") != 0) {
            cout << "Error renaming file." << endl;
            return;
        }

        cout << "Username updated successfully in instructors1.txt." << endl;
    }

    // Update usernames in instructor2.txt
    ifstream ifile3("instructor2.txt");
    ofstream ofile3("tempinstructor2.txt", ios::app);
    if (!ifile3 || !ofile3) {
        cout << "error" << endl;
    } else {
        while (ifile3 >> a) {
            if (olduser == a) {
                ofile3 << newuser << endl;
            } else {
                ofile3 << a << endl;
            }
        }
        ifile3.close();
        ofile3.close();

        if (remove("instructor2.txt") != 0) {
            cout << "Error deleting file." << endl;
            return;
        }

        if (rename("tempinstructor2.txt", "instructor2.txt") != 0) {
            cout << "Error renaming file." << endl;
            return;
        }

        cout << "Username updated successfully in instructor2.txt." << endl;
    }

    // Update username in DBMS.txt
    ifstream ifile4("DBMS.txt");
    ofstream ofile4("tempDBMS.txt", ios::app);
    if (!ifile4 || !ofile4) {
        cout << "ERROR" << endl;
    } else {
        string line;
        while (getline(ifile4, line)) {
            stringstream ss(line);
            string username, password, fname, lastname, fathername, age, address, NationalitY, CNic, num, job, sport, teacher, cOst, TiMe;
            
            // Read all values from the line
            ss >> username >> password >> fname >> lastname >> fathername >> age >> address >> NationalitY >> CNic >> num >> job >> sport >> teacher >> cOst >> TiMe;
            
            // Check if the teacher matches the old username
            if (teacher == olduser) {
                // Update the username with the new one
                teacher = newuser;
            }

            // Write the line with possibly updated username to the temporary file
            ofile4 << username << " " << password << " " << fname << " " << lastname << " " << fathername << " " << age << " " << address << " " << NationalitY << " " << CNic << " " << num << " " << job << " " << sport << " " << teacher << " " << cOst << " " << TiMe << endl;
        }

        ifile4.close();
        ofile4.close();

        // Replace the original file with the temporary file
        if (remove("DBMS.txt") != 0) {
            cout << "Error deleting file." << endl;
            return;
        }

        if (rename("tempDBMS.txt", "DBMS.txt") != 0) {
            cout << "Error renaming file." << endl;
            return;
        }

        cout << "Username updated successfully in DBMS.txt." << endl;
        break;
    }
}
            case 0:
            {
                cout << "Exiting Administrator Panel..." << endl;
                break;
            }
            default:
            {
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
            }
            }
            system("pause"); // Pause screen before returning to main menu
            system("cls");   // Clear the screen
            return;
            break;
        }
    }
}



	};
	
	int main()
	{
		mainmenu();
		return 0;
	}
void mainmenu() {
    menu m1;
    int select;
    do {
        system("cls"); // Clear the screen

        cout << "=============================" << endl;
    cout << "|   WELCOME TO IRONCLADS FITNESS   |" << endl;
    cout << "=============================" << endl;
    cout << "|                               |" << endl;
    cout << "| 1. Register a Single User     |" << endl;
    cout << "| 2. User Login                 |" << endl;
    cout << "| 3. Instructor Login           |" << endl;
    cout << "| 4. Administrator Login        |" << endl;
    cout << "|                               |" << endl;
    cout << "| 0. Exit                       |" << endl;
    cout << "|                               |" << endl;
    cout << "=============================" << endl;
        cout << "Enter your choice: ";
        cin >> select;

        system("cls"); // Clear the screen

        switch (select) {
            case 1: {
                cout << "USER LOGIN" << endl;
                m1.USERLOGIN();
                break;
            }
            case 2: {
                cout << "INSTRUCTOR LOGIN" << endl;
                m1.INSTRUCTORLOGIN();
                break;
            }
            case 3: {
                cout << "USER REGISTRATION" << endl;
                m1.REGISTRATIONSINGLE();
                break;
            }
            case 4: {
                cout << "ADMIN LOGIN" << endl;
                m1.ADMIN();
                break;
            }
            case 0: {
                cout << "Exiting program..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
            }
        }

        // Pause for a moment before clearing the screen
        cout << endl << "Press Enter to continue...";
        cin.ignore();
        cin.get();

    } while (select != 0);
}