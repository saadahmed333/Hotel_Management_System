#include<iostream>
#include <ctime>
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
    double pricePerDay;
    bool isBooked;
};

struct Booking {
    int bookingId;
    int roomId;
    double price;
    string persons;
    string name;
    string checkInDate;
    string checkOutDate;
    bool checkedIn;
};

User Info[] = {{name: "Saad", password: "123", 12321, "Aisha Bawani"},{name: "Ali", password: "12345", 12321, "Aisha Bawani"}};
Room RoomInfo[] = {{1, "Standard", 1000.0, false},{2, "Deluxe", 1500.0, false},{3, "Suite", 2000.0, false}};
Booking BookingInfo[] = {{}};

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

void displayRooms() {
  cout << endl;
  int roomInfo_lenght = sizeof(RoomInfo) / sizeof(RoomInfo[0]);
  for (int i = 0; i < roomInfo_lenght; i++) {
    cout << "Room ID: " << RoomInfo[i].roomId << endl;
    cout << "Room Type: " << RoomInfo[i].roomType << endl;
    cout << "Price Per Day: " << RoomInfo[i].pricePerDay << endl;
    if (RoomInfo[i].isBooked == 1) {
    	 cout << "Available: " << "No" << endl << endl;
	} else {
		 cout << "Available: " << "Yes"  << endl << endl;
	}
  }
    cout << endl;
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
            cout << "Name: " << BookingInfo[i].name << endl;
            cout << "Price: " << BookingInfo[i].price << endl;
            cout << "Persons: " << BookingInfo[i].persons << endl;
            if (BookingInfo[i].checkedIn == 1) {
               cout << "Checked In: " << "true" << endl;
			}
			else {
			   cout << "Checked In: " << "false" << endl;
			}
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
		cout << "You have no bookings at the moment." << endl;
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
}

int bookRoom() {
	cout<<"Welcome to Room Booking!";
	cout << endl;
	displayRooms();
	
	while (true) {
	  cout<<"1. To Book a room"<<endl;
	  cout<<"2. To Exit a booking of rooms"<<endl;
	  int book_room_option = 0;
	  cout<<"Press: ";
	  cin>>book_room_option;
	  if (book_room_option == 1) {
	  	cout<<"Room Booking"<<endl;
	  	int bookingId, roomId, days;
	  	double price;
        string name, checkInDate, checkOutDate, persons;
        int roomInfo_lenght = sizeof(RoomInfo) / sizeof(RoomInfo[0]);
        string current = currentDate();
        cout<<"Enter Room Id: ";
        cin>>roomId;
        for (int i = 0; i < roomInfo_lenght; i++) {
        	if (roomId == RoomInfo[i].roomId) {
        		if (RoomInfo[i].isBooked == 1) {
        			cout<< RoomInfo[i].roomType <<" room is already booked"<<endl;
        			cout<<endl;
				} else {
					cout<<"Room Is Available"<<endl;
					cout<<"Enter your name : ";
                    cin>>name;
                    cout<<"How many days will you stay? : ";
                    cin>>days;
                    cout<<"How many persons are with you? : ";
                    cin>>persons;
                    cout<<endl;
                    int bookingInfo_lenght = sizeof(BookingInfo) / sizeof(BookingInfo[0]);
                    BookingInfo[0].bookingId = bookingInfo_lenght;
                    BookingInfo[0].roomId = roomId;
                    BookingInfo[0].price = price * days;
                    BookingInfo[0].persons = persons;
                    BookingInfo[0].name = name;
                    BookingInfo[0].checkInDate = "";
                    BookingInfo[0].checkOutDate = "";
                    BookingInfo[0].checkedIn = false;
                    RoomInfo[i].isBooked = true;
                    cout<<"Room Booked SuccessFully"<<endl;
                    cout<<endl;
					return 1;               
				}
			}
		}
	  }
	  else if (book_room_option == 2) {
	  	return 1;
	  }
	  else {
	  	continue;
	  }
	}
}

int checkIn() {
	cout<<endl;
	cout<<"Check In"<<endl;
	while (true) {
		int bookingId;
        cout << "Enter your Booking ID to check in: ";
        cin >> bookingId;
        bool bookingFound = false;
        int bookingInfo_lenght = sizeof(BookingInfo) / sizeof(BookingInfo[0]);
        string current = currentDate();
        for (int i = 0; i < bookingInfo_lenght; i++) {
           if (BookingInfo[i].bookingId == bookingId) {
            BookingInfo[i].checkedIn = true;
            BookingInfo[i].checkInDate = current;
            bookingFound = true;
            cout << "Check-in successful for Booking ID: " << bookingId << endl;
            return 1;
            break;
        }
    }
      if (!bookingFound) {
        cout << "Invalid Booking ID or already checked in." << endl;
        cout<<endl;
        cout<<"1. To Continue"<<endl;
        cout<<"2. To exit a CheckIn"<<endl;
        int option = 0;
        cout<<"Option : ";
        cin>>option;
        if (option == 1) {
        	continue;
		}
		else if (option == 2) {
			return 1;
		}
		else {
			continue;
		}
      }
   }
}

int checkOut() {
	cout<<endl;
	cout<<"Check Out"<<endl;
	while (true) {
		int bookingId;
        cout << "Enter your Booking ID to check out: ";
        cin >> bookingId;
    
        bool bookingFound = false;
        int bookingInfo_lenght = sizeof(BookingInfo) / sizeof(BookingInfo[0]);
        string current = currentDate();
        for (int i = 0; i < bookingInfo_lenght; i++) {
           if (BookingInfo[i].bookingId == bookingId) {
            BookingInfo[i].checkedIn = false;
            BookingInfo[i].checkOutDate = current;
            bookingFound = true;
            cout << "Check-out successful for Booking ID: " << bookingId << endl;
            return 1;
            break;
        }
    }

      if (!bookingFound) {
        cout << "Invalid Booking ID or already checked out." << endl;
        cout<<endl;
        cout<<"1. To Continue"<<endl;
        cout<<"2. To exit a CheckIn"<<endl;
        int option = 0;
        cout<<"Option : ";
        cin>>option;
        if (option == 1) {
        	continue;
		}
		else if (option == 2) {
			return 1;
		}
		else {
			continue;
		}
      }
   }
}

int main(){
	while (true) {
	cout<<endl;
	cout<<"Welcome To Hotel Management System!"<<endl;
	int checkAuth = 0;
	int checkCondition = 0;
	cout<<"Log In / Sign Up"<<endl;
	cout<<"1. Login"<<endl;
	cout<<"2. Signup"<<endl;
	cout<<"3. Exit"<<endl;
	cout<<"Option: ";
	cin>>checkAuth;
	cout<<endl;
	string name, password;
	bool loginSuccess = false; 
	int attempts = 3;
	int info_lenght = sizeof(Info) / sizeof(Info[0]);
	if (checkAuth == 1) {	
	while (attempts > 0 && !loginSuccess) {
	    cout<<"Login In"<<endl;
	    cout<<"Enter your name: ";
	    cin>>name;
	    cout<<"Enter your password: ";
	    cin>>password;
	
	    for (int i = 0; i < info_lenght; i++) {
		  if (Info[i].name == name && Info[i].password == password) {
			cout<<"Login Successfully!"<<endl;
			cout<<endl;
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
	cout<<"Sign Up"<<endl;
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
		cout<<endl;
		cout <<"Please choose an option:" << endl;
        cout << "1. Book a Room" << endl;
        cout << "2. My Bookings" << endl;
        cout << "3. CheckIn" << endl;
        cout << "4. CheckOut" << endl;
        cout << "5. View Profile" << endl;
        cout << "6. Logout" << endl;
        cout<<"Option: ";
        cin>>option;
        
        if (option == 1) {
        	int roomBooking = bookRoom();
        	if (roomBooking == 1) {
				continue;
			}
		}
		else if (option == 2) {
			int booking = viewBookings();
			if (booking == 1) {
				continue;
			}
		}
		else if (option == 3) {
			int bookingInfo_lenght = sizeof(BookingInfo) / sizeof(BookingInfo[0]);
			if (BookingInfo[0].name != "") {
			   int checkedIn = checkIn();
			   if (checkedIn == 1) {
				continue;
			   }  
			}
			else {
				cout<<"You have not booked any room yet. You need to book a room first before you can check in."<<endl;
				continue;
			}
		}
		else if (option == 4) {
			int bookingInfo_lenght = sizeof(BookingInfo) / sizeof(BookingInfo[0]);
			if (BookingInfo[0].name != "") {
			   int checkedOut = checkOut();
			   if (checkedOut == 1) {
				continue;
			   }  
			}
			else {
				cout<<"You have not booked any room yet."<<endl;
				continue;
			}
		}
		else if (option == 5) {
		  cout<<endl;
	      cout<<"Profile Details!"<<endl;
	      int userinfo_length = sizeof(Info) / sizeof(Info[0]);
	
	      for (int i = 0; i < userinfo_length; i++) {
		     if (Info[i].name == name) {
			   cout<<"Name : "<<Info[i].name<<endl;
			   cout<<"Password : "<<Info[i].password<<endl;
			   cout<<"Phone Number : "<<Info[i].phoneNumber<<endl;
			   cout<<"Address : "<<Info[i].address<<endl;
			   cout<<endl;
	    	}
	     }
		
	    cout<<"1. To Update a profile detail."<<endl;
	    cout<<"2. To exit a profile detail."<<endl;
	    int option = 0;
	    cout<<"Option: ";
	    cin>>option;
	    if (option == 1) {
	    	cout<<endl;
		    cout<<"Update Profile Detail:"<<endl;
		    for (int i = 0; i < userinfo_length; i++) {
	    	if (Info[i].name == name) {
			  string user_name, password, address;
	          long long phoneNumber;
		      cout<<"Enter your name : ";
			  cin>>user_name;
			  cout<<"Enter your password : ";
		  	  cin>>password;
			  cout<<"Enter your phone number : ";
			  cin>>phoneNumber;
			  cout<<"Enter your address : ";
			  cin>>address;
			
			  Info[i].name = user_name;
			  Info[i].password = password;
			  Info[i].phoneNumber = phoneNumber;
			  Info[i].address = address;
			  name = user_name;
			  cout<<"Profile Update Successfully!"<<endl;
		     }
	       }
	       continue;
	     }
	      else {
		     continue;
	     }
		}
		else if (option == 6) {
			cout<<"Logout Successfully!";
			exit;
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




















