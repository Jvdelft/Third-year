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
char * append(char * string1, char * string2)
{
    char * result = NULL;
    asprintf(&result, "%s%s", string1, string2);
    return result;
}
/// ET CA FAIT BIM BAM BOUM CA FAIT PSCHIT ET CA FAIT VROUM
void MakeLongLight()
{
    D1_Write(1);
    D2_Write(1);
    D3_Write(1);
    D4_Write(1);
    CyDelay(250);
    D1_Write(0);
    D1_Write(0);
    D1_Write(0);
    D1_Write(0);
    CyDelay(250);
}

void MakeShortLight()
{
    D1_Write(1);
    D2_Write(1);
    D3_Write(1);
    D4_Write(1);
    CyDelay(500);
    D1_Write(0);
    D1_Write(0);
    D1_Write(0);
    D1_Write(0);
    CyDelay(250);
}

void LCDPrint(char* string)
{
    LCD_Char_1_Position(0,0);
    LCD_Char_1_PrintString(string);
}
void Send(char* string)
{
    int i;
    if(string == "SOS"){
        LCDPrint("SOS");
        for(i=1;i<3;i++){
            MakeShortLight();
        }
        CyDelay(500);
        for(i=1;i<3;i++){
            MakeLongLight();
        }
        CyDelay(500);
        for(i=1;i<3;i++){
            MakeShortLight();
        }
        CyDelay(500);
    }
    else if(string == "BEAMS"){
        LCDPrint("BEAMS");
        MakeLongLight();
        for(i=1;i<3;i++){
            MakeShortLight();
        }
        CyDelay(500);
        MakeShortLight();
        CyDelay(500);
        MakeShortLight();
        MakeLongLight();
        CyDelay(500);
        MakeLongLight();
        MakeLongLight();
        CyDelay(500);
        for(i=1;i<3;i++){
            MakeShortLight();
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
        if(string == "1*"){
            Send("SOS");
        }
        else if(string == "2*"){
            Send("BEAMS");
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
    {   
        if(keypadScan() != "z"){
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
            CyDelay(20);
            
        }
        else if(Switch_2_Read()){
            MakeShortLight();
        }
        else if(Switch_3_Read()){
            MakeLongLight();
        }
        D1_Write(0);
        D2_Write(0);
        D3_Write(0);
        D4_Write(0);
    }
}

/* [] END OF FILE */
