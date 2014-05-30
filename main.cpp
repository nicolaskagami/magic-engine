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
        if(Node::verify_all() == 0)
        {
            printf("Invalid circuit\n");
            exit(0);
        }
        else
        {
            Node::execute_all(10);
        }
    }
    else
    {
        printf("No input file parameter\n");
    }
} 
