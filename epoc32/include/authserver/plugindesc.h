/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
* CPluginDesc class declaration
*
*/


/**
 @file 
 @publishedAll
 @released
*/

#ifndef PLUGINDESC_H
#define PLUGINDESC_H

#include <s32strm.h>
#include <ct/rcpointerarray.h>
#include "authserver/authtypes.h"

namespace AuthServer
{

/**
 * Provides a description of an authentication plugin's properties.
 **/
NONSHARABLE_CLASS(CPluginDesc) : public CBase
	{
public:

	IMPORT_C static CPluginDesc* NewL(
		TPluginId aId, const TDesC& aName,
		TAuthPluginType aType, TAuthTrainingStatus aTrainingStatus,
		TEntropy aMinEntropy, TPercentage aFalsePositiveRate,
		TPercentage aFalseNegativeRate);
	IMPORT_C static CPluginDesc* NewLC(RReadStream& aIn);
	
	virtual ~CPluginDesc();
	
	IMPORT_C TPluginId           Id() const;
	IMPORT_C const TDesC*        Name() const;
	IMPORT_C TAuthPluginType     Type() const;
	IMPORT_C TAuthTrainingStatus TrainingStatus() const;
	IMPORT_C TEntropy            MinEntropy() const;
	IMPORT_C TPercentage         FalsePositiveRate() const;
	IMPORT_C TPercentage         FalseNegativeRate() const;

	IMPORT_C void ExternalizeL(RWriteStream& aOut) const;
		
private:
	static const TInt KMaxNameLength = 256;
		
	CPluginDesc(TPluginId           aId,
				TAuthPluginType     aType,
				TAuthTrainingStatus aTrainingStatus,
				TEntropy            aMinEntropy,
				TPercentage         aFalsePositiveRate,
				TPercentage         aFalseNegativeRate);
	void ConstructL(const TDesC& aName);

	inline CPluginDesc();
	void InternalizeL(RReadStream& aIn);

	/// the id of the plugin
	TPluginId           iId;
	/// The name of the plugin
	HBufC*              iName;
	/// The type of plugin
	TAuthPluginType     iType;
	/// Indicates whether the plugin is trained for none, some or all
	/// known identities.
	TAuthTrainingStatus iTrainingStatus;
	/// The minumum entropy provided by the plugin.
	TEntropy            iMinEntropy;
	/// The false positive rate of the plugin
	TPercentage         iFalsePositiveRate;
	/// The false negative rate of the plugin.
	TPercentage         iFalseNegativeRate;
    };

typedef RCPointerArray<const CPluginDesc> RPluginDescriptions;

}   

#include <authserver/plugindesc.inl>

#endif // PLUGINDESC_H
