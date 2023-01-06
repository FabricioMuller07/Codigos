#include<windows.h>
#include "ConsolaFuente.h"

typedef struct _CONSOLE_FONT_INFOEX
{
	ULONG cbSize;
	DWORD nFont;
	COORD dwFontSize;
	UINT  FontFamily;
	UINT  FontWeight;
	WCHAR FaceName[LF_FACESIZE];
}CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;
#ifdef __cplusplus
extern "C" {
#endif
	BOOL WINAPI SetCurrentConsoleFontEx(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx);
#ifdef __cplusplus
}
#endif
void CambiarFuente(HANDLE &hConsole, int newWidth, int newHeight){
	CONSOLE_FONT_INFOEX fontStructure={0};
	fontStructure.cbSize=sizeof(fontStructure);
	fontStructure.dwFontSize.X=newWidth;
	fontStructure.dwFontSize.Y=newHeight;
	SetCurrentConsoleFontEx(hConsole, true, &fontStructure);
}
