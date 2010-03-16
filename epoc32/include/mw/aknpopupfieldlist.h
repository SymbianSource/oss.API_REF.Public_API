/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
*
*/

// AknPopupFieldList.h
//
// Copyright (c) 2001 Symbian Ltd.  All rights reserved.
//

#if !defined(__AKNPOPUPFIELDLIST_H__)
#define __AKNPOPUPFIELDLIST_H__

#include "AknPopup.h"

class MAknQueryValue;
class TAknDesCArrayDecorator;
class CEikButtonGroupContainer;

/**
 * No longer implemented, do not use
 */
class CAknPopupFieldList : public CEikBorderedControl, public MEikCommandObserver, public MEikListBoxObserver, public MCoeControlObserver
	{
public:
	IMPORT_C static CAknPopupFieldList* NewL(CEikListBox* aListBox, TInt aCbaResource);
	IMPORT_C void SetQueryValue(MAknQueryValue* aValue);
	IMPORT_C void SetDecorator(TAknDesCArrayDecorator* aDecorator);
    // From CCoeControl
    IMPORT_C void HandlePointerEventL(const TPointerEvent& aPointerEvent);	
protected:
	// From MEikCommandObserver
	IMPORT_C void ProcessCommandL(TInt aCommandId);
	// From MEikListBoxObserver
	IMPORT_C void HandleListBoxEventL(CEikListBox* aListBox, TListBoxEvent aEventType);
	// From MCoeControlObserver
	IMPORT_C void HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType);
protected:
	IMPORT_C CAknPopupFieldList();
	IMPORT_C ~CAknPopupFieldList();
	IMPORT_C void ConstructL(CEikListBox* aListBox, TInt aCbaResource);
	IMPORT_C virtual void AttemptExitL(TBool aAccept);
	IMPORT_C CEikListBox* ListBox() const;
protected: // from MObjectProvider
	IMPORT_C TTypeUid::Ptr MopSupplyObject(TTypeUid aId);
private:
    /**
    * From CAknControl
    */
    IMPORT_C void* ExtensionInterface( TUid aInterface );
private:
	// the following members are owned
	CEikButtonGroupContainer* iPopoutCba;
	// the following members are not owned
	MAknQueryValue* iValue;
	TAknDesCArrayDecorator* iDecorator;
	CEikListBox* iListBox;

    TInt iSpare[2];

	__DECLARE_TEST;
	};

#endif
