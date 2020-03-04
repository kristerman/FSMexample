#include "Instruction.hpp"
#include "State.hpp"

#include <iostream>
#include <chrono>

using namespace std;
typedef std::chrono::high_resolution_clock Clock;


void event_generation() {
    //State(StateType::Start);
    //auto intstr = Instruction(static_cast<size_t>(0));
    while(true) {
        auto instr = Instruction(static_cast<size_t>(rand()));
        this_thread::sleep_for(chrono::seconds(1));
        State::dispatchEvent(instr);
        State::reportCurrentState();
    }
}

int main() {
    State::reportCurrentState();

    event_generation();

    return 0;
}
