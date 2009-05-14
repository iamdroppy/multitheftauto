/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        core/CSettings.h
*  PURPOSE:     Header file for in-game settings window class
*  DEVELOPERS:  Cecill Etheredge <ijsf@gmx.net>
*               Christian Myhre Lundheim <>
*               Ed Lyons <eai@opencoding.net>
*               Jax <>
*               Stanislav Bobrov <lil_toady@hotmail.com>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

class CSettings;

#ifndef __CSETTINGS_H
#define __CSETTINGS_H

#include "CMainMenu.h"

struct SKeyBindSection
{
    SKeyBindSection ( char * szTitle )
    {
        this->currentIndex = 0;
        this->szTitle = new char [ strlen ( szTitle ) + 1 ];
        this->szOriginalTitle = new char [ strlen ( szTitle ) + 1 ];
        // convert to upper case
        for ( unsigned int i = 0; i < strlen(szTitle); i++ )
        {
            if ( isalpha(szTitle[i]) )
                this->szTitle[i] = toupper(szTitle[i]);
            else
                this->szTitle[i] = szTitle[i];
        }

        this->szTitle[strlen(szTitle)] = '\0';

        strcpy ( szOriginalTitle, szTitle );

        this->rowCount = 0;

        headerItem = NULL;
    }

    ~SKeyBindSection ( )
    {
        if ( this->szTitle )
            delete[] this->szTitle;

        if ( szOriginalTitle )
            delete[] szOriginalTitle;
    }
    int currentIndex; // temporarily stores the index while the list is being created
    char* szTitle;
    char* szOriginalTitle;
    int rowCount;
    class CGUIListItem * headerItem;
};


class CSettings
{
	friend class CCore;

    public:
                        CSettings               ( void );
                        ~CSettings              ( void );

	bool			    ProcessMessage			( UINT uMsg, WPARAM wParam, LPARAM lParam );

    void                Update					( void );
	void			    Initialize				( void );

    void                SetVisible              ( bool bVisible );
    bool                IsVisible               ( void );

    void                LoadData                ( void );

    inline bool         IsCapturingKey          ( void )            { return m_bCaptureKey; }
    void                UpdateCaptureAxis       ();
    void                UpdateJoypadTab         ();

    void                AddKeyBindSection       ( char * szSectionName );
    void                RemoveKeyBindSection    ( char * szSectionName );
    void                RemoveAllKeyBindSections ( void );

    static void         OnLoginCallback         ( bool bResult, char* szError, void* obj );
    void                OnLoginStateChange      ( bool bResult );

protected:
    const static int    SecKeyNum = 3;     // Number of secondary keys

	// Keep these protected so we can access them in the event handlers of CClientGame
    CGUIWindow*         m_pWindow;
	CGUITabPanel*	    m_pTabs;
    CGUIButton*         m_pButtonOK;
	CGUIButton*		    m_pButtonCancel;
    CGUILabel*          m_pLabelNick;
    CGUIEdit*           m_pEditNick;
    CGUILabel*          m_pLabelConnection;
    CGUIComboBox*       m_pComboConnection;
	CGUICheckBox*	    m_pSavePasswords;

    CGUILabel*		    m_pVideoGeneralLabel;
    CGUILabel*		    m_pVideoResolutionLabel;
    CGUIComboBox*       m_pComboResolution;
    CGUICheckBox*       m_pCheckBoxWindowed;
    CGUICheckBox*       m_pCheckBoxWideScreen;
	CGUILabel*		    m_pVideoRenderingLabel;
	CGUICheckBox*	    m_pCheckBoxMenuDynamic;
	CGUICheckBox*	    m_pCheckBoxMenuVideo;
	CGUICheckBox*	    m_pCheckBoxMenuPostEffects;
	
    CGUILabel*          m_pLabelRadioVolume;
    CGUILabel*          m_pLabelSFXVolume;
    CGUILabel*          m_pLabelMTAVolume;
    CGUIProgressBar*    m_pAudioRadioVolume;
    CGUIProgressBar*    m_pAudioSFXVolume;
    CGUIProgressBar*    m_pAudioMTAVolume;

	CGUIGridList*	    m_pBindsList;
	CGUIButton*		    m_pBindsDefButton;
	CGUIHandle		    m_hBind, m_hPriKey, m_hSecKeys[SecKeyNum];

    CGUILabel*                  m_pJoypadName;
    CGUILabel*                  m_pJoypadUnderline;
    CGUIEdit*                   m_pEditDeadzone;
    CGUIEdit*                   m_pEditSaturation;
    std::vector < CGUILabel* >  m_pJoypadLabels;
    std::vector < CGUIButton* > m_pJoypadButtons;
    int                         m_JoypadSettingsRevision;

	CGUILabel*			m_pLabelCommunity;
	CGUILabel*			m_pLabelUser;
	CGUILabel*			m_pLabelPass;
	CGUIEdit*			m_pEditUser;
	CGUIEdit*			m_pEditPass;
	CGUIButton*			m_pButtonLogin;
    CGUIButton*			m_pButtonRegister;

    CGUILabel*          m_pControlsMouseLabel;
    CGUICheckBox*       m_pInvertMouse;
    CGUICheckBox*       m_pSteerWithMouse;
    CGUICheckBox*       m_pFlyWithMouse;

    CGUILabel*          m_pControlsJoypadLabel;
    CGUIScrollPane*     m_pControlsInputTypePane;
    CGUIRadioButton*    m_pStandardControls;
    CGUIRadioButton*    m_pClassicControls;

    bool			    OnJoypadTextChanged	    ( CGUIElement* pElement );
	bool			    OnAxisSelectClick       ( CGUIElement* pElement );
	bool			    OnJoypadDefaultClick    ( CGUIElement* pElement );
	bool			    OnBindsDefaultClick		( CGUIElement* pElement );
	bool			    OnBindsListClick		( CGUIElement* pElement );
	bool			    OnCheckBoxClick         ( CGUIElement* pElement );
    bool                OnOKButtonClick         ( CGUIElement* pElement );
    bool                OnCancelButtonClick     ( CGUIElement* pElement );
	bool				OnLoginButtonClick		( CGUIElement* pElement );
    bool				OnRegisterButtonClick	( CGUIElement* pElement );

	bool			    OnMouseDoubleClick		( CGUIMouseEventArgs Args );

private:
	void			    ProcessKeyBinds			( void );
	void			    ProcessJoypad			( void );

    void                SaveData                ( void );

	unsigned int	    m_uiCaptureKey;
    bool                m_bCaptureKey;
    bool                m_bCaptureAxis;

	CGUIListItem*	    m_pSelectedBind;

	DWORD			    m_dwFrameCount;

    std::list < SKeyBindSection *> m_pKeyBindSections;

	enum eCheckBox {
		CHECKBOX_MENU_DYNAMIC,
		CHECKBOX_MENU_VIDEO,
		CHECKBOX_MENU_POSTEFFECTS
	};
};

#endif