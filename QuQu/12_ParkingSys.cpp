#include <bits/stdc++.h>
using namespace std;

typedef struct ParkingSystem
{
    int big,small,medium;
    int cur_big,cur_small,cur_medium;
    ParkingSystem(int big,int small,int medium) : big(big), medium(medium) , small(small) {};
    bool addCar(int carType){
        if(carType == 1){
            if(cur_big < big){
                cur_big++;
                return true;
            }return false;
        }
        if(carType == 2){
            if(cur_medium < medium){
                cur_medium++;
                return true;
            }return false;
        }
        if(carType == 3){
            if(cur_small < small){
                cur_small++;
                return true;
            }return false;
        }
    }
}Parking;


int main()
{
    
    return	0;
}