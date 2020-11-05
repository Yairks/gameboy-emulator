#include "cpu.h"
#include "mem.h"
#include "opcodes.h"
#include <stdio.h>

void LD(unsigned char *, unsigned short);
void LD_B_n(void);
void LD_C_n(void);
void LD_D_n(void);
void LD_E_n(void);
void LD_H_n(void);
void LD_L_n(void);

void LD_A_A(void);
void LD_A_B(void);
void LD_A_C(void);
void LD_A_D(void);
void LD_A_E(void);
void LD_A_H(void);
void LD_A_L(void);
void LD_A_HL(void);
void LD_B_B(void);
void LD_B_C(void);
void LD_B_D(void);
void LD_B_E(void);
void LD_B_H(void);
void LD_B_L(void);
void LD_B_HL(void);
void LD_C_B(void);
void LD_C_C(void);
void LD_C_D(void);
void LD_C_E(void);
void LD_C_H(void);
void LD_C_L(void);
void LD_C_HL(void);
void LD_D_B(void);
void LD_D_C(void);
void LD_D_D(void);
void LD_D_E(void);
void LD_D_H(void);
void LD_D_L(void);
void LD_D_HL(void);
void LD_E_B(void);
void LD_E_C(void);
void LD_E_D(void);
void LD_E_E(void);
void LD_E_H(void);
void LD_E_L(void);
void LD_E_HL(void);
void LD_H_B(void);
void LD_H_C(void);
void LD_H_D(void);
void LD_H_E(void);
void LD_H_H(void);
void LD_H_L(void);
void LD_H_HL(void);
void LD_L_B(void);
void LD_L_C(void);
void LD_L_D(void);
void LD_L_E(void);
void LD_L_H(void);
void LD_L_L(void);
void LD_L_HL(void);
void LD_HL_B(void);
void LD_HL_C(void);
void LD_HL_D(void);
void LD_HL_E(void);
void LD_HL_H(void);
void LD_HL_L(void);
void LD_HL_n(void);

// LD A,n
void LD_A_B(void);
void LD_A_C(void);
void LD_A_D(void);
void LD_A_E(void);
void LD_A_H(void);
void LD_A_L(void);
void LD_A_BC(void);
void LD_A_DE(void);
void LD_A_HL(void);
void LD_A_nn(void);
void LD_A_li(void);

// LD n,A
void LD_B_A(void);
void LD_C_A(void);
void LD_D_A(void);
void LD_E_A(void);
void LD_H_A(void);
void LD_L_A(void);
void LD_BC_A(void);
void LD_DE_A(void);
void LD_HL_A(void);
void LD_nn_A(void);

// LD A,(C)
void LD_A_C_addr(void);

// LD (C),A
void LD_C_addr_A(void);

// LDD A,(HL)
void LDD_A_HL(void);

// LDD (HL),A
void LDD_HL_A(void);

// LDI A,(HL)
void LDI_A_HL(void);

// LDI (HL),A
void LDI_HL_A(void);

void LDH_n_A(void);
void LDH_A_n(void);

// ----------------
// 16-Bit Loads
void LD16(unsigned short *dest, unsigned short src);
void LD16_BC_nn(void);
void LD16_DE_nn(void);
void LD16_HL_nn(void);
void LD16_SP_nn(void);
void LD16_SP_HL(void);
void LDHL_SP_n(void);

void LD_nn_SP(void);

// PUSH operations
void PUSH(unsigned char value);
void PUSH_AF(void);
void PUSH_BC(void);
void PUSH_DE(void);
void PUSH_HL(void);

// POP operations
void POP(unsigned char *variable);
void POP_AF(void);
void POP_BC(void);
void POP_DE(void);
void POP_HL(void);

// 8-Bit ALU
void ADD(unsigned char *dest, unsigned short src);
void ADD_A_A(void);
void ADD_A_B(void);
void ADD_A_C(void);
void ADD_A_D(void);
void ADD_A_E(void);
void ADD_A_H(void);
void ADD_A_L(void);
void ADD_A_HL(void);
void ADD_A_n(void);

// ADC
void ADC(unsigned char *dest, unsigned short src);
void ADC_A_A(void);
void ADC_A_B(void);
void ADC_A_C(void);
void ADC_A_D(void);
void ADC_A_E(void);
void ADC_A_H(void);
void ADC_A_L(void);
void ADC_A_HL(void);
void ADC_A_n(void);

// SUB
void SUB(unsigned char src, bool save_value);
void SUB_A(void);
void SUB_B(void);
void SUB_C(void);
void SUB_D(void);
void SUB_E(void);
void SUB_H(void);
void SUB_L(void);
void SUB_HL(void);
void SUB_n(void);

// SBC
void SBC(unsigned char *dest, unsigned short src);
void SBC_A_A(void);
void SBC_A_B(void);
void SBC_A_C(void);
void SBC_A_D(void);
void SBC_A_E(void);
void SBC_A_H(void);
void SBC_A_L(void);
void SBC_A_HL(void);
void SBC_A_n(void);

// AND
void AND(unsigned char src);
void AND_A(void);
void AND_B(void);
void AND_C(void);
void AND_D(void);
void AND_E(void);
void AND_H(void);
void AND_L(void);
void AND_HL(void);
void AND_n(void);

// OR
void OR(unsigned char src);
void OR_A(void);
void OR_B(void);
void OR_C(void);
void OR_D(void);
void OR_E(void);
void OR_H(void);
void OR_L(void);
void OR_HL(void);
void OR_n(void);

// XOR
void XOR(unsigned char src);
void XOR_A(void);
void XOR_B(void);
void XOR_C(void);
void XOR_D(void);
void XOR_E(void);
void XOR_H(void);
void XOR_L(void);
void XOR_HL(void);
void XOR_n(void);

void CP(unsigned char src);
void CP_A(void);
void CP_B(void);
void CP_C(void);
void CP_D(void);
void CP_E(void);
void CP_H(void);
void CP_L(void);
void CP_HL(void);
void CP_n(void);

void INC(unsigned char *dest);
void INC_A(void);
void INC_B(void);
void INC_C(void);
void INC_D(void);
void INC_E(void);
void INC_H(void);
void INC_L(void);
void INC_HL(void);

void DEC(unsigned char *dest);
void DEC_A(void);
void DEC_B(void);
void DEC_C(void);
void DEC_D(void);
void DEC_E(void);
void DEC_H(void);
void DEC_L(void);
void DEC_HL(void);

// 16-bit arithmetic!
void ADD16(unsigned short *dest, unsigned short src);
void ADD16_BC(void);
void ADD16_DE(void);
void ADD16_HL(void);
void ADD16_SP(void);

void ADD16_SP_n(void);

void INC16(unsigned short *dest);
void INC16_BC(void);
void INC16_DE(void);
void INC16_HL(void);
void INC16_SP(void);

void DEC16(unsigned short *dest);
void DEC16_BC(void);
void DEC16_DE(void);
void DEC16_HL(void);
void DEC16_SP(void);

// ----------------------
// Miscellaneous
// This is it, guys. The extensions.
// The big kahuna. The ripe orange.
// The tasty melon. You get the point.
void SWAP(unsigned char *target);
void SWAP_A(void);
void SWAP_B(void);
void SWAP_C(void);
void SWAP_D(void);
void SWAP_E(void);
void SWAP_H(void);
void SWAP_L(void);
void SWAP_HL(void);

// Actually, not all of the misc are extensions. Huh.
void DAA(void);
void CPL(void);

void CCF(void);
void SCF(void);

// My favorite OP!
void NOP(void);
void HALT(void);
void STOP(void);
void DI(void); // What a throwback. First instruction in pokemon silver. Things were so simple then, back when I knew nothing about impementing an instruction set.
void EI(void);

// ----------------
// Rotates & Shifts
void RLCA(void);
void RLA(void);
void RRCA(void); // Why all these random ops on the A register? Give the other registers some love
void RRA(void);

void RLC(unsigned char *target); // Finally
void RLC_A(void); // Aww cmon, now you're jsut repeating yourself.
void RLC_B(void);
void RLC_C(void);
void RLC_D(void);
void RLC_E(void);
void RLC_H(void);
void RLC_L(void);
void RLC_HL(void);

void RL(unsigned char *target);
void RL_A(void);
void RL_B(void);
void RL_C(void);
void RL_D(void);
void RL_E(void);
void RL_H(void);
void RL_L(void);
void RL_HL(void);

void RRC(unsigned char *target);
void RRC_A(void);
void RRC_B(void);
void RRC_C(void);
void RRC_D(void);
void RRC_E(void);
void RRC_H(void);
void RRC_L(void);
void RRC_HL(void);

void RR(unsigned char *target);
void RR_A(void);
void RR_B(void);
void RR_C(void);
void RR_D(void);
void RR_E(void);
void RR_H(void);
void RR_L(void);
void RR_HL(void);

void SLA(unsigned char *target);
void SLA_A(void);
void SLA_B(void);
void SLA_C(void);
void SLA_D(void);
void SLA_E(void);
void SLA_H(void);
void SLA_L(void);
void SLA_HL(void);

void SRA(unsigned char *target);
void SRA_A(void);
void SRA_B(void);
void SRA_C(void);
void SRA_D(void);
void SRA_E(void);
void SRA_H(void);
void SRA_L(void);
void SRA_HL(void);

void SRL(unsigned char *target);
void SRL_A(void);
void SRL_B(void);
void SRL_C(void);
void SRL_D(void);
void SRL_E(void);
void SRL_H(void);
void SRL_L(void);
void SRL_HL(void);

// -----------------
// Bit Opcodes !!
void BIT(unsigned char target, unsigned char bit);
void BIT0_A(void);
void BIT0_B(void);
void BIT0_C(void);
void BIT0_D(void);
void BIT0_E(void);
void BIT0_H(void);
void BIT0_L(void);
void BIT0_HL(void);

void BIT1_A(void);
void BIT1_B(void);
void BIT1_C(void);
void BIT1_D(void);
void BIT1_E(void);
void BIT1_H(void);
void BIT1_L(void);
void BIT1_HL(void);

void BIT2_A(void);
void BIT2_B(void);
void BIT2_C(void);
void BIT2_D(void);
void BIT2_E(void);
void BIT2_H(void);
void BIT2_L(void);
void BIT2_HL(void);

void BIT3_A(void);
void BIT3_B(void);
void BIT3_C(void);
void BIT3_D(void);
void BIT3_E(void);
void BIT3_H(void);
void BIT3_L(void);
void BIT3_HL(void);

void BIT4_A(void);
void BIT4_B(void);
void BIT4_C(void);
void BIT4_D(void);
void BIT4_E(void);
void BIT4_H(void);
void BIT4_L(void);
void BIT4_HL(void);

void BIT5_A(void);
void BIT5_B(void);
void BIT5_C(void);
void BIT5_D(void);
void BIT5_E(void);
void BIT5_H(void);
void BIT5_L(void);
void BIT5_HL(void);

void BIT6_A(void);
void BIT6_B(void);
void BIT6_C(void);
void BIT6_D(void);
void BIT6_E(void);
void BIT6_H(void);
void BIT6_L(void);
void BIT6_HL(void);

void BIT7_A(void);
void BIT7_B(void);
void BIT7_C(void);
void BIT7_D(void);
void BIT7_E(void);
void BIT7_H(void);
void BIT7_L(void);
void BIT7_HL(void);

void SET(unsigned char *target, unsigned char bit);
void SET_A(void);
void SET_B(void);
void SET_C(void);
void SET_D(void);
void SET_E(void);
void SET_H(void);
void SET_L(void);
void SET_HL(void);

void RESET(unsigned char *target, unsigned char bit);
void RESET_A(void);
void RESET_B(void);
void RESET_C(void);
void RESET_D(void);
void RESET_E(void);
void RESET_H(void);
void RESET_L(void);
void RESET_HL(void);

// --------------
// Jumps !! Woohoo !!
void JP(void);
void JP_NZ(void);
void JP_Z(void);
void JP_NC(void);
void JP_C(void);
void JP_HL(void);
void JR(void);
void JR_NZ(void);
void JR_Z(void);
void JR_NC(void);
void JR_C(void);

// ----------------
// Calls
void CALL(void);
void CALL_NZ(void);
void CALL_Z(void);
void CALL_NC(void);
void CALL_C(void);

// ----------------
// Restarts
void RST(unsigned char location);
void RST_00(void);
void RST_08(void);
void RST_10(void);
void RST_18(void);
void RST_20(void);
void RST_28(void);
void RST_30(void);
void RST_38(void);


// ----------------
// Returns
void RET(void);
void RET_NZ(void);
void RET_Z(void);
void RET_NC(void);
void RET_C(void);
void RETI(void);

void init_opcodes(void) {
    opcodes[0x06] = LD_B_n;
    opcodes[0x0E] = LD_C_n;
    opcodes[0x16] = LD_D_n;
    opcodes[0x1E] = LD_E_n;
    opcodes[0x26] = LD_H_n;
    opcodes[0x2E] = LD_L_n;

    opcodes[0x7F] = LD_A_A;
    opcodes[0x78] = LD_A_B;
    opcodes[0x79] = LD_A_C;
    opcodes[0x7A] = LD_A_D;
    opcodes[0x7B] = LD_A_E;
    opcodes[0x7C] = LD_A_H;
    opcodes[0x7D] = LD_A_L;
    opcodes[0x7E] = LD_A_HL;
    opcodes[0x40] = LD_B_B;
    opcodes[0x41] = LD_B_C;
    opcodes[0x42] = LD_B_D;
    opcodes[0x43] = LD_B_E;
    opcodes[0x44] = LD_B_H;
    opcodes[0x45] = LD_B_L;
    opcodes[0x46] = LD_B_HL;
    opcodes[0x48] = LD_C_B;
    opcodes[0x49] = LD_C_C;
    opcodes[0x4A] = LD_C_D;
    opcodes[0x4B] = LD_C_E;
    opcodes[0x4C] = LD_C_H;
    opcodes[0x4D] = LD_C_L;
    opcodes[0x4E] = LD_C_HL;
    opcodes[0x50] = LD_D_B;
    opcodes[0x51] = LD_D_C;
    opcodes[0x52] = LD_D_D;
    opcodes[0x53] = LD_D_E;
    opcodes[0x54] = LD_D_H;
    opcodes[0x55] = LD_D_L;
    opcodes[0x56] = LD_D_HL;
    opcodes[0x58] = LD_E_B;
    opcodes[0x59] = LD_E_C;
    opcodes[0x5A] = LD_E_D;
    opcodes[0x5B] = LD_E_E;
    opcodes[0x5C] = LD_E_H;
    opcodes[0x5D] = LD_E_L;
    opcodes[0x5E] = LD_E_HL;
    opcodes[0x60] = LD_H_B;
    opcodes[0x61] = LD_H_C;
    opcodes[0x62] = LD_H_D;
    opcodes[0x63] = LD_H_E;
    opcodes[0x64] = LD_H_H;
    opcodes[0x65] = LD_H_L;
    opcodes[0x66] = LD_H_HL;
    opcodes[0x68] = LD_L_B;
    opcodes[0x69] = LD_L_C;
    opcodes[0x6A] = LD_L_D;
    opcodes[0x6B] = LD_L_E;
    opcodes[0x6C] = LD_L_H;
    opcodes[0x6D] = LD_L_L;
    opcodes[0x6E] = LD_L_HL;
    opcodes[0x70] = LD_HL_B;
    opcodes[0x71] = LD_HL_C;
    opcodes[0x72] = LD_HL_D;
    opcodes[0x73] = LD_HL_E;
    opcodes[0x74] = LD_HL_H;
    opcodes[0x75] = LD_HL_L;
    opcodes[0x36] = LD_HL_n;

    // LD A,n
    opcodes[0x78] = LD_A_B;
    opcodes[0x79] = LD_A_C;
    opcodes[0x7A] = LD_A_D;
    opcodes[0x7B] = LD_A_E;
    opcodes[0x7C] = LD_A_H;
    opcodes[0x7D] = LD_A_L;
    opcodes[0x0A] = LD_A_BC;
    opcodes[0x1A] = LD_A_DE;
    opcodes[0x7E] = LD_A_HL;
    opcodes[0xFA] = LD_A_nn;
    opcodes[0x3E] = LD_A_li;

    // LD n,A
    opcodes[0x47] = LD_B_A;
    opcodes[0x4F] = LD_C_A;
    opcodes[0x57] = LD_D_A;
    opcodes[0x5F] = LD_E_A;
    opcodes[0x67] = LD_H_A;
    opcodes[0x6F] = LD_L_A;
    opcodes[0x02] = LD_BC_A;
    opcodes[0x12] = LD_DE_A;
    opcodes[0x77] = LD_HL_A;
    opcodes[0xEA] = LD_nn_A;

    // LD A,(C)
    opcodes[0xF2] = LD_A_C_addr;
    opcodes[0xE2] = LD_C_addr_A;

    // LDD A,(HL)
    opcodes[0x3A] = LDD_A_HL;

    // LDD (HL),A
    opcodes[0x32] = LDD_HL_A;

    // LDI A,(HL)
    opcodes[0x2A] = LDI_A_HL;

    // LDI (HL),A
    opcodes[0x22] = LDI_HL_A;

    opcodes[0xE0] = LDH_n_A;
    opcodes[0xF0] = LDH_A_n;

    //-----------------
    // 16-Bit Loads
    opcodes[0x01] = LD16_BC_nn;
    opcodes[0x11] = LD16_DE_nn;
    opcodes[0x21] = LD16_HL_nn;
    opcodes[0x31] = LD16_SP_nn;
    opcodes[0xF9] = LD16_SP_HL;

    opcodes[0xF8] = LDHL_SP_n;
    opcodes[0x08] = LD_nn_SP;

    opcodes[0xF5] = PUSH_AF;
    opcodes[0xC5] = PUSH_BC;
    opcodes[0xD5] = PUSH_DE;
    opcodes[0xE5] = PUSH_HL;

    opcodes[0xF1] = POP_AF;
    opcodes[0xC1] = POP_BC;
    opcodes[0xD1] = POP_DE;
    opcodes[0xE1] = POP_HL;

    opcodes[0x87] = ADD_A_A;
    opcodes[0x80] = ADD_A_B;
    opcodes[0x81] = ADD_A_C;
    opcodes[0x82] = ADD_A_D;
    opcodes[0x83] = ADD_A_E;
    opcodes[0x84] = ADD_A_H;
    opcodes[0x85] = ADD_A_L;
    opcodes[0x86] = ADD_A_HL;
    opcodes[0xC6] = ADD_A_n;

    opcodes[0x8F] = ADC_A_A;
    opcodes[0x88] = ADC_A_B;
    opcodes[0x89] = ADC_A_C;
    opcodes[0x8A] = ADC_A_D;
    opcodes[0x8B] = ADC_A_E;
    opcodes[0x8C] = ADC_A_H;
    opcodes[0x8D] = ADC_A_L;
    opcodes[0x8E] = ADC_A_HL;
    opcodes[0xCE] = ADC_A_n;

    opcodes[0x97] = SUB_A;
    opcodes[0x90] = SUB_B;
    opcodes[0x91] = SUB_C;
    opcodes[0x92] = SUB_D;
    opcodes[0x93] = SUB_E;
    opcodes[0x94] = SUB_H;
    opcodes[0x95] = SUB_L;
    opcodes[0x96] = SUB_HL;
    opcodes[0xD6] = SUB_n;

    opcodes[0x9F] = SBC_A_A;
    opcodes[0x98] = SBC_A_B;
    opcodes[0x99] = SBC_A_C;
    opcodes[0x9A] = SBC_A_D;
    opcodes[0x9B] = SBC_A_E;
    opcodes[0x9C] = SBC_A_H;
    opcodes[0x9D] = SBC_A_L;
    opcodes[0x9E] = SBC_A_HL;
    // opcodes[0x9E] = SBC_A_n; // Listed in the manual as opcode number ??. Hmm.

    opcodes[0xA7] = AND_A;
    opcodes[0xA0] = AND_B;
    opcodes[0xA1] = AND_C;
    opcodes[0xA2] = AND_D;
    opcodes[0xA3] = AND_E;
    opcodes[0xA4] = AND_H;
    opcodes[0xA5] = AND_L;
    opcodes[0xA6] = AND_HL;
    opcodes[0xE6] = AND_n;

    opcodes[0xB7] = OR_A;
    opcodes[0xB0] = OR_B;
    opcodes[0xB1] = OR_C;
    opcodes[0xB2] = OR_D;
    opcodes[0xB3] = OR_E;
    opcodes[0xB4] = OR_H;
    opcodes[0xB5] = OR_L;
    opcodes[0xB6] = OR_HL;
    opcodes[0xF6] = OR_n;

    opcodes[0xAF] = XOR_A;
    opcodes[0xA8] = XOR_B;
    opcodes[0xA9] = XOR_C;
    opcodes[0xAA] = XOR_D;
    opcodes[0xAB] = XOR_E;
    opcodes[0xAC] = XOR_H;
    opcodes[0xAD] = XOR_L;
    opcodes[0xAE] = XOR_HL;
    opcodes[0xEE] = XOR_n;

    opcodes[0xBF] = CP_A;
    opcodes[0xB8] = CP_B;
    opcodes[0xB9] = CP_C;
    opcodes[0xBA] = CP_D;
    opcodes[0xBB] = CP_E;
    opcodes[0xBC] = CP_H;
    opcodes[0xBD] = CP_L;
    opcodes[0xBE] = CP_HL;
    opcodes[0xFE] = CP_n;

    opcodes[0x3C] = INC_A;
    opcodes[0x04] = INC_B;
    opcodes[0x0C] = INC_C;
    opcodes[0x14] = INC_D;
    opcodes[0x1C] = INC_E;
    opcodes[0x24] = INC_H;
    opcodes[0x2C] = INC_L;
    opcodes[0x34] = INC_HL;

    opcodes[0x3D] = DEC_A;
    opcodes[0x05] = DEC_B;
    opcodes[0x0D] = DEC_C;
    opcodes[0x15] = DEC_D;
    opcodes[0x1D] = DEC_E;
    opcodes[0x25] = DEC_H;
    opcodes[0x2D] = DEC_L;
    opcodes[0x35] = DEC_HL;

    opcodes[0x09] = ADD16_BC;
    opcodes[0x19] = ADD16_DE;
    opcodes[0x29] = ADD16_HL;
    opcodes[0x39] = ADD16_SP;

    opcodes[0xE8] = ADD16_SP_n;

    opcodes[0x03] = INC16_BC;
    opcodes[0x13] = INC16_DE;
    opcodes[0x23] = INC16_HL;
    opcodes[0x33] = INC16_SP;

    opcodes[0x0B] = DEC16_BC;
    opcodes[0x1B] = DEC16_DE;
    opcodes[0x2B] = DEC16_HL;
    opcodes[0x3B] = DEC16_SP;

    opcodes_ex[0x37] = SWAP_A;
    opcodes_ex[0x30] = SWAP_B;
    opcodes_ex[0x31] = SWAP_C;
    opcodes_ex[0x32] = SWAP_D;
    opcodes_ex[0x33] = SWAP_E;
    opcodes_ex[0x34] = SWAP_H;
    opcodes_ex[0x35] = SWAP_L;
    opcodes_ex[0x36] = SWAP_HL;

    opcodes[0x27] = DAA;
    opcodes[0x2F] = CPL;

    opcodes[0x3F] = CCF;
    opcodes[0x37] = SCF;

    opcodes[0x00] = NOP; // NOPE!
    opcodes[0x76] = HALT;
    opcodes[0x10] = STOP;
    opcodes[0xF3] = DI;
    opcodes[0xFB] = EI; // Facebook!

    opcodes[0x07] = RLCA;
    opcodes[0x17] = RLA;
    opcodes[0x0F] = RRCA;
    opcodes[0x1F] = RRA;

    opcodes_ex[0x07] = RLC_A;
    opcodes_ex[0x00] = RLC_B;
    opcodes_ex[0x01] = RLC_C;
    opcodes_ex[0x02] = RLC_D;
    opcodes_ex[0x03] = RLC_E;
    opcodes_ex[0x04] = RLC_H;
    opcodes_ex[0x05] = RLC_L;
    opcodes_ex[0x06] = RLC_HL;

    opcodes_ex[0x17] = RL_A;
    opcodes_ex[0x10] = RL_B;
    opcodes_ex[0x11] = RL_C;
    opcodes_ex[0x12] = RL_D;
    opcodes_ex[0x13] = RL_E;
    opcodes_ex[0x14] = RL_H;
    opcodes_ex[0x15] = RL_L;
    opcodes_ex[0x16] = RL_HL;

    opcodes_ex[0x0F] = RRC_A;
    opcodes_ex[0x08] = RRC_B;
    opcodes_ex[0x09] = RRC_C;
    opcodes_ex[0x0A] = RRC_D;
    opcodes_ex[0x0B] = RRC_E;
    opcodes_ex[0x0C] = RRC_H;
    opcodes_ex[0x0D] = RRC_L;
    opcodes_ex[0x0E] = RRC_HL;

    opcodes_ex[0x1F] = RR_A;
    opcodes_ex[0x18] = RR_B;
    opcodes_ex[0x19] = RR_C;
    opcodes_ex[0x1A] = RR_D;
    opcodes_ex[0x1B] = RR_E;
    opcodes_ex[0x1C] = RR_H;
    opcodes_ex[0x1D] = RR_L;
    opcodes_ex[0x1E] = RR_HL;

    opcodes_ex[0x27] = SLA_A;
    opcodes_ex[0x20] = SLA_B;
    opcodes_ex[0x21] = SLA_C;
    opcodes_ex[0x22] = SLA_D;
    opcodes_ex[0x23] = SLA_E;
    opcodes_ex[0x24] = SLA_H;
    opcodes_ex[0x25] = SLA_L;
    opcodes_ex[0x26] = SLA_HL;

    opcodes_ex[0x2F] = SRA_A;
    opcodes_ex[0x28] = SRA_B;
    opcodes_ex[0x29] = SRA_C;
    opcodes_ex[0x2A] = SRA_D;
    opcodes_ex[0x2B] = SRA_E;
    opcodes_ex[0x2C] = SRA_H;
    opcodes_ex[0x2D] = SRA_L;
    opcodes_ex[0x2E] = SRA_HL;

    opcodes_ex[0x3F] = SRL_A;
    opcodes_ex[0x38] = SRL_B;
    opcodes_ex[0x39] = SRL_C;
    opcodes_ex[0x3A] = SRL_D;
    opcodes_ex[0x3B] = SRL_E;
    opcodes_ex[0x3C] = SRL_H;
    opcodes_ex[0x3D] = SRL_L;
    opcodes_ex[0x3E] = SRL_HL;

    opcodes_ex[0x47] = BIT0_A;
    opcodes_ex[0x40] = BIT0_B;
    opcodes_ex[0x41] = BIT0_C;
    opcodes_ex[0x42] = BIT0_D;
    opcodes_ex[0x43] = BIT0_E;
    opcodes_ex[0x44] = BIT0_H;
    opcodes_ex[0x45] = BIT0_L;
    opcodes_ex[0x46] = BIT0_HL;

    opcodes_ex[0xC7] = SET_A;
    opcodes_ex[0xC0] = SET_B;
    opcodes_ex[0xC1] = SET_C;
    opcodes_ex[0xC2] = SET_D;
    opcodes_ex[0xC3] = SET_E;
    opcodes_ex[0xC4] = SET_H;
    opcodes_ex[0xC5] = SET_L;
    opcodes_ex[0xC6] = SET_HL;

    opcodes_ex[0x87] = RESET_A;
    opcodes_ex[0x80] = RESET_B;
    opcodes_ex[0x81] = RESET_C;
    opcodes_ex[0x82] = RESET_D;
    opcodes_ex[0x83] = RESET_E;
    opcodes_ex[0x84] = RESET_H;
    opcodes_ex[0x85] = RESET_L;
    opcodes_ex[0x86] = RESET_HL;

    // Just filling in some more opcodes:
    opcodes_ex[0x48] = BIT1_B;
    opcodes_ex[0x49] = BIT1_C;
    opcodes_ex[0x4A] = BIT1_D;
    opcodes_ex[0x4B] = BIT1_E;
    opcodes_ex[0x4C] = BIT1_H;
    opcodes_ex[0x4D] = BIT1_L;
    opcodes_ex[0x4E] = BIT1_HL;
    opcodes_ex[0x4F] = BIT1_A;

    opcodes_ex[0x50] = BIT2_B;
    opcodes_ex[0x51] = BIT2_C;
    opcodes_ex[0x52] = BIT2_D;
    opcodes_ex[0x53] = BIT2_E;
    opcodes_ex[0x54] = BIT2_H;
    opcodes_ex[0x55] = BIT2_L;
    opcodes_ex[0x56] = BIT2_HL;
    opcodes_ex[0x57] = BIT2_A;
    opcodes_ex[0x58] = BIT3_B;
    opcodes_ex[0x59] = BIT3_C;
    opcodes_ex[0x5A] = BIT3_D;
    opcodes_ex[0x5B] = BIT3_E;
    opcodes_ex[0x5C] = BIT3_H;
    opcodes_ex[0x5D] = BIT3_L;
    opcodes_ex[0x5E] = BIT3_HL;
    opcodes_ex[0x5F] = BIT3_A;

    opcodes_ex[0x60] = BIT4_B;
    opcodes_ex[0x61] = BIT4_C;
    opcodes_ex[0x62] = BIT4_D;
    opcodes_ex[0x63] = BIT4_E;
    opcodes_ex[0x64] = BIT4_H;
    opcodes_ex[0x65] = BIT4_L;
    opcodes_ex[0x66] = BIT4_HL;
    opcodes_ex[0x67] = BIT4_A;
    opcodes_ex[0x68] = BIT5_B;
    opcodes_ex[0x69] = BIT5_C;
    opcodes_ex[0x6A] = BIT5_D;
    opcodes_ex[0x6B] = BIT5_E;
    opcodes_ex[0x6C] = BIT5_H;
    opcodes_ex[0x6D] = BIT5_L;
    opcodes_ex[0x6E] = BIT5_HL;
    opcodes_ex[0x6F] = BIT5_A;

    opcodes_ex[0x70] = BIT6_B;
    opcodes_ex[0x71] = BIT6_C;
    opcodes_ex[0x72] = BIT6_D;
    opcodes_ex[0x73] = BIT6_E;
    opcodes_ex[0x74] = BIT6_H;
    opcodes_ex[0x75] = BIT6_L;
    opcodes_ex[0x76] = BIT6_HL;
    opcodes_ex[0x77] = BIT6_A;
    opcodes_ex[0x78] = BIT7_B;
    opcodes_ex[0x79] = BIT7_C;
    opcodes_ex[0x7A] = BIT7_D;
    opcodes_ex[0x7B] = BIT7_E;
    opcodes_ex[0x7C] = BIT7_H;
    opcodes_ex[0x7D] = BIT7_L;
    opcodes_ex[0x7E] = BIT7_HL;
    opcodes_ex[0x7F] = BIT7_A;

    opcodes[0xC3] = JP;
    opcodes[0xC2] = JP_NZ;
    opcodes[0xCA] = JP_Z;
    opcodes[0xD2] = JP_NC;
    opcodes[0xDA] = JP_C;
    opcodes[0xE9] = JP_HL;
    opcodes[0x18] = JR;
    opcodes[0x20] = JR_NZ;
    opcodes[0x28] = JR_Z;
    opcodes[0x30] = JR_NC;
    opcodes[0x38] = JR_C;

    opcodes[0xCD] = CALL;
    opcodes[0xC4] = CALL_NZ;
    opcodes[0xCC] = CALL_Z;
    opcodes[0xD4] = CALL_NC;
    opcodes[0xDC] = CALL_C;

    opcodes[0xC7] = RST_00;
    opcodes[0xCF] = RST_08;
    opcodes[0xD7] = RST_10;
    opcodes[0xDF] = RST_18;
    opcodes[0xE7] = RST_20;
    opcodes[0xEF] = RST_28;
    opcodes[0xF7] = RST_30;
    opcodes[0xFF] = RST_38;

    opcodes[0xC9] = RET;
    opcodes[0xC0] = RET_NZ;
    opcodes[0xC8] = RET_Z;
    opcodes[0xD0] = RET_NC;
    opcodes[0xD8] = RET_C;
    opcodes[0xD9] = RETI;
}

void LD(unsigned char *dest, unsigned short src) {
    *dest = src;
}

void LD_B_n(void) {
    LD(&registers.b, get_immediate());
    pc++;
}

void LD_C_n(void) {
    LD(&registers.c, get_immediate());
    pc++;
}

void LD_D_n(void) {
    LD(&registers.d, get_immediate());
    pc++;
}

void LD_E_n(void) {
    LD(&registers.e, get_immediate());
    pc++;
}

void LD_H_n(void) {
    LD(&registers.h, get_immediate());
    pc++;
}

void LD_L_n(void) {
    LD(&registers.l, get_immediate());
    pc++;
}

// 2. LD r1,r2
void LD_A_A(void) {
    LD(&registers.a, registers.a);
}

void LD_A_B(void) {
    LD(&registers.a, registers.b);
}

void LD_A_C(void) {
    LD(&registers.a, registers.c);
}

void LD_A_D(void) {
    LD(&registers.a, registers.d);
}

void LD_A_E(void) {
    LD(&registers.a, registers.e);
}

void LD_A_H(void) {
    LD(&registers.a, registers.h);
}

void LD_A_L(void) {
    LD(&registers.a, registers.l);
}

void LD_A_HL(void) {
    LD(&registers.a, memory[registers.hl]);
}

void LD_B_B(void) {
    LD(&registers.b, registers.b);
}

void LD_B_C(void) {
    LD(&registers.b, registers.c);
}

void LD_B_D(void) {
    LD(&registers.b, registers.d);
}

void LD_B_E(void) {
    LD(&registers.b, registers.e);
}

void LD_B_H(void) {
    LD(&registers.b, registers.h);
}

void LD_B_L(void) {
    LD(&registers.b, registers.l);
}

void LD_B_HL(void) {
    LD(&registers.b, memory[registers.hl]);
}

void LD_C_B(void) {
    LD(&registers.c, registers.b);
}

void LD_C_C(void) {
    LD(&registers.c, registers.c);
}

void LD_C_D(void) {
    LD(&registers.c, registers.d);
}

void LD_C_E(void) {
    LD(&registers.c, registers.e);
}

void LD_C_H(void) {
    LD(&registers.c, registers.h);
}

void LD_C_L(void) {
    LD(&registers.c, registers.l);
}

void LD_C_HL(void) {
    LD(&registers.c, memory[registers.hl]);
}

void LD_D_B(void) {
    LD(&registers.d, registers.b);
}

void LD_D_C(void) {
    LD(&registers.d, registers.c);
}

void LD_D_D(void) {
    LD(&registers.d, registers.d);
}

void LD_D_E(void) {
    LD(&registers.d, registers.e);
}

void LD_D_H(void) {
    LD(&registers.d, registers.h);
}

void LD_D_L(void) {
    LD(&registers.d, registers.l);
}

void LD_D_HL(void) {
    LD(&registers.d, memory[registers.hl]);
}

void LD_E_B(void) {
    LD(&registers.e, registers.b);
}

void LD_E_C(void) {
    LD(&registers.e, registers.c);
}

void LD_E_D(void) {
    LD(&registers.e, registers.d);
}

void LD_E_E(void) {
    LD(&registers.e, registers.e);
}

void LD_E_H(void) {
    LD(&registers.e, registers.h);
}

void LD_E_L(void) {
    LD(&registers.e, registers.l);
}

void LD_E_HL(void) {
    LD(&registers.e, memory[registers.hl]);
}

void LD_H_B(void) {
    LD(&registers.h, registers.b);
}

void LD_H_C(void) {
    LD(&registers.h, registers.c);
}

void LD_H_D(void) {
    LD(&registers.h, registers.d);
}

void LD_H_E(void) {
    LD(&registers.h, registers.e);
}

void LD_H_H(void) {
    LD(&registers.h, registers.h);
}

void LD_H_L(void) {
    LD(&registers.h, registers.l);
}

void LD_H_HL(void) {
    LD(&registers.h, memory[registers.hl]);
}

void LD_L_B(void) {
    LD(&registers.l, registers.b);
}

void LD_L_C(void) {
    LD(&registers.l, registers.c);
}

void LD_L_D(void) {
    LD(&registers.l, registers.d);
}

void LD_L_E(void) {
    LD(&registers.l, registers.e);
}

void LD_L_H(void) {
    LD(&registers.l, registers.h);
}

void LD_L_L(void) {
    LD(&registers.l, registers.l);
}

void LD_L_HL(void) {
    LD(&registers.l, memory[registers.hl]);
}

void LD_HL_B(void) {
    LD(&memory[registers.hl], registers.b);
}

void LD_HL_C(void) {
    LD(&memory[registers.hl], registers.c);
}

void LD_HL_D(void) {
    LD(&memory[registers.hl], registers.d);
}

void LD_HL_E(void) {
    LD(&memory[registers.hl], registers.e);
}

void LD_HL_H(void) {
    LD(&memory[registers.hl], registers.h);
}

void LD_HL_L(void) {
    LD(&memory[registers.hl], registers.l);
}

void LD_HL_n(void) {
    LD(&memory[registers.hl], get_immediate());
    pc++;
}

void LD_A_BC(void) {
    LD(&registers.a, registers.bc);
}

void LD_A_DE(void) {
    LD(&registers.a, registers.de);
}

void LD_A_nn(void) {
    LD(&registers.a, get_word());
    pc += 2;
}

void LD_A_li(void) {
    LD(&registers.a, get_immediate());
    pc++;
}

// LD n,A
void LD_B_A(void) {
    LD(&registers.b, registers.a);
}

void LD_C_A(void) {
    LD(&registers.c, registers.a);
}

void LD_D_A(void) {
    LD(&registers.d, registers.a);
}

void LD_E_A(void) {
    LD(&registers.e, registers.a);
}

void LD_H_A(void) {
    LD(&registers.h, registers.a);
}

void LD_L_A(void) {
    LD(&registers.l, registers.a);
}

void LD_BC_A(void) {
    LD(&memory[registers.bc], registers.a);
}

void LD_DE_A(void) {
    LD(&memory[registers.de], registers.a);
}

void LD_HL_A(void) {
    LD(&memory[registers.hl], registers.a);
}

void LD_nn_A(void) {
    LD(&memory[get_word()], registers.a);
    pc += 2;
}

// LD A,(C)
void LD_A_C_addr(void) {
    LD(&registers.a, memory[0xFF00 + registers.c]);
}

// LD A,(C)
void LD_C_addr_A(void) {
    LD(&memory[0xFF00 + registers.c], registers.a);
}

void LDD_A_HL(void) {
    LD_A_HL();
    DEC_HL();
}

// LDD (HL),A
void LDD_HL_A(void) {
    LD_HL_A();
    DEC_HL();
}

void LDI_A_HL(void) {
    LD_A_HL();
    INC_HL();
}

// LDD (HL),A
void LDI_HL_A(void) {
    LD_HL_A();
    INC_HL();
}

void LDH_n_A(void) {
    LD(&memory[0xFF00 + get_immediate()], registers.a);
    pc++;
}

void LDH_A_n(void) {
    LD(&registers.a, memory[0xFF00 + get_immediate()]);
    pc++;
}

void LD16(unsigned short *dest, unsigned short src) {
    *dest = src;
}

void LD16_BC_nn(void) {
    LD16(&registers.bc, get_word());
    pc += 2;
}

void LD16_DE_nn(void) {
    LD16(&registers.de, get_word());
    pc += 2;
}

void LD16_HL_nn(void) {
    LD16(&registers.hl, get_word());
    pc += 2;
}

void LD16_SP_nn(void) {
    LD16(&registers.sp, get_word());
    pc += 2;
}

void LD16_SP_HL(void) {
    LD16(&registers.sp, registers.hl);
}

void LDHL_SP_n(void) {
    LD16(&registers.hl, registers.sp + get_immediate());
    unsigned char next = get_immediate();
    unsigned char next_abs = next & 0x7F;

    flags.z = 0;
    flags.n = 0;

    if (next & 0x80) { // if is negative
        flags.h = (registers.sp & 0x0F) < (next_abs & 0x0F);
        flags.c = (registers.sp & 0xFF) < next_abs;
        LD16(&registers.hl, (registers.sp - next_abs) & 0xFFFF);
    }
    else {
        flags.c = ((registers.sp & 0xFF) + next_abs) > 0xFF;
        flags.h = (((registers.sp & 0x0F) + (next_abs & 0x0F)) > 0x0F);
        LD16(&registers.hl, registers.sp + (next_abs & 0xFFFF));
    }
    pc++;
}

void LD_nn_SP(void) {
    unsigned short address = get_word();
    LD(&memory[address & 0xFF], registers.sp & 0xFF);
    LD(&memory[(address & 0xFF00) >> 8], (registers.sp & 0xFF00) >> 8);
    pc += 2;
}

void PUSH(unsigned char value) {
    registers.sp--;
    stack[registers.sp] = value;
}

void PUSH_AF(void) {
    PUSH(registers.a);
    PUSH(registers.f);
}

void PUSH_BC(void) {
    PUSH(registers.b);
    PUSH(registers.c);
}

void PUSH_DE(void) {
    PUSH(registers.d);
    PUSH(registers.e);
}

void PUSH_HL(void) {
    PUSH(registers.h);
    PUSH(registers.l);
}

void POP(unsigned char *variable) {
    *variable = stack[registers.sp];
    registers.sp++;
}

void POP_AF(void) {
    POP(&registers.f);
    POP(&registers.a);
}

void POP_BC(void) {
    POP(&registers.c);
    POP(&registers.b);
}

void POP_DE(void) {
    POP(&registers.e);
    POP(&registers.d);
}

void POP_HL(void) {
    POP(&registers.l);
    POP(&registers.h);
}

// ---------------
// 8-Bit ALU
void ADD(unsigned char *dest, unsigned short src) {
    flags.z = !((*dest + src)&0xFF);
    flags.n = 0;
    flags.h = ((*dest)&0x0F) + (src&0x0F) > 0x0F;
    flags.c = (short)*dest + (short)src > 0xFF;
    *dest += src;
}

void ADD_A_A(void) {
    ADD(&registers.a, registers.a);
}

void ADD_A_B(void) {
    ADD(&registers.a, registers.b);
}

void ADD_A_C(void) {
    ADD(&registers.a, registers.c);
}

void ADD_A_D(void) {
    ADD(&registers.a, registers.d);
}

void ADD_A_E(void) {
    ADD(&registers.a, registers.e);
}

void ADD_A_H(void) {
    ADD(&registers.a, registers.h);
}

void ADD_A_L(void) {
    ADD(&registers.a, registers.l);
}

void ADD_A_HL(void) {
    ADD(&registers.a, memory[registers.hl]);
}

void ADD_A_n(void) {
    ADD(&registers.a, get_immediate());
    pc++;
}

// ADC
void ADC(unsigned char *dest, unsigned short src) {
    ADD(dest, src + flags.c);
}

void ADC_A_A(void) {
    ADC(&registers.a, registers.a);
}

void ADC_A_B(void) {
    ADC(&registers.a, registers.b);
}

void ADC_A_C(void) {
    ADC(&registers.a, registers.c);
}

void ADC_A_D(void) {
    ADC(&registers.a, registers.d);
}

void ADC_A_E(void) {
    ADC(&registers.a, registers.e);
}

void ADC_A_H(void) {
    ADC(&registers.a, registers.h);
}

void ADC_A_L(void) {
    ADC(&registers.a, registers.l);
}

void ADC_A_HL(void) {
    ADC(&registers.a, memory[registers.hl]);
}

void ADC_A_n(void) {
    ADC(&registers.a, get_immediate());
    pc++;
}

// SUB
void SUB(unsigned char src, bool save_value) {
    flags.z = ((registers.a - src)&0xFF) == 0;
    flags.n = 1;
    flags.h = ((registers.a&0x0F) >= (src&0x0F));
    flags.c = ((registers.c&0xFF) >= (src&0xFF));

    if (save_value)
        registers.a -= src;

}

void SUB_A(void) {
    SUB(registers.a, true);
}

void SUB_B(void) {
    SUB(registers.b, true);
}

void SUB_C(void) {
    SUB(registers.c, true);
}

void SUB_D(void) {
    SUB(registers.d, true);
}

void SUB_E(void) {
    SUB(registers.e, true);
}

void SUB_H(void) {
    SUB(registers.h, true);
}

void SUB_L(void) {
    SUB(registers.l, true);
}

void SUB_HL(void) {
    SUB(memory[registers.hl], true);
}

void SUB_n(void) {
    SUB(get_immediate(), true);
    pc++;
}


// SBC
void SBC(unsigned char *dest, unsigned short src) {
    SUB(src + flags.c, true);
}

void SBC_A_A(void) {
    SBC(&registers.a, registers.a);
}

void SBC_A_B(void) {
    SBC(&registers.a, registers.b);
}

void SBC_A_C(void) {
    SBC(&registers.a, registers.c);
}

void SBC_A_D(void) {
    SBC(&registers.a, registers.d);
}

void SBC_A_E(void) {
    SBC(&registers.a, registers.e);
}

void SBC_A_H(void) {
    SBC(&registers.a, registers.h);
}

void SBC_A_L(void) {
    SBC(&registers.a, registers.l);
}

void SBC_A_HL(void) {
    SBC(&registers.a, memory[registers.hl]);
}

void SBC_A_n(void) {
    SBC(&registers.a, registers.a);
}

// AND
void AND(unsigned char src) {
    flags.z = ((registers.a & src)&0xFF) == 0;
    flags.n = 0;
    flags.h = 1;
    flags.c = 0;
    registers.a &= src;
}

void AND_A(void) {
    AND(registers.a);
}

void AND_B(void) {
    AND(registers.b);
}

void AND_C(void) {
    AND(registers.c);
}

void AND_D(void) {
    AND(registers.d);
}

void AND_E(void) {
    AND(registers.e);
}

void AND_H(void) {
    AND(registers.h);
}

void AND_L(void) {
    AND(registers.l);
}

void AND_HL(void) {
    AND(memory[registers.hl]);
}

void AND_n(void) {
    AND(get_immediate());
    pc++;
}


// OR
void OR(unsigned char src) {
    flags.z = ((registers.a | src)&0xFF) == 0;
    flags.n = 0;
    flags.h = 0;
    flags.c = 0;
    registers.a |= src;
}

void OR_A(void) {
    OR(registers.a);
}

void OR_B(void) {
    OR(registers.b);
}

void OR_C(void) {
    OR(registers.c);
}

void OR_D(void) {
    OR(registers.d);
}

void OR_E(void) {
    OR(registers.e);
}

void OR_H(void) {
    OR(registers.h);
}

void OR_L(void) {
    OR(registers.l);
}

void OR_HL(void) {
    OR(memory[registers.hl]);
}

void OR_n(void) {
    OR(get_immediate());
    pc++;
}


// XOR
void XOR(unsigned char src) {
    flags.z = ((registers.a ^ src)&0xFF) == 0;
    flags.n = 0;
    flags.h = 0;
    flags.c = 0;

    registers.a ^= src;
}

void XOR_A(void) {
    XOR(registers.a);
}

void XOR_B(void) {
    XOR(registers.b);
}

void XOR_C(void) {
    XOR(registers.c);
}

void XOR_D(void) {
    XOR(registers.d);
}

void XOR_E(void) {
    XOR(registers.e);
}

void XOR_H(void) {
    XOR(registers.h);
}

void XOR_L(void) {
    XOR(registers.l);
}

void XOR_HL(void) {
    XOR(memory[registers.hl]);
}

void XOR_n(void) {
    XOR(get_immediate());
    pc++;
}

void CP(unsigned char src) {
    SUB(src, false);
}

void CP_A(void) {
    CP(registers.a);
}

void CP_B(void) {
    CP(registers.b);
}

void CP_C(void) {
    CP(registers.c);
}

void CP_D(void) {
    CP(registers.d);
}

void CP_E(void) {
    CP(registers.e);
}

void CP_H(void) {
    CP(registers.h);
}

void CP_L(void) {
    CP(registers.l);
}

void CP_HL(void) {
    CP(memory[registers.hl]);
}

void CP_n(void) {
    CP(get_immediate());
    pc++;
}

void INC(unsigned char *dest) {
    flags.z = ((*dest + 1)&0xFF) == 0;
    flags.n = 0;
    flags.h = *dest == 0x0F;

    (*dest)++;
}

void INC_A(void) {
    INC(&registers.a);
}

void INC_B(void) {
    INC(&registers.b);
}

void INC_C(void) {
    INC(&registers.c);
}

void INC_D(void) {
    INC(&registers.d);
}

void INC_E(void) {
    INC(&registers.e);
}

void INC_H(void) {
    INC(&registers.h);
}

void INC_L(void) {
    INC(&registers.l);
}

void INC_HL(void) {
    INC(&memory[registers.hl]);
}

void DEC(unsigned char *dest) {
    flags.z = ((*dest - 1)&0xFF) == 0;
    flags.n = 1;
    flags.h = (*dest&0x0F) == 0;
}

void DEC_A(void) {
    DEC(&registers.a);
}

void DEC_B(void) {
    DEC(&registers.b);
}

void DEC_C(void) {
    DEC(&registers.c);
}

void DEC_D(void) {
    DEC(&registers.d);
}

void DEC_E(void) {
    DEC(&registers.e);
}

void DEC_H(void) {
    DEC(&registers.h);
}

void DEC_L(void) {
    DEC(&registers.l);
}

void DEC_HL(void) {
    DEC(&memory[registers.hl]);
}

// 16-bit arithmetic!
void ADD16(unsigned short *dest, unsigned short src) {
    flags.n = 0;
    flags.h = (((*dest)&0xFF) + (src&0xFF)) >= 0x0100;
    flags.c = (int)(*dest) + (int)src > 0xFFFF;
    *dest += src;
}

void ADD16_BC(void) {
    ADD16(&registers.hl, registers.bc);
}

void ADD16_DE(void) {
    ADD16(&registers.hl, registers.de);
}

void ADD16_HL(void) {
    ADD16(&registers.hl, registers.hl);
}

void ADD16_SP(void) {
    ADD16(&registers.hl, registers.sp);
}

void ADD16_SP_n(void) {
    flags.z = 0;
    ADD16(&registers.sp, get_word());
    pc += 2;
}

void INC16(unsigned short *dest) {
    (*dest)++;
}

void INC16_BC(void) {
    INC16(&registers.bc);
}

void INC16_DE(void) {
    INC16(&registers.de);
}

void INC16_HL(void) {
    INC16(&registers.hl);
}

void INC16_SP(void) {
    INC16(&registers.sp);
}

void DEC16(unsigned short *dest) {
    (*dest)--;
}

void DEC16_BC(void) {
    DEC16(&registers.bc);
}

void DEC16_DE(void) {
    DEC16(&registers.de);
}

void DEC16_HL(void) {
    DEC16(&registers.hl);
}

void DEC16_SP(void) {
    DEC16(&registers.sp);
}

// ----------------------
// Miscellaneous
void SWAP(unsigned char *target) {
    // I know there's a way to do this that doesn't inolve a temp, but I'm too lazy to look it up.
    unsigned char low_bits = (*target) & 0x0F;
    unsigned char high_bits = (*target) & 0xF0;
    (*target) = high_bits >> 1;
    (*target) |= low_bits << 1;
}

void SWAP_A(void) {
    SWAP(&registers.a);
}

void SWAP_B(void) {
    SWAP(&registers.b);
}

void SWAP_C(void) {
    SWAP(&registers.c);
}

void SWAP_D(void) {
    SWAP(&registers.d);
}

void SWAP_E(void) {
    SWAP(&registers.e);
}

void SWAP_H(void) {
    SWAP(&registers.h);
}

void SWAP_L(void) {
    SWAP(&registers.l);
}

void SWAP_HL(void) {
    SWAP(&memory[registers.hl]);
}

void DAA(void) {
    if (!flags.n) {
        if (flags.c || registers.a > 0x99) {
            registers.a += 0x60;
            flags.c = 1;
        }

        else {
            if (flags.c)
                registers.a -= 0x60;

            if (flags.h)
                registers.a -= 0x6;
        }
    }
}

void CPL(void) {
    registers.a = ~registers.a;
    flags.n = 1;
    flags.h = 1;
}

void CCF(void) {
    flags.c = !flags.c;
    flags.n = 0;
    flags.h = 0;
}

void SCF(void) {
    flags.c = true;
    flags.n = 0;
    flags.h = 0;
}


void NOP(void) {
    // TODO: Do nothing.
}

void HALT(void) {
    // TODO: Nothing?
}

void STOP(void) {
    // TODO: Definitely something. I'll figure this one out later.
}
void DI(void) {
    interrupts_enabled = false;
    // TODO: I'm sure this has real meaning somewhere.
}

void EI(void) {
    interrupts_enabled = true;
}

void RLCA(void) {
    flags.c = (registers.a & 0x80) != 0;
    registers.a <<= 1;
    registers.a |= flags.c;
    flags.z = registers.a == 0;
    flags.n = 0;
    flags.h = 0;
}

void RLA(void) {
    unsigned char temp = flags.c;
    flags.c = (registers.a & 0x80) != 0;
    registers.a <<= 1;
    registers.a |= temp;
    flags.z = registers.a == 0;
    flags.n = 0;
    flags.h = 0;
}

void RRCA(void) {
    flags.c = (registers.a & 0x01) != 0;
    registers.a >>= 1;
    registers.a |= flags.c << 7;
    flags.z = registers.a == 0;
    flags.n = 0;
    flags.h = 0;
}

void RRA(void) {
    unsigned char temp = flags.c;
    flags.c = (registers.a & 0x01) != 0;
    registers.a >>= 1;
    registers.a |= temp << 7;
    flags.z = registers.a == 0;
    flags.n = 0;
    flags.h = 0;
}

void RLC(unsigned char *target) {
    flags.c = ((*target) & 0x80) != 0;
    *target <<= 1;
    *target |= flags.c;
    flags.z = *target == 0;
    flags.n = 0;
    flags.h = 0;
}

void RLC_A(void) {
    RLC(&registers.a);
}

void RLC_B(void) {
    RLC(&registers.b);
}

void RLC_C(void) {
    RLC(&registers.c);
}

void RLC_D(void) {
    RLC(&registers.d);
}

void RLC_E(void) {
    RLC(&registers.e);
}

void RLC_H(void) {
    RLC(&registers.h);
}

void RLC_L(void) {
    RLC(&registers.l);
}

void RLC_HL(void) {
    RLC(&memory[registers.hl]);
}

void RL(unsigned char *target) {
    unsigned char temp = flags.c;
    flags.c = ((*target) & 0x80) != 0;
    (*target) <<= 1;
    (*target) |= temp;
    flags.z = (*target) == 0;
    flags.n = 0;
    flags.h = 0;
}

void RL_A(void) {
    RL(&registers.a);
}

void RL_B(void) {
    RL(&registers.b);
}

void RL_C(void) {
    RL(&registers.c);
}

void RL_D(void) {
    RL(&registers.d);
}

void RL_E(void) {
    RL(&registers.e);
}

void RL_H(void) {
    RL(&registers.h);
}

void RL_L(void) {
    RL(&registers.l);
}

void RL_HL(void) {
    RL(&memory[registers.hl]);
}

void RRC(unsigned char *target) {
    flags.c = ((*target) & 0x01) != 0;
    (*target) >>= 1;
    (*target) |= flags.c << 7;
    flags.z = (*target) == 0;
    flags.n = 0;
    flags.h = 0;
}

void RRC_A(void) {
    RRC(&registers.a);
}

void RRC_B(void) {
    RRC(&registers.b);
}

void RRC_C(void) {
    RRC(&registers.c);
}

void RRC_D(void) {
    RRC(&registers.d);
}

void RRC_E(void) {
    RRC(&registers.e);
}

void RRC_H(void) {
    RRC(&registers.h);
}

void RRC_L(void) {
    RRC(&registers.l);
}

void RRC_HL(void) {
    RRC(&memory[registers.hl]);
}

void RR(unsigned char *target) {
    unsigned char temp = flags.c;
    flags.c = ((*target) & 0x01) != 0;
    (*target) >>= 1;
    (*target) |= temp << 7;
    flags.z = (*target) == 0;
    flags.n = 0;
    flags.h = 0;
}

void RR_A(void) {
    RR(&registers.a);
}

void RR_B(void) {
    RR(&registers.b);
}

void RR_C(void) {
    RR(&registers.c);
}

void RR_D(void) {
    RR(&registers.d);
}

void RR_E(void) {
    RR(&registers.e);
}

void RR_H(void) {
    RR(&registers.h);
}

void RR_L(void) {
    RR(&registers.l);
}

void RR_HL(void) {
    RR(&memory[registers.hl]);
}

void SLA(unsigned char *target) {
    flags.c = ((*target) & 0x80) != 0;
    (*target) <<= 1;
    flags.z = (*target) == 0;
    flags.n = 0;
    flags.h = 0;
}

void SLA_A(void) {
    SLA(&registers.a);
}

void SLA_B(void) {
    SLA(&registers.b);
}

void SLA_C(void) {
    SLA(&registers.c);
}

void SLA_D(void) {
    SLA(&registers.d);
}

void SLA_E(void) {
    SLA(&registers.e);
}

void SLA_H(void) {
    SLA(&registers.h);
}

void SLA_L(void) {
    SLA(&registers.l);
}

void SLA_HL(void) {
    SLA(&memory[registers.hl]);
}

void SRA(unsigned char *target) {
    flags.c = ((*target) & 0x01) != 0;
    flags.z = (*target) == 0;
    flags.n = 0;
    flags.h = 0;
}

void SRA_A(void) {
    SRA(&registers.a);
}

void SRA_B(void) {
    SRA(&registers.b);
}

void SRA_C(void) {
    SRA(&registers.c);
}

void SRA_D(void) {
    SRA(&registers.d);
}

void SRA_E(void) {
    SRA(&registers.e);
}

void SRA_H(void) {
    SRA(&registers.h);
}

void SRA_L(void) {
    SRA(&registers.l);
}

void SRA_HL(void) {
    SRA(&memory[registers.hl]);
}

void SRL(unsigned char *target) {
    flags.c = ((*target) & 0x01) != 0;
    (*target) >>= 1;
    flags.z = (*target) == 0;
    flags.n = 0;
    flags.h = 0;
}

void SRL_A(void) {
    SRA(&registers.a);
}

void SRL_B(void) {
    SRA(&registers.b);
}

void SRL_C(void) {
    SRA(&registers.c);
}

void SRL_D(void) {
    SRA(&registers.d);
}

void SRL_E(void) {
    SRA(&registers.e);
}

void SRL_H(void) {
    SRA(&registers.h);
}

void SRL_L(void) {
    SRL(&registers.l);
}

void SRL_HL(void) {
    SRL(&memory[registers.hl]);
}

// --------------------
// Bit Opcodes
void BIT(unsigned char target, unsigned char bit) {
    flags.z = (target & (1 << bit)) == 0;
    flags.n = 0;
    flags.h = 1;
}

void BIT0_A(void) {
    BIT(registers.a, 0);
}

void BIT0_B(void) {
    BIT(registers.b, 0);
}

void BIT0_C(void) {
    BIT(registers.c, 0);
}

void BIT0_D(void) {
    BIT(registers.d, 0);
}

void BIT0_E(void) {
    BIT(registers.e, 0);
}

void BIT0_H(void) {
    BIT(registers.h, 0);
}

void BIT0_L(void) {
    BIT(registers.l, 0);
}

void BIT0_HL(void) {
    BIT(memory[registers.hl], 0);
}

void BIT1_A(void) {
    BIT(registers.a, 1);
}

void BIT1_B(void) {
    BIT(registers.b, 1);
}

void BIT1_C(void) {
    BIT(registers.c, 1);
}

void BIT1_D(void) {
    BIT(registers.d, 1);
}

void BIT1_E(void) {
    BIT(registers.e, 1);
}

void BIT1_H(void) {
    BIT(registers.h, 1);
}

void BIT1_L(void) {
    BIT(registers.l, 1);
}

void BIT1_HL(void) {
    BIT(memory[registers.hl], 1);
}

void BIT2_A(void) {
    BIT(registers.a, 2);
}

void BIT2_B(void) {
    BIT(registers.b, 2);
}

void BIT2_C(void) {
    BIT(registers.c, 2);
}

void BIT2_D(void) {
    BIT(registers.d, 2);
}

void BIT2_E(void) {
    BIT(registers.e, 2);
}

void BIT2_H(void) {
    BIT(registers.h, 2);
}

void BIT2_L(void) {
    BIT(registers.l, 2);
}

void BIT2_HL(void) {
    BIT(memory[registers.hl], 2);
}

void BIT3_A(void) {
    BIT(registers.a, 3);
}

void BIT3_B(void) {
    BIT(registers.b, 3);
}

void BIT3_C(void) {
    BIT(registers.c, 3);
}

void BIT3_D(void) {
    BIT(registers.d, 3);
}

void BIT3_E(void) {
    BIT(registers.e, 3);
}

void BIT3_H(void) {
    BIT(registers.h, 3);
}

void BIT3_L(void) {
    BIT(registers.l, 3);
}

void BIT3_HL(void) {
    BIT(memory[registers.hl], 3);
}

void BIT4_A(void) {
    BIT(registers.a, 4);
}

void BIT4_B(void) {
    BIT(registers.b, 4);
}

void BIT4_C(void) {
    BIT(registers.c, 4);
}

void BIT4_D(void) {
    BIT(registers.d, 4);
}

void BIT4_E(void) {
    BIT(registers.e, 4);
}

void BIT4_H(void) {
    BIT(registers.h, 4);
}

void BIT4_L(void) {
    BIT(registers.l, 4);
}

void BIT4_HL(void) {
    BIT(memory[registers.hl], 4);
}

void BIT5_A(void) {
    BIT(registers.a, 5);
}

void BIT5_B(void) {
    BIT(registers.b, 5);
}

void BIT5_C(void) {
    BIT(registers.c, 5);
}

void BIT5_D(void) {
    BIT(registers.d, 5);
}

void BIT5_E(void) {
    BIT(registers.e, 5);
}

void BIT5_H(void) {
    BIT(registers.h, 5);
}

void BIT5_L(void) {
    BIT(registers.l, 5);
}

void BIT5_HL(void) {
    BIT(memory[registers.hl], 5);
}

void BIT6_A(void) {
    BIT(registers.a, 6);
}

void BIT6_B(void) {
    BIT(registers.b, 6);
}

void BIT6_C(void) {
    BIT(registers.c, 6);
}

void BIT6_D(void) {
    BIT(registers.d, 6);
}

void BIT6_E(void) {
    BIT(registers.e, 6);
}

void BIT6_H(void) {
    BIT(registers.h, 6);
}

void BIT6_L(void) {
    BIT(registers.l, 6);
}

void BIT6_HL(void) {
    BIT(memory[registers.hl], 6);
}

void BIT7_A(void) {
    BIT(registers.a, 7);
}

void BIT7_B(void) {
    BIT(registers.b, 7);
}

void BIT7_C(void) {
    BIT(registers.c, 7);
}

void BIT7_D(void) {
    BIT(registers.d, 7);
}

void BIT7_E(void) {
    BIT(registers.e, 7);
}

void BIT7_H(void) {
    BIT(registers.h, 7);
}

void BIT7_L(void) {
    BIT(registers.l, 7);
}

void BIT7_HL(void) {
    BIT(memory[registers.hl], 7);
}

void SET(unsigned char *target, unsigned char bit) {
    *target |= 1 << bit;
}

void SET_A(void) {
    SET(&registers.a, get_immediate());
    pc++;
}

void SET_B(void) {
    SET(&registers.b, get_immediate());
    pc++;
}

void SET_C(void) {
    SET(&registers.c, get_immediate());
    pc++;
}

void SET_D(void) {
    SET(&registers.d, get_immediate());
    pc++;
}

void SET_E(void) {
    SET(&registers.e, get_immediate());
    pc++;
}

void SET_H(void) {
    SET(&registers.h, get_immediate());
    pc++;
}

void SET_L(void) {
    SET(&registers.l, get_immediate());
    pc++;
}

void SET_HL(void) {
    SET(&memory[registers.hl], get_immediate());
    pc++;
}

void RESET(unsigned char *target, unsigned char bit) {
    *target &= ~(1 << bit);
}

void RESET_A(void) {
    RESET(&registers.a, get_immediate());
    pc++;
}

void RESET_B(void) {
    RESET(&registers.b, get_immediate());
    pc++;
}

void RESET_C(void) {
    RESET(&registers.c, get_immediate());
    pc++;
}

void RESET_D(void) {
    RESET(&registers.d, get_immediate());
    pc++;
}

void RESET_E(void) {
    RESET(&registers.e, get_immediate());
    pc++;
}

void RESET_H(void) {
    RESET(&registers.h, get_immediate());
    pc++;
}

void RESET_L(void) {
    RESET(&registers.l, get_immediate());
    pc++;
}

void RESET_HL(void) {
    RESET(&memory[registers.hl], get_immediate());
    pc++;
}


// --------------
// Jumps !! Woohoo !!
void JP(void) {
    pc = get_word();
    pc += 2;
}

void JP_NZ(void) {
    if (flags.z != 0)
        JP();
}

void JP_Z(void) {
    if (flags.z == 0)
        JP();
}

void JP_NC(void) {
    if (flags.c != 0)
        JP();
}

void JP_C(void) {
    if (flags.c == 0)
        JP();
}

void JP_HL(void) {
    pc = registers.hl;
}

void JR(void) {
    printf("\nJumping\n\n");
    unsigned char next = get_immediate();
    if (next & 0x80) {
        pc = pc + next + 1 - 0x100;
    }

    else
        pc += next;
}

void JR_NZ(void) {
    if (flags.z != 0)
        JR();
    
    pc++;
}

void JR_Z(void) {
    if (flags.z == 0)
        JR();

    pc++;
}

void JR_NC(void) {
    if (flags.c != 0)
        JR();

    pc++;
}

void JR_C(void) {
    if (flags.c == 0)
        JR();

    pc++;
}

// ---------
// Calls
void CALL(void) {
    PUSH(((pc + 3) & 0xFF00) >> 2);
    PUSH((pc + 3) & 0xFF);
    JP();
}

void CALL_NZ(void) {
    if (flags.z != 0)
        CALL();
}

void CALL_Z(void) {
    if (flags.z == 0)
        CALL();
}

void CALL_NC(void) {
    if (flags.c != 0)
        CALL();
}

void CALL_C(void) {
    if (flags.c == 0)
        CALL();
}

void RST(unsigned char location) {
    PUSH((pc & 0xFF00) >> 2);
    PUSH(pc & 0xFF);
    pc = location;
}

void RST_00(void) {
    RST(0x00);
}

void RST_08(void) {
    RST(0x08);
}

void RST_10(void) {
    RST(0x10);
}

void RST_18(void) {
    RST(0x18);
}

void RST_20(void) {
    RST(0x20);
}

void RST_28(void) {
    RST(0x28);
}

void RST_30(void) {
    RST(0x30);
}

void RST_38(void) {
    RST(0x38);
}


// ----------------
// Returns
// A fitting way to end this monstrosity of a file
void RET(void) {
    unsigned char pc_l, pc_h;
    POP(&pc_l);
    POP(&pc_h);
    pc = pc_l + (pc_h << 8);
}
void RET_NZ(void) {
    if (flags.z != 0) {
        RET();
    }
}

void RET_Z(void) {
    if (flags.z == 0) {
        RET();
    }
}

void RET_NC(void) {
    if (flags.c != 0) {
        RET();
    }
}

void RET_C(void) {
    if (flags.c == 0) {
        RET();
    }
}

void RETI(void) {
    RET();
    EI();
}
