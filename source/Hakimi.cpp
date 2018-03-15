/**
*	FileName: Hakimi.cpp
*	Author: James Muoghalu (j286m692@ku.edu)
*	Date: 3/11/18
*	Description: implementation file for Hakimi class
*/

#include "Hakimi.h"
#define PDEBUG 1 // set to 0 or 1
/*
        #if PDEBUG == 1
        #endif
*/
Hakimi::Hakimi()
{
        this->sequence = nullptr;
}


Hakimi::~Hakimi()
{
        delete this->sequence;
}


bool Hakimi::readInput(int input_choice)
{
        bool ret = true;
        std::string file_name = "";
        std::string seq_input = "";
        bool valid_sequence = true;

        delete this->sequence;
        this->sequence = new std::vector<int>();

        std::cout << "Provide the Name of the Input File: ";
        std::cin >> file_name;

        std::ifstream input_file(file_name);
        while(input_file >> seq_input)
        {
                for(std::size_t i = 0; i < seq_input.length() ; i++)
                {
                        if(!std::isdigit(seq_input[i]))
                        {
                                valid_sequence = false;
                                break;
                        }
                }
                if(!valid_sequence)
                {
                        std::cout << "Error: All values in the file must be non-negative integers" << std::endl;
                        delete this->sequence;
                        this->sequence = new std::vector<int>();
                        break;
                }
                else
                {
                        this->sequence->push_back(std::stoi(seq_input));
                }
        }

        if(valid_sequence)
        {
                sortSequence(this->sequence);
                #if (PDEBUG == 1)
                        std::cout << "Sequence: " << this->sequence->at(0);
                        for(std::size_t i = 1; i < this->sequence->size(); i++)
                        {
                                std::cout << " " << this->sequence->at(i);
                        }
                        std::cout << std::endl;
                #endif
        }
        else
        {
                return false;
        }

        return ret;
}

bool Hakimi::runAlgorithm()
{
        bool answer = true;

        bool end = false;
        int current_index = 0;

        while(!end)
        {
                int first = this->sequence->at(0);
                std::vector<int>* next_iteration = new std::vector<int>();

                #if (PDEBUG == 1)
                        std::cout << "\nSequence: " << this->sequence->at(0);
                        for(std::size_t i = 1; i < this->sequence->size(); i++)
                        {
                                std::cout << " " << this->sequence->at(i);
                        }
                        std::cout << std::endl;
                #endif

                std::size_t i = 1;
                for(; i <= (std::size_t) first; i++)
                {
                        next_iteration->push_back((this->sequence->at(i))-1);
                }
                for(std::size_t j = i; j < this->sequence->size(); j++)
                {
                        next_iteration->push_back(this->sequence->at(j));
                }

                #if (PDEBUG == 1)
                        std::string s = " ";
                        for(int j = 1; j <= current_index+1; j++) { s += " "; }
                        std::cout << "    Next: " << s << next_iteration->at(0);
                        for(std::size_t j = 1; j < next_iteration->size(); j++)
                        {
                                std::cout << " " << next_iteration->at(j);
                        }
                        std::cout << "\n" << std::endl;
                #endif

                sortSequence(next_iteration);


                bool found_non_zero = false;
                for(std::size_t k = 0; k < next_iteration->size(); k++)
                {
                        if(next_iteration->at(k) > 0)
                        {
                                found_non_zero = true;
                                break;
                        }
                }
                if(found_non_zero) // continue to the next iteration of the while loop
                {
                        delete this->sequence;
                        this->sequence = next_iteration;
                }

                else // else, ignore the new reduction and determine if this->sequence is graphical
                {
                        end = true;
                        delete next_iteration;
                }
        }

        if(this->sequence->at(0) >= (int) this->sequence->size())
        {
                return false;
        }

        int sum = 0;
        for(std::size_t i = 0; i < this->sequence->size(); i++)
        {
                sum +=  this->sequence->at(i);
        }
        if(sum % 2)
        {
                return false;
        }
        else
        {
                return true;
        }


        return answer;
}

// using selection sort
void Hakimi::sortSequence(std::vector<int>* seq_to_sort)
{
        int largest = 0;
        int largest_index = 0;
        for(std::size_t i = 0; i < seq_to_sort->size()-1; i++)
        {
                largest = seq_to_sort->at(i);
                largest_index = i;
                for(std::size_t j = i+1; j < seq_to_sort->size(); j++)
                {
                        if(seq_to_sort->at(j) > largest)
                        {
                                largest = seq_to_sort->at(j);
                                largest_index = j;
                        }
                }
                int temp = seq_to_sort->at(i);
                seq_to_sort->at(i) = largest;
                seq_to_sort->at(largest_index) = temp;
        }
}
