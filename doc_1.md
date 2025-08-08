 Balanced Bracket Checker

This program checks if the brackets in an expression are balanced using an array-based stack.

 How it Works

- **push()**: Adds an opening bracket to the stack.
- **pop()**: Removes the most recent opening bracket.
- **isMatchingPair()**: Checks if a pair of brackets match.

Main Steps

1. Go through each character in the input string.
2. Push opening brackets onto the stack.
3. When a closing bracket is found:
    - If the stack is empty, the expression is unbalanced.
    - Otherwise, check if it matches the last opened bracket.
4. After processing, the stack should be empty for the expression to be balanced.

Example Output

```
Expression: a+ (b− c) * (d  
=> Not Balanced

Expression: m+ [a− b * (c+ d * {m)]  
=> Not Balanced

Expression: a+ (b− c)  
=> Balanced

