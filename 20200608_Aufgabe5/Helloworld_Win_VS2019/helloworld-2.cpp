#include <windows.h>
int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE d2 , LPSTR d3 , int d4 ) {
MSG msg ;
HWND hwnd ;
hwnd = CreateWindowA("BUTTON", "Hello, World!", WS_VISIBLE | BS_CENTER, 100 , 100 , 100 , 80 , NULL , NULL , hInstance , NULL ) ;
while (GetMessage( &msg , NULL , 0 , 0 ) ) {
	if ( msg.message == WM_LBUTTONUP ) {
		DestroyWindow( hwnd ) ;
		PostQuitMessage( 0 ) ;
		}
	DispatchMessage( &msg ) ;
	}
return msg.wParam ;
}
