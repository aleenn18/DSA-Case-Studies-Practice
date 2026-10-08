#include<iostream>
using namespace std;

const int MIN_YEAR = 2022;
const int MAX_YEAR = 2025;
const int NUM_YEAR = MAX_YEAR-MIN_YEAR +1;

enum Make {FORD, LINCOLN, MERCURY, NUM_MAKES};
enum Color { BLUE, GREEN, RED, GRAY, NUM_COLORS };  

typedef int Inventory[NUM_YEAR][NUM_MAKES][NUM_COLORS];

void initInventory(Inventory inv){
    for(int y=0; y<NUM_YEAR;y++){
        for(int m =0; m<NUM_MAKES; m++){
            for(int c=0;c<NUM_COLORS;c++){
                inv[y][m][c] = 0;
            }
        }
    }
}

bool addcar(Inventory inv, int year, Make make, Color color, int qty){
    if(year < MIN_YEAR || year> MAX_YEAR||qty <=0){
        return false;
    }
    int yearIndex = year- MIN_YEAR;
    inv[yearIndex][make][color] +=qty;
    return true;
}
bool sellcar(Inventory inv, int year, Make make, Color color){
     if(year < MIN_YEAR || year> MAX_YEAR){
        return false;
    }
    int yearIndex = year - MIN_YEAR;
    if(inv[yearIndex][make][color] <=0){
        return false;
    }
    inv[yearIndex][make][color]--; 
    return true; //decrement by 1 means sold
}
int countcar(const Inventory inv, int year, Make make, Color color){
        int count =0;
        if(year < MIN_YEAR || year> MAX_YEAR){
        return -1;
    }
        return inv[year-MIN_YEAR][make][color];
    }
int totalbyMake(const Inventory inv, Make make){
    int total =0;
    for(int y =0; y<NUM_YEAR;y++){
        for(int c=0; c<NUM_COLORS; c++){
            total += inv[y][make][c];
        }
    }
    return total;
}

void print(const Inventory inv){
    for(int y=0; y<NUM_YEAR;y++){
        for(int m =0; m<NUM_MAKES; m++){
            for(int c=0;c<NUM_COLORS;c++){
               int stock = inv[y][m][c];
                if(stock>0){
                    int actualyear = MIN_YEAR +y;
                    cout<<" Year: "<<actualyear<<endl;
                    cout<<"Make: "<<m<<endl;
                    cout<<"Color: "<<c<<endl;
                    cout<<"Stock Available: "<<stock<<endl;
                }
            }
        }
    }
}

void showsize(const Inventory inv){
    cout<<"Elements: "<<NUM_YEAR*NUM_MAKES*NUM_COLORS<<endl;
    cout<<"Bytes: "<<sizeof(Inventory)<<endl;
}
int main()
{
    Inventory inv;
initInventory(inv);
showsize(inv);                              // Elements: 48, Bytes: 192
addcar(inv, 2023, FORD, RED, 3);
addcar(inv, 2024, LINCOLN, BLUE, 2);
addcar(inv, 2023, MERCURY, RED, 4);
cout << addcar(inv, 2030, FORD, RED, 1);    // 0 (false)
sellcar(inv, 2023, FORD, RED);
cout << countcar(inv, 2023, FORD, RED);     // 2
cout << totalbyMake(inv, FORD);             // 2
print(inv);
}
