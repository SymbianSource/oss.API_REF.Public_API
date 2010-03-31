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
// Defines ECOM-plugin related classes used accross the Core Dump client/server interface 
//



/**
 @file
 @publishedPartner 
 @released
*/

#ifndef PLUGINDATA_H
#define PLUGINDATA_H

/**
@publishedPartner 
@released

Class used between Core Dump Server and its clients to request 
the server to carry out actions on plugins, such as load/unload.
@see CCrashConfig::LoadPlugin()
*/
class TPluginRequest
{
public:

	/** 
	Type of plugin to request
	*/
	enum TPluginType
		{
		/** A formatter plugin */
		EFormatter,
		/** A writer plugin */
		EWriter
		};


	/** Whether to load or unload the plugin */
	TBool						iLoad;

	/** Type of plugin */
	TPluginType					iPluginType;

	/** @internalTechnology */
	TUint						iIndex;

	/** Plugin UID, used to check correct plugin */
	TUid						iUid;

	/** @internalTechnology */
	TUint32 iSpare1;

	/** @internalTechnology */
	TUint32 iSpare2;
};


/** Maximum length allowed for a plugin's name */
#define KPluginNameLength (50)

/** Maximum length allowed for a plugin's description */
#define KPluginDescriptionLength (250)

/**
@publishedPartner 
@released

Detailed information about a plugin.
@see RPluginList
@see TPluginInfoBlock
*/
class TPluginInfo
{
public:

	/** Plugin's own version.
	From rss file::IMPLEMENTATION_INFO::version_no */
	TUint					iVersion;

	/** Plugin's unique UID. 
	From rss file::IMPLEMENTATION_INFO::implementation_uid */
	TUid					iUid;

	/** Plugin's own name.
	From rss file::IMPLEMENTATION_INFO::display_name */
	TBufC<KPluginNameLength>			iName;

	/** Plugin's own description obtained from 
	CCoreDumpFormatter->GetDescription()
	@see CCoreDumpFormatter */
	TBufC<KPluginDescriptionLength>	iDescription;

	/** Plugin type : from TPluginRequest::TPluginType */
	TPluginRequest::TPluginType	iType;

	/** Plugin loaded state. */
	TBool					iLoaded;

	/** Reserved for future use
	@internalTechnology */
	TUint32 iSpare1;

	/** @internalTechnology */
	TUint32 iSpare2;
};


/**
@publishedPartner 
@released

List of TPluginInfo objects.
@see TPluginInfo
@see RArray
*/
typedef RArray<TPluginInfo>	RPluginList;



#endif
