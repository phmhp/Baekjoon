#include <iostream>
#include <vector>
using namespace std;

double rankToNum(string rank){
    if (rank == "A+") return 4.5;
    else if (rank == "A0") return 4.0;
    else if (rank == "B+") return 3.5;
    else if (rank == "B0") return 3.0;
    else if (rank == "C+") return 2.5;
    else if (rank == "C0") return 2.0;
    else if (rank == "D+") return 1.5;
    else if (rank == "D0") return 1.0;
    else if (rank == "F") return 0.0;
    
    return 0.0; 
}


int main(){
    //전공 평점 = 전공과목별(학점*과목평점)의 합/학점 총합
    int totalTime = 0; 
    double totalRank = 0.0; 
    double time;           //학점 
    string subject, rank;   //과목명, 과목평점


    for (int i=0; i<20; i++){
        cin >> subject >> time >> rank;     
        if (rank == "P") continue; 
        
        totalTime += time;
        totalRank += time * rankToNum(rank);
    }

    cout << totalRank / totalTime;

}