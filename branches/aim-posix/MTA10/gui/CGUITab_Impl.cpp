/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        gui/CGUITab_Impl.cpp
*  PURPOSE:     Tab widget class
*  DEVELOPERS:  Christian Myhre Lundheim <>
*               Cecill Etheredge <ijsf@gmx.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

CGUITab_Impl::CGUITab_Impl ( CGUI_Impl* pGUI, CGUIElement_Impl* pParent, const char* szCaption )
{
	m_pManager = pGUI;
	m_pData = NULL;

    // Get an unique identifier for CEGUI
    char szUnique [CGUI_CHAR_SIZE];
    pGUI->GetUniqueName ( szUnique );
	
    // Create the window and set default settings
    m_pWindow = pGUI->GetWindowManager ()->createWindow ( "DefaultWindow", szUnique );
    m_pWindow->setDestroyedByParent ( true );
    m_pWindow->setText ( szCaption );

	// Store the pointer to this CGUI element in the CEGUI element
	m_pWindow->setUserData ( reinterpret_cast < void* > ( this ) );

    AddEvents ();

    // If a parent is specified, add it to it's children list, if not, add it as a child to the pManager
    if ( pParent )
    {
        SetParent ( pParent );

		// Adjust the tab button (pParent should be a TabControl!)
		reinterpret_cast < CEGUI::TabControl* > ( ((CGUITabPanel_Impl*)pParent)->m_pWindow ) -> setAbsoluteTabHeight ( 24.0f );
    }
    else
    {
        pGUI->AddChild ( this );
		SetParent ( NULL );
    }
}


CGUITab_Impl::~CGUITab_Impl ( void )
{
    m_pManager->RemoveFromRedrawQueue ( reinterpret_cast < CGUIElement* > ( ( m_pWindow )->getUserData () ) );

    // Destroy the control
    m_pWindow->destroy ();

	// Destroy the properties list
	EmptyProperties ();
}


void CGUITab_Impl::SetCaption ( const char* szCaption )
{
	CEGUI::String strCaption;

	if ( szCaption ) strCaption.assign ( szCaption );
	m_pWindow->setText ( strCaption );
}
