#include<iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

struct User {
	string name;
	string password;
	long long phoneNumber;
	string address;
};

struct Room {
    int roomId;
    string roomType;
    double pricePerDaye;
    bool isBooked;
};

struct Booking {
    int bookingId;
    int roomId;
    string guestName;
    string checkInDate;
    string checkOutDate;
};

User Info[] = {{name: "Saad", password: "123"},{name: "Ali", password: "12345"}};
Room RoomInfo[] = {{1, "Standard", 1000.0, false},{2, "Deluxe", 1500.0, false},{3, "Suite", 2000.0, false}};
Booking BookingInfo[] = {
    {1, 101, "John Doe", "2024-07-01", "2024-07-05"},
    {2, 102, "Alice Smith", "2024-07-03", "2024-07-08"}
};

string currentDate() {
	time_t now = time(NULL);
    // Convert calendar time to local time
    tm* local_tm = localtime(&now);
    int year = local_tm->tm_year + 1900;  // years since 1900
    int month = local_tm->tm_mon + 1;     // months since January [0-11]
    int day = local_tm->tm_mday;          // day of the month [1-31]
    std::ostringstream currentDateStr;
    currentDateStr << year << "-" << month << "-" << day;
	return currentDateStr.str();
}

int viewBookings() {
	int bookingInfo_lenght = sizeof(BookingInfo) / sizeof(BookingInfo[0]);	
	if (bookingInfo_lenght > 0) {
		 cout<<endl;
		 cout << "Displaying Bookings:" << endl;
		 cout<<endl;
		 for (int i = 0; i < bookingInfo_lenght; i++) {
		 	cout << "Booking ID: " << BookingInfo[i].bookingId << endl;
            cout << "Room ID: " << BookingInfo[i].roomId << endl;
            cout << "Guest Name: " << BookingInfo[i].guestName << endl;
            cout << "Check-in Date: " << BookingInfo[i].checkInDate << endl;
            cout << "Check-out Date: " << BookingInfo[i].checkOutDate << endl << endl;
		 }
		 while (true) {
		 	int booking_exit = 0;
		    cout<<"Press 1 to exit a booking: ";
		    cin>>booking_exit;
		    if (booking_exit == 1) {
		    	return booking_exit;
			}
			else {
				continue;
			}
		 }
	}
	else {
		cout << "You have no bookings." << endl;
	}
}

void bookRoom() {
	cout<<"Book Room!";
}

int main(){
	while (true) {
	cout<<endl;
	cout<<"Welcome To Pearl Continential Hotel"<<endl;
	int checkAuth = 0;
	int checkCondition = 0;
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
			cout<<"Login Successfully!"<<endl;
			loginSuccess = true;
			checkCondition = 1;
            break;
	      }
    	}
        if (!loginSuccess) {
            attempts--;
            if (attempts > 0) {
                cout << "Invalid credentials. You have " << attempts << " attempts left." << endl;
            } else {
                cout << "Your ID has been blocked. Please contact support department." << endl;
                continue;
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
		checkCondition = 1;
		cout<<"Signup Successfully!"<<endl;
		Info[1].name = name;
		Info[1].phoneNumber = phoneNumber;
		Info[1].address = address;
		Info[1].password = password;
//		checkCondition = 1;
	}
	else {
		cout<<"Password and confirm password does not match.";
		continue;
	}
	}
	else if (checkAuth == 3) {
		cout << "Exiting program." << endl;
        return 0;
	}
	else {
		cout<<"Another Number not accepted!"<<endl;
		continue;
	}
	
	if (checkCondition == 1) {
		cout << "Welcome, " << Info[0].name << ". ";
		while (true) {
		int option = 0;
		cout <<"Please choose an option:" << endl;
        cout << "1. Book a Room" << endl;
        cout << "2. View old Bookings" << endl;
        cout << "4. Logout" << endl;
        cout<<"Option: ";
        cin>>option;
        
        if (option == 1) {
        	return 0;
		}
		else if (option == 2) {
			int booking = viewBookings();
			if (booking == 1) {
				continue;
			}
		}
		else {
			cout<<"Another number not supported!";
			continue;
		}
		return 0;
		}
	}
	else {
		cout<<"Authentication Failed!"<<endl;
	}
	}
} 



//		 string current = currentDate();
//		 cout << "Current date: " << current << endl;




















