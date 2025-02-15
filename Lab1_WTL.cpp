﻿// Lab1_WTL.cpp : Определяет точку входа для приложения.
//

#include <atlbase.h>
#include <atlapp.h>
extern CAppModule _Module;
#include <atlwin.h>
#include <atlgdi.h>
#include <atlmisc.h>
#include <atlctrls.h>
#include <atlctrlw.h>
#include <atlctrlx.h>
#include <atldlgs.h>
#include "Resource.h"
CAppModule _Module;


class CMainWindow : public CWindowImpl<CMainWindow, CWindow, CFrameWinTraits>
{
public:
    BEGIN_MSG_MAP(CMainWindow)
        MESSAGE_HANDLER(WM_CREATE, OnInit)
        MESSAGE_HANDLER(WM_PAINT, OnPaint)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
        MESSAGE_HANDLER(WM_COMMAND,OnCommand)
    END_MSG_MAP()
    LRESULT OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        switch (wParam)
        {
        case IDM_EXIT:
            DestroyWindow();
            return 0;
        case ID_SEARCH:
            OnSearch(uMsg, wParam, lParam, bHandled);
            return 0;
        case ID_About:
            dialog.DoModal();
            return 0;
        }
        return 0;
    }
    LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        CPaintDC dc(m_hWnd);
        CRect rect;
        GetClientRect(rect);
        dc.DrawTextW(TEXT("Приветствую в моем маленьком проводнике, искатель)"), -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        return 0;
    }
    LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        PostQuitMessage(0);
        return 0;
    }
    LRESULT OnInit(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        myMenu.LoadMenuW(IDC_LAB1WTL);
        SetMenu(myMenu);
        return 0;
    }
    LRESULT OnSearch(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        CFileDialog file(TRUE,NULL, TEXT("Выберите файл"), NULL, TEXT("File png (*.png)|*.png|\0\0Text Files (*.txt)|*.txt|"),this->m_hWnd);	//объект класса выбора файла
        int result = file.DoModal();	//запустить диалоговое окно
        if (result == IDOK)	//если файл выбран
        {
                
        }
        return 0;
    }
private:
    CMenu myMenu;
    CSimpleDialog<IDD_ABOUTBOX> dialog;
};




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
    _Module.Init(0, hInstance, 0);

    CMainWindow wnd;
    wnd.Create(NULL, CWindow::rcDefault, TEXT("Hello, Wtl!"));
    wnd.ShowWindow(SW_SHOW);
    CMessageLoop loop;
    int res = loop.Run();
    _Module.Term();
    return res;
}

