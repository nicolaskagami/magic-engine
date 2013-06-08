//Nicolas Silveira Kagami
//Components Header

#define NUM_PHASES                  4
#define NUM_TYPES                   5
#define MAX_NODES                   20

#define REPEATER_PAS_COST           10
#define TRANSITIONAL_PAS_COST       10
#define DIODE_PAS_COST              10
#define TRANSISTOR_PAS_COST         10
#define CAPACITOR_PAS_COST          10

#define REPEATER_ACT_COST           10
#define TRANSITIONAL_ACT_COST       10
#define DIODE_ACT_COST              10
#define TRANSISTOR_ACT_COST         10
#define CAPACITOR_ACT_COST          10

#define REPEATER_NUM_INT            10
#define TRANSITIONAL_NUM_INT        1
#define DIODE_NUM_INT               2 
#define TRANSISTOR_NUM_INT          3
#define CAPACITOR_NUM_INT           4

enum NodeType {Repeater,Transitional,Diode,Transistor,Capacitor};
class Wave
{
    public:
        int phase[NUM_PHASES];
        int type;
};
class Interface
{
    public:
        Wave input;
        Wave output;
        int next;
        void exchange();
};
class Node
{
    public:
        static int num_nodes;
        static Node nodes[MAX_NODES];
        int id;
        NodeType type;
        Interface connections[MAX_NODES];
        int total_active_cost;
        Node(NodeType, int *);
        void execute();
};
