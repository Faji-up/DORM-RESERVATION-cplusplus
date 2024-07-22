
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

struct Reservation{
    string name;
    string contactNo,email;
    int fourperson;
    bool hasNoPerson;
};

class Room{

public:
    int numberOfPersons;
    Room(int numberOfPersons): numberOfPersons(numberOfPersons){}

    bool isAvailable(){
        if(numberOfPersons > 0){
            return true;
        }else{
            return false;
        }
    }
    bool isFourPersons(){

        if(numberOfPersons == 1){
            return false;
        }else{
            return true;
        }
    }

};
void display_info(){
    cout << "------------- Welcome to KBH Apartment -------------\n" << endl;
    cout << "Landlady Personal Information\n";
    cout << "Name : Lovely Garcia \n";
    cout << "Contact No. 0923-465-2112";
    cout << "Location: GCH, ST.Earth, Alangilan Batangas City\n";
    cout << "\n-------------------------\n";

}

void display_available_rooms(Room rooms[2][3],bool isFour){
    cout << "\n";
    cout << "Available Rooms:\n";
    for(int row = 0 ; row < 2 ; row++){
        cout << "Floor : " << (row+1);
        cout << "\n";
        for(int col = 0 ; col < 3 ; col++){
            if(isFour == rooms[row][col].isFourPersons()){
                cout << "["<<(col+1)<<"] " << "Room "<< (col+1) << endl;
            }

        }
        cout << "\n\n";
    }
    cout << "\n-------------------------\n";
}

int main() {
    //----------------------------------------------------------------- Create an array of Rooms

    Room rooms[2][3] = {{Room(1),Room(4),Room(1)},
                        {Room(1),Room(4),Room(4)}};

    //-----------------------------------------------------------------

    bool hasFourPerson;

    //-----------------------------------------------------------------

    display_info();
    cout << "\n\n";

    //-----------------------------------------------------------------

    Reservation reservation;
    cout << "------------- Information of the Guest -------------\n";
    cout << "Enter Your Name: ";
    getline(cin,reservation.name);
    cout << "Email: ";
    getline(cin,reservation.email);
    cout << "Contact Number: ";
    cin >> reservation.contactNo;
    cout << "\n";

    //-----------------------------------------------------------------


    cout << "Do you want a Roommate? [0:NO][1:YES] :";
    cin >> hasFourPerson;
    cout << "\n-------------------------\n";
    cout << (hasFourPerson ? "One room you have four roommates\n"  : "In one room you have no roommate\n");
    cout << "Apartment Payment:\n";
    cout << "Deposite: " <<(hasFourPerson ? 5000 : 7000);
    cout << "\nMonthly: " <<(hasFourPerson ? 2800 : 3000 );
    cout << "\n\n-------------------------\n";

    //-----------------------------------------------------------------

    cout << "Welcome To Book Reservation of KBH Apartment" << endl;
    display_available_rooms(rooms,hasFourPerson);

    int floor;
    int room;
    cout << "Choose your floor: ";
    cin >> floor;
    cout << "Choose your room: ";
    cin >> room;
    Room myRoom = rooms[floor-1][room-1];
    cout << "\n\n"<<endl;
    cout << reservation.name << " Your Selected room is : * " << "Floor " << floor << ", Room "<< room << " * for your reservation\n\n";
    //-----------------------------------------------------------------

    char confirmation;

    cout << "Would you like to confirm your reservation? (y/n): ";
    cin >> confirmation;
    bool choice = confirmation  == 'y' || confirmation  == 'y' ? 1 : 0;
    cout << "\n\n";
    if(choice){
        cout << "Your Reservation for * " << "Floor " << floor << ", Room "<< room << " * has been approved\n\n";
    }else{
        cout << "Your Reservation for * " << "Floor " << floor << ", Room "<< room << " * has been cancelleed.\n\n";
    }
    cout << "\n\n";
    cout << "THANK YOU FOR CHOOSING KBH APARTMENT";

    //-----------------------------------------------------------------
    return 0;

}


