#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Delimiter
bool isSpace(char str)
{
    if (str == ' ' || str == '+' || str == '-' || str == '*' || str == '/' || str == '++' || str == '--' || str == ':=')
        return (true);
    return (false);
}
//returns TRUE if string is a Identifier
bool isIdentifier(char* str)
{
    int i, len = strlen(str);

    if (len == 0)
        return(false);
    else if (len > 0 && len <= 20 && isalpha(str[0]) == true) {
        for (i = 0; i < 20; i++)
            if (isalpha(str[i]) == true || str[i] == '_' || isdigit(str[i]) == true || isSpace(str[0]) == true) {
                return(true);
            }
    }
    else if (len > 20 && isalpha(str[0]) == true) {
        printf("identifier boyutu 20den buyuk olamaz");
    }

}

//returns true if string is a Integer
bool isInteger(char* str)
{
    int i, len = strlen(str);
    if (len == 0)
        return(false);
    else if (len > 0 && len <= 10 && (isdigit(str[0]) == true)) {
        for (i = 0; i < 10; i++)
            if (isdigit(str[i]) == true) {
                return(true);
            }
    }
    else if (len > 10) {
        printf("integer boyutu 10dan buyuk olamaz");
    }
}

//returns true if string is a Operator
bool isOperator(char* str)
{

    if (str == '+' || str == '-' || str == '*' || str == '/' || str == '++' || str == '--' || str == ':=') {
        return(true);
    }
    else {
        return(false);
    }
}

//returns TRUE if character is a Bracket
bool isBracket(char ch) {
    if (ch == '(') {
        ch = "LeftPar";
    }
    if (ch == ')') {
        ch = "RightPar";
    }
    if (ch == '[') {
        ch = "LeftSquareBracket";
    }
    if (ch == ']') {
        ch = "RightSquareBracket";
    }
    if (ch == '{') {
        ch = "LeftCurlyBracket";
    }
    if (ch == '}') {
        ch = "RightCurlyBracket";
    }
}

//returns True if there is a string constant
bool isStringConstant(char* str)
{
    int i, len = strlen(str);
    if (len == 0) {
        return(false);
    }

    if (str[0] == '"') {
        if (str[len - 1] == '"') {
            return(true);
        }
        else
            printf("lexical error");
    }

}

//returns True if string is a Keyword
bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "If") || !strcmp(str, "IF") ||
        !strcmp(str, "else") || !strcmp(str, "Else") || !strcmp(str, "ELSE") ||
        !strcmp(str, "while") || !strcmp(str, "While") || !strcmp(str, "WHILE") ||
        !strcmp(str, "do") || !strcmp(str, "Do") || !strcmp(str, "DO") ||
        !strcmp(str, "break") || !strcmp(str, "Break") || !strcmp(str, "BREAK") ||
        !strcmp(str, "continue") || !strcmp(str, "Continue") || !strcmp(str, "CONTINUE") ||
        !strcmp(str, "int") || !strcmp(str, "Int") || !strcmp(str, "INT") ||
        !strcmp(str, "float") || !strcmp(str, "Float") || !strcmp(str, "FLOAT") ||
        !strcmp(str, "return") || !strcmp(str, "Return") || !strcmp(str, "RETURN") ||
        !strcmp(str, "char") || !strcmp(str, "Char") || !strcmp(str, "CHAR") ||
        !strcmp(str, "case") || !strcmp(str, "Case") || !strcmp(str, "CASE") ||
        !strcmp(str, "long") || !strcmp(str, "Long") || !strcmp(str, "LONG") ||
        !strcmp(str, "static") || !strcmp(str, "Static") || !strcmp(str, "STATIC") ||
        !strcmp(str, "goto") || !strcmp(str, "Goto") || !strcmp(str, "GOTO") ||
        !strcmp(str, "const") || !strcmp(str, "Const") || !strcmp(str, "CONST") ||
        !strcmp(str, "enum") || !strcmp(str, "Enum") || !strcmp(str, "ENUM") ||
        !strcmp(str, "for") || !strcmp(str, "For") || !strcmp(str, "FOR") ||
        !strcmp(str, "record") || !strcmp(str, "Record") || !strcmp(str, "RECORD"))
        return (true);
    return (false);
}

//returns ture if end of line
bool isEndOfLine(char* str) {
    if (str == '\n') {
        return(true);
    }

}


// returns ture if string is a comment
bool isComment(char* str)
{
    int i, len = strlen(str);

    if (len == 0) {
        return false;
    }

    if (str[0] == '(' && str[1] == '*') {
        if (str[len - 1] == ')' && str[len-2] == '*') {
            return(true);
        }
        else {
            return(false);
        }
    }
}


// Extracts the SUBSTRING.

char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(
        sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}



/*void parse(char* str, FILE*dosya)
{
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right) {
        if (isSpace(str[right]) == false)
            right++;

        if (isSpace(str[right]) == true && left == right) {
            if (isOperator(str[right]) == true)
                fputc("Operator(", dosya);
            fputc(str, dosya);
            fputc(")\n", dosya);

            right++;
            left = right;
        }
        else if (isSpace(str[right]) == true && left != right
            || (right == len && left != right)) {
            char* subStr = subString(str, left, right - 1);
            if (isKeyword(str) == true) {
                fprintf("Keyword(", dosya);
                fprintf(str, dosya);
                fprintf(")\n", dosya);
            }
            if (isInteger(str) == true) {
                fprintf("Integer(", dosya);
                fprintf(str, dosya);
                fprintf(")\n", dosya);
            }
            if (isIdentifier(str) == true) {
                fprintf("Identifier(", dosya);
                fprintf(str, dosya);
                fprintf(")\n", dosya);
            }
            if (isOperator(str) == true) {
                fprintf("Operator(", dosya);
                fprintf(str, dosya);
                fprintf(")\n", dosya);
            }
            if (isIdentifier(str) == true) {
                fprintf("Identifier(", dosya);
                fprintf(str, dosya);
                fprintf(")\n", dosya);
            }
            if (isBracket(str) == true) {
                fprintf("Bracket(", dosya);
                fprintf(str, dosya);
                fprintf(")\n", dosya);
            }

            if (isComment(str) == true) {
                continue;
            }

            if (isEndOfLine(str) == true) {
                fputc("EndOfLine", dosya);
            }
            right++;
            left = right;
        }
        return;
    }
}*/


int main()
{
    char c;
    FILE* dosya;
    dosya = fopen("code.lex", "w");
    FILE* dosya1;
    dosya1 = fopen("code.psi", "r");
    if (dosya1  == NULL)
        printf("Dosya okumada hata var");
    else{
        dosya1 = fopen("code.psi", "r");

    while (!feof(dosya1)) {
        c = fgetc(dosya1);
        if (isKeyword(c) == true) {
            fprintf("Keyword(", dosya);
            fprintf(c, dosya);
            fprintf(")\n", dosya);
        }
        if (isInteger(c) == true) {
            fprintf("Integer(", dosya);
            fprintf(c, dosya);
            fprintf(")\n", dosya);
            }
        if (isIdentifier(c) == true) {
            fprintf("Identifier(", dosya);
            fprintf(c, dosya);
            fprintf(")\n", dosya);
            }
        if (isOperator(c) == true) {
            fprintf("Operator(", dosya);
            fprintf(c, dosya);
            fprintf(")\n", dosya);
            }
        if (isIdentifier(c) == true) {
            fprintf("Identifier(", dosya);
            fprintf(c, dosya);
            fprintf(")\n", dosya);
            }
        if (isBracket(c) == true) {
            fprintf("Bracket(", dosya);
            fprintf(c, dosya);
            fprintf(")\n", dosya);
            }

        if (isComment(c) == true) {
            continue;
            }

        if (isEndOfLine(c) == true) {
            fputc("EndOfLine", dosya);
            }



    }
    fclose(dosya1);
    fclose(dosya);
    return (0);
}
}
