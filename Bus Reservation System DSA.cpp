#include <iostream>
using namespace std;

const int NUM_SEATS = 8;

void initseat(char seats[], int size){
    for(int i = 0;i<size;i++){
        seats[i]='O';
    }
}
void display(const char seats[], int size){
    for(int i = 0; i<size;i++){
        cout<<(i+1)<<":"<<seats[i]<<endl;
    }
    cout<<"O = Open and X = Reserved "<<endl;
}

bool reserveseat(char seats[], int size, int seatno)
{
    if(seatno<1 || seatno>size)
    {
        return false;
    }
    int index = seatno -1; //convert to array index
    if(seats[index]=='O'){
        seats[index]='X';
        return true;
    }
    return false;
}

bool cancelseat(char seats[], int size, int seatno)
{
    if(seatno<1 || seatno>size)
    {
        return false;
    }
    int index = seatno-1;
    if(seats[index]=='X'){
        seats[index]='O';
        return true;
    }
    return false;
}

int countavailable(const char seats[], int size)
{
    int opencount = 0;
    for(int i=0; i<size;i++){
        if(seats[i]=='O'){
            opencount++;   
        }
        
    }
    return opencount;
}

int findfirstavailable(const char seats[], int size)
{
    for(int i=0;i<size;i++)
        {
            if(seats[i]=='0'){
                return i+1;
            }
        }
    return -1; //NOT AVAILABLE
}
int main(){
    char busseat[NUM_SEATS];
    initseat(busseat, NUM_SEATS);

    int choice = 0;
    int seatnum=0;
    while(choice !=5){
        cout<<"BUS RESERVATION SYSTEM"<<endl;
        cout<<"1. Display Seat"<<endl;
        cout<<"2. Reserve Seat"<<endl;
        cout<<"3. Cancel Seat"<<endl;
        cout<<"4. Show available number of seats"<<endl;
        cout<<"Enter Your Choice"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                display(busseat, NUM_SEATS);
                break;
            case 2:
                cout<<"Enter seat no to reserve (1 to "<<NUM_SEATS<<"):"<<endl;
                cin>>seatnum;
                if(reserveseat(busseat, NUM_SEATS, seatnum)){
    cout<<"Seat "<<seatnum<<" reserved"<<endl;
}
else{
    cout<<"Invalid seat number or seat already taken"<<endl;
}
break;
            case 3:
                cout<<"Enter seat no to cancel (1 to "<<NUM_SEATS<<"):"<<endl;
                cin>>seatnum;
                if(cancelseat(busseat, NUM_SEATS, seatnum)){
    cout<<"Seat "<<seatnum<<" cancelled"<<endl;
}
else{
    cout<<"Invalid seat number or seat already open"<<endl;
}
break;
             case 4:
                cout<<"Available Seats "<<countavailable(busseat, NUM_SEATS)<<endl;
                break;
             case 5:
                cout<<"Goodbye!"<<endl;
                break;
            default:
                cout<<"INVALID CHOICE TRY AGAIN"<<endl;
                break;        
        }
        
    }
    return 0;
}

