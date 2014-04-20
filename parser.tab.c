/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 3 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "header.h"
int linenumber = 1;
AST_NODE *prog;

extern int g_anyErrorOccur;

static inline AST_NODE* makeSibling(AST_NODE *a, AST_NODE *b)
{ 
    while (a->rightSibling) {
        a = a->rightSibling;
    }
    if (b == NULL) {
        return a;
    }
    b = b->leftmostSibling;
    a->rightSibling = b;
    
    b->leftmostSibling = a->leftmostSibling;
    b->parent = a->parent;
    while (b->rightSibling) {
        b = b->rightSibling;
        b->leftmostSibling = a->leftmostSibling;
        b->parent = a->parent;
    }
    return b;
}

static inline AST_NODE* makeChild(AST_NODE *parent, AST_NODE *child)
{
    if (child == NULL) {
        return parent;
    }
    if (parent->child) {
        makeSibling(parent->child, child);
    } else {
        child = child->leftmostSibling;
        parent->child = child;
        while (child) {
            child->parent = parent;
            child = child->rightSibling;
        }
    }
    return parent;
}

static AST_NODE* makeFamily(AST_NODE *parent, int childrenCount, ...)
{
    va_list childrenList;
    va_start(childrenList, childrenCount);
    AST_NODE* child = va_arg(childrenList, AST_NODE*);
    makeChild(parent, child);
    AST_NODE* tmp = child;
    int index = 1;
    for (index = 1; index < childrenCount; ++index) {
        child = va_arg(childrenList, AST_NODE*);
        tmp = makeSibling(tmp, child);
    }
    va_end(childrenList);
    return parent;
}

static inline AST_NODE* makeIDNode(char *lexeme, IDENTIFIER_KIND idKind)
{
    AST_NODE* identifier = Allocate(IDENTIFIER_NODE);
    identifier->semantic_value.identifierSemanticValue.identifierName = lexeme;
    identifier->semantic_value.identifierSemanticValue.kind = idKind;
    identifier->semantic_value.identifierSemanticValue.symbolTableEntry = NULL;
    return identifier;                        
}

static inline AST_NODE* makeStmtNode(STMT_KIND stmtKind)
{
    AST_NODE* stmtNode = Allocate(STMT_NODE);
    stmtNode->semantic_value.stmtSemanticValue.kind = stmtKind;
    return stmtNode;                        
}

static inline AST_NODE* makeDeclNode(DECL_KIND declKind)
{
    AST_NODE* declNode = Allocate(DECLARATION_NODE);
    declNode->semantic_value.declSemanticValue.kind = declKind;
    return declNode;                        
}

static inline AST_NODE* makeExprNode(EXPR_KIND exprKind, int operationEnumValue)
{
    AST_NODE* exprNode = Allocate(EXPR_NODE);
    exprNode->semantic_value.exprSemanticValue.isConstEval = 0;
    exprNode->semantic_value.exprSemanticValue.kind = exprKind;
    if (exprKind == BINARY_OPERATION) {
        exprNode->semantic_value.exprSemanticValue.op.binaryOp = operationEnumValue;
    } else if (exprKind == UNARY_OPERATION) {
        exprNode->semantic_value.exprSemanticValue.op.unaryOp = operationEnumValue;
    } else {
        printf("Error in static inline AST_NODE* makeExprNode(EXPR_KIND exprKind, int operationEnumValue)\n");
    }
    return exprNode;                        
}



/* Line 268 of yacc.c  */
#line 178 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     CONST = 259,
     VOID = 260,
     INT = 261,
     FLOAT = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     FOR = 266,
     TYPEDEF = 267,
     OP_ASSIGN = 268,
     OP_OR = 269,
     OP_AND = 270,
     OP_NOT = 271,
     OP_EQ = 272,
     OP_NE = 273,
     OP_GT = 274,
     OP_LT = 275,
     OP_GE = 276,
     OP_LE = 277,
     OP_PLUS = 278,
     OP_MINUS = 279,
     OP_TIMES = 280,
     OP_DIVIDE = 281,
     MK_LB = 282,
     MK_RB = 283,
     MK_LPAREN = 284,
     MK_RPAREN = 285,
     MK_LBRACE = 286,
     MK_RBRACE = 287,
     MK_COMMA = 288,
     MK_SEMICOLON = 289,
     MK_DOT = 290,
     ERROR = 291,
     RETURN = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 111 "parser.y"

	char *lexeme;
	CON_Type  *const1;
	AST_NODE  *node;



/* Line 293 of yacc.c  */
#line 259 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 271 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    14,    16,    25,
      34,    42,    50,    54,    56,    59,    63,    67,    72,    74,
      75,    78,    80,    82,    83,    86,    88,    90,    92,    97,
     102,   106,   110,   112,   114,   116,   120,   125,   128,   132,
     137,   141,   145,   147,   151,   155,   157,   159,   163,   165,
     169,   171,   174,   178,   181,   183,   187,   197,   202,   208,
     210,   213,   217,   219,   220,   224,   226,   230,   232,   234,
     238,   240,   244,   246,   250,   252,   254,   256,   258,   260,
     262,   264,   265,   269,   271,   275,   277,   279,   281,   285,
     287,   289,   291,   295,   300,   302,   305,   310,   316,   318,
     321,   323,   326,   331
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    40,    -1,    -1,    40,    41,    -1,    41,
      -1,    48,    42,    -1,    42,    -1,    52,     3,    29,    43,
      30,    31,    47,    32,    -1,     5,     3,    29,    43,    30,
      31,    47,    32,    -1,    52,     3,    29,    30,    31,    47,
      32,    -1,     5,     3,    29,    30,    31,    47,    32,    -1,
      43,    33,    44,    -1,    44,    -1,    52,     3,    -1,    52,
       3,    45,    -1,    27,    46,    28,    -1,    45,    27,    71,
      28,    -1,    71,    -1,    -1,    48,    60,    -1,    60,    -1,
      48,    -1,    -1,    48,    49,    -1,    49,    -1,    50,    -1,
      51,    -1,    12,    52,    53,    34,    -1,    12,     5,    53,
      34,    -1,    52,    58,    34,    -1,     3,    53,    34,    -1,
       6,    -1,     7,    -1,     3,    -1,    53,    33,     3,    -1,
      53,    33,     3,    54,    -1,     3,    54,    -1,    27,    55,
      28,    -1,    54,    27,    55,    28,    -1,    55,    23,    56,
      -1,    55,    24,    56,    -1,    56,    -1,    56,    25,    57,
      -1,    56,    26,    57,    -1,    57,    -1,     4,    -1,    29,
      55,    30,    -1,    59,    -1,    58,    33,    59,    -1,     3,
      -1,     3,    54,    -1,     3,    13,    65,    -1,    60,    61,
      -1,    61,    -1,    31,    47,    32,    -1,    11,    29,    62,
      34,    69,    34,    62,    30,    61,    -1,    76,    13,    65,
      34,    -1,     3,    29,    69,    30,    34,    -1,    34,    -1,
      37,    34,    -1,    37,    65,    34,    -1,    63,    -1,    -1,
      63,    33,    64,    -1,    64,    -1,     3,    13,    65,    -1,
      65,    -1,    66,    -1,    65,    14,    66,    -1,    67,    -1,
      66,    15,    67,    -1,    71,    -1,    71,    68,    71,    -1,
      17,    -1,    21,    -1,    22,    -1,    18,    -1,    19,    -1,
      20,    -1,    70,    -1,    -1,    70,    33,    65,    -1,    65,
      -1,    71,    72,    73,    -1,    73,    -1,    23,    -1,    24,
      -1,    73,    74,    75,    -1,    75,    -1,    25,    -1,    26,
      -1,    29,    65,    30,    -1,    16,    29,    65,    30,    -1,
       4,    -1,    16,     4,    -1,     3,    29,    69,    30,    -1,
      16,     3,    29,    69,    30,    -1,    76,    -1,    16,    76,
      -1,     3,    -1,     3,    77,    -1,    77,    27,    71,    28,
      -1,    27,    71,    28,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   166,   169,   173,   179,   183,   189,   196,
     203,   209,   217,   221,   227,   232,   238,   242,   248,   253,
     258,   264,   269,   274,   279,   283,   289,   293,   299,   305,
     312,   318,   325,   329,   335,   339,   343,   349,   354,   358,
     365,   370,   375,   380,   385,   390,   396,   401,   407,   411,
     417,   421,   425,   431,   435,   443,   449,   454,   463,   470,
     474,   478,   485,   490,   495,   500,   512,   516,   522,   526,
     533,   537,   544,   548,   555,   559,   563,   567,   571,   575,
     582,   587,   592,   597,   604,   610,   616,   620,   626,   632,
     638,   642,   648,   653,   658,   664,   670,   676,   681,   686,
     693,   697,   705,   710
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CONST", "VOID", "INT", "FLOAT",
  "IF", "ELSE", "WHILE", "FOR", "TYPEDEF", "OP_ASSIGN", "OP_OR", "OP_AND",
  "OP_NOT", "OP_EQ", "OP_NE", "OP_GT", "OP_LT", "OP_GE", "OP_LE",
  "OP_PLUS", "OP_MINUS", "OP_TIMES", "OP_DIVIDE", "MK_LB", "MK_RB",
  "MK_LPAREN", "MK_RPAREN", "MK_LBRACE", "MK_RBRACE", "MK_COMMA",
  "MK_SEMICOLON", "MK_DOT", "ERROR", "RETURN", "$accept", "program",
  "global_decl_list", "global_decl", "function_decl", "param_list",
  "param", "dim_fn", "expr_null", "block", "decl_list", "decl",
  "type_decl", "var_decl", "type", "id_list", "dim_decl", "cexpr",
  "mcexpr", "cfactor", "init_id_list", "init_id", "stmt_list", "stmt",
  "assign_expr_list", "nonempty_assign_expr_list", "assign_expr",
  "relop_expr", "relop_term", "relop_factor", "rel_op", "relop_expr_list",
  "nonempty_relop_expr_list", "expr", "add_op", "term", "mul_op", "factor",
  "var_ref", "dim_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    41,    41,    42,    42,
      42,    42,    43,    43,    44,    44,    45,    45,    46,    46,
      47,    47,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    53,    53,    53,    53,    54,    54,
      55,    55,    55,    56,    56,    56,    57,    57,    58,    58,
      59,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      76,    76,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     8,     8,
       7,     7,     3,     1,     2,     3,     3,     4,     1,     0,
       2,     1,     1,     0,     2,     1,     1,     1,     4,     4,
       3,     3,     1,     1,     1,     3,     4,     2,     3,     4,
       3,     3,     1,     3,     3,     1,     1,     3,     1,     3,
       1,     2,     3,     2,     1,     3,     9,     4,     5,     1,
       2,     3,     1,     0,     3,     1,     3,     1,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     4,     1,     2,     4,     5,     1,     2,
       1,     2,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,    32,    33,     0,     0,     2,     5,     7,
       0,    25,    26,    27,     0,    34,     0,     0,     0,     0,
       1,     4,     6,    24,    50,     0,    48,     0,    37,     0,
      31,     0,     0,     0,     0,     0,    51,     0,    30,    46,
       0,     0,    42,    45,     0,    35,     0,     0,    13,     0,
      29,    28,   100,    94,     0,     0,    52,    68,    70,    72,
      85,    89,    98,     0,     0,    50,    49,     0,     0,     0,
      38,     0,     0,     0,    36,    23,     0,     0,    14,     0,
      81,   101,   100,    95,     0,    99,     0,     0,     0,    74,
      77,    78,    79,    75,    76,    86,    87,     0,     0,    90,
      91,     0,    23,     0,    47,    40,    41,    43,    44,    39,
     100,     0,    23,    59,     0,     0,    22,     0,    21,    54,
       0,    23,    12,    19,    15,     0,    83,     0,    80,     0,
      81,     0,    92,    69,    71,    73,    84,    88,     0,    23,
      81,    63,     0,    60,     0,    11,    20,   100,    53,     0,
       0,     0,    18,     0,   103,    96,     0,     0,     0,    93,
      10,     0,     0,   100,     0,    62,    65,    67,    55,    61,
       0,     9,    16,     0,    82,   102,    97,     8,     0,     0,
      81,     0,    57,    17,    58,    66,     0,    64,    63,     0,
       0,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    47,    48,   124,   151,   115,
     116,    11,    12,    13,   117,    16,    36,    41,    42,    43,
      25,    26,   118,   119,   164,   165,   166,   126,    57,    58,
      97,   127,   128,    59,    98,    60,   101,    61,    62,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -126
static const yytype_int16 yypact[] =
{
     107,    42,    53,  -126,  -126,   151,    19,   107,  -126,  -126,
     107,  -126,  -126,  -126,    76,    61,   119,    68,    42,    42,
    -126,  -126,  -126,  -126,    77,   129,  -126,     3,    78,   137,
    -126,    27,   131,   133,    67,    30,    78,   146,  -126,  -126,
       3,    93,   143,  -126,     3,    61,   148,    70,  -126,   157,
    -126,  -126,    72,  -126,    73,    67,   160,   167,  -126,   106,
     145,  -126,  -126,   155,   103,    40,  -126,   108,     3,     3,
    -126,     3,     3,   111,    78,    17,   156,   166,   161,    67,
      67,   162,    91,  -126,    67,  -126,    16,    67,    67,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,    67,    67,  -126,
    -126,    67,    17,   163,  -126,   143,   143,  -126,  -126,  -126,
      37,   154,    17,  -126,    58,   158,    17,   146,     7,  -126,
     178,    17,  -126,    67,   165,   118,   160,   168,   164,    67,
      67,    64,  -126,   167,  -126,   152,   145,  -126,   169,    17,
      67,    69,   170,  -126,    13,  -126,     7,   132,  -126,    67,
     171,   172,   152,    67,  -126,  -126,    67,   120,   174,  -126,
    -126,   173,   176,    82,   175,   177,  -126,   160,  -126,  -126,
      55,  -126,  -126,   127,   160,  -126,  -126,  -126,   179,    67,
      67,    69,  -126,  -126,  -126,   160,   180,  -126,    69,   181,
       7,  -126
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,   186,   185,   182,   122,  -126,  -126,   -96,
      84,    -8,  -126,  -126,     4,   159,    -3,   -27,   112,   113,
    -126,   183,    80,  -115,    20,  -126,    26,   -34,   125,   128,
    -126,  -125,  -126,   -71,  -126,   117,  -126,   121,   -53,  -126
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      56,    85,    23,   148,    14,   158,   138,    39,   125,    19,
     147,    14,    28,    67,    14,   162,   142,    73,   111,    20,
     110,    86,   120,     3,     4,   150,   135,    87,   111,     5,
      87,   148,    40,     3,     4,    49,     3,     4,   112,    49,
      15,   113,    74,   161,   114,    15,   132,   169,   112,   120,
     131,   113,   152,    34,   114,   186,    17,    46,   157,   120,
      63,    52,    53,   120,    79,   120,   140,    27,   120,    87,
      52,    53,   163,    53,    54,   191,    82,    83,    87,    24,
     144,    49,   173,    54,    10,    54,   120,    55,    27,   182,
      34,    10,   143,   120,   159,   179,    55,    31,    55,    79,
      76,    80,    84,    77,    27,    44,    35,   167,    23,    79,
       1,    80,     2,     3,     4,   170,    68,    69,    79,     5,
     130,    70,   174,    89,    90,    91,    92,    93,    94,    95,
      96,    68,    69,   103,    68,    69,    77,   120,   104,   109,
      45,    95,    96,    95,    96,   185,   154,   167,   175,    65,
      95,    96,    29,    30,   167,   183,    18,     3,     4,    79,
      78,   140,    37,    38,    29,    50,    29,    51,    71,    72,
      99,   100,     3,     4,    87,    95,    96,    32,    33,    75,
     105,   106,    88,   141,   107,   108,   102,   121,   123,   129,
     145,   149,   153,    21,   139,    22,   146,   156,   155,   122,
     172,   160,   168,   171,   176,   177,   178,   187,   189,   180,
     181,   190,   133,   184,   188,   136,   134,    64,     0,     0,
      66,     0,   137
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-126))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      34,    54,    10,   118,     0,   130,   102,     4,    79,     5,
       3,     7,    15,    40,    10,   140,   112,    44,    11,     0,
       3,    55,    75,     6,     7,   121,    97,    14,    11,    12,
      14,   146,    29,     6,     7,    31,     6,     7,    31,    35,
       3,    34,    45,   139,    37,     3,    30,    34,    31,   102,
      84,    34,   123,    13,    37,   180,     3,    30,   129,   112,
      30,     3,     4,   116,    27,   118,    29,    27,   121,    14,
       3,     4,     3,     4,    16,   190,     3,     4,    14,     3,
     114,    77,   153,    16,     0,    16,   139,    29,    27,    34,
      13,     7,    34,   146,    30,    13,    29,    29,    29,    27,
      30,    29,    29,    33,    27,    27,    29,   141,   116,    27,
       3,    29,     5,     6,     7,   149,    23,    24,    27,    12,
      29,    28,   156,    17,    18,    19,    20,    21,    22,    23,
      24,    23,    24,    30,    23,    24,    33,   190,    30,    28,
       3,    23,    24,    23,    24,   179,    28,   181,    28,     3,
      23,    24,    33,    34,   188,    28,     5,     6,     7,    27,
       3,    29,    33,    34,    33,    34,    33,    34,    25,    26,
      25,    26,     6,     7,    14,    23,    24,    18,    19,    31,
      68,    69,    15,    29,    71,    72,    31,    31,    27,    27,
      32,    13,    27,     7,    31,    10,   116,    33,    30,    77,
      28,    32,    32,    32,    30,    32,    30,   181,   188,    34,
      33,    30,    87,    34,    34,    98,    88,    35,    -1,    -1,
      37,    -1,   101
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,    12,    39,    40,    41,    42,
      48,    49,    50,    51,    52,     3,    53,     3,     5,    52,
       0,    41,    42,    49,     3,    58,    59,    27,    54,    33,
      34,    29,    53,    53,    13,    29,    54,    33,    34,     4,
      29,    55,    56,    57,    27,     3,    30,    43,    44,    52,
      34,    34,     3,     4,    16,    29,    65,    66,    67,    71,
      73,    75,    76,    30,    43,     3,    59,    55,    23,    24,
      28,    25,    26,    55,    54,    31,    30,    33,     3,    27,
      29,    77,     3,     4,    29,    76,    65,    14,    15,    17,
      18,    19,    20,    21,    22,    23,    24,    68,    72,    25,
      26,    74,    31,    30,    30,    56,    56,    57,    57,    28,
       3,    11,    31,    34,    37,    47,    48,    52,    60,    61,
      76,    31,    44,    27,    45,    71,    65,    69,    70,    27,
      29,    65,    30,    66,    67,    71,    73,    75,    47,    31,
      29,    29,    47,    34,    65,    32,    60,     3,    61,    13,
      47,    46,    71,    27,    28,    30,    33,    71,    69,    30,
      32,    47,    69,     3,    62,    63,    64,    65,    32,    34,
      65,    32,    28,    71,    65,    28,    30,    32,    30,    13,
      34,    33,    34,    28,    34,    65,    69,    64,    34,    62,
      30,    61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 165 "parser.y"
    { (yyval.node)=Allocate(PROGRAM_NODE);  makeChild((yyval.node),(yyvsp[(1) - (1)].node)); prog=(yyval.node);}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 166 "parser.y"
    { (yyval.node)=Allocate(PROGRAM_NODE); prog=(yyval.node);}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 170 "parser.y"
    {
                        (yyval.node) = makeSibling((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
                    }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 174 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 180 "parser.y"
    {
                    (yyval.node) = makeSibling(makeChild(Allocate(VARIABLE_DECL_LIST_NODE), (yyvsp[(1) - (2)].node)), (yyvsp[(2) - (2)].node));
                }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 184 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 190 "parser.y"
    {
                        (yyval.node) = makeDeclNode(FUNCTION_DECL);
                        AST_NODE* parameterList = Allocate(PARAM_LIST_NODE);
                        makeChild(parameterList, (yyvsp[(4) - (8)].node));
                        makeFamily((yyval.node), 4, (yyvsp[(1) - (8)].node), makeIDNode((yyvsp[(2) - (8)].lexeme), NORMAL_ID), parameterList, (yyvsp[(7) - (8)].node));
                    }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 197 "parser.y"
    {
                        (yyval.node) = makeDeclNode(FUNCTION_DECL);
                        AST_NODE* parameterList = Allocate(PARAM_LIST_NODE);
                        makeChild(parameterList, (yyvsp[(4) - (8)].node));
                        makeFamily((yyval.node), 4, makeIDNode("void", NORMAL_ID), makeIDNode((yyvsp[(2) - (8)].lexeme), NORMAL_ID), parameterList, (yyvsp[(7) - (8)].node));
                    }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 204 "parser.y"
    {
                        (yyval.node) = makeDeclNode(FUNCTION_DECL);
                        AST_NODE* emptyParameterList = Allocate(PARAM_LIST_NODE);
                        makeFamily((yyval.node), 4, (yyvsp[(1) - (7)].node), makeIDNode((yyvsp[(2) - (7)].lexeme), NORMAL_ID), emptyParameterList, (yyvsp[(6) - (7)].node));
                    }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 210 "parser.y"
    {
                        (yyval.node) = makeDeclNode(FUNCTION_DECL);
                        AST_NODE* emptyParameterList = Allocate(PARAM_LIST_NODE);
                        makeFamily((yyval.node), 4, makeIDNode("void", NORMAL_ID), makeIDNode((yyvsp[(2) - (7)].lexeme), NORMAL_ID), emptyParameterList, (yyvsp[(6) - (7)].node));
                    }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 218 "parser.y"
    {
                    (yyval.node) = makeSibling((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 222 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 228 "parser.y"
    {
                    (yyval.node) = makeDeclNode(FUNCTION_PARAMETER_DECL);
                    makeFamily((yyval.node), 2, (yyvsp[(1) - (2)].node), makeIDNode((yyvsp[(2) - (2)].lexeme), NORMAL_ID));
                }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 233 "parser.y"
    {
                    (yyval.node) = makeDeclNode(FUNCTION_PARAMETER_DECL);
					makeFamily((yyval.node), 2, (yyvsp[(1) - (3)].node), makeChild(makeIDNode((yyvsp[(2) - (3)].lexeme), NORMAL_ID), (yyvsp[(3) - (3)].node)));
                }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 239 "parser.y"
    {
                    (yyval.node) = (yyvsp[(2) - (3)].node);
                }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 243 "parser.y"
    {
                    (yyval.node) = makeSibling((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
                }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 249 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 253 "parser.y"
    {
                    (yyval.node) = Allocate(NUL_NODE); 
                }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 259 "parser.y"
    {
                        (yyval.node) = Allocate(BLOCK_NODE);
                        makeChild((yyval.node), makeChild(Allocate(VARIABLE_DECL_LIST_NODE), (yyvsp[(1) - (2)].node)));
						makeSibling((yyval.node)->child, makeChild(Allocate(STMT_LIST_NODE), (yyvsp[(2) - (2)].node)));
                    }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 265 "parser.y"
    {
                        (yyval.node) = Allocate(BLOCK_NODE);
                        makeChild((yyval.node), makeChild(Allocate(STMT_LIST_NODE), (yyvsp[(1) - (1)].node)));
                    }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 270 "parser.y"
    {
                        (yyval.node) = Allocate(BLOCK_NODE);
                        makeChild((yyval.node), makeChild(Allocate(VARIABLE_DECL_LIST_NODE), (yyvsp[(1) - (1)].node)));
                    }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 274 "parser.y"
    {
                        (yyval.node) = Allocate(BLOCK_NODE);
                    }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 280 "parser.y"
    {
                        (yyval.node) = makeSibling((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
                }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 284 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 290 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 294 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 300 "parser.y"
    {
                    (yyval.node) = makeDeclNode(TYPE_DECL);
                    makeChild((yyval.node), (yyvsp[(2) - (4)].node));
					makeSibling((yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node));
                }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 306 "parser.y"
    {
					(yyval.node) = makeDeclNode(TYPE_DECL);
					makeChild((yyval.node), makeSibling( makeIDNode("void", NORMAL_ID), (yyvsp[(3) - (4)].node)));
                }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 313 "parser.y"
    {
					(yyval.node) = makeDeclNode(VARIABLE_DECL);
					makeChild( (yyval.node), (yyvsp[(1) - (3)].node));
					makeSibling( (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node));	
                }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 319 "parser.y"
    {
					(yyval.node) = makeDeclNode(VARIABLE_DECL);
					makeChild((yyval.node), makeSibling( makeIDNode((yyvsp[(1) - (3)].lexeme), NORMAL_ID), (yyvsp[(2) - (3)].node)));
                }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 326 "parser.y"
    {
                    (yyval.node) = makeIDNode("int", NORMAL_ID);  
                }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 330 "parser.y"
    {
                    (yyval.node) = makeIDNode("float", NORMAL_ID);
                }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 336 "parser.y"
    {
                    (yyval.node) = makeIDNode((yyvsp[(1) - (1)].lexeme), NORMAL_ID);
                }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 340 "parser.y"
    {
					(yyval.node) = makeSibling((yyvsp[(1) - (3)].node), makeIDNode((yyvsp[(3) - (3)].lexeme), NORMAL_ID));
                }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 344 "parser.y"
    {
					
					(yyval.node) = makeSibling((yyvsp[(1) - (4)].node), makeIDNode((yyvsp[(3) - (4)].lexeme), ARRAY_ID));
					makeChild((yyval.node), (yyvsp[(4) - (4)].node));
                }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 350 "parser.y"
    {
                    (yyval.node) = makeChild( makeIDNode((yyvsp[(1) - (2)].lexeme), ARRAY_ID), (yyvsp[(2) - (2)].node));
                }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 355 "parser.y"
    {
                    (yyval.node) = (yyvsp[(2) - (3)].node);
                }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 359 "parser.y"
    {
					(yyval.node) = makeSibling((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
				}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 366 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_ADD);
                    makeFamily((yyval.node), 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 371 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_SUB);
                    makeFamily((yyval.node), 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 376 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 381 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_MUL);
                    makeFamily((yyval.node), 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 386 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_DIV);
                    makeFamily((yyval.node), 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 391 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 397 "parser.y"
    {
                    (yyval.node) = Allocate(CONST_VALUE_NODE);
                    (yyval.node)->semantic_value.const1=(yyvsp[(1) - (1)].const1);
                }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 402 "parser.y"
    {
                    (yyval.node) = (yyvsp[(2) - (3)].node);
                }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 408 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 412 "parser.y"
    {
                        (yyval.node) = makeSibling((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                    }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 418 "parser.y"
    {
                    (yyval.node) = makeIDNode((yyvsp[(1) - (1)].lexeme), NORMAL_ID);
                }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 422 "parser.y"
    {
					(yyval.node) = makeChild(makeIDNode((yyvsp[(1) - (2)].lexeme), NORMAL_ID), (yyvsp[(2) - (2)].node));
                }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 426 "parser.y"
    {
					(yyval.node) = makeChild(makeIDNode((yyvsp[(1) - (3)].lexeme), NORMAL_ID), (yyvsp[(3) - (3)].node));
                }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 432 "parser.y"
    {
					(yyval.node) = makeSibling((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
                }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 436 "parser.y"
    {
					(yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 444 "parser.y"
    {
					(yyval.node) = Allocate(STMT_NODE);
					makeChild((yyval.node), (yyvsp[(2) - (3)].node));
                }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 450 "parser.y"
    {
					(yyval.node) = Allocate(STMT_NODE);
					makeFamily((yyval.node), 5,makeStmtNode(FOR_STMT), (yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node));
                }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 455 "parser.y"
    {
					(yyval.node) = Allocate(STMT_NODE);
					makeFamily((yyval.node), 2, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
                }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 464 "parser.y"
    {	
					(yyval.node) = makeStmtNode(FUNCTION_CALL_STMT);
					makeChild((yyval.node), makeSibling(makeIDNode((yyvsp[(1) - (5)].lexeme), NORMAL_ID), (yyvsp[(3) - (5)].node)));
				}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 471 "parser.y"
    {
					(yyval.node) = Allocate(STMT_NODE);
                }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 475 "parser.y"
    {
					(yyval.node) = makeStmtNode(RETURN_STMT);
                }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 479 "parser.y"
    {
					(yyval.node) = makeStmtNode(RETURN_STMT);
					makeChild((yyval.node), (yyvsp[(2) - (3)].node));
                }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 486 "parser.y"
    {
					 	 (yyval.node) = (yyvsp[(1) - (1)].node);	
                     }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 490 "parser.y"
    {
                         (yyval.node) = Allocate(NUL_NODE); 
                     }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 496 "parser.y"
    {
										(yyval.node) = (yyvsp[(1) - (3)].node);
										makeSibling((yyval.node), (yyvsp[(3) - (3)].node));
                                    }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 501 "parser.y"
    {
                                        (yyval.node) = makeChild(Allocate(NONEMPTY_ASSIGN_EXPR_LIST_NODE), (yyvsp[(1) - (1)].node));
                                    }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 513 "parser.y"
    {
						(yyval.node) = makeSibling( makeIDNode((yyvsp[(1) - (3)].lexeme), NORMAL_ID), (yyvsp[(3) - (3)].node));
                    }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 517 "parser.y"
    {
						(yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 523 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 527 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_OR);
                    makeFamily((yyval.node), 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 534 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 538 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_AND);
                    makeFamily((yyval.node), 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 545 "parser.y"
    {
						(yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 549 "parser.y"
    {
						(yyval.node) = (yyvsp[(2) - (3)].node);
						makeFamily((yyval.node), 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                    }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 556 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_EQ);
                }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 560 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_GE);
                }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 564 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_LE);
                }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 568 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_NE);
                }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 572 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_GT);
                }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 576 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_LT);
                }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 583 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                    }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 587 "parser.y"
    {
                        (yyval.node) = Allocate(NUL_NODE);
                    }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 593 "parser.y"
    {
                                    (yyval.node) = (yyvsp[(1) - (3)].node);
									makeSibling((yyval.node)->child, (yyvsp[(3) - (3)].node));
                                }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 598 "parser.y"
    {
                                    (yyval.node) = Allocate(NONEMPTY_RELOP_EXPR_LIST_NODE);
									makeChild((yyval.node), (yyvsp[(1) - (1)].node));
                                }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 605 "parser.y"
    {
					(yyval.node) = (yyvsp[(2) - (3)].node);
					makeChild((yyval.node), (yyvsp[(1) - (3)].node));
                    makeSibling((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 611 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 617 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_ADD);
                }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 621 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_SUB);
                }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 627 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (3)].node);
					makeSibling((yyval.node), (yyvsp[(2) - (3)].node));
					makeSibling((yyval.node), (yyvsp[(3) - (3)].node));
                }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 633 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 639 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_MUL);
                }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 643 "parser.y"
    {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_DIV);
                }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 649 "parser.y"
    {
                    (yyval.node) = (yyvsp[(2) - (3)].node);
                }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 654 "parser.y"
    {   
                    (yyval.node) = makeExprNode(UNARY_OPERATION, UNARY_OP_NEGATIVE);
                   	makeChild((yyval.node), (yyvsp[(3) - (4)].node)); 
                }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 659 "parser.y"
    {
                    (yyval.node) = Allocate(CONST_VALUE_NODE);
                    (yyval.node)->semantic_value.const1=(yyvsp[(1) - (1)].const1);
                }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 665 "parser.y"
    {
                    (yyval.node) = makeExprNode(UNARY_OPERATION, UNARY_OP_NEGATIVE);
					makeChild((yyval.node), Allocate(CONST_VALUE_NODE));
					(yyval.node)->child->semantic_value.const1 = (yyvsp[(2) - (2)].const1); 
                }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 671 "parser.y"
    {
                    (yyval.node) = makeIDNode((yyvsp[(1) - (4)].lexeme), NORMAL_ID);
					makeSibling((yyval.node), (yyvsp[(3) - (4)].node));
                }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 677 "parser.y"
    {
                    (yyval.node) = makeExprNode(UNARY_OPERATION, UNARY_OP_NEGATIVE);
					makeSibling( makeChild((yyval.node), makeIDNode((yyvsp[(2) - (5)].lexeme), NORMAL_ID)), (yyvsp[(4) - (5)].node));
                }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 682 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 687 "parser.y"
    {
                    (yyval.node) = makeExprNode(UNARY_OPERATION, UNARY_OP_NEGATIVE);
					makeSibling((yyval.node), (yyvsp[(2) - (2)].node));
                }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 694 "parser.y"
    {
                    (yyval.node) = makeIDNode((yyvsp[(1) - (1)].lexeme), NORMAL_ID);
                }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 698 "parser.y"
    {
                    (yyval.node) = makeIDNode((yyvsp[(1) - (2)].lexeme), NORMAL_ID);
                   	makeSibling((yyval.node), (yyvsp[(2) - (2)].node)); 
                }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 706 "parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (4)].node);
					makeSibling((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node));
                }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 711 "parser.y"
    {
                    (yyval.node) = (yyvsp[(2) - (3)].node);
                }
    break;



/* Line 1806 of yacc.c  */
#line 2646 "parser.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 717 "parser.y"


#include "lex.yy.c"
main (argc, argv)
int argc;
char *argv[];
  {
     yyin = fopen(argv[1],"r");
     yyparse();
	 printf("%s\n", "Parsing completed. No errors found.");
	 printGV(prog, NULL);
  } /* main */


int yyerror (mesg)
char *mesg;
  {
  printf("%s\t%d\t%s\t%s\n", "Error found in Line ", linenumber, "next token: ", yytext );
  exit(1);
  }

