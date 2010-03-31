/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
*     Contains common consts, typedefs for the Access Point settings.
*
*/


#ifndef APSETTINGS_HANDLER_COMMONS_H
#define APSETTINGS_HANDLER_COMMONS_H

// Deprecation warning
#warning This header file has been deprecated. Will be removed in one of the next SDK releases.
 
 
// INCLUDES
#include <ApEngineConsts.h>


//#define __TEST_OOMDEBUG


// CONSTANTS
_LIT( KEmpty, "");

_LIT( KTestFileName, "C:\\Data\\ApSetUiTest\\TestState.txt" );

const TInt  KApSelectionCanceled    = -350;
const TInt  KTxtNotOverriden        = -351;
const TInt  KErrInvalidTextId       = -355;

#ifdef __TEST_OOMDEBUG
    const TInt  KDialogListTest      = 1;   // Done
    const TInt  KPopupListTest       = 2;   // Done
    const TInt  KQueryTest           = 3;   // Done
    const TInt  KEditingTest         = 4;   // Done
    const TInt  KViewerTest          = 5;   // impl.
    const TInt  KCreateBlankTest     = 6;   // Impl
    const TInt  KCreateUseExistTest  = 7;   // Impl
    const TInt  KDeleteTest          = 8;   // N/I!

    const TUint32   KOOMRetryCount   = 10;
    const TUint32   KOOMRetryOffset  = 5;
#endif // __TEST_OOMDEBUG

// DATA TYPES
enum TTextID    /// These enums are used to identify the 'overridable' 
                /// text items in CApSettingsHandler.
    {
    EApSettingsSelStatusPaneText = 0x00,
    EApSettingsSelListEmptyText,
    EPopupPromptText            /// Only this last one is used & implemented.
    };


enum TTransactionResult         ///< Transaction results
    {
    EOwnTransaction,            ///< Own transaction started
    EUsingAlreadyStarted,       ///< Used already started one
    EFailedWithLocked           ///< Transaction start failed with KErrLocked
    };


enum TApUiExitReason
    {
    EExitNone,
    EExit,
    EShutDown
    };


// CONSTANTS
const TInt  KTTextIdMin             =  EApSettingsSelStatusPaneText;
const TInt  KTTextIdMax             =  EPopupPromptText;

const TInt  KMaxNumOfLockedDbRetries= 3;

/// Ui return code flags. They indicate what has happened inside the module. 
/// They can be combined.
/**
* Ui return code flags. They indicate what has happened inside the module. 
* They can be combined. The most important one is KApUiEventSelected and it 
* indicates that the user selected an access point (in case of selection...)
*/
const TInt  KApUiEventNone              = 0x00000000;   ///< Nothign happend
const TInt  KApUiEventSelected          = 0x00000001;   ///< Item was selected
const TInt  KApUiEventCreatedBlank      = 0x00000002;   ///< New item created 
                                                        ///< from blank
const TInt  KApUiEventCreatedUsedOld    = 0x00000004;   ///< New item created 
                                                        ///< from an existing 
                                                        ///< one
const TInt  KApUiEventEdited            = 0x00000008;   ///< Item edited
const TInt  KApUiEventDeleted           = 0x00000010;   ///< Item deleted
const TInt  KApUiEventExitRequested     = 0x00000020;   ///< User choosed Exit
const TInt  KApUiEventShutDownRequested = 0x00000040;   ///< System shutdown

// INTERNAL flag
const TUint32  KApUiEventInternal       = 0x80000000;   ///< Internal flag


const TUint32  KApNoneUID               = 0x00000000;


enum TSelectionListType         ///< Defines the list type to be used
    {
    EApSettingsSelListIsPopUp, 
    EApSettingsSelListIsListPane,
    EApSettingsSelListIsPopUpWithNone
    };


enum TSelectionMenuType         ///< Defines the Options menu type to be used
    {
    EApSettingsSelMenuNormal, 
    EApSettingsSelMenuSelectOnly,
    EApSettingsSelMenuSelectNormal
    };



enum TApSettingsHandlerUiPanicCodes ///< Defines the Panic codes
    {
    EMenuCommandUnknown,            ///< Unknonw menu command
    EInvalidDbType,                 ///< Invalid database type
    EInvalidBitmapType,             ///< Invalid bitmap type
    EInvalidBearerType,             ///< Invalid bearer type
    EInvalidIspRequest,             ///< Invalid ISP request
    ENullPointer,                   ///< Null pointer passed
    EUnknownCase,                   ///< Unknown 'case' 
    EInvalidTextType,               ///< Invalid text type
    EInvalidState                   ///< Invalid state
    } ;



/**
* Panic
* @param aPanic Panic code
*/
void Panic( TApSettingsHandlerUiPanicCodes aPanic );


/**
* Ask a query
* @param aResId Resource id
* @param aVar variable part of the query, if any
* @return The result of the query
*/
TInt AskQueryL( TInt aResId, TDesC* aVar = NULL );


/**
* Shows a note
* @param aResId Resource id
* @param aVar variable part of the note, if any
* @return The result of the note
*/
TInt ShowNoteL( TInt aResId, TDesC* aVar = NULL );


#ifdef __TEST_OOMDEBUG
    TInt GetTestState();
#endif // __TEST_OOMDEBUG

#endif


// End of File
