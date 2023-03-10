// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Body
    if ((0U == (IData)(vlSelf->sel_i))) {
        if (vlSymsp->_vm_contextp__->assertOn()) {
            if (VL_UNLIKELY((0U != (IData)(vlSelf->result_o)))) {
                VL_WRITEF("[%0t] %%Error: top.sv:20: Assertion failed in %Ntop.proc_assertions: 'assert' failed.\n",
                          64,VL_TIME_UNITED_Q(1),-12,
                          vlSymsp->name());
                VL_STOP_MT("top.sv", 20, "");
            }
        }
    }
    if ((1U == (IData)(vlSelf->sel_i))) {
        if (vlSymsp->_vm_contextp__->assertOn()) {
            if (VL_UNLIKELY(((IData)(vlSelf->result_o) 
                             != ((IData)(vlSelf->data0_i) 
                                 & (IData)(vlSelf->data1_i))))) {
                VL_WRITEF("[%0t] %%Error: top.sv:22: Assertion failed in %Ntop.proc_assertions: 'assert' failed.\n",
                          64,VL_TIME_UNITED_Q(1),-12,
                          vlSymsp->name());
                VL_STOP_MT("top.sv", 22, "");
            }
        }
    }
    if ((2U == (IData)(vlSelf->sel_i))) {
        if (vlSymsp->_vm_contextp__->assertOn()) {
            if (VL_UNLIKELY(((IData)(vlSelf->result_o) 
                             != ((IData)(vlSelf->data0_i) 
                                 | (IData)(vlSelf->data1_i))))) {
                VL_WRITEF("[%0t] %%Error: top.sv:24: Assertion failed in %Ntop.proc_assertions: 'assert' failed.\n",
                          64,VL_TIME_UNITED_Q(1),-12,
                          vlSymsp->name());
                VL_STOP_MT("top.sv", 24, "");
            }
        }
    }
    if ((3U == (IData)(vlSelf->sel_i))) {
        if (vlSymsp->_vm_contextp__->assertOn()) {
            if (VL_UNLIKELY(((IData)(vlSelf->result_o) 
                             != ((IData)(vlSelf->data0_i) 
                                 ^ (IData)(vlSelf->data1_i))))) {
                VL_WRITEF("[%0t] %%Error: top.sv:26: Assertion failed in %Ntop.proc_assertions: 'assert' failed.\n",
                          64,VL_TIME_UNITED_Q(1),-12,
                          vlSymsp->name());
                VL_STOP_MT("top.sv", 26, "");
            }
        }
    }
}
