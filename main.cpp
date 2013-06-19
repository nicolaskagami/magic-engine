//Nicolas Silveira Kagami
//main.c

#include<stdio.h>
#include<stdlib.h>
#include "analysis.h"
#include "io.h"
#include "components.h"

int main(int argc, char** argv)
{
    if(argc == 2)
    {
        Node::extract(argv[1]);
        Node::connect_all();
        Node::print_all();
    }
    else
    {
        printf("No input file parameter\n");
    }
} 
