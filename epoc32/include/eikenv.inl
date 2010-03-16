// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//



/**
 Gets the CEikonEnv maintained by the framework for the application. 
 
 This function should never be run in a thread where such a static Uikon environment 
 does not exist. Code that may run on the server side of an application server 
 is one such case.
 
 @return A static CEikonEnv. 
 @see CCoeEnv::Static() 
*/
inline CEikonEnv* CEikonEnv::Static()
	{ return((CEikonEnv*)(CCoeEnv::Static())); }

/**
@publishedPartner
@released
*/
inline TInt CEikonEnv::EditableControlStandardHeight() const
	{ return(iEditableControlStandardHeight); }

/** Gets the Uikon process that manages the files of applications started in this 
environment.

@return The CEikProcess object. */
inline CEikProcess* CEikonEnv::Process() const
	{ return(iProcess); }

/** Gets the application UI of the application using this CEikonEnv.

@return Pointer to the CEikAppUi. */
inline CEikAppUi* CEikonEnv::EikAppUi() const
	{ return((CEikAppUi*)iAppUi); }
inline const MEikAlertWin* CEikonEnv::Alert() const
	{ return(iAlertWin); }

/** Gets the minus nudge character, this could be the left arrow for example. 

@return Minus nudge character. */
inline TChar CEikonEnv::NudgeCharMinus() const
	{return(iNudgeChars[0]);}

/** Gets the plus nudge character, this could be the right arrow for example.

@return Plus nudge character. */
inline TChar CEikonEnv::NudgeCharPlus() const
	{return(iNudgeChars[1]);}

/** Gets the physical (TRgb) colour which corresponds to a logical colour.

@param aLogicalColor A logical colour value. 
@return The physical colour which corresponds to aLogicalColor. */
inline TRgb CEikonEnv::Color(TLogicalColor aLogicalColor) const
	{return ColorList().Color(aLogicalColor); }

/** Gets the custom colour array.

@return The custom colour array. */
inline CColorArray& CEikonEnv::CustomColorArray() const
	{return *(ColorList().ColorArray(TUid::Uid(KEikCustomColorsArrayValue)));}

/** Gets the application's colour list. 

The colour list provides member functions to retrieve and modify colours 
in the list, and to append new arrays of colours to the colour list.

@return The application's colour list */
inline CColorList& CEikonEnv::ColorList() const
	{__ASSERT_DEBUG(iColorList,User::Invariant()); return *iColorList; }

/** Sets a mapping in the application's colour list between the logical and physical 
colours specified.

@param aLogicalColor A logical colour value. 
@param aColor A physical colour value. */
inline void CEikonEnv::SetColor(TLogicalColor aLogicalColor, TRgb aColor)
	{ ColorList().SetColor(aLogicalColor, aColor); }

/**
@publishedPartner
@released
*/
inline void CEikonEnv::SetCDlgDialogFactory(MEikCDlgDialogFactory* aDialogFactory)
	{iCDlgDialogFactory=aDialogFactory;}

/**
@publishedPartner
@released
*/
inline void CEikonEnv::SetPrintDialogFactory(MEikPrintDialogFactory* aDialogFactory)
	{iPrintDialogFactory=aDialogFactory;}

/**
@publishedPartner
@released
*/
inline void CEikonEnv::SetFileDialogFactory(MEikFileDialogFactory* aDialogFactory)
	{iFileDialogFactory=aDialogFactory;}

/**
@publishedPartner
@released
*/
inline void CEikonEnv::SetIrFactory(MEikIrFactory* aIrFactory)
	{iIrFactory=aIrFactory;}

/**
@publishedPartner
@released
*/
inline MEikCDlgDialogFactory* CEikonEnv::CDlgDialogFactory() const
	{return iCDlgDialogFactory;}

/**
@publishedPartner
@released
*/
inline MEikPrintDialogFactory* CEikonEnv::PrintDialogFactory() const
	{return iPrintDialogFactory;}

/**
@publishedPartner
@released
*/
inline MEikFileDialogFactory* CEikonEnv::FileDialogFactory() const
	{return iFileDialogFactory;}

/**
@publishedPartner
@released
*/
inline MEikIrFactory* CEikonEnv::IrFactory() const
	{return iIrFactory;}


inline TInt CEikonEnv::AddLibraryL(TCreateByTypeFunction aControlFactory)
	{return(AddLibraryL(aControlFactory, NULL));}
inline TInt CEikonEnv::AddLibraryL(TFileName* aResourceFile)
	{return(AddLibraryL(NULL, aResourceFile));}
inline void CEikonEnv::RemoveLibrary(TCreateByTypeFunction aControlFactory)
	{RemoveLibrary(aControlFactory, NULL);}
inline void CEikonEnv::RemoveLibrary(TInt aResourceFileOffset)
	{RemoveLibrary(NULL, aResourceFileOffset);}


/**
@publishedPartner
@deprecated
*/
inline CBase* CEikonEnv::Extension() const
	{return iExtension;}

/**
@publishedPartner
@released
*/
inline TInt CEikonEnv::StatusPaneCoreResId() const
	{return iStatusPaneCoreResId;}

/**
@publishedPartner
@released
*/
inline void CEikonEnv::SetStatusPaneCoreResId(TInt aStatusPaneCoreResId)
	{iStatusPaneCoreResId=aStatusPaneCoreResId;}

/**
@publishedPartner
@released
*/
inline CEikAutoMenuTitleArray* CEikonEnv::AutoMenuTitleArray() const
	{return iAutoMenuTitleArray;}

inline const CEikDialog* MEikAlertWin::AsEikDialog() const
	{return (const CEikDialog*)const_cast<MEikAlertWin*>(this)->AsEikDialog();}

inline const CCoeControl* MEikAlertWin::AsCoeControl() const
	{return (const CCoeControl*)const_cast<MEikAlertWin*>(this)->AsCoeControl();}
