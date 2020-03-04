#ifndef STATE_HPP
#define STATE_HPP

#include "Instruction.hpp"

#include <string>
#include <chrono>
#include <map>
#include <thread>

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::_V2::system_clock::time_point time_point;

enum class StateType { Start, 
                     Idle,
                     Busy,
                     Off};
class State {    
  public:
    State(const std::string &stateName):m_stateName(stateName) {}
    virtual void OnEntry(){} 
    virtual void OnExit(){}
    //StateType gettate() const { return m_currentState; }
    std::string getStateName() const { return m_stateName; }
    virtual void transit(Instruction instr) = 0;
    static void reportCurrentState();
    static void dispatchEvent(Instruction instr);
  protected:
    //StateType m_state{StateType::Idle};
    std::string m_stateName;
    static std::shared_ptr<State> m_currentState;
};

class Start : public State {
  public:
    Start():State("Start"){}
    void transit(Instruction instr);
};

class Busy : public State {
  public:
    Busy():State("Busy"){}
    void transit(Instruction instr) override;
    void OnEntry();
    void OnExit();
    static void startTimer();
  private:
    time_point m_beginTime;
    const int64_t m_processingTime{2};
    std::thread m_thread;
};

class Idle : public State {
  public:
    Idle():State("Idle"){}
    void transit(Instruction instr) override;
};

class Off : public State {
  public:
    Off():State("Off"){}
    void transit(Instruction instr) override;
};

#endif