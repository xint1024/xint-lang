#ifndef _TOKEN_H_
#define _TOKEN_H_
#include "string.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


typedef enum { 
    TK_ERROR,
	TK_UNKNOWN,
	TK_EOF,


	//注释
	TK_COMMENT,		

	//数据常量
	TK_NUMBER, 
	TK_CHAR,
	TK_STRING,
	TK_MULT_STRING, 

    //标识符
	TK_ID,

	//分割符号
	TK_COMMA, 		//,
	TK_SEMICON, 		//;
	TK_COLON, 		//:
	TK_L_BRACE, 	//{
	TK_R_BRACE, 	//}
	TK_L_BRACKET, 	// [
	TK_R_BRACKET, 	//]
	TK_L_PAREN, 	//(
	TK_R_PAREN, 	//)
	TK_DOT,			 //.

	//赋值
	TK_ASSIGN,	//=

	//自增自减
	TK_SELF_ADD,	 //++
	TK_SELF_SUB,	//--

	//双目运算
	TK_ADD,	//+
	TK_SUB,	//-
	TK_MUL,	//*
	TK_DIV,	///
	TK_MOD, //%

	//逻辑运算
	TK_LOGIC_AND,  //&&
	TK_LOGIC_OR,   //||
	TK_LOGIC_NOT,  //!

	//位运算
	TK_BIT_AND,        //&
	TK_BIT_OR,         //|
	TK_BIT_XOR,        //^
	TK_BIT_NOT,        //~
	TK_BIT_SHIFT_LEFT, //<<
	TK_BIT_SHIFT_RIGHT, //>>

	//关系运算
	TK_EQ,			//=
	TK_NOT_EQ,		//!=
	TK_GT,			//>
	TK_GT_EQ,		//>=	
	TK_LT,			//<	
	TK_LT_EQ,		//<=
	TK_QUESTION, 	//?


	//关键字常量
    TK_NULL, 	//null
	TK_TRUE,	//true
	TK_FALSE,	//false

	//关键字-语句
	TK_VAR,			//var
	TK_FUNC,		//func
	TK_STRUCT,		//struct
	TK_IF, 			//if
	TK_ELSE,		//else
	TK_WHILE,		//while
	TK_FOR,			//for
	TK_LOOP,		//loop
	TK_BREAK,		//break
	TK_CONTINUE,	//continue
    TK_RETURN,		//return

	//关键字-模块
	TK_THIS,	 //this
	TK_SUPER,	 //super
	TK_MODULE,	 //module
	TK_IMPORT,	 //import
    TK_TRAIT,	 //trait
    TK_IMPL,	 //impl
	
} TokenKind;



typedef enum  { 
	TS_NORMAL,
	TS_ID_KEYWORD,
    TS_NUMBER, 
	TS_CHAR,
	TS_STRING,
    TS_COMMENT
} TokenStatus;


typedef enum {
   VT_UNDEFINED,
   VT_NULL,
   VT_FALSE,
   VT_TRUE,
   VT_NUMBER,
   VT_STRING   
} ValueType;    


/** value **/
typedef struct {
   ValueType type;
   union {
		int intVal;
		double doubleVal;
		char charVal;
		String* strVal;
   };
} Value;

/** token **/
typedef struct Token_{
    int size;
	int lineNo;
    TokenKind kind;
    Value value;
} Token;


typedef enum { 
	TT_SIGN,	 //标记符号
	TT_VALUE,	 //常量值
	TT_ID,		 //ID
	TT_DELIM,	 //界符
	TT_KEYWORD,	 //关键字
} TokeType;


typedef struct TokenTable_ {
	TokenKind kind;
	TokeType type;
	int size;
    char* kindName;
    char* kindWord;
} TokenTable;


char* Token_findKindName(TokenKind kind);
char* Token_findKindWord(TokenKind kind);
TokenKind Token_findKeywordKind(String* str);

#endif