#ifndef __GLOBALAUTO_H
#define __GLOBALAUTO_H


void    LoadSymbols() ;
void    ReleaseSymbols() ;


void GetDir_DrfnRoot(CString &strRet);

void	CopyString(char *pDest, int nDest, const char *pSrc);
CString	GetString(char *p, int n);
long	GetLong(char *p, int n);
void	SetLong(char *pDest, int nDest, int nVal);
void	TraceLog(LPCTSTR szMsg, ...);
long	GetArgs(CString strString, CStringArray &arrStr, TCHAR chDel);
int   GetMarketType(CString strCode) ;
//
//BOOL	IsStkCode(CString strCode);
//BOOL	IsELWCode(CString strCode);
//BOOL	IsSFOCode(CString strCode);
//BOOL	IsFutCode(CString strCode);
//BOOL	IsOptCode(CString strCode);
//BOOL	IsIndexCode(CString strCode);
//BOOL	IsDerivativesCode(CString strCode);
//BOOL	IsEquitiesCode(CString strCode);
//BOOL	IsETFCode(CString strCode);

void TRACEP(CString strCode, CString sMessage);
void InsertComma(CString & str1);

//CString GetIndexCodeName(CString strCode);
//CString GetEquitiesCodeName(CString strCode);
//CString GetDerivativesCodeName(CString strCode);

BOOL IsSame(double d1, double d2);
BOOL IsGreater(double d1, double d2);
BOOL IsLess(double d1, double d2);

void DefMessageBox(HWND hWnd, CString strMsg, CString strCaption = STR_CAPTION);


#endif