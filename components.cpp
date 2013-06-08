//Nicolas Silveira Kagami
//Components Source

#include<stdio.h>
#include "components.h"

int passive_cost[NUM_TYPES]={REPEATER_PAS_COST,TRANSITIONAL_PAS_COST,DIODE_PAS_COST,TRANSISTOR_PAS_COST,CAPACITOR_PAS_COST};
int active_cost[NUM_TYPES]={REPEATER_ACT_COST,TRANSITIONAL_ACT_COST,DIODE_ACT_COST,TRANSISTOR_ACT_COST,CAPACITOR_ACT_COST};
int num_interfaces[NUM_TYPES]={REPEATER_NUM_INT,TRANSITIONAL_NUM_INT,DIODE_NUM_INT,TRANSISTOR_NUM_INT,CAPACITOR_NUM_INT};

int Node::num_nodes = 0;
Node Node::nodes[MAX_NODES];
void Interface::exchange()
{
    nodes[next].input = output;  
}
Node::Node(NodeType kind, int * connects)
{
    int i;
    id = num_nodes;
    nodes[num_nodes] = this;
    num_nodes++;
    type = kind;
    for(i=0;i<num_interfaces[type];i++)
    {
        connections[i].next = connects[i];
    }
}
void Node::execute()
{ 
    printf("execution");
}
