// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__top__DOT__dut__DOT__state;
    // Body
    __Vdly__top__DOT__dut__DOT__state = vlSelf->top__DOT__dut__DOT__state;
    if ((8U & (IData)(vlSelf->top__DOT__dut__DOT__state))) {
        if ((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__state)))) {
                    if (vlSelf->pedestrian_button_i) {
                        __Vdly__top__DOT__dut__DOT__state = 4U;
                    } else if ((1U > (IData)(vlSelf->top__DOT__dut__DOT__Count_RED_AMBER))) {
                        vlSelf->top__DOT__dut__DOT__Count_RED_AMBER 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->top__DOT__dut__DOT__Count_RED_AMBER)));
                        vlSelf->red_o = 1U;
                        vlSelf->amber_o = 1U;
                        vlSelf->green_o = 0U;
                        __Vdly__top__DOT__dut__DOT__state = 8U;
                    } else {
                        vlSelf->top__DOT__dut__DOT__Count_RED_AMBER = 0U;
                        __Vdly__top__DOT__dut__DOT__state = 1U;
                    }
                }
            }
        }
    } else if ((4U & (IData)(vlSelf->top__DOT__dut__DOT__state))) {
        if ((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__state)))) {
                if ((6U > (IData)(vlSelf->top__DOT__dut__DOT__Count_RED))) {
                    vlSelf->top__DOT__dut__DOT__Count_RED 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__dut__DOT__Count_RED)));
                    vlSelf->red_o = 1U;
                    vlSelf->amber_o = 0U;
                    vlSelf->green_o = 0U;
                    __Vdly__top__DOT__dut__DOT__state = 4U;
                } else {
                    vlSelf->top__DOT__dut__DOT__Count_RED_AMBER = 0U;
                    __Vdly__top__DOT__dut__DOT__state = 8U;
                }
            }
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__dut__DOT__state))) {
        if ((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__state)))) {
            if (vlSelf->pedestrian_button_i) {
                __Vdly__top__DOT__dut__DOT__state = 4U;
            } else if ((1U > (IData)(vlSelf->top__DOT__dut__DOT__Count_AMBER))) {
                vlSelf->top__DOT__dut__DOT__Count_AMBER 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__dut__DOT__Count_AMBER)));
                vlSelf->red_o = 0U;
                vlSelf->amber_o = 1U;
                vlSelf->green_o = 0U;
                __Vdly__top__DOT__dut__DOT__state = 2U;
            } else {
                vlSelf->top__DOT__dut__DOT__Count_AMBER = 0U;
                __Vdly__top__DOT__dut__DOT__state = 4U;
            }
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__dut__DOT__state))) {
        if (vlSelf->pedestrian_button_i) {
            __Vdly__top__DOT__dut__DOT__state = 4U;
        } else if ((5U > (IData)(vlSelf->top__DOT__dut__DOT__Count_GREEN))) {
            vlSelf->top__DOT__dut__DOT__Count_GREEN 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__dut__DOT__Count_GREEN)));
            vlSelf->red_o = 0U;
            vlSelf->amber_o = 0U;
            vlSelf->green_o = 1U;
            __Vdly__top__DOT__dut__DOT__state = 1U;
        } else {
            vlSelf->top__DOT__dut__DOT__Count_GREEN = 0U;
            __Vdly__top__DOT__dut__DOT__state = 2U;
        }
    } else {
        __Vdly__top__DOT__dut__DOT__state = ((IData)(vlSelf->pedestrian_button_i)
                                              ? 4U : 1U);
    }
    vlSelf->top__DOT__dut__DOT__state = __Vdly__top__DOT__dut__DOT__state;
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->pedestrian_button_i & 0xfeU))) {
        Verilated::overWidthError("pedestrian_button_i");}
}
#endif  // VL_DEBUG
