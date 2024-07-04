
# CISC Instruction Set Simulator

## Introduction
Welcome to the CISC Instruction Set Simulator project, part of the IT Marathon, AMD 2024. This project aims to emulate a simple CISC instruction set on a CPU simulator. The simulator will read, decode, and execute instructions, providing a clear and informative output to help users understand the behavior of the program.

## Main Blocks and Basic Operation
A processor, or CPU, is the primary component of a computing system responsible for executing programs and operating the computer's hardware. It fetches instructions from memory, decodes them, and executes them in sequence. The performance of a processor is typically measured in instructions per clock cycle (IPC).

### CPU Components:
- **Fetch (Instruction Cache):** Fetches the instruction bytes from memory.
- **Decode:** Decodes the instruction to determine what operation to perform.
- **Execute:** Performs the specified operation.
- **Load/Store (Data Cache):** Loads data from or stores data to memory.
- **Memory:** Interacts with the CPU to read and write data.

## Instruction Flow
The flow of an instruction on a CPU typically involves several steps:
1. **Fetch:** Retrieves the instruction bytes from memory.
2. **Decode:** Determines the operation and operands.
3. **Execute:** Performs the specified operation.
4. **Load or Store:** Loads or stores data to/from memory.
5. **Increment Program Counter:** Moves to the next instruction.

## Task Description
Write a C++ program to emulate the CISC instruction set. The program will:
- Read instructions in hexadecimal format.
- Decode each instruction into its opcode and operands.
- Simulate the execution using registers and memory locations.
- Output the result of each instruction.

The software architecture must include OOP constraints, encapsulating functionalities within well-defined interfaces.

## Scores and Features
### Basic Implementation:
- Abstract CPU and Memory at the same level.
- Parallelize Fetch/Decode/Execute/Load/Store threads.
- Implement timing constraints and observe clock cycles.
- Implement Instruction Cache, Decode, Execute, and Load/Store functionalities.

### Advanced Features:
- Implement cache for fetch windows.
- Speculative fetch and decode capabilities.
- Multiple ALUs for parallel execution.
- Handle exceptions and interrupts.
- Implement SIMD extensions and branch prediction unit.

## CPU Modelling Details
The CPU consists of four main blocks:
1. **Instruction Fetch (IC):** Fetches the next instruction from memory.
2. **Instruction Decode (DE):** Decodes the instruction and prepares control signals.
3. **Execute (EX):** Performs the operation specified by the instruction.
4. **Load/Store (LS):** Manages data loading from and storing to memory.

### Object-Oriented Design
- **CPU Class:** Main orchestrator, instantiates other unit classes.
- **Instruction Fetch Class:** Handles fetching instructions.
- **Instruction Decode Class:** Decodes instructions.
- **Execute Class:** Executes decoded instructions.
- **Load/Store Class:** Manages memory operations.
- **Memory Class:** Provides data from memory based on address input.

### UML Diagram
A UML diagram represents the relationships between these classes, ensuring encapsulation and communication through well-defined interfaces.

## Registers Definition
### Internal Registers:
- **R0, R1, ..., R7:** General-purpose registers.
- **IP:** Instruction pointer.
- **FLAGS:** State register indicating zero, equality, and greater comparisons.

### Config Registers:
- **Stack_base:** Sets the address for the stack base.
- **SP:** Stack pointer.

All registers are 16 bits wide, and the stack is used for storing execution states and subroutine information.

## Instruction Set
### Opcode and Mnemonics
The instruction set includes various operations such as addition, subtraction, multiplication, division, comparison, jumps, calls, returns, and stack operations. Each instruction is defined with its opcode, mnemonic, and detailed behavior.

## Additional Instruction Details
- **POP Instruction:** Pops the top value from the stack into the destination register, adjusting the stack pointer accordingly.
- **Instruction Encoding:** Instructions have variable sizes (16 to 48 bits) and include opcodes, source, and destination parameters. The format and encoding allow for flexible instruction lengths.

## Memory Constraints
- **Address Size:** 16 bits
- **Data Size:** 16 bits
- **Fetch Window:** 4 words (64 bits)
- **Instruction Length:** 16-48 bits
- **Alignment:** Only even addresses are used.

## Exceptions Handling
The simulator includes advanced exception handling for conditions like divide by zero, invalid decode, misaligned access, and stack overflow. Exception handlers save CPU state and manage the control flow during exceptions.

## Interrupts
The CPU handles different types of interrupts, including external interrupts (INT, NMI) and special instruction interrupts (BREAK). Handlers for these interrupts manage the CPU state and ensure proper execution flow.

## SIMD Extension
Support for SIMD (Single Instruction, Multiple Data) operations is provided, allowing operations on multiple sets of data simultaneously. New registers and instructions are introduced to handle these operations.

## Parsing Input Files
The simulator parses input files to load instructions and data into memory, following specific syntax for defining program sections, labels, and comments.

## Clock Cycle Timings
The simulator models clock cycles for different units (IC, DE, EX, LS) and considers timing constraints for speculative execution and cache accesses.

## Pipeline and Parallelism
Examples demonstrate how instructions are processed in a pipeline and parallel fashion, highlighting the efficiency gains from these techniques.

## Using the Provided Model
A pre-built CPU model is provided for simulation. Users can download and run this model with specific memory and interrupt files.

## Assembler Usage
An assembler is included for ease of testing, allowing users to convert assembly code into machine code. The assembler supports defining program sections, labels, and generating output files for the simulator.

### Example Program
An example program is provided, illustrating the use of different instructions and program structure. This example helps users understand how to write and run programs using the simulator.

```assembly
.boot
    jmp main ; this jumps to a label in code

.code
main: ; the JMP instruction above should take us here
    mov r0, 0
    mov r1, 50

loop: ; this loop will run
    add r0, 1
    sub r1, 2
    cmp r0, r1
    jl loop

    ; this will move the value 0xC001 to the "status" location in memory
    mov [status], 0xC001
    end_sim

.data ; this is where we can define data to be used by the program
status:
    dw 0x0000 ; this defines a 16-bit word in memory with the value 0
```

By running the assembler on the program written above, the following memory file is generated:

```
#fff0 ; next data has the address of fff0
lC20  ; address fff0 : 000111 00001 00000 : JMP IMM NULL
0010  ; address fff2 : src2=10 represents immediate value
ffff  ; address fff4 : src1=ffff because this is a jump and the parameters have been identified
```

## Example of Parsing Input File
The following is an example of parsing an input file for the simulator:

```
#fff0 -> next data has the address of fff0
lC20 -> address fff0 : 000111 00001 00000 : JMP IMM NULL
0010 -> address fff2 : src2=10 represents immediate value
ffff -> address fff4 : src1=ffff because this is a jump and the parameters have been identified
```

## Clock Cycle Timings
The simulator also includes detailed modeling of clock cycle timings for different units:

- **IC (Instruction Cache):** 3 cycles
- **IC Speculative:** 2 cycles
- **IC Reading from Cache:** 4 cycles
- **DE (Decode):** 5 cycles
- **DE Speculative:** 2 cycles
- **EX (Execute):** 5 cycles
- **LS (Load/Store):** 5 cycles

## Example of Pipeline/Parallelism
Here is an example showing the behavior of pipeline and parallelism in the simulator:

### Simple Instruction (No Memory Operation)
```
Cycle:    1   2   3   4   5   6
Pipe:    IC  DE  EX
```

### Instruction with Memory Operation
```
Cycle:    1   2   ... 15  16  17  18  19  20
Pipe:    LS   IC
Cycle:   21  22  23  24  25  26  27  41
Pipe:    EX
```

### Parallel/Pipeline Execution
```
Cycle:   1  2  3  4  5  6  7  8  9 10
Inst1:  IC DE EX
Inst2:      IC DE EX
Inst3:          IC DE EX
```

## Conclusion
This README.md provides a comprehensive overview of the CISC Instruction Set Simulator project, including its objectives, components, implementation details, and features. It serves as a guide for understanding and contributing to the project.
