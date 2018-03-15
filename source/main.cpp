/**
*	FileName: main.cpp
*	Author: James Muoghalu (j286m692@ku.edu)
*	Date: 3/11/18
*	Description: driver file for program
*/
#include <string>
#include <iostream>
#include <fstream>
#include "Hakimi.h"


int main(int argc, char** argv)
{

        Hakimi* program = new Hakimi();

        bool continue_loop = true;
        int input_choice = 0;
        while(continue_loop)
        {

                std::cout << "\n.....................................................\n"
                << "Pick One of the Following Options for Running Hakimi-Havel's Algorithm:"
                << "\n1) Read from a Text File"
                << "\n2) Exit Program"
                << "\nYour Choice (1 or 2): ";
                std::cin >> input_choice;

                std::cout << std::endl;
                if(input_choice < 1 || input_choice > 2)
                {
                        std::cout << "Invalid Input" << std::endl;
                }

                else if(input_choice == 2)
                {
                        std::cout << "Goodbye." << std::endl;
                        continue_loop = false;
                }

                else
                {
                        bool valid = program->readInput(input_choice);
                        if(valid)
                        {
                                bool answer = program->runAlgorithm();
                                if(answer)
                                {
                                        std::cout << "The sequence is graphical." << std::endl;
                                }
                                else
                                {
                                        std::cout << "The sequence is not graphical." << std::endl;
                                }
                        }
                        else
                        {

                        }
                }

                std::cout << std::endl;

        }



        delete program;
        return(0);

}
