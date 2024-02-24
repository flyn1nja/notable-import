/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Sep 14 10:45:12 EDT 2021 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw_c.native -fma -simd -compact -variables 4 -pipeline-latency 8 -n 10 -name n2fv_10 -with-ostride 2 -include dft/simd/n2f.h -store-multiple 2 */

/*
 * This function contains 42 FP additions, 22 FP multiplications,
 * (or, 24 additions, 4 multiplications, 18 fused multiply/add),
 * 36 stack variables, 4 constants, and 25 memory accesses
 */
#include "dft/simd/n2f.h"

static void n2fv_10(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(20, is), MAKE_VOLATILE_STRIDE(20, os)) {
	       V T3, Tr, Tm, Tn, TD, TC, Tu, Tx, Ty, Ta, Th, Ti, T1, T2;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       T3 = VSUB(T1, T2);
	       Tr = VADD(T1, T2);
	       {
		    V T6, Ts, Tg, Tw, T9, Tt, Td, Tv;
		    {
			 V T4, T5, Te, Tf;
			 T4 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 T5 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 T6 = VSUB(T4, T5);
			 Ts = VADD(T4, T5);
			 Te = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 Tf = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Tg = VSUB(Te, Tf);
			 Tw = VADD(Te, Tf);
		    }
		    {
			 V T7, T8, Tb, Tc;
			 T7 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 T8 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 T9 = VSUB(T7, T8);
			 Tt = VADD(T7, T8);
			 Tb = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 Tc = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			 Td = VSUB(Tb, Tc);
			 Tv = VADD(Tb, Tc);
		    }
		    Tm = VSUB(T6, T9);
		    Tn = VSUB(Td, Tg);
		    TD = VSUB(Ts, Tt);
		    TC = VSUB(Tv, Tw);
		    Tu = VADD(Ts, Tt);
		    Tx = VADD(Tv, Tw);
		    Ty = VADD(Tu, Tx);
		    Ta = VADD(T6, T9);
		    Th = VADD(Td, Tg);
		    Ti = VADD(Ta, Th);
	       }
	       {
		    V TH, TI, TK, TL, TM;
		    TH = VADD(T3, Ti);
		    STM2(&(xo[10]), TH, ovs, &(xo[2]));
		    TI = VADD(Tr, Ty);
		    STM2(&(xo[0]), TI, ovs, &(xo[0]));
		    {
			 V To, Tq, Tl, Tp, Tj, Tk, TJ;
			 To = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), Tn, Tm));
			 Tq = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), Tm, Tn));
			 Tj = VFNMS(LDK(KP250000000), Ti, T3);
			 Tk = VSUB(Ta, Th);
			 Tl = VFMA(LDK(KP559016994), Tk, Tj);
			 Tp = VFNMS(LDK(KP559016994), Tk, Tj);
			 TJ = VFNMSI(To, Tl);
			 STM2(&(xo[2]), TJ, ovs, &(xo[2]));
			 STN2(&(xo[0]), TI, TJ, ovs);
			 TK = VFMAI(Tq, Tp);
			 STM2(&(xo[14]), TK, ovs, &(xo[2]));
			 TL = VFMAI(To, Tl);
			 STM2(&(xo[18]), TL, ovs, &(xo[2]));
			 TM = VFNMSI(Tq, Tp);
			 STM2(&(xo[6]), TM, ovs, &(xo[2]));
		    }
		    {
			 V TE, TG, TB, TF, Tz, TA;
			 TE = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), TD, TC));
			 TG = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), TC, TD));
			 Tz = VFNMS(LDK(KP250000000), Ty, Tr);
			 TA = VSUB(Tu, Tx);
			 TB = VFNMS(LDK(KP559016994), TA, Tz);
			 TF = VFMA(LDK(KP559016994), TA, Tz);
			 {
			      V TN, TO, TP, TQ;
			      TN = VFMAI(TE, TB);
			      STM2(&(xo[4]), TN, ovs, &(xo[0]));
			      STN2(&(xo[4]), TN, TM, ovs);
			      TO = VFNMSI(TG, TF);
			      STM2(&(xo[12]), TO, ovs, &(xo[0]));
			      STN2(&(xo[12]), TO, TK, ovs);
			      TP = VFNMSI(TE, TB);
			      STM2(&(xo[16]), TP, ovs, &(xo[0]));
			      STN2(&(xo[16]), TP, TL, ovs);
			      TQ = VFMAI(TG, TF);
			      STM2(&(xo[8]), TQ, ovs, &(xo[0]));
			      STN2(&(xo[8]), TQ, TH, ovs);
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 10, XSIMD_STRING("n2fv_10"), { 24, 4, 18, 0 }, &GENUS, 0, 2, 0, 0 };

void XSIMD(codelet_n2fv_10) (planner *p) { X(kdft_register) (p, n2fv_10, &desc);
}

#else

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 10 -name n2fv_10 -with-ostride 2 -include dft/simd/n2f.h -store-multiple 2 */

/*
 * This function contains 42 FP additions, 12 FP multiplications,
 * (or, 36 additions, 6 multiplications, 6 fused multiply/add),
 * 36 stack variables, 4 constants, and 25 memory accesses
 */
#include "dft/simd/n2f.h"

static void n2fv_10(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(20, is), MAKE_VOLATILE_STRIDE(20, os)) {
	       V Ti, Ty, Tm, Tn, Tw, Tt, Tz, TA, TB, T7, Te, Tj, Tg, Th;
	       Tg = LD(&(xi[0]), ivs, &(xi[0]));
	       Th = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       Ti = VSUB(Tg, Th);
	       Ty = VADD(Tg, Th);
	       {
		    V T3, Tu, Td, Ts, T6, Tv, Ta, Tr;
		    {
			 V T1, T2, Tb, Tc;
			 T1 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 T2 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 T3 = VSUB(T1, T2);
			 Tu = VADD(T1, T2);
			 Tb = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 Tc = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Td = VSUB(Tb, Tc);
			 Ts = VADD(Tb, Tc);
		    }
		    {
			 V T4, T5, T8, T9;
			 T4 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 T5 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 T6 = VSUB(T4, T5);
			 Tv = VADD(T4, T5);
			 T8 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 T9 = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			 Ta = VSUB(T8, T9);
			 Tr = VADD(T8, T9);
		    }
		    Tm = VSUB(T3, T6);
		    Tn = VSUB(Ta, Td);
		    Tw = VSUB(Tu, Tv);
		    Tt = VSUB(Tr, Ts);
		    Tz = VADD(Tu, Tv);
		    TA = VADD(Tr, Ts);
		    TB = VADD(Tz, TA);
		    T7 = VADD(T3, T6);
		    Te = VADD(Ta, Td);
		    Tj = VADD(T7, Te);
	       }
	       {
		    V TH, TI, TK, TL, TM;
		    TH = VADD(Ti, Tj);
		    STM2(&(xo[10]), TH, ovs, &(xo[2]));
		    TI = VADD(Ty, TB);
		    STM2(&(xo[0]), TI, ovs, &(xo[0]));
		    {
			 V To, Tq, Tl, Tp, Tf, Tk, TJ;
			 To = VBYI(VFMA(LDK(KP951056516), Tm, VMUL(LDK(KP587785252), Tn)));
			 Tq = VBYI(VFNMS(LDK(KP587785252), Tm, VMUL(LDK(KP951056516), Tn)));
			 Tf = VMUL(LDK(KP559016994), VSUB(T7, Te));
			 Tk = VFNMS(LDK(KP250000000), Tj, Ti);
			 Tl = VADD(Tf, Tk);
			 Tp = VSUB(Tk, Tf);
			 TJ = VSUB(Tl, To);
			 STM2(&(xo[2]), TJ, ovs, &(xo[2]));
			 STN2(&(xo[0]), TI, TJ, ovs);
			 TK = VADD(Tq, Tp);
			 STM2(&(xo[14]), TK, ovs, &(xo[2]));
			 TL = VADD(To, Tl);
			 STM2(&(xo[18]), TL, ovs, &(xo[2]));
			 TM = VSUB(Tp, Tq);
			 STM2(&(xo[6]), TM, ovs, &(xo[2]));
		    }
		    {
			 V Tx, TF, TE, TG, TC, TD;
			 Tx = VBYI(VFNMS(LDK(KP587785252), Tw, VMUL(LDK(KP951056516), Tt)));
			 TF = VBYI(VFMA(LDK(KP951056516), Tw, VMUL(LDK(KP587785252), Tt)));
			 TC = VFNMS(LDK(KP250000000), TB, Ty);
			 TD = VMUL(LDK(KP559016994), VSUB(Tz, TA));
			 TE = VSUB(TC, TD);
			 TG = VADD(TD, TC);
			 {
			      V TN, TO, TP, TQ;
			      TN = VADD(Tx, TE);
			      STM2(&(xo[4]), TN, ovs, &(xo[0]));
			      STN2(&(xo[4]), TN, TM, ovs);
			      TO = VSUB(TG, TF);
			      STM2(&(xo[12]), TO, ovs, &(xo[0]));
			      STN2(&(xo[12]), TO, TK, ovs);
			      TP = VSUB(TE, Tx);
			      STM2(&(xo[16]), TP, ovs, &(xo[0]));
			      STN2(&(xo[16]), TP, TL, ovs);
			      TQ = VADD(TF, TG);
			      STM2(&(xo[8]), TQ, ovs, &(xo[0]));
			      STN2(&(xo[8]), TQ, TH, ovs);
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 10, XSIMD_STRING("n2fv_10"), { 36, 6, 6, 0 }, &GENUS, 0, 2, 0, 0 };

void XSIMD(codelet_n2fv_10) (planner *p) { X(kdft_register) (p, n2fv_10, &desc);
}

#endif
