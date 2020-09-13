/* A Bison parser, made by GNU Bison 2.0.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse dnayyparse
#define yylex   dnayylex
#define yyerror dnayyerror
#define yylval  dnayylval
#define yychar  dnayychar
#define yydebug dnayydebug
#define yynerrs dnayynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     STRING = 259,
     FRONT_DOOR_POINT_ = 260,
     SIDE_DOOR_POINT_ = 261,
     STREET_POINT_ = 262,
     COGHQ_IN_POINT_ = 263,
     COGHQ_OUT_POINT_ = 264,
     ARTICLE = 265,
     BATTLE_CELL = 266,
     CODE = 267,
     COLOR = 268,
     COUNT = 269,
     CORNICE = 270,
     DOOR = 271,
     FLAT_BUILDING = 272,
     FLAT_DOOR = 273,
     DNAGROUP = 274,
     HEIGHT = 275,
     HOOD_MODEL = 276,
     BUILDING_TYPE = 277,
     PLACE_MODEL = 278,
     HPR = 279,
     NHPR = 280,
     LANDMARK_BUILDING = 281,
     MODEL = 282,
     NODE = 283,
     POS = 284,
     PROP = 285,
     SCALE = 286,
     SIGN = 287,
     BASELINE = 288,
     INDENT = 289,
     KERN = 290,
     WIGGLE = 291,
     STUMBLE = 292,
     FLAGS = 293,
     STOMP = 294,
     TEXT_ = 295,
     LETTERS = 296,
     GRAPHIC = 297,
     STORE_FONT = 298,
     STORE_NODE = 299,
     STORE_TEXTURE = 300,
     STREET = 301,
     SUIT_EDGE = 302,
     STORE_SUIT_POINT = 303,
     TEXTURE = 304,
     TITLE = 305,
     VIS = 306,
     VISGROUP = 307,
     WALL = 308,
     WIDTH = 309,
     WINDOWS = 310
   };
#endif
#define NUMBER 258
#define STRING 259
#define FRONT_DOOR_POINT_ 260
#define SIDE_DOOR_POINT_ 261
#define STREET_POINT_ 262
#define COGHQ_IN_POINT_ 263
#define COGHQ_OUT_POINT_ 264
#define ARTICLE 265
#define BATTLE_CELL 266
#define CODE 267
#define COLOR 268
#define COUNT 269
#define CORNICE 270
#define DOOR 271
#define FLAT_BUILDING 272
#define FLAT_DOOR 273
#define DNAGROUP 274
#define HEIGHT 275
#define HOOD_MODEL 276
#define BUILDING_TYPE 277
#define PLACE_MODEL 278
#define HPR 279
#define NHPR 280
#define LANDMARK_BUILDING 281
#define MODEL 282
#define NODE 283
#define POS 284
#define PROP 285
#define SCALE 286
#define SIGN 287
#define BASELINE 288
#define INDENT 289
#define KERN 290
#define WIGGLE 291
#define STUMBLE 292
#define FLAGS 293
#define STOMP 294
#define TEXT_ 295
#define LETTERS 296
#define GRAPHIC 297
#define STORE_FONT 298
#define STORE_NODE 299
#define STORE_TEXTURE 300
#define STREET 301
#define SUIT_EDGE 302
#define STORE_SUIT_POINT 303
#define TEXTURE 304
#define TITLE 305
#define VIS 306
#define VISGROUP 307
#define WALL 308
#define WIDTH 309
#define WINDOWS 310




/* Copy the first part of user declarations.  */
#line 6 "parser.yxx"


#include "toontownbase.h"
#include "parserDefs.h"
#include "lexerDefs.h"
#include "dnaLoader.h"
#include "dnaGroup.h"
#include "dnaVisGroup.h"
#include "dnaData.h"
#include "dnaNode.h"
#include "dnaProp.h"
#include "dnaBuildings.h"
#include "dnaCornice.h"
#include "dnaStreet.h"
#include "dnaWindow.h"
#include "dnaDoor.h"
#include "dnaSign.h"
#include "dnaSignBaseline.h"
#include "dnaSignGraphic.h"
#include "dnaSignText.h"
#include "dnaSuitPoint.h"
#include "dnaSuitEdge.h"
#include "dnaBattleCell.h"

#include "pandaNode.h"
#include "texture.h"
#include "fontPool.h"
#include "texturePool.h"
#include "loader.h"
#include "compose_matrix.h"
#include "config_linmath.h"
#include "dcast.h"

#include "string_utils.h"
#include "pvector.h"
#include "parser.h"

////////////////////////////////////////////////////////////////////
// Defining the interface to the parser.
////////////////////////////////////////////////////////////////////



// We need a stack of DnaGroup pointers.  Each time we encounter a
// nested DnaGroup of some kind, we'll allocate a new one of these
// and push it onto the stack.  At any given time, the top of the
// stack is the DnaGroup we are currently scanning.

typedef pvector<PT(DNAGroup)> DNAStack;
static DNAStack dna_stack;

// There's one "top-level" dna node
static DNAData* dna_top_node;

// Keep track of the current vis group/zone name:
static std::string g_current_zone_name;

static NodePath current_model;
static int current_model_hood;
static int current_model_place;

// Create a loader so we can load models
static Loader loader;

void
dna_init_parser(std::istream &in,
                std::ostream &err,
                const std::string &filename,
                DNAData* top_node) {
  dna_init_lexer(in, err, filename);

  dna_stack.clear();
  dna_stack.push_back(top_node);
  dna_top_node = top_node;
}

void
dna_cleanup_parser() {
  // Clean these out after we're done, so we don't keep big memory
  // structures around needlessly.
  dna_stack.clear();
  current_model = NodePath();
  dna_top_node = NULL;
}


#define yyvsp dnayyvsp



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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 213 of yacc.c.  */
#line 294 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   540

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  107
/* YYNRULES -- Number of rules. */
#define YYNRULES  202
/* YYNRULES -- Number of states. */
#define YYNSTATES  444

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    58,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    13,    15,    17,    19,
      21,    23,    25,    28,    30,    32,    34,    36,    38,    40,
      42,    44,    46,    48,    50,    52,    53,    60,    62,    63,
      70,    75,    80,    82,    85,    87,    90,    96,    98,   101,
     110,   111,   118,   123,   125,   126,   133,   139,   141,   144,
     145,   151,   153,   156,   158,   160,   162,   168,   173,   178,
     179,   186,   195,   206,   214,   223,   233,   244,   253,   264,
     272,   282,   283,   289,   293,   294,   300,   303,   304,   310,
     313,   314,   321,   323,   326,   328,   330,   332,   334,   336,
     338,   341,   342,   348,   351,   353,   356,   358,   360,   362,
     364,   366,   368,   370,   372,   374,   376,   378,   380,   385,
     387,   389,   392,   395,   396,   402,   404,   407,   409,   411,
     413,   415,   417,   419,   421,   422,   428,   430,   433,   435,
     437,   439,   441,   443,   445,   450,   455,   460,   465,   470,
     475,   476,   482,   485,   486,   493,   500,   508,   517,   528,
     530,   533,   534,   541,   545,   550,   555,   561,   566,   572,
     578,   585,   590,   595,   600,   605,   607,   612,   619,   626,
     633,   640,   648,   653,   654,   661,   662,   669,   670,   677,
     679,   682,   689,   695,   702,   709,   718,   728,   739,   752,
     754,   756,   758,   760,   762,   764,   766,   768,   770,   772,
     774,   776,   778
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
      60,     0,    -1,    61,    63,    -1,   165,    -1,    61,    62,
      -1,   148,    -1,   150,    -1,   152,    -1,   156,    -1,   157,
      -1,   158,    -1,   165,    -1,    63,    64,    -1,    65,    -1,
      68,    -1,    77,    -1,    80,    -1,    91,    -1,   131,    -1,
     135,    -1,   128,    -1,    97,    -1,   100,    -1,    84,    -1,
      94,    -1,    -1,    19,   160,    56,    66,    67,    57,    -1,
      63,    -1,    -1,    52,   160,    56,    69,    70,    57,    -1,
      71,    73,    75,    63,    -1,    51,    56,    72,    57,    -1,
     162,    -1,    72,   162,    -1,   165,    -1,    73,    74,    -1,
      47,    56,   164,   164,    57,    -1,   165,    -1,    75,    76,
      -1,    11,    56,   163,   163,   163,   163,   163,    57,    -1,
      -1,    28,   160,    56,    78,    79,    57,    -1,   143,   144,
     145,    63,    -1,    63,    -1,    -1,    17,   160,    56,    81,
      82,    57,    -1,   143,   144,    89,    83,   134,    -1,   165,
      -1,    83,    84,    -1,    -1,    53,    56,    85,    88,    57,
      -1,   165,    -1,    86,    87,    -1,    94,    -1,   128,    -1,
     100,    -1,    90,   138,   146,    86,   134,    -1,    54,    56,
     163,    57,    -1,    20,    56,   163,    57,    -1,    -1,    26,
     160,    56,    92,    93,    57,    -1,   138,   141,   140,   143,
     144,   146,    97,   134,    -1,   138,   141,   140,   143,   144,
     146,    97,   134,   103,   134,    -1,   138,   141,   140,   143,
     144,    97,   134,    -1,   138,   142,   141,   140,   143,   144,
      97,   134,    -1,   138,   141,   140,   143,   144,    97,   134,
     103,   134,    -1,   138,   142,   141,   140,   143,   144,    97,
     134,   103,   134,    -1,   138,   142,   141,   140,   143,   144,
     146,   134,    -1,   138,   142,   141,   140,   143,   144,   146,
     134,   103,   134,    -1,   138,   142,   141,   140,   143,   144,
     134,    -1,   138,   142,   141,   140,   143,   144,   134,   103,
     134,    -1,    -1,    55,    56,    95,    96,    57,    -1,   138,
     146,   139,    -1,    -1,    16,    56,    98,    99,    57,    -1,
     138,   146,    -1,    -1,    18,    56,   101,   102,    57,    -1,
     138,   146,    -1,    -1,    32,    56,   104,   105,   107,    57,
      -1,   165,    -1,   105,   106,    -1,   138,    -1,   146,    -1,
     143,    -1,   144,    -1,   145,    -1,   165,    -1,   107,   108,
      -1,    -1,    33,    56,   109,   110,    57,    -1,   111,   113,
      -1,   165,    -1,   111,   112,    -1,   138,    -1,   146,    -1,
     143,    -1,   144,    -1,   145,    -1,   123,    -1,   124,    -1,
     125,    -1,   126,    -1,   127,    -1,    89,    -1,    90,    -1,
      38,    56,   161,    57,    -1,   118,    -1,   114,    -1,   113,
     118,    -1,   113,   114,    -1,    -1,    42,    56,   115,   116,
      57,    -1,   117,    -1,   116,   117,    -1,   145,    -1,   143,
      -1,   144,    -1,   138,    -1,   146,    -1,    89,    -1,    90,
      -1,    -1,    40,    56,   119,   120,    57,    -1,   121,    -1,
     120,   121,    -1,   145,    -1,   143,    -1,   144,    -1,   138,
      -1,   146,    -1,   122,    -1,    41,    56,   161,    57,    -1,
      34,    56,   163,    57,    -1,    35,    56,   163,    57,    -1,
      36,    56,   163,    57,    -1,    37,    56,   163,    57,    -1,
      39,    56,   163,    57,    -1,    -1,    15,    56,   129,   130,
      57,    -1,   138,   146,    -1,    -1,    46,   160,    56,   132,
     133,    57,    -1,   138,   143,   144,   147,   147,   134,    -1,
     138,   143,   144,   147,   147,   147,   134,    -1,   138,   143,
     144,   146,   146,   147,   147,   134,    -1,   138,   143,   144,
     146,   146,   146,   147,   147,   147,   134,    -1,   165,    -1,
     134,   135,    -1,    -1,    30,   160,    56,   136,   137,    57,
      -1,   138,   143,   144,    -1,   138,   143,   144,   145,    -1,
     138,   143,   144,   146,    -1,   138,   143,   144,   145,   146,
      -1,   138,   143,   144,   103,    -1,   138,   143,   144,   145,
     103,    -1,   138,   143,   144,   146,   103,    -1,   138,   143,
     144,   145,   146,   103,    -1,    12,    56,   161,    57,    -1,
      14,    56,   164,    57,    -1,    50,    56,   161,    57,    -1,
      10,    56,   161,    57,    -1,   165,    -1,    22,    56,   162,
      57,    -1,    29,    56,   163,   163,   163,    57,    -1,    25,
      56,   163,   163,   163,    57,    -1,    24,    56,   163,   163,
     163,    57,    -1,    31,    56,   163,   163,   163,    57,    -1,
      13,    56,   163,   163,   163,   163,    57,    -1,    49,    56,
     161,    57,    -1,    -1,    27,   161,    56,   149,   154,    57,
      -1,    -1,    21,   161,    56,   151,   154,    57,    -1,    -1,
      23,   161,    56,   153,   154,    57,    -1,   165,    -1,   154,
     155,    -1,    44,    56,   162,   162,   162,    57,    -1,    44,
      56,   162,   162,    57,    -1,    45,    56,   162,   162,   162,
      57,    -1,    43,    56,   162,   162,   162,    57,    -1,    48,
      56,   164,   164,   163,   163,   163,    57,    -1,    48,    56,
     164,   164,   163,   163,   163,   164,    57,    -1,    48,    56,
     164,    58,   159,    58,   163,   163,   163,    57,    -1,    48,
      56,   164,    58,   159,    58,   163,   163,   163,    58,   164,
      57,    -1,     5,    -1,     6,    -1,     7,    -1,     8,    -1,
       9,    -1,   165,    -1,   162,    -1,   165,    -1,   162,    -1,
       3,    -1,     4,    -1,     3,    -1,     3,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   157,   157,   161,   162,   166,   167,   168,   169,   170,
     171,   175,   176,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   200,   199,   211,   220,   219,
     239,   246,   253,   258,   266,   267,   275,   295,   296,   303,
     322,   321,   333,   340,   348,   347,   359,   369,   370,   375,
     374,   388,   389,   393,   394,   395,   399,   409,   416,   425,
     424,   439,   449,   459,   468,   482,   491,   505,   520,   535,
     549,   567,   566,   580,   591,   590,   604,   616,   615,   629,
     641,   640,   654,   655,   659,   664,   669,   674,   679,   687,
     688,   693,   692,   706,   710,   711,   715,   720,   725,   730,
     735,   740,   741,   742,   743,   744,   745,   750,   755,   763,
     764,   765,   766,   771,   770,   783,   784,   788,   793,   798,
     803,   808,   813,   818,   827,   826,   839,   840,   844,   849,
     854,   859,   864,   869,   877,   884,   892,   900,   908,   916,
     925,   924,   938,   948,   947,   959,   970,   980,   995,  1011,
    1012,  1021,  1020,  1032,  1039,  1047,  1055,  1064,  1071,  1079,
    1087,  1099,  1106,  1113,  1120,  1124,  1131,  1138,  1148,  1157,
    1168,  1175,  1182,  1195,  1194,  1212,  1211,  1231,  1230,  1247,
    1248,  1253,  1288,  1312,  1328,  1350,  1359,  1369,  1376,  1388,
    1392,  1396,  1400,  1404,  1419,  1424,  1437,  1442,  1456,  1460,
    1472,  1483,  1519
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "STRING", "FRONT_DOOR_POINT_",
  "SIDE_DOOR_POINT_", "STREET_POINT_", "COGHQ_IN_POINT_",
  "COGHQ_OUT_POINT_", "ARTICLE", "BATTLE_CELL", "CODE", "COLOR", "COUNT",
  "CORNICE", "DOOR", "FLAT_BUILDING", "FLAT_DOOR", "DNAGROUP", "HEIGHT",
  "HOOD_MODEL", "BUILDING_TYPE", "PLACE_MODEL", "HPR", "NHPR",
  "LANDMARK_BUILDING", "MODEL", "NODE", "POS", "PROP", "SCALE", "SIGN",
  "BASELINE", "INDENT", "KERN", "WIGGLE", "STUMBLE", "FLAGS", "STOMP",
  "TEXT_", "LETTERS", "GRAPHIC", "STORE_FONT", "STORE_NODE",
  "STORE_TEXTURE", "STREET", "SUIT_EDGE", "STORE_SUIT_POINT", "TEXTURE",
  "TITLE", "VIS", "VISGROUP", "WALL", "WIDTH", "WINDOWS", "'['", "']'",
  "','", "$accept", "top", "load_list", "load", "internal_node_list",
  "internal_node", "group", "@1", "group_body", "visgroup", "@2",
  "visgroup_body", "vis", "vis_list", "suit_edge_list", "suit_edge",
  "battle_cell_list", "battle_cell", "node", "@3", "node_body",
  "flat_building", "@4", "flat_building_body", "wall_list", "wall", "@5",
  "wall_node_list", "wall_node", "wall_body", "width", "height",
  "landmark_building", "@6", "landmark_building_body", "windows", "@7",
  "windows_body", "door", "@8", "door_body", "flat_door", "@9",
  "flat_door_body", "sign", "@10", "sign_list", "sign_node",
  "baseline_list", "baseline", "@11", "baseline_body",
  "baseline_body_node_list", "baseline_body_node", "text_list",
  "sign_graphic", "@12", "graphic_node_list", "sign_graphic_node",
  "sign_text", "@13", "text_node_list", "text_node", "letters",
  "baseline_indent", "baseline_kern", "baseline_wiggle",
  "baseline_stumble", "baseline_stomp", "cornice", "@14", "cornice_body",
  "street", "@15", "street_body", "prop_list", "prop", "@16", "prop_body",
  "code", "count", "title", "article", "building_type", "pos", "hpr",
  "scale", "color", "texture", "model", "@17", "hood_model", "@18",
  "place_model", "@19", "store_node_list", "store_node", "store_texture",
  "store_font", "store_suit_point", "suit_point_type", "required_name",
  "required_string", "string", "real", "integer", "empty", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    91,    93,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    66,    65,    67,    69,    68,
      70,    71,    72,    72,    73,    73,    74,    75,    75,    76,
      78,    77,    79,    79,    81,    80,    82,    83,    83,    85,
      84,    86,    86,    87,    87,    87,    88,    89,    90,    92,
      91,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    95,    94,    96,    98,    97,    99,   101,   100,   102,
     104,   103,   105,   105,   106,   106,   106,   106,   106,   107,
     107,   109,   108,   110,   111,   111,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   113,
     113,   113,   113,   115,   114,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   119,   118,   120,   120,   121,   121,
     121,   121,   121,   121,   122,   123,   124,   125,   126,   127,
     129,   128,   130,   132,   131,   133,   133,   133,   133,   134,
     134,   136,   135,   137,   137,   137,   137,   137,   137,   137,
     137,   138,   139,   140,   141,   141,   142,   143,   144,   144,
     145,   146,   147,   149,   148,   151,   150,   153,   152,   154,
     154,   155,   155,   156,   157,   158,   158,   158,   158,   159,
     159,   159,   159,   159,   160,   160,   161,   161,   162,   162,
     163,   164,   165
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     1,     0,     6,
       4,     4,     1,     2,     1,     2,     5,     1,     2,     8,
       0,     6,     4,     1,     0,     6,     5,     1,     2,     0,
       5,     1,     2,     1,     1,     1,     5,     4,     4,     0,
       6,     8,    10,     7,     8,     9,    10,     8,    10,     7,
       9,     0,     5,     3,     0,     5,     2,     0,     5,     2,
       0,     6,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     0,     5,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     2,     2,     0,     5,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     1,     2,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       0,     5,     2,     0,     6,     6,     7,     8,    10,     1,
       2,     0,     6,     3,     4,     4,     5,     4,     5,     5,
       6,     4,     4,     4,     4,     1,     4,     6,     6,     6,
       6,     7,     4,     0,     6,     0,     6,     0,     6,     1,
       2,     6,     5,     6,     6,     8,     9,    10,    12,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
     202,     0,   202,     3,     1,   202,   202,   202,     0,     0,
       0,     4,     2,     5,     6,     7,     8,     9,    10,    11,
     198,   199,     0,   197,   196,     0,     0,     0,     0,     0,
       0,     0,   202,     0,   202,   202,   202,   202,   202,   202,
       0,     0,    12,    13,    14,    15,    16,    23,    17,    24,
      21,    22,    20,    18,    19,   175,   177,   173,     0,     0,
     201,     0,   140,    74,     0,   195,   194,    77,     0,     0,
       0,     0,     0,     0,    49,    71,   202,   202,   202,     0,
       0,     0,     0,     0,     0,    44,     0,    25,    59,    40,
     151,   143,    28,     0,     0,     0,   179,     0,     0,     0,
       0,   189,   190,   191,   192,   193,     0,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     0,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
     180,   178,   174,   184,   183,     0,     0,   202,   141,     0,
     142,    75,    76,     0,     0,     0,    78,    79,    27,     0,
       0,   202,    43,     0,     0,     0,     0,     0,     0,     0,
       0,   202,     0,    50,     0,    72,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,    26,    60,     0,
       0,     0,   202,   165,    41,     0,   152,     0,   144,     0,
       0,    29,   202,    34,     0,   202,     0,    73,     0,     0,
     185,     0,   161,     0,     0,     0,     0,     0,   202,   202,
       0,     0,     0,     0,     0,   202,   153,     0,     0,    32,
       0,    35,   202,    37,    58,   202,    51,     0,     0,     0,
     186,     0,     0,     0,     0,     0,   202,    47,     0,     0,
     202,     0,     0,     0,    42,     0,   157,   154,   155,     0,
       0,     0,    31,    33,     0,     0,    30,    38,    52,    53,
      55,    54,    56,   149,     0,   182,     0,   187,     0,     0,
       0,     0,     0,     0,    48,    46,   164,   166,     0,     0,
       0,     0,    80,   158,   156,   159,   202,     0,   202,     0,
       0,   150,   162,   181,     0,     0,   167,     0,     0,    57,
     163,   202,     0,   202,     0,   202,   160,     0,     0,     0,
     145,   202,     0,     0,   188,   171,   169,   168,    63,   202,
     202,    69,   202,     0,   202,    82,   172,     0,   202,   146,
      36,     0,   202,    61,    64,   202,    67,   170,    83,     0,
      84,    86,    87,    88,    85,    89,     0,   147,     0,    65,
     202,   202,    70,   202,     0,    81,    90,   202,     0,    62,
      66,    68,    91,   148,     0,   202,    39,     0,     0,    94,
      92,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,    95,    93,   110,   109,   101,   102,   103,   104,   105,
      96,    98,    99,   100,    97,     0,     0,     0,     0,   202,
       0,   124,   113,   112,   111,     0,     0,     0,     0,     0,
       0,     0,     0,   135,   136,   137,   138,   108,   139,     0,
       0,   126,   133,   131,   129,   130,   128,   132,   122,   123,
       0,   115,   120,   118,   119,   117,   121,   202,   125,   127,
     114,   116,     0,   134
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,     2,    11,    12,    42,    43,   117,   149,    44,
     122,   160,   161,   218,   192,   221,   222,   257,    45,   119,
     153,    46,   114,   144,   236,    47,    93,   225,   258,   124,
     428,   429,    48,   118,   150,    49,    94,   126,    50,    84,
     112,    51,    86,   115,   246,   305,   324,   338,   339,   356,
     365,   367,   368,   381,   382,   383,   412,   430,   431,   384,
     411,   420,   421,   422,   385,   386,   387,   388,   389,    52,
      83,   110,    53,   121,   157,   262,   291,   120,   155,   423,
     197,   212,   181,   182,   424,   425,   426,   427,   251,    13,
      78,    14,    76,    15,    77,    95,   130,    16,    17,    18,
     106,    64,    22,    23,   108,    61,   263
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -251
static const short int yypact[] =
{
    -251,    27,    62,  -251,  -251,    68,    68,    68,   -25,    -7,
      36,  -251,   465,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,    52,  -251,  -251,    66,    85,    68,    68,   145,
     103,   104,    68,   106,    68,    68,    68,    68,    68,    68,
     108,   110,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,    68,    68,
    -251,    15,  -251,  -251,   113,  -251,  -251,  -251,   123,   124,
     125,   129,   131,   138,  -251,  -251,  -251,  -251,  -251,    68,
      68,   191,   190,   189,   189,  -251,   189,  -251,  -251,  -251,
    -251,  -251,  -251,   183,   189,    54,  -251,    86,   101,   147,
     154,  -251,  -251,  -251,  -251,  -251,   155,  -251,   190,   156,
     157,   212,   170,   212,   200,   173,   212,  -251,   189,   200,
     189,   189,   182,   178,   179,   189,   181,   212,   185,  -251,
    -251,  -251,  -251,  -251,  -251,   190,   190,    68,  -251,   186,
    -251,  -251,  -251,   196,   198,    72,  -251,  -251,   465,   202,
     206,   117,   465,   207,    72,   211,   200,   214,   200,   197,
     215,  -251,   190,  -251,   212,  -251,   221,    68,   190,    17,
     220,   190,   190,  -251,   223,   225,   193,  -251,  -251,   226,
     231,   238,   229,  -251,  -251,   260,  -251,    72,  -251,    72,
      68,  -251,   245,  -251,   237,  -251,   239,  -251,    68,   190,
    -251,   242,  -251,   190,   190,   190,   190,   244,  -251,    68,
      68,   246,   200,   238,   248,  -251,    48,    10,    37,  -251,
     251,  -251,   297,  -251,  -251,     7,  -251,   145,    44,    45,
    -251,   190,   190,   190,   190,   190,   257,  -251,   255,   256,
      68,    72,   200,   190,   465,   259,  -251,    43,   285,   262,
     212,   270,  -251,  -251,   145,   264,   465,  -251,  -251,  -251,
    -251,  -251,   291,  -251,   265,  -251,   266,  -251,   145,   190,
     268,   190,   190,   269,  -251,   291,  -251,  -251,   271,    41,
      72,   190,  -251,  -251,   285,  -251,    68,    10,   270,   145,
     190,  -251,  -251,  -251,   273,   274,  -251,   277,   278,  -251,
    -251,  -251,   322,    41,   190,  -251,  -251,   284,   270,   270,
     291,  -251,   288,   190,  -251,  -251,  -251,  -251,    34,  -251,
    -251,    34,  -251,   295,   272,  -251,  -251,   270,  -251,   291,
    -251,   190,  -251,    34,    34,  -251,    34,  -251,  -251,    11,
    -251,  -251,  -251,  -251,  -251,  -251,   270,   291,   190,   291,
    -251,  -251,   291,  -251,   286,  -251,  -251,  -251,   190,   291,
     291,   291,  -251,   291,   296,  -251,  -251,   299,   434,  -251,
    -251,   298,   301,   302,   303,   304,   305,   306,   307,  -251,
    -251,  -251,    25,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,   190,   190,   190,   190,    68,
     190,  -251,  -251,  -251,  -251,   309,   310,   311,   315,   316,
     317,   219,   111,  -251,  -251,  -251,  -251,  -251,  -251,   308,
     249,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
      75,  -251,  -251,  -251,  -251,  -251,  -251,    68,  -251,  -251,
    -251,  -251,   318,  -251
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -251,  -251,  -251,  -251,   -89,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,   133,  -251,  -251,  -251,  -251,
    -163,   -92,  -251,  -251,  -251,   151,  -251,  -251,  -250,  -251,
    -251,   152,  -251,  -251,  -166,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,    -4,  -251,  -251,   -51,     4,
    -251,  -251,   -36,  -251,  -251,  -251,  -251,  -251,  -251,   162,
    -251,  -251,  -251,  -251,  -251,   100,     2,  -251,  -251,   -75,
    -251,   176,   208,  -251,   -98,  -103,  -161,  -101,  -218,  -251,
    -251,  -251,  -251,  -251,  -251,    35,  -251,  -251,  -251,  -251,
    -251,   137,    -3,   312,   -15,   -44,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short int yytable[] =
{
       3,   125,    19,    25,    26,    24,    24,    24,   111,   113,
     140,   116,   142,   208,    54,   147,   145,    82,    60,   127,
      60,   154,    30,   139,   215,    33,   166,     4,   148,   301,
     152,    27,    66,   288,    66,    66,    66,    66,    66,    66,
      20,    21,   176,   151,   354,   156,   158,    20,    21,    28,
     164,   185,   319,   320,   139,   247,   139,    31,   187,   249,
     189,   139,    41,   195,    37,   377,   245,   378,   355,   309,
     311,    20,    21,    81,   200,   245,    96,    96,    96,   214,
     245,   283,   285,     5,   216,     6,   217,   109,   139,     7,
     327,   328,    29,   136,   252,   123,   174,   175,   128,   174,
     175,   265,   267,   268,   143,     8,   214,     9,    55,   346,
      10,   129,    97,    98,   241,   248,   250,    19,   306,    19,
     168,   169,    56,   109,   139,   201,   244,   179,   357,   207,
     128,   123,   440,   256,   170,   174,   175,    24,   279,   180,
     143,    57,   214,   131,   280,   128,   284,   194,    60,   287,
      54,   183,   332,   199,    54,   335,   203,   204,   132,    62,
      63,   193,    67,   343,    74,   207,    75,   350,   351,    85,
     353,    68,    69,    70,    71,    72,    73,   303,   302,    87,
      88,    89,   183,   264,   229,    90,   308,    91,   231,   232,
     233,   234,   223,   107,    92,   226,   101,   102,   103,   104,
     105,   109,   322,   123,   133,   379,   238,   393,   237,    24,
     289,   134,   137,   135,   138,    19,   269,   270,   271,   272,
     273,   342,    19,   344,   294,   139,   341,   141,   281,   143,
     146,   109,   139,   159,   162,   196,   163,   278,   165,   179,
      24,   167,   171,   174,   175,   312,    54,   207,   143,   340,
     214,   435,   172,   190,   295,   173,   297,   298,    54,   177,
     419,   109,   139,   178,   184,   392,   304,   394,   186,   435,
     391,   188,   191,   174,   175,   313,   380,   202,   143,   205,
     214,   206,   209,   307,   109,   139,    24,   210,   211,   323,
     419,   214,   220,   390,   224,   227,   174,   175,   331,   230,
     235,   143,   240,   214,   243,   325,   438,   254,   255,   434,
      40,   436,   276,   277,   433,   282,   348,   245,   286,   249,
     290,    37,   292,   293,   345,   296,   299,   434,   300,   436,
     314,   315,   433,   358,   316,   317,   275,   432,    31,    58,
      59,   326,   362,   364,    65,   330,    65,    65,    65,    65,
      65,    65,   337,   366,   395,   432,   370,   396,   397,   398,
     399,   400,   401,   402,   437,   369,   413,   414,   415,   274,
      79,    80,   416,   417,   418,   443,   259,   260,   403,   441,
     405,   406,   407,   408,   439,   410,   404,   261,   310,   242,
     213,    99,   100,     0,     0,     0,   409,     0,     0,    24,
       0,   318,     0,   321,     0,     0,     0,     0,     0,     0,
       0,   329,     0,     0,     0,     0,     0,     0,     0,   333,
     334,     0,   336,     0,     0,     0,     0,     0,   347,     0,
       0,     0,   349,     0,   442,   352,     0,    24,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   139,     0,     0,
     359,   360,     0,   361,   123,     0,     0,   363,   174,   175,
       0,     0,     0,   143,     0,   214,     0,     0,   371,   372,
     373,   374,   375,   376,   377,     0,   378,     0,     0,   198,
      30,    31,    32,    33,    34,     0,     0,     0,   207,     0,
       0,    35,     0,    36,     0,    37,     0,     0,     0,     0,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
     228,    38,     0,     0,     0,     0,     0,    39,    40,     0,
      41,     0,   239,     0,     0,     0,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     266
};

static const short int yycheck[] =
{
       0,    93,     2,     6,     7,     5,     6,     7,    83,    84,
     111,    86,   113,   176,    12,   116,   114,    61,     3,    94,
       3,   119,    15,    13,   185,    18,   127,     0,   117,   279,
     119,    56,    32,   251,    34,    35,    36,    37,    38,    39,
       3,     4,   145,   118,    33,   120,   121,     3,     4,    56,
     125,   154,   302,   303,    13,   216,    13,    16,   156,    49,
     158,    13,    55,   164,    30,    40,    32,    42,    57,   287,
     288,     3,     4,    58,    57,    32,    76,    77,    78,    31,
      32,   247,   248,    21,   187,    23,   189,    12,    13,    27,
     308,   309,    56,   108,    57,    20,    24,    25,    44,    24,
      25,    57,    57,    58,    29,    43,    31,    45,    56,   327,
      48,    57,    77,    78,   212,   216,   217,   117,   284,   119,
     135,   136,    56,    12,    13,   169,   215,    10,   346,    54,
      44,    20,    57,   222,   137,    24,    25,   137,   241,    22,
      29,    56,    31,    57,   242,    44,   247,   162,     3,   250,
     148,   151,   318,   168,   152,   321,   171,   172,    57,    56,
      56,   161,    56,   324,    56,    54,    56,   333,   334,    56,
     336,    34,    35,    36,    37,    38,    39,   280,   279,    56,
      56,    56,   182,   227,   199,    56,   287,    56,   203,   204,
     205,   206,   192,     3,    56,   195,     5,     6,     7,     8,
       9,    12,   303,    20,    57,   368,   209,   368,   208,   209,
     254,    57,    56,    58,    57,   215,   231,   232,   233,   234,
     235,   324,   222,   324,   268,    13,   324,    57,   243,    29,
      57,    12,    13,    51,    56,    14,    57,   240,    57,    10,
     240,    56,    56,    24,    25,   289,   244,    54,    29,   324,
      31,   412,    56,    56,   269,    57,   271,   272,   256,    57,
      41,    12,    13,    57,    57,   368,   281,   368,    57,   430,
     368,    57,    57,    24,    25,   290,   368,    57,    29,    56,
      31,    56,    56,   286,    12,    13,   286,    56,    50,   304,
      41,    31,    47,   368,    57,    56,    24,    25,   313,    57,
      56,    29,    56,    31,    56,   305,    57,    56,    11,   412,
      53,   412,    57,    57,   412,    56,   331,    32,    56,    49,
      56,    30,    57,    57,   324,    57,    57,   430,    57,   430,
      57,    57,   430,   348,    57,    57,   236,   412,    16,    27,
      28,    57,    56,   358,    32,    57,    34,    35,    36,    37,
      38,    39,    57,    57,    56,   430,    57,    56,    56,    56,
      56,    56,    56,    56,    56,   365,    57,    57,    57,   236,
      58,    59,    57,    57,    57,    57,   225,   225,   382,   430,
     395,   396,   397,   398,   420,   400,   382,   225,   288,   213,
     182,    79,    80,    -1,    -1,    -1,   399,    -1,    -1,   399,
      -1,   301,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,
     320,    -1,   322,    -1,    -1,    -1,    -1,    -1,   328,    -1,
      -1,    -1,   332,    -1,   437,   335,    -1,   437,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
     350,   351,    -1,   353,    20,    -1,    -1,   357,    24,    25,
      -1,    -1,    -1,    29,    -1,    31,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,   167,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    54,    -1,
      -1,    26,    -1,    28,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    46,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,
      55,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     228
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    60,    61,   165,     0,    21,    23,    27,    43,    45,
      48,    62,    63,   148,   150,   152,   156,   157,   158,   165,
       3,     4,   161,   162,   165,   161,   161,    56,    56,    56,
      15,    16,    17,    18,    19,    26,    28,    30,    46,    52,
      53,    55,    64,    65,    68,    77,    80,    84,    91,    94,
      97,   100,   128,   131,   135,    56,    56,    56,   162,   162,
       3,   164,    56,    56,   160,   162,   165,    56,   160,   160,
     160,   160,   160,   160,    56,    56,   151,   153,   149,   162,
     162,    58,   164,   129,    98,    56,   101,    56,    56,    56,
      56,    56,    56,    85,    95,   154,   165,   154,   154,   162,
     162,     5,     6,     7,     8,     9,   159,     3,   163,    12,
     130,   138,    99,   138,    81,   102,   138,    66,    92,    78,
     136,   132,    69,    20,    88,    90,    96,   138,    44,    57,
     155,    57,    57,    57,    57,    58,   163,    56,    57,    13,
     146,    57,   146,    29,    82,   143,    57,   146,    63,    67,
      93,   138,    63,    79,   143,   137,   138,   133,   138,    51,
      70,    71,    56,    57,   138,    57,   146,    56,   163,   163,
     161,    56,    56,    57,    24,    25,   144,    57,    57,    10,
      22,   141,   142,   165,    57,   144,    57,   143,    57,   143,
      56,    57,    73,   165,   163,   146,    14,   139,   162,   163,
      57,   164,    57,   163,   163,    56,    56,    54,    89,    56,
      56,    50,   140,   141,    31,   145,   144,   144,    72,   162,
      47,    74,    75,   165,    57,    86,   165,    56,   162,   163,
      57,   163,   163,   163,   163,    56,    83,   165,   161,   162,
      56,   143,   140,    56,    63,    32,   103,   145,   146,    49,
     146,   147,    57,   162,    56,    11,    63,    76,    87,    94,
     100,   128,   134,   165,   164,    57,   162,    57,    58,   163,
     163,   163,   163,   163,    84,   134,    57,    57,   161,   144,
     143,   163,    56,   103,   146,   103,    56,   146,   147,   164,
      56,   135,    57,    57,   164,   163,    57,   163,   163,    57,
      57,    97,   146,   144,   163,   104,   103,   161,   146,   147,
     134,   147,   164,   163,    57,    57,    57,    57,   134,    97,
      97,   134,   146,   163,   105,   165,    57,   147,   147,   134,
      57,   163,   103,   134,   134,   103,   134,    57,   106,   107,
     138,   143,   144,   145,   146,   165,   147,   134,   163,   134,
     103,   103,   134,   103,    33,    57,   108,   147,   163,   134,
     134,   134,    56,   134,   163,   109,    57,   110,   111,   165,
      57,    34,    35,    36,    37,    38,    39,    40,    42,    89,
      90,   112,   113,   114,   118,   123,   124,   125,   126,   127,
     138,   143,   144,   145,   146,    56,    56,    56,    56,    56,
      56,    56,    56,   114,   118,   163,   163,   163,   163,   161,
     163,   119,   115,    57,    57,    57,    57,    57,    57,    41,
     120,   121,   122,   138,   143,   144,   145,   146,    89,    90,
     116,   117,   138,   143,   144,   145,   146,    56,    57,   121,
      57,   117,   161,    57
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;


  yyvsp[0] = yylval;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
        case 12:
#line 177 "parser.yxx"
    {
  dna_stack.back()->add((yyvsp[0]._dna_group));
}
    break;

  case 25:
#line 200 "parser.yxx"
    {
  dna_stack.push_back(new DNAGroup((yyvsp[-1]._string)));
}
    break;

  case 26:
#line 204 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 27:
#line 212 "parser.yxx"
    {
}
    break;

  case 28:
#line 220 "parser.yxx"
    {
  DNAVisGroup *vis_group = new DNAVisGroup((yyvsp[-1]._string));

  // Get the name of the current vis group and make it globaly available:
  g_current_zone_name = vis_group->get_name();

  dna_stack.push_back(vis_group);
  // This dna vis group needs to be stored now before we traverse
  // because the AI does not ever traverse but needs the vis groups
  dna_top_node->get_dna_storage()->store_DNAVisGroupAI(vis_group);
}
    break;

  case 29:
#line 232 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 30:
#line 240 "parser.yxx"
    {
}
    break;

  case 31:
#line 247 "parser.yxx"
    {
}
    break;

  case 32:
#line 254 "parser.yxx"
    {
  DNAVisGroup *visgroup = DCAST(DNAVisGroup, dna_stack.back());
  visgroup->add_visible((yyvsp[0]._string));
}
    break;

  case 33:
#line 259 "parser.yxx"
    {
  DNAVisGroup *visgroup = DCAST(DNAVisGroup, dna_stack.back());
  visgroup->add_visible((yyvsp[0]._string));
}
    break;

  case 35:
#line 268 "parser.yxx"
    {
}
    break;

  case 36:
#line 276 "parser.yxx"
    {
  // The top node on the stack should be the dnaVisGroup
  DNAVisGroup *vis_group = DCAST(DNAVisGroup, dna_stack.back());

  // Get the name of the current vis group so we can store that in the edge
  std::string current_zone = vis_group->get_name();

  // Store the edge in the dna storage
  PT(DNASuitEdge) edge = dna_top_node->get_dna_storage()->store_suit_edge((int)(yyvsp[-2]._number), (int)(yyvsp[-1]._number), current_zone);

  // Record this edge with the current vis group in case he needs to write it back out
  vis_group->add_suit_edge(edge);
}
    break;

  case 38:
#line 297 "parser.yxx"
    {
}
    break;

  case 39:
#line 304 "parser.yxx"
    {
  // Make a new battle cell
  PT(DNABattleCell) cell = new DNABattleCell((yyvsp[-5]._number), (yyvsp[-4]._number), LPoint3f((yyvsp[-3]._number), (yyvsp[-2]._number), (yyvsp[-1]._number)));

  // Store the battle cell in the dna storage
  dna_top_node->get_dna_storage()->store_battle_cell(cell);

  // Record this battle cell with the current vis group in case he needs to write it back out
  // The top node on the stack should be the dnaVisGroup
  DNAVisGroup *vis_group = DCAST(DNAVisGroup, dna_stack.back());
  vis_group->add_battle_cell(cell);
}
    break;

  case 40:
#line 322 "parser.yxx"
    {
  dna_stack.push_back(new DNANode((yyvsp[-1]._string)));
}
    break;

  case 41:
#line 326 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 42:
#line 334 "parser.yxx"
    {
  DNANode *node = DCAST(DNANode, dna_stack.back());
  node->set_pos((yyvsp[-3]._v3));
  node->set_hpr((yyvsp[-2]._v3));
  node->set_scale((yyvsp[-1]._v3));
}
    break;

  case 43:
#line 341 "parser.yxx"
    {
}
    break;

  case 44:
#line 348 "parser.yxx"
    {
  dna_stack.push_back(new DNAFlatBuilding((yyvsp[-1]._string)));
}
    break;

  case 45:
#line 352 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 46:
#line 360 "parser.yxx"
    {
  DNAFlatBuilding *building = DCAST(DNAFlatBuilding, dna_stack.back());
  building->set_pos((yyvsp[-4]._v3));
  building->set_hpr((yyvsp[-3]._v3));
  building->set_width((yyvsp[-2]._number));
}
    break;

  case 49:
#line 375 "parser.yxx"
    {
  DNAWall *wall = new DNAWall();
  dna_stack.back()->add(wall);
  dna_stack.push_back(wall);
}
    break;

  case 50:
#line 381 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 56:
#line 400 "parser.yxx"
    {
  DNAWall *wall = DCAST(DNAWall, dna_stack.back());
  wall->set_height((yyvsp[-4]._number));
  wall->set_code((yyvsp[-3]._string));
  wall->set_color((yyvsp[-2]._color));
}
    break;

  case 57:
#line 410 "parser.yxx"
    {
  (yyval._number) = (yyvsp[-1]._number);
}
    break;

  case 58:
#line 417 "parser.yxx"
    {
  (yyval._number) = (yyvsp[-1]._number);
}
    break;

  case 59:
#line 425 "parser.yxx"
    {
  // Store info on which blocks are in each zone:
  dna_top_node->get_dna_storage()->store_block_number((yyvsp[-1]._string), g_current_zone_name);
  dna_stack.push_back(new DNALandmarkBuilding((yyvsp[-1]._string)));
}
    break;

  case 60:
#line 431 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 61:
#line 440 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[-7]._string));
  building->set_article((yyvsp[-6]._string));
  building->set_title((yyvsp[-5]._string));
  building->set_pos((yyvsp[-4]._v3));
  building->set_hpr((yyvsp[-3]._v3));
  building->set_wall_color((yyvsp[-2]._color));
}
    break;

  case 62:
#line 450 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[-9]._string));
  building->set_article((yyvsp[-8]._string));
  building->set_title((yyvsp[-7]._string));
  building->set_pos((yyvsp[-6]._v3));
  building->set_hpr((yyvsp[-5]._v3));
  building->set_wall_color((yyvsp[-4]._color));
}
    break;

  case 63:
#line 460 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[-6]._string));
  building->set_article((yyvsp[-5]._string));
  building->set_title((yyvsp[-4]._string));
  building->set_pos((yyvsp[-3]._v3));
  building->set_hpr((yyvsp[-2]._v3));
}
    break;

  case 64:
#line 469 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[-7]._string));
  if (!((yyvsp[-6]._string)).empty()) {
    building->set_building_type((yyvsp[-6]._string));
    // Record this building type at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[-6]._string));
  }
  building->set_article((yyvsp[-5]._string));
  building->set_title((yyvsp[-4]._string));
  building->set_pos((yyvsp[-3]._v3));
  building->set_hpr((yyvsp[-2]._v3));
}
    break;

  case 65:
#line 483 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[-8]._string));
  building->set_article((yyvsp[-7]._string));
  building->set_title((yyvsp[-6]._string));
  building->set_pos((yyvsp[-5]._v3));
  building->set_hpr((yyvsp[-4]._v3));
}
    break;

  case 66:
#line 492 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[-9]._string));
  if (!((yyvsp[-8]._string)).empty()) {
    building->set_building_type((yyvsp[-8]._string));
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[-8]._string));
  }
  building->set_article((yyvsp[-7]._string));
  building->set_title((yyvsp[-6]._string));
  building->set_pos((yyvsp[-5]._v3));
  building->set_hpr((yyvsp[-4]._v3));
}
    break;

  case 67:
#line 506 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[-7]._string));
  if (!((yyvsp[-6]._string)).empty()) {
    building->set_building_type((yyvsp[-6]._string));
    // Record this headquarter at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[-6]._string));
  }
  building->set_article((yyvsp[-5]._string));
  building->set_title((yyvsp[-4]._string));
  building->set_pos((yyvsp[-3]._v3));
  building->set_hpr((yyvsp[-2]._v3));
  building->set_wall_color((yyvsp[-1]._color));
}
    break;

  case 68:
#line 521 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[-9]._string));
  if (!((yyvsp[-8]._string)).empty()) {
    building->set_building_type((yyvsp[-8]._string));
    // Record this headquarter at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[-8]._string));
  }
  building->set_article((yyvsp[-7]._string));
  building->set_title((yyvsp[-6]._string));
  building->set_pos((yyvsp[-5]._v3));
  building->set_hpr((yyvsp[-4]._v3));
  building->set_wall_color((yyvsp[-3]._color));
}
    break;

  case 69:
#line 536 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[-6]._string));
  if (!((yyvsp[-5]._string)).empty()) {
    building->set_building_type((yyvsp[-5]._string));
    // Record this headquarter at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[-5]._string));
  }
  building->set_article((yyvsp[-4]._string));
  building->set_title((yyvsp[-3]._string));
  building->set_pos((yyvsp[-2]._v3));
  building->set_hpr((yyvsp[-1]._v3));
}
    break;

  case 70:
#line 550 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[-8]._string));
  if (!((yyvsp[-7]._string)).empty()) {
    building->set_building_type((yyvsp[-7]._string));
    // Record this headquarter at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[-7]._string));
  }
  building->set_article((yyvsp[-6]._string));
  building->set_title((yyvsp[-5]._string));
  building->set_pos((yyvsp[-4]._v3));
  building->set_hpr((yyvsp[-3]._v3));
}
    break;

  case 71:
#line 567 "parser.yxx"
    {
  DNAWindows *windows = new DNAWindows();
  dna_stack.back()->add(windows);
  dna_stack.push_back(windows);
}
    break;

  case 72:
#line 573 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 73:
#line 581 "parser.yxx"
    {
  DNAWindows *windows = DCAST(DNAWindows, dna_stack.back());
  windows->set_code((yyvsp[-2]._string));
  windows->set_color((yyvsp[-1]._color));
  windows->set_window_count((int)(yyvsp[0]._number));
}
    break;

  case 74:
#line 591 "parser.yxx"
    {
  DNADoor *door = new DNADoor();
  dna_stack.back()->add(door);
  dna_stack.push_back(door);
}
    break;

  case 75:
#line 597 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 76:
#line 605 "parser.yxx"
    {
  DNADoor *door = DCAST(DNADoor, dna_stack.back());
  door->set_code((yyvsp[-1]._string));
  door->set_color((yyvsp[0]._color));
}
    break;

  case 77:
#line 616 "parser.yxx"
    {
  DNAFlatDoor *door = new DNAFlatDoor();
  dna_stack.back()->add(door);
  dna_stack.push_back(door);
}
    break;

  case 78:
#line 622 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 79:
#line 630 "parser.yxx"
    {
  DNAFlatDoor *door = DCAST(DNAFlatDoor, dna_stack.back());
  door->set_code((yyvsp[-1]._string));
  door->set_color((yyvsp[0]._color));
}
    break;

  case 80:
#line 641 "parser.yxx"
    {
  DNASign *sign = new DNASign();
  dna_stack.back()->add(sign);
  dna_stack.push_back(sign);
}
    break;

  case 81:
#line 647 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 84:
#line 660 "parser.yxx"
    {
  DNASign *sign = DCAST(DNASign, dna_stack.back());
  sign->set_code((yyvsp[0]._string));
}
    break;

  case 85:
#line 665 "parser.yxx"
    {
  DNASign *sign = DCAST(DNASign, dna_stack.back());
  sign->set_color((yyvsp[0]._color));
}
    break;

  case 86:
#line 670 "parser.yxx"
    {
  DNASign *sign = DCAST(DNASign, dna_stack.back());
  sign->set_pos((yyvsp[0]._v3));
}
    break;

  case 87:
#line 675 "parser.yxx"
    {
  DNASign *sign = DCAST(DNASign, dna_stack.back());
  sign->set_hpr((yyvsp[0]._v3));
}
    break;

  case 88:
#line 680 "parser.yxx"
    {
  DNASign *sign = DCAST(DNASign, dna_stack.back());
  sign->set_scale((yyvsp[0]._v3));
}
    break;

  case 91:
#line 693 "parser.yxx"
    {
  DNASignBaseline *baseline = new DNASignBaseline();
  dna_stack.back()->add(baseline);
  dna_stack.push_back(baseline);
}
    break;

  case 92:
#line 699 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 96:
#line 716 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_code((yyvsp[0]._string));
}
    break;

  case 97:
#line 721 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_color((yyvsp[0]._color));
}
    break;

  case 98:
#line 726 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_pos((yyvsp[0]._v3));
}
    break;

  case 99:
#line 731 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_hpr((yyvsp[0]._v3));
}
    break;

  case 100:
#line 736 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_scale((yyvsp[0]._v3));
}
    break;

  case 106:
#line 746 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_width((yyvsp[0]._number));
}
    break;

  case 107:
#line 751 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_height((yyvsp[0]._number));
}
    break;

  case 108:
#line 756 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_flags((yyvsp[-1]._string));
}
    break;

  case 113:
#line 771 "parser.yxx"
    {
  DNASignGraphic *graphic = new DNASignGraphic();
  dna_stack.back()->add(graphic);
  dna_stack.push_back(graphic);
}
    break;

  case 114:
#line 777 "parser.yxx"
    {
  dna_stack.pop_back();
}
    break;

  case 117:
#line 789 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_scale((yyvsp[0]._v3));
}
    break;

  case 118:
#line 794 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_pos((yyvsp[0]._v3));
}
    break;

  case 119:
#line 799 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_hpr((yyvsp[0]._v3));
}
    break;

  case 120:
#line 804 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_code((yyvsp[0]._string));
}
    break;

  case 121:
#line 809 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_color((yyvsp[0]._color));
}
    break;

  case 122:
#line 814 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_width((yyvsp[0]._number));
}
    break;

  case 123:
#line 819 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_height((yyvsp[0]._number));
}
    break;

  case 124:
#line 827 "parser.yxx"
    {
  DNASignText *text = new DNASignText();
  dna_stack.back()->add(text);
  dna_stack.push_back(text);
}
    break;

  case 125:
#line 833 "parser.yxx"
    {
  dna_stack.pop_back();
}
    break;

  case 128:
#line 845 "parser.yxx"
    {
  DNASignText *text = DCAST(DNASignText, dna_stack.back());
  text->set_scale((yyvsp[0]._v3));
}
    break;

  case 129:
#line 850 "parser.yxx"
    {
  DNASignText *text = DCAST(DNASignText, dna_stack.back());
  text->set_pos((yyvsp[0]._v3));
}
    break;

  case 130:
#line 855 "parser.yxx"
    {
  DNASignText *text = DCAST(DNASignText, dna_stack.back());
  text->set_hpr((yyvsp[0]._v3));
}
    break;

  case 131:
#line 860 "parser.yxx"
    {
  DNASignText *text = DCAST(DNASignText, dna_stack.back());
  text->set_code((yyvsp[0]._string));
}
    break;

  case 132:
#line 865 "parser.yxx"
    {
  DNASignText *text = DCAST(DNASignText, dna_stack.back());
  text->set_color((yyvsp[0]._color));
}
    break;

  case 133:
#line 870 "parser.yxx"
    {
  DNASignText *text = DCAST(DNASignText, dna_stack.back());
  text->set_letters((yyvsp[0]._string));
}
    break;

  case 134:
#line 878 "parser.yxx"
    {
  (yyval._string) = (yyvsp[-1]._string);
}
    break;

  case 135:
#line 885 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_indent((yyvsp[-1]._number));
}
    break;

  case 136:
#line 893 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_kern((yyvsp[-1]._number));
}
    break;

  case 137:
#line 901 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_wiggle((yyvsp[-1]._number));
}
    break;

  case 138:
#line 909 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_stumble((yyvsp[-1]._number));
}
    break;

  case 139:
#line 917 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_stomp((yyvsp[-1]._number));
}
    break;

  case 140:
#line 925 "parser.yxx"
    {
  DNACornice *cornice = new DNACornice();
  dna_stack.back()->add(cornice);
  dna_stack.push_back(cornice);
}
    break;

  case 141:
#line 931 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 142:
#line 939 "parser.yxx"
    {
  DNACornice *cornice = DCAST(DNACornice, dna_stack.back());
  cornice->set_code((yyvsp[-1]._string));
  cornice->set_color((yyvsp[0]._color));
}
    break;

  case 143:
#line 948 "parser.yxx"
    {
  dna_stack.push_back(new DNAStreet((yyvsp[-1]._string)));
}
    break;

  case 144:
#line 952 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 145:
#line 960 "parser.yxx"
    {
  DNAStreet *street = DCAST(DNAStreet, dna_stack.back());
  street->set_code((yyvsp[-5]._string));
  street->set_pos((yyvsp[-4]._v3));
  street->set_hpr((yyvsp[-3]._v3));
  street->set_street_texture((yyvsp[-2]._string));
  street->set_sidewalk_texture((yyvsp[-1]._string));
  // No curb texture specified, just use the sidewalk texture
  street->set_curb_texture((yyvsp[-1]._string));
}
    break;

  case 146:
#line 971 "parser.yxx"
    {
  DNAStreet *street = DCAST(DNAStreet, dna_stack.back());
  street->set_code((yyvsp[-6]._string));
  street->set_pos((yyvsp[-5]._v3));
  street->set_hpr((yyvsp[-4]._v3));
  street->set_street_texture((yyvsp[-3]._string));
  street->set_sidewalk_texture((yyvsp[-2]._string));
  street->set_curb_texture((yyvsp[-1]._string));
}
    break;

  case 147:
#line 981 "parser.yxx"
    {
  DNAStreet *street = DCAST(DNAStreet, dna_stack.back());
  street->set_code((yyvsp[-7]._string));
  street->set_pos((yyvsp[-6]._v3));
  street->set_hpr((yyvsp[-5]._v3));
  street->set_street_color((yyvsp[-4]._color));
  street->set_sidewalk_color((yyvsp[-3]._color));
  // No curb color specified, just use sidewalk color
  street->set_curb_color((yyvsp[-3]._color));
  street->set_street_texture((yyvsp[-2]._string));
  street->set_sidewalk_texture((yyvsp[-1]._string));
  // No curb texture specified, just use sidewalk texture
  street->set_curb_texture((yyvsp[-1]._string));
}
    break;

  case 148:
#line 996 "parser.yxx"
    {
  DNAStreet *street = DCAST(DNAStreet, dna_stack.back());
  street->set_code((yyvsp[-9]._string));
  street->set_pos((yyvsp[-8]._v3));
  street->set_hpr((yyvsp[-7]._v3));
  street->set_street_color((yyvsp[-6]._color));
  street->set_sidewalk_color((yyvsp[-5]._color));
  street->set_curb_color((yyvsp[-4]._color));
  street->set_street_texture((yyvsp[-3]._string));
  street->set_sidewalk_texture((yyvsp[-2]._string));
  street->set_curb_texture((yyvsp[-1]._string));
}
    break;

  case 150:
#line 1013 "parser.yxx"
    {
  // Parent this prop to whatever the top of the stack is
  dna_stack.back()->add((yyvsp[0]._dna_group));
}
    break;

  case 151:
#line 1021 "parser.yxx"
    {
  dna_stack.push_back(new DNAProp((yyvsp[-1]._string)));
}
    break;

  case 152:
#line 1025 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 153:
#line 1033 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[-2]._string));
  prop->set_pos((yyvsp[-1]._v3));
  prop->set_hpr((yyvsp[0]._v3));
}
    break;

  case 154:
#line 1040 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[-3]._string));
  prop->set_pos((yyvsp[-2]._v3));
  prop->set_hpr((yyvsp[-1]._v3));
  prop->set_scale((yyvsp[0]._v3));
}
    break;

  case 155:
#line 1048 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[-3]._string));
  prop->set_pos((yyvsp[-2]._v3));
  prop->set_hpr((yyvsp[-1]._v3));
  prop->set_color((yyvsp[0]._color));
}
    break;

  case 156:
#line 1056 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[-4]._string));
  prop->set_pos((yyvsp[-3]._v3));
  prop->set_hpr((yyvsp[-2]._v3));
  prop->set_scale((yyvsp[-1]._v3));
  prop->set_color((yyvsp[0]._color));
}
    break;

  case 157:
#line 1065 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[-3]._string));
  prop->set_pos((yyvsp[-2]._v3));
  prop->set_hpr((yyvsp[-1]._v3));
}
    break;

  case 158:
#line 1072 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[-4]._string));
  prop->set_pos((yyvsp[-3]._v3));
  prop->set_hpr((yyvsp[-2]._v3));
  prop->set_scale((yyvsp[-1]._v3));
}
    break;

  case 159:
#line 1080 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[-4]._string));
  prop->set_pos((yyvsp[-3]._v3));
  prop->set_hpr((yyvsp[-2]._v3));
  prop->set_color((yyvsp[-1]._color));
}
    break;

  case 160:
#line 1088 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[-5]._string));
  prop->set_pos((yyvsp[-4]._v3));
  prop->set_hpr((yyvsp[-3]._v3));
  prop->set_scale((yyvsp[-2]._v3));
  prop->set_color((yyvsp[-1]._color));
}
    break;

  case 161:
#line 1100 "parser.yxx"
    {
  (yyval._string) = (yyvsp[-1]._string);
}
    break;

  case 162:
#line 1107 "parser.yxx"
    {
  (yyval._number) = (yyvsp[-1]._number);
}
    break;

  case 163:
#line 1114 "parser.yxx"
    {
  (yyval._string) = (yyvsp[-1]._string);
}
    break;

  case 164:
#line 1121 "parser.yxx"
    {
  (yyval._string) = (yyvsp[-1]._string);
}
    break;

  case 165:
#line 1125 "parser.yxx"
    {
  (yyval._string) = "";
}
    break;

  case 166:
#line 1132 "parser.yxx"
    {
  (yyval._string) = (yyvsp[-1]._string);
}
    break;

  case 167:
#line 1139 "parser.yxx"
    {
  // An apparent compiler bug with MSVC prevents this line from compiling properly:
  //  $$ = LVecBase3f($3, $4, $5);

  // Fortunately, this is functionally equivalent:
  (yyval._v3).set((yyvsp[-3]._number), (yyvsp[-2]._number), (yyvsp[-1]._number));
}
    break;

  case 168:
#line 1149 "parser.yxx"
    {
  // New (correct) HPR representation
#if temp_hpr_fix
    (yyval._v3).set((yyvsp[-3]._number), (yyvsp[-2]._number), (yyvsp[-1]._number));
#else
    (yyval._v3) = new_to_old_hpr(LVecBase3f((yyvsp[-3]._number), (yyvsp[-2]._number), (yyvsp[-1]._number)));
#endif
}
    break;

  case 169:
#line 1158 "parser.yxx"
    {
  // Old (broken) HPR representation
  if (temp_hpr_fix) {
    (yyval._v3) = old_to_new_hpr(LVecBase3f((yyvsp[-3]._number), (yyvsp[-2]._number), (yyvsp[-1]._number)));
  } else {
    (yyval._v3).set((yyvsp[-3]._number), (yyvsp[-2]._number), (yyvsp[-1]._number));
  }
}
    break;

  case 170:
#line 1169 "parser.yxx"
    {
  (yyval._v3).set((yyvsp[-3]._number), (yyvsp[-2]._number), (yyvsp[-1]._number));
}
    break;

  case 171:
#line 1176 "parser.yxx"
    {
  (yyval._color).set((yyvsp[-4]._number), (yyvsp[-3]._number), (yyvsp[-2]._number), (yyvsp[-1]._number));
}
    break;

  case 172:
#line 1183 "parser.yxx"
    {
  (yyval._string) = (yyvsp[-1]._string);
}
    break;

  case 173:
#line 1195 "parser.yxx"
    {
  // Flag this model as not being for a specific neighborhood
  current_model_hood = 0;
  current_model_place = 0;
  Filename model = (yyvsp[-1]._string);
  model.set_extension("bam");
  current_model = NodePath(loader.load_sync(model));
}
    break;

  case 175:
#line 1212 "parser.yxx"
    {
  // Flag this model as being for a specific neighborhood
  current_model_hood = 1;
  current_model_place = 0;
  LoaderOptions options;
  options.set_flags(options.get_flags() | LoaderOptions::LF_no_ram_cache);
  Filename model = (yyvsp[-1]._string);
  model.set_extension("bam");
  current_model = NodePath(loader.load_sync(model, options));
}
    break;

  case 177:
#line 1231 "parser.yxx"
    {
  // Flag this model as being for a specific neighborhood
  current_model_hood = 0;
  current_model_place = 1;
  LoaderOptions options;
  options.set_flags(options.get_flags() | LoaderOptions::LF_no_ram_cache);
  Filename model = (yyvsp[-1]._string);
  model.set_extension("bam");
  current_model = NodePath(loader.load_sync(model, options));
}
    break;

  case 181:
#line 1254 "parser.yxx"
    {
  // If the std::string is empty std::string that means use the top node of the model
  if ((yyvsp[-1]._string) == "") {
    // If this model is neighborhood specific, store it in the hood map
    if (current_model_hood) {
      dna_top_node->get_dna_storage()->store_hood_node((yyvsp[-2]._string), current_model, (yyvsp[-3]._string));
    } else if (current_model_place) {
      dna_top_node->get_dna_storage()->store_place_node((yyvsp[-2]._string), current_model, (yyvsp[-3]._string));
    } else {
      dna_top_node->get_dna_storage()->store_node((yyvsp[-2]._string), current_model, (yyvsp[-3]._string));
    };
  } else {
    // Find the node with the name stored in $5
    NodePath node = current_model.find((yyvsp[-1]._string).insert(0, "**/"));
    // Error if we could not find it
    if (node.is_empty()) {
      dnayyerror("Empty NodePath");
    };
    // If this model is neighborhood specific, store it in the hood map
    if (current_model_hood) {
      dna_top_node->get_dna_storage()->store_hood_node((yyvsp[-2]._string), node, (yyvsp[-3]._string));
    } else if (current_model_place) {
      dna_top_node->get_dna_storage()->store_place_node((yyvsp[-2]._string), node, (yyvsp[-3]._string));
    } else {
      dna_top_node->get_dna_storage()->store_node((yyvsp[-2]._string), node, (yyvsp[-3]._string));
    };
  }

  // Put this item name in the catalog
  dna_top_node->get_dna_storage()->store_catalog_string((yyvsp[-3]._string), (yyvsp[-2]._string));

}
    break;

  case 182:
#line 1289 "parser.yxx"
    {
  std::string find_string = (yyvsp[-1]._string);
  NodePath node = current_model.find(find_string.insert(0, "**/"));
  if (node.is_empty()) {
        dnayyerror("Empty NodePath");
        };
  // If this model is neighborhood specific, store it in the hood map
  if (current_model_hood) {
    dna_top_node->get_dna_storage()->store_hood_node((yyvsp[-1]._string), node, (yyvsp[-2]._string));
  } else if (current_model_place) {
    dna_top_node->get_dna_storage()->store_place_node((yyvsp[-1]._string), node, (yyvsp[-2]._string));
  } else {
    dna_top_node->get_dna_storage()->store_node((yyvsp[-1]._string), node, (yyvsp[-2]._string));
  };
  dna_top_node->get_dna_storage()->store_catalog_string((yyvsp[-2]._string), (yyvsp[-1]._string));

}
    break;

  case 183:
#line 1313 "parser.yxx"
    {
  PT(Texture) texture = TexturePool::load_texture((yyvsp[-1]._string));
  if (texture == (Texture *)NULL) {
    dna_cat.error()
      << "Unable to load texture file " << (yyvsp[-1]._string) << "\n";
  } else {
    dna_top_node->get_dna_storage()->store_texture((yyvsp[-2]._string), texture);
    dna_top_node->get_dna_storage()->store_catalog_string((yyvsp[-3]._string), (yyvsp[-2]._string));
  }
}
    break;

  case 184:
#line 1329 "parser.yxx"
    {
  Filename model = (yyvsp[-1]._string);
  if (model.get_extension() == "") {
    model.set_extension("bam");
  }
  PT(TextFont) font = FontPool::load_font(model);

  if (font != (TextFont *)NULL && font->is_valid()) {
    dna_top_node->get_dna_storage()->store_font((yyvsp[-2]._string), font);
    dna_top_node->get_dna_storage()->store_catalog_string((yyvsp[-3]._string), (yyvsp[-2]._string));
  } else {
    dna_cat.warning()
      << "Unable to load font file " << (yyvsp[-1]._string) << "\n";
  }
}
    break;

  case 185:
#line 1351 "parser.yxx"
    {
  // Old syntax, for backward compatibility, without lb_index.
  PT(DNASuitPoint) point = new DNASuitPoint((int)(yyvsp[-5]._number),
                                            (DNASuitPoint::DNASuitPointType)(int
)(yyvsp[-4]._number),
                                            LPoint3f((yyvsp[-3]._number), (yyvsp[-2]._number), (yyvsp[-1]._number)));
  dna_top_node->get_dna_storage()->store_suit_point(point);
}
    break;

  case 186:
#line 1360 "parser.yxx"
    {
  // Old syntax, for backward compatibility, with lb_index.
  PT(DNASuitPoint) point = new DNASuitPoint((int)(yyvsp[-6]._number),
                                            (DNASuitPoint::DNASuitPointType)(int
)(yyvsp[-5]._number),
                                            LPoint3f((yyvsp[-4]._number), (yyvsp[-3]._number), (yyvsp[-2]._number)),
                                            (int)(yyvsp[-1]._number));
  dna_top_node->get_dna_storage()->store_suit_point(point);
}
    break;

  case 187:
#line 1370 "parser.yxx"
    {
  // Current syntax, without lb_index.
  PT(DNASuitPoint) point = new DNASuitPoint((int)(yyvsp[-7]._number), (yyvsp[-5]._suit_point_type),
                                            LPoint3f((yyvsp[-3]._number), (yyvsp[-2]._number), (yyvsp[-1]._number)));
  dna_top_node->get_dna_storage()->store_suit_point(point);
}
    break;

  case 188:
#line 1377 "parser.yxx"
    {
  // Current syntax, with lb_index.
  PT(DNASuitPoint) point = new DNASuitPoint((int)(yyvsp[-9]._number), (yyvsp[-7]._suit_point_type),
                                            LPoint3f((yyvsp[-5]._number), (yyvsp[-4]._number), (yyvsp[-3]._number)),
                                            (int)(yyvsp[-1]._number));
  dna_top_node->get_dna_storage()->store_suit_point(point);
}
    break;

  case 189:
#line 1389 "parser.yxx"
    {
  (yyval._suit_point_type) = DNASuitPoint::FRONT_DOOR_POINT;
}
    break;

  case 190:
#line 1393 "parser.yxx"
    {
  (yyval._suit_point_type) = DNASuitPoint::SIDE_DOOR_POINT;
}
    break;

  case 191:
#line 1397 "parser.yxx"
    {
  (yyval._suit_point_type) = DNASuitPoint::STREET_POINT;
}
    break;

  case 192:
#line 1401 "parser.yxx"
    {
  (yyval._suit_point_type) = DNASuitPoint::COGHQ_IN_POINT;
}
    break;

  case 193:
#line 1405 "parser.yxx"
    {
  (yyval._suit_point_type) = DNASuitPoint::COGHQ_OUT_POINT;
}
    break;

  case 194:
#line 1420 "parser.yxx"
    {
  dnayyerror("Name required.");
  (yyval._string) = "";
}
    break;

  case 196:
#line 1438 "parser.yxx"
    {
  dnayyerror("String required.");
  (yyval._string) = "";
}
    break;

  case 198:
#line 1457 "parser.yxx"
    {
  (yyval._string) = (yyvsp[0]._string);
}
    break;

  case 201:
#line 1484 "parser.yxx"
    {
  int i = (int)(yyvsp[0]._number);
  if ((double)i != (yyvsp[0]._number)) {
    dnayywarning("Integer expected.");
    (yyval._number) = (double)i;
  }
}
    break;


    }

/* Line 1037 of yacc.c.  */
#line 2992 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {

		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 yydestruct ("Error: popping",
                             yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

yyvsp -= yylen;
  yyssp -= yylen;
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
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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
  yydestruct ("Error: discarding lookahead",
              yytoken, &yylval);
  yychar = YYEMPTY;
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
