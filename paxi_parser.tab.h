/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PAXI_PARSER_TAB_H_INCLUDED
# define YY_YY_PAXI_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID_TOKEN = 258,
    INT_TOKEN = 259,
    STRING_TOKEN = 260,
    CHAR_TOKEN = 261,
    NEWLINE_TOKEN = 262,
    WHITESPACE_TOKEN = 263,
    AND_TOKEN = 264,
    ARRAY_TOKEN = 265,
    DO_TOKEN = 266,
    ELSE_TOKEN = 267,
    ENDO_TOKEN = 268,
    ENDIF_TOKEN = 269,
    ENDPROC_TOKEN = 270,
    ENDWHILE_TOKEN = 271,
    IF_TOKEN = 272,
    LINE_TOKEN = 273,
    NOT_TOKEN = 274,
    OR_TOKEN = 275,
    PROC_TOKEN = 276,
    READ_TOKEN = 277,
    READSTR_TOKEN = 278,
    RETVAL_TOKEN = 279,
    VAR_TOKEN = 280,
    WHILE_TOKEN = 281,
    WRITESTR_TOKEN = 282,
    WRITE_TOKEN = 283,
    ADD_TOKEN = 284,
    SUBTRACT_TOKEN = 285,
    MULT_TOKEN = 286,
    DIV_TOKEN = 287,
    EQUAL_TOKEN = 288,
    LT_TOKEN = 289,
    LTEQ_TOKEN = 290,
    GT_TOKEN = 291,
    GTEQ_TOKEN = 292,
    HASH_TOKEN = 293,
    LPAREN_TOKEN = 294,
    RPAREN_TOKEN = 295,
    LBRACE_TOKEN = 296,
    RBRACE_TOKEN = 297,
    COMMA_TOKEN = 298,
    SEMICOLON_TOKEN = 299,
    DOUBLEQUOTE_TOKEN = 300,
    SINGLEQUOTE_TOKEN = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 38 "paxi_parser.y" /* yacc.c:1909  */

	int ival;
	char* strval;
	struct symtab_entry_s* entryval;

#line 107 "paxi_parser.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PAXI_PARSER_TAB_H_INCLUDED  */
