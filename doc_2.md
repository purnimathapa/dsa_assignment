Program 2 - Infix to Postfix & Evaluation

In this program, I worked on two main tasks:
1. Converting a regular infix expression like `3+5*2` into postfix format
2. Evaluating the postfix expression to get the result

I used the stack data structure to help with both parts.

---

Functions and Logic:

- For infix to postfix:
  - I check each character from left to right.
  - If it's a number, I add it to the postfix string.
  - If it's an operator (+, -, *, /), I compare its priority with what's on the stack and push/pop accordingly.

- For evaluation:
  - I go through the postfix string.
  - Every time I see a number, I push it into another stack.
  - When I find an operator, I pop the last two numbers, perform the operation, and push the result back.

I kept the code simple and limited it to single-digit numbers only to avoid parsing complexity.

---

Functions I Used:

- `infixToPostfix()` – handles conversion using operator precedence
- `evalPostfix()` – uses a separate stack to calculate final result
- `precedence()` – returns which operator should come first
- `isOperator()` – checks if a character is an operator

---

Sample Output from My Run:

```
Enter an infix expression (only digits and +,-,*,/,(,)) : 3+5*2
Postfix: 352*+
Evaluation Result: 13
```

This confirmed that the program correctly followed BODMAS rules
