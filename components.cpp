//Nicolas Silveira Kagami
//Components Source updated

#include<stdio.h>
#include "components.h"
#include "io.h"

int passive_cost[NUM_TYPES]={REPEATER_PAS_COST,TRANSITIONAL_PAS_COST,DIODE_PAS_COST,TRANSISTOR_PAS_COST,CAPACITOR_PAS_COST,SHIFTER_PAS_COST};
int active_cost[NUM_TYPES]={REPEATER_ACT_COST,TRANSITIONAL_ACT_COST,DIODE_ACT_COST,TRANSISTOR_ACT_COST,CAPACITOR_ACT_COST,SHIFTER_ACT_COST};
int num_interfaces[NUM_TYPES]={REPEATER_NUM_INT,TRANSITIONAL_NUM_INT,DIODE_NUM_INT,TRANSISTOR_NUM_INT,CAPACITOR_NUM_INT,SHIFTER_NUM_INT};

int Node::num_nodes = 0;
Node * Node:: first = 0;
Node * Node:: last = 0;

void Wave::print()
{
    int i;
    printf("Type %d\t", type);
    for(i=0;i<NUM_PHASES;i++)
        printf("%d ",phase[i]);
    printf("\n");
}

Interface::Interface()
{
    next = 0;
    next_id = 0;
    next_int = 0;
}
int Interface::establish()
{
    Node * candidate = Node::find(next_id);
    if(candidate)
    {
        next = &(candidate->connections[next_int]);
        return 1;
    }
    else
    {
        return 0;
    }
}
void Interface::update()
{
    input = next->output;
}
void Interface::print()
{
    //input.print()
    //output.print()
    if(next)
    {
        printf("Connected to %d at %d \n", next_id, next_int);
    }
    else
    {
        printf("Not connected\n");
    }
}
int Interface::verify()
{
    if(next->next == this)
    {
        return 1; 
    }
    else
    {
        //printf("Not verified:%d")
        return 0;
    }
}

void Node::set_next(Node * new_node)
{
    next = new_node;
}
void Node::connect()
{
    int i;
    for(i=0;i<num_active_interfaces;i++)
    {
        connections[i].establish();
    }
}
Node::Node()
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
    num_active_interfaces = 0;
    num_nodes++;
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
    num_active_interfaces = 0;
    num_nodes++;
    type = kind;
    if(type == 1)
    {
        connections[0].input.phase[0] = 1;
    }
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
    int i;
    printf("Execute %d\n", id);
    for(i=0;i<num_active_interfaces;i++)
    {
        printf("Connection %d:\n",i);
        printf("Input\t");
        connections[i].input.print();
        printf("Output\t");
        connections[i].output.print();
        connections[i].update();
    }
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
        case  Shifter:
            printf("Shifter\n");break;
        default:
            printf("Unknown Type\n");
    }
}
void Node::print()
{
    int i;
    printf("Node: %d\n",id);
    print_type();
    printf("Passive Cost: %d\n", passive_cost[type]);
    for(i=0;i<num_active_interfaces;i++) 
    {
        connections[i].print();
    }
}
void Node::print_all()
{
    Node * parser;
    for(parser = first; parser; parser = parser->next)
    {
        parser->print(); 
    }
}
int Node::add_component(int * parameters, int numparam)
{
    switch(parameters[0])
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
        case  Shifter:
            printf("Shifter\n");break;
        default:
            printf("Unknown Type\n");
    }
}
void Node::extract(char * filename)
{
    int i,j;
    IO input;
    input.open_file(filename);
    while(input.read())
    {
        if(input.parameters[0]>=NUM_TYPES)
        {
            printf("Type %d does not exist\n",input.parameters[0]);
            break;
        }
        Node * newnode = new Node((NodeType)input.parameters[0]);
        for(i=1,j=0;(i<input.numparam) && (j<num_interfaces[input.parameters[0]]);i+=2,j++)
        {
            newnode->connections[j].next_id = input.parameters[i];
            newnode->connections[j].next_int = input.parameters[i+1]; 
        }
        newnode->num_active_interfaces = j;
    }
}
void Node::connect_all()
{
    Node * parser;
    for(parser = first; parser; parser = parser->next)
    {
        parser->connect(); 
    }
}
int Node::verify()
{
    int i;
    for(i=0;i<num_active_interfaces;i++)
    {
        if(connections[i].verify() == 0)
        {
            return 0;
        }
    }
    return 1;
}
int Node::verify_all()
{
    Node * parser;
    for(parser = first; parser; parser = parser->next)
    {
        if(parser->verify() == 0)
            return 0; 
    }
    return 1;
}
void Node::execute_all(int rounds)
{
    int i;
    Node * parser;
    for(i=0;i<rounds;i++)
    {
        printf("Round: %d\n",i);
        for(parser = first; parser; parser = parser->next)
        {
            parser->execute(); 
        }
        getchar();
    }
}
