#include <iostream>
using namespace std;

const int NUM_STUDENTS = 4;
const int NUM_TESTS = 3;
int scores[NUM_STUDENTS][NUM_TESTS];

void read(int scores[][NUM_TESTS],int rows ){
    for(int i=0; i<rows;i++){
        for(int j =0; j< NUM_TESTS; j++){
            cout<<"STUDENT "<<(i+1)<<", TEST "<<(j+1)<<" ";
            cin>>scores[i][j];
        }
        cout<<endl;
    }
}

void display(int scores[][NUM_TESTS], int rows) {
    for (int i = 0; i < rows; i++) {
        cout << "STUDENT " << (i + 1) << " ";
        for (int j = 0; j < NUM_TESTS; j++) {
            cout << scores[i][j] << " ";
        }
        cout << endl;
    }
}
double Average(int scores[][NUM_TESTS], int student){
    if(student <1 || student> NUM_STUDENTS){
        return -1; //invalid
    }
    double sum = 0;
    
        for(int j=0; j<NUM_TESTS; j++){
            sum += scores[student -1][j];
            
        }
    return sum/NUM_TESTS;
    }

int beststd( int scores[][NUM_TESTS], int rows){
    int bestIndex =1;
    double best= Average(scores, 1);
    for(int i =2; i<=rows; i++){
        double avg= Average(scores, i);
        if(avg>best){
            best = avg;
            bestIndex =i;
        }
        
    }
    return bestIndex;
}
int passcount(int scores[][NUM_TESTS], int rows, int PassMark){
    
    int count = 0;
    for(int i =0; i<rows; i++){
        for(int j =0; j<NUM_TESTS;j++){
            if(scores[i][j]>=PassMark){
                count++;
            }
        }
    }
    return count;
}
int main() {
    int scores[NUM_STUDENTS][NUM_TESTS];
    read(scores, NUM_STUDENTS);
    display(scores, NUM_STUDENTS);
    for(int i =0; i<=NUM_STUDENTS; i++){
        cout<<"Average Score of Student "<<(i)<<": "<<Average(scores,i)<<endl;
    }
    cout<<"The best student is Student "<<beststd(scores, NUM_STUDENTS)<<endl;
    cout<<"No. of Students Passed: "<<passcount(scores, NUM_STUDENTS, 60)<<" "<<endl;
}
