#include "Svetofor.h"

#include <iostream>

svetofor_sm::svetofor_sm(std::string fileName)
{
    state = 0;

    state_out = 
    {
        {0, "G  r"},
        {1, "YL r"},
        {2, "YL r"},
        {3, "R  g"},
        {4, "R yl"},
        {5, "R yl"},
        {6, "YL r"}
    };

    std::ifstream tableFile(fileName);
    char transit;
    int i = 0;
    int j = 0;
    while (!tableFile.eof())
    {
        tableFile.get(transit);
        if (transit == ' ')
        {
            j++;
        }
        else if (transit == '\n')
        {
            j = 0;
            i++;
        }
        else if (transit >= '0' && transit <= '9')
        {
            transitionTable[j][i] = int(transit - '0');
        }
    }
}

void svetofor_sm::reset()
{
    state = 0;
}

void svetofor_sm::input(int i)
{   
    state = transitionTable[state][i];
}

std::string svetofor_sm::get_result()
{
    return state_out.at(state);
}

svetofor_sm::~svetofor_sm()
{
}