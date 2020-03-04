#include "State.hpp"

std::shared_ptr<State> State::m_currentState = std::make_shared<Start>();

void State::reportCurrentState()
{
    std::cout << "Current State is: " << m_currentState->getStateName() << std::endl;
}

void State::dispatchEvent(Instruction instr)
{
    m_currentState->transit(instr);
}

void Off::transit(Instruction instr) 
{
    if (instr.getInstructionType() == InstructionType::Boot)
        m_currentState = std::make_shared<Start>();;
}

void Start::transit(Instruction instr) 
{
    if (instr.getInstructionType() == InstructionType::TurnOff)
        m_currentState = std::make_shared<Off>();
    else if (instr.getInstructionType() == InstructionType::Process) {
        m_currentState = std::make_shared<Busy>();
        m_currentState->OnEntry();
    }
    else
        m_currentState = std::make_shared<Idle>();
}

void Busy::startTimer()
{
    std::cout << "Began processing..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "End of busy mode" << std::endl;
    m_currentState->OnExit();
}

void Busy::OnEntry()
{
    m_thread = std::thread(Busy::startTimer);
    m_thread.detach();
}

void Busy::OnExit()
{
    std::cout << "Exiting Busy state" << std::endl;
    m_currentState = std::make_shared<Idle>();
}

void Busy::transit(Instruction instr) 
{
    std::cout << "Still Busy" << std::endl;
}

void Idle::transit(Instruction instr) 
{
    if (instr.getInstructionType() == InstructionType::Process) {
        m_currentState = std::make_shared<Busy>();
        m_currentState->OnEntry();
    }
    else if (instr.getInstructionType() == InstructionType::TurnOff)
        m_currentState = std::make_shared<Off>();
}