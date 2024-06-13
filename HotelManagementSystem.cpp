#include<iostream>
using namespace std;

struct User {
	string name;
	string password;
};

User Info[2] = {{name: "Saad", password: "123"},{name: "Ali", password: "12345"},};

void signUp() {
	string name,password,confirmPassword;
	cout<<"Sign UP"<<endl;
	cout<<"Enter Name: ";
	cin>>name;
	cout<<"Enter Password: ";
	cin>>password;
	cout<<"Enter Confirm Password: ";
	cin>>confirmPassword;
		
	if (password == confirmPassword) {
		cout<<"Signup Successfully!";
		Info[1].name = name;
		Info[1].password = password;
	}
	else {
		cout<<"Password and confirm password does not match.";
		return;
	}
}


int main(){
	
	cout<<"Welcome To Pearl Continential Hotel"<<endl;
	
	int checkAuth = 0;
	bool checkCondition = 0;
	cout<<"Log In / Sign Up"<<endl;
	cout<<"Login press 1"<<endl;
	cout<<"Signup press 2"<<endl;
	cin>>checkAuth;
	if (checkAuth == 1) {
		string name,password;
	    int info_lenght = sizeof(Info) / sizeof(Info[0]);
	    cout<<"Login In"<<endl;
	    cout<<"Enter your name: ";
	    cin>>name;
	    cout<<"Enter your password: ";
	    cin>>password;
	
	    for (int i = 0; i < info_lenght; i++) {
		  if (Info[i].name == name && Info[i].password == password) {
			cout<<"Login Successfully!";
			checkCondition = 0;
	      }
    	}
        cout<<"Invalid credentials";
    	return 0;
	}
	else if (checkAuth == 2) {
		signUp();
		checkCondition = 1;
	}
	else {
		cout<<"Another Number not accepted!"<<endl;
		return 0;
	}
	
	if (checkCondition == 1) {
		cout<<"Signup";
	}
	else {
		cout<<"Signin";
	}
} 
























