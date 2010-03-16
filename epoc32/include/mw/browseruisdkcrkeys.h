/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
*
*/
#ifndef BROWSERUISDKCRKEYS_H
#define BROWSERUISDKCRKEYS_H

const TUid KCRUidBrowserUiLV = {0x101F861B};
const TUid KCRUidBrowser   = {0x10008D39};

// Users should be able to select the volume for plugins
// Valid Values: (mute)0,2,5,8,10(maximum)
const TUint32 KBrowserMediaVolumeControl =  0x0000001C;

// The setting for CSS fetching.
// Valid values: 0 = disabled, 1 = enabled
const TUint32 KBrowserCSSFetch =            0x00000003;

// Boolean value which determines if text inside <nowrap>
// tags on a wml page should be wrapped.
// Valid values: 0 = On, 1 = Off
const TUint32 KBrowserTextWrapEnabled =     0x00000004;

// Browser Security Dialog suppression setting.
// Valid values: 0 = off 1 = on
const TUint32 KBrowserSecurityUI =          0x00000008;

// Variant specific Browser encoding setting.
// Valid values: any positive 32-bit integer value
const TUint32 KBrowserDefaultCharset =      0x00000009;

// Default access point, UID of the AP record.
// Valid values:any positive 32-bit integer value
const TUint32 KBrowserDefaultAccessPoint =  0x0000000E;

// Indicates whether the user has to confirm DTFM sending or not.
// Valid values: 0 = off 1 = on
const TUint32 KBrowserConfirmDTMFSending =  0x00000017;

// Browser IMEI notification setting. UAProf filter uses
// this key to decide whether to send phone's IMEI code
// within User-Agent header. IMEI notification feature is
// only ON if the operator requests it.#
// Valid values: 0 = disable 1 = enable
const TUint32 KBrowserIMEINotification =    0x00000018;

// Integer value to turn on or off the send referrer
// header option.
// Valid values: 0 = off 1 = on
const TUint32 KBrowserSendReferrerHeader =  0x00000019;

// Flags for variating Browser engine
// Any Integer value
const TUint32 KBrowserEngineFlags =         0x00000001;

// These content types will be handled specially like descriptor contents
// Any String value
const TUint32 KBrowserSelfDownloadContentTypes = 0x0000001D;

enum TBrowserCenRepApSelectionModeValues 
    {
    EBrowserCenRepApSelModeUserDefined = 0, // User defined
    EBrowserCenRepApSelModeAlwaysAsk = 1,   // Always ask
    EBrowserCenRepApSelModeDestination = 2  // Destination
    };

// Defines the access point selection mode (User defined, Always ask, Destination)
// Valid values: See above TBrowserCenRepApSelectionModeValues.
// User defined is also what so called Connection Method after SNAP introduction
const TUint32 KBrowserAccessPointSelectionMode = 0x0000001E;

// Setting for DownloadManager to indicate the available drives on harware.
// Valid values: constant string with maximum length of 52bytes,
const TUint32 KBrowserDrivePrefListForDownloadedContent = 0x00000021;

// The flag that's set if Browser build is to be used in United States (USA)
// Valid values: 0 = not set (non-US build)  1 = set (US build)
const TUint32 KBrowserUsBuild =             0x00000023;

// Indicates whether the user has confirmed DTFM once or not.
// Valid values: 0 = no 1 = yes
const TUint32 KBrowserConfirmedDTMFOnce =  0x00000024;

/**
*
* OSS Browser Keys
*
*/

// Load Content 
// Valid values: 
// If flash plugin is present: 0 = Text only, 1 = Images,No flash, 2 = All
// If flash plugin is not present 0 = Text only, 1 = All
const TUint32 KBrowserNGImagesEnabled =       	0x00000025;

// Browser font size.
// Valid values:any positive 32-bit integer value
const TUint32 KBrowserNGFontSize =            	0x00000026;

// Browser encoding setting.
// Valid values: any positive 32-bit integer value
const TUint32 KBrowserNGEncoding =            	0x00000027;

// Browser uses cookies.
// Valid values: 0 = reject 1 = allow
const TUint32 KBrowserNGCookiesEnabled =      	0x0000002B;

// Boolean value which determines whether ECMA Script
// setting is enabled or disabled in Browser.
// Valid values: 0 = disabled 1 = enabled
const TUint32 KBrowserNGECMAScriptSupport =   	0x0000002C;

// Show HTTP security warnings.
// Valid values: 0 = off 1 = on
const TUint32 KBrowserNGShowSecurityWarnings= 	0x0000002D;

// Show Page Overview.
// Valid values: 0 = off 1 = on
const TUint32 KBrowserNGPageOverview = 		  	0x0000002E;

// Mime types for HTTP accept header.
// Any String value
const TUint32 KBrowserNGMimeTypes = 		  	0x00000032;

// Show History view on back softkey press.
// Valid values: 0 = off 1 = on
const TUint32 KBrowserNGBackList = 		  		0x00000033;

// Auto refresh.
// Valid values: 0 = off 1 = on
const TUint32 KBrowserNGAutoRefresh = 		  	0x00000034;

// The setting for encoding a URL with UTF-8 or the original encoding.
// Valid values: 0 = off 1 = on
const TUint32 KBrowserNGUtf8Encoding = 	  		0x00000036;

// With this setting automatic updating of
// Wen Feeds can be set on (with anupdate interval) or off.
// Valid values:
// 0 = Every week
// 1 = Every day
// 2 = Every 4 hours
// 3 = Every hour
// 4 = Every 15 minutes
// 5 = Off
const TUint32 KBrowserNGAutomaticUpdating = 	0x00000037;

// Short cut keys for function: Navigates to home page
// Any String value
const TUint32 KBrowserNGShortCutFuncHomePg =    0x0000003A;

// Short cut keys for function: Go to bookmark 
// Any String value
const TUint32 KBrowserNGShortCutFuncBkMark =    0x0000003B;

// Short cut keys for function: Find keyword
// Any String value
const TUint32 KBrowserNGShortCutFuncFindKeyWord  =    0x0000003C;

// Short cut keys for function: Go to the previous page
// Any String value
const TUint32 KBrowserNGShortCutFuncPrePage =    0x0000003D;

// Short cut keys for function: Switch window
// Any String value
const TUint32 KBrowserNGShortCutFuncSwitchWin =    0x0000003E;

// Short cut keys for function: Toggles miniature image on/off
// Any String value
const TUint32 KBrowserNGShortCutFuncMiniImage =    0x0000003F;

// Short cut keys for function: Go to address
// Any String value
const TUint32 KBrowserNGShortCutFuncGoAddr =    0x00000040;

// Short cut keys for function: Zoom in
// Any String value
const TUint32 KBrowserNGShortCutFuncZoomIn =    0x00000041;

// Short cut keys for function: Zoom out
// Any String value
const TUint32 KBrowserNGShortCutFuncZoomOut =    0x00000042;

// The access point used when Web Feeds was updated automatically
const TUint32 KBrowserNGAutomaticUpdatingAccessPoint =     0x00000043;

// Setting to enable "Rotate display" menu item
const TUint32 KBrowserNGRotateDisplay =          0x00000044;

// Setting to enable "Open download" menu item
// Valid value 0 = no, 1 = yes 
const TUint32 KBrowserNGOpenDownloads =          0x00000045;

//DEPRECATED/OBSOLETE: Smart Link.
// Valid values: 0 = off 1 = on
const TUint32 KBrowserNGSmartLink = 		  	0x00000046;    

// Setting to enable updating while roaming
// Valid values: 0 = off 1 = on
const TUint32 KBrowserNGAutomaticUpdatingWhileRoaming = 0x00000047;

// DEPRECATED/OBSOLETE: Show platform toolbar
// Valid value int
//const TUInt32 KBrowserNGShowPlatformToolbar = 0x00000048;

// Last visible toolbar
// Valid values: basic toolbar = 0 address toolbar = 1
//const TUint32 KBrowserNGLastVisibleToolbar = 0x00000049;

// Setting to enable the Http Optimisations (HttpFilterOptB)
// Valid values: 0 = disabled, 1 = enabled
const TUint32 KBrowserNGHttpOptBEnabled	=        0x00000050;

// Setting to determines if the Access keys feature is enabled or disabled
// Valid values: 0 = off 1 = on
//const TUint32 KBrowserNGAccessKeys =            0x00000051;

// The FileManager UID
const TUint32 KFileManagerUid =               0x00000052;

//the key used to get the default snap id
const TUint32 KBrowserNGDefaultSnapId =    0x00000053;

// User configurable suffixes for URL completion
// Any String value
const TUint32 KBrowserUrlSuffix =    0x00000054;

//Setting for Toolbar On/Off configuration
// Turns Toolbar On or Off ( 0 = Off ; 1 = On)
const TUint32 KToolbarOnOff =                 0x00000055;

//Setting for Toolbar Button 1 Command
const TUint32 KToolbarButton1Cmd =            0x00000056;

//Setting for Toolbar Button 2 Command
const TUint32 KToolbarButton2Cmd =            0x00000057;
             
//Setting for Toolbar Button 3 Command
const TUint32 KToolbarButton3Cmd =            0x00000058;

//Setting for Toolbar Button 4 Command
const TUint32 KToolbarButton4Cmd =            0x00000059;

//Setting for Toolbar Button 5 Command
const TUint32 KToolbarButton5Cmd =            0x00000060;

//Setting for Toolbar Button 6 Command
const TUint32 KToolbarButton6Cmd =            0x00000061;

//Setting for Toolbar Button 7 Command
const TUint32 KToolbarButton7Cmd =            0x00000062;

//Setting for Shortcut Key 1 Command
const TUint32 KShortcutKey1Cmd =            0x00000063;

//Setting for Shortcut Key 2 Command
const TUint32 KShortcutKey2Cmd =            0x00000064;

//Setting for Shortcut Key 3 Command
const TUint32 KShortcutKey3Cmd =            0x00000065;

//Setting for Shortcut Key 4 Command
const TUint32 KShortcutKey4Cmd =            0x00000066;

//Setting for Shortcut Key 5 Command
const TUint32 KShortcutKey5Cmd =            0x00000067;

//Setting for Shortcut Key 6 Command
const TUint32 KShortcutKey6Cmd =            0x00000068;

//Setting for Shortcut Key 7 Command
const TUint32 KShortcutKey7Cmd =            0x00000069;

//Setting for Shortcut Key 8 Command
const TUint32 KShortcutKey8Cmd =            0x0000006A;

//Setting for Shortcut Key 9 Command
const TUint32 KShortcutKey9Cmd =            0x0000006B;

//Setting for Shortcut Key 0 Command
const TUint32 KShortcutKey0Cmd =            0x0000006C;

//Setting for Shortcut Key Star Command
const TUint32 KShortcutKeyStarCmd =            0x0000006D;

//Setting for Shortcut Key Hash Command
const TUint32 KShortcutKeyHashCmd =            0x0000006E;

//Setting for Shortcut Keys for QWERTY keypad
// (1 = On = QWERTY keypad)
// (0 = Off = Numeric keypad)
const TUint32 KShortcutKeysForQwerty =            0x0000006F;

// Int value which determines if and how
// script console is enabled in Browser.
// Valid values: 0 = disabled 1 = log to file 1 = log to UI console
const TUint32 KBrowserNGScriptLog =   	0x00000070;

// KBrowserNGZoomMin represents the minimum percentage zoom level to be 
// supported by the browser. 
// Valid values: 10 to 2000, default value for this field 10
const TUint32 KBrowserNGZoomMin =   	0x00000071;

// The browser supports zoom levels between 10-2000 percent.
// KBrowserNGZoomMax represents the maximum percentage zoom level to be 
// supported by the browser.
// Valid values: 10 to 2000, default value for this field 200
const TUint32 KBrowserNGZoomMax =   	0x00000072;

// KBrowserNGZoomDefault represents the default percentage zoom level to be 
// supported by the browser when opening a webpage for the first time.
// Valid values: 10 to 2000, default value for this field 100
const TUint32 KBrowserNGZoomDefault =  0x00000073;

// KBrowserNGMaxRecentUrls is the number of Recent URLs to be shown in 
// the pop up list 
// Valid values: 1 to 10, default value for this field is 6
const TUint32 KBrowserNGMaxRecentUrls = 0x00000074;

// Short cut keys for function: Toggles Full Screen Mode on/off
// Any String value
const TUint32 KBrowserNGShortCutFuncFullScreen =    0x00000075;

// Short cut keys for function: Zoom Mode
// Any String value
const TUint32 KBrowserNGShortCutFuncZoomMode =      0x00000076;

// KBrowserSearchIconPath path to mif file saving search icons
// Given and updated by search application
// like z:\\resource\\apps\\xxx.mif
const TUint32 KBrowserSearchIconPath = 0x00000077;

// KBrowserSearchIconId Current search iconId From search mif file
// Given and updated by search application
// Valid values: TInt
const TUint32 KBrowserSearchIconId = 0x00000078;

// KBrowserSearchIconMaskId Current search iconMaskId From search mif file
// Given and updated by search application
// Valid values: TInt
const TUint32 KBrowserSearchIconMaskId = 0x00000079;

// KBrowserSearchProviderTitle Title to current search provider
// Given and updated by search application
const TUint32 KBrowserSearchProviderTitle = 0x0000007A;

// KBrowserServiceUrl Browser Service url
// Used to lauch service application through scheme handler
const TUint32 KBrowserServiceUrl = 0x0000007B;

// KBrowserFirstBoot
// Valid values: 1 if browser first boot is not done yet, other 0  
const TUint32 KBrowserFirstBoot = 0x0000007C;

// KBrowserSearch TInt if browser search is present 
// Valid values: 0, 1
const TUint32 KBrowserSearch = 0x0000007D;

// KBrowserServices TInt if browser service is present
// Valid values: 0,1 
const TUint32 KBrowserServices = 0x0000007E;

// KBrowserSearchAppUid - browser Search Application UID
// Valid values:any positive 32-bit integer value
const TUint32 KBrowserSearchAppUid= 0x0000007F;

// Search Application View UID for selection of Default 
// Search Provider.
// Valid values:any positive 32-bit integer value.
const TUint32 KBrowserSearchProviderSettingViewId = 0x00000080;

// KBrowserSearchProviderUrl Browser Search url
// Used by Search Scheme Handler.
const TUint32 KBrowserSearchProviderUrl = 0x00000081;

#endif      // BROWSERUISDKCRKEYS_H