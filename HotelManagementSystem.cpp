#include<iostream>
using namespace std;

struct User {
	string name;
	string password;
	long long phoneNumber;
	string address;
};

User Info[] = {{name: "Saad", password: "123"},{name: "Ali", password: "12345"}};

int main(){
	while (true) {
	cout<<"Welcome To Pearl Continential Hotel"<<endl;
	int checkAuth = 0;
	int checkCondition = 3;
	cout<<"Log In / Sign Up"<<endl;
	cout<<"1. Login"<<endl;
	cout<<"2. Signup"<<endl;
	cout<<"3. Exit"<<endl;
	cin>>checkAuth;
	if (checkAuth == 1) {
	string name, password;
	bool loginSuccess = false; 
	int attempts = 3;
	int info_lenght = sizeof(Info) / sizeof(Info[0]);
	
	while (attempts > 0 && !loginSuccess) {
	    cout<<"Login In"<<endl;
	    cout<<"Enter your name: ";
	    cin>>name;
	    cout<<"Enter your password: ";
	    cin>>password;
	
	    for (int i = 0; i < info_lenght; i++) {
		  if (Info[i].name == name && Info[i].password == password) {
			cout<<"Login Successfully!";
			loginSuccess = true;
            break;
			checkCondition = 0;
	      }
    	}
        if (!loginSuccess) {
            attempts--;
            if (attempts > 0) {
                cout << "Invalid credentials. You have " << attempts << " attempts left." << endl;
            } else {
                cout << "Your ID has been blocked. Please contact support department." << endl;
                continue;
//                return 0;
            }
        }
      }
	}
	else if (checkAuth == 2) {
	string name, password, confirmPassword, address;
	long long phoneNumber;
	cout<<"Sign UP"<<endl;
	cout<<"Enter Name: ";
	cin>>name;
	cout<<"Enter Phone Number: ";
	cin>>phoneNumber;
	cout<<"Enter Address: ";
	cin>>address;
	cout<<"Enter Password: ";
	cin>>password;
	cout<<"Enter Confirm Password: ";
	cin>>confirmPassword;
		
	if (password == confirmPassword) {
		cout<<"Signup Successfully!";
		Info[1].name = name;
		Info[1].phoneNumber = phoneNumber;
		Info[1].address = address;
		Info[1].password = password;
		checkCondition = 1;
	}
	else {
		cout<<"Password and confirm password does not match.";
		continue;
//		return 0;
	}
	}
	else if (checkAuth == 3) {
		cout << "Exiting program." << endl;
        return 0;
	}
	else {
		cout<<"Another Number not accepted!"<<endl;
		continue;
//		return 0;
	}
	
	if (checkCondition == 1) {
		cout<<"Signup";
	}
	else {
		cout<<"Signin";
	}
	}
} 
























