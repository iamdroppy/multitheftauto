/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        gui/CGUITabPanel_Impl.cpp
*  PURPOSE:     Tab panel widget class
*  DEVELOPERS:  Christian Myhre Lundheim <>
*               Cecill Etheredge <ijsf@gmx.net>
*               Chris McArthur <>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

#define CGUITABPANEL_NAME "CGUI/TabControl"

CGUITabPanel_Impl::CGUITabPanel_Impl ( CGUI_Impl* pGUI, CGUIElement* pParent )
{
	m_pManager = pGUI;
	m_pData = NULL;

	// Initialize
	m_pGUI = pGUI;

    // Get an unique identifier for CEGUI (gah, there's gotta be an another way)
    char szUnique [CGUI_CHAR_SIZE];
    pGUI->GetUniqueName ( szUnique );

    // Create the window and set default settings
    m_pWindow = pGUI->GetWindowManager ()->createWindow ( CGUITABPANEL_NAME, szUnique );
    m_pWindow->setDestroyedByParent ( false );
    m_pWindow->setRect ( CEGUI::Relative, CEGUI::Rect (0.9f, 0.9f, 0.9f, 0.9f) );
	reinterpret_cast < CEGUI::TabControl* > ( m_pWindow ) -> setAbsoluteTabTextPadding ( 10.0f );

	// Store the pointer to this CGUI element in the CEGUI element
	m_pWindow->setUserData ( reinterpret_cast < void* > ( this ) );

    AddEvents ();

    // If a parent is specified, add it to it's children list, if not, add it as a child to the m_pManager
    if ( pParent )
    {
        SetParent ( pParent );
    }
    else
    {
        pGUI->AddChild ( this );
		SetParent ( NULL );
    }
}

CGUITabPanel_Impl::~CGUITabPanel_Impl ( void )
{
    m_pManager->RemoveFromRedrawQueue ( reinterpret_cast < CGUIElement* > ( ( m_pWindow )->getUserData () ) );

    // Destroy the control
    m_pWindow->destroy ();

	// Destroy the properties list
	EmptyProperties ();
}


CGUITab* CGUITabPanel_Impl::CreateTab ( const char* szCaption )
{
	return new CGUITab_Impl ( m_pGUI, this, szCaption );
}

void CGUITabPanel_Impl::DeleteTab ( CGUITab* pTab )
{
	CEGUI::TabControl* TabControl = reinterpret_cast < CEGUI::TabControl* > ( m_pWindow );
	CGUITab_Impl* pTabImpl = reinterpret_cast < CGUITab_Impl* > ( pTab );

	TabControl->removeTab(pTabImpl->GetWindow()->getName());
	return;
}

size_t CGUITabPanel_Impl::GetSelectedTabIndex ( void )
{
    return reinterpret_cast < CEGUI::TabControl* > ( m_pWindow )->getSelectedTabIndex ();
}

void CGUITabPanel_Impl::SetSelectedTabIndex ( size_t index )
{
    reinterpret_cast < CEGUI::TabControl* > ( m_pWindow )->setSelectedTabAtIndex ( index );
}

bool CGUITabPanel_Impl::IsTabSelected ( CGUITab* pTab )
{
    return reinterpret_cast < CEGUI::TabControl* > ( m_pWindow )->isTabContentsSelected ( reinterpret_cast < CGUITab_Impl* > ( pTab )->GetWindow () );
}

CGUITab* CGUITabPanel_Impl::GetSelectedTab ( void )
{
    size_t tabIndex = GetSelectedTabIndex ();
    CEGUI::TabControl* pTab = reinterpret_cast < CEGUI::TabControl* > ( m_pWindow );
    return reinterpret_cast < CGUITab* > ( pTab->getTabContentsAtIndex ( tabIndex ) );
}