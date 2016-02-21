/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "paxi_parser.y" /* yacc.c:339  */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

// Global Var declarations
static int param_ctr = 0;
static int local_ctr = 0;
char* proc_name;

// Values shared between flex, bison, and driver files
extern int* code_store;
extern int cs_pointer; 
extern int line_count;
extern int next_avail;
extern int string_space;
extern int entry_point;

char* mangle(char* proc, char* var);
void emit(int opcode, int arg1, int arg2);
void backpatch(int address, int opcode, int arg1, int arg2);
void yyerror(char *str);


#line 93 "paxi_parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "paxi_parser.tab.h".  */
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
#line 38 "paxi_parser.y" /* yacc.c:355  */

	int ival;
	char* strval;
	struct symtab_entry_s* entryval;

#line 186 "paxi_parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PAXI_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "paxi_parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    46,    46,    48,    48,    50,    50,    52,    54,    63,
      73,    75,    75,    77,    87,    87,    90,   108,   123,   127,
      89,   150,   150,   152,   158,   164,   164,   166,   168,   174,
     180,   180,   182,   182,   182,   182,   182,   182,   184,   194,
     201,   208,   193,   214,   214,   216,   216,   219,   224,   230,
     218,   239,   238,   252,   252,   252,   255,   254,   278,   284,
     289,   293,   297,   302,   309,   313,   318,   323,   377,   394,
     376,   405,   414,   431,   437,   436,   444,   443,   463,   468,
     481,   483,   495,   497,   497,   499,   503,   508,   512,   517,
     526,   528,   537,   539,   547,   549,   562,   564,   569,   573,
     577,   581,   585
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID_TOKEN", "INT_TOKEN", "STRING_TOKEN",
  "CHAR_TOKEN", "NEWLINE_TOKEN", "WHITESPACE_TOKEN", "AND_TOKEN",
  "ARRAY_TOKEN", "DO_TOKEN", "ELSE_TOKEN", "ENDO_TOKEN", "ENDIF_TOKEN",
  "ENDPROC_TOKEN", "ENDWHILE_TOKEN", "IF_TOKEN", "LINE_TOKEN", "NOT_TOKEN",
  "OR_TOKEN", "PROC_TOKEN", "READ_TOKEN", "READSTR_TOKEN", "RETVAL_TOKEN",
  "VAR_TOKEN", "WHILE_TOKEN", "WRITESTR_TOKEN", "WRITE_TOKEN", "ADD_TOKEN",
  "SUBTRACT_TOKEN", "MULT_TOKEN", "DIV_TOKEN", "EQUAL_TOKEN", "LT_TOKEN",
  "LTEQ_TOKEN", "GT_TOKEN", "GTEQ_TOKEN", "HASH_TOKEN", "LPAREN_TOKEN",
  "RPAREN_TOKEN", "LBRACE_TOKEN", "RBRACE_TOKEN", "COMMA_TOKEN",
  "SEMICOLON_TOKEN", "DOUBLEQUOTE_TOKEN", "SINGLEQUOTE_TOKEN", "$accept",
  "program", "globals_list", "globals_decl", "global_var_decl",
  "global_var_list", "array_decl", "array_list", "single_array",
  "procedure_list", "procedure_decl", "$@1", "$@2", "$@3", "$@4",
  "formal_parameters", "formal_list", "locals_list", "local_decl",
  "local_var_list", "statement_list", "statement", "assignment",
  "conditional", "$@5", "$@6", "$@7", "else_clause", "loop", "while_loop",
  "$@8", "$@9", "$@10", "do_loop", "$@11", "io", "call", "$@12",
  "return_value", "actual_parameters", "parameter_list", "quantity",
  "variable", "$@13", "$@14", "read_statement", "write_statement", "$@15",
  "$@16", "line_statement", "arithmetic_expression", "arithmetic_term",
  "arithmetic_factor", "add_operator", "mult_operator",
  "boolean_expression", "boolean_term", "boolean_factor", "boolean_atom",
  "relational_operator", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -69

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -67,    12,     5,   -67,    20,    28,   -67,   -67,   -67,    23,
      33,   -17,   -67,   -67,     4,    46,   -67,   -67,    20,   -67,
      60,   -67,   -67,   -67,   -67,    27,    62,   -67,   -67,    37,
      30,    68,   -67,   -67,    47,    78,   -67,   -67,   -67,     8,
     106,    81,   -67,   -22,   -67,   -10,   -67,    55,    58,     7,
     -67,    59,    61,    70,    57,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,    66,   -67,   -67,   -67,   -67,     7,    63,
     -67,    64,     2,    82,    96,   -67,   -67,   104,   105,   -67,
     -67,     7,   -67,   -67,   -67,    26,    29,   -67,   -10,    15,
       7,   -67,   -67,     7,   -67,    67,    26,     7,    51,   -67,
       2,   107,    -6,   -10,   -67,   -10,    73,    71,    75,    -7,
     -67,   -67,     7,   -67,   -67,     7,    82,   -67,   -67,    10,
      26,    76,     7,    26,    92,    53,   -67,   -67,   -67,   -67,
     -67,   -67,     7,   -67,    96,   106,   -67,   -67,   -67,   -67,
      29,   -67,   -67,    79,    80,   -67,   -67,    26,    83,   -10,
      13,   114,   106,   -67,   -67,   -67,    82,   -67,   -67,   -67,
     111,   106,   117,   -67,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    15,     1,     0,     0,     3,     5,     6,     2,
       0,     0,    12,     9,     0,     0,    14,    13,     0,    10,
       0,     7,    16,    11,     8,     0,    22,    24,    17,    21,
       0,     0,    26,    23,    18,     0,    31,    25,    29,     0,
      19,     0,    27,    67,    51,     0,    78,     0,     0,     0,
      47,     0,     0,     0,     0,    32,    33,    34,    45,    46,
      35,    36,    37,     0,    53,    54,    55,    28,    60,     0,
      31,     0,     0,    39,    90,    92,    94,     0,     0,    64,
      66,     0,    65,    83,    63,    58,    80,    82,     0,     0,
       0,    20,    30,     0,    56,    59,    62,     0,     0,    93,
       0,     0,     0,     0,    31,     0,    67,     0,     0,     0,
      85,    86,     0,    87,    88,     0,    48,    76,    74,     0,
      38,     0,     0,    69,     0,     0,    97,    98,    99,   100,
     101,   102,     0,    96,    89,    40,    91,    71,    72,    84,
      79,    81,    31,     0,     0,    73,    57,    61,     0,     0,
       0,    44,    49,    77,    75,    70,    52,    95,    31,    41,
       0,    43,     0,    50,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   120,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -66,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -39,   -67,   -67,   -67,
     -67,   -67,   -40,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -65,    34,    24,   -67,   -67,   -43,    32,    42,    77,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,    14,     8,    11,    12,     9,
      16,    25,    30,    36,    53,    28,    29,    34,    37,    39,
      40,    54,    55,    56,   104,   151,   162,   159,    57,    58,
      88,   142,   160,    59,    70,    60,    82,   121,    62,    94,
      95,    83,    84,    69,   148,    64,    65,   144,   143,    66,
      85,    86,    87,   112,   115,   102,    74,    75,    76,   132
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    61,    73,    96,    98,    43,    79,   101,    80,    71,
      43,    79,     3,    80,   103,     4,   109,    68,   117,   -68,
     118,    71,   110,   111,    10,   119,    18,    19,   120,    72,
       5,    13,   123,   139,   133,   125,    17,   107,   135,   110,
     111,   100,   110,   111,    15,   116,    81,    20,    21,    22,
     145,    41,    42,   157,    43,   110,   111,   147,    63,    61,
     113,   114,    44,    24,   124,    27,    26,   150,    45,    46,
      32,    33,    35,    47,    48,    49,   152,    50,    51,    52,
      31,    38,   110,   111,    67,    91,   126,   127,   128,   129,
     130,   131,   161,   139,    77,    63,    61,    78,    89,    93,
      90,    92,   103,    72,    97,   105,   156,   106,   108,    43,
     122,   137,    63,    61,   -68,   138,   146,    44,   149,   153,
     154,    63,    61,    45,    46,   155,   158,   163,    47,    48,
      49,   164,    50,    51,    52,   134,   110,   111,    23,   141,
     126,   127,   128,   129,   130,   131,   140,   136,    99
};

static const yytype_uint8 yycheck[] =
{
      40,    40,    45,    68,    70,     3,     4,    72,     6,    19,
       3,     4,     0,     6,    20,    10,    81,    39,     3,    41,
       5,    19,    29,    30,     4,    90,    43,    44,    93,    39,
      25,     3,    97,    40,    40,   100,     3,    77,   104,    29,
      30,    39,    29,    30,    21,    88,    39,    43,    44,     3,
      40,    43,    44,    40,     3,    29,    30,   122,    98,    98,
      31,    32,    11,     3,    13,     3,    39,   132,    17,    18,
      40,     3,    25,    22,    23,    24,   142,    26,    27,    28,
      43,     3,    29,    30,     3,    15,    33,    34,    35,    36,
      37,    38,   158,    40,    39,   135,   135,    39,    39,    33,
      39,    44,    20,    39,    41,     9,   149,     3,     3,     3,
      43,    40,   152,   152,    41,    40,    40,    11,    26,    40,
      40,   161,   161,    17,    18,    42,    12,    16,    22,    23,
      24,    14,    26,    27,    28,   103,    29,    30,    18,   115,
      33,    34,    35,    36,    37,    38,   112,   105,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,     0,    10,    25,    50,    51,    53,    56,
       4,    54,    55,     3,    52,    21,    57,     3,    43,    44,
      43,    44,     3,    55,     3,    58,    39,     3,    62,    63,
      59,    43,    40,     3,    64,    25,    60,    65,     3,    66,
      67,    43,    44,     3,    11,    17,    18,    22,    23,    24,
      26,    27,    28,    61,    68,    69,    70,    75,    76,    80,
      82,    83,    85,    89,    92,    93,    96,     3,    39,    90,
      81,    19,    39,   102,   103,   104,   105,    39,    39,     4,
       6,    39,    83,    88,    89,    97,    98,    99,    77,    39,
      39,    15,    44,    33,    86,    87,    97,    41,    67,   105,
      39,    97,   102,    20,    71,     9,     3,    89,     3,    97,
      29,    30,   100,    31,    32,   101,   102,     3,     5,    97,
      97,    84,    43,    97,    13,    97,    33,    34,    35,    36,
      37,    38,   106,    40,   103,    67,   104,    40,    40,    40,
      98,    99,    78,    95,    94,    40,    40,    97,    91,    26,
      97,    72,    67,    40,    40,    42,   102,    40,    12,    74,
      79,    67,    73,    16,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    52,    52,
      53,    54,    54,    55,    56,    56,    58,    59,    60,    61,
      57,    62,    62,    63,    63,    64,    64,    65,    66,    66,
      67,    67,    68,    68,    68,    68,    68,    68,    69,    71,
      72,    73,    70,    74,    74,    75,    75,    77,    78,    79,
      76,    81,    80,    82,    82,    82,    84,    83,    85,    86,
      86,    87,    87,    88,    88,    88,    88,    89,    90,    91,
      89,    92,    92,    93,    94,    93,    95,    93,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   105,   106,   106,   106,
     106,   106,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     3,     3,     1,
       3,     3,     1,     2,     2,     0,     0,     0,     0,     0,
      12,     1,     0,     3,     1,     2,     0,     3,     3,     1,
       3,     0,     1,     1,     1,     1,     1,     1,     3,     0,
       0,     0,     8,     2,     0,     1,     1,     0,     0,     0,
       7,     0,     6,     1,     1,     1,     0,     5,     2,     1,
       0,     3,     1,     1,     1,     1,     1,     1,     0,     0,
       6,     4,     4,     4,     0,     5,     0,     5,     1,     3,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     3,     1,     2,     1,     5,     3,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
#line 55 "paxi_parser.y" /* yacc.c:1646  */
    {
			if(lookup((yyvsp[0].strval)) == NULL){
				insert((yyvsp[0].strval), "variable", 1, next_avail);
				next_avail += 1;
			}else{
				yyerror("Variable defined earlier in program");
			}	
		}
#line 1419 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 64 "paxi_parser.y" /* yacc.c:1646  */
    {
			if(lookup((yyvsp[0].strval)) == NULL){
				insert((yyvsp[0].strval), "variable", 1, next_avail);
				next_avail += 1;
			}else{
				yyerror("Variable defined earlier in program");
			}
		}
#line 1432 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 78 "paxi_parser.y" /* yacc.c:1646  */
    {
			if(lookup((yyvsp[0].strval)) == NULL){
				insert((yyvsp[0].strval), "array", (yyvsp[-1].ival), next_avail);
				next_avail += (yyvsp[-1].ival);
			}else{
				yyerror("Array identifier defined earlier in program");	
			}
		}
#line 1445 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 90 "paxi_parser.y" /* yacc.c:1646  */
    {
			if(lookup((yyvsp[0].strval)) == NULL){
				// save newly read procedure name into global
				char* new_proc = malloc(sizeof((yyvsp[0].strval) + 1));
				strcpy(new_proc, (yyvsp[0].strval));
				proc_name = new_proc;
				param_ctr = 0;
				local_ctr = 0;
			}else{
				yyerror("Procedure name defined earlier in program");
			}

			// doing this so that main doesnt break
			if(!strcmp(proc_name, "main")){
				entry_point = cs_pointer;
			}
		}
#line 1467 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 108 "paxi_parser.y" /* yacc.c:1646  */
    {
			//cs_pointer may be the wrong thing here	
			insert((yyvsp[-3].strval), "procedure", param_ctr, cs_pointer);
			
			//start executing in main	
			if(!strcmp(proc_name, "main")){
			//	entry_point = cs_pointer;
			} 	
			// push current frame pointer value 
			// copy value of stack pointer to frame pointer
			emit(25, 1, 0);
			emit(8, 1, 0);
					
		}
#line 1486 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 123 "paxi_parser.y" /* yacc.c:1646  */
    {
			emit(10, 0, -local_ctr);
		}
#line 1494 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 127 "paxi_parser.y" /* yacc.c:1646  */
    { 
			/* Clearing stack frame
			 * 
			 * Deallocate stack pointer, inc by # of local vars
			 * Pop frame pointer into Register 1
			 * return instruction with parameter count as argument
			 */
			emit(10, 0, local_ctr);
			emit(28, 1, 0);
		}
#line 1509 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 138 "paxi_parser.y" /* yacc.c:1646  */
    {
		
			//emitting stop_op if at the end of main
			if(!strcmp(proc_name, "main")){
				emit(36, 0, 0);
			}else{
				//emit a return
				emit(35, param_ctr, 0);	
			}
		}
#line 1524 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 153 "paxi_parser.y" /* yacc.c:1646  */
    {
			//Changed param_ctr++ to ++param_ctr
			char* mangled_param = mangle(proc_name, (yyvsp[0].strval));
			insert(mangled_param, "parameter", 1, ++param_ctr);
		}
#line 1534 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 159 "paxi_parser.y" /* yacc.c:1646  */
    {
			char* mangled_param = mangle(proc_name, (yyvsp[0].strval));
			insert(mangled_param, "parameter", 1, ++param_ctr);
		}
#line 1543 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 169 "paxi_parser.y" /* yacc.c:1646  */
    {
			//changed local_ctr++ to ++local_ctr
			char* mangled_param = mangle(proc_name, (yyvsp[0].strval));
			insert(mangled_param, "local_variable", 1, ++local_ctr);	
		}
#line 1553 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 175 "paxi_parser.y" /* yacc.c:1646  */
    {
			char* mangled_param = mangle(proc_name, (yyvsp[0].strval));
			insert(mangled_param, "local_variable", 1, ++local_ctr);
		}
#line 1562 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 185 "paxi_parser.y" /* yacc.c:1646  */
    {
		//popping variable address and value
		//moving value into variable address
	 	emit(27, 500, 0);
		emit(27, 501, 0);
		emit(4, 501, 500); 
	    }
#line 1574 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 194 "paxi_parser.y" /* yacc.c:1646  */
    {
		
	     	emit(27, 500, 0); //pop top of stack
		(yyvsp[0].ival) = cs_pointer; //save address for backpatching
		emit(999, 999, 999); // emit dummy instuction for backpatching
             }
#line 1585 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 201 "paxi_parser.y" /* yacc.c:1646  */
    {
	     	(yyvsp[0].ival) = cs_pointer;
	        emit(999, 999, 999);
		//if boolean_expression is false, jump here
		backpatch((yyvsp[-2].ival), 18, cs_pointer, 500); 
	     }
#line 1596 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 208 "paxi_parser.y" /* yacc.c:1646  */
    {
		//jump over the else if boolean_expression is true
             	backpatch((yyvsp[-2].ival), 17, cs_pointer, 0);
	     }
#line 1605 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 219 "paxi_parser.y" /* yacc.c:1646  */
    {
		//save start location of loop
	    	(yyvsp[0].ival) = cs_pointer;
	    }
#line 1614 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 224 "paxi_parser.y" /* yacc.c:1646  */
    {
		emit(27, 500, 0);
		(yyvsp[0].ival) = cs_pointer;
		emit(999, 999, 999);	    
	    }
#line 1624 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 230 "paxi_parser.y" /* yacc.c:1646  */
    {
		//if boolean_expression is false exit the loop
            	backpatch((yyvsp[-2].ival), 18, cs_pointer+3, 500);
		//if boolean_expression is true, keep looping
		emit(17, (yyvsp[-4].ival), 0);
            }
#line 1635 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 239 "paxi_parser.y" /* yacc.c:1646  */
    {
		//save beginning of loop
	 	(yyvsp[0].ival) = cs_pointer;
	 }
#line 1644 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 244 "paxi_parser.y" /* yacc.c:1646  */
    {
	 	emit(27, 500, 0);
		//if boolean_expression is false exit the loop
		emit(18, cs_pointer+6, 500);
		//if boolean_expression is true keep looping
		emit(17, (yyvsp[-5].ival), 0);
	 }
#line 1656 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 255 "paxi_parser.y" /* yacc.c:1646  */
    {
      	/* count paramters in actual_parameters and parameters list
	 * look up procedure in symtab and compare parameters with expected values
	 * emit a call instruction with the locaiton field fo symtab entry as arg
	 */
	struct symtab_entry_s* entry;
	entry = lookup((yyvsp[-2].strval));
	if(entry != NULL && !strcmp(entry->type, "procedure")){
		if((yyvsp[0].ival) == entry->size){
			emit(34, entry->location, 0);
		}else{
			printf("%d %d\n", (yyvsp[0].ival), entry->size);
			yyerror("Procedure called with wrong amount of params");
		}	
	}else{
		yyerror("Bad procedure call");
	}

		
	//emmiting call instruction
      	//emit(34, entry->location, 0);
      }
#line 1683 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 279 "paxi_parser.y" /* yacc.c:1646  */
    {
		 // pop top of stack into Register 2
		emit(28, 2, 0);
	      }
#line 1692 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 285 "paxi_parser.y" /* yacc.c:1646  */
    {
				(yyval.ival) = (yyvsp[0].ival);
			}
#line 1700 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 289 "paxi_parser.y" /* yacc.c:1646  */
    { 
				(yyval.ival) = 0;
			}
#line 1708 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 294 "paxi_parser.y" /* yacc.c:1646  */
    {
			(yyval.ival) = (yyvsp[-2].ival) + 1;
		}
#line 1716 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 298 "paxi_parser.y" /* yacc.c:1646  */
    {
			(yyval.ival) = 1;
		}
#line 1724 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 303 "paxi_parser.y" /* yacc.c:1646  */
    {
		//pushing variable address onto stack
		emit(27, 500, 0);
		emit(3, 500, 500);
		emit(24, 500, 0); 
	  }
#line 1735 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 310 "paxi_parser.y" /* yacc.c:1646  */
    {
	  	emit(26, (yyvsp[0].ival), 0);
	  }
#line 1743 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 314 "paxi_parser.y" /* yacc.c:1646  */
    {
		// push the value in register 2 onto stack
		emit(25, 2, 0);
	  }
#line 1752 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 319 "paxi_parser.y" /* yacc.c:1646  */
    {
	  	emit(26, (yyvsp[0].ival), 0);
	  }
#line 1760 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 324 "paxi_parser.y" /* yacc.c:1646  */
    {

		/* 
		 * add (p-n+2) to frame pointer to get addres of parameter
		 * p is the param_ctr
		 * 
		 * addresses of local vars is done by finding the location relative to fp
		 * lv1 = (fp + 1)
		 */
			
		(yyval.ival) = ID_TOKEN;
		int location;
		int offset;
		struct symtab_entry_s* entry;
		char* mangled_param = mangle(proc_name, (yyvsp[0].strval));
		entry = lookup(mangled_param);
		//if mangled version in symtab
		if(entry != NULL){
			if(!strcmp(entry->type, "local_variable")){
		       		location = entry->location;
				emit(7, 500, 1);
				emit(2, 501, location);
				emit(11, 500, 501);
				emit(24, 500, 0);

			}else if(!strcmp(entry->type, "parameter")){
				//Looking up parameter passed into function
				offset = (param_ctr - entry->location + 2);
				emit(7, 500, 1);
				emit(2, 501, offset);
				emit(9, 500, 501);
				//emit(3, 500, 500);
				emit(24, 500, 0);
			}
				
                }else{
			//lookup unmagled for if variable
                        entry = lookup((yyvsp[0].strval));
                        if(entry != NULL){
                               if(!strcmp(entry->type, "variable")){
					location = entry->location;
			       		emit(26, location, 0);
			       }
                        }

                }
		if(entry == NULL){
			yyerror("Attempt to use undeclared variable");
		}
		//printf("%s\n", $<strval>1);
		free((yyvsp[0].strval));		
	  }
#line 1817 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 377 "paxi_parser.y" /* yacc.c:1646  */
    {
	  	//ARRAY REFERENCE
	 	int location;
		struct symtab_entry_s* entry;
		entry = lookup((yyvsp[0].strval));
		if(entry != NULL){
                       if(!strcmp(entry->type, "array")){
		       		location = entry->location;
				//ARRAY BASE LOCATION PUSHED
				emit(26, location, 0);
			}
		}
       		if(entry == NULL){
			yyerror("Attempt to access undelcared array");
		}
	  }
#line 1838 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 394 "paxi_parser.y" /* yacc.c:1646  */
    {
		//POP the base address and offset
	 	emit(27, 501, 0);
		emit(27, 500, 0);
		//Add offset to base address
		emit(9, 500, 501);
		//push location+offset
		emit(24, 500, 0);
		
	  }
#line 1853 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 406 "paxi_parser.y" /* yacc.c:1646  */
    {
				
			//the geti operation
			emit(27, 500, 0);
			emit(32, 501, 0);
			emit(4, 500, 501);
	
		}
#line 1866 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 415 "paxi_parser.y" /* yacc.c:1646  */
    {
		        int location;
                        struct symtab_entry_s* entry;
                        entry = lookup((yyvsp[-1].strval));
                        if(entry != NULL){
                               if(!strcmp(entry->type, "array")){
                                        location = entry->location;
                                        //Print string starting at location
                                        emit(33, location, 0);
                                }
                        }
                        if(entry == NULL){
                                yyerror("Attempt to access undelcared array");
                        }		
		}
#line 1886 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 432 "paxi_parser.y" /* yacc.c:1646  */
    {
		 	emit(27, 500, 0);
			emit(29, 500, 0);
		 }
#line 1895 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 437 "paxi_parser.y" /* yacc.c:1646  */
    {
			emit(30, (next_avail + string_space), 0);
			string_space += ((yyvsp[0].ival) - 1);	 
		 }
#line 1904 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 444 "paxi_parser.y" /* yacc.c:1646  */
    {
 	
			int location;
                	struct symtab_entry_s* entry;
                	entry = lookup((yyvsp[0].strval));
                	if(entry != NULL){
                	       if(!strcmp(entry->type, "array")){
                	                location = entry->location;
                	                //Print string starting at location
                	                emit(30, location, 0);
                	        }
                	}
                	if(entry == NULL){
                	        yyerror("Attempt to access undelcared array");
                	}
		
		 }
#line 1926 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 464 "paxi_parser.y" /* yacc.c:1646  */
    {
			emit(31, 0, 0);
		}
#line 1934 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 469 "paxi_parser.y" /* yacc.c:1646  */
    {
	       	       		emit(27, 501, 0);
				emit(27, 500, 0);
				if((yyvsp[-1].ival) == ADD_TOKEN){
					emit(9, 500, 501);
				}
				else if((yyvsp[-1].ival) == SUBTRACT_TOKEN){
					emit(11, 500, 501);
				}
				emit(24, 500, 0);
			
		       }
#line 1951 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 484 "paxi_parser.y" /* yacc.c:1646  */
    {
			emit(27, 501, 0);
			emit(27, 500, 0);
  			if((yyvsp[-1].ival) == MULT_TOKEN){
                                emit(12, 500, 501);
                        }
                        if((yyvsp[-1].ival) == DIV_TOKEN){
                                emit(13, 500, 501);
                        }
			emit(24, 500, 0);
		 }
#line 1967 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 500 "paxi_parser.y" /* yacc.c:1646  */
    {
		(yyval.ival) = ADD_TOKEN;
	      }
#line 1975 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 504 "paxi_parser.y" /* yacc.c:1646  */
    {
	      	(yyval.ival) = SUBTRACT_TOKEN;
              }
#line 1983 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 509 "paxi_parser.y" /* yacc.c:1646  */
    {
               	(yyval.ival) = MULT_TOKEN;
	       }
#line 1991 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 513 "paxi_parser.y" /* yacc.c:1646  */
    {
               	(yyval.ival) = DIV_TOKEN;
	       }
#line 1999 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 518 "paxi_parser.y" /* yacc.c:1646  */
    {
			//pop vals into scratch
			//Or them, push back onto stack
		    	emit(27, 500, 0);
			emit(27, 501, 0);
			emit(14, 500, 501);
			emit(24, 500, 0);
		    }
#line 2012 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 529 "paxi_parser.y" /* yacc.c:1646  */
    {
			//pop vals into scratch
			//And them, push back onto stack
			emit(27, 500, 0);
			emit(27, 501, 0);
			emit(15, 500, 501);
			emit(24, 500, 0); 
		}
#line 2025 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 540 "paxi_parser.y" /* yacc.c:1646  */
    {
			//pop value
			//boolean Not, push back onto stack
			emit(27, 500, 0);
			emit(16, 500, 0);
			emit(24, 500, 0);
		}
#line 2037 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 551 "paxi_parser.y" /* yacc.c:1646  */
    {
			emit(27, 501, 0);
			emit(27, 500, 0);
			//subract values, branch compares to 0 
			emit(11, 500, 501); 
			// if true, jump 3 lines
			emit((yyvsp[-2].ival), cs_pointer+9, 500); 
			emit(26, 0, 0); //push 0 for false
			emit(17, cs_pointer+6, 0); // jump 2 lines
			emit(26, 1, 0);	// push 1 for true
		}
#line 2053 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 565 "paxi_parser.y" /* yacc.c:1646  */
    {
				//Using parse stack to pass up opcodes
				(yyval.ival) = 18;
			}
#line 2062 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 570 "paxi_parser.y" /* yacc.c:1646  */
    {
				(yyval.ival) = 22;
			}
#line 2070 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 574 "paxi_parser.y" /* yacc.c:1646  */
    {
				(yyval.ival) = 23;
			}
#line 2078 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 578 "paxi_parser.y" /* yacc.c:1646  */
    {
				(yyval.ival) = 20;
			}
#line 2086 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 582 "paxi_parser.y" /* yacc.c:1646  */
    {
				(yyval.ival) = 21;
			}
#line 2094 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 586 "paxi_parser.y" /* yacc.c:1646  */
    {
				(yyval.ival) = 19;
			}
#line 2102 "paxi_parser.tab.c" /* yacc.c:1646  */
    break;


#line 2106 "paxi_parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 590 "paxi_parser.y" /* yacc.c:1906  */


void yyerror(char *str){
	printf("%s\nLine: %d\n", str, line_count);
	exit(1);
}

void emit(int opcode, int arg1, int arg2){

	code_store[cs_pointer] = opcode;
	code_store[cs_pointer + 1] = arg1;
	code_store[cs_pointer + 2] = arg2;	
	cs_pointer += 3;

	//Resize code_store if it fills up	
	if((cs_pointer%300)==0){
		code_store = (int*) realloc(code_store,
				 	   ((300+cs_pointer)*sizeof(int)));
	}

}

void backpatch(int address, int opcode, int arg1, int arg2){
	code_store[address] = opcode;
	code_store[address + 1] = arg1;
	code_store[address + 2] = arg2;	
}

char* mangle(char* proc, char* var){
        int i = 0;
        int len = 0;

        while(*(var + len) != '\0'){
                len++;
        }
        len++;

        //find length of associated proc
        while(*(proc + i) != '\0'){
                i++;
        }
        i++;
        //determine size of mangled string and malloc it
        int mangled_len = (len + i);
        //printf("%d\n", mangled_len);
        char* mangled_param = calloc((mangled_len+1), sizeof(char));
        len = i = 0;
        // put the var name infront of the proc
        while(*(var + i) != '\0'){
                mangled_param[i] = *(var + i);
                i++;
        }
       // i++;
        mangled_param[i] = '@';
        i++;
        while(*(proc + len) != '\0'){
                mangled_param[i + len] = *(proc+len);
                len++;
        }
        return mangled_param;
}

