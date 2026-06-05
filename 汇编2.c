#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 定义关键字
#define KEYWORDS_COUNT 6
const char *keywords[KEYWORDS_COUNT] = {"begin", "end", "if", "then", "while", "do"};

// 定义运算符和分隔符
#define SYMBOLS_COUNT 12
const char *symbols[SYMBOLS_COUNT] = {"+", "-", "*", "/", "<", "<=", "=", "<>", ">=", ">", ":=", ";"};

// 全局变量
#define MAX_SIZE 1000
char input[MAX_SIZE]; // 输入缓冲区
char buffer[MAX_SIZE];
int pos = 0;      // 当前读取位置
int count_statement=0;

// 辅助函数：跳过空白字符
void skip_whitespace() {
    while (isspace(input[pos])) {
        pos++;
    }
}

// 辅助函数：读取一个单词
void read_word(char *word) {
    int i = 0;
    while (isalnum(input[pos]) || input[pos] == '_') {
        word[i++] = input[pos++];
    }
    word[i] = '\0';
}

// 辅助函数：读取一个符号
void read_symbol(char *symbol) {
    symbol[0] = input[pos++];
    symbol[1] = '\0';
}

// 辅助函数：判断是否为关键字
int is_keyword(const char *word) {
    for (int i = 0; i < KEYWORDS_COUNT; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// 辅助函数：判断是否为符号
int is_symbol(const char *symbol) {
     for (int i = 0; i < SYMBOLS_COUNT; i++) {
        if (strcmp(symbol, symbols[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void expression(int indent);

// 语法分析函数：因子
void factor(int indent) {
    skip_whitespace();
    if (isdigit(input[pos])) {
        char num[100];
        int i = 0;
        while (isdigit(input[pos])) {
            num[i++] = input[pos++];
        }
        num[i] = '\0';
        printf("%*s因子: %s\n", indent, "", num);
    } else if (isalpha(input[pos])) {
        char id[100];
        read_word(id);
        printf("%*s因子: %s\n", indent, "", id);
    } else if (input[pos] == '(') {
        printf("%*s因子: (\n", indent, "");
        pos++;
        expression(indent + 4);
        skip_whitespace();
        if (input[pos] == ')') {
            printf("%*s)\n", indent, "");
            pos++;
        } else {
            printf("错误：缺少右括号\n");
        }
    } else {
        printf("错误：无效的因子\n");
    }
}

// 语法分析函数：项
void term(int indent) {
    printf("%*s项:\n", indent, "");
    factor(indent + 4);
    skip_whitespace();
    while (input[pos] == '*' || input[pos] == '/') {
        char op[2];
        read_symbol(op);
        printf("%*s操作符: %s\n", indent + 4, "", op);
        factor(indent + 4);
        skip_whitespace();
    }
}

// 语法分析函数：表达式
void expression(int indent) {
    printf("%*s表达式:\n", indent, "");
    term(indent + 4);
    skip_whitespace();
    while (input[pos] == '+' || input[pos] == '-') {
        char op[2];
        read_symbol(op);
        printf("%*s操作符: %s\n", indent + 4, "", op);
        term(indent + 4);
        skip_whitespace();
    }
}

// 语法分析函数：逻辑运算
void logical_expression(int indent) {
    printf("%*s逻辑运算:\n", indent, "");
    expression(indent + 4);
    skip_whitespace();
    if (input[pos] == '<' || input[pos] == '>' || input[pos] == '=') {
        char op[3];
        if (input[pos + 1] == '=' || input[pos + 1] == '>') {
            op[0] = input[pos++];
            op[1] = input[pos++];
            op[2] = '\0';
        } else if (input[pos] == '<' && input[pos + 1] == '>') {
            op[0] = input[pos++];
            op[1] = input[pos++];
            op[2] = '\0';
        } else {
            op[0] = input[pos++];
            op[1] = '\0';
        }
        printf("%*s逻辑运算符: %s\n", indent + 4, "", op);
        expression(indent + 4);
    } else {
        printf("错误：无效的逻辑运算符\n");
    }
}

void statement(int indent);
// 语法分析函数：赋值语句
void assignment_statement(int indent) {
    printf("%*s赋值语句:\n", indent, "");
    char id[100];
    read_word(id);
    printf("%*s标识符: %s\n", indent + 4, "", id);
    skip_whitespace();
    if (input[pos] == ':' && input[pos + 1] == '=') {
        pos += 2;
        skip_whitespace();
        expression(indent + 4);
    } else {
        printf("错误：缺少赋值符号 :=\n");
    }
}

// 语法分析函数：条件语句
void if_statement(int indent) {
    printf("%*s条件语句:\n", indent, "");
    pos += 2; // 跳过 'if'
    skip_whitespace();
    logical_expression(indent + 4);
    skip_whitespace();
    if (strncmp(&input[pos], "then", 4) == 0) {
        pos += 4;
        skip_whitespace();
        statement(indent + 4);
        skip_whitespace();
        if (strncmp(&input[pos], "end", 3) == 0) {
            pos += 3;
            printf("%*s结束条件语句\n", indent, "");
        } else {
            printf("错误：缺少 end\n");
        }
    } else {
        printf("错误：缺少 then\n");
    }
}

// 语法分析函数：循环语句
void while_statement(int indent) {
    printf("%*s循环语句:\n", indent, "");
    pos += 5; // 跳过 'while'
    skip_whitespace();
    logical_expression(indent + 4);
    skip_whitespace();
    if (strncmp(&input[pos], "do", 2) == 0) {
        pos += 2;
        skip_whitespace();
        statement(indent + 4);
        skip_whitespace();
        if (strncmp(&input[pos], "end", 3) == 0) {
            pos += 3;
            printf("%*s结束循环语句\n", indent, "");
        } else {
            printf("错误：缺少 end\n");
        }
    } else {
        printf("错误：缺少 do\n");
    }
}

// 语法分析函数：语句
void statement(int indent) {
    skip_whitespace();
    if (isalpha(input[pos])) {
        assignment_statement(indent);
    } else if (strncmp(&input[pos], "if", 2) == 0) {
        if_statement(indent);
    } else if (strncmp(&input[pos], "while", 5) == 0) {
        while_statement(indent);
    } else {
        printf("错误：无效的语句\n");
    }
    skip_whitespace();
    if (input[pos] == ';') {
        pos++;
    }
}

// 语法分析函数：语句串
void statement_list(int indent) {
    printf("%*s语句串:\n", indent, "");
    while (input[pos] != '\0' && strncmp(&input[pos], "end", 3) != 0) {
        statement(indent + 4);
        skip_whitespace();
    }
}

// 语法分析函数：程序
void program() {
    printf("程序:\n");
    if (strncmp(&input[pos], "begin", 5) == 0) {
        pos += 5;
        skip_whitespace();
        statement_list(4);
        if (strncmp(&input[pos], "end", 3) == 0) {
            pos += 3;
            printf("结束\n");
        } else {
            printf("错误1-2：缺少 end\n");
        }
    } else {
        printf("错误1-1：缺少 begin\n");
    }
}

// 主函数
int main() {
    while(1){
        if(fgets(buffer, sizeof(buffer), stdin)==NULL)
            break;
        if(strlen(input)+strlen(buffer)<MAX_SIZE){
            strcat(input,buffer);
        }else break; 
}stdin);    
    program();
    return 0;
}