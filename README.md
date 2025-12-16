

 *This project has been created as part of the 42 curriculum by nelhansa.*

# push_swap

## Description

**push_swap** is an algorithmic project from the 42 curriculum.  
The goal is to **sort a stack of integers in ascending order using the smallest possible number of operations**, while respecting a strict set of allowed instructions and using only **two stacks: A and B**.

This project focuses on:
- Algorithmic thinking
- Optimization
- Data structures (stacks / linked lists)
- Working under strong constraints

The program outputs a sequence of operations (`sa`, `pb`, `ra`, etc.) that sorts stack **A**.

---

## Instructions

### Compilation

Compile the project using the provided `Makefile`:

```bash
   make
```
### This will generate the executable:

```bash
  ./push_swap
```

### To compile the bonus program (*checker*):

```bash
   make bonus
```

### This will generate:

```sh
  ./checker
```

#   Usage

_*push_swap*_

```bash
  ./push_swap 3 2 1
```

*Output:*

```
    sa
    rra
```

_*checker*_

The checker program reads instructions from standard input:
```
    ./checker 3 2 1
```
_Output:_

- ```OK``` → stack A is sorted and stack B is empty
- ```KO``` → otherwise
- ```Error``` → invalid input or instruction

## Allowed Operations

- sa  sb  ss   → swap operations
- pa  pb       → push operations
- ra  rb  rr   → rotate operations
- rra rrb rrr  → reverse rotate operations

## Resources

- 42 subject PDF: push_swap
- stackoverflow

## AI Usage
*AI tools were used only as an assistance for:*

- Understanding algorithmic concepts
- Reviewing logic and edge cases