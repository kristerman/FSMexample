#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <string>
#include <iostream>

enum class InstructionType { Boot,
                    TurnOff,
                    Process,
                    Invalid};

inline std::ostream& operator<<(std::ostream &out, const InstructionType &it)
{
    switch (it)
    {
    case InstructionType::Boot:
        out << "Boot";
        break;
    case InstructionType::TurnOff:
        out << "TurnOff";
        break;
    case InstructionType::Process:
        out << "Process";
        break;
    case InstructionType::Invalid:
        out << "Invalid";
        break;
    }
    return out;
}

class Instruction {
    public:
        Instruction(size_t Instruction_id);
        InstructionType getInstructionType() const;
    private:
        size_t m_Instruction_id;
        InstructionType m_Instruction_type;

};

#endif