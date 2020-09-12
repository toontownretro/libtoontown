/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         dnayyparse
#define yylex           dnayylex
#define yyerror         dnayyerror
#define yylval          dnayylval
#define yychar          dnayychar
#define yydebug         dnayydebug
#define yynerrs         dnayynerrs

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
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
#include "dnaAnimProp.h"
#include "dnaInteractiveProp.h"
#include "dnaAnimBuilding.h"
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


/* Line 371 of yacc.c  */
#line 167 "parser.cxx"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "parser.hxx".  */
#ifndef YY_DNAYY_PARSER_HXX_INCLUDED
# define YY_DNAYY_PARSER_HXX_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int dnayydebug;
#endif

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
     ANIM = 265,
     ANIM_BUILDING = 266,
     ANIM_PROP = 267,
     ARTICLE = 268,
     BATTLE_CELL = 269,
     CELL_ID = 270,
     CODE = 271,
     COLOR = 272,
     COUNT = 273,
     CORNICE = 274,
     DOOR = 275,
     FLAT_BUILDING = 276,
     FLAT_DOOR = 277,
     DNAGROUP = 278,
     INTERACTIVE_PROP = 279,
     HEIGHT = 280,
     HOOD_MODEL = 281,
     BUILDING_TYPE = 282,
     PLACE_MODEL = 283,
     HPR = 284,
     NHPR = 285,
     LANDMARK_BUILDING = 286,
     MODEL = 287,
     NODE = 288,
     POS = 289,
     PROP = 290,
     SCALE = 291,
     SIGN = 292,
     BASELINE = 293,
     INDENT = 294,
     KERN = 295,
     WIGGLE = 296,
     STUMBLE = 297,
     FLAGS = 298,
     STOMP = 299,
     TEXT_ = 300,
     LETTERS = 301,
     GRAPHIC = 302,
     STORE_FONT = 303,
     STORE_NODE = 304,
     STORE_TEXTURE = 305,
     STREET = 306,
     SUIT_EDGE = 307,
     STORE_SUIT_POINT = 308,
     TEXTURE = 309,
     TITLE = 310,
     VIS = 311,
     VISGROUP = 312,
     WALL = 313,
     WIDTH = 314,
     WINDOWS = 315
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define STRING 259
#define FRONT_DOOR_POINT_ 260
#define SIDE_DOOR_POINT_ 261
#define STREET_POINT_ 262
#define COGHQ_IN_POINT_ 263
#define COGHQ_OUT_POINT_ 264
#define ANIM 265
#define ANIM_BUILDING 266
#define ANIM_PROP 267
#define ARTICLE 268
#define BATTLE_CELL 269
#define CELL_ID 270
#define CODE 271
#define COLOR 272
#define COUNT 273
#define CORNICE 274
#define DOOR 275
#define FLAT_BUILDING 276
#define FLAT_DOOR 277
#define DNAGROUP 278
#define INTERACTIVE_PROP 279
#define HEIGHT 280
#define HOOD_MODEL 281
#define BUILDING_TYPE 282
#define PLACE_MODEL 283
#define HPR 284
#define NHPR 285
#define LANDMARK_BUILDING 286
#define MODEL 287
#define NODE 288
#define POS 289
#define PROP 290
#define SCALE 291
#define SIGN 292
#define BASELINE 293
#define INDENT 294
#define KERN 295
#define WIGGLE 296
#define STUMBLE 297
#define FLAGS 298
#define STOMP 299
#define TEXT_ 300
#define LETTERS 301
#define GRAPHIC 302
#define STORE_FONT 303
#define STORE_NODE 304
#define STORE_TEXTURE 305
#define STREET 306
#define SUIT_EDGE 307
#define STORE_SUIT_POINT 308
#define TEXTURE 309
#define TITLE 310
#define VIS 311
#define VISGROUP 312
#define WALL 313
#define WIDTH 314
#define WINDOWS 315



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE dnayylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int dnayyparse (void *YYPARSE_PARAM);
#else
int dnayyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int dnayyparse (void);
#else
int dnayyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_DNAYY_PARSER_HXX_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 352 "parser.cxx"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   685

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  118
/* YYNRULES -- Number of rules.  */
#define YYNRULES  240
/* YYNRULES -- Number of states.  */
#define YYNSTATES  529

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    13,    15,    17,    19,
      21,    23,    25,    28,    30,    32,    34,    36,    38,    40,
      42,    44,    46,    48,    50,    52,    54,    56,    58,    59,
      66,    68,    69,    76,    81,    86,    88,    91,    93,    96,
     102,   104,   107,   116,   117,   124,   129,   131,   132,   139,
     145,   147,   150,   151,   157,   159,   162,   164,   166,   168,
     174,   179,   184,   185,   192,   201,   212,   220,   229,   239,
     250,   259,   270,   278,   288,   289,   296,   306,   318,   327,
     337,   348,   360,   370,   382,   391,   402,   403,   409,   413,
     414,   420,   423,   424,   430,   433,   434,   441,   443,   446,
     448,   450,   452,   454,   456,   458,   461,   462,   468,   471,
     473,   476,   478,   480,   482,   484,   486,   488,   490,   492,
     494,   496,   498,   500,   505,   507,   509,   512,   515,   516,
     522,   524,   527,   529,   531,   533,   535,   537,   539,   541,
     542,   548,   550,   553,   555,   557,   559,   561,   563,   565,
     570,   575,   580,   585,   590,   595,   596,   602,   605,   606,
     613,   620,   628,   637,   648,   650,   653,   656,   657,   664,
     668,   673,   678,   684,   689,   695,   701,   708,   709,   716,
     721,   727,   733,   740,   746,   753,   760,   768,   769,   776,
     782,   789,   796,   804,   811,   819,   827,   836,   841,   846,
     851,   856,   861,   866,   868,   873,   880,   887,   894,   901,
     909,   914,   915,   922,   923,   930,   931,   938,   940,   943,
     950,   956,   963,   970,   979,   989,  1000,  1013,  1015,  1017,
    1019,  1021,  1023,  1025,  1027,  1029,  1031,  1033,  1035,  1037,
    1039
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      65,     0,    -1,    66,    68,    -1,   181,    -1,    66,    67,
      -1,   164,    -1,   166,    -1,   168,    -1,   172,    -1,   173,
      -1,   174,    -1,   181,    -1,    68,    69,    -1,    70,    -1,
      73,    -1,    82,    -1,    85,    -1,    96,    -1,    99,    -1,
     139,    -1,   146,    -1,   149,    -1,   143,    -1,   136,    -1,
     105,    -1,   108,    -1,    89,    -1,   102,    -1,    -1,    23,
     176,    61,    71,    72,    62,    -1,    68,    -1,    -1,    57,
     176,    61,    74,    75,    62,    -1,    76,    78,    80,    68,
      -1,    56,    61,    77,    62,    -1,   178,    -1,    77,   178,
      -1,   181,    -1,    78,    79,    -1,    52,    61,   180,   180,
      62,    -1,   181,    -1,    80,    81,    -1,    14,    61,   179,
     179,   179,   179,   179,    62,    -1,    -1,    33,   176,    61,
      83,    84,    62,    -1,   159,   160,   161,    68,    -1,    68,
      -1,    -1,    21,   176,    61,    86,    87,    62,    -1,   159,
     160,    94,    88,   142,    -1,   181,    -1,    88,    89,    -1,
      -1,    58,    61,    90,    93,    62,    -1,   181,    -1,    91,
      92,    -1,   102,    -1,   136,    -1,   108,    -1,    95,   154,
     162,    91,   142,    -1,    59,    61,   179,    62,    -1,    25,
      61,   179,    62,    -1,    -1,    31,   176,    61,    97,    98,
      62,    -1,   154,   157,   156,   159,   160,   162,   105,   142,
      -1,   154,   157,   156,   159,   160,   162,   105,   142,   111,
     142,    -1,   154,   157,   156,   159,   160,   105,   142,    -1,
     154,   158,   157,   156,   159,   160,   105,   142,    -1,   154,
     157,   156,   159,   160,   105,   142,   111,   142,    -1,   154,
     158,   157,   156,   159,   160,   105,   142,   111,   142,    -1,
     154,   158,   157,   156,   159,   160,   162,   142,    -1,   154,
     158,   157,   156,   159,   160,   162,   142,   111,   142,    -1,
     154,   158,   157,   156,   159,   160,   142,    -1,   154,   158,
     157,   156,   159,   160,   142,   111,   142,    -1,    -1,    11,
     176,    61,   100,   101,    62,    -1,   154,   157,   156,   152,
     159,   160,   162,   105,   142,    -1,   154,   157,   156,   152,
     159,   160,   162,   105,   142,   111,   142,    -1,   154,   157,
     156,   152,   159,   160,   105,   142,    -1,   154,   158,   157,
     156,   152,   159,   160,   105,   142,    -1,   154,   157,   156,
     152,   159,   160,   105,   142,   111,   142,    -1,   154,   158,
     157,   156,   152,   159,   160,   105,   142,   111,   142,    -1,
     154,   158,   157,   156,   152,   159,   160,   162,   142,    -1,
     154,   158,   157,   156,   152,   159,   160,   162,   142,   111,
     142,    -1,   154,   158,   157,   156,   152,   159,   160,   142,
      -1,   154,   158,   157,   156,   152,   159,   160,   142,   111,
     142,    -1,    -1,    60,    61,   103,   104,    62,    -1,   154,
     162,   155,    -1,    -1,    20,    61,   106,   107,    62,    -1,
     154,   162,    -1,    -1,    22,    61,   109,   110,    62,    -1,
     154,   162,    -1,    -1,    37,    61,   112,   113,   115,    62,
      -1,   181,    -1,   113,   114,    -1,   154,    -1,   162,    -1,
     159,    -1,   160,    -1,   161,    -1,   181,    -1,   115,   116,
      -1,    -1,    38,    61,   117,   118,    62,    -1,   119,   121,
      -1,   181,    -1,   119,   120,    -1,   154,    -1,   162,    -1,
     159,    -1,   160,    -1,   161,    -1,   131,    -1,   132,    -1,
     133,    -1,   134,    -1,   135,    -1,    94,    -1,    95,    -1,
      43,    61,   177,    62,    -1,   126,    -1,   122,    -1,   121,
     126,    -1,   121,   122,    -1,    -1,    47,    61,   123,   124,
      62,    -1,   125,    -1,   124,   125,    -1,   161,    -1,   159,
      -1,   160,    -1,   154,    -1,   162,    -1,    94,    -1,    95,
      -1,    -1,    45,    61,   127,   128,    62,    -1,   129,    -1,
     128,   129,    -1,   161,    -1,   159,    -1,   160,    -1,   154,
      -1,   162,    -1,   130,    -1,    46,    61,   177,    62,    -1,
      39,    61,   179,    62,    -1,    40,    61,   179,    62,    -1,
      41,    61,   179,    62,    -1,    42,    61,   179,    62,    -1,
      44,    61,   179,    62,    -1,    -1,    19,    61,   137,   138,
      62,    -1,   154,   162,    -1,    -1,    51,   176,    61,   140,
     141,    62,    -1,   154,   159,   160,   163,   163,   142,    -1,
     154,   159,   160,   163,   163,   163,   142,    -1,   154,   159,
     160,   162,   162,   163,   163,   142,    -1,   154,   159,   160,
     162,   162,   162,   163,   163,   163,   142,    -1,   181,    -1,
     142,   143,    -1,   142,   146,    -1,    -1,    35,   176,    61,
     144,   145,    62,    -1,   154,   159,   160,    -1,   154,   159,
     160,   161,    -1,   154,   159,   160,   162,    -1,   154,   159,
     160,   161,   162,    -1,   154,   159,   160,   111,    -1,   154,
     159,   160,   161,   111,    -1,   154,   159,   160,   162,   111,
      -1,   154,   159,   160,   161,   162,   111,    -1,    -1,    12,
     176,    61,   147,   148,    62,    -1,   154,   152,   159,   160,
      -1,   154,   152,   159,   160,   161,    -1,   154,   152,   159,
     160,   162,    -1,   154,   152,   159,   160,   161,   162,    -1,
     154,   152,   159,   160,   111,    -1,   154,   152,   159,   160,
     161,   111,    -1,   154,   152,   159,   160,   162,   111,    -1,
     154,   152,   159,   160,   161,   162,   111,    -1,    -1,    24,
     176,    61,   150,   151,    62,    -1,   154,   152,   153,   159,
     160,    -1,   154,   152,   153,   159,   160,   161,    -1,   154,
     152,   153,   159,   160,   162,    -1,   154,   152,   153,   159,
     160,   161,   162,    -1,   154,   152,   153,   159,   160,   111,
      -1,   154,   152,   153,   159,   160,   161,   111,    -1,   154,
     152,   153,   159,   160,   162,   111,    -1,   154,   152,   153,
     159,   160,   161,   162,   111,    -1,    10,    61,   177,    62,
      -1,    15,    61,   180,    62,    -1,    16,    61,   177,    62,
      -1,    18,    61,   180,    62,    -1,    55,    61,   177,    62,
      -1,    13,    61,   177,    62,    -1,   181,    -1,    27,    61,
     178,    62,    -1,    34,    61,   179,   179,   179,    62,    -1,
      30,    61,   179,   179,   179,    62,    -1,    29,    61,   179,
     179,   179,    62,    -1,    36,    61,   179,   179,   179,    62,
      -1,    17,    61,   179,   179,   179,   179,    62,    -1,    54,
      61,   177,    62,    -1,    -1,    32,   177,    61,   165,   170,
      62,    -1,    -1,    26,   177,    61,   167,   170,    62,    -1,
      -1,    28,   177,    61,   169,   170,    62,    -1,   181,    -1,
     170,   171,    -1,    49,    61,   178,   178,   178,    62,    -1,
      49,    61,   178,   178,    62,    -1,    50,    61,   178,   178,
     178,    62,    -1,    48,    61,   178,   178,   178,    62,    -1,
      53,    61,   180,   180,   179,   179,   179,    62,    -1,    53,
      61,   180,   180,   179,   179,   179,   180,    62,    -1,    53,
      61,   180,    63,   175,    63,   179,   179,   179,    62,    -1,
      53,    61,   180,    63,   175,    63,   179,   179,   179,    63,
     180,    62,    -1,     5,    -1,     6,    -1,     7,    -1,     8,
      -1,     9,    -1,   181,    -1,   178,    -1,   181,    -1,   178,
      -1,     3,    -1,     4,    -1,     3,    -1,     3,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   169,   170,   174,   175,   176,   177,   178,
     179,   183,   184,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   211,   210,
     222,   231,   230,   252,   259,   266,   271,   279,   280,   288,
     308,   309,   316,   335,   334,   346,   353,   361,   360,   372,
     382,   383,   388,   387,   401,   402,   406,   407,   408,   412,
     422,   429,   438,   437,   452,   462,   472,   481,   495,   504,
     518,   533,   548,   562,   580,   579,   594,   605,   616,   626,
     641,   651,   666,   682,   698,   713,   732,   731,   745,   756,
     755,   769,   781,   780,   794,   806,   805,   819,   820,   824,
     829,   834,   839,   844,   852,   853,   858,   857,   871,   875,
     876,   880,   885,   890,   895,   900,   905,   906,   907,   908,
     909,   910,   915,   920,   928,   929,   930,   931,   936,   935,
     948,   949,   953,   958,   963,   968,   973,   978,   983,   992,
     991,  1004,  1005,  1009,  1014,  1019,  1024,  1029,  1034,  1042,
    1049,  1057,  1065,  1073,  1081,  1090,  1089,  1103,  1113,  1112,
    1124,  1135,  1145,  1160,  1176,  1177,  1182,  1191,  1190,  1202,
    1209,  1217,  1225,  1234,  1241,  1249,  1257,  1270,  1269,  1282,
    1290,  1299,  1308,  1318,  1326,  1335,  1344,  1358,  1357,  1370,
    1379,  1389,  1399,  1410,  1419,  1429,  1439,  1453,  1460,  1467,
    1474,  1481,  1488,  1492,  1499,  1506,  1516,  1526,  1537,  1544,
    1551,  1564,  1563,  1581,  1580,  1600,  1599,  1616,  1617,  1622,
    1657,  1681,  1697,  1719,  1728,  1738,  1745,  1757,  1761,  1765,
    1769,  1773,  1788,  1793,  1806,  1811,  1825,  1829,  1841,  1852,
    1888
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "STRING", "FRONT_DOOR_POINT_",
  "SIDE_DOOR_POINT_", "STREET_POINT_", "COGHQ_IN_POINT_",
  "COGHQ_OUT_POINT_", "ANIM", "ANIM_BUILDING", "ANIM_PROP", "ARTICLE",
  "BATTLE_CELL", "CELL_ID", "CODE", "COLOR", "COUNT", "CORNICE", "DOOR",
  "FLAT_BUILDING", "FLAT_DOOR", "DNAGROUP", "INTERACTIVE_PROP", "HEIGHT",
  "HOOD_MODEL", "BUILDING_TYPE", "PLACE_MODEL", "HPR", "NHPR",
  "LANDMARK_BUILDING", "MODEL", "NODE", "POS", "PROP", "SCALE", "SIGN",
  "BASELINE", "INDENT", "KERN", "WIGGLE", "STUMBLE", "FLAGS", "STOMP",
  "TEXT_", "LETTERS", "GRAPHIC", "STORE_FONT", "STORE_NODE",
  "STORE_TEXTURE", "STREET", "SUIT_EDGE", "STORE_SUIT_POINT", "TEXTURE",
  "TITLE", "VIS", "VISGROUP", "WALL", "WIDTH", "WINDOWS", "'['", "']'",
  "','", "$accept", "top", "load_list", "load", "internal_node_list",
  "internal_node", "group", "$@1", "group_body", "visgroup", "$@2",
  "visgroup_body", "vis", "vis_list", "suit_edge_list", "suit_edge",
  "battle_cell_list", "battle_cell", "node", "$@3", "node_body",
  "flat_building", "$@4", "flat_building_body", "wall_list", "wall", "$@5",
  "wall_node_list", "wall_node", "wall_body", "width", "height",
  "landmark_building", "$@6", "landmark_building_body", "anim_building",
  "$@7", "anim_building_body", "windows", "$@8", "windows_body", "door",
  "$@9", "door_body", "flat_door", "$@10", "flat_door_body", "sign",
  "$@11", "sign_list", "sign_node", "baseline_list", "baseline", "$@12",
  "baseline_body", "baseline_body_node_list", "baseline_body_node",
  "text_list", "sign_graphic", "$@13", "graphic_node_list",
  "sign_graphic_node", "sign_text", "$@14", "text_node_list", "text_node",
  "letters", "baseline_indent", "baseline_kern", "baseline_wiggle",
  "baseline_stumble", "baseline_stomp", "cornice", "$@15", "cornice_body",
  "street", "$@16", "street_body", "prop_list", "prop", "$@17",
  "prop_body", "anim_prop", "$@18", "anim_prop_body", "interactive_prop",
  "$@19", "interactive_prop_body", "anim", "cell_id", "code", "count",
  "title", "article", "building_type", "pos", "hpr", "scale", "color",
  "texture", "model", "$@20", "hood_model", "$@21", "place_model", "$@22",
  "store_node_list", "store_node", "store_texture", "store_font",
  "store_suit_point", "suit_point_type", "required_name",
  "required_string", "string", "real", "integer", "empty", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    91,    93,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    67,    67,    67,
      67,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    71,    70,
      72,    74,    73,    75,    76,    77,    77,    78,    78,    79,
      80,    80,    81,    83,    82,    84,    84,    86,    85,    87,
      88,    88,    90,    89,    91,    91,    92,    92,    92,    93,
      94,    95,    97,    96,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,   100,    99,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   103,   102,   104,   106,
     105,   107,   109,   108,   110,   112,   111,   113,   113,   114,
     114,   114,   114,   114,   115,   115,   117,   116,   118,   119,
     119,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   121,   121,   121,   121,   123,   122,
     124,   124,   125,   125,   125,   125,   125,   125,   125,   127,
     126,   128,   128,   129,   129,   129,   129,   129,   129,   130,
     131,   132,   133,   134,   135,   137,   136,   138,   140,   139,
     141,   141,   141,   141,   142,   142,   142,   144,   143,   145,
     145,   145,   145,   145,   145,   145,   145,   147,   146,   148,
     148,   148,   148,   148,   148,   148,   148,   150,   149,   151,
     151,   151,   151,   151,   151,   151,   151,   152,   153,   154,
     155,   156,   157,   157,   158,   159,   160,   160,   161,   162,
     163,   165,   164,   167,   166,   169,   168,   170,   170,   171,
     171,   172,   173,   174,   174,   174,   174,   175,   175,   175,
     175,   175,   176,   176,   177,   177,   178,   178,   179,   180,
     181
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       1,     0,     6,     4,     4,     1,     2,     1,     2,     5,
       1,     2,     8,     0,     6,     4,     1,     0,     6,     5,
       1,     2,     0,     5,     1,     2,     1,     1,     1,     5,
       4,     4,     0,     6,     8,    10,     7,     8,     9,    10,
       8,    10,     7,     9,     0,     6,     9,    11,     8,     9,
      10,    11,     9,    11,     8,    10,     0,     5,     3,     0,
       5,     2,     0,     5,     2,     0,     6,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     0,     5,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     2,     2,     0,     5,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     1,     2,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     0,     5,     2,     0,     6,
       6,     7,     8,    10,     1,     2,     2,     0,     6,     3,
       4,     4,     5,     4,     5,     5,     6,     0,     6,     4,
       5,     5,     6,     5,     6,     6,     7,     0,     6,     5,
       6,     6,     7,     6,     7,     7,     8,     4,     4,     4,
       4,     4,     4,     1,     4,     6,     6,     6,     6,     7,
       4,     0,     6,     0,     6,     0,     6,     1,     2,     6,
       5,     6,     6,     8,     9,    10,    12,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     240,     0,   240,     3,     1,   240,   240,   240,     0,     0,
       0,     4,     2,     5,     6,     7,     8,     9,    10,    11,
     236,   237,     0,   235,   234,     0,     0,     0,     0,     0,
     240,   240,     0,     0,   240,     0,   240,   240,   240,   240,
     240,   240,   240,     0,     0,    12,    13,    14,    15,    16,
      26,    17,    18,    27,    24,    25,    23,    19,    22,    20,
      21,   213,   215,   211,     0,     0,   239,     0,     0,   233,
     232,     0,   155,    89,     0,    92,     0,     0,     0,     0,
       0,     0,     0,    52,    86,   240,   240,   240,     0,     0,
       0,     0,    74,   177,     0,     0,    47,     0,    28,   187,
      62,    43,   167,   158,    31,     0,     0,     0,   217,     0,
       0,     0,     0,   227,   228,   229,   230,   231,     0,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,     0,     0,   240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   214,   218,   216,   212,   222,   221,
       0,     0,     0,   240,     0,     0,   240,   156,     0,   157,
      90,    91,     0,     0,     0,    93,    94,    30,     0,     0,
       0,     0,   240,    46,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,    53,     0,    87,     0,     0,     0,
       0,    75,     0,     0,     0,   240,   203,   178,     0,     0,
       0,     0,     0,    48,     0,     0,     0,    29,   188,     0,
      63,     0,   240,    44,     0,   168,     0,   159,     0,     0,
      32,   240,    37,     0,   240,     0,    88,     0,     0,   223,
       0,   240,     0,     0,     0,     0,   240,     0,   199,     0,
       0,     0,     0,     0,   240,     0,     0,     0,     0,     0,
     240,   169,     0,     0,    35,     0,    38,   240,    40,    61,
     240,    54,     0,     0,     0,   224,     0,     0,   240,     0,
       0,     0,   179,     0,     0,     0,     0,     0,   240,    50,
       0,     0,     0,     0,     0,    45,     0,   173,   170,   171,
       0,     0,     0,    34,    36,     0,     0,    33,    41,    55,
      56,    58,    57,    59,   164,     0,   220,     0,   225,     0,
     202,   204,     0,     0,     0,   197,   183,   180,   181,     0,
       0,     0,     0,     0,    51,    49,     0,   189,     0,     0,
       0,    95,   174,   172,   175,   240,     0,   240,     0,     0,
     165,   166,   200,   219,     0,   201,     0,     0,   184,   182,
     185,     0,   205,     0,     0,    60,   198,   193,   190,   191,
     240,     0,   240,     0,   240,   176,     0,     0,     0,   160,
     240,     0,     0,   226,   240,     0,   240,   186,   209,   207,
     206,   194,   192,   195,    66,   240,   240,    72,   240,     0,
     240,    97,   210,     0,   240,   161,    39,     0,    78,   240,
     240,    84,   240,   196,   240,    64,    67,   240,    70,   208,
      98,     0,    99,   101,   102,   103,   100,   104,     0,   162,
       0,   240,    76,    79,   240,    82,    68,   240,   240,    73,
     240,     0,    96,   105,   240,     0,    80,   240,   240,    85,
     240,    65,    69,    71,   106,   163,     0,    77,    81,    83,
     240,    42,     0,     0,   109,   107,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   122,   110,   108,   125,   124,
     116,   117,   118,   119,   120,   111,   113,   114,   115,   112,
       0,     0,     0,     0,   240,     0,   139,   128,   127,   126,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
     152,   153,   123,   154,     0,     0,   141,   148,   146,   144,
     145,   143,   147,   137,   138,     0,   130,   135,   133,   134,
     132,   136,   240,   140,   142,   129,   131,     0,   149
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    11,    12,    45,    46,   131,   168,    47,
     137,   181,   182,   253,   221,   256,   257,   298,    48,   134,
     174,    49,   128,   163,   278,    50,   105,   260,   299,   139,
     513,   514,    51,   133,   171,    52,   121,   152,    53,   106,
     141,    54,    95,   126,    55,    97,   129,   287,   364,   390,
     410,   411,   433,   450,   452,   453,   466,   467,   468,   497,
     515,   516,   469,   496,   505,   506,   507,   470,   471,   472,
     473,   474,    56,    94,   124,    57,   136,   178,   303,   340,
     135,   176,   341,   122,   154,    60,   132,   169,   199,   246,
     508,   226,   234,   194,   195,   509,   510,   511,   512,   292,
      13,    87,    14,    85,    15,    86,   107,   145,    16,    17,
      18,   118,    68,    22,    23,   120,    67,   304
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -278
static const yytype_int16 yypact[] =
{
    -278,     4,    95,  -278,  -278,    79,    79,    79,   -36,   -32,
     -11,  -278,   391,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,     5,  -278,  -278,    27,    51,    79,    79,   114,
      79,    79,    63,    77,    79,    86,    79,    79,    79,    79,
      79,    79,    79,    96,   109,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,    79,    79,  -278,    29,   119,  -278,
    -278,   124,  -278,  -278,   126,  -278,   129,   130,   132,   138,
     139,   141,   152,  -278,  -278,  -278,  -278,  -278,    79,    79,
     202,   137,  -278,  -278,   199,   199,  -278,   199,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,   195,   199,   101,  -278,   105,
     117,   160,   165,  -278,  -278,  -278,  -278,  -278,   176,  -278,
     137,   199,   199,   171,   168,   223,   179,   223,   208,   183,
     223,  -278,   199,   199,   208,   199,   199,   190,   186,   193,
     199,   194,   223,   191,  -278,  -278,  -278,  -278,  -278,  -278,
     137,   137,   198,    80,   205,   251,    79,  -278,   203,  -278,
    -278,  -278,   210,   207,   103,  -278,  -278,   391,   211,   213,
     251,   214,    80,   391,   215,   103,   219,   208,   220,   208,
     226,   228,  -278,   137,  -278,   223,  -278,   271,    79,   137,
      11,  -278,   233,   235,   244,   288,  -278,  -278,   242,   208,
     245,   137,   137,  -278,   243,   250,   247,  -278,  -278,   300,
    -278,   244,   288,  -278,   282,  -278,   103,  -278,   103,    79,
    -278,   274,  -278,   265,  -278,   267,  -278,    79,   137,  -278,
     268,    79,    79,   270,   251,   244,    79,   103,  -278,   137,
     137,   137,   137,   272,  -278,   273,   208,   208,   244,   277,
    -278,    60,    10,    42,  -278,   278,  -278,   315,  -278,  -278,
      59,  -278,   114,    44,     9,  -278,   279,   280,    79,   208,
     251,   284,    60,   137,   137,   137,   137,   137,   287,  -278,
     114,   103,   103,   208,   137,   391,   291,  -278,   118,   295,
     292,   223,   286,  -278,  -278,   114,   293,   391,  -278,  -278,
    -278,  -278,  -278,    87,  -278,   296,  -278,   299,  -278,   114,
    -278,  -278,   310,   103,   208,  -278,  -278,   118,   295,   137,
     311,   137,   137,   312,  -278,    87,   314,    60,   169,   103,
     137,  -278,  -278,   295,  -278,    79,    10,   286,   114,   137,
    -278,  -278,  -278,  -278,   316,  -278,   169,   103,  -278,   295,
    -278,   324,  -278,   326,   327,  -278,  -278,  -278,   118,   295,
    -278,   335,   169,   137,  -278,  -278,   333,   286,   286,    87,
    -278,   334,   137,  -278,  -278,   335,   169,  -278,  -278,  -278,
    -278,  -278,   295,  -278,    68,  -278,  -278,    68,  -278,   336,
     135,  -278,  -278,   286,  -278,    87,  -278,   137,    68,  -278,
    -278,    68,  -278,  -278,  -278,    68,    68,  -278,    68,  -278,
    -278,    14,  -278,  -278,  -278,  -278,  -278,  -278,   286,    87,
     137,  -278,    68,    68,  -278,    68,    87,  -278,  -278,    87,
    -278,   330,  -278,  -278,  -278,   137,    87,  -278,  -278,    87,
    -278,    87,    87,    87,  -278,    87,   337,    87,    87,    87,
    -278,  -278,   338,   626,  -278,  -278,   340,   343,   345,   346,
     347,   348,   355,   359,  -278,  -278,  -278,   -12,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
     137,   137,   137,   137,    79,   137,  -278,  -278,  -278,  -278,
     363,   366,   369,   370,   371,   372,   189,   249,  -278,  -278,
    -278,  -278,  -278,  -278,   360,    84,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,   167,  -278,  -278,  -278,  -278,
    -278,  -278,    79,  -278,  -278,  -278,  -278,   373,  -278
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -278,  -278,  -278,  -278,  -108,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,    99,  -278,  -278,  -278,  -278,
    -205,  -102,  -278,  -278,  -278,  -278,  -278,  -278,   180,  -278,
    -278,  -267,  -278,  -278,   184,  -278,  -278,   227,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,   -70,  -278,
    -278,   -79,   -24,  -278,  -278,   -60,  -278,  -278,  -278,  -278,
    -278,  -278,   192,  -278,  -278,  -278,  -278,  -278,   102,     1,
    -278,  -278,     8,  -278,  -278,  -278,  -278,  -278,  -160,  -278,
     -78,  -278,  -109,   -97,   281,  -110,  -153,  -202,   -74,  -277,
    -278,  -278,  -278,  -278,  -278,  -278,    75,  -278,  -278,  -278,
    -278,  -278,   283,     2,   329,   108,   -46,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
       3,   244,    19,   140,     4,    24,    24,    24,    25,    26,
     209,   206,   250,    58,    66,   337,   125,   127,   164,   130,
      59,    91,   214,   167,   175,    27,   173,   158,   142,    28,
      70,    70,    66,   462,    70,   463,    70,    70,    70,    70,
      70,    70,    70,   153,   155,    20,    21,    20,    21,   288,
      29,   159,   431,   161,   170,   172,   166,   177,   179,   368,
     370,   360,   185,   251,   290,   252,    61,   216,   187,   218,
     317,   308,   309,   229,   269,   211,   432,   158,    32,   374,
      31,    35,    20,    21,   272,   108,   108,   108,    62,   237,
     393,   394,    90,   192,   385,   386,   249,   286,   235,    31,
     123,   158,   247,    40,   293,   286,   306,   193,   399,   400,
     314,   224,    63,   204,   205,   248,   418,    66,   162,    44,
     249,     5,    40,     6,    72,   358,   270,     7,   327,   328,
     504,    19,   204,   205,    19,   158,   281,   282,    73,   283,
     119,   434,   285,     8,   230,     9,   523,    75,    10,   297,
     143,   123,   158,   196,   143,   286,    24,    83,   200,   313,
     346,   109,   110,   144,   204,   205,   143,   146,    58,   162,
      84,   249,   196,   329,    58,    59,   362,   289,   291,   147,
      92,    59,   222,   123,   158,    93,   158,    96,   415,    33,
      98,    99,   138,   100,   376,   196,   204,   205,   318,   101,
     102,   162,   103,   249,   347,   123,   158,   113,   114,   115,
     116,   117,   196,   104,   333,   123,   305,   336,   204,   205,
     138,   258,   148,   162,   261,   249,   243,   149,   151,   525,
     157,    24,   156,   266,   326,   504,    24,   414,   271,   150,
     158,   160,   162,   349,   279,   165,   180,   183,   464,   338,
      19,   478,   188,   359,   361,   184,   186,    19,   189,   190,
     191,   198,   367,   344,   201,   123,   158,   197,    24,   203,
     312,   202,   375,   207,   138,   208,   210,   213,   204,   205,
     413,   215,   217,   162,   382,   249,    58,   219,   388,   225,
     220,   223,   371,    59,   231,   520,   232,   228,    58,   233,
     477,   192,   402,   236,   241,    59,   243,   238,   243,   239,
     240,   242,   412,   520,    71,   245,   416,    74,   249,    76,
      77,    78,    79,    80,    81,    82,   255,   259,   262,   296,
     265,   268,   286,   277,   280,    24,   264,   366,   284,   295,
     290,   310,   311,   476,   519,    43,   315,   273,   274,   275,
     276,   465,   331,   335,   339,    33,    64,    65,   342,    69,
      69,   343,   519,    69,   391,    69,    69,    69,    69,    69,
      69,    69,   345,   352,   355,   475,   356,   324,   373,   479,
     325,   319,   320,   321,   322,   323,   378,   518,   379,   380,
     417,   444,   330,    88,    89,   392,   396,   488,   409,   451,
     455,   480,    30,    31,   481,   518,   482,   483,   484,   485,
      32,    33,    34,    35,    36,    37,   486,   111,   112,   517,
     487,   522,    38,   521,    39,   498,    40,   351,   499,   353,
     354,   500,   501,   502,   503,   528,   526,   517,   363,   369,
     300,   521,    41,   489,   301,   524,     0,   372,    42,    43,
     454,    44,   302,   212,     0,     0,     0,     0,     0,     0,
       0,     0,   384,     0,   387,     0,     0,     0,     0,     0,
       0,   389,   395,     0,     0,     0,   398,     0,   401,     0,
     397,     0,     0,     0,    24,     0,   494,   405,   406,     0,
     408,     0,     0,     0,     0,     0,   419,     0,     0,   316,
       0,   422,   423,     0,   425,   420,   426,     0,     0,   429,
       0,     0,     0,     0,     0,   332,   334,   227,     0,     0,
       0,     0,    24,   436,   527,     0,   439,     0,   435,   441,
     442,     0,   443,     0,     0,     0,   445,     0,     0,   447,
     448,     0,   449,   446,   348,   350,     0,     0,   254,     0,
       0,     0,     0,     0,   357,     0,   263,     0,     0,     0,
     365,   267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,   294,     0,     0,   381,   383,     0,   490,   491,
     492,   493,   307,   495,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   403,
       0,   404,     0,     0,   407,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   421,     0,     0,   424,     0,
       0,     0,   427,   428,     0,   430,     0,     0,     0,     0,
       0,     0,   123,   158,     0,     0,     0,     0,     0,   437,
     438,   138,   440,     0,     0,   204,   205,     0,     0,     0,
     162,     0,   249,     0,     0,   456,   457,   458,   459,   460,
     461,   462,     0,   463,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   243
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-278)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,   206,     2,   105,     0,     5,     6,     7,     6,     7,
     170,   164,   214,    12,     3,   292,    94,    95,   128,    97,
      12,    67,   175,   131,   134,    61,   134,    17,   106,    61,
      30,    31,     3,    45,    34,    47,    36,    37,    38,    39,
      40,    41,    42,   121,   122,     3,     4,     3,     4,   251,
      61,   125,    38,   127,   132,   133,   130,   135,   136,   336,
     337,   328,   140,   216,    54,   218,    61,   177,   142,   179,
     272,    62,    63,    62,   234,   172,    62,    17,    19,   346,
      12,    22,     3,     4,   237,    85,    86,    87,    61,   199,
     367,   368,    63,    13,   361,   362,    36,    37,   195,    12,
      16,    17,   211,    35,    62,    37,    62,    27,   375,   376,
     270,   185,    61,    29,    30,   212,   393,     3,    34,    60,
      36,    26,    35,    28,    61,   327,   235,    32,   281,   282,
      46,   131,    29,    30,   134,    17,   246,   247,    61,   248,
       3,   418,   250,    48,   190,    50,    62,    61,    53,   257,
      49,    16,    17,   153,    49,    37,   156,    61,   156,   269,
     313,    86,    87,    62,    29,    30,    49,    62,   167,    34,
      61,    36,   172,   283,   173,   167,   329,   251,   252,    62,
      61,   173,   182,    16,    17,    61,    17,    61,   390,    20,
      61,    61,    25,    61,   347,   195,    29,    30,   272,    61,
      61,    34,    61,    36,   314,    16,    17,     5,     6,     7,
       8,     9,   212,    61,   288,    16,   262,   291,    29,    30,
      25,   221,    62,    34,   224,    36,    59,    62,   120,    62,
      62,   231,    61,   231,   280,    46,   236,   390,   236,    63,
      17,    62,    34,   317,   244,    62,    56,    61,   453,   295,
     250,   453,    61,   327,   328,    62,    62,   257,   150,   151,
      62,    10,   336,   309,    61,    16,    17,    62,   268,    62,
     268,    61,   346,    62,    25,    62,    62,    62,    29,    30,
     390,    62,    62,    34,   358,    36,   285,    61,   362,    18,
      62,   183,   338,   285,    61,   497,    61,   189,   297,    55,
     453,    13,   376,    61,    61,   297,    59,    62,    59,   201,
     202,    61,   390,   515,    31,    15,   390,    34,    36,    36,
      37,    38,    39,    40,    41,    42,    52,    62,    61,    14,
      62,    61,    37,    61,    61,   335,   228,   335,    61,    61,
      54,    62,    62,   453,   497,    58,    62,   239,   240,   241,
     242,   453,    61,    61,    61,    20,    27,    28,    62,    30,
      31,    62,   515,    34,   364,    36,    37,    38,    39,    40,
      41,    42,    62,    62,    62,   453,    62,   278,    62,   453,
     278,   273,   274,   275,   276,   277,    62,   497,    62,    62,
     390,    61,   284,    64,    65,    62,    62,   467,    62,    62,
      62,    61,    11,    12,    61,   515,    61,    61,    61,    61,
      19,    20,    21,    22,    23,    24,    61,    88,    89,   497,
      61,    61,    31,   497,    33,    62,    35,   319,    62,   321,
     322,    62,    62,    62,    62,    62,   515,   515,   330,   337,
     260,   515,    51,   467,   260,   505,    -1,   339,    57,    58,
     450,    60,   260,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   360,    -1,   362,    -1,    -1,    -1,    -1,    -1,
      -1,   363,   370,    -1,    -1,    -1,   374,    -1,   376,    -1,
     372,    -1,    -1,    -1,   484,    -1,   484,   385,   386,    -1,
     388,    -1,    -1,    -1,    -1,    -1,   394,    -1,    -1,   272,
      -1,   399,   400,    -1,   402,   397,   404,    -1,    -1,   407,
      -1,    -1,    -1,    -1,    -1,   288,   289,   188,    -1,    -1,
      -1,    -1,   522,   421,   522,    -1,   424,    -1,   420,   427,
     428,    -1,   430,    -1,    -1,    -1,   434,    -1,    -1,   437,
     438,    -1,   440,   435,   317,   318,    -1,    -1,   219,    -1,
      -1,    -1,    -1,    -1,   327,    -1,   227,    -1,    -1,    -1,
     333,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,
      -1,    -1,   253,    -1,    -1,   358,   359,    -1,   480,   481,
     482,   483,   263,   485,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   382,
      -1,   384,    -1,    -1,   387,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   398,    -1,    -1,   401,    -1,
      -1,    -1,   405,   406,    -1,   408,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    -1,   422,
     423,    25,   425,    -1,    -1,    29,    30,    -1,    -1,    -1,
      34,    -1,    36,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,    66,   181,     0,    26,    28,    32,    48,    50,
      53,    67,    68,   164,   166,   168,   172,   173,   174,   181,
       3,     4,   177,   178,   181,   177,   177,    61,    61,    61,
      11,    12,    19,    20,    21,    22,    23,    24,    31,    33,
      35,    51,    57,    58,    60,    69,    70,    73,    82,    85,
      89,    96,    99,   102,   105,   108,   136,   139,   143,   146,
     149,    61,    61,    61,   178,   178,     3,   180,   176,   178,
     181,   176,    61,    61,   176,    61,   176,   176,   176,   176,
     176,   176,   176,    61,    61,   167,   169,   165,   178,   178,
      63,   180,    61,    61,   137,   106,    61,   109,    61,    61,
      61,    61,    61,    61,    61,    90,   103,   170,   181,   170,
     170,   178,   178,     5,     6,     7,     8,     9,   175,     3,
     179,   100,   147,    16,   138,   154,   107,   154,    86,   110,
     154,    71,   150,    97,    83,   144,   140,    74,    25,    93,
      95,   104,   154,    49,    62,   171,    62,    62,    62,    62,
      63,   179,   101,   154,   148,   154,    61,    62,    17,   162,
      62,   162,    34,    87,   159,    62,   162,    68,    72,   151,
     154,    98,   154,    68,    84,   159,   145,   154,   141,   154,
      56,    75,    76,    61,    62,   154,    62,   162,    61,   179,
     179,    62,    13,    27,   157,   158,   181,    62,    10,   152,
     177,    61,    61,    62,    29,    30,   160,    62,    62,   152,
      62,   157,   158,    62,   160,    62,   159,    62,   159,    61,
      62,    78,   181,   179,   162,    18,   155,   178,   179,    62,
     180,    61,    61,    55,   156,   157,    61,   159,    62,   179,
     179,    61,    61,    59,    94,    15,   153,   156,   157,    36,
     161,   160,   160,    77,   178,    52,    79,    80,   181,    62,
      91,   181,    61,   178,   179,    62,   177,   178,    61,   152,
     156,   177,   160,   179,   179,   179,   179,    61,    88,   181,
      61,   159,   159,   156,    61,    68,    37,   111,   161,   162,
      54,   162,   163,    62,   178,    61,    14,    68,    81,    92,
     102,   108,   136,   142,   181,   180,    62,   178,    62,    63,
      62,    62,   177,   159,   152,    62,   111,   161,   162,   179,
     179,   179,   179,   179,    89,   142,   180,   160,   160,   159,
     179,    61,   111,   162,   111,    61,   162,   163,   180,    61,
     143,   146,    62,    62,   180,    62,   160,   159,   111,   162,
     111,   179,    62,   179,   179,    62,    62,   111,   161,   162,
     105,   162,   160,   179,   112,   111,   177,   162,   163,   142,
     163,   180,   179,    62,   105,   162,   160,   111,    62,    62,
      62,   111,   162,   111,   142,   105,   105,   142,   162,   179,
     113,   181,    62,   163,   163,   142,    62,   179,   142,   105,
     105,   142,   162,   111,   111,   142,   142,   111,   142,    62,
     114,   115,   154,   159,   160,   161,   162,   181,   163,   142,
     179,   111,   142,   142,   111,   142,   142,   111,   111,   142,
     111,    38,    62,   116,   163,   179,   142,   111,   111,   142,
     111,   142,   142,   142,    61,   142,   179,   142,   142,   142,
     117,    62,   118,   119,   181,    62,    39,    40,    41,    42,
      43,    44,    45,    47,    94,    95,   120,   121,   122,   126,
     131,   132,   133,   134,   135,   154,   159,   160,   161,   162,
      61,    61,    61,    61,    61,    61,    61,    61,   122,   126,
     179,   179,   179,   179,   177,   179,   127,   123,    62,    62,
      62,    62,    62,    62,    46,   128,   129,   130,   154,   159,
     160,   161,   162,    94,    95,   124,   125,   154,   159,   160,
     161,   162,    61,    62,   129,    62,   125,   177,    62
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
/* Line 1792 of yacc.c  */
#line 185 "parser.yxx"
    {
  dna_stack.back()->add((yyvsp[(2) - (2)]._dna_group));
}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 211 "parser.yxx"
    {
  dna_stack.push_back(new DNAGroup((yyvsp[(2) - (3)]._string)));
}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 215 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 223 "parser.yxx"
    {
}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 231 "parser.yxx"
    {
  DNAVisGroup *vis_group = new DNAVisGroup((yyvsp[(2) - (3)]._string));

  // Get the name of the current vis group and make it globaly available:
  g_current_zone_name = vis_group->get_name();

  dna_cat.debug() << "current_zone " << g_current_zone_name <<"\n";

  dna_stack.push_back(vis_group);
  // This dna vis group needs to be stored now before we traverse
  // because the AI does not ever traverse but needs the vis groups
  dna_top_node->get_dna_storage()->store_DNAVisGroupAI(vis_group);
}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 245 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 253 "parser.yxx"
    {
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 260 "parser.yxx"
    {
}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 267 "parser.yxx"
    {
  DNAVisGroup *visgroup = DCAST(DNAVisGroup, dna_stack.back());
  visgroup->add_visible((yyvsp[(1) - (1)]._string));
}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 272 "parser.yxx"
    {
  DNAVisGroup *visgroup = DCAST(DNAVisGroup, dna_stack.back());
  visgroup->add_visible((yyvsp[(2) - (2)]._string));
}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 281 "parser.yxx"
    {
}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 289 "parser.yxx"
    {
  // The top node on the stack should be the dnaVisGroup
  DNAVisGroup *vis_group = DCAST(DNAVisGroup, dna_stack.back());

  // Get the name of the current vis group so we can store that in the edge
  std::string current_zone = vis_group->get_name();

  // Store the edge in the dna storage
  PT(DNASuitEdge) edge = dna_top_node->get_dna_storage()->store_suit_edge((int)(yyvsp[(3) - (5)]._number), (int)(yyvsp[(4) - (5)]._number), current_zone);

  // Record this edge with the current vis group in case he needs to write it back out
  vis_group->add_suit_edge(edge);
}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 310 "parser.yxx"
    {
}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 317 "parser.yxx"
    {
  // Make a new battle cell
  PT(DNABattleCell) cell = new DNABattleCell((yyvsp[(3) - (8)]._number), (yyvsp[(4) - (8)]._number), LPoint3f((yyvsp[(5) - (8)]._number), (yyvsp[(6) - (8)]._number), (yyvsp[(7) - (8)]._number)));

  // Store the battle cell in the dna storage
  dna_top_node->get_dna_storage()->store_battle_cell(cell);

  // Record this battle cell with the current vis group in case he needs to write it back out
  // The top node on the stack should be the dnaVisGroup
  DNAVisGroup *vis_group = DCAST(DNAVisGroup, dna_stack.back());
  vis_group->add_battle_cell(cell);
}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 335 "parser.yxx"
    {
  dna_stack.push_back(new DNANode((yyvsp[(2) - (3)]._string)));
}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 339 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 347 "parser.yxx"
    {
  DNANode *node = DCAST(DNANode, dna_stack.back());
  node->set_pos((yyvsp[(1) - (4)]._v3));
  node->set_hpr((yyvsp[(2) - (4)]._v3));
  node->set_scale((yyvsp[(3) - (4)]._v3));
}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 354 "parser.yxx"
    {
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 361 "parser.yxx"
    {
  dna_stack.push_back(new DNAFlatBuilding((yyvsp[(2) - (3)]._string)));
}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 365 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 373 "parser.yxx"
    {
  DNAFlatBuilding *building = DCAST(DNAFlatBuilding, dna_stack.back());
  building->set_pos((yyvsp[(1) - (5)]._v3));
  building->set_hpr((yyvsp[(2) - (5)]._v3));
  building->set_width((yyvsp[(3) - (5)]._number));
}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 388 "parser.yxx"
    {
  DNAWall *wall = new DNAWall();
  dna_stack.back()->add(wall);
  dna_stack.push_back(wall);
}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 394 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 413 "parser.yxx"
    {
  DNAWall *wall = DCAST(DNAWall, dna_stack.back());
  wall->set_height((yyvsp[(1) - (5)]._number));
  wall->set_code((yyvsp[(2) - (5)]._string));
  wall->set_color((yyvsp[(3) - (5)]._color));
}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 423 "parser.yxx"
    {
  (yyval._number) = (yyvsp[(3) - (4)]._number);
}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 430 "parser.yxx"
    {
  (yyval._number) = (yyvsp[(3) - (4)]._number);
}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 438 "parser.yxx"
    {
  // Store info on which blocks are in each zone:
  dna_top_node->get_dna_storage()->store_block_number((yyvsp[(2) - (3)]._string), g_current_zone_name);
  dna_stack.push_back(new DNALandmarkBuilding((yyvsp[(2) - (3)]._string)));
}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 444 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 453 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (8)]._string));
  building->set_article((yyvsp[(2) - (8)]._string));
  building->set_title((yyvsp[(3) - (8)]._string));
  building->set_pos((yyvsp[(4) - (8)]._v3));
  building->set_hpr((yyvsp[(5) - (8)]._v3));
  building->set_wall_color((yyvsp[(6) - (8)]._color));
}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 463 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (10)]._string));
  building->set_article((yyvsp[(2) - (10)]._string));
  building->set_title((yyvsp[(3) - (10)]._string));
  building->set_pos((yyvsp[(4) - (10)]._v3));
  building->set_hpr((yyvsp[(5) - (10)]._v3));
  building->set_wall_color((yyvsp[(6) - (10)]._color));
}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 473 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (7)]._string));
  building->set_article((yyvsp[(2) - (7)]._string));
  building->set_title((yyvsp[(3) - (7)]._string));
  building->set_pos((yyvsp[(4) - (7)]._v3));
  building->set_hpr((yyvsp[(5) - (7)]._v3));
}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 482 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (8)]._string));
  if (!((yyvsp[(2) - (8)]._string)).empty()) {
    building->set_building_type((yyvsp[(2) - (8)]._string));
    // Record this building type at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[(2) - (8)]._string));
  }
  building->set_article((yyvsp[(3) - (8)]._string));
  building->set_title((yyvsp[(4) - (8)]._string));
  building->set_pos((yyvsp[(5) - (8)]._v3));
  building->set_hpr((yyvsp[(6) - (8)]._v3));
}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 496 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (9)]._string));
  building->set_article((yyvsp[(2) - (9)]._string));
  building->set_title((yyvsp[(3) - (9)]._string));
  building->set_pos((yyvsp[(4) - (9)]._v3));
  building->set_hpr((yyvsp[(5) - (9)]._v3));
}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 505 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (10)]._string));
  if (!((yyvsp[(2) - (10)]._string)).empty()) {
    building->set_building_type((yyvsp[(2) - (10)]._string));
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[(2) - (10)]._string));
  }
  building->set_article((yyvsp[(3) - (10)]._string));
  building->set_title((yyvsp[(4) - (10)]._string));
  building->set_pos((yyvsp[(5) - (10)]._v3));
  building->set_hpr((yyvsp[(6) - (10)]._v3));
}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 519 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (8)]._string));
  if (!((yyvsp[(2) - (8)]._string)).empty()) {
    building->set_building_type((yyvsp[(2) - (8)]._string));
    // Record this headquarter at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[(2) - (8)]._string));
  }
  building->set_article((yyvsp[(3) - (8)]._string));
  building->set_title((yyvsp[(4) - (8)]._string));
  building->set_pos((yyvsp[(5) - (8)]._v3));
  building->set_hpr((yyvsp[(6) - (8)]._v3));
  building->set_wall_color((yyvsp[(7) - (8)]._color));
}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 534 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (10)]._string));
  if (!((yyvsp[(2) - (10)]._string)).empty()) {
    building->set_building_type((yyvsp[(2) - (10)]._string));
    // Record this headquarter at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[(2) - (10)]._string));
  }
  building->set_article((yyvsp[(3) - (10)]._string));
  building->set_title((yyvsp[(4) - (10)]._string));
  building->set_pos((yyvsp[(5) - (10)]._v3));
  building->set_hpr((yyvsp[(6) - (10)]._v3));
  building->set_wall_color((yyvsp[(7) - (10)]._color));
}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 549 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (7)]._string));
  if (!((yyvsp[(2) - (7)]._string)).empty()) {
    building->set_building_type((yyvsp[(2) - (7)]._string));
    // Record this headquarter at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[(2) - (7)]._string));
  }
  building->set_article((yyvsp[(3) - (7)]._string));
  building->set_title((yyvsp[(4) - (7)]._string));
  building->set_pos((yyvsp[(5) - (7)]._v3));
  building->set_hpr((yyvsp[(6) - (7)]._v3));
}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 563 "parser.yxx"
    {
  DNALandmarkBuilding *building = DCAST(DNALandmarkBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (9)]._string));
  if (!((yyvsp[(2) - (9)]._string)).empty()) {
    building->set_building_type((yyvsp[(2) - (9)]._string));
    // Record this headquarter at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[(2) - (9)]._string));
  }
  building->set_article((yyvsp[(3) - (9)]._string));
  building->set_title((yyvsp[(4) - (9)]._string));
  building->set_pos((yyvsp[(5) - (9)]._v3));
  building->set_hpr((yyvsp[(6) - (9)]._v3));
}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 580 "parser.yxx"
    {
  // Store info on which blocks are in each zone:
  dna_top_node->get_dna_storage()->store_block_number((yyvsp[(2) - (3)]._string), g_current_zone_name);
  dna_stack.push_back(new DNAAnimBuilding((yyvsp[(2) - (3)]._string)));
}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 586 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 595 "parser.yxx"
    {
  DNAAnimBuilding *building = DCAST(DNAAnimBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (9)]._string));
  building->set_article((yyvsp[(2) - (9)]._string));
  building->set_title((yyvsp[(3) - (9)]._string));
  building->set_anim((yyvsp[(4) - (9)]._string));
  building->set_pos((yyvsp[(5) - (9)]._v3));
  building->set_hpr((yyvsp[(6) - (9)]._v3));
  building->set_wall_color((yyvsp[(7) - (9)]._color));
}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 606 "parser.yxx"
    {
  DNAAnimBuilding *building = DCAST(DNAAnimBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (11)]._string));
  building->set_article((yyvsp[(2) - (11)]._string));
  building->set_title((yyvsp[(3) - (11)]._string));
  building->set_anim((yyvsp[(4) - (11)]._string));
  building->set_pos((yyvsp[(5) - (11)]._v3));
  building->set_hpr((yyvsp[(6) - (11)]._v3));
  building->set_wall_color((yyvsp[(7) - (11)]._color));
}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 617 "parser.yxx"
    {
  DNAAnimBuilding *building = DCAST(DNAAnimBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (8)]._string));
  building->set_article((yyvsp[(2) - (8)]._string));
  building->set_title((yyvsp[(3) - (8)]._string));
  building->set_anim((yyvsp[(4) - (8)]._string));
  building->set_pos((yyvsp[(5) - (8)]._v3));
  building->set_hpr((yyvsp[(6) - (8)]._v3));
}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 627 "parser.yxx"
    {
  DNAAnimBuilding *building = DCAST(DNAAnimBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (9)]._string));
  if (!((yyvsp[(2) - (9)]._string)).empty()) {
    building->set_building_type((yyvsp[(2) - (9)]._string));
    // Record this building type at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[(2) - (9)]._string));
  }
  building->set_article((yyvsp[(3) - (9)]._string));
  building->set_title((yyvsp[(4) - (9)]._string));
  building->set_anim((yyvsp[(5) - (9)]._string));
  building->set_pos((yyvsp[(6) - (9)]._v3));
  building->set_hpr((yyvsp[(7) - (9)]._v3));
}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 642 "parser.yxx"
    {
  DNAAnimBuilding *building = DCAST(DNAAnimBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (10)]._string));
  building->set_article((yyvsp[(2) - (10)]._string));
  building->set_title((yyvsp[(3) - (10)]._string));
  building->set_anim((yyvsp[(4) - (10)]._string));
  building->set_pos((yyvsp[(5) - (10)]._v3));
  building->set_hpr((yyvsp[(6) - (10)]._v3));
}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 652 "parser.yxx"
    {
  DNAAnimBuilding *building = DCAST(DNAAnimBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (11)]._string));
  if (!((yyvsp[(2) - (11)]._string)).empty()) {
    building->set_building_type((yyvsp[(2) - (11)]._string));
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[(2) - (11)]._string));
  }
  building->set_article((yyvsp[(3) - (11)]._string));
  building->set_title((yyvsp[(4) - (11)]._string));
  building->set_anim((yyvsp[(5) - (11)]._string));
  building->set_pos((yyvsp[(6) - (11)]._v3));
  building->set_hpr((yyvsp[(7) - (11)]._v3));
}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 667 "parser.yxx"
    {
  DNAAnimBuilding *building = DCAST(DNAAnimBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (9)]._string));
  if (!((yyvsp[(2) - (9)]._string)).empty()) {
    building->set_building_type((yyvsp[(2) - (9)]._string));
    // Record this headquarter at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[(2) - (9)]._string));
  }
  building->set_article((yyvsp[(3) - (9)]._string));
  building->set_title((yyvsp[(4) - (9)]._string));
  building->set_anim((yyvsp[(5) - (9)]._string));
  building->set_pos((yyvsp[(6) - (9)]._v3));
  building->set_hpr((yyvsp[(7) - (9)]._v3));
  building->set_wall_color((yyvsp[(8) - (9)]._color));
}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 683 "parser.yxx"
    {
  DNAAnimBuilding *building = DCAST(DNAAnimBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (11)]._string));
  if (!((yyvsp[(2) - (11)]._string)).empty()) {
    building->set_building_type((yyvsp[(2) - (11)]._string));
    // Record this headquarter at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[(2) - (11)]._string));
  }
  building->set_article((yyvsp[(3) - (11)]._string));
  building->set_title((yyvsp[(4) - (11)]._string));
  building->set_anim((yyvsp[(5) - (11)]._string));
  building->set_pos((yyvsp[(6) - (11)]._v3));
  building->set_hpr((yyvsp[(7) - (11)]._v3));
  building->set_wall_color((yyvsp[(8) - (11)]._color));
}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 699 "parser.yxx"
    {
  DNAAnimBuilding *building = DCAST(DNAAnimBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (8)]._string));
  if (!((yyvsp[(2) - (8)]._string)).empty()) {
    building->set_building_type((yyvsp[(2) - (8)]._string));
    // Record this headquarter at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[(2) - (8)]._string));
  }
  building->set_article((yyvsp[(3) - (8)]._string));
  building->set_title((yyvsp[(4) - (8)]._string));
  building->set_anim((yyvsp[(5) - (8)]._string));
  building->set_pos((yyvsp[(6) - (8)]._v3));
  building->set_hpr((yyvsp[(7) - (8)]._v3));
}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 714 "parser.yxx"
    {
  DNAAnimBuilding *building = DCAST(DNAAnimBuilding, dna_stack.back());
  building->set_code((yyvsp[(1) - (10)]._string));
  if (!((yyvsp[(2) - (10)]._string)).empty()) {
    building->set_building_type((yyvsp[(2) - (10)]._string));
    // Record this headquarter at this block in the storage
    dna_top_node->get_dna_storage()->store_block_building_type(building->get_name(), (yyvsp[(2) - (10)]._string));
  }
  building->set_article((yyvsp[(3) - (10)]._string));
  building->set_title((yyvsp[(4) - (10)]._string));
  building->set_anim((yyvsp[(5) - (10)]._string));
  building->set_pos((yyvsp[(6) - (10)]._v3));
  building->set_hpr((yyvsp[(7) - (10)]._v3));
}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 732 "parser.yxx"
    {
  DNAWindows *windows = new DNAWindows();
  dna_stack.back()->add(windows);
  dna_stack.push_back(windows);
}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 738 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 746 "parser.yxx"
    {
  DNAWindows *windows = DCAST(DNAWindows, dna_stack.back());
  windows->set_code((yyvsp[(1) - (3)]._string));
  windows->set_color((yyvsp[(2) - (3)]._color));
  windows->set_window_count((int)(yyvsp[(3) - (3)]._number));
}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 756 "parser.yxx"
    {
  DNADoor *door = new DNADoor();
  dna_stack.back()->add(door);
  dna_stack.push_back(door);
}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 762 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 770 "parser.yxx"
    {
  DNADoor *door = DCAST(DNADoor, dna_stack.back());
  door->set_code((yyvsp[(1) - (2)]._string));
  door->set_color((yyvsp[(2) - (2)]._color));
}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 781 "parser.yxx"
    {
  DNAFlatDoor *door = new DNAFlatDoor();
  dna_stack.back()->add(door);
  dna_stack.push_back(door);
}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 787 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 795 "parser.yxx"
    {
  DNAFlatDoor *door = DCAST(DNAFlatDoor, dna_stack.back());
  door->set_code((yyvsp[(1) - (2)]._string));
  door->set_color((yyvsp[(2) - (2)]._color));
}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 806 "parser.yxx"
    {
  DNASign *sign = new DNASign();
  dna_stack.back()->add(sign);
  dna_stack.push_back(sign);
}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 812 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 825 "parser.yxx"
    {
  DNASign *sign = DCAST(DNASign, dna_stack.back());
  sign->set_code((yyvsp[(1) - (1)]._string));
}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 830 "parser.yxx"
    {
  DNASign *sign = DCAST(DNASign, dna_stack.back());
  sign->set_color((yyvsp[(1) - (1)]._color));
}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 835 "parser.yxx"
    {
  DNASign *sign = DCAST(DNASign, dna_stack.back());
  sign->set_pos((yyvsp[(1) - (1)]._v3));
}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 840 "parser.yxx"
    {
  DNASign *sign = DCAST(DNASign, dna_stack.back());
  sign->set_hpr((yyvsp[(1) - (1)]._v3));
}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 845 "parser.yxx"
    {
  DNASign *sign = DCAST(DNASign, dna_stack.back());
  sign->set_scale((yyvsp[(1) - (1)]._v3));
}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 858 "parser.yxx"
    {
  DNASignBaseline *baseline = new DNASignBaseline();
  dna_stack.back()->add(baseline);
  dna_stack.push_back(baseline);
}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 864 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 881 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_code((yyvsp[(1) - (1)]._string));
}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 886 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_color((yyvsp[(1) - (1)]._color));
}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 891 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_pos((yyvsp[(1) - (1)]._v3));
}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 896 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_hpr((yyvsp[(1) - (1)]._v3));
}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 901 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_scale((yyvsp[(1) - (1)]._v3));
}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 911 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_width((yyvsp[(1) - (1)]._number));
}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 916 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_height((yyvsp[(1) - (1)]._number));
}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 921 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_flags((yyvsp[(3) - (4)]._string));
}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 936 "parser.yxx"
    {
  DNASignGraphic *graphic = new DNASignGraphic();
  dna_stack.back()->add(graphic);
  dna_stack.push_back(graphic);
}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 942 "parser.yxx"
    {
  dna_stack.pop_back();
}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 954 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_scale((yyvsp[(1) - (1)]._v3));
}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 959 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_pos((yyvsp[(1) - (1)]._v3));
}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 964 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_hpr((yyvsp[(1) - (1)]._v3));
}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 969 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_code((yyvsp[(1) - (1)]._string));
}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 974 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_color((yyvsp[(1) - (1)]._color));
}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 979 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_width((yyvsp[(1) - (1)]._number));
}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 984 "parser.yxx"
    {
  DNASignGraphic *graphic = DCAST(DNASignGraphic, dna_stack.back());
  graphic->set_height((yyvsp[(1) - (1)]._number));
}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 992 "parser.yxx"
    {
  DNASignText *text = new DNASignText();
  dna_stack.back()->add(text);
  dna_stack.push_back(text);
}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 998 "parser.yxx"
    {
  dna_stack.pop_back();
}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 1010 "parser.yxx"
    {
  DNASignText *text = DCAST(DNASignText, dna_stack.back());
  text->set_scale((yyvsp[(1) - (1)]._v3));
}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 1015 "parser.yxx"
    {
  DNASignText *text = DCAST(DNASignText, dna_stack.back());
  text->set_pos((yyvsp[(1) - (1)]._v3));
}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 1020 "parser.yxx"
    {
  DNASignText *text = DCAST(DNASignText, dna_stack.back());
  text->set_hpr((yyvsp[(1) - (1)]._v3));
}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1025 "parser.yxx"
    {
  DNASignText *text = DCAST(DNASignText, dna_stack.back());
  text->set_code((yyvsp[(1) - (1)]._string));
}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1030 "parser.yxx"
    {
  DNASignText *text = DCAST(DNASignText, dna_stack.back());
  text->set_color((yyvsp[(1) - (1)]._color));
}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1035 "parser.yxx"
    {
  DNASignText *text = DCAST(DNASignText, dna_stack.back());
  text->set_letters((yyvsp[(1) - (1)]._string));
}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1043 "parser.yxx"
    {
  (yyval._string) = (yyvsp[(3) - (4)]._string);
}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1050 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_indent((yyvsp[(3) - (4)]._number));
}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1058 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_kern((yyvsp[(3) - (4)]._number));
}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1066 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_wiggle((yyvsp[(3) - (4)]._number));
}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1074 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_stumble((yyvsp[(3) - (4)]._number));
}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 1082 "parser.yxx"
    {
  DNASignBaseline *baseline = DCAST(DNASignBaseline, dna_stack.back());
  baseline->set_stomp((yyvsp[(3) - (4)]._number));
}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1090 "parser.yxx"
    {
  DNACornice *cornice = new DNACornice();
  dna_stack.back()->add(cornice);
  dna_stack.push_back(cornice);
}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1096 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1104 "parser.yxx"
    {
  DNACornice *cornice = DCAST(DNACornice, dna_stack.back());
  cornice->set_code((yyvsp[(1) - (2)]._string));
  cornice->set_color((yyvsp[(2) - (2)]._color));
}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1113 "parser.yxx"
    {
  dna_stack.push_back(new DNAStreet((yyvsp[(2) - (3)]._string)));
}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1117 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1125 "parser.yxx"
    {
  DNAStreet *street = DCAST(DNAStreet, dna_stack.back());
  street->set_code((yyvsp[(1) - (6)]._string));
  street->set_pos((yyvsp[(2) - (6)]._v3));
  street->set_hpr((yyvsp[(3) - (6)]._v3));
  street->set_street_texture((yyvsp[(4) - (6)]._string));
  street->set_sidewalk_texture((yyvsp[(5) - (6)]._string));
  // No curb texture specified, just use the sidewalk texture
  street->set_curb_texture((yyvsp[(5) - (6)]._string));
}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1136 "parser.yxx"
    {
  DNAStreet *street = DCAST(DNAStreet, dna_stack.back());
  street->set_code((yyvsp[(1) - (7)]._string));
  street->set_pos((yyvsp[(2) - (7)]._v3));
  street->set_hpr((yyvsp[(3) - (7)]._v3));
  street->set_street_texture((yyvsp[(4) - (7)]._string));
  street->set_sidewalk_texture((yyvsp[(5) - (7)]._string));
  street->set_curb_texture((yyvsp[(6) - (7)]._string));
}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1146 "parser.yxx"
    {
  DNAStreet *street = DCAST(DNAStreet, dna_stack.back());
  street->set_code((yyvsp[(1) - (8)]._string));
  street->set_pos((yyvsp[(2) - (8)]._v3));
  street->set_hpr((yyvsp[(3) - (8)]._v3));
  street->set_street_color((yyvsp[(4) - (8)]._color));
  street->set_sidewalk_color((yyvsp[(5) - (8)]._color));
  // No curb color specified, just use sidewalk color
  street->set_curb_color((yyvsp[(5) - (8)]._color));
  street->set_street_texture((yyvsp[(6) - (8)]._string));
  street->set_sidewalk_texture((yyvsp[(7) - (8)]._string));
  // No curb texture specified, just use sidewalk texture
  street->set_curb_texture((yyvsp[(7) - (8)]._string));
}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1161 "parser.yxx"
    {
  DNAStreet *street = DCAST(DNAStreet, dna_stack.back());
  street->set_code((yyvsp[(1) - (10)]._string));
  street->set_pos((yyvsp[(2) - (10)]._v3));
  street->set_hpr((yyvsp[(3) - (10)]._v3));
  street->set_street_color((yyvsp[(4) - (10)]._color));
  street->set_sidewalk_color((yyvsp[(5) - (10)]._color));
  street->set_curb_color((yyvsp[(6) - (10)]._color));
  street->set_street_texture((yyvsp[(7) - (10)]._string));
  street->set_sidewalk_texture((yyvsp[(8) - (10)]._string));
  street->set_curb_texture((yyvsp[(9) - (10)]._string));
}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1178 "parser.yxx"
    {
  // Parent this prop to whatever the top of the stack is
  dna_stack.back()->add((yyvsp[(2) - (2)]._dna_group));
}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1183 "parser.yxx"
    {
  // Parent this prop to whatever the top of the stack is
  dna_stack.back()->add((yyvsp[(2) - (2)]._dna_group));
}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1191 "parser.yxx"
    {
  dna_stack.push_back(new DNAProp((yyvsp[(2) - (3)]._string)));
}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1195 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1203 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[(1) - (3)]._string));
  prop->set_pos((yyvsp[(2) - (3)]._v3));
  prop->set_hpr((yyvsp[(3) - (3)]._v3));
}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1210 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[(1) - (4)]._string));
  prop->set_pos((yyvsp[(2) - (4)]._v3));
  prop->set_hpr((yyvsp[(3) - (4)]._v3));
  prop->set_scale((yyvsp[(4) - (4)]._v3));
}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1218 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[(1) - (4)]._string));
  prop->set_pos((yyvsp[(2) - (4)]._v3));
  prop->set_hpr((yyvsp[(3) - (4)]._v3));
  prop->set_color((yyvsp[(4) - (4)]._color));
}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1226 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[(1) - (5)]._string));
  prop->set_pos((yyvsp[(2) - (5)]._v3));
  prop->set_hpr((yyvsp[(3) - (5)]._v3));
  prop->set_scale((yyvsp[(4) - (5)]._v3));
  prop->set_color((yyvsp[(5) - (5)]._color));
}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1235 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[(1) - (4)]._string));
  prop->set_pos((yyvsp[(2) - (4)]._v3));
  prop->set_hpr((yyvsp[(3) - (4)]._v3));
}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1242 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[(1) - (5)]._string));
  prop->set_pos((yyvsp[(2) - (5)]._v3));
  prop->set_hpr((yyvsp[(3) - (5)]._v3));
  prop->set_scale((yyvsp[(4) - (5)]._v3));
}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1250 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[(1) - (5)]._string));
  prop->set_pos((yyvsp[(2) - (5)]._v3));
  prop->set_hpr((yyvsp[(3) - (5)]._v3));
  prop->set_color((yyvsp[(4) - (5)]._color));
}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1258 "parser.yxx"
    {
  DNAProp *prop = DCAST(DNAProp, dna_stack.back());
  prop->set_code((yyvsp[(1) - (6)]._string));
  prop->set_pos((yyvsp[(2) - (6)]._v3));
  prop->set_hpr((yyvsp[(3) - (6)]._v3));
  prop->set_scale((yyvsp[(4) - (6)]._v3));
  prop->set_color((yyvsp[(5) - (6)]._color));
}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1270 "parser.yxx"
    {
  dna_stack.push_back(new DNAAnimProp((yyvsp[(2) - (3)]._string)));
  dna_cat.debug() << "anim prop " << (yyvsp[(2) - (3)]._string) <<"\n";
}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1275 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 1283 "parser.yxx"
    {
  DNAAnimProp *anim_prop = DCAST(DNAAnimProp, dna_stack.back());
  anim_prop->set_code((yyvsp[(1) - (4)]._string));
  anim_prop->set_anim((yyvsp[(2) - (4)]._string));
  anim_prop->set_pos((yyvsp[(3) - (4)]._v3));
  anim_prop->set_hpr((yyvsp[(4) - (4)]._v3));
}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1291 "parser.yxx"
    {
  DNAAnimProp *anim_prop = DCAST(DNAAnimProp, dna_stack.back());
  anim_prop->set_code((yyvsp[(1) - (5)]._string));
  anim_prop->set_anim((yyvsp[(2) - (5)]._string));
  anim_prop->set_pos((yyvsp[(3) - (5)]._v3));
  anim_prop->set_hpr((yyvsp[(4) - (5)]._v3));
  anim_prop->set_scale((yyvsp[(5) - (5)]._v3));
}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1300 "parser.yxx"
    {
  DNAAnimProp *anim_prop = DCAST(DNAAnimProp, dna_stack.back());
  anim_prop->set_code((yyvsp[(1) - (5)]._string));
  anim_prop->set_anim((yyvsp[(2) - (5)]._string));
  anim_prop->set_pos((yyvsp[(3) - (5)]._v3));
  anim_prop->set_hpr((yyvsp[(4) - (5)]._v3));
  anim_prop->set_color((yyvsp[(5) - (5)]._color));
}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1309 "parser.yxx"
    {
  DNAAnimProp *anim_prop = DCAST(DNAAnimProp, dna_stack.back());
  anim_prop->set_code((yyvsp[(1) - (6)]._string));
  anim_prop->set_anim((yyvsp[(2) - (6)]._string));
  anim_prop->set_pos((yyvsp[(3) - (6)]._v3));
  anim_prop->set_hpr((yyvsp[(4) - (6)]._v3));
  anim_prop->set_scale((yyvsp[(5) - (6)]._v3));
  anim_prop->set_color((yyvsp[(6) - (6)]._color));
}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1319 "parser.yxx"
    {
  DNAAnimProp *anim_prop = DCAST(DNAAnimProp, dna_stack.back());
  anim_prop->set_code((yyvsp[(1) - (5)]._string));
  anim_prop->set_anim((yyvsp[(2) - (5)]._string));
  anim_prop->set_pos((yyvsp[(3) - (5)]._v3));
  anim_prop->set_hpr((yyvsp[(4) - (5)]._v3));
}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1327 "parser.yxx"
    {
  DNAAnimProp *anim_prop = DCAST(DNAAnimProp, dna_stack.back());
  anim_prop->set_code((yyvsp[(1) - (6)]._string));
  anim_prop->set_anim((yyvsp[(2) - (6)]._string));
  anim_prop->set_pos((yyvsp[(3) - (6)]._v3));
  anim_prop->set_hpr((yyvsp[(4) - (6)]._v3));
  anim_prop->set_scale((yyvsp[(5) - (6)]._v3));
}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 1336 "parser.yxx"
    {
  DNAAnimProp *anim_prop = DCAST(DNAAnimProp, dna_stack.back());
  anim_prop->set_code((yyvsp[(1) - (6)]._string));
  anim_prop->set_anim((yyvsp[(2) - (6)]._string));
  anim_prop->set_pos((yyvsp[(3) - (6)]._v3));
  anim_prop->set_hpr((yyvsp[(4) - (6)]._v3));
  anim_prop->set_color((yyvsp[(5) - (6)]._color));
}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1345 "parser.yxx"
    {
  DNAAnimProp *anim_prop = DCAST(DNAAnimProp, dna_stack.back());
  anim_prop->set_code((yyvsp[(1) - (7)]._string));
  anim_prop->set_anim((yyvsp[(2) - (7)]._string));
  anim_prop->set_pos((yyvsp[(3) - (7)]._v3));
  anim_prop->set_hpr((yyvsp[(4) - (7)]._v3));
  anim_prop->set_scale((yyvsp[(5) - (7)]._v3));
  anim_prop->set_color((yyvsp[(6) - (7)]._color));
}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1358 "parser.yxx"
    {
  dna_stack.push_back(new DNAInteractiveProp((yyvsp[(2) - (3)]._string)));
  dna_cat.debug() << "interactive prop " << (yyvsp[(2) - (3)]._string) <<"\n";
}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 1363 "parser.yxx"
    {
  (yyval._dna_group) = dna_stack.back();
  dna_stack.pop_back();
}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1371 "parser.yxx"
    {
  DNAInteractiveProp *interactive_prop = DCAST(DNAInteractiveProp, dna_stack.back());
  interactive_prop->set_code((yyvsp[(1) - (5)]._string));
  interactive_prop->set_anim((yyvsp[(2) - (5)]._string));
  interactive_prop->set_cell_id((yyvsp[(3) - (5)]._number));
  interactive_prop->set_pos((yyvsp[(4) - (5)]._v3));
  interactive_prop->set_hpr((yyvsp[(5) - (5)]._v3));
}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1380 "parser.yxx"
    {
  DNAInteractiveProp *interactive_prop = DCAST(DNAInteractiveProp, dna_stack.back());
  interactive_prop->set_code((yyvsp[(1) - (6)]._string));
  interactive_prop->set_anim((yyvsp[(2) - (6)]._string));
  interactive_prop->set_cell_id((yyvsp[(3) - (6)]._number));
  interactive_prop->set_pos((yyvsp[(4) - (6)]._v3));
  interactive_prop->set_hpr((yyvsp[(5) - (6)]._v3));
  interactive_prop->set_scale((yyvsp[(6) - (6)]._v3));
}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1390 "parser.yxx"
    {
  DNAInteractiveProp *interactive_prop = DCAST(DNAInteractiveProp, dna_stack.back());
  interactive_prop->set_code((yyvsp[(1) - (6)]._string));
  interactive_prop->set_anim((yyvsp[(2) - (6)]._string));
  interactive_prop->set_cell_id((yyvsp[(3) - (6)]._number));
  interactive_prop->set_pos((yyvsp[(4) - (6)]._v3));
  interactive_prop->set_hpr((yyvsp[(5) - (6)]._v3));
  interactive_prop->set_color((yyvsp[(6) - (6)]._color));
}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 1400 "parser.yxx"
    {
  DNAInteractiveProp *interactive_prop = DCAST(DNAInteractiveProp, dna_stack.back());
  interactive_prop->set_code((yyvsp[(1) - (7)]._string));
  interactive_prop->set_anim((yyvsp[(2) - (7)]._string));
  interactive_prop->set_cell_id((yyvsp[(3) - (7)]._number));
  interactive_prop->set_pos((yyvsp[(4) - (7)]._v3));
  interactive_prop->set_hpr((yyvsp[(5) - (7)]._v3));
  interactive_prop->set_scale((yyvsp[(6) - (7)]._v3));
  interactive_prop->set_color((yyvsp[(7) - (7)]._color));
}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 1411 "parser.yxx"
    {
  DNAInteractiveProp *interactive_prop = DCAST(DNAInteractiveProp, dna_stack.back());
  interactive_prop->set_code((yyvsp[(1) - (6)]._string));
  interactive_prop->set_anim((yyvsp[(2) - (6)]._string));
  interactive_prop->set_cell_id((yyvsp[(3) - (6)]._number));
  interactive_prop->set_pos((yyvsp[(4) - (6)]._v3));
  interactive_prop->set_hpr((yyvsp[(5) - (6)]._v3));
}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1420 "parser.yxx"
    {
  DNAInteractiveProp *interactive_prop = DCAST(DNAInteractiveProp, dna_stack.back());
  interactive_prop->set_code((yyvsp[(1) - (7)]._string));
  interactive_prop->set_anim((yyvsp[(2) - (7)]._string));
  interactive_prop->set_cell_id((yyvsp[(3) - (7)]._number));
  interactive_prop->set_pos((yyvsp[(4) - (7)]._v3));
  interactive_prop->set_hpr((yyvsp[(5) - (7)]._v3));
  interactive_prop->set_scale((yyvsp[(6) - (7)]._v3));
}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 1430 "parser.yxx"
    {
  DNAInteractiveProp *interactive_prop = DCAST(DNAInteractiveProp, dna_stack.back());
  interactive_prop->set_code((yyvsp[(1) - (7)]._string));
  interactive_prop->set_anim((yyvsp[(2) - (7)]._string));
  interactive_prop->set_cell_id((yyvsp[(3) - (7)]._number));
  interactive_prop->set_pos((yyvsp[(4) - (7)]._v3));
  interactive_prop->set_hpr((yyvsp[(5) - (7)]._v3));
  interactive_prop->set_color((yyvsp[(6) - (7)]._color));
}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 1440 "parser.yxx"
    {
  DNAInteractiveProp *interactive_prop = DCAST(DNAInteractiveProp, dna_stack.back());
  interactive_prop->set_code((yyvsp[(1) - (8)]._string));
  interactive_prop->set_anim((yyvsp[(2) - (8)]._string));
  interactive_prop->set_cell_id((yyvsp[(3) - (8)]._number));
  interactive_prop->set_pos((yyvsp[(4) - (8)]._v3));
  interactive_prop->set_hpr((yyvsp[(5) - (8)]._v3));
  interactive_prop->set_scale((yyvsp[(6) - (8)]._v3));
  interactive_prop->set_color((yyvsp[(7) - (8)]._color));
}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 1454 "parser.yxx"
    {
  (yyval._string) = (yyvsp[(3) - (4)]._string);
}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 1461 "parser.yxx"
    {
  (yyval._number) = (yyvsp[(3) - (4)]._number);
}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 1468 "parser.yxx"
    {
  (yyval._string) = (yyvsp[(3) - (4)]._string);
}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 1475 "parser.yxx"
    {
  (yyval._number) = (yyvsp[(3) - (4)]._number);
}
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 1482 "parser.yxx"
    {
  (yyval._string) = (yyvsp[(3) - (4)]._string);
}
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 1489 "parser.yxx"
    {
  (yyval._string) = (yyvsp[(3) - (4)]._string);
}
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 1493 "parser.yxx"
    {
  (yyval._string) = "";
}
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 1500 "parser.yxx"
    {
  (yyval._string) = (yyvsp[(3) - (4)]._string);
}
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 1507 "parser.yxx"
    {
  // An apparent compiler bug with MSVC prevents this line from compiling properly:
  //  $$ = LVecBase3f($3, $4, $5);

  // Fortunately, this is functionally equivalent:
  (yyval._v3).set((yyvsp[(3) - (6)]._number), (yyvsp[(4) - (6)]._number), (yyvsp[(5) - (6)]._number));
}
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 1517 "parser.yxx"
    {
  // New (correct) HPR representation
  if (temp_hpr_fix) {
    (yyval._v3).set((yyvsp[(3) - (6)]._number), (yyvsp[(4) - (6)]._number), (yyvsp[(5) - (6)]._number));
  } else {
    //$$ = new_to_old_hpr(LVecBase3f($3, $4, $5));
    (yyval._v3).set((yyvsp[(3) - (6)]._number), (yyvsp[(4) - (6)]._number), (yyvsp[(5) - (6)]._number));
  }
}
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 1527 "parser.yxx"
    {
  // Old (broken) HPR representation
  if (temp_hpr_fix) {
    (yyval._v3) = old_to_new_hpr(LVecBase3f((yyvsp[(3) - (6)]._number), (yyvsp[(4) - (6)]._number), (yyvsp[(5) - (6)]._number)));
  } else {
    (yyval._v3).set((yyvsp[(3) - (6)]._number), (yyvsp[(4) - (6)]._number), (yyvsp[(5) - (6)]._number));
  }
}
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 1538 "parser.yxx"
    {
  (yyval._v3).set((yyvsp[(3) - (6)]._number), (yyvsp[(4) - (6)]._number), (yyvsp[(5) - (6)]._number));
}
    break;

  case 209:
/* Line 1792 of yacc.c  */
#line 1545 "parser.yxx"
    {
  (yyval._color).set((yyvsp[(3) - (7)]._number), (yyvsp[(4) - (7)]._number), (yyvsp[(5) - (7)]._number), (yyvsp[(6) - (7)]._number));
}
    break;

  case 210:
/* Line 1792 of yacc.c  */
#line 1552 "parser.yxx"
    {
  (yyval._string) = (yyvsp[(3) - (4)]._string);
}
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 1564 "parser.yxx"
    {
  // Flag this model as not being for a specific neighborhood
  current_model_hood = 0;
  current_model_place = 0;
  Filename model = (yyvsp[(2) - (3)]._string);
  model.set_extension("bam");
  current_model = NodePath(loader.load_sync(model));
}
    break;

  case 213:
/* Line 1792 of yacc.c  */
#line 1581 "parser.yxx"
    {
  // Flag this model as being for a specific neighborhood
  current_model_hood = 1;
  current_model_place = 0;
  LoaderOptions options;
  options.set_flags(options.get_flags() | LoaderOptions::LF_no_ram_cache);
  Filename model = (yyvsp[(2) - (3)]._string);
  model.set_extension("bam");
  current_model = NodePath(loader.load_sync(model, options));
}
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 1600 "parser.yxx"
    {
  // Flag this model as being for a specific neighborhood
  current_model_hood = 0;
  current_model_place = 1;
  LoaderOptions options;
  options.set_flags(options.get_flags() | LoaderOptions::LF_no_ram_cache);
  Filename model = (yyvsp[(2) - (3)]._string);
  model.set_extension("bam");
  current_model = NodePath(loader.load_sync(model, options));
}
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 1623 "parser.yxx"
    {
  // If the std::string is empty std::string that means use the top node of the model
  if ((yyvsp[(5) - (6)]._string) == "") {
    // If this model is neighborhood specific, store it in the hood map
    if (current_model_hood) {
      dna_top_node->get_dna_storage()->store_hood_node((yyvsp[(4) - (6)]._string), current_model, (yyvsp[(3) - (6)]._string));
    } else if (current_model_place) {
      dna_top_node->get_dna_storage()->store_place_node((yyvsp[(4) - (6)]._string), current_model, (yyvsp[(3) - (6)]._string));
    } else {
      dna_top_node->get_dna_storage()->store_node((yyvsp[(4) - (6)]._string), current_model, (yyvsp[(3) - (6)]._string));
    };
  } else {
    // Find the node with the name stored in $5
    NodePath node = current_model.find((yyvsp[(5) - (6)]._string).insert(0, "**/"));
    // Error if we could not find it
    if (node.is_empty()) {
      dnayyerror("Empty NodePath");
    };
    // If this model is neighborhood specific, store it in the hood map
    if (current_model_hood) {
      dna_top_node->get_dna_storage()->store_hood_node((yyvsp[(4) - (6)]._string), node, (yyvsp[(3) - (6)]._string));
    } else if (current_model_place) {
      dna_top_node->get_dna_storage()->store_place_node((yyvsp[(4) - (6)]._string), node, (yyvsp[(3) - (6)]._string));
    } else {
      dna_top_node->get_dna_storage()->store_node((yyvsp[(4) - (6)]._string), node, (yyvsp[(3) - (6)]._string));
    };
  }

  // Put this item name in the catalog
  dna_top_node->get_dna_storage()->store_catalog_string((yyvsp[(3) - (6)]._string), (yyvsp[(4) - (6)]._string));

}
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 1658 "parser.yxx"
    {
  std::string find_string = (yyvsp[(4) - (5)]._string);
  NodePath node = current_model.find(find_string.insert(0, "**/"));
  if (node.is_empty()) {
        dnayyerror("Empty NodePath");
        };
  // If this model is neighborhood specific, store it in the hood map
  if (current_model_hood) {
    dna_top_node->get_dna_storage()->store_hood_node((yyvsp[(4) - (5)]._string), node, (yyvsp[(3) - (5)]._string));
  } else if (current_model_place) {
    dna_top_node->get_dna_storage()->store_place_node((yyvsp[(4) - (5)]._string), node, (yyvsp[(3) - (5)]._string));
  } else {
    dna_top_node->get_dna_storage()->store_node((yyvsp[(4) - (5)]._string), node, (yyvsp[(3) - (5)]._string));
  };
  dna_top_node->get_dna_storage()->store_catalog_string((yyvsp[(3) - (5)]._string), (yyvsp[(4) - (5)]._string));

}
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 1682 "parser.yxx"
    {
  PT(Texture) texture = TexturePool::load_texture((yyvsp[(5) - (6)]._string));
  if (texture == (Texture *)NULL) {
    dna_cat.error()
      << "Unable to load texture file " << (yyvsp[(5) - (6)]._string) << "\n";
  } else {
    dna_top_node->get_dna_storage()->store_texture((yyvsp[(4) - (6)]._string), texture);
    dna_top_node->get_dna_storage()->store_catalog_string((yyvsp[(3) - (6)]._string), (yyvsp[(4) - (6)]._string));
  }
}
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 1698 "parser.yxx"
    {
  Filename model = (yyvsp[(5) - (6)]._string);
  if (model.get_extension() == "") {
    model.set_extension("bam");
  }
  PT(TextFont) font = FontPool::load_font(model);

  if (font != (TextFont *)NULL && font->is_valid()) {
    dna_top_node->get_dna_storage()->store_font((yyvsp[(4) - (6)]._string), font);
    dna_top_node->get_dna_storage()->store_catalog_string((yyvsp[(3) - (6)]._string), (yyvsp[(4) - (6)]._string));
  } else {
    dna_cat.warning()
      << "Unable to load font file " << (yyvsp[(5) - (6)]._string) << "\n";
  }
}
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 1720 "parser.yxx"
    {
  // Old syntax, for backward compatibility, without lb_index.
  PT(DNASuitPoint) point = new DNASuitPoint((int)(yyvsp[(3) - (8)]._number),
                                            (DNASuitPoint::DNASuitPointType)(int
)(yyvsp[(4) - (8)]._number),
                                            LPoint3f((yyvsp[(5) - (8)]._number), (yyvsp[(6) - (8)]._number), (yyvsp[(7) - (8)]._number)));
  dna_top_node->get_dna_storage()->store_suit_point(point);
}
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 1729 "parser.yxx"
    {
  // Old syntax, for backward compatibility, with lb_index.
  PT(DNASuitPoint) point = new DNASuitPoint((int)(yyvsp[(3) - (9)]._number),
                                            (DNASuitPoint::DNASuitPointType)(int
)(yyvsp[(4) - (9)]._number),
                                            LPoint3f((yyvsp[(5) - (9)]._number), (yyvsp[(6) - (9)]._number), (yyvsp[(7) - (9)]._number)),
                                            (int)(yyvsp[(8) - (9)]._number));
  dna_top_node->get_dna_storage()->store_suit_point(point);
}
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 1739 "parser.yxx"
    {
  // Current syntax, without lb_index.
  PT(DNASuitPoint) point = new DNASuitPoint((int)(yyvsp[(3) - (10)]._number), (yyvsp[(5) - (10)]._suit_point_type),
                                            LPoint3f((yyvsp[(7) - (10)]._number), (yyvsp[(8) - (10)]._number), (yyvsp[(9) - (10)]._number)));
  dna_top_node->get_dna_storage()->store_suit_point(point);
}
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 1746 "parser.yxx"
    {
  // Current syntax, with lb_index.
  PT(DNASuitPoint) point = new DNASuitPoint((int)(yyvsp[(3) - (12)]._number), (yyvsp[(5) - (12)]._suit_point_type),
                                            LPoint3f((yyvsp[(7) - (12)]._number), (yyvsp[(8) - (12)]._number), (yyvsp[(9) - (12)]._number)),
                                            (int)(yyvsp[(11) - (12)]._number));
  dna_top_node->get_dna_storage()->store_suit_point(point);
}
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 1758 "parser.yxx"
    {
  (yyval._suit_point_type) = DNASuitPoint::FRONT_DOOR_POINT;
}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 1762 "parser.yxx"
    {
  (yyval._suit_point_type) = DNASuitPoint::SIDE_DOOR_POINT;
}
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 1766 "parser.yxx"
    {
  (yyval._suit_point_type) = DNASuitPoint::STREET_POINT;
}
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 1770 "parser.yxx"
    {
  (yyval._suit_point_type) = DNASuitPoint::COGHQ_IN_POINT;
}
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 1774 "parser.yxx"
    {
  (yyval._suit_point_type) = DNASuitPoint::COGHQ_OUT_POINT;
}
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 1789 "parser.yxx"
    {
  dnayyerror("Name required.");
  (yyval._string) = "";
}
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 1807 "parser.yxx"
    {
  dnayyerror("String required.");
  (yyval._string) = "";
}
    break;

  case 236:
/* Line 1792 of yacc.c  */
#line 1826 "parser.yxx"
    {
  (yyval._string) = (yyvsp[(1) - (1)]._string);
}
    break;

  case 239:
/* Line 1792 of yacc.c  */
#line 1853 "parser.yxx"
    {
  int i = (int)(yyvsp[(1) - (1)]._number);
  if ((double)i != (yyvsp[(1) - (1)]._number)) {
    dnayywarning("Integer expected.");
    (yyval._number) = (double)i;
  }
}
    break;


/* Line 1792 of yacc.c  */
#line 4042 "parser.cxx"
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


