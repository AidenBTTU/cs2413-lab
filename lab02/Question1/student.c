// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

bool isValid(const char* s) {
    if (s == NULL || strlen(s) % 2 != 0) {
        return false;
    }
    int length = strlen(s);
    char stack[length]; // stack is length of string
    int top = -1;

    for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[++top] = s[i];
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (top < 0) return false;
            if ((stack[top] == '(' && s[i] == ')') ||
                (stack[top] == '[' && s[i] == ']') ||
                (stack[top] == '{' && s[i] == '}')) {
                top--;
            }
            else {
                return false;
            }
        }
    }

    return true; // true if stack is empty
}

