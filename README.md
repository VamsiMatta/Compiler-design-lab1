#  Compiler Design Lab – C Programs

##  Overview

This repository contains C programs that demonstrate different phases of a compiler. Each experiment helps in understanding how source code is processed step-by-step.

---

##  Experiments

### 1. Lexical Analyzer

This program scans the input code and identifies tokens such as keywords, identifiers, numbers, and operators. It is the first phase of a compiler.

### 2. NFA Construction

This program creates a simple Non-Deterministic Finite Automaton (NFA) for a given input symbol. It shows how states and transitions are formed.

### 3. NFA to DFA Conversion

This program converts an NFA into a DFA using subset construction. Each DFA state represents a group of NFA states.

### 4. Removal of Left Recursion

This program removes immediate left recursion from a grammar. It helps in making the grammar suitable for top-down parsing.

### 5. FIRST and FOLLOW

This program calculates FIRST and FOLLOW sets for grammar symbols. These sets are important for building parsing tables.

### 6. Predictive Parsing Table

This program constructs an LL(1) parsing table using grammar rules. It helps in predictive (top-down) parsing.

### 7. Shift Reduce Parser

This program simulates shift and reduce operations using a stack. It checks whether the input string is accepted or rejected.

### 8. LEADING and TRAILING

This program finds leading and trailing symbols of grammar. It is used in operator precedence parsing.

### 9. Closure of LR(0) Items

This program computes the closure of LR(0) items. It is used in constructing LR parsing tables.

### 10. Infix to Postfix Conversion

This program converts infix expressions into postfix form using a stack. It helps in easier expression evaluation.

### 11. Quadruple Generation

This program generates intermediate code in quadruple format. Each instruction contains operator, operands, and result.

### 12. Code Generation

This program converts expressions into simple assembly-like instructions. It represents the final phase of a compiler.

### 13. DAG Representation

This program creates a Directed Acyclic Graph for expressions. It helps in eliminating repeated computations.

### 14. Data Flow Analysis

This program initializes IN and OUT sets for nodes in a control flow graph. It is used to track data movement in programs.

### 15. Stack Implementation

This program implements stack operations like push and pop. Stack is widely used in parsing and expression evaluation.

---

##  Conclusion

These programs provide a clear understanding of different compiler phases. They help in learning how code is analyzed, transformed, and executed.
