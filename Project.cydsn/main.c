/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "keypad.h"
#include "project.h"
typedef enum { false, true } bool;

const int A[3] = {1,2,0};
const int B[5] = {2,1,1,1,0};
const int C[5] = {2,1,2,1,0};
const int D[4] = {2,1,1,0};
const int E[2] = {1,0};
const int F[5] = {1,1,2,1,0};
const int G[4] = {2,2,1,0};
const int H[5] = {1,1,1,1,0};
const int I[3] = {1,1,0};
const int J[5] = {1,2,2,2,0};
const int K[4] = {2,1,2,0};
const int L[5] = {1,2,1,1,0};
const int M[3] = {2,2,0};
const int N[3] = {2,1,0};
const int O[4] = {2,2,2,0};
const int P[5] = {1,2,2,1,0};
const int Q[5] = {2,2,1,2,0};
const int R[4] = {1,2,1,0};
const int S[4] = {1,1,1,0};
const int T[2] = {2,0};
const int U[4] = {1,1,2,0};
const int V[5] = {1,1,1,2,0};
const int W[4] = {1,2,2,0};
const int X[5] = {2,1,1,2,0};
const int Y[5] = {2,1,2,2,0};
const int Z[5] = {2,2,1,1,0};

const int morse_0[6] = {2,2,2,2,2,0};
const int morse_1[6] = {1,2,2,2,2,0};
const int morse_2[6] = {1,1,2,2,2,0};
const int morse_3[6] = {1,1,1,2,2,0};
const int morse_4[6] = {1,1,1,1,2,0};
const int morse_5[6] = {1,1,1,1,1,0};
const int morse_6[6] = {2,1,1,1,1,0};
const int morse_7[6] = {2,2,1,1,1,0};
const int morse_8[6] = {2,2,2,1,1,0};
const int morse_9[6] = {2,2,2,2,1,0};

/// ET CA FAIT BIM BAM BOUM CA FAIT PSCHIT ET CA FAIT VROUM
void MakeLongLight()
{
    D1_Write(1);
    D2_Write(1);
    D3_Write(1);
    D4_Write(1);
    CyDelay(500);
    D1_Write(0);
    D2_Write(0);
    D3_Write(0);
    D4_Write(0);
    CyDelay(250);
}
/// Chip coup
void MakeShortLight()
{
    D1_Write(1);
    D2_Write(1);
    D3_Write(1);
    D4_Write(1);
    CyDelay(250);
    D1_Write(0);
    D2_Write(0);
    D3_Write(0);
    D4_Write(0);
    CyDelay(250);
}
const int* Translate_to_morse(char c){
    
    if(c == 'a' || c=='A'){
        return(A);
    }
    else if(c == 'b' || c=='B'){
        return(B);
    }
    else if(c == 'c' || c=='C'){
        return(C);
    }
    else if(c == 'd' || c=='D'){
        return(D);
    }
    else if(c == 'e' || c=='E'){
        return(E);
    }
    else if(c == 'f' || c=='F'){
        return(F);
    }
    else if(c == 'g' || c=='G'){
        return(G);
    }
    else if(c == 'h' || c=='H'){
        return(H);
    }
    else if(c == 'i' || c=='I'){
        return(I);
    }
    else if(c == 'j' || c=='J'){
        return(J);
    }
    else if(c == 'k' || c=='K'){
        return(K);
    }
    else if(c == 'l' || c=='L'){
        return(L);
    }
    else if(c == 'm' || c=='M'){
        return(M);
    }
    else if(c == 'n' || c=='N'){
        return(N);
    }
    else if(c == 'o' || c=='O'){
        return(O);
    }
    else if(c == 'p' || c=='P'){
        return(P);
    }
    else if(c == 'q' || c=='Q'){
        return(Q);
    }
    else if(c == 'r' || c=='R'){
        return(R);
    }
    else if(c == 's' || c=='S'){
        return(S);
    }
    else if(c == 't' || c=='T'){
        return(T);
    }
    else if(c == 'u' || c=='U'){
        return(U);
    }
    else if(c == 'v' || c=='V'){
        return(V);
    }
    else if(c == 'w' || c=='W'){
        return(W);
    }
    else if(c == 'x' || c=='X'){
        return(X);
    }
    else if(c == 'y' || c=='Y'){
        return(Y);
    }
    else if(c == 'z' || c=='Z'){
        return(Z);
    }
    else{
        return(NULL);
    }
    
}
void LCDPrint(char* string)
{
    int n = strlen(string);
    LCD_Char_1_Position(0,0);
    if(strlen(string) > 8){
        int i;
        char ToWriteFirst[] = "";
        for(i=0;i<8;i++){
            strcat(ToWriteFirst,&string[i]);
        }
        LCD_Char_1_PrintString(ToWriteFirst);
        char ToWriteSecond[] = "";
        LCD_Char_1_Position(1,0);
        for(i=8;i<n;i++){
            strcat(ToWriteSecond,&string[i]);
        }
        LCD_Char_1_PrintString(ToWriteSecond);
    }
    else{
        LCD_Char_1_PrintString(string);
    }
}

void Send_to_leds(char* string){
    LCDPrint(string);
    int n = strlen(string);
    for(int i = 0; i<n ;i++){
        int j = 0;
        while(Translate_to_morse(string[i])[j] != 0){
            if(Translate_to_morse(string[i])[j] == 1){
                MakeShortLight();
            }
            else if(Translate_to_morse(string[i])[j] == 2){
                MakeLongLight();
            }
            j++;
        }
        CyDelay(500);
    }  
    LCD_Char_1_ClearDisplay();
}

bool Send_SOS_message(char* string)
{
    if(strlen(string) == 1){
        return false;
    }
    else if(strlen(string) == 2){
        if (strcmp(string,"1*")){
            Send_to_leds("SOS");
        }
        else if(strcmp(string,"2*")){
            Send_to_leds("BEAMS");
        }
        return true;
    }
    return false;
}

int main(void)
{   
    CyGlobalIntEnable; /* Enable global interrupts. */
    LCD_Char_1_Start();
    char signal[] = "";
    keypadInit();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {   LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintString("hello");
        if (!(strcmp(keypadScan(),"z"))){
            strcat(signal,keypadScan());
        }
        if(Send_SOS_message(signal) == true){
            *signal = '\0';
        }
        if(Switch_1_Read()){
            D1_Write(1);
            D2_Write(1);
            D3_Write(1);
            D4_Write(1);

        }
        else if(Switch_2_Read()){
            MakeShortLight();
        }
        else if(Switch_3_Read()){
            MakeLongLight();
        }
        else {D1_Write(0);
        D2_Write(0);
        D3_Write(0);
        D4_Write(0);
        }
    }
}

/* [] END OF FILE */
