#include "game.h"

#include <vector>
#include <iostream> 

Cube a = Cube(1);
Cube b = Cube(2);
Cube c = Cube(3);
Cube d = Cube(4);

std::vector<Cube> stack;
stack.push_back(d);
stack.push_back(c);
stack.push_back(b);
stack.push_back(a);

//printing game
std::ostream& operator<<(std::ostream& stream, const Game& game) {
 
 for (int i=0;i<3;i++)
 {
     stream << "Stack[i]" << game.stack[i] << endl;  
 }

return stream;
}


//printing cubes
std::ostream& operator<<(std::ostream stream, const Cube& cube){
    
    stream << cube.length << endl;

    return stream;
}