# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2004.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_MINUS_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_MINUS_H
#
# include <chaos/preprocessor/arbitrary/detail/lookup.h>
#
# /* CHAOS_PP_MINUS */
#
# define CHAOS_PP_MINUS(a, b) \
    CHAOS_PP_ARBITRARY_LOOKUP(b, CHAOS_PP_ARBITRARY_LOOKUP(a, ( \
        ((0, 0), (1, 9), (1, 8), (1, 7), (1, 6), (1, 5), (1, 4), (1, 3), (1, 2), (1, 1)), \
        ((0, 1), (0, 0), (1, 9), (1, 8), (1, 7), (1, 6), (1, 5), (1, 4), (1, 3), (1, 2)), \
        ((0, 2), (0, 1), (0, 0), (1, 9), (1, 8), (1, 7), (1, 6), (1, 5), (1, 4), (1, 3)), \
        ((0, 3), (0, 2), (0, 1), (0, 0), (1, 9), (1, 8), (1, 7), (1, 6), (1, 5), (1, 4)), \
        ((0, 4), (0, 3), (0, 2), (0, 1), (0, 0), (1, 9), (1, 8), (1, 7), (1, 6), (1, 5)), \
        ((0, 5), (0, 4), (0, 3), (0, 2), (0, 1), (0, 0), (1, 9), (1, 8), (1, 7), (1, 6)), \
        ((0, 6), (0, 5), (0, 4), (0, 3), (0, 2), (0, 1), (0, 0), (1, 9), (1, 8), (1, 7)), \
        ((0, 7), (0, 6), (0, 5), (0, 4), (0, 3), (0, 2), (0, 1), (0, 0), (1, 9), (1, 8)), \
        ((0, 8), (0, 7), (0, 6), (0, 5), (0, 4), (0, 3), (0, 2), (0, 1), (0, 0), (1, 9)), \
        ((0, 9), (0, 8), (0, 7), (0, 6), (0, 5), (0, 4), (0, 3), (0, 2), (0, 1), (0, 0)) \
    ))) \
    /**/
#
# endif
