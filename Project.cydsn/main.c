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

char * append(char * string1, char * string2)
{
    char * result = NULL;
    asprintf(&result, "%s%s", string1, string2);
    return result;
}

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
    
    if(c == 'a'){
        return(A);
    }
    else if(c == 'b'){
        return(B);
    }
    else if(c == 'c'){
        return(C);
    }
    else if(c == 'd'){
        return(D);
    }
    else if(c == 'e'){
        return(E);
    }
    else if(c == 'f'){
        return(F);
    }
    else if(c == 'g'){
        return(G);
    }
    else if(c == 'h'){
        return(H);
    }
    else if(c == 'i'){
        return(I);
    }
    else if(c == 'j'){
        return(J);
    }
    else if(c == 'k'){
        return(K);
    }
    else if(c == 'l'){
        return(L);
    }
    else if(c == 'm'){
        return(M);
    }
    else if(c == 'n'){
        return(N);
    }
    else if(c == 'o'){
        return(O);
    }
    else if(c == 'p'){
        return(P);
    }
    else if(c == 'q'){
        return(Q);
    }
    else if(c == 'r'){
        return(R);
    }
    else if(c == 's'){
        return(S);
    }
    else if(c == 't'){
        return(T);
    }
    else if(c == 'u'){
        return(U);
    }
    else if(c == 'v'){
        return(V);
    }
    else if(c == 'w'){
        return(W);
    }
    else if(c == 'x'){
        return(X);
    }
    else if(c == 'y'){
        return(Y);
    }
    else if(c == 'z'){
        return(Z);
    }
    else{
        return(NULL);
    }
    
}
void LCDPrint(char* string)
{
    LCD_Char_1_Position(0,0);
    LCD_Char_1_PrintString(string);
}

const int* Translate_to_morse(char c){
    
    if(c == 'a'){
        return(A);
    }
    else if(c == 'b'){
        return(B);
    }
    else if(c == 'c'){
        return(C);
    }
    else if(c == 'd'){
        return(D);
    }
    else if(c == 'e'){
        return(E);
    }
    else if(c == 'f'){
        return(F);
    }
    else if(c == 'g'){
        return(G);
    }
    else if(c == 'h'){
        return(H);
    }
    else if(c == 'i'){
        return(I);
    }
    else if(c == 'j'){
        return(J);
    }
    else if(c == 'k'){
        return(K);
    }
    else if(c == 'l'){
        return(L);
    }
    else if(c == 'm'){
        return(M);
    }
    else if(c == 'n'){
        return(N);
    }
    else if(c == 'o'){
        return(O);
    }
    else if(c == 'p'){
        return(P);
    }
    else if(c == 'q'){
        return(Q);
    }
    else if(c == 'r'){
        return(R);
    }
    else if(c == 's'){
        return(S);
    }
    else if(c == 't'){
        return(T);
    }
    else if(c == 'u'){
        return(U);
    }
    else if(c == 'v'){
        return(V);
    }
    else if(c == 'w'){
        return(W);
    }
    else if(c == 'x'){
        return(X);
    }
    else if(c == 'y'){
        return(Y);
    }
    else if(c == 'z'){
        return(Z);
    }
    else{
        return(NULL);
    }
    
}

 


void Send_to_leds(char* string){
    LCDPrint(string);
    int n = strlen(string);
    for(int i = 0; i<n ;n++){
        int j = 0;
        while(Translate_to_morse(string[i])[j] != 0){
            if(Translate_to_morse(string[i])[j] == 1){
                MakeShortLight();
            }
            else if(Translate_to_morse(string[i])[j] == 2){
                MakeLongLight();
            }
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
            append(signal,keypadScan());
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
