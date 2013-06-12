//Nicolas Silveira Kagami
//Components Source

#include<stdio.h>
#include "components.h"

int passive_cost[NUM_TYPES]={REPEATER_PAS_COST,TRANSITIONAL_PAS_COST,DIODE_PAS_COST,TRANSISTOR_PAS_COST,CAPACITOR_PAS_COST};
int active_cost[NUM_TYPES]={REPEATER_ACT_COST,TRANSITIONAL_ACT_COST,DIODE_ACT_COST,TRANSISTOR_ACT_COST,CAPACITOR_ACT_COST};
int num_interfaces[NUM_TYPES]={REPEATER_NUM_INT,TRANSITIONAL_NUM_INT,DIODE_NUM_INT,TRANSISTOR_NUM_INT,CAPACITOR_NUM_INT};

int Node::num_nodes = 0;
Node * Node:: first = 0;
Node * Node:: last = 0;
Interface::Interface()
{
    next = 0;
}
int Interface::establish(Interface * connectee)
{
    next = connectee;
}
void Interface::exchange()
{
}

void Node::set_next(Node * new_node)
{
    next = new_node;
}
Node::Node(NodeType kind)
{
    if(num_nodes)
    {
        last->set_next(this);
    }
    else
    {
        first = this;
    }
    last = this;
    next = NULL;
    id = num_nodes;
    num_nodes++;
    type = kind;
}
Node * Node::find(int id)
{
    Node * parser;
    for(parser = first; parser; parser = parser->next)
    {
        if(parser->id == id)
            return parser;
    }
    return NULL;
}
void Node::execute()
{ 
    printf("execution");
}
void Node::print_type()
{
    printf("Type: ");
    switch(type)
    {
        case  Repeater:
            printf("Repeater\n");break;
        case  Transitional:
            printf("Transitional\n");break;
        case  Diode:
            printf("Diode\n");break;
        case  Transistor:
            printf("Transistor\n");break;
        case  Capacitor:
            printf("Capacitor\n");break;
        default:
            printf("Unknown Type\n");
    }
}
void Node::print()
{
    printf("Node: %d\n",id);
    print_type();
    printf("Passive Cost: %d\n", passive_cost[type]);
}
void Node::print_all()
{
    Node * parser;
    for(parser = first; parser; parser = parser->next)
    {
        parser->print(); 
    }
}
