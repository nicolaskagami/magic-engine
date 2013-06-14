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
        IO input;
        input.open_file(argv[1]);
        input.read();
        Node lala ((NodeType)1);
        Node lala2 ((NodeType)2);
        Node lala3 ((NodeType)3);
        Node lala4 ((NodeType)4);
        Node lala5 ((NodeType)0);
        
        Node::print_all();
    }
    else
    {
        printf("No input file parameter\n");
    }
} 

