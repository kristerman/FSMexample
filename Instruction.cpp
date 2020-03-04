#include "Instruction.hpp"

#include <iostream>
#include <stdlib.h>

Instruction::Instruction(size_t Instruction_id):m_Instruction_id(Instruction_id)
{
    m_Instruction_type = static_cast<InstructionType>(Instruction_id % 4);
    std::cout << m_Instruction_type << std::endl;
}

InstructionType Instruction::getInstructionType() const
{
    return m_Instruction_type;
}