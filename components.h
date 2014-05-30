//Nicolas Silveira Kagami
//Components Header

#define NUM_PHASES                  4
#define NUM_TYPES                   6
#define MAX_NODES                   20
#define MAX_CONNECTIONS             5

#define REPEATER_PAS_COST           1
#define TRANSITIONAL_PAS_COST       10
#define DIODE_PAS_COST              10
#define TRANSISTOR_PAS_COST         10
#define CAPACITOR_PAS_COST          10
#define SHIFTER_PAS_COST            10

#define REPEATER_ACT_COST           0
#define TRANSITIONAL_ACT_COST       10
#define DIODE_ACT_COST              10
#define TRANSISTOR_ACT_COST         10
#define CAPACITOR_ACT_COST          10
#define SHIFTER_ACT_COST            10

#define REPEATER_NUM_INT            10
#define TRANSITIONAL_NUM_INT        1
#define DIODE_NUM_INT               2 
#define TRANSISTOR_NUM_INT          3 
#define CAPACITOR_NUM_INT           4
#define SHIFTER_NUM_INT             4

enum NodeType {Repeater,Transitional,Diode,Transistor,Capacitor,Shifter};

// Interfaces:
// Repeater: 0 
//      all =  
// Transitional: 1 next_id next_interface 
//      0 = connection
// Diode: 2 input_nid input_nint output_nid output_nint  
//      0 = input 
//      1 = output
// Transistor: 3  first_nid first_nint second_nid second_nint 
//      0 = first
//      1 = second
//      2 = controller
// Capacitor: 4 first_nid first_nint second_nid second_nint
//      0 = first
//      1 = first controller
//      2 = second
//      3 = second controller
// Shifter: 5 first_nid first_nint second_nid second_nint 
//      0 = first (bothways)
//      1 = second (bothways)


class Wave
{
    public:
        void print();
        int phase[NUM_PHASES];
        int type;
};
class Interface
{
    public:
        Wave input;
        Wave output;
        Interface * next;
        int next_id;
        int next_int;

        Interface();
        int establish();
        void update();
        int verify();
        void print();
};
class Node
{
    public:
        static int num_nodes;
        static Node * first;
        static Node * last;
        static void print_all();
        static Node * find(int);
        static void extract(char*);
        static void connect_all();
        static int verify_all();
        static void execute_all(int rounds);

        int id;
        Node * next;  
        NodeType type;
        int num_active_interfaces;
        Interface connections[MAX_CONNECTIONS];
        int total_active_cost;

        Node();
        Node(NodeType kind);
        void set_next(Node*);
        void connect();
        int verify();
        void print_type();
        void print();
        void execute();
        int add_component(int*, int);
};
