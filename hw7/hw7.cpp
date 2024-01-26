//
//  main.cpp
//  hw7
//
//  Created by Patricia Antlitz on 3/31/23.
//
/***********************************************
Author: <Patricia>
Date: <04/01/2023>
Purpose: <use the map function to read a file>
Sources of Help: <https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm https://stackoverflow.com/questions/7648756/is-the-order-of-iterating-through-stdmap-known-and-guaranteed-by-the-standard https://www.educative.io/answers/how-to-sort-a-map-by-value-in-cpp >
***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
*/

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main(int argc, char * argv[])
{
    string readLine;
    int rating;
    int totalRatings;
    
    map<string, int> sumRatings;
    map<string, int> totalReviews;

    ifstream inStream("/Users/patriciaantlitz/Documents/UMASS/SPRING 2023/CSIII/CODE/hw7/hw7/hw7.txt");

    //check if it failed
    if(inStream.fail())
    {
        cerr << "Error, unable to read file" << endl;
        exit(1);
    }
    
    while(inStream >> readLine)
    {
        //read file line by line
        getline(inStream, readLine);
        //initialize total ratings read from the file
        //https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm
        totalRatings = atoi(readLine.c_str());

        while(getline(inStream, readLine))
        {
            string temp = readLine;
            getline(inStream, readLine);
            //first line into int
            rating = atoi(readLine.c_str());

            auto l = sumRatings.find(temp);
            if (l != sumRatings.end())
            {
                rating += sumRatings.find(temp)->second;
                totalReviews[temp] = totalReviews.find(temp)->second + 1;
            }
            else
                totalReviews[temp]++;
            //updated value
            sumRatings[temp] = rating;
        }

        for (auto p = totalReviews.rbegin(); p != totalReviews.rend(); p++)
        {
            cout << p->first << " : " << p->second << " review(s)";
            
            auto l = sumRatings.find(p->first);
            if (l != sumRatings.end())
            {
                int sum = (double)(sumRatings.find(p->first)->second) / (p->second);
                cout << " Average of "<< fixed << setprecision(1) << sum << " / " << 5 << endl;
            }
        }
    }
    
    inStream.close();
    cout << endl;

    return 0;
}
