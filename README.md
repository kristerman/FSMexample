# FSMexample
FSM Experimentation

An event thread generates random events every 1 second and the FSM processes them and transitions to the appropriate state

Possible states are: `Start`(Initial State), `Busy`, `Idle`, `Off`
Possible Events (Instructions) are: `Boot`, `Process`, `TurnOff`, `Invalid`

When the system enters the Busy state, any event has no effect until the processing is over where it transiitions to Idle state.
Also when the system is in the Off state the only Instruction that has an effect is `Boot`.
