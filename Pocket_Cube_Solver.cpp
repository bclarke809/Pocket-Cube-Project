//
//  main.cpp
//  Testing
//
//  Created by Brett Clarke on 8/8/18.
//  Copyright © 2018 Brett Clarke. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <istream>
#include <sstream>
using namespace std;

int Array[25];                  //The input Cube arrangement
string New = " ";               //This is a string version of Array for comparison with text file

//Each value 1 - 9 is assigned to a move on the cube

// Right Clockwise == 1
void RC(){
    
    swap(Array[13], Array[14]);
    swap(Array[13], Array[16]);
    swap(Array[13], Array[15]);
    swap(Array[4], Array[24]);
    swap(Array[4], Array[20]);
    swap(Array[4], Array[12]);
    swap(Array[2], Array[22]);
    swap(Array[2], Array[18]);
    swap(Array[2], Array[10]);
    
    return;
}

//Right Anticlockwise == 2
void RA(){
    
    swap(Array[13], Array[15]);
    swap(Array[13], Array[16]);
    swap(Array[13], Array[14]);
    swap(Array[4], Array[12]);
    swap(Array[4], Array[20]);
    swap(Array[4], Array[24]);
    swap(Array[2], Array[10]);
    swap(Array[2], Array[18]);
    swap(Array[2], Array[22]);
    
    return;
}

// Double Right == 3
void RR(){
    
    swap(Array[13], Array[16]);
    swap(Array[14], Array[15]);
    swap(Array[4], Array[20]);
    swap(Array[2], Array[18]);
    swap(Array[24], Array[12]);
    swap(Array[22], Array[10]);
    
    return;
}

//Up Clockwise == 4
void UC(){
    
    swap(Array[3], Array[1]);
    swap(Array[3], Array[2]);
    swap(Array[3], Array[4]);
    swap(Array[9], Array[5]);
    swap(Array[9], Array[24]);
    swap(Array[9], Array[13]);
    swap(Array[10], Array[6]);
    swap(Array[10], Array[23]);
    swap(Array[10], Array[14]);
    
    return;
}

//Up Anticlockwise == 5
void UA(){
    
    swap(Array[3], Array[4]);
    swap(Array[3], Array[2]);
    swap(Array[3], Array[1]);
    swap(Array[9], Array[13]);
    swap(Array[9], Array[24]);
    swap(Array[9], Array[5]);
    swap(Array[10], Array[14]);
    swap(Array[10], Array[23]);
    swap(Array[10], Array[6]);
    
    return;
}

//Double Up == 6
void UU(){
    
    swap(Array[3], Array[2]);
    swap(Array[1], Array[4]);
    swap(Array[10], Array[23]);
    swap(Array[9], Array[24]);
    swap(Array[6], Array[14]);
    swap(Array[5], Array[13]);
    
    return;
}

//Front Clockwise == 7
void FC(){
    
    swap(Array[9], Array[10]);
    swap(Array[9], Array[12]);
    swap(Array[9], Array[11]);
    swap(Array[3], Array[13]);
    swap(Array[3], Array[18]);
    swap(Array[3], Array[8]);
    swap(Array[4], Array[15]);
    swap(Array[4], Array[17]);
    swap(Array[4], Array[6]);
    
    return;
}

//Front Anticlockwise == 8
void FA(){
    
    swap(Array[9], Array[11]);
    swap(Array[9], Array[12]);
    swap(Array[9], Array[10]);
    swap(Array[3], Array[8]);
    swap(Array[3], Array[18]);
    swap(Array[3], Array[13]);
    swap(Array[4], Array[6]);
    swap(Array[4], Array[17]);
    swap(Array[4], Array[15]);
    
    return;
}

//Double Front == 9
void FF(){
    
    swap(Array[9], Array[12]);
    swap(Array[10], Array[11]);
    swap(Array[3], Array[18]);
    swap(Array[4], Array[17]);
    swap(Array[13], Array[8]);
    swap(Array[15], Array[6]);
    
    return;
}


int main(){
    
    //Create first , or solved state
    int a = 1;
    int b = 4;
    int c = 1;
    Array[0] = 0;
    while(a < 25){
        while(a <= b){
            Array[a] = c;
            a++;
        }
        b += 4;
        c++;
    }
    
    // Create set of moves to mix up the cube
    int i = -1;
    cout << "Enter the Moves of Cube as space seperated single digit integers, corresponding to their respective moves. End the string with a zero (0) before pressing 'Enter' \n";
    
    while (i != 0)
    {
        cin >> i;
        
        if(i == 1)
        { RC(); }
        else if(i == 2)
        { RA(); }
        else if(i == 3)
        { RR(); }
        else if(i == 4)
        { UC(); }
        else if(i == 5)
        { UA(); }
        else if(i == 6)
        { UU(); }
        else if(i == 7)
        { FC(); }
        else if(i == 8)
        { FA(); }
        else if(i == 9)
        { FF(); }
        
    }
    
    //Use new Cube arrangement to make string for comparison with text file
    for(int i = 1; i < 25; i++){
        New = New + to_string(Array[i]) + " ";
    }
    
    //Open the text file
    string line;
    string Lead;
    ifstream my_file;
    my_file.open("File_Test.txt");
    
    if(my_file.is_open())
    {
        while(New != line)      //Compare each line with your Cube arrangement until they are equal
        {
            my_file >> line;
            Lead = line;            //This is the Lead number which indicates the moves to solve
            getline(my_file, line);
        }
        
        my_file.close();
        
    }
    else
    {
        cout << "Unable to open file to read \n";
    }

    //Transfer the value of Lead to Moves as an integer
    stringstream Leading_Num(Lead);
    long long Moves = 0;
    Leading_Num >> Moves;
    long long Num = 0;
    
    //Reverse the integers of Move using mod and output the move corresponding to each digit
    while(Moves != 0){
        long long i = Moves%10;
        
        if(i == 1)
        { cout << "RA "; }
        else if(i == 2)
        { cout << "RC "; }
        else if(i == 3)
        { cout << "RR "; }
        else if(i == 4)
        { cout << "UA "; }
        else if(i == 5)
        { cout << "UC "; }
        else if(i == 6)
        { cout << "UU "; }
        else if(i == 7)
        { cout << "FA "; }
        else if(i == 8)
        { cout << "FC "; }
        else if(i == 9)
        { cout << "FF "; }
        
        Moves /= 10;
        Num++;
    }
    
    //Once all moves have been calculated, write how many moves are needed
    if(Moves == 0){
        cout << '\n' << "The Cube will be solved in " << Num << " moves " << '\n';
    }
    
    return 0;
}


// If you have trouble attaching the file with the array, run just this part of the code, to create a text file that will automatically link to the code, then replace the values with the array values from the original file, and take out tthe code. Make sure the name of the file is the same when opening it from the above code.
/*
 int count = 0;
 ofstream myfile;
 myfile.open("File_Test.txt");
 if(myfile.is_open()){
 
 for(int i = 0; i < 5; i++)
 {
 for(int j = 0; j < 5; j++)
 {
 myfile << count << " ";
 count++;
 }
 myfile << '\n';
 }
 myfile.close();
 }
 else
 {
 cout << "Unable to open file \n";
 }
 */

