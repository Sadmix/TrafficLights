#include <string>
#include <fstream>
#include <map>

class svetofor_sm
{
private:
    int transitionTable[6][8];
    int state;
    std::map<int, std::string> state_out;
public:
    svetofor_sm(std::string fileName);
    void reset();
    void input(int i);
    std::string get_result();
    ~svetofor_sm();
};

