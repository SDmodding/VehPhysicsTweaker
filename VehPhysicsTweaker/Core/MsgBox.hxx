#pragma once

class CMsgBox
{
public:
    static void Show(const char* p_Caption, const char* p_Text, DWORD p_Style, LPCSTR p_Icon)
	{
        MSGBOXPARAMS m_MsgBox = { 0 };
        {
            m_MsgBox.cbSize = sizeof(MSGBOXPARAMS);
            m_MsgBox.hwndOwner = 0;
            m_MsgBox.hInstance = 0;
            m_MsgBox.lpszText = p_Text;
            m_MsgBox.lpszCaption = p_Caption;
            m_MsgBox.dwStyle = (p_Style | MB_SETFOREGROUND);
            m_MsgBox.lpszIcon = p_Icon;
            if (p_Icon)
                m_MsgBox.dwStyle |= MB_USERICON;
        }
        MessageBoxIndirectA(&m_MsgBox);
	}

    static void ShowInfo(const char* p_Format, ...)
    {
        char m_Buffer[1024];
        {
            va_list m_Args;
            va_start(m_Args, p_Format);
            vsnprintf(m_Buffer, sizeof(m_Buffer), p_Format, m_Args);
            va_end(m_Args);
        }
        Show(PROJECT_NAME, m_Buffer, MB_OK, IDI_INFORMATION);
    } 
    
    static void ShowError(const char* p_Format, ...)
    {
        char m_Buffer[1024];
        {
            va_list m_Args;
            va_start(m_Args, p_Format);
            vsnprintf(m_Buffer, sizeof(m_Buffer), p_Format, m_Args);
            va_end(m_Args);
        }
        Show(PROJECT_NAME, m_Buffer, MB_OK, IDI_ERROR);
    }
};