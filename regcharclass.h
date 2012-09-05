/* -*- buffer-read-only: t -*-
 *
 *    regcharclass.h
 *
 *    Copyright (C) 2007, 2011 by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 * !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
 * This file is built by regen/regcharclass.pl.
 * Any changes made here will be lost!
 */


#ifndef H_REGCHARCLASS   /* Guard against nested #includes */
#define H_REGCHARCLASS 1

/*
	LNBREAK: Line Break: \R

	"\x0D\x0A"      # CRLF - Network (Windows) line ending
	\p{VertSpace}
*/
/*** GENERATED CODE ***/
#define is_LNBREAK(s,is_utf8)                                               \
( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0C ) ? 1                        \
: ( 0x0D == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x0A == ((U8*)s)[1] ) ? 2 : 1 )                                     \
: ( is_utf8 ) ?                                                             \
    ( ( 0xC2 == ((U8*)s)[0] ) ?                                             \
	( ( 0x85 == ((U8*)s)[1] ) ? 2 : 0 )                                 \
    : ( 0xE2 == ((U8*)s)[0] ) ?                                             \
	( ( ( 0x80 == ((U8*)s)[1] ) && ( ( ((U8*)s)[2] & 0xFE ) == 0xA8 ) ) ? 3 : 0 )\
    : 0 )                                                                   \
: ( 0x85 == ((U8*)s)[0] ) )

/*** GENERATED CODE ***/
#define is_LNBREAK_safe(s,e,is_utf8)                                        \
( ((e)-(s) > 2) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0C ) ? 1                    \
    : ( 0x0D == ((U8*)s)[0] ) ?                                             \
	( ( 0x0A == ((U8*)s)[1] ) ? 2 : 1 )                                 \
    : ( is_utf8 ) ?                                                         \
	( ( 0xC2 == ((U8*)s)[0] ) ?                                         \
	    ( ( 0x85 == ((U8*)s)[1] ) ? 2 : 0 )                             \
	: ( 0xE2 == ((U8*)s)[0] ) ?                                         \
	    ( ( ( 0x80 == ((U8*)s)[1] ) && ( ( ((U8*)s)[2] & 0xFE ) == 0xA8 ) ) ? 3 : 0 )\
	: 0 )                                                               \
    : ( 0x85 == ((U8*)s)[0] ) )                                             \
: ((e)-(s) > 1) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0C ) ? 1                    \
    : ( 0x0D == ((U8*)s)[0] ) ?                                             \
	( ( 0x0A == ((U8*)s)[1] ) ? 2 : 1 )                                 \
    : ( is_utf8 ) ?                                                         \
	( ( ( 0xC2 == ((U8*)s)[0] ) && ( 0x85 == ((U8*)s)[1] ) ) ? 2 : 0 )  \
    : ( 0x85 == ((U8*)s)[0] ) )                                             \
: ((e)-(s) > 0) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D ) ? 1                    \
    : ( !( is_utf8 ) ) ?                                                    \
	( 0x85 == ((U8*)s)[0] )                                             \
    : 0 )                                                                   \
: 0 )

/*** GENERATED CODE ***/
#define is_LNBREAK_utf8(s)                                                  \
( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0C ) ? 1                        \
: ( 0x0D == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x0A == ((U8*)s)[1] ) ? 2 : 1 )                                     \
: ( 0xC2 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x85 == ((U8*)s)[1] ) ? 2 : 0 )                                     \
: ( 0xE2 == ((U8*)s)[0] ) ?                                                 \
    ( ( ( 0x80 == ((U8*)s)[1] ) && ( ( ((U8*)s)[2] & 0xFE ) == 0xA8 ) ) ? 3 : 0 )\
: 0 )

/*** GENERATED CODE ***/
#define is_LNBREAK_utf8_safe(s,e)                                           \
( ((e)-(s) > 2) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0C ) ? 1                    \
    : ( 0x0D == ((U8*)s)[0] ) ?                                             \
	( ( 0x0A == ((U8*)s)[1] ) ? 2 : 1 )                                 \
    : ( 0xC2 == ((U8*)s)[0] ) ?                                             \
	( ( 0x85 == ((U8*)s)[1] ) ? 2 : 0 )                                 \
    : ( 0xE2 == ((U8*)s)[0] ) ?                                             \
	( ( ( 0x80 == ((U8*)s)[1] ) && ( ( ((U8*)s)[2] & 0xFE ) == 0xA8 ) ) ? 3 : 0 )\
    : 0 )                                                                   \
: ((e)-(s) > 1) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0C ) ? 1                    \
    : ( 0x0D == ((U8*)s)[0] ) ?                                             \
	( ( 0x0A == ((U8*)s)[1] ) ? 2 : 1 )                                 \
    : ( 0xC2 == ((U8*)s)[0] ) ?                                             \
	( ( 0x85 == ((U8*)s)[1] ) ? 2 : 0 )                                 \
    : 0 )                                                                   \
: ((e)-(s) > 0) ?                                                           \
    ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D )                          \
: 0 )

/*** GENERATED CODE ***/
#define is_LNBREAK_latin1(s)                                                \
( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0C ) ? 1                        \
: ( 0x0D == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x0A == ((U8*)s)[1] ) ? 2 : 1 )                                     \
: ( 0x85 == ((U8*)s)[0] ) )

/*** GENERATED CODE ***/
#define is_LNBREAK_latin1_safe(s,e)                                         \
( ((e)-(s) > 1) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0C ) ? 1                    \
    : ( 0x0D == ((U8*)s)[0] ) ?                                             \
	( ( 0x0A == ((U8*)s)[1] ) ? 2 : 1 )                                 \
    : ( 0x85 == ((U8*)s)[0] ) )                                             \
: ((e)-(s) > 0) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D ) || 0x85 == ((U8*)s)[0] )\
: 0 )

/*
	HORIZWS: Horizontal Whitespace: \h \H

	\p{HorizSpace}
*/
/*** GENERATED CODE ***/
#define is_HORIZWS(s,is_utf8)                                               \
( ( 0x09 == ((U8*)s)[0] || 0x20 == ((U8*)s)[0] ) ? 1                        \
: ( is_utf8 ) ?                                                             \
    ( ( 0xC2 == ((U8*)s)[0] ) ?                                             \
	( ( 0xA0 == ((U8*)s)[1] ) ? 2 : 0 )                                 \
    : ( 0xE1 == ((U8*)s)[0] ) ?                                             \
	( ( 0x9A == ((U8*)s)[1] ) ?                                         \
	    ( ( 0x80 == ((U8*)s)[2] ) ? 3 : 0 )                             \
	: ( 0xA0 == ((U8*)s)[1] ) ?                                         \
	    ( ( 0x8E == ((U8*)s)[2] ) ? 3 : 0 )                             \
	: 0 )                                                               \
    : ( 0xE2 == ((U8*)s)[0] ) ?                                             \
	( ( 0x80 == ((U8*)s)[1] ) ?                                         \
	    ( ( ( 0x80 <= ((U8*)s)[2] && ((U8*)s)[2] <= 0x8A ) || 0xAF == ((U8*)s)[2] ) ? 3 : 0 )\
	: ( 0x81 == ((U8*)s)[1] ) ?                                         \
	    ( ( 0x9F == ((U8*)s)[2] ) ? 3 : 0 )                             \
	: 0 )                                                               \
    : ( 0xE3 == ((U8*)s)[0] ) ?                                             \
	( ( ( 0x80 == ((U8*)s)[1] ) && ( 0x80 == ((U8*)s)[2] ) ) ? 3 : 0 )  \
    : 0 )                                                                   \
: ( 0xA0 == ((U8*)s)[0] ) )

/*** GENERATED CODE ***/
#define is_HORIZWS_safe(s,e,is_utf8)                                        \
( ((e)-(s) > 2) ?                                                           \
    ( ( 0x09 == ((U8*)s)[0] || 0x20 == ((U8*)s)[0] ) ? 1                    \
    : ( is_utf8 ) ?                                                         \
	( ( 0xC2 == ((U8*)s)[0] ) ?                                         \
	    ( ( 0xA0 == ((U8*)s)[1] ) ? 2 : 0 )                             \
	: ( 0xE1 == ((U8*)s)[0] ) ?                                         \
	    ( ( 0x9A == ((U8*)s)[1] ) ?                                     \
		( ( 0x80 == ((U8*)s)[2] ) ? 3 : 0 )                         \
	    : ( 0xA0 == ((U8*)s)[1] ) ?                                     \
		( ( 0x8E == ((U8*)s)[2] ) ? 3 : 0 )                         \
	    : 0 )                                                           \
	: ( 0xE2 == ((U8*)s)[0] ) ?                                         \
	    ( ( 0x80 == ((U8*)s)[1] ) ?                                     \
		( ( ( 0x80 <= ((U8*)s)[2] && ((U8*)s)[2] <= 0x8A ) || 0xAF == ((U8*)s)[2] ) ? 3 : 0 )\
	    : ( 0x81 == ((U8*)s)[1] ) ?                                     \
		( ( 0x9F == ((U8*)s)[2] ) ? 3 : 0 )                         \
	    : 0 )                                                           \
	: ( 0xE3 == ((U8*)s)[0] ) ?                                         \
	    ( ( ( 0x80 == ((U8*)s)[1] ) && ( 0x80 == ((U8*)s)[2] ) ) ? 3 : 0 )\
	: 0 )                                                               \
    : ( 0xA0 == ((U8*)s)[0] ) )                                             \
: ((e)-(s) > 1) ?                                                           \
    ( ( 0x09 == ((U8*)s)[0] || 0x20 == ((U8*)s)[0] ) ? 1                    \
    : ( is_utf8 ) ?                                                         \
	( ( ( 0xC2 == ((U8*)s)[0] ) && ( 0xA0 == ((U8*)s)[1] ) ) ? 2 : 0 )  \
    : ( 0xA0 == ((U8*)s)[0] ) )                                             \
: ((e)-(s) > 0) ?                                                           \
    ( ( 0x09 == ((U8*)s)[0] || 0x20 == ((U8*)s)[0] ) ? 1                    \
    : ( !( is_utf8 ) ) ?                                                    \
	( 0xA0 == ((U8*)s)[0] )                                             \
    : 0 )                                                                   \
: 0 )

/*** GENERATED CODE ***/
#define is_HORIZWS_utf8(s)                                                  \
( ( 0x09 == ((U8*)s)[0] || 0x20 == ((U8*)s)[0] ) ? 1                        \
: ( 0xC2 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0xA0 == ((U8*)s)[1] ) ? 2 : 0 )                                     \
: ( 0xE1 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x9A == ((U8*)s)[1] ) ?                                             \
	( ( 0x80 == ((U8*)s)[2] ) ? 3 : 0 )                                 \
    : ( 0xA0 == ((U8*)s)[1] ) ?                                             \
	( ( 0x8E == ((U8*)s)[2] ) ? 3 : 0 )                                 \
    : 0 )                                                                   \
: ( 0xE2 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x80 == ((U8*)s)[1] ) ?                                             \
	( ( ( ((U8*)s)[2] <= 0x8A ) || 0xAF == ((U8*)s)[2] ) ? 3 : 0 )      \
    : ( 0x81 == ((U8*)s)[1] ) ?                                             \
	( ( 0x9F == ((U8*)s)[2] ) ? 3 : 0 )                                 \
    : 0 )                                                                   \
: ( 0xE3 == ((U8*)s)[0] ) ?                                                 \
    ( ( ( 0x80 == ((U8*)s)[1] ) && ( 0x80 == ((U8*)s)[2] ) ) ? 3 : 0 )      \
: 0 )

/*** GENERATED CODE ***/
#define is_HORIZWS_utf8_safe(s,e)                                           \
( ((e)-(s) > 2) ?                                                           \
    ( ( 0x09 == ((U8*)s)[0] || 0x20 == ((U8*)s)[0] ) ? 1                    \
    : ( 0xC2 == ((U8*)s)[0] ) ?                                             \
	( ( 0xA0 == ((U8*)s)[1] ) ? 2 : 0 )                                 \
    : ( 0xE1 == ((U8*)s)[0] ) ?                                             \
	( ( 0x9A == ((U8*)s)[1] ) ?                                         \
	    ( ( 0x80 == ((U8*)s)[2] ) ? 3 : 0 )                             \
	: ( 0xA0 == ((U8*)s)[1] ) ?                                         \
	    ( ( 0x8E == ((U8*)s)[2] ) ? 3 : 0 )                             \
	: 0 )                                                               \
    : ( 0xE2 == ((U8*)s)[0] ) ?                                             \
	( ( 0x80 == ((U8*)s)[1] ) ?                                         \
	    ( ( ( 0x80 <= ((U8*)s)[2] && ((U8*)s)[2] <= 0x8A ) || 0xAF == ((U8*)s)[2] ) ? 3 : 0 )\
	: ( 0x81 == ((U8*)s)[1] ) ?                                         \
	    ( ( 0x9F == ((U8*)s)[2] ) ? 3 : 0 )                             \
	: 0 )                                                               \
    : ( 0xE3 == ((U8*)s)[0] ) ?                                             \
	( ( ( 0x80 == ((U8*)s)[1] ) && ( 0x80 == ((U8*)s)[2] ) ) ? 3 : 0 )  \
    : 0 )                                                                   \
: ((e)-(s) > 1) ?                                                           \
    ( ( 0x09 == ((U8*)s)[0] || 0x20 == ((U8*)s)[0] ) ? 1                    \
    : ( 0xC2 == ((U8*)s)[0] ) ?                                             \
	( ( 0xA0 == ((U8*)s)[1] ) ? 2 : 0 )                                 \
    : 0 )                                                                   \
: ((e)-(s) > 0) ?                                                           \
    ( 0x09 == ((U8*)s)[0] || 0x20 == ((U8*)s)[0] )                          \
: 0 )

/*** GENERATED CODE ***/
#define is_HORIZWS_latin1(s)                                                \
( 0x09 == ((U8*)s)[0] || 0x20 == ((U8*)s)[0] || 0xA0 == ((U8*)s)[0] )

/*** GENERATED CODE ***/
#define is_HORIZWS_latin1_safe(s,e)                                         \
( ((e)-(s) > 0) ?                                                           \
    ( 0x09 == ((U8*)s)[0] || 0x20 == ((U8*)s)[0] || 0xA0 == ((U8*)s)[0] )   \
: 0 )

/*** GENERATED CODE ***/
#define is_HORIZWS_cp(cp)                                                   \
( 0x09 == cp || ( 0x09 < cp &&                                              \
( 0x20 == cp || ( 0x20 < cp &&                                              \
( 0xA0 == cp || ( 0xA0 < cp &&                                              \
( 0x1680 == cp || ( 0x1680 < cp &&                                          \
( 0x180E == cp || ( 0x180E < cp &&                                          \
( ( 0x2000 <= cp && cp <= 0x200A ) || ( 0x200A < cp &&                      \
( 0x202F == cp || ( 0x202F < cp &&                                          \
( 0x205F == cp || ( 0x205F < cp &&                                          \
0x3000 == cp ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )

/*
	VERTWS: Vertical Whitespace: \v \V

	\p{VertSpace}
*/
/*** GENERATED CODE ***/
#define is_VERTWS(s,is_utf8)                                                \
( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D ) ? 1                        \
: ( is_utf8 ) ?                                                             \
    ( ( 0xC2 == ((U8*)s)[0] ) ?                                             \
	( ( 0x85 == ((U8*)s)[1] ) ? 2 : 0 )                                 \
    : ( 0xE2 == ((U8*)s)[0] ) ?                                             \
	( ( ( 0x80 == ((U8*)s)[1] ) && ( ( ((U8*)s)[2] & 0xFE ) == 0xA8 ) ) ? 3 : 0 )\
    : 0 )                                                                   \
: ( 0x85 == ((U8*)s)[0] ) )

/*** GENERATED CODE ***/
#define is_VERTWS_safe(s,e,is_utf8)                                         \
( ((e)-(s) > 2) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D ) ? 1                    \
    : ( is_utf8 ) ?                                                         \
	( ( 0xC2 == ((U8*)s)[0] ) ?                                         \
	    ( ( 0x85 == ((U8*)s)[1] ) ? 2 : 0 )                             \
	: ( 0xE2 == ((U8*)s)[0] ) ?                                         \
	    ( ( ( 0x80 == ((U8*)s)[1] ) && ( ( ((U8*)s)[2] & 0xFE ) == 0xA8 ) ) ? 3 : 0 )\
	: 0 )                                                               \
    : ( 0x85 == ((U8*)s)[0] ) )                                             \
: ((e)-(s) > 1) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D ) ? 1                    \
    : ( is_utf8 ) ?                                                         \
	( ( ( 0xC2 == ((U8*)s)[0] ) && ( 0x85 == ((U8*)s)[1] ) ) ? 2 : 0 )  \
    : ( 0x85 == ((U8*)s)[0] ) )                                             \
: ((e)-(s) > 0) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D ) ? 1                    \
    : ( !( is_utf8 ) ) ?                                                    \
	( 0x85 == ((U8*)s)[0] )                                             \
    : 0 )                                                                   \
: 0 )

/*** GENERATED CODE ***/
#define is_VERTWS_utf8(s)                                                   \
( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D ) ? 1                        \
: ( 0xC2 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x85 == ((U8*)s)[1] ) ? 2 : 0 )                                     \
: ( 0xE2 == ((U8*)s)[0] ) ?                                                 \
    ( ( ( 0x80 == ((U8*)s)[1] ) && ( ( ((U8*)s)[2] & 0xFE ) == 0xA8 ) ) ? 3 : 0 )\
: 0 )

/*** GENERATED CODE ***/
#define is_VERTWS_utf8_safe(s,e)                                            \
( ((e)-(s) > 2) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D ) ? 1                    \
    : ( 0xC2 == ((U8*)s)[0] ) ?                                             \
	( ( 0x85 == ((U8*)s)[1] ) ? 2 : 0 )                                 \
    : ( 0xE2 == ((U8*)s)[0] ) ?                                             \
	( ( ( 0x80 == ((U8*)s)[1] ) && ( ( ((U8*)s)[2] & 0xFE ) == 0xA8 ) ) ? 3 : 0 )\
    : 0 )                                                                   \
: ((e)-(s) > 1) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D ) ? 1                    \
    : ( 0xC2 == ((U8*)s)[0] ) ?                                             \
	( ( 0x85 == ((U8*)s)[1] ) ? 2 : 0 )                                 \
    : 0 )                                                                   \
: ((e)-(s) > 0) ?                                                           \
    ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D )                          \
: 0 )

/*** GENERATED CODE ***/
#define is_VERTWS_latin1(s)                                                 \
( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D ) || 0x85 == ((U8*)s)[0] )

/*** GENERATED CODE ***/
#define is_VERTWS_latin1_safe(s,e)                                          \
( ((e)-(s) > 0) ?                                                           \
    ( ( 0x0A <= ((U8*)s)[0] && ((U8*)s)[0] <= 0x0D ) || 0x85 == ((U8*)s)[0] )\
: 0 )

/*** GENERATED CODE ***/
#define is_VERTWS_cp(cp)                                                    \
( ( 0x0A <= cp && cp <= 0x0D ) || ( 0x0D < cp &&                            \
( 0x85 == cp || ( 0x85 < cp &&                                              \
( 0x2028 == cp || ( 0x2028 < cp &&                                          \
0x2029 == cp ) ) ) ) ) )

/*
	GCB_L: Grapheme_Cluster_Break=L

	\p{_X_GCB_L}
*/
/*** GENERATED CODE ***/
#define is_GCB_L_utf8(s)                                                    \
( ( 0xE1 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x84 == ((U8*)s)[1] ) ?                                             \
	3                                                                   \
    : ( 0x85 == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] <= 0x9F ) ? 3 : 0 )                                 \
    : 0 )                                                                   \
: ( 0xEA == ((U8*)s)[0] ) ?                                                 \
    ( ( ( 0xA5 == ((U8*)s)[1] ) && ( 0xA0 <= ((U8*)s)[2] && ((U8*)s)[2] <= 0xBC ) ) ? 3 : 0 )\
: 0 )

/*
	GCB_LV_LVT_V: Grapheme_Cluster_Break=(LV or LVT or V)

	\p{_X_LV_LVT_V}
*/
/*** GENERATED CODE ***/
#define is_GCB_LV_LVT_V_utf8(s)                                             \
( ( 0xE1 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x85 == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] >= 0xA0 ) ? 3 : 0 )                                 \
    : ( 0x86 == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] <= 0xA7 ) ? 3 : 0 )                                 \
    : 0 )                                                                   \
: ( 0xEA == ((U8*)s)[0] ) ?                                                 \
    ( ( ((U8*)s)[1] >= 0xB0 ) ?                                             \
	3                                                                   \
    : 0 )                                                                   \
: ( 0xEB == ((U8*)s)[0] || 0xEC == ((U8*)s)[0] ) ?                          \
    3                                                                       \
: ( 0xED == ((U8*)s)[0] ) ?                                                 \
    ( ( ((U8*)s)[1] <= 0x9D ) ?                                             \
	3                                                                   \
    : ( 0x9E == ((U8*)s)[1] ) ?                                             \
	( ( ( ((U8*)s)[2] <= 0xA3 ) || ( ((U8*)s)[2] >= 0xB0 ) ) ? 3 : 0 )  \
    : ( 0x9F == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] <= 0x86 ) ? 3 : 0 )                                 \
    : 0 )                                                                   \
: 0 )

/*
	GCB_Prepend: Grapheme_Cluster_Break=Prepend

	\p{_X_GCB_Prepend}
*/
/*** GENERATED CODE ***/
#define is_GCB_Prepend_utf8(s)                                              \
( 0 )

/*
	GCB_RI: Grapheme_Cluster_Break=RI

	\p{_X_RI}
*/
/*** GENERATED CODE ***/
#define is_GCB_RI_utf8(s)                                                   \
( ( ( ( ( 0xF0 == ((U8*)s)[0] ) && ( 0x9F == ((U8*)s)[1] ) ) && ( 0x87 == ((U8*)s)[2] ) ) && ( ((U8*)s)[3] >= 0xA6 ) ) ? 4 : 0 )

/*
	GCB_SPECIAL_BEGIN: Grapheme_Cluster_Break=special_begins

	\p{_X_Special_Begin}
*/
/*** GENERATED CODE ***/
#define is_GCB_SPECIAL_BEGIN_utf8(s)                                        \
( ( 0xE1 == ((U8*)s)[0] ) ?                                                 \
    ( ( ( ((U8*)s)[1] & 0xFC ) == 0x84 ) ?                                  \
	3                                                                   \
    : 0 )                                                                   \
: ( 0xEA == ((U8*)s)[0] ) ?                                                 \
    ( ( 0xA5 == ((U8*)s)[1] ) ?                                             \
	( ( 0xA0 <= ((U8*)s)[2] && ((U8*)s)[2] <= 0xBC ) ? 3 : 0 )          \
    : ( ((U8*)s)[1] >= 0xB0 ) ?                                             \
	3                                                                   \
    : 0 )                                                                   \
: ( 0xEB == ((U8*)s)[0] || 0xEC == ((U8*)s)[0] ) ?                          \
    3                                                                       \
: ( 0xED == ((U8*)s)[0] ) ?                                                 \
    ( ( ((U8*)s)[1] <= 0x9D ) ?                                             \
	3                                                                   \
    : ( 0x9E == ((U8*)s)[1] ) ?                                             \
	( ( ( ((U8*)s)[2] <= 0xA3 ) || ( ((U8*)s)[2] >= 0xB0 ) ) ? 3 : 0 )  \
    : ( 0x9F == ((U8*)s)[1] ) ?                                             \
	( ( ( ((U8*)s)[2] <= 0x86 ) || ( 0x8B <= ((U8*)s)[2] && ((U8*)s)[2] <= 0xBB ) ) ? 3 : 0 )\
    : 0 )                                                                   \
: ( 0xF0 == ((U8*)s)[0] ) ?                                                 \
    ( ( ( ( 0x9F == ((U8*)s)[1] ) && ( 0x87 == ((U8*)s)[2] ) ) && ( ((U8*)s)[3] >= 0xA6 ) ) ? 4 : 0 )\
: 0 )

/*
	GCB_T: Grapheme_Cluster_Break=T

	\p{_X_GCB_T}
*/
/*** GENERATED CODE ***/
#define is_GCB_T_utf8(s)                                                    \
( ( 0xE1 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x86 == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] >= 0xA8 ) ? 3 : 0 )                                 \
    : ( 0x87 == ((U8*)s)[1] ) ?                                             \
	3                                                                   \
    : 0 )                                                                   \
: ( 0xED == ((U8*)s)[0] ) ?                                                 \
    ( ( ( 0x9F == ((U8*)s)[1] ) && ( 0x8B <= ((U8*)s)[2] && ((U8*)s)[2] <= 0xBB ) ) ? 3 : 0 )\
: 0 )

/*
	GCB_V: Grapheme_Cluster_Break=V

	\p{_X_GCB_V}
*/
/*** GENERATED CODE ***/
#define is_GCB_V_utf8(s)                                                    \
( ( 0xE1 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x85 == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] >= 0xA0 ) ? 3 : 0 )                                 \
    : ( 0x86 == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] <= 0xA7 ) ? 3 : 0 )                                 \
    : 0 )                                                                   \
: ( 0xED == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x9E == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] >= 0xB0 ) ? 3 : 0 )                                 \
    : ( 0x9F == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] <= 0x86 ) ? 3 : 0 )                                 \
    : 0 )                                                                   \
: 0 )

/*
	QUOTEMETA: Meta-characters that \Q should quote

	\p{_Perl_Quotemeta}
*/
/*** GENERATED CODE ***/
#define is_QUOTEMETA_high(s)                                                \
( ( 0xCD == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x8F == ((U8*)s)[1] ) ? 2 : 0 )                                     \
: ( 0xE1 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x85 == ((U8*)s)[1] ) ?                                             \
	( ( 0x9F == ((U8*)s)[2] || 0xA0 == ((U8*)s)[2] ) ? 3 : 0 )          \
    : ( 0x9A == ((U8*)s)[1] ) ?                                             \
	( ( 0x80 == ((U8*)s)[2] ) ? 3 : 0 )                                 \
    : ( 0x9E == ((U8*)s)[1] ) ?                                             \
	( ( ( ((U8*)s)[2] & 0xFE ) == 0xB4 ) ? 3 : 0 )                      \
    : ( 0xA0 == ((U8*)s)[1] ) ?                                             \
	( ( 0x8B <= ((U8*)s)[2] && ((U8*)s)[2] <= 0x8E ) ? 3 : 0 )          \
    : 0 )                                                                   \
: ( 0xE2 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x80 == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] <= 0xBE ) ? 3 : 0 )                                 \
    : ( 0x81 == ((U8*)s)[1] ) ?                                             \
	( ( ( 0x81 <= ((U8*)s)[2] && ((U8*)s)[2] <= 0x93 ) || ( 0x95 <= ((U8*)s)[2] && ((U8*)s)[2] <= 0xAF ) ) ? 3 : 0 )\
    : ( 0x86 == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] >= 0x90 ) ? 3 : 0 )                                 \
    : ( 0x87 <= ((U8*)s)[1] && ((U8*)s)[1] <= 0x90 ) ?                      \
	3                                                                   \
    : ( 0x91 == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] <= 0x9F ) ? 3 : 0 )                                 \
    : ( 0x94 <= ((U8*)s)[1] && ((U8*)s)[1] <= 0x9C ) ?                      \
	3                                                                   \
    : ( 0x9D == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] <= 0xB5 ) ? 3 : 0 )                                 \
    : ( 0x9E == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] >= 0x94 ) ? 3 : 0 )                                 \
    : ( ( 0x9F <= ((U8*)s)[1] && ((U8*)s)[1] <= 0xAF ) || ( ((U8*)s)[1] & 0xFE ) == 0xB8 ) ?\
	3                                                                   \
    : 0 )                                                                   \
: ( 0xE3 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0x80 == ((U8*)s)[1] ) ?                                             \
	( ( ( ((U8*)s)[2] <= 0x83 ) || ( 0x88 <= ((U8*)s)[2] && ((U8*)s)[2] <= 0xA0 ) || 0xB0 == ((U8*)s)[2] ) ? 3 : 0 )\
    : ( 0x85 == ((U8*)s)[1] ) ?                                             \
	( ( 0xA4 == ((U8*)s)[2] ) ? 3 : 0 )                                 \
    : 0 )                                                                   \
: ( 0xEF == ((U8*)s)[0] ) ?                                                 \
    ( ( 0xB4 == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] >= 0xBE ) ? 3 : 0 )                                 \
    : ( 0xB8 == ((U8*)s)[1] ) ?                                             \
	( ( ((U8*)s)[2] <= 0x8F ) ? 3 : 0 )                                 \
    : ( 0xB9 == ((U8*)s)[1] ) ?                                             \
	( ( 0x85 == ((U8*)s)[2] || 0x86 == ((U8*)s)[2] ) ? 3 : 0 )          \
    : ( 0xBB == ((U8*)s)[1] ) ?                                             \
	( ( 0xBF == ((U8*)s)[2] ) ? 3 : 0 )                                 \
    : ( 0xBE == ((U8*)s)[1] ) ?                                             \
	( ( 0xA0 == ((U8*)s)[2] ) ? 3 : 0 )                                 \
    : ( 0xBF == ((U8*)s)[1] ) ?                                             \
	( ( 0xB0 <= ((U8*)s)[2] && ((U8*)s)[2] <= 0xB8 ) ? 3 : 0 )          \
    : 0 )                                                                   \
: ( 0xF0 == ((U8*)s)[0] ) ?                                                 \
    ( ( ( ( 0x9D == ((U8*)s)[1] ) && ( 0x85 == ((U8*)s)[2] ) ) && ( 0xB3 <= ((U8*)s)[3] && ((U8*)s)[3] <= 0xBA ) ) ? 4 : 0 )\
: ( 0xF3 == ((U8*)s)[0] ) ?                                                 \
    ( ( 0xA0 == ((U8*)s)[1] ) ?                                             \
	4                                                                   \
    : 0 )                                                                   \
: 0 )


#endif /* H_REGCHARCLASS */

/* ex: set ro: */
