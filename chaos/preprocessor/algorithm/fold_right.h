# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_FOLD_RIGHT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_FOLD_RIGHT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_FOLD_RIGHT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_RIGHT(op, g, ...) CHAOS_PP_FOLD_RIGHT_S(CHAOS_PP_STATE(), op, g, __VA_ARGS__)
#    define CHAOS_PP_FOLD_RIGHT_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_RIGHT_ID)()
# else
#    define CHAOS_PP_FOLD_RIGHT(op, g, state) CHAOS_PP_FOLD_RIGHT_S(CHAOS_PP_STATE(), op, g, state)
# endif
#
# define CHAOS_PP_FOLD_RIGHT_ID() CHAOS_PP_FOLD_RIGHT
#
# /* CHAOS_PP_FOLD_RIGHT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_RIGHT_S(s, op, g, ...) CHAOS_IP_FOLD_RIGHT_U(s, op, g, (__VA_ARGS__))
#    define CHAOS_PP_FOLD_RIGHT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_RIGHT_S_ID)()
# else
#    define CHAOS_PP_FOLD_RIGHT_S(s, op, g, state) CHAOS_IP_FOLD_RIGHT_U(s, op, g, (state))
# endif
#
# define CHAOS_PP_FOLD_RIGHT_S_ID() CHAOS_PP_FOLD_RIGHT_S
#
# define CHAOS_IP_FOLD_RIGHT_U(s, op, g, ps) CHAOS_IP_FOLD_RIGHT_I(CHAOS_PP_NEXT(s), op, CHAOS_PP_CALL(op), CHAOS_PP_TYPEOF(g), g, ps)
# define CHAOS_IP_FOLD_RIGHT_INDIRECT() CHAOS_IP_FOLD_RIGHT_I
# define CHAOS_IP_FOLD_RIGHT_I(s, op, _o, type, g, ps) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOLD_RIGHT_II, CHAOS_PP_UNPACK ps CHAOS_PP_TUPLE_EAT(7) \
    )(CHAOS_PP_OBSTRUCT(), s, op, _o, type, g, ps) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_II(_, s, op, _o, type, g, ps) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOLD_RIGHT_III _( \
        CHAOS_PP_NEXT(s), op, _o, type, g, \
        (CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOLD_RIGHT_INDIRECT _()(CHAOS_PP_NEXT(s), op, _o, type, CHAOS_PP_REST(g), ps))) \
    )) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_III(s, op, _o, type, g, ps) \
    _o()(s, op, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)) CHAOS_PP_COMMA() CHAOS_PP_UNPACK ps) \
    /**/
#
# endif