#include <windows.h>
#include <tchar.h>
void DrawHello( HWND hwnd ) {
	HDC hDC ;
	PAINTSTRUCT paintStruct ;
	RECT clientRect ;
	hDC = BeginPaint( hwnd , &paintStruct ) ;
	if ( hDC != NULL ) {
		GetClientRect( hwnd , &clientRect ) ;
		DPtoLP( hDC , ( LPPOINT ) &clientRect , 2 ) ;
		DrawTextA( hDC , "helloworld" , -1 , &clientRect , DT_CENTER | DT_VCENTER | DT_SINGLELINE ) ;
		EndPaint( hwnd , &paintStruct ) ;
		}
	}
LRESULT CALLBACK WndProc( HWND hwnd , UINT uMsg , WPARAM wParam , LPARAM lParam ) {
	switch( uMsg ) {
		case WM_PAINT :
		DrawHello( hwnd ) ;
		break ;
		case WM_DESTROY :
		PostQuitMessage( 0 ) ;
		break ;
		default :
		return DefWindowProc( hwnd , uMsg , wParam , lParam ) ;
		}
	return 0;
	}
int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR d3 , int nCmdShow ) {
	MSG msg ;
	HWND hwnd ;
	WNDCLASS wndClass ;
	const wchar_t* szMainWndClass = L"WinTestWin" ; //Name of main window class
	memset( &wndClass , 0 , sizeof( wndClass ) ) ; 
	wndClass.style = CS_HREDRAW | CS_VREDRAW ;
	wndClass.lpfnWndProc = WndProc ;
	wndClass.hInstance = hInstance ;
	wndClass.hCursor = LoadCursor( NULL , IDC_ARROW ) ;
	wndClass.hbrBackground = ( HBRUSH ) ( COLOR_WINDOW + 1 ) ;
	wndClass.lpszClassName = szMainWndClass ;
	wndClass.lpszMenuName = NULL ;
	if ( !RegisterClass( &wndClass ) ) return FALSE ;

	hwnd = CreateWindow( szMainWndClass , L"HELLO" ,	WS_OVERLAPPEDWINDOW ,
		CW_USEDEFAULT , 0 , CW_USEDEFAULT , 0 , NULL , NULL , hInstance , NULL ) ;
	ShowWindow( hwnd , nCmdShow ) ;
	UpdateWindow( hwnd ) ;
	while ( GetMessage( &msg , NULL , 0 , 0 ) )
		DispatchMessage( &msg ) ;
		return msg.wParam ;
		}