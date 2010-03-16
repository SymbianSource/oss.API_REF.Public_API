// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
 @file
 @publishedAll
 @released
*/

#ifndef REMCONMEDIAINFORMATIONTARGETOBSERVER_H
#define REMCONMEDIAINFORMATIONTARGETOBSERVER_H

#include <e32base.h>

enum TMediaAttributeId
	{
	ETitleOfMedia 			=0x1,
	ENameOfArtist			=0x2,
	ENameOfAlbum			=0x3,
	ETrackNumber			=0x4,		/* for example the CD track number */
	ENumberOfTracks			=0x5,		/* for example the total track number of the CD */
	EGenre					=0x6,
	EPlayingTime			=0x7
	};

/**
 * Provide an iterator wrapper class 
 */
class TMediaAttributeIter
	{
public:
	TMediaAttributeIter(RArray<TMediaAttributeId>& aMediaAttributeIDs);
	IMPORT_C void Start();
	IMPORT_C TBool Next(TMediaAttributeId& aId);
	
private:
	RArray<TMediaAttributeId>& iMediaAttributeIDs;
	TInt iterator;
	};


/**
Clients must implement this interface in order to instantiate objects of type 
CRemConMediaInformationTarget. This interface passes incoming commands from RemCon to 
the client. 
*/
NONSHARABLE_CLASS(MRemConMediaInformationTargetObserver)
	{
public:

	/**
	For each element in aAttributeList for which the requested Metadata is available,
	the client shall respond by calling CRemConMediaInformationTarget::AttributeValue(). 
	After all attributes have been supplied the client shall call CRemConMediaInformationTarget::Completed().
	@param aAttributeList A CMediaAttributeIDs containing a list of TMediaAttributeIds requested by the controller
	@see CRemConMediaInformationTarget::AttributeValue()
	@see CRemConMediaInformationTarget::Completed()
	*/
	virtual void MrcmitoGetCurrentlyPlayingMetadata( TMediaAttributeIter& aAttributeIter ) = 0;

	};

#endif // REMCONMEDIAINFORMATIONTARGETOBSERVER_H
