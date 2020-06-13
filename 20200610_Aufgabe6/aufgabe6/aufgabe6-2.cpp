#include <windows.h>
#include <wchar.h>
#include <string>
#include <strsafe.h>
#define ID_TIMER 1

std::string arabic_to_roman( int number ) ;
LRESULT CALLBACK WndProc (HWND , UINT , WPARAM , LPARAM ) ;

int WINAPI WinMain( HINSTANCE hInstance, 
                    HINSTANCE hPrevInstance,
                    LPSTR d3,
	                  int nCmdShow ) {
	static TCHAR szAppName[ ] = TEXT ( "RomanClock" ) ;
  HWND hwnd ;
  MSG msg ;
  WNDCLASS wndclass ;
  wndclass.style = CS_HREDRAW | CS_VREDRAW ;
  wndclass.lpfnWndProc = WndProc ;
  wndclass.cbClsExtra = 0 ;
  wndclass.cbWndExtra = 0 ;
  wndclass.hInstance = hInstance ;
  wndclass.hIcon = LoadIcon ( NULL , IDI_APPLICATION ) ;
  wndclass.hCursor = LoadCursor ( NULL , IDC_ARROW ) ;
  wndclass.hbrBackground = ( HBRUSH ) GetStockObject ( WHITE_BRUSH ) ;
  wndclass.lpszMenuName = NULL ;
  wndclass.lpszClassName = szAppName ;
	if ( !RegisterClass( &wndclass ) )  return 0 ; 

	hwnd = CreateWindow ( szAppName, // window class name
                          TEXT ("RomanClock"), // window caption
                          WS_OVERLAPPEDWINDOW, // window style
													CW_USEDEFAULT, // initial x position
													CW_USEDEFAULT, // initial y position
													CW_USEDEFAULT, // initial x size
													CW_USEDEFAULT, // initial y size
													NULL, // parent window handle
													NULL, // window menu handle
													hInstance, // program instance handle
													NULL) ; // creation parameters

  ShowWindow (hwnd , nCmdShow ) ;
  UpdateWindow ( hwnd ) ;
  while( GetMessage( &msg , NULL , 0 , 0 ) ) {
    TranslateMessage ( &msg ) ;
    DispatchMessage ( &msg ) ;
    }
  return msg.wParam ;
  }

LRESULT CALLBACK WndProc ( HWND hwnd , 
	                         UINT message , 
	                         WPARAM wParam ,
	                         LPARAM lParam ) {
  static BOOL f24Hour, fSuppress ;
  static HBRUSH hBrush ;
	HFONT hFont ;
	static BOOL fFlipFlop = FALSE ;
  static int cxClient, cyClient ;
	RECT clientRect ;
  HDC hdc ;
	PAINTSTRUCT paintStruct ;
	TCHAR szBuffer [2] ;
  SYSTEMTIME lt ;
	int hour , minute , second ;
	LPSTR time_lpstr ;
	std::string hour_str , minute_str , second_str  , time_str ;
  switch ( message ) {
    case WM_CREATE:
      SetTimer ( hwnd , ID_TIMER , 1000 , NULL ) ;

		case WM_SETTINGCHANGE :
      GetLocaleInfo ( LOCALE_USER_DEFAULT , LOCALE_ITIME , szBuffer , 2 ) ;
			f24Hour = ( szBuffer[0] == '1' ) ;
      GetLocaleInfo ( LOCALE_USER_DEFAULT , LOCALE_ITLZERO , szBuffer , 2 ) ;
      fSuppress = ( szBuffer[ 0 ] == '0' ) ;
      InvalidateRect ( hwnd , NULL , TRUE ) ;
      return 0 ;

    case WM_SIZE :
      cxClient = LOWORD ( lParam ) ;
      cyClient = HIWORD ( lParam ) ;
      return 0 ;

    case WM_TIMER :
		GetLocalTime (&lt) ;
    InvalidateRect ( hwnd , NULL , TRUE ) ;
		fFlipFlop = !fFlipFlop ;
    return 0 ;

    case WM_PAINT:
			hdc = BeginPaint (hwnd, &paintStruct) ;
			GetClientRect (hwnd, &clientRect) ;
			hBrush = CreateSolidBrush (fFlipFlop ? RGB( 230 , 0 , 180 ) : RGB( 0, 250 , 30 ) ) ;
			SetTextColor (hdc, RGB( 255 , 255 , 0 ) ) ;
			SetBkMode (hdc, TRANSPARENT) ;
			hFont = CreateFont (200, 0, 0, 0, FW_ULTRABOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
			SelectObject( hdc , hFont ) ;


			GetLocalTime (&lt) ;
			hour = lt.wHour ;
			minute = lt.wMinute ;
			second = lt.wSecond ;
			hour_str = ( hour == 0 ? "0" :  arabic_to_roman( hour ) ) ;
			minute_str = ( minute == 0 ? "0" : arabic_to_roman( minute ) ) ;
			second_str = ( second == 0 ? "0" : arabic_to_roman( second ) ) ;
			time_str = ( hour_str + ":" + minute_str + ":" + second_str ) ;
			time_lpstr = const_cast<char *>(time_str.c_str( ) ) ;
			FillRect (hdc, &clientRect, hBrush) ;
			DrawTextA( hdc , time_lpstr , -1 , &clientRect , DT_CENTER | DT_VCENTER | DT_SINGLELINE ) ;
			EndPaint (hwnd, &paintStruct) ;
			DeleteObject (hBrush) ;
			DeleteObject (hFont) ;
			return 0 ;

    case WM_DESTROY :
      KillTimer ( hwnd , ID_TIMER) ;
      DeleteObject ( hBrush ) ;
      PostQuitMessage ( 0 ) ;
      return 0 ;
    }
  return DefWindowProc ( hwnd , message, wParam, lParam) ;
  }

std::string arabic_to_roman( int number ) {
	std::string converted_num ;
  std::string rom[ 13 ] = { "I" , "IV" , "V" , "IX" , "X" , "XL" , "L" , "XC" , "C" , "CD" , "D" , "CM" , "M"} ;
  int ara[ 13 ] = { 1 , 4 , 5 , 9 , 10 , 40 , 50 , 90 , 100 , 400 , 500 , 900 , 1000 } ;
  int c = 12 ;
  while (number > 0) {
		if ( ara[ c ] <= number ) {
			converted_num += rom[ c ] ;
      number -= ara[ c ] ;
      }
		else {
     c-- ;
     }
    }
	return converted_num ;
	}