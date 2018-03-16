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

                else if(input_choice == 1)
                {

                        std::string file_name = "";
                        std::string seq_input = "";

                        std::cout << "Provide the Name of the Input File: ";
                        std::cin >> file_name;

                        std::ifstream input_file(file_name);
                        while(std::getline(input_file, seq_input))
                        {

                                // if there are empty lines in the input file
                                if(seq_input == "\n" || seq_input == "\r")
                                {
                                        continue;
                                }

                                delete program->sequence;
                                program->sequence = new std::vector<int>();
                                delete program->original_sequence;
                                program->original_sequence = new std::vector<int>();

                                bool valid_sequence = true;
                                std::string sub = "";

                                for(std::size_t i = 0; i < seq_input.length() ; i++)
                                {

                                        // read the next digit character
                                        if(std::isdigit(seq_input[i]))
                                        {
                                                sub += seq_input[i];
                                        }

                                        // a number has been read for the sequence
                                        else if(seq_input[i] == ' ' && sub != "")
                                        {
                                                program->original_sequence->push_back(std::stoi(sub));
                                                program->sequence->push_back(std::stoi(sub));
                                                sub = "";
                                        }

                                        // an invalid string appears in the file
                                        else if(seq_input[i] != '\n' && seq_input[i] != '\0' && seq_input[i] != '\r')
                                        {
                                                valid_sequence = false;
                                                break;
                                        }
                                }
                                if(valid_sequence && sub != "")
                                {
                                        program->original_sequence->push_back(std::stoi(sub));
                                        program->sequence->push_back(std::stoi(sub));
                                }

                                if(!valid_sequence)
                                {
                                        std::cout << "\n--------------------------------------------------------" << std::endl;
                                        std::cout << "Error: All values in the sequence must be non-negative integers" << std::endl;
                                        std::cout << "--------------------------------------------------------\n" << std::endl;
                                }

                                // this line of input is valid, so the algorithm will run
                                else
                                {
                                        program->quickSort(program->sequence, 0, (program->sequence->size()-1));
                                        program->quickSort(program->original_sequence, 0, (program->original_sequence->size()-1));

                                        std::cout << "\n--------------------------------------------------------" << std::endl;
                                        std::cout << "Original Sequence: " << program->original_sequence->at(0);
                                        for(std::size_t i = 1; i < program->original_sequence->size(); i++)
                                        {
                                                std::cout << " " << program->original_sequence->at(i);
                                        }
                                        std::cout << std::endl;

                                        // check if the degree of the highest-degree vertex is greater than the order of the graph
                                        if( program->original_sequence->at(0) > (int)program->original_sequence->size() )
                                        {
                                                std::cout << "Result: The sequence is not graphical." << std::endl;
                                        }
                                        else
                                        {
                                                bool answer = program->runAlgorithm();
                                                if(answer)
                                                {
                                                        std::cout << "Result: The sequence is graphical.\n" << std::endl;
                                                }
                                                else
                                                {
                                                        std::cout << "Result: The sequence is not graphical." << std::endl;
                                                }
                                        }

                                        std::cout << "--------------------------------------------------------\n" << std::endl;
                                }
                        }

                }

                else if(input_choice == 2)
                {
                        std::cout << "Goodbye." << std::endl;
                        continue_loop = false;
                }
                std::cout << std::endl;

        }



        delete program;
        return(0);

}
