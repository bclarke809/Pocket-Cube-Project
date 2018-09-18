// Example program
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <fstream>
using namespace std;

long long Array[4000000][25] = {};          //Array to hold all combinations
double prev_count = 0;                      //These are for
double prev_time = 0;                       //statistic purposes

long x = 0;
long Lead = 1;
long interval = 0;

//Each Number 1 - 9 is assigned to a move, which is performed with a series of Array swaps

// Right Clockwise == 1
void RC(long Lead){
    
    swap(Array[Lead][13], Array[Lead][14]);
    swap(Array[Lead][13], Array[Lead][16]);
    swap(Array[Lead][13], Array[Lead][15]);
    swap(Array[Lead][4], Array[Lead][24]);
    swap(Array[Lead][4], Array[Lead][20]);
    swap(Array[Lead][4], Array[Lead][12]);
    swap(Array[Lead][2], Array[Lead][22]);
    swap(Array[Lead][2], Array[Lead][18]);
    swap(Array[Lead][2], Array[Lead][10]);
    
    return;
}

//Right Anticlockwise == 2
void RA(long Lead){
    
    swap(Array[Lead][13], Array[Lead][15]);
    swap(Array[Lead][13], Array[Lead][16]);
    swap(Array[Lead][13], Array[Lead][14]);
    swap(Array[Lead][4], Array[Lead][12]);
    swap(Array[Lead][4], Array[Lead][20]);
    swap(Array[Lead][4], Array[Lead][24]);
    swap(Array[Lead][2], Array[Lead][10]);
    swap(Array[Lead][2], Array[Lead][18]);
    swap(Array[Lead][2], Array[Lead][22]);
    
    return;
}

// Double Right == 3
void RR(long Lead){
    
    swap(Array[Lead][13], Array[Lead][16]);
    swap(Array[Lead][14], Array[Lead][15]);
    swap(Array[Lead][4], Array[Lead][20]);
    swap(Array[Lead][2], Array[Lead][18]);
    swap(Array[Lead][24], Array[Lead][12]);
    swap(Array[Lead][22], Array[Lead][10]);
    
    return;
}

//Up Clockwise == 4
void UC(long Lead){
    
    swap(Array[Lead][3], Array[Lead][1]);
    swap(Array[Lead][3], Array[Lead][2]);
    swap(Array[Lead][3], Array[Lead][4]);
    swap(Array[Lead][9], Array[Lead][5]);
    swap(Array[Lead][9], Array[Lead][24]);
    swap(Array[Lead][9], Array[Lead][13]);
    swap(Array[Lead][10], Array[Lead][6]);
    swap(Array[Lead][10], Array[Lead][23]);
    swap(Array[Lead][10], Array[Lead][14]);
    
    return;
}

//Up Anticlockwise == 5
void UA(long Lead){
    
    swap(Array[Lead][3], Array[Lead][4]);
    swap(Array[Lead][3], Array[Lead][2]);
    swap(Array[Lead][3], Array[Lead][1]);
    swap(Array[Lead][9], Array[Lead][13]);
    swap(Array[Lead][9], Array[Lead][24]);
    swap(Array[Lead][9], Array[Lead][5]);
    swap(Array[Lead][10], Array[Lead][14]);
    swap(Array[Lead][10], Array[Lead][23]);
    swap(Array[Lead][10], Array[Lead][6]);
    
    return;
}

//Double Up == 6
void UU(long Lead){
    
    swap(Array[Lead][3], Array[Lead][2]);
    swap(Array[Lead][1], Array[Lead][4]);
    swap(Array[Lead][10], Array[Lead][23]);
    swap(Array[Lead][9], Array[Lead][24]);
    swap(Array[Lead][6], Array[Lead][14]);
    swap(Array[Lead][5], Array[Lead][13]);
    
    return;
}

//Front Clockwise == 7
void FC(long Lead){
    
    swap(Array[Lead][9], Array[Lead][10]);
    swap(Array[Lead][9], Array[Lead][12]);
    swap(Array[Lead][9], Array[Lead][11]);
    swap(Array[Lead][3], Array[Lead][13]);
    swap(Array[Lead][3], Array[Lead][18]);
    swap(Array[Lead][3], Array[Lead][8]);
    swap(Array[Lead][4], Array[Lead][15]);
    swap(Array[Lead][4], Array[Lead][17]);
    swap(Array[Lead][4], Array[Lead][6]);
    
    return;
}

//Front Anticlockwise == 8
void FA(long Lead){
    
    swap(Array[Lead][9], Array[Lead][11]);
    swap(Array[Lead][9], Array[Lead][12]);
    swap(Array[Lead][9], Array[Lead][10]);
    swap(Array[Lead][3], Array[Lead][8]);
    swap(Array[Lead][3], Array[Lead][18]);
    swap(Array[Lead][3], Array[Lead][13]);
    swap(Array[Lead][4], Array[Lead][6]);
    swap(Array[Lead][4], Array[Lead][17]);
    swap(Array[Lead][4], Array[Lead][15]);
    
    return;
}

//Double Front == 9
void FF(long Lead){
    
    swap(Array[Lead][9], Array[Lead][12]);
    swap(Array[Lead][10], Array[Lead][11]);
    swap(Array[Lead][3], Array[Lead][18]);
    swap(Array[Lead][4], Array[Lead][17]);
    swap(Array[Lead][13], Array[Lead][8]);
    swap(Array[Lead][15], Array[Lead][6]);
    
    return;
}

int main()
{
    //Start the time
    clock_t start;
    double duration;
    start = clock();
    
    //Open textfile for output
    ofstream textfile;
    textfile.open("Pocket Cube Output.txt");
    
    //Create first Lead, or solved state
    int a = 1;
    int b = 4;
    int c = 1;
    Array[0][0] = 0;
    while(a < 25){
        while(a <= b){
            Array[0][a] = c;
            a++;
        }
        b += 4;
        c++;
    }
    
    long long Lead = 1;
    long long count = 0;
    //Here, we create each Lead using set of functions based on specific parameters
    for(long row = 0; row < 3674160; row++)
    {
        for(int i = 1; i < 10; i++)
        {
            Array[Lead][0] = Array[row][0]*10 + i;
            long index = Array[row][0] % 10;
            
            //We don't want to test these because they will always be repetitions, hence a waste of time
            while( ((index == 1 || index == 2 || index == 3)&&(i == 1 || i == 2 || i == 3)) ||
                  ((index == 4 || index == 5 || index == 6)&&(i == 4 || i == 5 || i == 6)) ||
                  ((index == 7 || index == 8 || index == 9)&&(i == 7 || i == 8 || i == 9)) )
            {
                i++;
                Array[Lead][0] = Array[row][0]*10 + i;
            }
            
            //Make new row equal to the branch
            for(long j = 1; j < 25; j++)
            {
                Array[Lead][j] = Array[row][j];
            }
            
            //Change new row by one move from branch state
            if(i == 1)
            {
                RC(Lead);
            }
            else if(i == 2)
            {
                RA(Lead);
            }
            else if(i == 3)
            {
                RR(Lead);
            }
            else if(i == 4)
            {
                UC(Lead);
            }
            else if(i == 5)
            {
                UA(Lead);
            }
            else if(i == 6)
            {
                UU(Lead);
            }
            else if(i == 7)
            {
                FC(Lead);
            }
            else if(i == 8)
            {
                FA(Lead);
            }
            else if(i == 9)
            {
                FF(Lead);
            }
            
            //Check if New row is same as any previous rows
            
            for(long k = 0; k < Lead; k++)
            {
                int check = 0;
                //Compare each part of the array with corresponding part of every previous array
                for(int z = 1; z < 25; z++)
                {
                    //If Two parts are not equal, than whole row is not equal
                    if(Array[Lead][z] != Array[k][z])
                    {
                        check++;
                    }
                    //Break from z loop if Lead and k are not equal
                    if(check > 0)
                    {
                        break;
                    }
                }
                
                //If they are equal, break from k loop and make Lead one less
                if(check == 0)
                {
                    Lead = Lead - 1;
                    break;
                }
            }
            
            Lead++;
        }
        
        //Create variables for the percentage complete and the time taken in secs
        float percentage = (float(row)/3674160)*100;
        duration = clock()/ (double) CLOCKS_PER_SEC;
        
        //Send new row to textfile
        for(long j = 0; j < 25; j++){
            //cout<< Array[row][j] << " ";
            textfile<< Array[row][j] << " ";
        }
        
        //Statistics, including number of rows complete, time taken, rate at which rows are created, ETA and percent complete
        if(duration > interval)
        {
            interval += 5;
            double rate = (count-prev_count)/(duration-prev_time);
            cout << count << "  " << duration << "  secs   rate = " << rate <<
            "  ETA = " << (3674160-count)/rate << " secs  " << percentage << " %" << endl;
            prev_count = count;
            prev_time = duration;
        }
        textfile << endl;
        
        count++;
    }
    cout << count <<endl;
    textfile.close();
    return 0;
}


