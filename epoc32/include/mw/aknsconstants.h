/*
* Copyright (c) 2002-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Defines constant values for Avkon Skins.
*
*/


#ifndef AKNSCONSTANTS_H
#define AKNSCONSTANTS_H

/**
* @file AknsConstants.h
*
* Defines constants common for Avkon Skins.
*
* @since 2.0
*/

//  INCLUDES
#include <e32std.h>
#include <AknsItemID.h>
#include <aknsconstants.hrh>

// CONSTANTS

// SCCMARKER_BEGIN

// ============================================================================
// Common IIDs
// ============================================================================

// ----------------------------------------------------------------------------
// None and default values
// ----------------------------------------------------------------------------

static const TAknsItemID KAknsIIDNone =
    { EAknsMajorNone, EAknsMinorNone };

static const TAknsItemID KAknsIIDDefault =
    { EAknsMajorDefault, EAknsMinorDefault };

// ----------------------------------------------------------------------------
// EAknsMajorSkin item IDs
// ----------------------------------------------------------------------------

// Screen, status and control areas

static const TAknsItemID KAknsIIDQsnBgScreen =
    { EAknsMajorSkin, EAknsMinorQsnBgScreen };

static const TAknsItemID KAknsIIDQsnBgScreenIdle =
    { EAknsMajorSkin, EAknsMinorQsnBgScreenIdle };

static const TAknsItemID KAknsIIDQsnBgScreenMp =
    { EAknsMajorSkin, EAknsMinorQsnBgScreenMp };

static const TAknsItemID KAknsIIDQsnBgAreaStatus =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaStatus };

static const TAknsItemID KAknsIIDQsnBgAreaStatusIdle =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaStatusIdle };

static const TAknsItemID KAknsIIDQsnBgAreaControl =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaControl };

static const TAknsItemID KAknsIIDQsnBgAreaControlPopup =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaControlPopup };

static const TAknsItemID KAknsIIDQsnBgAreaControlIdle =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaControlIdle };

static const TAknsItemID KAknsIIDQsnBgAreaControlMp =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaControlMp };

// Stacon

static const TAknsItemID KAknsIIDQsnBgAreaStaconRt =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaStaconRt };

static const TAknsItemID KAknsIIDQsnBgAreaStaconLt =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaStaconLt };

static const TAknsItemID KAknsIIDQsnBgAreaStaconRb =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaStaconRb };

static const TAknsItemID KAknsIIDQsnBgAreaStaconLb =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaStaconLb };

static const TAknsItemID KAknsIIDQsnBgAreaStaconRtIdle =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaStaconRtIdle };

static const TAknsItemID KAknsIIDQsnBgAreaStaconLtIdle =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaStaconLtIdle };

static const TAknsItemID KAknsIIDQsnBgAreaStaconRbIdle =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaStaconRbIdle };

static const TAknsItemID KAknsIIDQsnBgAreaStaconLbIdle =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaStaconLbIdle };

// Main areas

static const TAknsItemID KAknsIIDQsnBgAreaMain =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMain };

static const TAknsItemID KAknsIIDQsnBgAreaMainListGene =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainListGene };

static const TAknsItemID KAknsIIDQsnBgAreaMainListSet =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainListSet };

static const TAknsItemID KAknsIIDQsnBgAreaMainAppsGrid =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainAppsGrid };

static const TAknsItemID KAknsIIDQsnBgAreaMainMessage =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainMessage };

static const TAknsItemID KAknsIIDQsnBgAreaMainIdle =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainIdle };

static const TAknsItemID KAknsIIDQsnBgAreaMainPinb =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainPinb };

static const TAknsItemID KAknsIIDQsnBgAreaMainCalc =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainCalc };

static const TAknsItemID KAknsIIDQsnBgAreaMainQdial =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainQdial };

static const TAknsItemID KAknsIIDQsnBgAreaMainIdleDimmed =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainIdleDimmed };

static const TAknsItemID KAknsIIDQsnBgAreaMainHigh =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainHigh };

static const TAknsItemID KAknsIIDQsnBgAreaMainMp =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainMp };

// Do not use these two directly, they are just placeholders
static const TAknsItemID KAknsIIDQsnBgAreaMainFlat =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainFlat };

static const TAknsItemID KAknsIIDQsnBgAreaMainSmall =
    { EAknsMajorSkin, EAknsMinorQsnBgAreaMainSmall };


// Slice elements

static const TAknsItemID KAknsIIDQsnBgSlicePopup =
    { EAknsMajorSkin, EAknsMinorQsnBgSlicePopup};

static const TAknsItemID KAknsIIDQsnBgSlicePinb =
    { EAknsMajorSkin, EAknsMinorQsnBgSlicePinb };

static const TAknsItemID KAknsIIDQsnBgSliceFswap =
    { EAknsMajorSkin, EAknsMinorQsnBgSliceFswap };

// Wallpaper

static const TAknsItemID KAknsIIDWallpaper =
    { EAknsMajorSkin, EAknsMinorWallpaper };

static const TAknsItemID KAknsIIDQgnGrafIdleFade =
    { EAknsMajorSkin, EAknsMinorQgnGrafIdleFade };

static const TAknsItemID KAknsIIDQgnGrafDimWipeLscLeft =
    { EAknsMajorSkin, EAknsMinorQgnGrafDimWipeLscLeft };
// Volume levels

static const TAknsItemID KAknsIIDQsnCpVolumeOn =
    { EAknsMajorSkin, EAknsMinorQsnCpVolumeOn };

static const TAknsItemID KAknsIIDQsnCpVolumeOff =
    { EAknsMajorSkin, EAknsMinorQsnCpVolumeOff };

// List column background

static const TAknsItemID KAknsIIDQsnBgColumn0 =
    { EAknsMajorSkin, EAknsMinorQsnBgColumn0 };

static const TAknsItemID KAknsIIDQsnBgColumnA =
    { EAknsMajorSkin, EAknsMinorQsnBgColumnA };

static const TAknsItemID KAknsIIDQsnBgColumnAB =
    { EAknsMajorSkin, EAknsMinorQsnBgColumnAB };

static const TAknsItemID KAknsIIDQsnBgColumnC0 =
    { EAknsMajorSkin, EAknsMinorQsnBgColumnC0 };

static const TAknsItemID KAknsIIDQsnBgColumnCA =
    { EAknsMajorSkin, EAknsMinorQsnBgColumnCA };

static const TAknsItemID KAknsIIDQsnBgColumnCAB =
    { EAknsMajorSkin, EAknsMinorQsnBgColumnCAB };

// List bottom elements

static const TAknsItemID KAknsIIDQsnBgSliceList0 =
    { EAknsMajorSkin, EAknsMinorQsnBgSliceList0 };

static const TAknsItemID KAknsIIDQsnBgSliceListA =
    { EAknsMajorSkin, EAknsMinorQsnBgSliceListA };

static const TAknsItemID KAknsIIDQsnBgSliceListAB =
    { EAknsMajorSkin, EAknsMinorQsnBgSliceListAB };

// Setting item list - option item frame

static const TAknsItemID KAknsIIDQsnFrSetOpt =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOpt };

static const TAknsItemID KAknsIIDQsnFrSetOptCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptCornerTl };

static const TAknsItemID KAknsIIDQsnFrSetOptCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptCornerTr };

static const TAknsItemID KAknsIIDQsnFrSetOptCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptCornerBl };

static const TAknsItemID KAknsIIDQsnFrSetOptCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptCornerBr };

static const TAknsItemID KAknsIIDQsnFrSetOptSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptSideT };

static const TAknsItemID KAknsIIDQsnFrSetOptSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptSideB };

static const TAknsItemID KAknsIIDQsnFrSetOptSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptSideL };

static const TAknsItemID KAknsIIDQsnFrSetOptSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptSideR };

static const TAknsItemID KAknsIIDQsnFrSetOptCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptCenter };

// Setting item list - focused option item frame

static const TAknsItemID KAknsIIDQsnFrSetOptFoc =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptFoc };

static const TAknsItemID KAknsIIDQsnFrSetOptFocCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptFocCornerTl };

static const TAknsItemID KAknsIIDQsnFrSetOptFocCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptFocCornerTr };

static const TAknsItemID KAknsIIDQsnFrSetOptFocCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptFocCornerBl };

static const TAknsItemID KAknsIIDQsnFrSetOptFocCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptFocCornerBr };

static const TAknsItemID KAknsIIDQsnFrSetOptFocSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptFocSideT };

static const TAknsItemID KAknsIIDQsnFrSetOptFocSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptFocSideB };

static const TAknsItemID KAknsIIDQsnFrSetOptFocSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptFocSideL };

static const TAknsItemID KAknsIIDQsnFrSetOptFocSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptFocSideR };

static const TAknsItemID KAknsIIDQsnFrSetOptFocCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrSetOptFocCenter };

// Setting list volume graphics

static const TAknsItemID KAknsIIDQsnCpSetListVolumeOn =
    { EAknsMajorSkin, EAknsMinorQsnCpSetListVolumeOn };

static const TAknsItemID KAknsIIDQsnCpSetListVolumeOff =
    { EAknsMajorSkin, EAknsMinorQsnCpSetListVolumeOff };

// Setting list slider graphics

static const TAknsItemID KAknsIIDQgnIndiSliderSet =
    { EAknsMajorSkin, EAknsMinorQgnIndiSliderSet };

// General list highlight frame

static const TAknsItemID KAknsIIDQsnFrList =
    { EAknsMajorSkin, EAknsMinorQsnFrList };

static const TAknsItemID KAknsIIDQsnFrListCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrListCornerTl };

static const TAknsItemID KAknsIIDQsnFrListCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrListCornerTr };

static const TAknsItemID KAknsIIDQsnFrListCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrListCornerBl };

static const TAknsItemID KAknsIIDQsnFrListCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrListCornerBr };

static const TAknsItemID KAknsIIDQsnFrListSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrListSideT };

static const TAknsItemID KAknsIIDQsnFrListSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrListSideB };

static const TAknsItemID KAknsIIDQsnFrListSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrListSideL };

static const TAknsItemID KAknsIIDQsnFrListSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrListSideR };

static const TAknsItemID KAknsIIDQsnFrListCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrListCenter };

// General grid highlight frame

static const TAknsItemID KAknsIIDQsnFrGrid =
    { EAknsMajorSkin, EAknsMinorQsnFrGrid };

static const TAknsItemID KAknsIIDQsnFrGridCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrGridCornerTl };

static const TAknsItemID KAknsIIDQsnFrGridCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrGridCornerTr };

static const TAknsItemID KAknsIIDQsnFrGridCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrGridCornerBl };

static const TAknsItemID KAknsIIDQsnFrGridCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrGridCornerBr };

static const TAknsItemID KAknsIIDQsnFrGridSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrGridSideT };

static const TAknsItemID KAknsIIDQsnFrGridSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrGridSideB };

static const TAknsItemID KAknsIIDQsnFrGridSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrGridSideL };

static const TAknsItemID KAknsIIDQsnFrGridSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrGridSideR };

static const TAknsItemID KAknsIIDQsnFrGridCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrGridCenter };

// General input field border frame

static const TAknsItemID KAknsIIDQsnFrInput =
    { EAknsMajorSkin, EAknsMinorQsnFrInput };

static const TAknsItemID KAknsIIDQsnFrInputCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCornerTl };

static const TAknsItemID KAknsIIDQsnFrInputCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCornerTr };

static const TAknsItemID KAknsIIDQsnFrInputCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCornerBl };

static const TAknsItemID KAknsIIDQsnFrInputCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCornerBr };

static const TAknsItemID KAknsIIDQsnFrInputSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrInputSideT };

static const TAknsItemID KAknsIIDQsnFrInputSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrInputSideB };

static const TAknsItemID KAknsIIDQsnFrInputSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrInputSideL };

static const TAknsItemID KAknsIIDQsnFrInputSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrInputSideR };

static const TAknsItemID KAknsIIDQsnFrInputCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCenter };

// Settings volume graphics

static const TAknsItemID KAknsIIDQsnCpSetVolumeOn =
    { EAknsMajorSkin, EAknsMinorQsnCpSetVolumeOn };

static const TAknsItemID KAknsIIDQsnCpSetVolumeOff =
    { EAknsMajorSkin, EAknsMinorQsnCpSetVolumeOff };

// Slider editing graphics

static const TAknsItemID KAknsIIDQgnIndiSliderEdit =
    { EAknsMajorSkin, EAknsMinorQgnIndiSliderEdit };

// Scrollbars

static const TAknsItemID KAknsIIDQsnCpScrollBgTop =
    { EAknsMajorSkin, EAknsMinorQsnCpScrollBgTop };

static const TAknsItemID KAknsIIDQsnCpScrollBgMiddle =
    { EAknsMajorSkin, EAknsMinorQsnCpScrollBgMiddle };

static const TAknsItemID KAknsIIDQsnCpScrollBgBottom =
    { EAknsMajorSkin, EAknsMinorQsnCpScrollBgBottom };

static const TAknsItemID KAknsIIDQsnCpScrollHandleBgTop =
    { EAknsMajorSkin, EAknsMinorQsnCpScrollHandleBgTop };

static const TAknsItemID KAknsIIDQsnCpScrollHandleBgMiddle =
    { EAknsMajorSkin, EAknsMinorQsnCpScrollHandleBgMiddle };

static const TAknsItemID KAknsIIDQsnCpScrollHandleBgBottom =
    { EAknsMajorSkin, EAknsMinorQsnCpScrollHandleBgBottom };

static const TAknsItemID KAknsIIDQsnCpScrollHandleTop =
    { EAknsMajorSkin, EAknsMinorQsnCpScrollHandleTop };

static const TAknsItemID KAknsIIDQsnCpScrollHandleMiddle =
    { EAknsMajorSkin, EAknsMinorQsnCpScrollHandleMiddle };

static const TAknsItemID KAknsIIDQsnCpScrollHandleBottom =
    { EAknsMajorSkin, EAknsMinorQsnCpScrollHandleBottom };

// Popup generics

static const TAknsItemID KAknsIIDQsnBgScreenDimming =
    { EAknsMajorSkin, EAknsMinorQsnBgScreenDimming };

static const TAknsItemID KAknsIIDQsnBgPopupBackground =
    { EAknsMajorSkin, EAknsMinorQsnBgPopupBackground };

// General popup frame

static const TAknsItemID KAknsIIDQsnFrPopup =
    { EAknsMajorSkin, EAknsMinorQsnFrPopup };

static const TAknsItemID KAknsIIDQsnFrPopupCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupCornerTl };

static const TAknsItemID KAknsIIDQsnFrPopupCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupCornerTr };

static const TAknsItemID KAknsIIDQsnFrPopupCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupCornerBl };

static const TAknsItemID KAknsIIDQsnFrPopupCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupCornerBr };

static const TAknsItemID KAknsIIDQsnFrPopupSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSideT };

static const TAknsItemID KAknsIIDQsnFrPopupSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSideB };

static const TAknsItemID KAknsIIDQsnFrPopupSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSideL };

static const TAknsItemID KAknsIIDQsnFrPopupSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSideR };

static const TAknsItemID KAknsIIDQsnFrPopupCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupCenter };

// Specific popup centers

static const TAknsItemID KAknsIIDQsnFrPopupCenterMenu =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupCenterMenu };

static const TAknsItemID KAknsIIDQsnFrPopupCenterSubmenu =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupCenterSubmenu };

static const TAknsItemID KAknsIIDQsnFrPopupCenterNote =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupCenterNote };

static const TAknsItemID KAknsIIDQsnFrPopupCenterQuery =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupCenterQuery };

static const TAknsItemID KAknsIIDQsnFrPopupCenterFind =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupCenterFind };

static const TAknsItemID KAknsIIDQsnFrPopupCenterSnote =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupCenterSnote };

static const TAknsItemID KAknsIIDQsnFrPopupCenterFswap =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupCenterFswap };

// Submenu frame

static const TAknsItemID KAknsIIDQsnFrPopupSub =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSub };

static const TAknsItemID KAknsIIDQsnFrPopupSubCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSubCornerTl };

static const TAknsItemID KAknsIIDQsnFrPopupSubCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSubCornerTr };

static const TAknsItemID KAknsIIDQsnFrPopupSubCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSubCornerBl };

static const TAknsItemID KAknsIIDQsnFrPopupSubCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSubCornerBr };

static const TAknsItemID KAknsIIDQsnFrPopupSubSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSubSideT };

static const TAknsItemID KAknsIIDQsnFrPopupSubSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSubSideB };

static const TAknsItemID KAknsIIDQsnFrPopupSubSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSubSideL };

static const TAknsItemID KAknsIIDQsnFrPopupSubSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupSubSideR };

// Popup heading frame

static const TAknsItemID KAknsIIDQsnFrPopupHeading =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupHeading };

static const TAknsItemID KAknsIIDQsnFrPopupHeadingCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupHeadingCornerTl };

static const TAknsItemID KAknsIIDQsnFrPopupHeadingCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupHeadingCornerTr };

static const TAknsItemID KAknsIIDQsnFrPopupHeadingCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupHeadingCornerBl };

static const TAknsItemID KAknsIIDQsnFrPopupHeadingCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupHeadingCornerBr };

static const TAknsItemID KAknsIIDQsnFrPopupHeadingSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupHeadingSideT };

static const TAknsItemID KAknsIIDQsnFrPopupHeadingSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupHeadingSideB };

static const TAknsItemID KAknsIIDQsnFrPopupHeadingSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupHeadingSideL };

static const TAknsItemID KAknsIIDQsnFrPopupHeadingSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupHeadingSideR };

static const TAknsItemID KAknsIIDQsnFrPopupHeadingCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupHeadingCenter };

// Fast application swapping

static const TAknsItemID KAknsIIDQsnBgFswapEnd =
    { EAknsMajorSkin, EAknsMinorQsnBgFswapEnd };


// Flat status pane frame
static const TAknsItemID KAknsIIDQsnFrStatusFlat =
    { EAknsMajorSkin, EAknsMinorQsnFrStatusFlat };

static const TAknsItemID KAknsIIDQsnFrStatusFlatCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrStatusFlatCornerTl };

static const TAknsItemID KAknsIIDQsnFrStatusFlatCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrStatusFlatCornerTr };

static const TAknsItemID KAknsIIDQsnFrStatusFlatCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrStatusFlatCornerBl };

static const TAknsItemID KAknsIIDQsnFrStatusFlatCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrStatusFlatCornerBr  };

static const TAknsItemID KAknsIIDQsnFrStatusFlatSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrStatusFlatSideT };

static const TAknsItemID KAknsIIDQsnFrStatusFlatSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrStatusFlatSideB  };

static const TAknsItemID KAknsIIDQsnFrStatusFlatSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrStatusFlatSideL };

static const TAknsItemID KAknsIIDQsnFrStatusFlatSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrStatusFlatSideR };

static const TAknsItemID KAknsIIDQsnFrStatusFlatCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrStatusFlatCenter };

// toolbar buttons

static const TAknsItemID KAknsIIDQsnFrButtonTb =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTb };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerTl };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerTr };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerBl };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerBr };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideT };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideB };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideL };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideR };

static const TAknsItemID KAknsIIDQsnFrButtonTbCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCenter };


static const TAknsItemID KAknsIIDQsnFrButtonTbInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerTlInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerTlInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerTrInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerTrInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerBlInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerBlInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerBrInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerBrInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideTInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideTInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideBInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideBInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideLInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideLInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideRInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideRInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTbCenterInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCenterInactive };


static const TAknsItemID KAknsIIDQsnFrButtonTbMode =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbMode };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerTlMode =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerTlMode };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerTrMode =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerTrMode };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerBlMode =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerBlMode };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerBrMode =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerBrMode };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideTMode =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideTMode };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideBMode =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideBMode };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideLMode =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideLMode };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideRMode =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideRMode };

static const TAknsItemID KAknsIIDQsnFrButtonTbCenterMode =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCenterMode };


static const TAknsItemID KAknsIIDQsnFrButtonTbPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerTlPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerTlPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerTrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerTrPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerBlPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerBlPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTbCornerBrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCornerBrPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideTPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideTPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideBPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideBPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideLPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideLPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTbSideRPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbSideRPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTbCenterPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTbCenterPressed };


static const TAknsItemID KAknsIIDQsnFrButtonInactive          =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactive };

static const TAknsItemID KAknsIIDQsnFrButtonCornerTlInactive  =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerTlInactive };

static const TAknsItemID KAknsIIDQsnFrButtonCornerTrInactive  =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerTrInactive };

static const TAknsItemID KAknsIIDQsnFrButtonCornerBlInactive  =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerBlInactive };

static const TAknsItemID KAknsIIDQsnFrButtonCornerBrInactive  =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerBrInactive };

static const TAknsItemID KAknsIIDQsnFrButtonSideTInactive     =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideTInactive };

static const TAknsItemID KAknsIIDQsnFrButtonSideBInactive     =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideBInactive };

static const TAknsItemID KAknsIIDQsnFrButtonSideLInactive     =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideLInactive };

static const TAknsItemID KAknsIIDQsnFrButtonSideRInactive     =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideRInactive };

static const TAknsItemID KAknsIIDQsnFrButtonCenterInactive    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCenterInactive };


static const TAknsItemID KAknsIIDQsnFrButtonNormal            =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormal };

static const TAknsItemID KAknsIIDQsnFrButtonCornerTlNormal    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerTlNormal };

static const TAknsItemID KAknsIIDQsnFrButtonCornerTrNormal    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerTrNormal };

static const TAknsItemID KAknsIIDQsnFrButtonCornerBlNormal    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerBlNormal };

static const TAknsItemID KAknsIIDQsnFrButtonCornerBrNormal    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerBrNormal };

static const TAknsItemID KAknsIIDQsnFrButtonSideTNormal       =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideTNormal };

static const TAknsItemID KAknsIIDQsnFrButtonSideBNormal       =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideBNormal };

static const TAknsItemID KAknsIIDQsnFrButtonSideLNormal       =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideLNormal };

static const TAknsItemID KAknsIIDQsnFrButtonSideRNormal       =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideRNormal };

static const TAknsItemID KAknsIIDQsnFrButtonCenterNormal      =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCenterNormal };


static const TAknsItemID KAknsIIDQsnFrButtonPressed           =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressed };

static const TAknsItemID KAknsIIDQsnFrButtonCornerTlPressed   =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerTlPressed };

static const TAknsItemID KAknsIIDQsnFrButtonCornerTrPressed   =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerTrPressed };

static const TAknsItemID KAknsIIDQsnFrButtonCornerBlPressed   =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerBlPressed };

static const TAknsItemID KAknsIIDQsnFrButtonCornerBrPressed   =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerBrPressed };

static const TAknsItemID KAknsIIDQsnFrButtonSideTPressed      =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideTPressed  };

static const TAknsItemID KAknsIIDQsnFrButtonSideBPressed      =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideBPressed };

static const TAknsItemID KAknsIIDQsnFrButtonSideLPressed      =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideLPressed };

static const TAknsItemID KAknsIIDQsnFrButtonSideRPressed      =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideRPressed };

static const TAknsItemID KAknsIIDQsnFrButtonCenterPressed     =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCenterPressed };

// touch pane buttons
static const TAknsItemID KAknsIIDQsnFrButtonTpNormal          =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpNormal };

static const TAknsItemID KAknsIIDQsnFrButtonTpCornerTlNormal  =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCornerTlNormal };

static const TAknsItemID KAknsIIDQsnFrButtonTpCornerTrNormal  =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCornerTrNormal };

static const TAknsItemID KAknsIIDQsnFrButtonTpCornerBlNormal  =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCornerBlNormal };

static const TAknsItemID KAknsIIDQsnFrButtonTpCornerBrNormal  =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCornerBrNormal };

static const TAknsItemID KAknsIIDQsnFrButtonTpSideTNormal     =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpSideTNormal };

static const TAknsItemID KAknsIIDQsnFrButtonTpSideBNormal     =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpSideBNormal };

static const TAknsItemID KAknsIIDQsnFrButtonTpSideLNormal     =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpSideLNormal };

static const TAknsItemID KAknsIIDQsnFrButtonTpSideRNormal     =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpSideRNormal };

static const TAknsItemID KAknsIIDQsnFrButtonTpCenterNormal    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCenterNormal };


static const TAknsItemID KAknsIIDQsnFrButtonTpPressed         =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTpCornerTlPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCornerTlPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTpCornerTrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCornerTrPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTpCornerBlPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCornerBlPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTpCornerBrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCornerBrPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTpSideTPressed    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpSideTPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTpSideBPressed    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpSideBPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTpSideLPressed    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpSideLPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTpSideRPressed    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpSideRPressed };

static const TAknsItemID KAknsIIDQsnFrButtonTpCenterPressed   =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCenterPressed };


static const TAknsItemID KAknsIIDQsnFrButtonTpInactive        =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTpCornerTlInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCornerTlInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTpCornerTrInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCornerTrInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTpCornerBlInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCornerBlInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTpCornerBrInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCornerBrInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTpSideTInactive   =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpSideTInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTpSideBInactive   =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpSideBInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTpSideLInactive   =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpSideLInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTpSideRInactive   =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpSideRInactive };

static const TAknsItemID KAknsIIDQsnFrButtonTpCenterInactive  =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonTpCenterInactive };



static const TAknsItemID KAknsIIDQgnFrSctrlButton        =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButton              };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCornerTl     =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCornerTl      };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCornerTr     =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCornerTr      };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCornerBl     =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCornerBl      };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCornerBr     =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCornerBr      };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonSideT        =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonSideT         };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonSideB        =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonSideB         };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonSideL        =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonSideL         };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonSideR        =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonSideR         };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCenter       =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCenter        };



static const TAknsItemID KAknsIIDQgnFrSctrlSkButton           =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButton            };

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonCornerTl   =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonCornerTl    };

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonCornerTr   =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonCornerTr    };

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonCornerBl   =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonCornerBl    };

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonCornerBr   =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonCornerBr    };

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonSideT      =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonSideT       };

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonSideB      =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonSideB       };

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonSideL      =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonSideL       };

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonSideR      =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonSideR       };

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonCenter     =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonCenter      };


static const TAknsItemID KAknsIIDQsnFrButtonLatchdown         =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonLatchdown          };

static const TAknsItemID KAknsIIDQsnFrButtonCornerTlLatchdown =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerTlLatchdown  };

static const TAknsItemID KAknsIIDQsnFrButtonCornerTrLatchdown =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerTrLatchdown  };

static const TAknsItemID KAknsIIDQsnFrButtonCornerBlLatchdown =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerBlLatchdown  };

static const TAknsItemID KAknsIIDQsnFrButtonCornerBrLatchdown =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCornerBrLatchdown  };

static const TAknsItemID KAknsIIDQsnFrButtonSideTLatchdown    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideTLatchdown     };

static const TAknsItemID KAknsIIDQsnFrButtonSideBLatchdown    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideBLatchdown     };

static const TAknsItemID KAknsIIDQsnFrButtonSideLLatchdown    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideLLatchdown     };

static const TAknsItemID KAknsIIDQsnFrButtonSideRLatchdown    =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonSideRLatchdown     };

static const TAknsItemID KAknsIIDQsnFrButtonCenterLatchdown   =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonCenterLatchdown    };



static const TAknsItemID KAknsIIDQsnFrOrgBg         =
    { EAknsMajorSkin, EAknsMinorQsnFrOrgBg  };

static const TAknsItemID KAknsIIDQsnFrOrgBgCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrOrgBgCornerTl  };

static const TAknsItemID KAknsIIDQsnFrOrgBgCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrOrgBgCornerTr  };

static const TAknsItemID KAknsIIDQsnFrOrgBgCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrOrgBgCornerBl  };

static const TAknsItemID KAknsIIDQsnFrOrgBgCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrOrgBgCornerBr  };

static const TAknsItemID KAknsIIDQsnFrOrgBgSideT    =
    { EAknsMajorSkin, EAknsMinorQsnFrOrgBgSideT     };

static const TAknsItemID KAknsIIDQsnFrOrgBgSideB    =
    { EAknsMajorSkin, EAknsMinorQsnFrOrgBgSideB     };

static const TAknsItemID KAknsIIDQsnFrOrgBgSideL    =
    { EAknsMajorSkin, EAknsMinorQsnFrOrgBgSideL     };

static const TAknsItemID KAknsIIDQsnFrOrgBgSideR    =
    { EAknsMajorSkin, EAknsMinorQsnFrOrgBgSideR     };

static const TAknsItemID KAknsIIDQsnFrOrgBgCenter   =
    { EAknsMajorSkin, EAknsMinorQsnFrOrgBgCenter    };

// This frame is deprecated.
static const TAknsItemID KAknsIIDQgnFrSctrlButtonLatchdown         =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonLatchdown  };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCornerTlLatchdown =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCornerTlLatchdown  };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCornerTrLatchdown =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCornerTrLatchdown  };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCornerBlLatchdown =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCornerBlLatchdown  };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCornerBrLatchdown =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCornerBrLatchdown  };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonSideTLatchdown    =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonSideTLatchdown     };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonSideBLatchdown    =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonSideBLatchdown     };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonSideLLatchdown    =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonSideLLatchdown     };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonSideRLatchdown    =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonSideRLatchdown     };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCenterLatchdown   =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCenterLatchdown    };



static const TAknsItemID KAknsIIDQgnFrSctrlButtonPressed         =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonPressed  };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCornerTlPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCornerTlPressed  };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCornerTrPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCornerTrPressed  };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCornerBlPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCornerBlPressed  };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCornerBrPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCornerBrPressed  };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonSideTPressed    =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonSideTPressed     };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonSideBPressed    =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonSideBPressed     };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonSideLPressed    =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonSideLPressed     };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonSideRPressed    =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonSideRPressed     };

static const TAknsItemID KAknsIIDQgnFrSctrlButtonCenterPressed   =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlButtonCenterPressed    };

// Input character preview frame.
static const TAknsItemID KAknsIIDQsnFrInputCharPreview         =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCharPreview  };

static const TAknsItemID KAknsIIDQsnFrInputCharPreviewCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCharPreviewCornerTl  };

static const TAknsItemID KAknsIIDQsnFrInputCharPreviewCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCharPreviewCornerTr  };

static const TAknsItemID KAknsIIDQsnFrInputCharPreviewCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCharPreviewCornerBl  };

static const TAknsItemID KAknsIIDQsnFrInputCharPreviewCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCharPreviewCornerBr  };

static const TAknsItemID KAknsIIDQsnFrInputCharPreviewSideT    =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCharPreviewSideT     };

static const TAknsItemID KAknsIIDQsnFrInputCharPreviewSideB    =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCharPreviewSideB     };

static const TAknsItemID KAknsIIDQsnFrInputCharPreviewSideL    =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCharPreviewSideL     };

static const TAknsItemID KAknsIIDQsnFrInputCharPreviewSideR    =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCharPreviewSideR     };

static const TAknsItemID KAknsIIDQsnFrInputCharPreviewCenter   =
    { EAknsMajorSkin, EAknsMinorQsnFrInputCharPreviewCenter    };


// Colours

/**
* Component color group.
*
* @since 2.0
*
* @deprecated Since release 2.8, use specific color groups instead.
*/
static const TAknsItemID KAknsIIDQsnComponentColors =
    { EAknsMajorSkin, EAknsMinorQsnComponentColors };

/**
* Enumeration for values in QsnComponentColors color table.
*
* @since 2.0
*
* @deprecated Since release 2.8, use specific color groups instead.
*/
enum TAknsQsnComponentColorsIndex
    {
    EAknsCIQsnComponentColorsCG1    = 0,
    EAknsCIQsnComponentColorsCG2    = 1,
    EAknsCIQsnComponentColorsCG3    = 2,
    EAknsCIQsnComponentColorsCG4    = 3,
    EAknsCIQsnComponentColorsCG5    = 4,
    EAknsCIQsnComponentColorsCG6a   = 5,
    EAknsCIQsnComponentColorsCG6b   = 6,
    EAknsCIQsnComponentColorsCG7    = 7,
    EAknsCIQsnComponentColorsCG8    = 8,
    EAknsCIQsnComponentColorsCG9    = 9,
    EAknsCIQsnComponentColorsCG10   = 10,
    EAknsCIQsnComponentColorsCG11   = 11,
    EAknsCIQsnComponentColorsCG12   = 12,
    EAknsCIQsnComponentColorsCG13   = 13,
    EAknsCIQsnComponentColorsCG14   = 14,
    EAknsCIQsnComponentColorsCG15   = 15,
    EAknsCIQsnComponentColorsCG16   = 16,
    EAknsCIQsnComponentColorsCG17   = 17,
    EAknsCIQsnComponentColorsCG18   = 18,
    EAknsCIQsnComponentColorsCG19   = 19,
    EAknsCIQsnComponentColorsCG20   = 20,
    EAknsCIQsnComponentColorsCG21   = 21,
    EAknsCIQsnComponentColorsCG22   = 22,
    EAknsCIQsnComponentColorsCG23   = 23,
    EAknsCIQsnComponentColorsCG24   = 24
    };

/**
* @deprecated Since release 2.8, use color groups instead.
*/
static const TAknsItemID KAknsIIDQsnComponentColorBmpCG1 =
    { EAknsMajorSkin, EAknsMinorQsnComponentColorBmpCG1 };

/**
* @deprecated Since release 2.8, use color groups instead.
*/
static const TAknsItemID KAknsIIDQsnComponentColorBmpCG2 =
    { EAknsMajorSkin, EAknsMinorQsnComponentColorBmpCG2 };

/**
* @deprecated Since release 2.8, use color groups instead.
*/
static const TAknsItemID KAknsIIDQsnComponentColorBmpCG3 =
    { EAknsMajorSkin, EAknsMinorQsnComponentColorBmpCG3 };

/**
* @deprecated Since release 2.8, use color groups instead.
*/
static const TAknsItemID KAknsIIDQsnComponentColorBmpCG4 =
    { EAknsMajorSkin, EAknsMinorQsnComponentColorBmpCG4 };

/**
* @deprecated Since release 2.8, use color groups instead.
*/
static const TAknsItemID KAknsIIDQsnComponentColorBmpCG5 =
    { EAknsMajorSkin, EAknsMinorQsnComponentColorBmpCG5 };

/**
* @deprecated Since release 2.8, use color groups instead.
*/
static const TAknsItemID KAknsIIDQsnComponentColorBmpCG6a =
    { EAknsMajorSkin, EAknsMinorQsnComponentColorBmpCG6a };

/**
* @deprecated Since release 2.8, use color groups instead.
*/
static const TAknsItemID KAknsIIDQsnComponentColorBmpCG6b =
    { EAknsMajorSkin, EAknsMinorQsnComponentColorBmpCG6b };

/**
* Scroll indicator color group.
*
* @since 2.0
*/
static const TAknsItemID KAknsIIDQsnScrollColors =
    { EAknsMajorSkin, EAknsMinorQsnScrollColors };

/**
* Icon color group.
*
* @since 2.8
*/
static const TAknsItemID KAknsIIDQsnIconColors =
    { EAknsMajorSkin, EAknsMinorQsnIconColors };

/**
* Enumeration for values in QsnIconColors color table.
*
* @since 2.8
*/
enum TAknsQsnIconColorsIndex
    {
    // icon #1	main area; idle	status indicators	#215
    EAknsCIQsnIconColorsCG1    = 0,
    // icon #2	status area	universal indicator pane icons	#215
    EAknsCIQsnIconColorsCG2    = 1,
    // icon #3	status area	reception off icon	#215
    EAknsCIQsnIconColorsCG3    = 2,
    // icon #4	navi pane	editing state icons	#0
    EAknsCIQsnIconColorsCG4    = 3,
    // icon #5	navi pane	signal iconpacket data indications	#0
    EAknsCIQsnIconColorsCG5    = 4,
    // icon #6	navi pane	battery icon	#0
    EAknsCIQsnIconColorsCG6    = 5,
    // icon #7	navi pane	other navi pane icons (e.g. tab 1 icons)	#0
    EAknsCIQsnIconColorsCG7    = 6,
    // icon #8	active tab	active tab icon colour	#215
    EAknsCIQsnIconColorsCG8    = 7,
    // icon #9	passive tab	passive tab icon colour	#243
    EAknsCIQsnIconColorsCG9    = 8,
    // icon #10	popup window	query editing state icons	#210
    EAknsCIQsnIconColorsCG10   = 9,
    // icon #11	call graphics	call status icons	#215
    EAknsCIQsnIconColorsCG11   = 10,
    // icon #12
    EAknsCIQsnIconColorsCG12   = 11,
    // icon #13	main area	additional list icons	#215
    EAknsCIQsnIconColorsCG13   = 12,
    // icon #14	settings popup list	checkbox, radio button	#215
    EAknsCIQsnIconColorsCG14   = 13,
    // icon #15	form popup list	checkbox, radio button	#215
    EAknsCIQsnIconColorsCG15   = 14,
    // icon #16	list highlight	additional list iconsform checkbox, radio button	#215
    EAknsCIQsnIconColorsCG16   = 15,
    // icon #17	grid highlight	additional list iconsgms images (?)	#215
    EAknsCIQsnIconColorsCG17   = 16,
    // icon #18	setting list highlight	checkbox, radio button	#0
    EAknsCIQsnIconColorsCG18   = 17,
    // icon #19	calendar views	additional list icons	#215
    EAknsCIQsnIconColorsCG19   = 18,
    // icon #20	stacon area	universal indicator pane icons	#0
    EAknsCIQsnIconColorsCG20   = 19,
    // icon #21	stacon area	reception off icon	#0
    EAknsCIQsnIconColorsCG21   = 20,
    // icon #22	stacon navi pane	editing state icons	#0
    EAknsCIQsnIconColorsCG22   = 21,
    // icon #23	stacon navi pane	signal iconpacket data indications	#0
    EAknsCIQsnIconColorsCG23   = 22,
    // icon #24	stacon navi pane	battery icon	#0
    EAknsCIQsnIconColorsCG24   = 23,
    // icon #25	stacon navi pane	other navi pane icons (e.g. tab 1 icons)	#0
    EAknsCIQsnIconColorsCG25   = 24,
    // icon #26 music player main pane  function indicators #215
    EAknsCIQsnIconColorsCG26   = 25,
    // icon #27 control pane general  middle softkey icon
    EAknsCIQsnIconColorsCG27   = 26,
    // icon #28 control pane idle  middle softkey icon
    EAknsCIQsnIconColorsCG28   = 27,
    // icon #29 control pane idle  middle softkey icon
    EAknsCIQsnIconColorsCG29   = 28,
    // icon #30 Virtual ITU-T,Dialer, Compatibility mode, Adaptive search, Canvas application (Java),FS Query Spell Query  Function button icons
    EAknsCIQsnIconColorsCG30   = 29,
    // icon #31 Compatibility mode  Virtual rocker icons
    EAknsCIQsnIconColorsCG31   = 30,
    // icon #32 Radio mainpane  Virtual rocker normal icons
    EAknsCIQsnIconColorsCG32   = 31,
    // icon #33 Radio mainpane  Virtual rocker highlight icons
    EAknsCIQsnIconColorsCG33   = 32
    };

/**
* Text color group.
*
* @since 2.8
*/
static const TAknsItemID KAknsIIDQsnTextColors =
    { EAknsMajorSkin, EAknsMinorQsnTextColors };

/**
* Enumeration for values in QsnTextColors color table.
*
* @since 2.8
*/
enum TAknsQsnTextColorsIndex
    {
    // text #1	status area	title text	#215
    EAknsCIQsnTextColorsCG1    = 0,
    // text #2	navi pane	navi pane texts	#0
    EAknsCIQsnTextColorsCG2    = 1,
    // text #3	active tab	active tab text	#215
    EAknsCIQsnTextColorsCG3    = 2,
    // text #4	passive tab	passive tab text	#243
    EAknsCIQsnTextColorsCG4    = 3,
    // text #5	power save state	time/date power save text	#0
    EAknsCIQsnTextColorsCG5    = 4,
    // text #6	main area	main area texts	#215
    EAknsCIQsnTextColorsCG6    = 5,
    // text #7	settings popup list	settings list item text	#215
    EAknsCIQsnTextColorsCG7    = 6,
    // text #8	form popup listform input field	form list item textform data entry text	#215
    EAknsCIQsnTextColorsCG8    = 7,
    // text #9	application grid	unfocused application title texts 	#215
    EAknsCIQsnTextColorsCG9    = 8,
    // text #10	list highlight	list texts	#215
    EAknsCIQsnTextColorsCG10   = 9,
    // text #11	grid highlight	grid text 	#215
    EAknsCIQsnTextColorsCG11   = 10,
    // text #12	settings popup list highlight;settings list item value box	settings value item text	#0
    EAknsCIQsnTextColorsCG12   = 11,
    // text #13	control pane general	left softkey text	#215
    EAknsCIQsnTextColorsCG13   = 12,
    // text #14	control pane general	right softkey text	#215
    EAknsCIQsnTextColorsCG14   = 13,
    // text #15	control pane idle	left softkey text	#215
    EAknsCIQsnTextColorsCG15   = 14,
    // text #16 control pane idle	right softkey text	#215
    EAknsCIQsnTextColorsCG16   = 15,
    // text #17	control pane popup windows	left softkey text	#215
    EAknsCIQsnTextColorsCG17   = 16,
    // text #18	control pane popup windows	right softkey text	#215
    EAknsCIQsnTextColorsCG18   = 17,
    // text #19	popup windows	popup windows text	#215
    EAknsCIQsnTextColorsCG19   = 18,
    // text #20	submenu popup windows	submenu texts	#215
    EAknsCIQsnTextColorsCG20   = 19,
    // text #21	calendar month view	passive month day numbers	#221
    EAknsCIQsnTextColorsCG21   = 20,
    // text #22	calendar month viewcalendar day view	active month day numbersday view list items	#215
    EAknsCIQsnTextColorsCG22   = 21,
    // text #23	calendar month viewcalendar week view	day abbreviationshoursweek numbers	#215
    EAknsCIQsnTextColorsCG23   = 22,
    // text #24	cut/copy/paste highlight	copied text	#0
    EAknsCIQsnTextColorsCG24   = 23,
    // text #25	find pane	search string text	#215
    EAknsCIQsnTextColorsCG25   = 24,
    // text #26	settings input field	setting text entry	#215
    EAknsCIQsnTextColorsCG26   = 25,
    // text #27	query input field	query text entry	#215
    EAknsCIQsnTextColorsCG27   = 26,
    // text #28	power save mode	time/date shadow text	#215
    EAknsCIQsnTextColorsCG28   = 27,
    // text #29	calculator paper 	operator/operand	#215
    EAknsCIQsnTextColorsCG29   = 28,
    // text #30	calculator display	result	#210
    EAknsCIQsnTextColorsCG30   = 29,
    // text #31 calculator display	result shadow	#219
    EAknsCIQsnTextColorsCG31   = 30,
    // text #32	pinboard input field	item title/find string	#215
    EAknsCIQsnTextColorsCG32   = 31,
    // text #33	pinboard/list view	item title	#215
    EAknsCIQsnTextColorsCG33   = 32,
    // text #34	notepad	note text	#215
    EAknsCIQsnTextColorsCG34   = 33,
    // text #35 active idle text    #215
    EAknsCIQsnTextColorsCG35   = 34,
    // text #36 status area title text in idle #215
    EAknsCIQsnTextColorsCG36   = 35,
    // text #37 stacon area title text  #0
    EAknsCIQsnTextColorsCG37   = 36,
    // text #38 stacon area title text in idle #0
    EAknsCIQsnTextColorsCG38   = 37,
    // text #39 stacon area top softkey text    #0
    EAknsCIQsnTextColorsCG39   = 38,
    // text #40 stacon area bottom softkey text    #0
    EAknsCIQsnTextColorsCG40   = 39,
    // text #41 stacon area top softkey text in idle #0
    EAknsCIQsnTextColorsCG41   = 40,
    // text #42 stacon area bottom softkey text in idle #0
    EAknsCIQsnTextColorsCG42   = 41,
    // text #43 stacon navi pane text   #0
    EAknsCIQsnTextColorsCG43   = 42,
    // text #44 title text  music player title text #215
    EAknsCIQsnTextColorsCG44   = 43,
    // text #45 stacon title text  music player title text #0
    EAknsCIQsnTextColorsCG45   = 44,
    // text #46 music player control pane area  music player right softkey #215
    EAknsCIQsnTextColorsCG46   = 45,
    // text #47 music player control pane area  music player left softkey #215
    EAknsCIQsnTextColorsCG47   = 46,
    // text #48 stacon area  music player bottom softkey #0
    EAknsCIQsnTextColorsCG48   = 47,
    // text #49 stacon area  music player top softkey #0
    EAknsCIQsnTextColorsCG49   = 48,
    // text #50 main area  music player mainpane texts #215
    EAknsCIQsnTextColorsCG50   = 49,
    // text #51 call handling, call bubble texts #215
    EAknsCIQsnTextColorsCG51   = 50,
    // text #52 MIDP Main area	MIDP uneditable textbox	#221
    EAknsCIQsnTextColorsCG52   = 51,
    // text #53 MIDP form input field	MIDP uneditable textfield #221
    EAknsCIQsnTextColorsCG53   = 52,
    // Text #54	Main area	Cardinal points.	#215
    EAknsCIQsnTextColorsCG54   = 53,
    //Text #55	Preview popup window	Popup texts	#215
    EAknsCIQsnTextColorsCG55   = 54,
    //Text #56	Control pane general	Middle softkey text	#215
    EAknsCIQsnTextColorsCG56   = 55,
    //Text#57	Control pane idle	Middle softkey text	#215
    EAknsCIQsnTextColorsCG57   = 56,
    //Text#58	Control pane popup windows	Middle softkey text	#215
    EAknsCIQsnTextColorsCG58   = 57,
    //Text#59	VKB / HWR pop-up windows	VKB / HWR keypad button text	#215
    EAknsCIQsnTextColorsCG59   = 58,
    //Text#60	VKB / HWR pop-up windows	VKB / HWR input field	#215
    EAknsCIQsnTextColorsCG60   = 59,
    //Text#61	VKB pop-up window	VKB button text dimmed	#129
    EAknsCIQsnTextColorsCG61   = 60,
    //Text#62	VKB / HWR pop-up windows	VKB / HWR button text shadow	#0
    EAknsCIQsnTextColorsCG62   = 61,
    //Text#63   Universal Message Editor    Messaging touch buttons    #215
    EAknsCIQsnTextColorsCG63   = 62,
    //Text#64   Predicitve text input   Suggested text #87ACB2
    EAknsCIQsnTextColorsCG64   = 63,
    //Text#65   Virtual ITU-T, Adaptive search, FS Query, Spell Query    Function button texts Adaptive search texts FS and Spelly query texts  #496da2
    EAknsCIQsnTextColorsCG65   = 64,
    //Text#66   Adaptive search     Page indicator texts     #496da2
    EAknsCIQsnTextColorsCG66   = 65,
    //Text#67  Character counter (Fullscreen qwerty and Virtual ITU-T).    Character counter texts   #4b5879
    EAknsCIQsnTextColorsCG67   = 66,
    //Text#68  Fullscreen QWERTY, Small VirtualKeyBoard.    Keyprint texts.   #ffffff
    EAknsCIQsnTextColorsCG68   = 67,
    //Text#69  Control area, Pressed state for softkey texts. #445A72
    EAknsCIQsnTextColorsCG69   = 68,
    //Text#70  Camera, Outline colour of text. #ffffff
    EAknsCIQsnTextColorsCG70   = 69,
    //Text#71  Camera, Fill colour of text. #000000
    EAknsCIQsnTextColorsCG71   = 70,
    //Text#72  Camera, Outline colour of pressed text. #999999
    EAknsCIQsnTextColorsCG72   = 71,
    //Text#73  Camera, Fill colour of pressed text. #333333
    EAknsCIQsnTextColorsCG73   = 72,
    //Text#74  AKAASH Main area Visited web link text. #590061
    EAknsCIQsnTextColorsCG74   = 73,
    //Text#75  Homescreen widget text #ffffff
    EAknsCIQsnTextColorsCG75   = 74,
    //Text#76  Call handling Keylock texts. #ffffff
    EAknsCIQsnTextColorsCG76   = 75,
    //Text#77  Teleport Taskswapper texts #4b5879
    EAknsCIQsnTextColorsCG77   = 76,
    //Text#78  Main area, Focused items without highlight. #9c3958
    EAknsCIQsnTextColorsCG78   = 77,
    //Text#79  Form input field, Items highlight. #9c3958
    EAknsCIQsnTextColorsCG79   = 78,
    //Text#80  AVKON Buttons, AVKON Button default texts. #4b5879
    EAknsCIQsnTextColorsCG80   = 79,
    //Text#81  Email, Email header texts. #4b5879
    EAknsCIQsnTextColorsCG81   = 80,
    //Text#82  Call handling, Answer-button text. #ffffff
    EAknsCIQsnTextColorsCG82   = 81,
    //Text#83  Call handling, Reject-button text. #ffffff
    EAknsCIQsnTextColorsCG83   = 82
    };

/**
* Line color group.
*
* @since 2.8
*/
static const TAknsItemID KAknsIIDQsnLineColors =
    { EAknsMajorSkin, EAknsMinorQsnLineColors };

/**
* Enumeration for values in QsnLineColors color table.
*
* @since 2.8
*/
enum TAknsQsnLineColorsIndex
    {
    // line #1	calendar day/week/month view	lines 	#215
    EAknsCIQsnLineColorsCG1    = 0,
    // line #2	calendar day/week/month view	lines 	#221
    EAknsCIQsnLineColorsCG2    = 1,
    // line #3	heading pane	heading pane separator line	#215
    EAknsCIQsnLineColorsCG3    = 2,
    // line #4	main pane	grid cell separator lines	#221
    EAknsCIQsnLineColorsCG4    = 3,
    // line #5	popup windows	grid cell separator lines	#221
    EAknsCIQsnLineColorsCG5    = 4,
    // line #6	lists	column separator lines	#215
    EAknsCIQsnLineColorsCG6    = 5,
    // line #7	setting list	column separator lines	#215
    EAknsCIQsnLineColorsCG7    = 6,
    // line #8	form	slider line 	#215
    EAknsCIQsnLineColorsCG8    = 7,
    // line #9	settings list	value item slider line	#215
    EAknsCIQsnLineColorsCG9    = 8,
    // line #10	opened settings list	value item slider line	#215
    EAknsCIQsnLineColorsCG10   = 9,
    // line #11	popup 	separator line in options menu	#221
    EAknsCIQsnLineColorsCG11   = 10,
    // line #12 main area  music player oscilloscope line and visualizer accent color #144
    EAknsCIQsnLineColorsCG12   = 11,
    // line #13 Calculator line color #35
    EAknsCIQsnLineColorsCG13   = 12,
    //line #14	HWR pop-up window	Guideline	#120
    EAknsCIQsnLineColorsCG14   = 13,
    //line #15	lists	Separator line for touch items	#333333
    EAknsCIQsnLineColorsCG15   = 14
    };

/**
* Miscellaneous color group.
*
* @since 2.8
*/
static const TAknsItemID KAknsIIDQsnOtherColors =
    { EAknsMajorSkin, EAknsMinorQsnOtherColors };

/**
* Enumeration for values in QsnOtherColors color table.
*
* @since 2.8
*/
enum TAknsQsnOtherColorsIndex
    {
    // other #1	calendar week view	public event	#35
    EAknsCIQsnOtherColorsCG1    = 0,
    // other #2	calendar week view	private event	#210
    EAknsCIQsnOtherColorsCG2    = 1,
    // other #3	calendar week view	not synchronized event	#35 dimmed
    EAknsCIQsnOtherColorsCG3    = 2,
    // other #4	calendar week view	2 or more events overlapping	#215
    EAknsCIQsnOtherColorsCG4    = 3,
    // other #5	calendar month view	event indication on focused month	#215
    EAknsCIQsnOtherColorsCG5    = 4,
    // other #6	calendar month view	event indication on unfocused month	#221
    EAknsCIQsnOtherColorsCG6    = 5,
    // other #7 music player mainpane  spectrum bar gradient top #0
    EAknsCIQsnOtherColorsCG7    = 6,
    // other #8 music player mainpane  spectrum bar gradient bottom RGB(0,70,183)
    EAknsCIQsnOtherColorsCG8    = 7,
    //other #9	VKB/HWR pop-up windows	Background color, HWR writing box frame	#193
    EAknsCIQsnOtherColorsCG9    = 8,
    // Other #10 Main area	eSWT Background color	#ecf2f2	eSWT backup colour
    EAknsCIQsnOtherColorsCG10   = 9,
    // Other #11 Status area	eSWT Title background color	#ecf2f2	eSWT backup colour
    EAknsCIQsnOtherColorsCG11   = 10,
    // Other #12 Main pane	eSWT Control border colour	#b6c9cf	eSWT backup colour
    EAknsCIQsnOtherColorsCG12   = 11,
    // Other #13 Main pane	eSWT List background colour	#ecf2f2	eSWT backup colour
    EAknsCIQsnOtherColorsCG13   = 12,
    // Other #14 Main pane	eSWT List highlight colour	#e4e5e6	eSWT backup colour
    EAknsCIQsnOtherColorsCG14   = 13,
    // Other #15 Main pane	eSWT List highlighted border colour #9c3958
    EAknsCIQsnOtherColorsCG15   = 14,
    // Other #16 HandWritingRecognition	Writing box frame text colour #ffffff
    EAknsCIQsnOtherColorsCG16   = 15,
    // Other #17 Main pane	Fade Black Map (0-255) 0
    EAknsCIQsnOtherColorsCG17   = 16,
    // Other #18 Main pane	Fade White Map (0-255) 255
    EAknsCIQsnOtherColorsCG18   = 17,
    // Other #19 Main pane	Screen dimming colour #6c8eB7
    EAknsCIQsnOtherColorsCG19   = 18,
    // Other #20 Hand Writing Recognition	Hand Writing trace text colour #ffffff
    EAknsCIQsnOtherColorsCG20   = 19,
    // Other #21 Main pane, Coverflow gradient colour. #f0f7f7
    EAknsCIQsnOtherColorsCG21   = 20,
    // Other #22 Email, Email header background. #f2f6f6
    EAknsCIQsnOtherColorsCG22   = 21
    };

/**
* Highlight color group.
*
* @since 2.8
*/
static const TAknsItemID KAknsIIDQsnHighlightColors =
    { EAknsMajorSkin, EAknsMinorQsnHighlightColors };

/**
* Enumeration for values in QsnHighlightColors color table.
*
* @since 2.8
*/
enum TAknsQsnHighlightColorsIndex
    {
    // highlight #1	link highlight 	browser link highlight colour; japanese fep predictive candidate indication;automatic find item indcation	#244
    EAknsCIQsnHighlightColorsCG1    = 0,
    // highlight #2	cut/copy/paste 	cut/copy/paste highlight	#210
    EAknsCIQsnHighlightColorsCG2    = 1,
    // highlight #3	link indication	link text and underline indication	#210
    EAknsCIQsnHighlightColorsCG3    = 2
    };

static const TAknsItemID KAknsIIDQsnParentColors =
    { EAknsMajorSkin, EAknsMinorQsnParentColors };

/**
* Enumeration for values in QsnParentColors color table.
*
* @par Notes:
* No client code should use these groups, they are reserved for
* the framework and skin package preparation tools.
*
* @since 2.8
*/
enum TAknsQsnParentColorsIndex
    {
    EAknsCIQsnParentColorsCG1    = 0,
    EAknsCIQsnParentColorsCG2    = 1,
    EAknsCIQsnParentColorsCG3    = 2,
    EAknsCIQsnParentColorsCG4    = 3,
    EAknsCIQsnParentColorsCG5    = 4,
    EAknsCIQsnParentColorsCG6    = 5,
    EAknsCIQsnParentColorsCG7    = 6,
    EAknsCIQsnParentColorsCG8    = 7,
    EAknsCIQsnParentColorsCG9    = 8,
    EAknsCIQsnParentColorsCG10   = 9,
    EAknsCIQsnParentColorsCG11   = 10,
    EAknsCIQsnParentColorsCG12   = 11,
    EAknsCIQsnParentColorsCG13   = 12,
    EAknsCIQsnParentColorsCG14   = 13,
    EAknsCIQsnParentColorsCG15   = 14,
    EAknsCIQsnParentColorsCG16   = 15,
    EAknsCIQsnParentColorsCG17   = 16,
    EAknsCIQsnParentColorsCG18   = 17,
    EAknsCIQsnParentColorsCG19   = 18,
    EAknsCIQsnParentColorsCG20   = 19,
    EAknsCIQsnParentColorsCG21   = 20,
    EAknsCIQsnParentColorsCG22   = 21,
    EAknsCIQsnParentColorsCG23   = 22,
    EAknsCIQsnParentColorsCG24   = 23,
    EAknsCIQsnParentColorsCG25   = 24,
    EAknsCIQsnParentColorsCG26   = 25,
    EAknsCIQsnParentColorsCG27   = 26,
    EAknsCIQsnParentColorsCG28   = 27,
    EAknsCIQsnParentColorsCG29   = 28
    };

// Analogue clock

static const TAknsItemID KAknsIIDQsnCpClockAnalogueFace1 =
    { EAknsMajorSkin, EAknsMinorQsnCpClockAnalogueFace1 };
static const TAknsItemID KAknsIIDQsnCpClockAnalogueFace1MaskIcon =
    { EAknsMajorSkin, EAknsMinorQsnCpClockAnalogueFace1MaskIcon };
static const TAknsItemID KAknsIIDQsnCpClockAnalogueFace1MaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockAnalogueFace1MaskSoft };

static const TAknsItemID KAknsIIDQsnCpClockAnalogueBorderNum =
    { EAknsMajorSkin, EAknsMinorQsnCpClockAnalogueBorderNum };

static const TAknsItemID KAknsIIDQsnCpClockAnalogueFace2 =
    { EAknsMajorSkin, EAknsMinorQsnCpClockAnalogueFace2 };
static const TAknsItemID KAknsIIDQsnCpClockAnalogueFace2MaskIcon =
    { EAknsMajorSkin, EAknsMinorQsnCpClockAnalogueFace2MaskIcon };
static const TAknsItemID KAknsIIDQsnCpClockAnalogueFace2MaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockAnalogueFace2MaskSoft };

static const TAknsItemID KAknsIIDQsnCpClockAnaloguePointerHour =
    { EAknsMajorSkin, EAknsMinorQsnCpClockAnaloguePointerHour };
static const TAknsItemID KAknsIIDQsnCpClockAnaloguePointerMinute =
    { EAknsMajorSkin, EAknsMinorQsnCpClockAnaloguePointerMinute };

// Obsolete digital clock graphics

static const TAknsItemID KAknsIIDQsnCpClockDigitalZero =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalZero };
static const TAknsItemID KAknsIIDQsnCpClockDigitalOne =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalOne };
static const TAknsItemID KAknsIIDQsnCpClockDigitalTwo =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalTwo };
static const TAknsItemID KAknsIIDQsnCpClockDigitalThree =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalThree };
static const TAknsItemID KAknsIIDQsnCpClockDigitalFour =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalFour };
static const TAknsItemID KAknsIIDQsnCpClockDigitalFive =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalFive };
static const TAknsItemID KAknsIIDQsnCpClockDigitalSix =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalSix };
static const TAknsItemID KAknsIIDQsnCpClockDigitalSeven =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalSeven };
static const TAknsItemID KAknsIIDQsnCpClockDigitalEight =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalEight };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNine =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNine };
static const TAknsItemID KAknsIIDQsnCpClockDigitalStop =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalStop };
static const TAknsItemID KAknsIIDQsnCpClockDigitalColon =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalColon };
static const TAknsItemID KAknsIIDQsnCpClockDigitalZeroMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalZeroMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalOneMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalOneMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalTwoMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalTwoMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalThreeMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalThreeMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalFourMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalFourMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalFiveMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalFiveMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalSixMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalSixMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalSevenMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalSevenMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalEightMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalEightMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNineMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNineMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalStopMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalStopMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalColonMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalColonMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalZeroMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalZeroMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalOneMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalOneMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalTwoMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalTwoMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalThreeMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalThreeMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalFourMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalFourMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalFiveMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalFiveMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalSixMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalSixMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalSevenMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalSevenMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalEightMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalEightMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNineMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNineMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalStopMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalStopMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalColonMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalColonMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhZero =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhZero };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhOne =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhOne };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhTwo =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhTwo };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhThree =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhThree };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhFour =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhFour };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhFive =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhFive };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhSix =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhSix };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhSeven =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhSeven };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhEight =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhEight };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNine =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNine };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhStop =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhStop };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhColon =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhColon };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhZeroMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhZeroMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhOneMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhOneMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhTwoMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhTwoMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhThreeMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhThreeMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhFourMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhFourMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhFiveMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhFiveMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhSixMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhSixMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhSevenMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhSevenMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhEightMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhEightMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNineMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNineMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhStopMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhStopMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhColonMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhColonMaskSoft };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhZeroMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhZeroMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhOneMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhOneMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhTwoMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhTwoMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhThreeMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhThreeMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhFourMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhFourMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhFiveMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhFiveMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhSixMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhSixMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhSevenMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhSevenMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhEightMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhEightMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNineMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNineMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhStopMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhStopMaskHard };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhColonMaskHard =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhColonMaskHard };

// New digital clock digits (softmasked with halo, and white shape on black bg)

static const TAknsItemID KAknsIIDQsnCpClockDigitalNewZero =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewZero };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewOne =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewOne };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewTwo =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewTwo };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewThree =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewThree };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewFour =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewFour };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewFive =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewFive };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewSix =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewSix };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewSeven =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewSeven };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewEight =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewEight };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewNine =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewNine };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewStop =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewStop };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewColon =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewColon };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewZeroShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewZeroShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewOneShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewOneShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewTwoShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewTwoShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewThreeShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewThreeShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewFourShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewFourShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewFiveShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewFiveShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewSixShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewSixShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewSevenShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewSevenShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewEightShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewEightShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewNineShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewNineShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewStopShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewStopShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalNewColonShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalNewColonShape };

// New Arabic-Indic digital clock digits (softmasked with halo, and white shape on black bg)

static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewZero =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewZero };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewOne =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewOne };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewTwo =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewTwo };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewThree =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewThree };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewFour =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewFour };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewFive =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewFive };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewSix =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewSix };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewSeven =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewSeven };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewEight =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewEight };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewNine =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewNine };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewStop =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewStop };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewColon =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewColon };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewZeroShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewZeroShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewOneShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewOneShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewTwoShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewTwoShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewThreeShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewThreeShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewFourShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewFourShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewFiveShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewFiveShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewSixShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewSixShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewSevenShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewSevenShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewEightShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewEightShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewNineShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewNineShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewStopShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewStopShape };
static const TAknsItemID KAknsIIDQsnCpClockDigitalAhNewColonShape =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalAhNewColonShape };

// Notepad frame

static const TAknsItemID KAknsIIDQsnFrNotepad =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepad };

static const TAknsItemID KAknsIIDQsnFrNotepadCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadCornerTl };

static const TAknsItemID KAknsIIDQsnFrNotepadCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadCornerTr };

static const TAknsItemID KAknsIIDQsnFrNotepadCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadCornerBl };

static const TAknsItemID KAknsIIDQsnFrNotepadCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadCornerBr };

static const TAknsItemID KAknsIIDQsnFrNotepadSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadSideT };

static const TAknsItemID KAknsIIDQsnFrNotepadSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadSideB };

static const TAknsItemID KAknsIIDQsnFrNotepadSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadSideL };

static const TAknsItemID KAknsIIDQsnFrNotepadSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadSideR };

static const TAknsItemID KAknsIIDQsnFrNotepadCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadCenter };

// Notepad "cont" frame

static const TAknsItemID KAknsIIDQsnFrNotepadCont =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadCont };

static const TAknsItemID KAknsIIDQsnFrNotepadContCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadContCornerTl };

static const TAknsItemID KAknsIIDQsnFrNotepadContCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadContCornerTr };

static const TAknsItemID KAknsIIDQsnFrNotepadContCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadContCornerBl };

static const TAknsItemID KAknsIIDQsnFrNotepadContCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadContCornerBr };

static const TAknsItemID KAknsIIDQsnFrNotepadContSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadContSideT };

static const TAknsItemID KAknsIIDQsnFrNotepadContSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadContSideB };

static const TAknsItemID KAknsIIDQsnFrNotepadContSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadContSideL };

static const TAknsItemID KAknsIIDQsnFrNotepadContSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadContSideR };

static const TAknsItemID KAknsIIDQsnFrNotepadContCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrNotepadContCenter };

// Calculator paper frame

static const TAknsItemID KAknsIIDQsnFrCalcPaper =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcPaper };

static const TAknsItemID KAknsIIDQsnFrCalcPaperCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcPaperCornerTl };

static const TAknsItemID KAknsIIDQsnFrCalcPaperCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcPaperCornerTr };

static const TAknsItemID KAknsIIDQsnFrCalcPaperCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcPaperCornerBl };

static const TAknsItemID KAknsIIDQsnFrCalcPaperCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcPaperCornerBr };

static const TAknsItemID KAknsIIDQsnFrCalcPaperSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcPaperSideT };

static const TAknsItemID KAknsIIDQsnFrCalcPaperSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcPaperSideB };

static const TAknsItemID KAknsIIDQsnFrCalcPaperSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcPaperSideL };

static const TAknsItemID KAknsIIDQsnFrCalcPaperSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcPaperSideR };

static const TAknsItemID KAknsIIDQsnFrCalcPaperCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcPaperCenter };

// Calculator display parts

static const TAknsItemID KAknsIIDQsnFrCalcDisplaySideL =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcDisplaySideL };

static const TAknsItemID KAknsIIDQsnFrCalcDisplaySideR =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcDisplaySideR };

static const TAknsItemID KAknsIIDQsnFrCalcDisplayCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrCalcDisplayCenter };

// Button frame

static const TAknsItemID KAknsIIDQsnFrSelButton =
    { EAknsMajorSkin, EAknsMinorQsnFrSelButton };

static const TAknsItemID KAknsIIDQsnFrSelButtonCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrSelButtonCornerTl };

static const TAknsItemID KAknsIIDQsnFrSelButtonCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrSelButtonCornerTr };

static const TAknsItemID KAknsIIDQsnFrSelButtonCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrSelButtonCornerBl };

static const TAknsItemID KAknsIIDQsnFrSelButtonCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrSelButtonCornerBr };

static const TAknsItemID KAknsIIDQsnFrSelButtonSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrSelButtonSideT };

static const TAknsItemID KAknsIIDQsnFrSelButtonSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrSelButtonSideB };

static const TAknsItemID KAknsIIDQsnFrSelButtonSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrSelButtonSideL };

static const TAknsItemID KAknsIIDQsnFrSelButtonSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrSelButtonSideR };

static const TAknsItemID KAknsIIDQsnFrSelButtonCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrSelButtonCenter };

// Info popup frame

static const TAknsItemID KAknsIIDQsnFrPopupPreview =
    { EAknsMajorSkin, EAknsMinorQsnFrPopupPreview };

static const TAknsItemID KAknsIIDQgnGrafPopupTrans =
    { EAknsMajorSkin, EAknsMinorQgnGrafPopupTrans };


// Highlight animations

static const TAknsItemID KAknsIIDQsnAnimGrid =
    { EAknsMajorSkin, EAknsMinorQsnAnimGrid };

static const TAknsItemID KAknsIIDQsnAnimList =
    { EAknsMajorSkin, EAknsMinorQsnAnimList };

static const TAknsItemID KAknsIIDQsnAnimSetOptFoc =
    { EAknsMajorSkin, EAknsMinorQsnAnimSetOptFoc };

// Bitmap animation which are not tied to resource id.
// The default system skin must define these items
static const TAknsItemID KAknsIIDQgnGrafLongPressAnim =
    { EAknsMajorSkin, EAknsMinorQgnGrafLongPressAnim };

static const TAknsItemID KAknsIIDQgnNoteAlarmAlertAnim =
    { EAknsMajorSkin, EAknsMinorQgnNoteAlarmAlertAnim };

// ESeries frames - Action frame
static const TAknsItemID KAknsIIDQgnFsAction =
    { EAknsMajorSkin, EAknsMinorQgnFsAction };

static const TAknsItemID KAknsIIDQgnFsActionCornerTl =
    { EAknsMajorSkin, EAknsMinorQgnFsActionCornerTl };

static const TAknsItemID KAknsIIDQgnFsActionCornerTr =
    { EAknsMajorSkin, EAknsMinorQgnFsActionCornerTr };

static const TAknsItemID KAknsIIDQgnFsActionCornerBl =
    { EAknsMajorSkin, EAknsMinorQgnFsActionCornerBl };

static const TAknsItemID KAknsIIDQgnFsActionCornerBr =
    { EAknsMajorSkin, EAknsMinorQgnFsActionCornerBr };

static const TAknsItemID KAknsIIDQgnFsActionSideT =
    { EAknsMajorSkin, EAknsMinorQgnFsActionSideT };

static const TAknsItemID KAknsIIDQgnFsActionSideB =
    { EAknsMajorSkin, EAknsMinorQgnFsActionSideB };

static const TAknsItemID KAknsIIDQgnFsActionSideL =
    { EAknsMajorSkin, EAknsMinorQgnFsActionSideL };

static const TAknsItemID KAknsIIDQgnFsActionSideR =
    { EAknsMajorSkin, EAknsMinorQgnFsActionSideR };

static const TAknsItemID KAknsIIDQgnFsActionCenter =
    { EAknsMajorSkin, EAknsMinorQgnFsActionCenter };

// ESeries frames - Calendar week high bottom frame
static const TAknsItemID KAknsIIDQgnFsCaleWeekHighBottom =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighBottom };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighBottomCornerTl =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighBottomCornerTl };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighBottomCornerTr =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighBottomCornerTr };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighBottomCornerBl =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighBottomCornerBl };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighBottomCornerBr =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighBottomCornerBr };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighBottomSideT =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighBottomSideT };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighBottomSideB =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighBottomSideB };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighBottomSideL =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighBottomSideL };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighBottomSideR =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighBottomSideR };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighBottomCenter =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighBottomCenter };

// ESeries frames - calendar week high
static const TAknsItemID KAknsIIDQgnFsCaleWeekHigh =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHigh };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighCornerTl =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighCornerTl };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighCornerTr =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighCornerTr };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighCornerBl =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighCornerBl };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighCornerBr =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighCornerBr };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighSideT =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighSideT };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighSideB =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighSideB };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighSideL =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighSideL };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighSideR =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighSideR };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighCenter =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighCenter };

// ESeries frames - calendar high top
static const TAknsItemID KAknsIIDQgnFsCaleWeekHighTop =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighTop };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighTopCornerTl =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighTopCornerTl };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighTopCornerTr =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighTopCornerTr };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighTopCornerBl =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighTopCornerBl };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighTopCornerBr =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighTopCornerBr };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighTopSideT =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighTopSideT };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighTopSideB =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighTopSideB };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighTopSideL =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighTopSideL };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighTopSideR =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighTopSideR };

static const TAknsItemID KAknsIIDQgnFsCaleWeekHighTopCenter =
    { EAknsMajorSkin, EAknsMinorQgnFsCaleWeekHighTopCenter };

// ESeries frames - Grid
static const TAknsItemID KAknsIIDQgnFsGrid =
    { EAknsMajorSkin, EAknsMinorQgnFsGrid };

static const TAknsItemID KAknsIIDQgnFsGridCornerTl =
    { EAknsMajorSkin, EAknsMinorQgnFsGridCornerTl };

static const TAknsItemID KAknsIIDQgnFsGridCornerTr =
    { EAknsMajorSkin, EAknsMinorQgnFsGridCornerTr };

static const TAknsItemID KAknsIIDQgnFsGridCornerBl =
    { EAknsMajorSkin, EAknsMinorQgnFsGridCornerBl };

static const TAknsItemID KAknsIIDQgnFsGridCornerBr =
    { EAknsMajorSkin, EAknsMinorQgnFsGridCornerBr };

static const TAknsItemID KAknsIIDQgnFsGridSideT =
    { EAknsMajorSkin, EAknsMinorQgnFsGridSideT };

static const TAknsItemID KAknsIIDQgnFsGridSideL =
    { EAknsMajorSkin, EAknsMinorQgnFsGridSideL };

static const TAknsItemID KAknsIIDQgnFsGridSideR =
    { EAknsMajorSkin, EAknsMinorQgnFsGridSideR };

static const TAknsItemID KAknsIIDQgnFsGridSideB =
    { EAknsMajorSkin, EAknsMinorQgnFsGridSideB };

static const TAknsItemID KAknsIIDQgnFsGridCenter =
    { EAknsMajorSkin, EAknsMinorQgnFsGridCenter };

// ESeries frames - Input frame
static const TAknsItemID KAknsIIDQgnFsInput  =
    { EAknsMajorSkin, EAknsMinorQgnFsInput };

static const TAknsItemID KAknsIIDQgnFsInputCornerTl  =
    { EAknsMajorSkin, EAknsMinorQgnFsInputCornerTl };

static const TAknsItemID KAknsIIDQgnFsInputCornerTr  =
    { EAknsMajorSkin, EAknsMinorQgnFsInputCornerTr };

static const TAknsItemID KAknsIIDQgnFsInputCornerBl  =
    { EAknsMajorSkin, EAknsMinorQgnFsInputCornerBl };

static const TAknsItemID KAknsIIDQgnFsInputCornerBr  =
    { EAknsMajorSkin, EAknsMinorQgnFsInputCornerBr };

static const TAknsItemID KAknsIIDQgnFsInputSideT  =
    { EAknsMajorSkin, EAknsMinorQgnFsInputSideT };

static const TAknsItemID KAknsIIDQgnFsInputSideL  =
    { EAknsMajorSkin, EAknsMinorQgnFsInputSideL };

static const TAknsItemID KAknsIIDQgnFsInputSideR =
    { EAknsMajorSkin, EAknsMinorQgnFsInputSideR };

static const TAknsItemID KAknsIIDQgnFsInputSideB  =
    { EAknsMajorSkin, EAknsMinorQgnFsInputSideB };

static const TAknsItemID KAknsIIDQgnFsInputCenter  =
    { EAknsMajorSkin, EAknsMinorQgnFsInputCenter };

// ESeries frames - List frame
static const TAknsItemID KAknsIIDQgnFsList =
    { EAknsMajorSkin, EAknsMinorQgnFsList };

static const TAknsItemID KAknsIIDQgnFsListCornerTl  =
    { EAknsMajorSkin, EAknsMinorQgnFsListCornerTl };

static const TAknsItemID KAknsIIDQgnFsListCornerTr  =
    { EAknsMajorSkin, EAknsMinorQgnFsListCornerTr };

static const TAknsItemID KAknsIIDQgnFsListCornerBl  =
    { EAknsMajorSkin, EAknsMinorQgnFsListCornerBl };

static const TAknsItemID KAknsIIDQgnFsListCornerBr =
    { EAknsMajorSkin, EAknsMinorQgnFsListCornerBr };

static const TAknsItemID KAknsIIDQgnFsListSideT  =
    { EAknsMajorSkin, EAknsMinorQgnFsListSideT };

static const TAknsItemID KAknsIIDQgnFsListSideL  =
    { EAknsMajorSkin, EAknsMinorQgnFsListSideL };

static const TAknsItemID KAknsIIDQgnFsListSideR  =
    { EAknsMajorSkin, EAknsMinorQgnFsListSideR };

static const TAknsItemID KAknsIIDQgnFsListSideB =
    { EAknsMajorSkin, EAknsMinorQgnFsListSideB };

static const TAknsItemID KAknsIIDQgnFsListCenter  =
    { EAknsMajorSkin, EAknsMinorQgnFsListCenter };


// ----------------------------------------------------------------------------
// EAknsMajorAvkon item IDs
// ----------------------------------------------------------------------------

// Icon group "gene"

static const TAknsItemID KAknsIIDQgnIndiScrollUpMask =
    { EAknsMajorAvkon, EAknsMinorQgnIndiScrollUpMask };

static const TAknsItemID KAknsIIDQgnIndiScrollDownMask =
    { EAknsMajorAvkon, EAknsMinorQgnIndiScrollDownMask };

static const TAknsItemID KAknsIIDQgnIndiSignalStrength =
    { EAknsMajorAvkon, EAknsMinorQgnIndiSignalStrength };

static const TAknsItemID KAknsIIDQgnIndiBatteryStrength =
    { EAknsMajorAvkon, EAknsMinorQgnIndiBatteryStrength };

static const TAknsItemID KAknsIIDQgnIndiNoSignal =
    { EAknsMajorAvkon, EAknsMinorQgnIndiNoSignal };

static const TAknsItemID KAknsIIDQgnIndiFindGlass =
    { EAknsMajorAvkon, EAknsMinorQgnIndiFindGlass };

static const TAknsItemID KAknsIIDQgnPropCheckboxOff =
    { EAknsMajorAvkon, EAknsMinorQgnPropCheckboxOff };

static const TAknsItemID KAknsIIDQgnPropCheckboxOn =
    { EAknsMajorAvkon, EAknsMinorQgnPropCheckboxOn };

static const TAknsItemID KAknsIIDQgnPropFolderSmall =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderSmall };

static const TAknsItemID KAknsIIDQgnPropGroupSmall =
    { EAknsMajorAvkon, EAknsMinorQgnPropGroupSmall };

static const TAknsItemID KAknsIIDQgnPropRadiobuttOff =
    { EAknsMajorAvkon, EAknsMinorQgnPropRadiobuttOff };

static const TAknsItemID KAknsIIDQgnPropRadiobuttOn =
    { EAknsMajorAvkon, EAknsMinorQgnPropRadiobuttOn };

static const TAknsItemID KAknsIIDQgnPropFolderLarge =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderLarge };

static const TAknsItemID KAknsIIDQgnPropFolderMedium =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderMedium };

static const TAknsItemID KAknsIIDQgnPropGroupLarge =
    { EAknsMajorAvkon, EAknsMinorQgnPropGroupLarge };

static const TAknsItemID KAknsIIDQgnPropGroupMedium =
    { EAknsMajorAvkon, EAknsMinorQgnPropGroupMedium };

static const TAknsItemID KAknsIIDQgnPropUnsupportedFile =
    { EAknsMajorAvkon, EAknsMinorQgnPropUnsupportedFile };

static const TAknsItemID KAknsIIDQgnPropFolderGms =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderGms };

static const TAknsItemID KAknsIIDQgnPropFmgrFileGame =
    { EAknsMajorAvkon, EAknsMinorQgnPropFmgrFileGame};

static const TAknsItemID KAknsIIDQgnPropFmgrFileOther =
    { EAknsMajorAvkon, EAknsMinorQgnPropFmgrFileOther};

static const TAknsItemID KAknsIIDQgnPropFolderCurrent =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderCurrent };

static const TAknsItemID KAknsIIDQgnPropFolderSubSmall =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderSubSmall };

static const TAknsItemID KAknsIIDQgnPropFolderAppsMedium =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderAppsMedium };

static const TAknsItemID KAknsIIDQgnMenuFolderApps =
    { EAknsMajorAvkon, EAknsMinorQgnMenuFolderApps };

static const TAknsItemID KAknsIIDQgnPropFolderSubMedium =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderSubMedium };

static const TAknsItemID KAknsIIDQgnPropFolderImages =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderImages };

static const TAknsItemID KAknsIIDQgnPropFolderMmsTemp =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderMmsTemp };

static const TAknsItemID KAknsIIDQgnPropFolderSounds =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderSounds };

static const TAknsItemID KAknsIIDQgnPropFolderSubLarge =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderSubLarge };

static const TAknsItemID KAknsIIDQgnPropFolderVideo =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderVideo };

static const TAknsItemID KAknsIIDQgnPropImFrom =
    { EAknsMajorAvkon, EAknsMinorQgnPropImFrom };

static const TAknsItemID KAknsIIDQgnPropImTome =
    { EAknsMajorAvkon, EAknsMinorQgnPropImTome };

static const TAknsItemID KAknsIIDQgnPropNrtypAddress =
    { EAknsMajorAvkon, EAknsMinorQgnPropNrtypAddress };

static const TAknsItemID KAknsIIDQgnPropNrtypCompAddress =
    { EAknsMajorAvkon, EAknsMinorQgnPropNrtypCompAddress };

static const TAknsItemID KAknsIIDQgnPropNrtypHomeAddress =
    { EAknsMajorAvkon, EAknsMinorQgnPropNrtypHomeAddress };

static const TAknsItemID KAknsIIDQgnPropNrtypDate =
    { EAknsMajorAvkon, EAknsMinorQgnPropNrtypDate };

static const TAknsItemID KAknsIIDQgnPropNrtypEmail =
    { EAknsMajorAvkon, EAknsMinorQgnPropNrtypEmail };

static const TAknsItemID KAknsIIDQgnPropNrtypFax =
    { EAknsMajorAvkon, EAknsMinorQgnPropNrtypFax };

static const TAknsItemID KAknsIIDQgnPropNrtypMobile =
    { EAknsMajorAvkon, EAknsMinorQgnPropNrtypMobile };

static const TAknsItemID KAknsIIDQgnPropNrtypNote =
    { EAknsMajorAvkon, EAknsMinorQgnPropNrtypNote };

static const TAknsItemID KAknsIIDQgnPropNrtypPager =
    { EAknsMajorAvkon, EAknsMinorQgnPropNrtypPager };

static const TAknsItemID KAknsIIDQgnPropNrtypPhone =
    { EAknsMajorAvkon, EAknsMinorQgnPropNrtypPhone };

static const TAknsItemID KAknsIIDQgnPropNrtypTone =
    { EAknsMajorAvkon, EAknsMinorQgnPropNrtypTone };

static const TAknsItemID KAknsIIDQgnPropNrtypUrl =
    { EAknsMajorAvkon, EAknsMinorQgnPropNrtypUrl };

static const TAknsItemID KAknsIIDQgnIndiSubmenu =
    { EAknsMajorAvkon, EAknsMinorQgnIndiSubmenu };

static const TAknsItemID KAknsIIDQgnIndiOnimageAudio =
    { EAknsMajorAvkon, EAknsMinorQgnIndiOnimageAudio };

static const TAknsItemID KAknsIIDQgnPropFolderDigital =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderDigital };

static const TAknsItemID KAknsIIDQgnPropFolderSimple =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderSimple };

static const TAknsItemID KAknsIIDQgnPropFolderPres =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderPres };

static const TAknsItemID KAknsIIDQgnPropFileVideo =
    { EAknsMajorAvkon, EAknsMinorQgnPropFileVideo };

static const TAknsItemID KAknsIIDQgnPropFileAudio =
    { EAknsMajorAvkon, EAknsMinorQgnPropFileAudio };

static const TAknsItemID KAknsIIDQgnPropFileRam =
    { EAknsMajorAvkon, EAknsMinorQgnPropFileRam };

static const TAknsItemID KAknsIIDQgnPropFilePlaylist =
    { EAknsMajorAvkon, EAknsMinorQgnPropFilePlaylist };

static const TAknsItemID KAknsIIDQgnPropWmlFolderLinkSeamless =
    { EAknsMajorAvkon, EAknsMinorQgnPropWmlFolderLinkSeamless };

static const TAknsItemID KAknsIIDQgnIndiFindGoto =
    { EAknsMajorAvkon, EAknsMinorQgnIndiFindGoto };

// Icon group "tab"

static const TAknsItemID KAknsIIDQgnGrafTab21 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTab21 };

static const TAknsItemID KAknsIIDQgnGrafTab22 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTab22 };

static const TAknsItemID KAknsIIDQgnGrafTab31 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTab31 };

static const TAknsItemID KAknsIIDQgnGrafTab32 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTab32 };

static const TAknsItemID KAknsIIDQgnGrafTab33 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTab33 };

static const TAknsItemID KAknsIIDQgnGrafTab41 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTab41 };

static const TAknsItemID KAknsIIDQgnGrafTab42 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTab42 };

static const TAknsItemID KAknsIIDQgnGrafTab43 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTab43 };

static const TAknsItemID KAknsIIDQgnGrafTab44 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTab44 };

static const TAknsItemID KAknsIIDQgnGrafTabLong21 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTabLong21 };

static const TAknsItemID KAknsIIDQgnGrafTabLong22 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTabLong22 };

static const TAknsItemID KAknsIIDQgnGrafTabLong31 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTabLong31 };

static const TAknsItemID KAknsIIDQgnGrafTabLong32 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTabLong32 };

static const TAknsItemID KAknsIIDQgnGrafTabLong33 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafTabLong33 };

// Tab icons for A&H

static const TAknsItemID KAknsIIDQgnPropFolderTab1 =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderTab1 };

static const TAknsItemID KAknsIIDQgnPropFolderHelpTab1 =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderHelpTab1 };

static const TAknsItemID KAknsIIDQgnPropHelpOpenTab1 =
    { EAknsMajorAvkon, EAknsMinorQgnPropHelpOpenTab1 };

static const TAknsItemID KAknsIIDQgnPropFolderImageTab1 =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderImageTab1 };

static const TAknsItemID KAknsIIDQgnPropFolderMessageTab1 =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderMessageTab1 };

static const TAknsItemID KAknsIIDQgnPropFolderMessageAttachTab1 =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderMessageAttachTab1 };

static const TAknsItemID KAknsIIDQgnPropFolderMessageAudioTab1 =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderMessageAudioTab1 };

static const TAknsItemID KAknsIIDQgnPropFolderMessageObjectTab1 =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderMessageObjectTab1 };

static const TAknsItemID KAknsIIDQgnPropNoteListAlphaTab2 =
    { EAknsMajorAvkon, EAknsMinorQgnPropNoteListAlphaTab2 };

static const TAknsItemID KAknsIIDQgnPropListKeywordTab2 =
    { EAknsMajorAvkon, EAknsMinorQgnPropListKeywordTab2 };

static const TAknsItemID KAknsIIDQgnPropNoteListTimeTab2 =
    { EAknsMajorAvkon, EAknsMinorQgnPropNoteListTimeTab2 };

static const TAknsItemID KAknsIIDQgnPropMceDocTab4 =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceDocTab4 };

static const TAknsItemID KAknsIIDQgnPropFolderTab =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderTab };

static const TAknsItemID KAknsIIDQgnPropListKeywordArabicTab2 =
    { EAknsMajorAvkon, EAknsMinorQgnPropListKeywordArabicTab2 };

static const TAknsItemID KAknsIIDQgnPropListKeywordHebrewTab2 =
    { EAknsMajorAvkon, EAknsMinorQgnPropListKeywordHebrewTab2 };

static const TAknsItemID KAknsIIDQgnPropNoteListAlphaArabicTab2 =
    { EAknsMajorAvkon, EAknsMinorQgnPropNoteListAlphaArabicTab2 };

static const TAknsItemID KAknsIIDQgnPropNoteListAlphaHebrewTab2 =
    { EAknsMajorAvkon, EAknsMinorQgnPropNoteListAlphaHebrewTab2 };

// Icon group "bt"

static const TAknsItemID KAknsIIDQgnPropBtAudio =
    { EAknsMajorAvkon, EAknsMinorQgnPropBtAudio };

static const TAknsItemID KAknsIIDQgnPropBtUnknown =
    { EAknsMajorAvkon, EAknsMinorQgnPropBtUnknown };

// Icon group "mce"

static const TAknsItemID KAknsIIDQgnPropFolderSmallNew =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderSmallNew };

static const TAknsItemID KAknsIIDQgnPropFolderTemp =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderTemp };

static const TAknsItemID KAknsIIDQgnPropMceUnknownRead =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceUnknownRead };

static const TAknsItemID KAknsIIDQgnPropMceUnknownUnread =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceUnknownUnread };

static const TAknsItemID KAknsIIDQgnPropMceBtUnread =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceBtUnread };

static const TAknsItemID KAknsIIDQgnPropMceDocSmall =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceDocSmall };

static const TAknsItemID KAknsIIDQgnPropMceDocumentsNewSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceDocumentsNewSub };

static const TAknsItemID KAknsIIDQgnPropMceDocumentsSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceDocumentsSub };

static const TAknsItemID KAknsIIDQgnPropFolderSubs =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderSubs };

static const TAknsItemID KAknsIIDQgnPropFolderSubsNew =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderSubsNew };

static const TAknsItemID KAknsIIDQgnPropFolderSubSubs =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderSubSubs };

static const TAknsItemID KAknsIIDQgnPropFolderSubSubsNew =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderSubSubsNew };

static const TAknsItemID KAknsIIDQgnPropFolderSubUnsubsNew =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderSubUnsubsNew };

static const TAknsItemID KAknsIIDQgnPropFolderUnsubsNew =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderUnsubsNew };

static const TAknsItemID KAknsIIDQgnPropMceWriteSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceWriteSub };

static const TAknsItemID KAknsIIDQgnPropMceInboxSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceInboxSub };

static const TAknsItemID KAknsIIDQgnPropMceInboxNewSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceInboxNewSub };

static const TAknsItemID KAknsIIDQgnPropMceRemoteSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceRemoteSub };

static const TAknsItemID KAknsIIDQgnPropMceRemoteNewSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceRemoteNewSub };

static const TAknsItemID KAknsIIDQgnPropMceSentSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceSentSub };

static const TAknsItemID KAknsIIDQgnPropMceOutboxSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceOutboxSub };

static const TAknsItemID KAknsIIDQgnPropMceDrSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceDrSub };

// Icon group "logs"

static const TAknsItemID KAknsIIDQgnPropLogCallsSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogCallsSub };

static const TAknsItemID KAknsIIDQgnPropLogMissedSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogMissedSub };

static const TAknsItemID KAknsIIDQgnPropLogInSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogInSub };

static const TAknsItemID KAknsIIDQgnPropLogOutSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogOutSub };

static const TAknsItemID KAknsIIDQgnPropLogTimersSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogTimersSub };

static const TAknsItemID KAknsIIDQgnPropLogTimerCallLast =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogTimerCallLast };

static const TAknsItemID KAknsIIDQgnPropLogTimerCallOut =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogTimerCallOut };

static const TAknsItemID KAknsIIDQgnPropLogTimerCallIn =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogTimerCallIn };

static const TAknsItemID KAknsIIDQgnPropLogTimerCallAll =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogTimerCallAll };

static const TAknsItemID KAknsIIDQgnPropLogGprsSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogGprsSub };

static const TAknsItemID KAknsIIDQgnPropLogGprsSent =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogGprsSent };

static const TAknsItemID KAknsIIDQgnPropLogGprsReceived =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogGprsReceived };

// Icon group "Camera settings"

static const TAknsItemID KAknsIIDQgnPropSetCamsImageSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetCamsImageSub };

static const TAknsItemID KAknsIIDQgnPropSetCamsVideoSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetCamsVideoSub };

// Icon group "Realplayer settings"

static const TAknsItemID KAknsIIDQgnPropSetMpVideoSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetMpVideoSub };

static const TAknsItemID KAknsIIDQgnPropSetMpAudioSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetMpAudioSub };

static const TAknsItemID KAknsIIDQgnPropSetMpStreamSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetMpStreamSub };

// Icon group "chat"

static const TAknsItemID KAknsIIDQgnPropImIbox =
    { EAknsMajorAvkon, EAknsMinorQgnPropImIbox };

static const TAknsItemID KAknsIIDQgnPropImFriends =
    { EAknsMajorAvkon, EAknsMinorQgnPropImFriends };

static const TAknsItemID KAknsIIDQgnPropImList =
    { EAknsMajorAvkon, EAknsMinorQgnPropImList };

// Icon group "dyc"

static const TAknsItemID KAknsIIDQgnPropDycPublicSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropDycPublicSub };

static const TAknsItemID KAknsIIDQgnPropDycPrivateSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropDycPrivateSub };

static const TAknsItemID KAknsIIDQgnPropDycBlockedSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropDycBlockedSub };

static const TAknsItemID KAknsIIDQgnPropDycAvailBig =
    { EAknsMajorAvkon, EAknsMinorQgnPropDycAvailBig };

static const TAknsItemID KAknsIIDQgnPropDycDiscreetBig =
    { EAknsMajorAvkon, EAknsMinorQgnPropDycDiscreetBig };

static const TAknsItemID KAknsIIDQgnPropDycNotAvailBig =
    { EAknsMajorAvkon, EAknsMinorQgnPropDycNotAvailBig };

static const TAknsItemID KAknsIIDQgnPropDycNotPublishBig =
    { EAknsMajorAvkon, EAknsMinorQgnPropDycNotPublishBig };

// Icon group "Settings"

static const TAknsItemID KAknsIIDQgnPropSetDeviceSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetDeviceSub };

static const TAknsItemID KAknsIIDQgnPropSetCallSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetCallSub };

static const TAknsItemID KAknsIIDQgnPropSetConnecSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetConnecSub };

static const TAknsItemID KAknsIIDQgnPropSetDatimSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetDatimSub };

static const TAknsItemID KAknsIIDQgnPropSetSecSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetSecSub };

static const TAknsItemID KAknsIIDQgnPropSetDivSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetDivSub };

static const TAknsItemID KAknsIIDQgnPropSetBarrSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetBarrSub };

static const TAknsItemID KAknsIIDQgnPropSetNetworkSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetNetworkSub };

static const TAknsItemID KAknsIIDQgnPropSetAccessorySub =
    { EAknsMajorAvkon, EAknsMinorQgnPropSetAccessorySub };

// Icon group "location"

static const TAknsItemID KAknsIIDQgnPropLocSetSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropLocSetSub };

static const TAknsItemID KAknsIIDQgnPropLocRequestsSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropLocRequestsSub };

// Icon group "Wallet"

static const TAknsItemID KAknsIIDQgnPropWalletServiceSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropWalletServiceSub };

static const TAknsItemID KAknsIIDQgnPropWalletTicketsSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropWalletTicketsSub };

static const TAknsItemID KAknsIIDQgnPropWalletCardsSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropWalletCardsSub };

static const TAknsItemID KAknsIIDQgnPropWalletPnotesSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropWalletPnotesSub };

// Icon group "Sync"

static const TAknsItemID KAknsIIDQgnPropSmlBt =
    { EAknsMajorAvkon, EAknsMinorQgnPropSmlBt };

// Icon group "note"

static const TAknsItemID KAknsIIDQgnNoteQuery =
    { EAknsMajorAvkon, EAknsMinorQgnNoteQuery };

static const TAknsItemID KAknsIIDQgnNoteAlarmClock =
    { EAknsMajorAvkon, EAknsMinorQgnNoteAlarmClock };

static const TAknsItemID KAknsIIDQgnNoteBattCharging =
    { EAknsMajorAvkon, EAknsMinorQgnNoteBattCharging };

static const TAknsItemID KAknsIIDQgnNoteBattFull =
    { EAknsMajorAvkon, EAknsMinorQgnNoteBattFull };

static const TAknsItemID KAknsIIDQgnNoteBattLow =
    { EAknsMajorAvkon, EAknsMinorQgnNoteBattLow };

static const TAknsItemID KAknsIIDQgnNoteBattNotCharging =
    { EAknsMajorAvkon, EAknsMinorQgnNoteBattNotCharging };

static const TAknsItemID KAknsIIDQgnNoteBattRecharge =
    { EAknsMajorAvkon, EAknsMinorQgnNoteBattRecharge };

static const TAknsItemID KAknsIIDQgnNoteErased =
    { EAknsMajorAvkon, EAknsMinorQgnNoteErased };

static const TAknsItemID KAknsIIDQgnNoteError =
    { EAknsMajorAvkon, EAknsMinorQgnNoteError };

static const TAknsItemID KAknsIIDQgnNoteFaxpc =
    { EAknsMajorAvkon, EAknsMinorQgnNoteFaxpc };

static const TAknsItemID KAknsIIDQgnNoteGrps =
    { EAknsMajorAvkon, EAknsMinorQgnNoteGrps };

static const TAknsItemID KAknsIIDQgnNoteInfo =
    { EAknsMajorAvkon, EAknsMinorQgnNoteInfo };

static const TAknsItemID KAknsIIDQgnNoteKeyguard =
    { EAknsMajorAvkon, EAknsMinorQgnNoteKeyguard };

static const TAknsItemID KAknsIIDQgnNoteOk =
    { EAknsMajorAvkon, EAknsMinorQgnNoteOk };

static const TAknsItemID KAknsIIDQgnNoteProgress =
    { EAknsMajorAvkon, EAknsMinorQgnNoteProgress };

static const TAknsItemID KAknsIIDQgnNoteWarning =
    { EAknsMajorAvkon, EAknsMinorQgnNoteWarning };

// Icon group "phota"

static const TAknsItemID KAknsIIDQgnPropImageNotcreated =
    { EAknsMajorAvkon, EAknsMinorQgnPropImageNotcreated };

static const TAknsItemID KAknsIIDQgnPropImageCorrupted =
    { EAknsMajorAvkon, EAknsMinorQgnPropImageCorrupted };

// Icon group "memc"

static const TAknsItemID KAknsIIDQgnPropFileSmall =
    { EAknsMajorAvkon, EAknsMinorQgnPropFileSmall };

static const TAknsItemID KAknsIIDQgnPropPhoneMemc =
    { EAknsMajorAvkon, EAknsMinorQgnPropPhoneMemc };

static const TAknsItemID KAknsIIDQgnPropMmcMemc =
    { EAknsMajorAvkon, EAknsMinorQgnPropMmcMemc };

static const TAknsItemID KAknsIIDQgnPropMmcLocked =
    { EAknsMajorAvkon, EAknsMinorQgnPropMmcLocked };

static const TAknsItemID KAknsIIDQgnPropMmcNon =
    { EAknsMajorAvkon, EAknsMinorQgnPropMmcNon };

static const TAknsItemID KAknsIIDQgnPropPhoneMemcLarge =
    { EAknsMajorAvkon, EAknsMinorQgnPropPhoneMemcLarge };

static const TAknsItemID KAknsIIDQgnPropMmcMemcLarge =
    { EAknsMajorAvkon, EAknsMinorQgnPropMmcMemcLarge };

// Other icons

static const TAknsItemID KAknsIIDQgnIndiNaviArrowLeft =
    { EAknsMajorAvkon, EAknsMinorQgnIndiNaviArrowLeft };

static const TAknsItemID KAknsIIDQgnIndiNaviArrowRight =
    { EAknsMajorAvkon, EAknsMinorQgnIndiNaviArrowRight };

static const TAknsItemID KAknsIIDQgnGrafProgressBar =
    { EAknsMajorAvkon, EAknsMinorQgnGrafProgressBar };

static const TAknsItemID KAknsIIDQgnGrafVorecProgressBar =
    { EAknsMajorAvkon, EAknsMinorQgnGrafVorecProgressBar };

static const TAknsItemID KAknsIIDQgnGrafVorecBarBackground =
    { EAknsMajorAvkon, EAknsMinorQgnGrafVorecBarBackground };

static const TAknsItemID KAknsIIDQgnGrafWaitBarBackground =
    { EAknsMajorAvkon, EAknsMinorQgnGrafWaitBarBackground };

static const TAknsItemID KAknsIIDQgnGrafWaitBar1 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafWaitBar1 };

static const TAknsItemID KAknsIIDQgnGrafSimpdStatusBackg =
    { EAknsMajorAvkon, EAknsMinorQgnGrafSimpdStatusBackg };

static const TAknsItemID KAknsIIDQgnGrafPbStatusBackg =
    { EAknsMajorAvkon, EAknsMinorQgnGrafPbStatusBackg };

static const TAknsItemID KAknsIIDQgnGrafSnoteAdd1 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafSnoteAdd1 };

static const TAknsItemID KAknsIIDQgnGrafSnoteAdd2 =
    { EAknsMajorAvkon, EAknsMinorQgnGrafSnoteAdd2 };

// Other icons for A&H

static const TAknsItemID KAknsIIDQgnIndiCamsPhoneMemc =
    { EAknsMajorAvkon, EAknsMinorQgnIndiCamsPhoneMemc };

static const TAknsItemID KAknsIIDQgnIndiDycDtOtherAdd =
    { EAknsMajorAvkon, EAknsMinorQgnIndiDycDtOtherAdd };

static const TAknsItemID KAknsIIDQgnPropFolderDyc =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderDyc };

static const TAknsItemID KAknsIIDQgnPropFolderTab2 =
    { EAknsMajorAvkon, EAknsMinorQgnPropFolderTab2 };

static const TAknsItemID KAknsIIDQgnPropLogLogsTab2 =
    { EAknsMajorAvkon, EAknsMinorQgnPropLogLogsTab2 };

static const TAknsItemID KAknsIIDQgnPropMceDraftsNewSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceDraftsNewSub };

static const TAknsItemID KAknsIIDQgnPropMceDraftsSub =
    { EAknsMajorAvkon, EAknsMinorQgnPropMceDraftsSub };

static const TAknsItemID KAknsIIDQgnPropWmlFolderAdap =
    { EAknsMajorAvkon, EAknsMinorQgnPropWmlFolderAdap };

// Navi area components

static const TAknsItemID KAknsIIDQsnBgNavipaneSolid =
    { EAknsMajorAvkon, EAknsMinorQsnBgNavipaneSolid };

static const TAknsItemID KAknsIIDQsnBgNavipaneWipe =
    { EAknsMajorAvkon, EAknsMinorQsnBgNavipaneWipe };

static const TAknsItemID KAknsIIDQsnBgNavipaneSolidIdle =
    { EAknsMajorAvkon, EAknsMinorQsnBgNavipaneSolidIdle };

static const TAknsItemID KAknsIIDQsnBgNavipaneWipeIdle =
    { EAknsMajorAvkon, EAknsMinorQsnBgNavipaneWipeIdle };

static const TAknsItemID KAknsIIDQgnNoteQuery2 =
    { EAknsMajorAvkon, EAknsMinorQgnNoteQuery2 };

static const TAknsItemID KAknsIIDQgnNoteQuery3 =
    { EAknsMajorAvkon, EAknsMinorQgnNoteQuery3 };

static const TAknsItemID KAknsIIDQgnNoteQuery4 =
    { EAknsMajorAvkon, EAknsMinorQgnNoteQuery4 };

static const TAknsItemID KAknsIIDQgnNoteQuery5 =
    { EAknsMajorAvkon, EAknsMinorQgnNoteQuery5 };

// Animations

static const TAknsItemID KAknsIIDQgnNoteQueryAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteQueryAnim };

static const TAknsItemID KAknsIIDQgnNoteBattChargingAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteBattChargingAnim };

static const TAknsItemID KAknsIIDQgnNoteBattFullAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteBattFullAnim };

static const TAknsItemID KAknsIIDQgnNoteBattLowAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteBattLowAnim };

static const TAknsItemID KAknsIIDQgnNoteBattNotChargingAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteBattNotChargingAnim };

static const TAknsItemID KAknsIIDQgnNoteBattRechargeAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteBattRechargeAnim };

static const TAknsItemID KAknsIIDQgnNoteErasedAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteErasedAnim };

static const TAknsItemID KAknsIIDQgnNoteErrorAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteErrorAnim };

static const TAknsItemID KAknsIIDQgnNoteInfoAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteInfoAnim };

static const TAknsItemID KAknsIIDQgnNoteKeyguardLockedAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteKeyguardLockedAnim };

static const TAknsItemID KAknsIIDQgnNoteKeyguardOpenAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteKeyguardOpenAnim };

static const TAknsItemID KAknsIIDQgnNoteOkAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteOkAnim };

static const TAknsItemID KAknsIIDQgnNoteWarningAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteWarningAnim };

static const TAknsItemID KAknsIIDQgnNoteBtAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteBtAnim };

static const TAknsItemID KAknsIIDQgnNoteFaxpcAnim =
    { EAknsMajorAvkon, EAknsMinorQgnNoteFaxpcAnim };

static const TAknsItemID KAknsIIDQgnGrafBarWaitAnim =
    { EAknsMajorAvkon, EAknsMinorQgnGrafBarWaitAnim };

static const TAknsItemID KAknsIIDQgnGrafFpsSwipeAnim =
    { EAknsMajorAvkon, EAknsMinorQgnGrafFpsSwipeAnim };

// Browser animations

static const TAknsItemID KAknsIIDQgnMenuWmlAnim =
    { EAknsMajorAvkon, EAknsMinorQgnMenuWmlAnim };

static const TAknsItemID KAknsIIDQgnIndiWaitWmlCsdAnim =
    { EAknsMajorAvkon, EAknsMinorQgnIndiWaitWmlCsdAnim };

static const TAknsItemID KAknsIIDQgnIndiWaitWmlGprsAnim =
    { EAknsMajorAvkon, EAknsMinorQgnIndiWaitWmlGprsAnim };

static const TAknsItemID KAknsIIDQgnIndiWaitWmlHscsdAnim =
    { EAknsMajorAvkon, EAknsMinorQgnIndiWaitWmlHscsdAnim };

// CLS animations

static const TAknsItemID KAknsIIDQgnMenuClsCxtAnim =
    { EAknsMajorAvkon, EAknsMinorQgnMenuClsCxtAnim };

// Telephony Swipe Indicator animations

static const TAknsItemID KAknsIIDQgnGrafSwipeindiAnimLeft =
    { EAknsMajorAvkon, EAknsMinorQgnGrafSwipeindiAnimLeft };

static const TAknsItemID KAknsIIDQgnGrafSwipeindiBgLeftAnim =
    { EAknsMajorAvkon, EAknsMinorQgnGrafSwipeindiBgLeftAnim };

static const TAknsItemID KAknsIIDQgnGrafSwipeindiBgRightAnim =
    { EAknsMajorAvkon, EAknsMinorQgnGrafSwipeindiBgRightAnim };

static const TAknsItemID KAknsIIDQgnGrafSwipeindiBlueAnimLeft =
    { EAknsMajorAvkon, EAknsMinorQgnGrafSwipeindiBlueAnimLeft };

static const TAknsItemID KAknsIIDQgnGrafSwipeindiGreenAnimRight =
    { EAknsMajorAvkon, EAknsMinorQgnGrafSwipeindiGreenAnimRight };

static const TAknsItemID KAknsIIDQgnGrafSwipeindiOrangeAnimLeft =
    { EAknsMajorAvkon, EAknsMinorQgnGrafSwipeindiOrangeAnimLeft };

static const TAknsItemID KAknsIIDQgnGrafSwipeindiOrangeAnimRight =
    { EAknsMajorAvkon, EAknsMinorQgnGrafSwipeindiOrangeAnimRight };

static const TAknsItemID KAknsIIDQgnGrafSwipeindiRedAnimLeft =
    { EAknsMajorAvkon, EAknsMinorQgnGrafSwipeindiRedAnimLeft };

static const TAknsItemID KAknsIIDQgnGrafSwipeindiRedAnimRight =
    { EAknsMajorAvkon, EAknsMinorQgnGrafSwipeindiRedAnimRight };


// ----------------------------------------------------------------------------
// EAknsMajorAppIconBmpLst item IDs
// ----------------------------------------------------------------------------

static const TAknsItemID KAknsIIDQgnMenuBtLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuBtLst };

static const TAknsItemID KAknsIIDQgnMenuCalcLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuCalcLst };

static const TAknsItemID KAknsIIDQgnMenuCaleLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuCaleLst };

static const TAknsItemID KAknsIIDQgnMenuCamcorderLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuCamcorderLst };

static const TAknsItemID KAknsIIDQgnMenuCamLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuCamLst };

// Deprecated - divert application was removed from platform in 2.0.
static const TAknsItemID KAknsIIDQgnMenuDivertLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuDivertLst };

static const TAknsItemID KAknsIIDQgnMenuGamesLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuGamesLst };

static const TAknsItemID KAknsIIDQgnMenuHelpLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuHelpLst };

static const TAknsItemID KAknsIIDQgnMenuIdleLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuIdleLst };

static const TAknsItemID KAknsIIDQgnMenuImLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuImLst };

static const TAknsItemID KAknsIIDQgnMenuIrLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuIrLst };

static const TAknsItemID KAknsIIDQgnMenuLogLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuLogLst };

static const TAknsItemID KAknsIIDQgnMenuMceLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuMceLst };

static const TAknsItemID KAknsIIDQgnMenuMceCardLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuMceCardLst };

static const TAknsItemID KAknsIIDQgnMenuMemoryLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuMemoryLst };

static const TAknsItemID KAknsIIDQgnMenuMidletLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuMidletLst };

static const TAknsItemID KAknsIIDQgnMenuMidletSuiteLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuMidletSuiteLst };

static const TAknsItemID KAknsIIDQgnMenuModeLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuModeLst };

static const TAknsItemID KAknsIIDQgnMenuNoteLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuNoteLst };

static const TAknsItemID KAknsIIDQgnMenuPhobLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuPhobLst };

static const TAknsItemID KAknsIIDQgnMenuPhotaLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuPhotaLst };

static const TAknsItemID KAknsIIDQgnMenuPinbLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuPinbLst };

static const TAknsItemID KAknsIIDQgnMenuQdialLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuQdialLst };

static const TAknsItemID KAknsIIDQgnMenuSetLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuSetLst };

static const TAknsItemID KAknsIIDQgnMenuSimpdLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuSimpdLst };

static const TAknsItemID KAknsIIDQgnMenuSmsvoLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuSmsvoLst };

static const TAknsItemID KAknsIIDQgnMenuTodoLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuTodoLst };

static const TAknsItemID KAknsIIDQgnMenuUnknownLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuUnknownLst };

static const TAknsItemID KAknsIIDQgnMenuVideoLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuVideoLst };

static const TAknsItemID KAknsIIDQgnMenuVoirecLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuVoirecLst };

static const TAknsItemID KAknsIIDQgnMenuWclkLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuWclkLst };

static const TAknsItemID KAknsIIDQgnMenuWmlLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuWmlLst };

static const TAknsItemID KAknsIIDQgnMenuLocLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuLocLst };

static const TAknsItemID KAknsIIDQgnMenuBlidLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuBlidLst };

static const TAknsItemID KAknsIIDQgnMenuDycLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuDycLst };

static const TAknsItemID KAknsIIDQgnMenuDmLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuDmLst };

static const TAknsItemID KAknsIIDQgnMenuLmLst =
    { EAknsMajorAppIconBmpLst, EAknsMinorQgnMenuLmLst };

// ----------------------------------------------------------------------------
// EAknsMajorAppIconBmpCxt item IDs
// ----------------------------------------------------------------------------

static const TAknsItemID KAknsIIDQgnMenuAppsgridCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuAppsgridCxt };

static const TAknsItemID KAknsIIDQgnMenuBtCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuBtCxt };

static const TAknsItemID KAknsIIDQgnMenuCaleCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuCaleCxt };

static const TAknsItemID KAknsIIDQgnMenuCamcorderCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuCamcorderCxt };

static const TAknsItemID KAknsIIDQgnMenuCamCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuCamCxt };

static const TAknsItemID KAknsIIDQgnMenuCnvCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuCnvCxt };

static const TAknsItemID KAknsIIDQgnMenuConCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuConCxt };

// Deprecated - divert application was removed from platform in 2.0.
static const TAknsItemID KAknsIIDQgnMenuDivertCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuDivertCxt };

static const TAknsItemID KAknsIIDQgnMenuGamesCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuGamesCxt };

static const TAknsItemID KAknsIIDQgnMenuHelpCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuHelpCxt };

static const TAknsItemID KAknsIIDQgnMenuImCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuImCxt };

static const TAknsItemID KAknsIIDQgnMenuImOffCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuImOffCxt };

static const TAknsItemID KAknsIIDQgnMenuIrCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuIrCxt };

static const TAknsItemID KAknsIIDQgnMenuJavaCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuJavaCxt };

static const TAknsItemID KAknsIIDQgnMenuLogCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuLogCxt };

static const TAknsItemID KAknsIIDQgnMenuMceCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuMceCxt };

static const TAknsItemID KAknsIIDQgnMenuMceCardCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuMceCardCxt };

static const TAknsItemID KAknsIIDQgnMenuMceMmcCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuMceMmcCxt };

static const TAknsItemID KAknsIIDQgnMenuMemoryCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuMemoryCxt };

static const TAknsItemID KAknsIIDQgnMenuMidletSuiteCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuMidletSuiteCxt };

static const TAknsItemID KAknsIIDQgnMenuModeCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuModeCxt };

static const TAknsItemID KAknsIIDQgnMenuNoteCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuNoteCxt };

static const TAknsItemID KAknsIIDQgnMenuPhobCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuPhobCxt };

static const TAknsItemID KAknsIIDQgnMenuPhotaCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuPhotaCxt };

static const TAknsItemID KAknsIIDQgnMenuSetCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuSetCxt };

static const TAknsItemID KAknsIIDQgnMenuSimpdCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuSimpdCxt };

static const TAknsItemID KAknsIIDQgnMenuSmsvoCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuSmsvoCxt };

static const TAknsItemID KAknsIIDQgnMenuTodoCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuTodoCxt };

static const TAknsItemID KAknsIIDQgnMenuUnknownCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuUnknownCxt };

static const TAknsItemID KAknsIIDQgnMenuVideoCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuVideoCxt };

static const TAknsItemID KAknsIIDQgnMenuVoirecCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuVoirecCxt };

static const TAknsItemID KAknsIIDQgnMenuWclkCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuWclkCxt };

static const TAknsItemID KAknsIIDQgnMenuWmlCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuWmlCxt };

static const TAknsItemID KAknsIIDQgnMenuLocCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuLocCxt };

static const TAknsItemID KAknsIIDQgnMenuBlidCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuBlidCxt };

static const TAknsItemID KAknsIIDQgnMenuBlidOffCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuBlidOffCxt };

static const TAknsItemID KAknsIIDQgnMenuDycCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuDycCxt };

static const TAknsItemID KAknsIIDQgnMenuDycOffCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuDycOffCxt };

static const TAknsItemID KAknsIIDQgnMenuDmCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuDmCxt };

static const TAknsItemID KAknsIIDQgnMenuDmDisabledCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuDmDisabledCxt };

static const TAknsItemID KAknsIIDQgnMenuLmCxt =
    { EAknsMajorAppIconBmpCxt, EAknsMinorQgnMenuLmCxt };

// ----------------------------------------------------------------------------
// EAknsMajorScreensaver item IDs
// ----------------------------------------------------------------------------

static const TAknsItemID KAknsIIDQsnBgPowersave =
    { EAknsMajorScreensaver, EAknsMinorQsnBgPowersave };

static const TAknsItemID KAknsIIDQsnBgScreenSaver =
    { EAknsMajorScreensaver, EAknsMinorQsnBgScreenSaver};

// ----------------------------------------------------------------------------
// EAknsMajorCallstatus item IDs
// ----------------------------------------------------------------------------

// Icon group "call" - call status icons

static const TAknsItemID KAknsIIDQgnIndiCallActive =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallActive };

static const TAknsItemID KAknsIIDQgnIndiCallActiveCyphOff =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallActiveCyphOff };

static const TAknsItemID KAknsIIDQgnIndiCallDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallDisconn };

static const TAknsItemID KAknsIIDQgnIndiCallDisconnCyphOff =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallDisconnCyphOff };

static const TAknsItemID KAknsIIDQgnIndiCallHeld =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallHeld };

static const TAknsItemID KAknsIIDQgnIndiCallHeldCyphOff =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallHeldCyphOff };

static const TAknsItemID KAknsIIDQgnIndiCallMutedCallsta =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallMutedCallsta };

static const TAknsItemID KAknsIIDQgnIndiCallActive2 =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallActive2 };

static const TAknsItemID KAknsIIDQgnIndiCallActiveCyphOff2 =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallActiveCyphOff2 };

static const TAknsItemID KAknsIIDQgnIndiCallActiveConf =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallActiveConf };

static const TAknsItemID KAknsIIDQgnIndiCallActiveConfCyphOff =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallActiveConfCyphOff };

static const TAknsItemID KAknsIIDQgnIndiCallDisconnConf =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallDisconnConf };

static const TAknsItemID KAknsIIDQgnIndiCallDisconnConfCyphOff =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallDisconnConfCyphOff };

static const TAknsItemID KAknsIIDQgnIndiCallHeldConf =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallHeldConf };

static const TAknsItemID KAknsIIDQgnIndiCallHeldConfCyphOff =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallHeldConfCyphOff };

static const TAknsItemID KAknsIIDQgnIndiCallMuted =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallMuted };

static const TAknsItemID KAknsIIDQgnIndiCallWaiting =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallWaiting };

static const TAknsItemID KAknsIIDQgnIndiCallWaiting2 =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallWaiting2 };

static const TAknsItemID KAknsIIDQgnIndiCallWaitingCyphOff =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallWaitingCyphOff };

static const TAknsItemID KAknsIIDQgnIndiCallWaitingCyphOff2 =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallWaitingCyphOff2 };

static const TAknsItemID KAknsIIDQgnIndiCallWaitingDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallWaitingDisconn };

static const TAknsItemID KAknsIIDQgnIndiCallWaitingDisconnCyphOff =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallWaitingDisconnCyphOff };

static const TAknsItemID KAknsIIDQgnIndiCallWaiting1 =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallWaiting1 };

// Icon group "call" - call handling graphics icons

static const TAknsItemID KAknsIIDQgnGrafBubbleIncall =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafBubbleIncall };

static const TAknsItemID KAknsIIDQgnGrafBubbleIncallDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafBubbleIncallDisconn };

static const TAknsItemID KAknsIIDQgnGrafCallConfFive =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallConfFive };

static const TAknsItemID KAknsIIDQgnGrafCallConfFour =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallConfFour };

static const TAknsItemID KAknsIIDQgnGrafCallConfThree =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallConfThree };

static const TAknsItemID KAknsIIDQgnGrafCallConfTwo =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallConfTwo };

static const TAknsItemID KAknsIIDQgnGrafCallFirstHeld =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallFirstHeld };

static const TAknsItemID KAknsIIDQgnGrafCallFirstOneActive =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallFirstOneActive };

static const TAknsItemID KAknsIIDQgnGrafCallFirstOneDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallFirstOneDisconn };

static const TAknsItemID KAknsIIDQgnGrafCallFirstOneHeld =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallFirstOneHeld };

static const TAknsItemID KAknsIIDQgnGrafCallFirstThreeActive =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallFirstThreeActive };

static const TAknsItemID KAknsIIDQgnGrafCallFirstThreeDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallFirstThreeDisconn };

static const TAknsItemID KAknsIIDQgnGrafCallFirstThreeHeld =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallFirstThreeHeld };

static const TAknsItemID KAknsIIDQgnGrafCallFirstTwoActive =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallFirstTwoActive };

static const TAknsItemID KAknsIIDQgnGrafCallFirstTwoDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallFirstTwoDisconn };

static const TAknsItemID KAknsIIDQgnGrafCallFirstTwoHeld =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallFirstTwoHeld };

static const TAknsItemID KAknsIIDQgnGrafCallFirstWaitActive =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallFirstWaitActive };

static const TAknsItemID KAknsIIDQgnGrafCallFirstWaitDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallFirstWaitDisconn };

static const TAknsItemID KAknsIIDQgnGrafCallHiddenHeld =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallHiddenHeld };

static const TAknsItemID KAknsIIDQgnGrafCallRecBig =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallRecBig };

static const TAknsItemID KAknsIIDQgnGrafCallRecBigDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallRecBigDisconn };

static const TAknsItemID KAknsIIDQgnGrafCallRecBigLeft =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallRecBigLeft };

static const TAknsItemID KAknsIIDQgnGrafCallRecBigLeftDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallRecBigLeftDisconn };

static const TAknsItemID KAknsIIDQgnGrafCallRecBigRight =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallRecBigRight };

static const TAknsItemID KAknsIIDQgnGrafCallRecBigger =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallRecBigger };

static const TAknsItemID KAknsIIDQgnGrafCallRecBigRightDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallRecBigRightDisconn };

static const TAknsItemID KAknsIIDQgnGrafCallRecSmallLeft =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallRecSmallLeft };

static const TAknsItemID KAknsIIDQgnGrafCallRecSmallRight =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallRecSmallRight };

static const TAknsItemID KAknsIIDQgnGrafCallRecSmallRightDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallRecSmallRightDisconn };

static const TAknsItemID KAknsIIDQgnGrafCallSecondThreeActive =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallSecondThreeActive };

static const TAknsItemID KAknsIIDQgnGrafCallSecondThreeDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallSecondThreeDisconn };

static const TAknsItemID KAknsIIDQgnGrafCallSecondThreeHeld =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallSecondThreeHeld };

static const TAknsItemID KAknsIIDQgnGrafCallSecondTwoActive =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallSecondTwoActive };

static const TAknsItemID KAknsIIDQgnGrafCallSecondTwoDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallSecondTwoDisconn };

static const TAknsItemID KAknsIIDQgnGrafCallSecondTwoHeld =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafCallSecondTwoHeld };

// Video call

static const TAknsItemID KAknsIIDQgnIndiCallVideo1 =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallVideo1 };

static const TAknsItemID KAknsIIDQgnIndiCallVideo2 =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallVideo2 };

static const TAknsItemID KAknsIIDQgnIndiCallVideoBlindIn =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallVideoBlindIn };

static const TAknsItemID KAknsIIDQgnIndiCallVideoBlindOut =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallVideoBlindOut };

static const TAknsItemID KAknsIIDQgnIndiCallVideoCallsta1 =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallVideoCallsta1 };

static const TAknsItemID KAknsIIDQgnIndiCallVideoCallsta2 =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallVideoCallsta2 };

static const TAknsItemID KAknsIIDQgnIndiCallVideoCallstaDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallVideoCallstaDisconn };

static const TAknsItemID KAknsIIDQgnIndiCallVideoDisconn =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallVideoDisconn };

static const TAknsItemID KAknsIIDQgnIndiCallVideoLst =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiCallVideoLst };

// Zoom indications

static const TAknsItemID KAknsIIDQgnGrafZoomArea =
    { EAknsMajorCallstatus, EAknsMinorQgnGrafZoomArea };

static const TAknsItemID KAknsIIDQgnIndiZoomMin =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiZoomMin };

static const TAknsItemID KAknsIIDQgnIndiZoomMax =
    { EAknsMajorCallstatus, EAknsMinorQgnIndiZoomMax };

// Call handling frames

static const TAknsItemID KAknsIIDQsnFrCall2Bubble =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall2Bubble };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall2BubbleDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleFirst =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall2BubbleFirst };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleFirstDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall2BubbleFirstDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSecond =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall2BubbleSecond };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSecondDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall2BubbleSecondDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2Rect =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall2Rect };

static const TAknsItemID KAknsIIDQsnFrCall2RectDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall2RectDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCoMask =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall2BubbleCoMask };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleFirstCoMask =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall2BubbleFirstCoMask };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSecondCoMask =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall2BubbleSecondCoMask };

static const TAknsItemID KAknsIIDQsnFrCall2RectCoMask =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall2RectCoMask };

// Call handling frames
static const TAknsItemID KAknsIIDQsnFrCall3Rect =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3Rect };

static const TAknsItemID KAknsIIDQsnFrCall3RectCornerTl =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectCornerTl };

static const TAknsItemID KAknsIIDQsnFrCall3RectCornerTr =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectCornerTr };

static const TAknsItemID KAknsIIDQsnFrCall3RectCornerBl =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectCornerBl };

static const TAknsItemID KAknsIIDQsnFrCall3RectCornerBr =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectCornerBr };

static const TAknsItemID KAknsIIDQsnFrCall3RectSideT =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectSideT };

static const TAknsItemID KAknsIIDQsnFrCall3RectSideB =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectSideB };

static const TAknsItemID KAknsIIDQsnFrCall3RectSideL =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectSideL };

static const TAknsItemID KAknsIIDQsnFrCall3RectSideR =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectSideR };

static const TAknsItemID KAknsIIDQsnFrCall3RectCenter =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectCenter};


static const TAknsItemID KAknsIIDQsnFrCall3RectDisconn =
	{ EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectDisconn };

static const TAknsItemID KAknsIIDQsnFrCall3RectCornerTlDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectCornerTlDisconn };

static const TAknsItemID KAknsIIDQsnFrCall3RectCornerTrDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectCornerTrDisconn };

static const TAknsItemID KAknsIIDQsnFrCall3RectCornerBlDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectCornerBlDisconn };

static const TAknsItemID KAknsIIDQsnFrCall3RectCornerBrDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectCornerBrDisconn };

static const TAknsItemID KAknsIIDQsnFrCall3RectSideTDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectSideTDisconn };

static const TAknsItemID KAknsIIDQsnFrCall3RectSideBDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectSideBDisconn };

static const TAknsItemID KAknsIIDQsnFrCall3RectSideLDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectSideLDisconn };

static const TAknsItemID KAknsIIDQsnFrCall3RectSideRDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectSideRDisconn };

static const TAknsItemID KAknsIIDQsnFrCall3RectCenterDisconn =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCall3RectCenterDisconn};

// POC frames

static const TAknsItemID KAknsIIDQsnFrCallPocAct =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCallPocAct };

static const TAknsItemID KAknsIIDQsnFrCallPocActIdle =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCallPocActIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocInact =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCallPocInact };

static const TAknsItemID KAknsIIDQsnFrCallPocInactIdle =
    { EAknsMajorCallstatus, EAknsMinorQsnFrCallPocInactIdle };

// ----------------------------------------------------------------------------
// EAknsMajorCalendar item IDs
// ----------------------------------------------------------------------------

// General calendar frame

static const TAknsItemID KAknsIIDQsnFrCale =
    { EAknsMajorCalendar, EAknsMinorQsnFrCale };

static const TAknsItemID KAknsIIDQsnFrCaleCornerTl =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleCornerTl };

static const TAknsItemID KAknsIIDQsnFrCaleCornerTr =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleCornerTr };

static const TAknsItemID KAknsIIDQsnFrCaleCornerBl =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleCornerBl };

static const TAknsItemID KAknsIIDQsnFrCaleCornerBr =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleCornerBr };

static const TAknsItemID KAknsIIDQsnFrCaleSideT =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideT };

static const TAknsItemID KAknsIIDQsnFrCaleSideB =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideB };

static const TAknsItemID KAknsIIDQsnFrCaleSideL =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideL };

static const TAknsItemID KAknsIIDQsnFrCaleSideR =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideR };

static const TAknsItemID KAknsIIDQsnFrCaleCenter =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleCenter };

// Calendar frame for holiday event

static const TAknsItemID KAknsIIDQsnFrCaleHoli =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHoli };

static const TAknsItemID KAknsIIDQsnFrCaleHoliCornerTl =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHoliCornerTl };

static const TAknsItemID KAknsIIDQsnFrCaleHoliCornerTr =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHoliCornerTr };

static const TAknsItemID KAknsIIDQsnFrCaleHoliCornerBl =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHoliCornerBl };

static const TAknsItemID KAknsIIDQsnFrCaleHoliCornerBr =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHoliCornerBr };

static const TAknsItemID KAknsIIDQsnFrCaleHoliSideT =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHoliSideT };

static const TAknsItemID KAknsIIDQsnFrCaleHoliSideB =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHoliSideB };

static const TAknsItemID KAknsIIDQsnFrCaleHoliSideL =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHoliSideL };

static const TAknsItemID KAknsIIDQsnFrCaleHoliSideR =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHoliSideR };

static const TAknsItemID KAknsIIDQsnFrCaleHoliCenter =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHoliCenter };

// Calendar icons

static const TAknsItemID KAknsIIDQgnIndiCdrBirthday =
    { EAknsMajorCalendar, EAknsMinorQgnIndiCdrBirthday };

static const TAknsItemID KAknsIIDQgnIndiCdrMeeting =
    { EAknsMajorCalendar, EAknsMinorQgnIndiCdrMeeting };

static const TAknsItemID KAknsIIDQgnIndiCdrReminder =
    { EAknsMajorCalendar, EAknsMinorQgnIndiCdrReminder };

// Calendar heading frame

static const TAknsItemID KAknsIIDQsnFrCaleHeading =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHeading };

static const TAknsItemID KAknsIIDQsnFrCaleHeadingCornerTl =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHeadingCornerTl };

static const TAknsItemID KAknsIIDQsnFrCaleHeadingCornerTr =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHeadingCornerTr };

static const TAknsItemID KAknsIIDQsnFrCaleHeadingCornerBl =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHeadingCornerBl };

static const TAknsItemID KAknsIIDQsnFrCaleHeadingCornerBr =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHeadingCornerBr };

static const TAknsItemID KAknsIIDQsnFrCaleHeadingSideT =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHeadingSideT };

static const TAknsItemID KAknsIIDQsnFrCaleHeadingSideB =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHeadingSideB };

static const TAknsItemID KAknsIIDQsnFrCaleHeadingSideL =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHeadingSideL };

static const TAknsItemID KAknsIIDQsnFrCaleHeadingSideR =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHeadingSideR };

static const TAknsItemID KAknsIIDQsnFrCaleHeadingCenter =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleHeadingCenter };

// Calendar side frame

static const TAknsItemID KAknsIIDQsnFrCaleSide =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSide };

static const TAknsItemID KAknsIIDQsnFrCaleSideCornerTl =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideCornerTl };

static const TAknsItemID KAknsIIDQsnFrCaleSideCornerTr =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideCornerTr };

static const TAknsItemID KAknsIIDQsnFrCaleSideCornerBl =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideCornerBl };

static const TAknsItemID KAknsIIDQsnFrCaleSideCornerBr =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideCornerBr };

static const TAknsItemID KAknsIIDQsnFrCaleSideSideT =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideSideT };

static const TAknsItemID KAknsIIDQsnFrCaleSideSideB =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideSideB };

static const TAknsItemID KAknsIIDQsnFrCaleSideSideL =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideSideL };

static const TAknsItemID KAknsIIDQsnFrCaleSideSideR =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideSideR };

static const TAknsItemID KAknsIIDQsnFrCaleSideCenter =
    { EAknsMajorCalendar, EAknsMinorQsnFrCaleSideCenter };

// ----------------------------------------------------------------------------
// EAknsMajorPinboard item IDs
// ----------------------------------------------------------------------------

// Pinboard frame

static const TAknsItemID KAknsIIDQsnFrPinb =
    { EAknsMajorPinboard, EAknsMinorQsnFrPinb };

static const TAknsItemID KAknsIIDQsnFrPinbCornerTl =
    { EAknsMajorPinboard, EAknsMinorQsnFrPinbCornerTl };

static const TAknsItemID KAknsIIDQsnFrPinbCornerTr =
    { EAknsMajorPinboard, EAknsMinorQsnFrPinbCornerTr };

static const TAknsItemID KAknsIIDQsnFrPinbCornerBl =
    { EAknsMajorPinboard, EAknsMinorQsnFrPinbCornerBl };

static const TAknsItemID KAknsIIDQsnFrPinbCornerBr =
    { EAknsMajorPinboard, EAknsMinorQsnFrPinbCornerBr };

static const TAknsItemID KAknsIIDQsnFrPinbSideT =
    { EAknsMajorPinboard, EAknsMinorQsnFrPinbSideT };

static const TAknsItemID KAknsIIDQsnFrPinbSideB =
    { EAknsMajorPinboard, EAknsMinorQsnFrPinbSideB };

static const TAknsItemID KAknsIIDQsnFrPinbSideL =
    { EAknsMajorPinboard, EAknsMinorQsnFrPinbSideL };

static const TAknsItemID KAknsIIDQsnFrPinbSideR =
    { EAknsMajorPinboard, EAknsMinorQsnFrPinbSideR };

// Pinboard wallpaper

static const TAknsItemID KAknsIIDQsnFrPinbCenterWp =
    { EAknsMajorPinboard, EAknsMinorQsnFrPinbCenterWp };

// Icon group "pinb"

static const TAknsItemID KAknsIIDQgnPropPinbLinkUnknownId =
    { EAknsMajorPinboard, EAknsMinorQgnPropPinbLinkUnknownId };

static const TAknsItemID KAknsIIDQgnIndiFindTitle =
    { EAknsMajorPinboard, EAknsMinorQgnIndiFindTitle };

static const TAknsItemID KAknsIIDQgnPropPinbHelp =
    { EAknsMajorPinboard, EAknsMinorQgnPropPinbHelp };

// ----------------------------------------------------------------------------
// EAknsMajorCbsuiApp item IDs
// ----------------------------------------------------------------------------

// List icons

static const TAknsItemID KAknsIIDQgnPropCbMsg =
    { EAknsMajorCbsuiApp, EAknsMinorQgnPropCbMsg };

static const TAknsItemID KAknsIIDQgnPropCbMsgUnread =
    { EAknsMajorCbsuiApp, EAknsMinorQgnPropCbMsgUnread };

static const TAknsItemID KAknsIIDQgnPropCbSubs =
    { EAknsMajorCbsuiApp, EAknsMinorQgnPropCbSubs };

static const TAknsItemID KAknsIIDQgnPropCbSubsUnread =
    { EAknsMajorCbsuiApp, EAknsMinorQgnPropCbSubsUnread };

static const TAknsItemID KAknsIIDQgnPropCbUnsubs =
    { EAknsMajorCbsuiApp, EAknsMinorQgnPropCbUnsubs };

static const TAknsItemID KAknsIIDQgnPropCbUnsubsUnread =
    { EAknsMajorCbsuiApp, EAknsMinorQgnPropCbUnsubsUnread };

// ----------------------------------------------------------------------------
// EAknsMajorSound item IDs
// ----------------------------------------------------------------------------

static const TAknsItemID KAknsIIDSoundRingingTone =
    { EAknsMajorSound, EAknsMinorSoundRingingTone };

static const TAknsItemID KAknsIIDSoundMessageAlert =
    { EAknsMajorSound, EAknsMinorSoundMessageAlert };

// ----------------------------------------------------------------------------
// EAknsMajorProperty item IDs
// ----------------------------------------------------------------------------

static const TAknsItemID KAknsIIDPropertyListSeparatorLines =
    { EAknsMajorProperty, EAknsMinorPropertyListSeparatorLines };

static const TAknsItemID KAknsIIDPropertyMessageHeaderLines =
    { EAknsMajorProperty, EAknsMinorPropertyMessageHeaderLines };

static const TAknsItemID KAknsIIDPropertyAnalogueClockDate =
    { EAknsMajorProperty, EAknsMinorPropertyAnalogueClockDate };

static const TAknsItemID KAknsIIDPropertyMorphingTime =
    { EAknsMajorProperty, EAknsMinorPropertyMorphingTime };

static const TAknsItemID KAknsIIDPropertyNoteSlidingMode =
    { EAknsMajorProperty, EAknsMinorPropertyNoteSlidingMode };

static const TAknsItemID KAknsIIDPropertyAnimBgParam =
    { EAknsMajorProperty, EAknsMinorPropertyAnimBgParam };

// ----------------------------------------------------------------------------
// EAknsMajorGeneric item IDs
// ----------------------------------------------------------------------------

static const TAknsItemID KAknsIIDQgnBtConnectOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnBtConnectOn };

static const TAknsItemID KAknsIIDQgnGrafBarFrame =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarFrame };

static const TAknsItemID KAknsIIDQgnGrafBarFrameLong =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarFrameLong };

static const TAknsItemID KAknsIIDQgnGrafBarFrameShort =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarFrameShort };

static const TAknsItemID KAknsIIDQgnGrafBarFrameVorec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarFrameVorec };

static const TAknsItemID KAknsIIDQgnGrafBarProgress =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarProgress };

static const TAknsItemID KAknsIIDQgnGrafBarWait1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWait1 };

static const TAknsItemID KAknsIIDQgnGrafBarWait2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWait2 };

static const TAknsItemID KAknsIIDQgnGrafBarWait3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWait3 };

static const TAknsItemID KAknsIIDQgnGrafBarWait4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWait4 };

static const TAknsItemID KAknsIIDQgnGrafBarWait5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWait5 };

static const TAknsItemID KAknsIIDQgnGrafBarWait6 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWait6 };

static const TAknsItemID KAknsIIDQgnGrafBarWait7 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWait7 };

static const TAknsItemID KAknsIIDQgnGrafBlidCompass =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidCompass };

static const TAknsItemID KAknsIIDQgnGrafCalcDisplay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCalcDisplay };

static const TAknsItemID KAknsIIDQgnGrafCalcPaper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCalcPaper };

static const TAknsItemID KAknsIIDQgnGrafCallFirstOneActiveEmergency =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCallFirstOneActiveEmergency };

static const TAknsItemID KAknsIIDQgnGrafCallTwoActiveEmergency =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCallTwoActiveEmergency };

static const TAknsItemID KAknsIIDQgnGrafCallVideoOutBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCallVideoOutBg };

static const TAknsItemID KAknsIIDQgnGrafMmsAudioInserted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsAudioInserted };

static const TAknsItemID KAknsIIDQgnGrafMmsAudioPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsAudioPlay };

static const TAknsItemID KAknsIIDQgnGrafMmsEdit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsEdit };

static const TAknsItemID KAknsIIDQgnGrafMmsInsertedVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsInsertedVideo };

static const TAknsItemID KAknsIIDQgnGrafMmsInsertedVideoEdit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsInsertedVideoEdit };

static const TAknsItemID KAknsIIDQgnGrafMmsInsertedVideoView =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsInsertedVideoView };

static const TAknsItemID KAknsIIDQgnGrafMmsInsertImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsInsertImage };

static const TAknsItemID KAknsIIDQgnGrafMmsInsertVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsInsertVideo };

static const TAknsItemID KAknsIIDQgnGrafMmsObjectCorrupt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsObjectCorrupt };

static const TAknsItemID KAknsIIDQgnGrafMmsPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsPlay };

static const TAknsItemID KAknsIIDQgnGrafMmsTransBar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTransBar };

static const TAknsItemID KAknsIIDQgnGrafMmsTransClock =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTransClock };

static const TAknsItemID KAknsIIDQgnGrafMmsTransEye =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTransEye };

static const TAknsItemID KAknsIIDQgnGrafMmsTransFade =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTransFade };

static const TAknsItemID KAknsIIDQgnGrafMmsTransHeart =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTransHeart };

static const TAknsItemID KAknsIIDQgnGrafMmsTransIris =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTransIris };

static const TAknsItemID KAknsIIDQgnGrafMmsTransNone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTransNone };

static const TAknsItemID KAknsIIDQgnGrafMmsTransPush =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTransPush };

static const TAknsItemID KAknsIIDQgnGrafMmsTransSlide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTransSlide };

static const TAknsItemID KAknsIIDQgnGrafMmsTransSnake =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTransSnake };

static const TAknsItemID KAknsIIDQgnGrafMmsTransStar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTransStar };

static const TAknsItemID KAknsIIDQgnGrafMmsUnedit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsUnedit };

static const TAknsItemID KAknsIIDQgnGrafMpSplash =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMpSplash };

static const TAknsItemID KAknsIIDQgnGrafNoteCont =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNoteCont };

static const TAknsItemID KAknsIIDQgnGrafNoteStart =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNoteStart };

static const TAknsItemID KAknsIIDQgnGrafPhoneLocked =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPhoneLocked };

static const TAknsItemID KAknsIIDQgnGrafPopup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPopup };

static const TAknsItemID KAknsIIDQgnGrafQuickEight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafQuickEight };

static const TAknsItemID KAknsIIDQgnGrafQuickFive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafQuickFive };

static const TAknsItemID KAknsIIDQgnGrafQuickFour =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafQuickFour };

static const TAknsItemID KAknsIIDQgnGrafQuickNine =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafQuickNine };

static const TAknsItemID KAknsIIDQgnGrafQuickOne =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafQuickOne };

static const TAknsItemID KAknsIIDQgnGrafQuickSeven =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafQuickSeven };

static const TAknsItemID KAknsIIDQgnGrafQuickSix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafQuickSix };

static const TAknsItemID KAknsIIDQgnGrafQuickThree =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafQuickThree };

static const TAknsItemID KAknsIIDQgnGrafQuickTwo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafQuickTwo };

static const TAknsItemID KAknsIIDQgnGrafStatusSmallProg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafStatusSmallProg };

static const TAknsItemID KAknsIIDQgnGrafWmlSplash =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafWmlSplash };

static const TAknsItemID KAknsIIDQgnImstatEmpty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnImstatEmpty };

static const TAknsItemID KAknsIIDQgnIndiAccuracyOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAccuracyOff };

static const TAknsItemID KAknsIIDQgnIndiAccuracyOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAccuracyOn };

static const TAknsItemID KAknsIIDQgnIndiAlarmAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAlarmAdd };

static const TAknsItemID KAknsIIDQgnIndiAlsLine2Add =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAlsLine2Add };

static const TAknsItemID KAknsIIDQgnIndiAmInstMmcAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAmInstMmcAdd };

static const TAknsItemID KAknsIIDQgnIndiAmNotInstAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAmNotInstAdd };

static const TAknsItemID KAknsIIDQgnIndiAttachementAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAttachementAdd };

static const TAknsItemID KAknsIIDQgnIndiAttachAudio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAttachAudio };

static const TAknsItemID KAknsIIDQgnIndiAttachGene =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAttachGene };

static const TAknsItemID KAknsIIDQgnIndiAttachImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAttachImage };

static const TAknsItemID KAknsIIDQgnIndiAttachUnsupportAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAttachUnsupportAdd };

static const TAknsItemID KAknsIIDQgnIndiBtAudioConnectedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBtAudioConnectedAdd };

static const TAknsItemID KAknsIIDQgnIndiBtAudioSelectedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBtAudioSelectedAdd };

static const TAknsItemID KAknsIIDQgnIndiBtPairedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBtPairedAdd };

static const TAknsItemID KAknsIIDQgnIndiBtTrustedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBtTrustedAdd };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonDivide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonDivide };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonDividePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonDividePressed };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonDown };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonDownInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonDownInactive };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonDownPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonDownPressed };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonEquals =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonEquals };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonEqualsPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonEqualsPressed };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonMinus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonMinus };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonMinusPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonMinusPressed };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonMr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonMr };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonMrPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonMrPressed };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonMs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonMs };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonMsPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonMsPressed };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonMultiply =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonMultiply };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonMultiplyPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonMultiplyPressed };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonPercent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonPercent };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonPercentInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonPercentInactive };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonPercentPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonPercentPressed };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonPlus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonPlus };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonPlusPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonPlusPressed };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonSign =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonSign };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonSignInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonSignInactive };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonSignPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonSignPressed };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonSquareroot =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonSquareroot };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonSquarerootInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonSquarerootInactive };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonSquarerootPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonSquarerootPressed };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonUp };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonUpInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonUpInactive };

static const TAknsItemID KAknsIIDQgnIndiCalcButtonUpPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcButtonUpPressed };

static const TAknsItemID KAknsIIDQgnIndiCallActiveEmergency =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallActiveEmergency };

static const TAknsItemID KAknsIIDQgnIndiCallCypheringOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallCypheringOff };

static const TAknsItemID KAknsIIDQgnIndiCallData =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallData };

static const TAknsItemID KAknsIIDQgnIndiCallDataDiv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallDataDiv };

static const TAknsItemID KAknsIIDQgnIndiCallDataHscsd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallDataHscsd };

static const TAknsItemID KAknsIIDQgnIndiCallDataHscsdDiv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallDataHscsdDiv };

static const TAknsItemID KAknsIIDQgnIndiCallDataHscsdWaiting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallDataHscsdWaiting };

static const TAknsItemID KAknsIIDQgnIndiCallDataWaiting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallDataWaiting };

static const TAknsItemID KAknsIIDQgnIndiCallDiverted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallDiverted };

static const TAknsItemID KAknsIIDQgnIndiCallFax =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallFax };

static const TAknsItemID KAknsIIDQgnIndiCallFaxDiv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallFaxDiv };

static const TAknsItemID KAknsIIDQgnIndiCallFaxWaiting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallFaxWaiting };

static const TAknsItemID KAknsIIDQgnIndiCallLine2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallLine2 };

static const TAknsItemID KAknsIIDQgnIndiCallVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVideo };

static const TAknsItemID KAknsIIDQgnIndiCallVideoAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVideoAdd };

static const TAknsItemID KAknsIIDQgnIndiCallVideoCallsta =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVideoCallsta };

static const TAknsItemID KAknsIIDQgnIndiCallWaitingCyphOff1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallWaitingCyphOff1 };

static const TAknsItemID KAknsIIDQgnIndiCamsExpo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsExpo };

static const TAknsItemID KAknsIIDQgnIndiCamsFlashOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsFlashOff };

static const TAknsItemID KAknsIIDQgnIndiCamsFlashOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsFlashOn };

static const TAknsItemID KAknsIIDQgnIndiCamsMicOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsMicOff };

static const TAknsItemID KAknsIIDQgnIndiCamsMmc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsMmc };

static const TAknsItemID KAknsIIDQgnIndiCamsNight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsNight };

static const TAknsItemID KAknsIIDQgnIndiCamsPaused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsPaused };

static const TAknsItemID KAknsIIDQgnIndiCamsRec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsRec };

static const TAknsItemID KAknsIIDQgnIndiCamsTimer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTimer };

static const TAknsItemID KAknsIIDQgnIndiCamsZoomBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsZoomBg };

static const TAknsItemID KAknsIIDQgnIndiCamsZoomElevator =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsZoomElevator };

static const TAknsItemID KAknsIIDQgnIndiCamZoom2Video =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamZoom2Video };

static const TAknsItemID KAknsIIDQgnIndiCbHotAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCbHotAdd };

static const TAknsItemID KAknsIIDQgnIndiCbKeptAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCbKeptAdd };

static const TAknsItemID KAknsIIDQgnIndiCdrDummy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrDummy };

static const TAknsItemID KAknsIIDQgnIndiCdrEventDummy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrEventDummy };

static const TAknsItemID KAknsIIDQgnIndiCdrEventGrayed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrEventGrayed };

static const TAknsItemID KAknsIIDQgnIndiCdrEventMixed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrEventMixed };

static const TAknsItemID KAknsIIDQgnIndiCdrEventPrivate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrEventPrivate };

static const TAknsItemID KAknsIIDQgnIndiCdrEventPrivateDimm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrEventPrivateDimm };

static const TAknsItemID KAknsIIDQgnIndiCdrEventPublic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrEventPublic };

static const TAknsItemID KAknsIIDQgnIndiCheckboxOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCheckboxOff };

static const TAknsItemID KAknsIIDQgnIndiCheckboxOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCheckboxOn };

static const TAknsItemID KAknsIIDQgnIndiChiFindNumeric =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiChiFindNumeric };

static const TAknsItemID KAknsIIDQgnIndiChiFindPinyin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiChiFindPinyin };

static const TAknsItemID KAknsIIDQgnIndiChiFindSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiChiFindSmall };

static const TAknsItemID KAknsIIDQgnIndiChiFindStrokeSimple =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiChiFindStrokeSimple };

static const TAknsItemID KAknsIIDQgnIndiChiFindStrokeSymbol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiChiFindStrokeSymbol };

static const TAknsItemID KAknsIIDQgnIndiChiFindStrokeTrad =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiChiFindStrokeTrad };

static const TAknsItemID KAknsIIDQgnIndiChiFindZhuyin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiChiFindZhuyin };

static const TAknsItemID KAknsIIDQgnIndiChiFindZhuyinSymbol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiChiFindZhuyinSymbol };

static const TAknsItemID KAknsIIDQgnIndiConnectionAlwaysAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiConnectionAlwaysAdd };

static const TAknsItemID KAknsIIDQgnIndiConnectionInactiveAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiConnectionInactiveAdd };

static const TAknsItemID KAknsIIDQgnIndiConnectionOnAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiConnectionOnAdd };

static const TAknsItemID KAknsIIDQgnIndiDrmRightsExpAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDrmRightsExpAdd };

static const TAknsItemID KAknsIIDQgnIndiDstAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDstAdd };

static const TAknsItemID KAknsIIDQgnIndiDycAvailAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDycAvailAdd };

static const TAknsItemID KAknsIIDQgnIndiDycDiscreetAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDycDiscreetAdd };

static const TAknsItemID KAknsIIDQgnIndiDycDtMobileAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDycDtMobileAdd };

static const TAknsItemID KAknsIIDQgnIndiDycDtPcAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDycDtPcAdd };

static const TAknsItemID KAknsIIDQgnIndiDycNotAvailAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDycNotAvailAdd };

static const TAknsItemID KAknsIIDQgnIndiDycNotPublishAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDycNotPublishAdd };

static const TAknsItemID KAknsIIDQgnIndiEarpiece =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiEarpiece };

static const TAknsItemID KAknsIIDQgnIndiEarpieceActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiEarpieceActive };

static const TAknsItemID KAknsIIDQgnIndiEarpieceMuted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiEarpieceMuted };

static const TAknsItemID KAknsIIDQgnIndiEarpiecePassive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiEarpiecePassive };

static const TAknsItemID KAknsIIDQgnIndiFepArrowDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepArrowDown };

static const TAknsItemID KAknsIIDQgnIndiFepArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepArrowLeft };

static const TAknsItemID KAknsIIDQgnIndiFepArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepArrowRight };

static const TAknsItemID KAknsIIDQgnIndiFepArrowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepArrowUp };

static const TAknsItemID KAknsIIDQgnIndiFindGlassPinb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFindGlassPinb };

static const TAknsItemID KAknsIIDQgnIndiImFriendOffAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImFriendOffAdd };

static const TAknsItemID KAknsIIDQgnIndiImFriendOnAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImFriendOnAdd };

static const TAknsItemID KAknsIIDQgnIndiImImsgAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImImsgAdd };

static const TAknsItemID KAknsIIDQgnIndiImWatchAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImWatchAdd };

static const TAknsItemID KAknsIIDQgnIndiItemNotShown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiItemNotShown };

static const TAknsItemID KAknsIIDQgnIndiLevelBack =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiLevelBack };

static const TAknsItemID KAknsIIDQgnIndiMarkedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMarkedAdd };

static const TAknsItemID KAknsIIDQgnIndiMarkedGridAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMarkedGridAdd };

static const TAknsItemID KAknsIIDQgnIndiMic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMic };

static const TAknsItemID KAknsIIDQgnIndiMissedCallOne =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMissedCallOne };

static const TAknsItemID KAknsIIDQgnIndiMissedCallTwo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMissedCallTwo };

static const TAknsItemID KAknsIIDQgnIndiMissedMessOne =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMissedMessOne };

static const TAknsItemID KAknsIIDQgnIndiMissedMessTwo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMissedMessTwo };

static const TAknsItemID KAknsIIDQgnIndiMmcAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmcAdd };

static const TAknsItemID KAknsIIDQgnIndiMmcMarkedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmcMarkedAdd };

static const TAknsItemID KAknsIIDQgnIndiMmsArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsArrowLeft };

static const TAknsItemID KAknsIIDQgnIndiMmsArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsArrowRight };

static const TAknsItemID KAknsIIDQgnIndiMmsPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsPause };

static const TAknsItemID KAknsIIDQgnIndiMmsSpeakerActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsSpeakerActive };

static const TAknsItemID KAknsIIDQgnIndiMmsTemplateImageCorrupt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsTemplateImageCorrupt };

static const TAknsItemID KAknsIIDQgnIndiMpButtonForw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonForw };

static const TAknsItemID KAknsIIDQgnIndiMpButtonForwInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonForwInact };

static const TAknsItemID KAknsIIDQgnIndiMpButtonNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonNext };

static const TAknsItemID KAknsIIDQgnIndiMpButtonNextInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonNextInact };

static const TAknsItemID KAknsIIDQgnIndiMpButtonPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonPause };

static const TAknsItemID KAknsIIDQgnIndiMpButtonPauseInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonPauseInact };

static const TAknsItemID KAknsIIDQgnIndiMpButtonPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonPlay };

static const TAknsItemID KAknsIIDQgnIndiMpButtonPlayInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonPlayInact };

static const TAknsItemID KAknsIIDQgnIndiMpButtonPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonPrev };

static const TAknsItemID KAknsIIDQgnIndiMpButtonPrevInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonPrevInact };

static const TAknsItemID KAknsIIDQgnIndiMpButtonRew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonRew };

static const TAknsItemID KAknsIIDQgnIndiMpButtonRewInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonRewInact };

static const TAknsItemID KAknsIIDQgnIndiMpButtonStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonStop };

static const TAknsItemID KAknsIIDQgnIndiMpButtonStopInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpButtonStopInact };

static const TAknsItemID KAknsIIDQgnIndiMpCorruptedFileAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpCorruptedFileAdd };

static const TAknsItemID KAknsIIDQgnIndiMpPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpPause };

static const TAknsItemID KAknsIIDQgnIndiMpPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpPlay };

static const TAknsItemID KAknsIIDQgnIndiMpPlaylistArrowAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpPlaylistArrowAdd };

static const TAknsItemID KAknsIIDQgnIndiMpRandom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpRandom };

static const TAknsItemID KAknsIIDQgnIndiMpRandomRepeat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpRandomRepeat };

static const TAknsItemID KAknsIIDQgnIndiMpRepeat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpRepeat };

static const TAknsItemID KAknsIIDQgnIndiMpStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpStop };

static const TAknsItemID KAknsIIDQgnIndiObjectGene =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiObjectGene };

static const TAknsItemID KAknsIIDQgnIndiPaused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPaused };

static const TAknsItemID KAknsIIDQgnIndiPinSpace =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPinSpace };

static const TAknsItemID KAknsIIDQgnIndiQdialAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiQdialAdd };

static const TAknsItemID KAknsIIDQgnIndiRadiobuttOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadiobuttOff };

static const TAknsItemID KAknsIIDQgnIndiRadiobuttOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadiobuttOn };

static const TAknsItemID KAknsIIDQgnIndiRepeatAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRepeatAdd };

static const TAknsItemID KAknsIIDQgnIndiSettProtectedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSettProtectedAdd };

static const TAknsItemID KAknsIIDQgnIndiSignalActiveCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalActiveCdma };

static const TAknsItemID KAknsIIDQgnIndiSignalDormantCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalDormantCdma };

static const TAknsItemID KAknsIIDQgnIndiSignalGprsAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalGprsAttach };

static const TAknsItemID KAknsIIDQgnIndiSignalGprsContext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalGprsContext };

static const TAknsItemID KAknsIIDQgnIndiSignalGprsMultipdp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalGprsMultipdp };

static const TAknsItemID KAknsIIDQgnIndiSignalGprsSuspended =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalGprsSuspended };

static const TAknsItemID KAknsIIDQgnIndiSignalPdAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalPdAttach };

static const TAknsItemID KAknsIIDQgnIndiSignalPdContext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalPdContext };

static const TAknsItemID KAknsIIDQgnIndiSignalPdMultipdp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalPdMultipdp };

static const TAknsItemID KAknsIIDQgnIndiSignalPdSuspended =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalPdSuspended };

static const TAknsItemID KAknsIIDQgnIndiSignalWcdmaAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalWcdmaAttach };

static const TAknsItemID KAknsIIDQgnIndiSignalWcdmaContext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalWcdmaContext };

static const TAknsItemID KAknsIIDQgnIndiSignalWcdmaIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalWcdmaIcon };

static const TAknsItemID KAknsIIDQgnIndiSignalWcdmaMultidp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalWcdmaMultidp };

static const TAknsItemID KAknsIIDQgnIndiSignalWcdmaMultipdp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalWcdmaMultipdp };

static const TAknsItemID KAknsIIDQgnIndiSliderNavi =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSliderNavi };

static const TAknsItemID KAknsIIDQgnIndiSpeaker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSpeaker };

static const TAknsItemID KAknsIIDQgnIndiSpeakerActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSpeakerActive };

static const TAknsItemID KAknsIIDQgnIndiSpeakerMuted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSpeakerMuted };

static const TAknsItemID KAknsIIDQgnIndiSpeakerPassive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSpeakerPassive };

static const TAknsItemID KAknsIIDQgnIndiThaiFindSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiThaiFindSmall };

static const TAknsItemID KAknsIIDQgnIndiTodoHighAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTodoHighAdd };

static const TAknsItemID KAknsIIDQgnIndiTodoLowAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTodoLowAdd };

static const TAknsItemID KAknsIIDQgnIndiVoiceAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVoiceAdd };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonForw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonForw };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonForwInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonForwInactive };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonForwPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonForwPressed };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonPause };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonPauseInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonPauseInactive };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonPausePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonPausePressed };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonPlay };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonPlayInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonPlayInactive };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonPlayPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonPlayPressed };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonRec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonRec };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonRecInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonRecInactive };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonRecPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonRecPressed };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonRew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonRew };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonRewInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonRewInactive };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonRewPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonRewPressed };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonStop };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonStopInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonStopInactive };

static const TAknsItemID KAknsIIDQgnIndiVorecButtonStopPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecButtonStopPressed };

static const TAknsItemID KAknsIIDQgnIndiWmlCsdAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWmlCsdAdd };

static const TAknsItemID KAknsIIDQgnIndiWmlGprsAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWmlGprsAdd };

static const TAknsItemID KAknsIIDQgnIndiWmlHscsdAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWmlHscsdAdd };

static const TAknsItemID KAknsIIDQgnIndiWmlObject =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWmlObject };

static const TAknsItemID KAknsIIDQgnIndiXhtmlMmc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXhtmlMmc };

static const TAknsItemID KAknsIIDQgnIndiZoomDir =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiZoomDir };

static const TAknsItemID KAknsIIDQgnLogoEmpty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnLogoEmpty };

static const TAknsItemID KAknsIIDQgnNoteAlarmAlert =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteAlarmAlert };

static const TAknsItemID KAknsIIDQgnNoteAlarmCalendar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteAlarmCalendar };

static const TAknsItemID KAknsIIDQgnNoteAlarmMisc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteAlarmMisc };

static const TAknsItemID KAknsIIDQgnNoteBt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteBt };

static const TAknsItemID KAknsIIDQgnNoteBtPopup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteBtPopup };

static const TAknsItemID KAknsIIDQgnNoteCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteCall };

static const TAknsItemID KAknsIIDQgnNoteCopy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteCopy };

static const TAknsItemID KAknsIIDQgnNoteCsd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteCsd };

static const TAknsItemID KAknsIIDQgnNoteDycStatusChanged =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteDycStatusChanged };

static const TAknsItemID KAknsIIDQgnNoteEmpty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteEmpty };

static const TAknsItemID KAknsIIDQgnNoteGprs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteGprs };

static const TAknsItemID KAknsIIDQgnNoteImMessage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteImMessage };

static const TAknsItemID KAknsIIDQgnNoteMail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteMail };

static const TAknsItemID KAknsIIDQgnNoteMemory =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteMemory };

static const TAknsItemID KAknsIIDQgnNoteMessage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteMessage };

static const TAknsItemID KAknsIIDQgnNoteMms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteMms };

static const TAknsItemID KAknsIIDQgnNoteMove =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteMove };

static const TAknsItemID KAknsIIDQgnNoteRemoteMailbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteRemoteMailbox };

static const TAknsItemID KAknsIIDQgnNoteSim =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteSim };

static const TAknsItemID KAknsIIDQgnNoteSml =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteSml };

static const TAknsItemID KAknsIIDQgnNoteSmlServer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteSmlServer };

static const TAknsItemID KAknsIIDQgnNoteUrgentMessage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteUrgentMessage };

static const TAknsItemID KAknsIIDQgnNoteVoice =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteVoice };

static const TAknsItemID KAknsIIDQgnNoteVoiceFound =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteVoiceFound };

static const TAknsItemID KAknsIIDQgnNoteWarr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteWarr };

static const TAknsItemID KAknsIIDQgnNoteWml =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteWml };

static const TAknsItemID KAknsIIDQgnPropAlbumMusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumMusic };

static const TAknsItemID KAknsIIDQgnPropAlbumPhoto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumPhoto };

static const TAknsItemID KAknsIIDQgnPropAlbumVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumVideo };

static const TAknsItemID KAknsIIDQgnPropAmsGetNewSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAmsGetNewSub };

static const TAknsItemID KAknsIIDQgnPropAmMidlet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAmMidlet };

static const TAknsItemID KAknsIIDQgnPropAmSis =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAmSis };

static const TAknsItemID KAknsIIDQgnPropBatteryIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBatteryIcon };

static const TAknsItemID KAknsIIDQgnPropBlidCompassSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidCompassSub };

static const TAknsItemID KAknsIIDQgnPropBlidCompassTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidCompassTab3 };

static const TAknsItemID KAknsIIDQgnPropBlidLocationSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidLocationSub };

static const TAknsItemID KAknsIIDQgnPropBlidLocationTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidLocationTab3 };

static const TAknsItemID KAknsIIDQgnPropBlidNavigationSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidNavigationSub };

static const TAknsItemID KAknsIIDQgnPropBlidNavigationTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidNavigationTab3 };

static const TAknsItemID KAknsIIDQgnPropBrowserSelectfile =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBrowserSelectfile };

static const TAknsItemID KAknsIIDQgnPropBtCarkit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtCarkit };

static const TAknsItemID KAknsIIDQgnPropBtComputer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtComputer };

static const TAknsItemID KAknsIIDQgnPropBtDeviceTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtDeviceTab2 };

static const TAknsItemID KAknsIIDQgnPropBtHeadset =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtHeadset };

static const TAknsItemID KAknsIIDQgnPropBtMisc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtMisc };

static const TAknsItemID KAknsIIDQgnPropBtPhone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtPhone };

static const TAknsItemID KAknsIIDQgnPropBtSetTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtSetTab2 };

static const TAknsItemID KAknsIIDQgnPropCamsBright =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCamsBright };

static const TAknsItemID KAknsIIDQgnPropCamsBurst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCamsBurst };

static const TAknsItemID KAknsIIDQgnPropCamsContrast =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCamsContrast };

static const TAknsItemID KAknsIIDQgnPropCamsSetImageTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCamsSetImageTab2 };

static const TAknsItemID KAknsIIDQgnPropCamsSetVideoTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCamsSetVideoTab2 };

static const TAknsItemID KAknsIIDQgnPropCheckboxOffSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCheckboxOffSel };

static const TAknsItemID KAknsIIDQgnPropClkAlarmTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClkAlarmTab2 };

static const TAknsItemID KAknsIIDQgnPropClkDualTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClkDualTab2 };

static const TAknsItemID KAknsIIDQgnPropCmonGprsSuspended =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmonGprsSuspended };

static const TAknsItemID KAknsIIDQgnPropDrmExpForbid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmExpForbid };

static const TAknsItemID KAknsIIDQgnPropDrmExpForbidLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmExpForbidLarge };

static const TAknsItemID KAknsIIDQgnPropDrmRightsExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRightsExp };

static const TAknsItemID KAknsIIDQgnPropDrmRightsExpLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRightsExpLarge };

static const TAknsItemID KAknsIIDQgnPropDrmExpLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmExpLarge }; // Intentionally duplicate numeric IID

static const TAknsItemID KAknsIIDQgnPropDrmRightsHold =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRightsHold };

static const TAknsItemID KAknsIIDQgnPropDrmRightsMultiple =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRightsMultiple };

static const TAknsItemID KAknsIIDQgnPropDrmRightsValid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRightsValid };

static const TAknsItemID KAknsIIDQgnPropDrmSendForbid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmSendForbid };

static const TAknsItemID KAknsIIDQgnPropDscontentTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDscontentTab2 };

static const TAknsItemID KAknsIIDQgnPropDsprofileTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDsprofileTab2 };

static const TAknsItemID KAknsIIDQgnPropDycActWatch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDycActWatch };

static const TAknsItemID KAknsIIDQgnPropDycAvail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDycAvail };

static const TAknsItemID KAknsIIDQgnPropDycBlockedTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDycBlockedTab3 };

static const TAknsItemID KAknsIIDQgnPropDycDiscreet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDycDiscreet };

static const TAknsItemID KAknsIIDQgnPropDycNotAvail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDycNotAvail };

static const TAknsItemID KAknsIIDQgnPropDycNotPublish =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDycNotPublish };

static const TAknsItemID KAknsIIDQgnPropDycPrivateTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDycPrivateTab3 };

static const TAknsItemID KAknsIIDQgnPropDycPublicTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDycPublicTab3 };

static const TAknsItemID KAknsIIDQgnPropDycStatusTab1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDycStatusTab1 };

static const TAknsItemID KAknsIIDQgnPropEmpty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmpty };

static const TAknsItemID KAknsIIDQgnPropFileAllSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileAllSub };

static const TAknsItemID KAknsIIDQgnPropFileAllTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileAllTab4 };

static const TAknsItemID KAknsIIDQgnPropFileDownload =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileDownload };

static const TAknsItemID KAknsIIDQgnPropFileImagesSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileImagesSub };

static const TAknsItemID KAknsIIDQgnPropFileImagesTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileImagesTab4 };

static const TAknsItemID KAknsIIDQgnPropFileLinksSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileLinksSub };

static const TAknsItemID KAknsIIDQgnPropFileLinksTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileLinksTab4 };

static const TAknsItemID KAknsIIDQgnPropFileMusicSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileMusicSub };

static const TAknsItemID KAknsIIDQgnPropFileMusicTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileMusicTab4 };

static const TAknsItemID KAknsIIDQgnPropFileSounds =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileSounds };

static const TAknsItemID KAknsIIDQgnPropFileSoundsSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileSoundsSub };

static const TAknsItemID KAknsIIDQgnPropFileSoundsTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileSoundsTab4 };

static const TAknsItemID KAknsIIDQgnPropFileVideoSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileVideoSub };

static const TAknsItemID KAknsIIDQgnPropFileVideoTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileVideoTab4 };

static const TAknsItemID KAknsIIDQgnPropFmgrDycLogos =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrDycLogos };

static const TAknsItemID KAknsIIDQgnPropFmgrFileApps =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrFileApps };

static const TAknsItemID KAknsIIDQgnPropFmgrFileCompo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrFileCompo };

static const TAknsItemID KAknsIIDQgnPropFmgrFileGms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrFileGms };

static const TAknsItemID KAknsIIDQgnPropFmgrFileImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrFileImage };

static const TAknsItemID KAknsIIDQgnPropFmgrFileLink =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrFileLink };

static const TAknsItemID KAknsIIDQgnPropFmgrFilePlaylist =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrFilePlaylist };

static const TAknsItemID KAknsIIDQgnPropFmgrFileSound =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrFileSound };

static const TAknsItemID KAknsIIDQgnPropFmgrFileVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrFileVideo };

static const TAknsItemID KAknsIIDQgnPropFmgrFileVoicerec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrFileVoicerec };

static const TAknsItemID KAknsIIDQgnPropFolder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolder };

static const TAknsItemID KAknsIIDQgnPropFolderSmsTab1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderSmsTab1 };

static const TAknsItemID KAknsIIDQgnPropGroupOpenTab1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropGroupOpenTab1 };

static const TAknsItemID KAknsIIDQgnPropGroupTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropGroupTab2 };

static const TAknsItemID KAknsIIDQgnPropGroupTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropGroupTab3 };

static const TAknsItemID KAknsIIDQgnPropImageOpenTab1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageOpenTab1 };

static const TAknsItemID KAknsIIDQgnPropImFriendOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendOff };

static const TAknsItemID KAknsIIDQgnPropImFriendOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendOn };

static const TAknsItemID KAknsIIDQgnPropImFriendTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendTab4 };

static const TAknsItemID KAknsIIDQgnPropImIboxNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImIboxNew };

static const TAknsItemID KAknsIIDQgnPropImIboxTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImIboxTab4 };

static const TAknsItemID KAknsIIDQgnPropImImsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImImsg };

static const TAknsItemID KAknsIIDQgnPropImJoinedNotSaved =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImJoinedNotSaved };

static const TAknsItemID KAknsIIDQgnPropImListTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImListTab4 };

static const TAknsItemID KAknsIIDQgnPropImMany =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImMany };

static const TAknsItemID KAknsIIDQgnPropImNewInvit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImNewInvit };

static const TAknsItemID KAknsIIDQgnPropImNonuserCreatedSavedActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImNonuserCreatedSavedActive };

static const TAknsItemID KAknsIIDQgnPropImNonuserCreatedSavedInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImNonuserCreatedSavedInactive };

static const TAknsItemID KAknsIIDQgnPropImSaved =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSaved };

static const TAknsItemID KAknsIIDQgnPropImSavedChat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSavedChat };

static const TAknsItemID KAknsIIDQgnPropImSavedChatTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSavedChatTab4 };

static const TAknsItemID KAknsIIDQgnPropImSavedConv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSavedConv };

static const TAknsItemID KAknsIIDQgnPropImSmileysAngry =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysAngry };

static const TAknsItemID KAknsIIDQgnPropImSmileysBored =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysBored };

static const TAknsItemID KAknsIIDQgnPropImSmileysCrying =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysCrying };

static const TAknsItemID KAknsIIDQgnPropImSmileysGlasses =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysGlasses };

static const TAknsItemID KAknsIIDQgnPropImSmileysHappy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysHappy };

static const TAknsItemID KAknsIIDQgnPropImSmileysIndif =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysIndif };

static const TAknsItemID KAknsIIDQgnPropImSmileysKiss =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysKiss };

static const TAknsItemID KAknsIIDQgnPropImSmileysLaugh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysLaugh };

static const TAknsItemID KAknsIIDQgnPropImSmileysRobot =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysRobot };

static const TAknsItemID KAknsIIDQgnPropImSmileysSad =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysSad };

static const TAknsItemID KAknsIIDQgnPropImSmileysShock =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysShock };

static const TAknsItemID KAknsIIDQgnPropImSmileysSkeptical =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysSkeptical };

static const TAknsItemID KAknsIIDQgnPropImSmileysSleepy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysSleepy };

static const TAknsItemID KAknsIIDQgnPropImSmileysSunglasses =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysSunglasses };

static const TAknsItemID KAknsIIDQgnPropImSmileysSurprise =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysSurprise };

static const TAknsItemID KAknsIIDQgnPropImSmileysTired =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysTired };

static const TAknsItemID KAknsIIDQgnPropImSmileysVeryhappy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysVeryhappy };

static const TAknsItemID KAknsIIDQgnPropImSmileysVerysad =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysVerysad };

static const TAknsItemID KAknsIIDQgnPropImSmileysWickedsmile =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysWickedsmile };

static const TAknsItemID KAknsIIDQgnPropImSmileysWink =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSmileysWink };

static const TAknsItemID KAknsIIDQgnPropImToMany =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImToMany };

static const TAknsItemID KAknsIIDQgnPropImUserBlocked =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImUserBlocked };

static const TAknsItemID KAknsIIDQgnPropImUserCreatedActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImUserCreatedActive };

static const TAknsItemID KAknsIIDQgnPropImUserCreatedInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImUserCreatedInactive };

static const TAknsItemID KAknsIIDQgnPropKeywordFindTab1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropKeywordFindTab1 };

static const TAknsItemID KAknsIIDQgnPropListAlphaTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropListAlphaTab2 };

static const TAknsItemID KAknsIIDQgnPropListTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropListTab3 };

static const TAknsItemID KAknsIIDQgnPropLocAccepted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocAccepted };

static const TAknsItemID KAknsIIDQgnPropLocExpired =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocExpired };

static const TAknsItemID KAknsIIDQgnPropLocPolicyAccept =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocPolicyAccept };

static const TAknsItemID KAknsIIDQgnPropLocPolicyAsk =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocPolicyAsk };

static const TAknsItemID KAknsIIDQgnPropLocPolicyReject =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocPolicyReject };

static const TAknsItemID KAknsIIDQgnPropLocPrivacySub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocPrivacySub };

static const TAknsItemID KAknsIIDQgnPropLocPrivacyTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocPrivacyTab3 };

static const TAknsItemID KAknsIIDQgnPropLocRejected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocRejected };

static const TAknsItemID KAknsIIDQgnPropLocRequestsTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocRequestsTab2 };

static const TAknsItemID KAknsIIDQgnPropLocRequestsTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocRequestsTab3 };

static const TAknsItemID KAknsIIDQgnPropLocSetTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocSetTab2 };

static const TAknsItemID KAknsIIDQgnPropLocSetTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocSetTab3 };

static const TAknsItemID KAknsIIDQgnPropLogCallsInTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogCallsInTab3 };

static const TAknsItemID KAknsIIDQgnPropLogCallsMissedTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogCallsMissedTab3 };

static const TAknsItemID KAknsIIDQgnPropLogCallsOutTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogCallsOutTab3 };

static const TAknsItemID KAknsIIDQgnPropLogCallsTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogCallsTab4 };

static const TAknsItemID KAknsIIDQgnPropLogCallAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogCallAll };

static const TAknsItemID KAknsIIDQgnPropLogCallLast =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogCallLast };

static const TAknsItemID KAknsIIDQgnPropLogCostsSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogCostsSub };

static const TAknsItemID KAknsIIDQgnPropLogCostsTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogCostsTab4 };

static const TAknsItemID KAknsIIDQgnPropLogCountersTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogCountersTab2 };

static const TAknsItemID KAknsIIDQgnPropLogGprsTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogGprsTab4 };

static const TAknsItemID KAknsIIDQgnPropLogIn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogIn };

static const TAknsItemID KAknsIIDQgnPropLogMissed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogMissed };

static const TAknsItemID KAknsIIDQgnPropLogOut =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogOut };

static const TAknsItemID KAknsIIDQgnPropLogTimersTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogTimersTab4 };

static const TAknsItemID KAknsIIDQgnPropLogTimerCallActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogTimerCallActive };

static const TAknsItemID KAknsIIDQgnPropMailText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMailText };

static const TAknsItemID KAknsIIDQgnPropMailUnsupported =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMailUnsupported };

static const TAknsItemID KAknsIIDQgnPropMceBtRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceBtRead };

static const TAknsItemID KAknsIIDQgnPropMceDraftsTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceDraftsTab4 };

static const TAknsItemID KAknsIIDQgnPropMceDrTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceDrTab4 };

static const TAknsItemID KAknsIIDQgnPropMceInboxSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceInboxSmall };

static const TAknsItemID KAknsIIDQgnPropMceInboxTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceInboxTab4 };

static const TAknsItemID KAknsIIDQgnPropMceIrRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceIrRead };

static const TAknsItemID KAknsIIDQgnPropMceIrUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceIrUnread };

static const TAknsItemID KAknsIIDQgnPropMceMailFetRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMailFetRead };

static const TAknsItemID KAknsIIDQgnPropMceMailFetReaDel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMailFetReaDel };

static const TAknsItemID KAknsIIDQgnPropMceMailFetUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMailFetUnread };

static const TAknsItemID KAknsIIDQgnPropMceMailUnfetRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMailUnfetRead };

static const TAknsItemID KAknsIIDQgnPropMceMailUnfetUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMailUnfetUnread };

static const TAknsItemID KAknsIIDQgnPropMceMmsInfo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMmsInfo };

static const TAknsItemID KAknsIIDQgnPropMceMmsRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMmsRead };

static const TAknsItemID KAknsIIDQgnPropMceMmsUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMmsUnread };

static const TAknsItemID KAknsIIDQgnPropMceNotifRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceNotifRead };

static const TAknsItemID KAknsIIDQgnPropMceNotifUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceNotifUnread };

static const TAknsItemID KAknsIIDQgnPropMceOutboxTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceOutboxTab4 };

static const TAknsItemID KAknsIIDQgnPropMcePushRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMcePushRead };

static const TAknsItemID KAknsIIDQgnPropMcePushUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMcePushUnread };

static const TAknsItemID KAknsIIDQgnPropMceRemoteOnTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceRemoteOnTab4 };

static const TAknsItemID KAknsIIDQgnPropMceRemoteTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceRemoteTab4 };

static const TAknsItemID KAknsIIDQgnPropMceSentTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSentTab4 };

static const TAknsItemID KAknsIIDQgnPropMceSmartRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSmartRead };

static const TAknsItemID KAknsIIDQgnPropMceSmartUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSmartUnread };

static const TAknsItemID KAknsIIDQgnPropMceSmsInfo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSmsInfo };

static const TAknsItemID KAknsIIDQgnPropMceSmsRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSmsRead };

static const TAknsItemID KAknsIIDQgnPropMceSmsReadUrgent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSmsReadUrgent };

static const TAknsItemID KAknsIIDQgnPropMceSmsUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSmsUnread };

static const TAknsItemID KAknsIIDQgnPropMceSmsUnreadUrgent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSmsUnreadUrgent };

static const TAknsItemID KAknsIIDQgnPropMceTemplate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceTemplate };

static const TAknsItemID KAknsIIDQgnPropMemcMmcTab =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMemcMmcTab };

static const TAknsItemID KAknsIIDQgnPropMemcMmcTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMemcMmcTab2 };

static const TAknsItemID KAknsIIDQgnPropMemcPhoneTab =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMemcPhoneTab };

static const TAknsItemID KAknsIIDQgnPropMemcPhoneTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMemcPhoneTab2 };

static const TAknsItemID KAknsIIDQgnPropMmsEmptyPageSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsEmptyPageSub };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateImageSmSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateImageSmSub };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateImageSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateImageSub };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateTitleSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateTitleSub };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateVideoSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateVideoSub };

static const TAknsItemID KAknsIIDQgnPropNetwork2g =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNetwork2g };

static const TAknsItemID KAknsIIDQgnPropNetwork3g =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNetwork3g };

static const TAknsItemID KAknsIIDQgnPropNrtypHome =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypHome };

static const TAknsItemID KAknsIIDQgnPropNrtypHomeDiv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypHomeDiv };

static const TAknsItemID KAknsIIDQgnPropNrtypMobileDiv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypMobileDiv };

static const TAknsItemID KAknsIIDQgnPropNrtypPhoneCnap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypPhoneCnap };

static const TAknsItemID KAknsIIDQgnPropNrtypPhoneDiv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypPhoneDiv };

static const TAknsItemID KAknsIIDQgnPropNrtypSdn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypSdn };

static const TAknsItemID KAknsIIDQgnPropNrtypVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypVideo };

static const TAknsItemID KAknsIIDQgnPropNrtypWork =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypWork };

static const TAknsItemID KAknsIIDQgnPropNrtypWorkDiv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypWorkDiv };

static const TAknsItemID KAknsIIDQgnPropNrtypWvid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypWvid };

static const TAknsItemID KAknsIIDQgnPropNtypVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNtypVideo };

static const TAknsItemID KAknsIIDQgnPropOtaTone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropOtaTone };

static const TAknsItemID KAknsIIDQgnPropPbContactsTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbContactsTab3 };

static const TAknsItemID KAknsIIDQgnPropPbPersonalTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbPersonalTab4 };

static const TAknsItemID KAknsIIDQgnPropPbPhotoTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbPhotoTab3 };

static const TAknsItemID KAknsIIDQgnPropPbSubsTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbSubsTab3 };

static const TAknsItemID KAknsIIDQgnPropPinbAnchorId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbAnchorId };

static const TAknsItemID KAknsIIDQgnPropPinbBagId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbBagId };

static const TAknsItemID KAknsIIDQgnPropPinbBeerId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbBeerId };

static const TAknsItemID KAknsIIDQgnPropPinbBookId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbBookId };

static const TAknsItemID KAknsIIDQgnPropPinbCrownId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbCrownId };

static const TAknsItemID KAknsIIDQgnPropPinbCupId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbCupId };

static const TAknsItemID KAknsIIDQgnPropPinbDocument =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbDocument };

static const TAknsItemID KAknsIIDQgnPropPinbDuckId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbDuckId };

static const TAknsItemID KAknsIIDQgnPropPinbEightId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbEightId };

static const TAknsItemID KAknsIIDQgnPropPinbExclamtionId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbExclamtionId };

static const TAknsItemID KAknsIIDQgnPropPinbFiveId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbFiveId };

static const TAknsItemID KAknsIIDQgnPropPinbFourId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbFourId };

static const TAknsItemID KAknsIIDQgnPropPinbHeartId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbHeartId };

static const TAknsItemID KAknsIIDQgnPropPinbInbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbInbox };

static const TAknsItemID KAknsIIDQgnPropPinbLinkBmId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbLinkBmId };

static const TAknsItemID KAknsIIDQgnPropPinbLinkImageId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbLinkImageId };

static const TAknsItemID KAknsIIDQgnPropPinbLinkMessageId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbLinkMessageId };

static const TAknsItemID KAknsIIDQgnPropPinbLinkNoteId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbLinkNoteId };

static const TAknsItemID KAknsIIDQgnPropPinbLinkPageId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbLinkPageId };

static const TAknsItemID KAknsIIDQgnPropPinbLinkToneId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbLinkToneId };

static const TAknsItemID KAknsIIDQgnPropPinbLinkVideoId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbLinkVideoId };

static const TAknsItemID KAknsIIDQgnPropPinbLinkVorecId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbLinkVorecId };

static const TAknsItemID KAknsIIDQgnPropPinbLockId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbLockId };

static const TAknsItemID KAknsIIDQgnPropPinbLorryId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbLorryId };

static const TAknsItemID KAknsIIDQgnPropPinbMoneyId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbMoneyId };

static const TAknsItemID KAknsIIDQgnPropPinbMovieId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbMovieId };

static const TAknsItemID KAknsIIDQgnPropPinbNineId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbNineId };

static const TAknsItemID KAknsIIDQgnPropPinbNotepad =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbNotepad };

static const TAknsItemID KAknsIIDQgnPropPinbOneId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbOneId };

static const TAknsItemID KAknsIIDQgnPropPinbPhoneId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbPhoneId };

static const TAknsItemID KAknsIIDQgnPropPinbSevenId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbSevenId };

static const TAknsItemID KAknsIIDQgnPropPinbSixId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbSixId };

static const TAknsItemID KAknsIIDQgnPropPinbSmiley1Id =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbSmiley1Id };

static const TAknsItemID KAknsIIDQgnPropPinbSmiley2Id =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbSmiley2Id };

static const TAknsItemID KAknsIIDQgnPropPinbSoccerId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbSoccerId };

static const TAknsItemID KAknsIIDQgnPropPinbStarId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbStarId };

static const TAknsItemID KAknsIIDQgnPropPinbSuitcaseId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbSuitcaseId };

static const TAknsItemID KAknsIIDQgnPropPinbTeddyId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbTeddyId };

static const TAknsItemID KAknsIIDQgnPropPinbThreeId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbThreeId };

static const TAknsItemID KAknsIIDQgnPropPinbToday =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbToday };

static const TAknsItemID KAknsIIDQgnPropPinbTwoId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbTwoId };

static const TAknsItemID KAknsIIDQgnPropPinbWml =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbWml };

static const TAknsItemID KAknsIIDQgnPropPinbZeroId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbZeroId };

static const TAknsItemID KAknsIIDQgnPropPslnActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPslnActive };

static const TAknsItemID KAknsIIDQgnPropPushDefault =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPushDefault };

static const TAknsItemID KAknsIIDQgnPropSetAccessoryTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAccessoryTab4 };

static const TAknsItemID KAknsIIDQgnPropSetBarrTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetBarrTab4 };

static const TAknsItemID KAknsIIDQgnPropSetCallTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetCallTab4 };

static const TAknsItemID KAknsIIDQgnPropSetConnecTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnecTab4 };

static const TAknsItemID KAknsIIDQgnPropSetDatimTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetDatimTab4 };

static const TAknsItemID KAknsIIDQgnPropSetDeviceTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetDeviceTab4 };

static const TAknsItemID KAknsIIDQgnPropSetDivTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetDivTab4 };

static const TAknsItemID KAknsIIDQgnPropSetMpAudioTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetMpAudioTab3 };

static const TAknsItemID KAknsIIDQgnPropSetMpStreamTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetMpStreamTab3 };

static const TAknsItemID KAknsIIDQgnPropSetMpVideoTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetMpVideoTab3 };

static const TAknsItemID KAknsIIDQgnPropSetNetworkTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetNetworkTab4 };

static const TAknsItemID KAknsIIDQgnPropSetSecTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetSecTab4 };

static const TAknsItemID KAknsIIDQgnPropSetTonesSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetTonesSub };

static const TAknsItemID KAknsIIDQgnPropSetTonesTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetTonesTab4 };

static const TAknsItemID KAknsIIDQgnPropSignalIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSignalIcon };

static const TAknsItemID KAknsIIDQgnPropSmlBtOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlBtOff };

static const TAknsItemID KAknsIIDQgnPropSmlHttp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlHttp };

static const TAknsItemID KAknsIIDQgnPropSmlHttpOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlHttpOff };

static const TAknsItemID KAknsIIDQgnPropSmlIr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlIr };

static const TAknsItemID KAknsIIDQgnPropSmlIrOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlIrOff };

static const TAknsItemID KAknsIIDQgnPropSmlRemoteNewSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlRemoteNewSub };

static const TAknsItemID KAknsIIDQgnPropSmlRemoteSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlRemoteSub };

static const TAknsItemID KAknsIIDQgnPropSmlUsb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlUsb };

static const TAknsItemID KAknsIIDQgnPropSmlUsbOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlUsbOff };

static const TAknsItemID KAknsIIDQgnPropSmsDeliveredCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmsDeliveredCdma };

static const TAknsItemID KAknsIIDQgnPropSmsDeliveredUrgentCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmsDeliveredUrgentCdma };

static const TAknsItemID KAknsIIDQgnPropSmsFailedCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmsFailedCdma };

static const TAknsItemID KAknsIIDQgnPropSmsFailedUrgentCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmsFailedUrgentCdma };

static const TAknsItemID KAknsIIDQgnPropSmsPendingCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmsPendingCdma };

static const TAknsItemID KAknsIIDQgnPropSmsPendingUrgentCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmsPendingUrgentCdma };

static const TAknsItemID KAknsIIDQgnPropSmsSentCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmsSentCdma };

static const TAknsItemID KAknsIIDQgnPropSmsSentUrgentCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmsSentUrgentCdma };

static const TAknsItemID KAknsIIDQgnPropSmsWaitingCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmsWaitingCdma };

static const TAknsItemID KAknsIIDQgnPropSmsWaitingUrgentCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmsWaitingUrgentCdma };

static const TAknsItemID KAknsIIDQgnPropTodoDone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropTodoDone };

static const TAknsItemID KAknsIIDQgnPropTodoUndone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropTodoUndone };

static const TAknsItemID KAknsIIDQgnPropVoice =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVoice };

static const TAknsItemID KAknsIIDQgnPropVpnLogError =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVpnLogError };

static const TAknsItemID KAknsIIDQgnPropVpnLogInfo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVpnLogInfo };

static const TAknsItemID KAknsIIDQgnPropVpnLogWarn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVpnLogWarn };

static const TAknsItemID KAknsIIDQgnPropWalletCards =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWalletCards };

static const TAknsItemID KAknsIIDQgnPropWalletCardsLib =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWalletCardsLib };

static const TAknsItemID KAknsIIDQgnPropWalletCardsLibDef =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWalletCardsLibDef };

static const TAknsItemID KAknsIIDQgnPropWalletCardsLibOta =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWalletCardsLibOta };

static const TAknsItemID KAknsIIDQgnPropWalletCardsOta =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWalletCardsOta };

static const TAknsItemID KAknsIIDQgnPropWalletPnotes =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWalletPnotes };

static const TAknsItemID KAknsIIDQgnPropWalletService =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWalletService };

static const TAknsItemID KAknsIIDQgnPropWalletTickets =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWalletTickets };

static const TAknsItemID KAknsIIDQgnPropWmlBm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlBm };

static const TAknsItemID KAknsIIDQgnPropWmlBmAdap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlBmAdap };

static const TAknsItemID KAknsIIDQgnPropWmlBmLast =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlBmLast };

static const TAknsItemID KAknsIIDQgnPropWmlBmTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlBmTab2 };

static const TAknsItemID KAknsIIDQgnPropWmlCheckboxOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlCheckboxOff };

static const TAknsItemID KAknsIIDQgnPropWmlCheckboxOffSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlCheckboxOffSel };

static const TAknsItemID KAknsIIDQgnPropWmlCheckboxOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlCheckboxOn };

static const TAknsItemID KAknsIIDQgnPropWmlCheckboxOnSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlCheckboxOnSel };

static const TAknsItemID KAknsIIDQgnPropWmlCircle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlCircle };

static const TAknsItemID KAknsIIDQgnPropWmlCsd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlCsd };

static const TAknsItemID KAknsIIDQgnPropWmlDisc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlDisc };

static const TAknsItemID KAknsIIDQgnPropWmlGprs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlGprs };

static const TAknsItemID KAknsIIDQgnPropWmlHome =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlHome };

static const TAknsItemID KAknsIIDQgnPropWmlHscsd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlHscsd };

static const TAknsItemID KAknsIIDQgnPropWmlImageMap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlImageMap };

static const TAknsItemID KAknsIIDQgnPropWmlImageNotShown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlImageNotShown };

static const TAknsItemID KAknsIIDQgnPropWmlObject =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlObject };

static const TAknsItemID KAknsIIDQgnPropWmlPage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlPage };

static const TAknsItemID KAknsIIDQgnPropWmlPagesTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlPagesTab2 };

static const TAknsItemID KAknsIIDQgnPropWmlRadiobuttOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlRadiobuttOff };

static const TAknsItemID KAknsIIDQgnPropWmlRadiobuttOffSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlRadiobuttOffSel };

static const TAknsItemID KAknsIIDQgnPropWmlRadiobuttOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlRadiobuttOn };

static const TAknsItemID KAknsIIDQgnPropWmlRadiobuttOnSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlRadiobuttOnSel };

static const TAknsItemID KAknsIIDQgnPropWmlSelectarrow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlSelectarrow };

static const TAknsItemID KAknsIIDQgnPropWmlSelectfile =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlSelectfile };

static const TAknsItemID KAknsIIDQgnPropWmlSms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlSms };

static const TAknsItemID KAknsIIDQgnPropWmlSquare =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlSquare };

static const TAknsItemID KAknsIIDQgnStatAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatAlarm };

static const TAknsItemID KAknsIIDQgnStatBt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatBt };

static const TAknsItemID KAknsIIDQgnStatBtBlank =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatBtBlank };

static const TAknsItemID KAknsIIDQgnStatBtUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatBtUni };

static const TAknsItemID KAknsIIDQgnStatBtUniBlank =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatBtUniBlank };

static const TAknsItemID KAknsIIDQgnStatCaseArabic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseArabic };

static const TAknsItemID KAknsIIDQgnStatCaseArabicNumeric =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseArabicNumeric };

static const TAknsItemID KAknsIIDQgnStatCaseArabicNumericQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseArabicNumericQuery };

static const TAknsItemID KAknsIIDQgnStatCaseArabicQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseArabicQuery };

static const TAknsItemID KAknsIIDQgnStatCaseCapital =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseCapital };

static const TAknsItemID KAknsIIDQgnStatCaseCapitalFull =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseCapitalFull };

static const TAknsItemID KAknsIIDQgnStatCaseCapitalQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseCapitalQuery };

static const TAknsItemID KAknsIIDQgnStatCaseHebrew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseHebrew };

static const TAknsItemID KAknsIIDQgnStatCaseHebrewQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseHebrewQuery };

static const TAknsItemID KAknsIIDQgnStatCaseNumeric =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseNumeric };

static const TAknsItemID KAknsIIDQgnStatCaseNumericFull =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseNumericFull };

static const TAknsItemID KAknsIIDQgnStatCaseNumericQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseNumericQuery };

static const TAknsItemID KAknsIIDQgnStatCaseSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseSmall };

static const TAknsItemID KAknsIIDQgnStatCaseSmallFull =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseSmallFull };

static const TAknsItemID KAknsIIDQgnStatCaseSmallQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseSmallQuery };

static const TAknsItemID KAknsIIDQgnStatCaseText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseText };

static const TAknsItemID KAknsIIDQgnStatCaseTextFull =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseTextFull };

static const TAknsItemID KAknsIIDQgnStatCaseTextQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseTextQuery };

static const TAknsItemID KAknsIIDQgnStatCaseThai =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseThai };

static const TAknsItemID KAknsIIDQgnStatCaseTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseTitle };

static const TAknsItemID KAknsIIDQgnStatCaseTitleQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseTitleQuery };

static const TAknsItemID KAknsIIDQgnStatCdmaRoaming =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCdmaRoaming };

static const TAknsItemID KAknsIIDQgnStatCdmaRoamingUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCdmaRoamingUni };

static const TAknsItemID KAknsIIDQgnStatChiPinyin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiPinyin };

static const TAknsItemID KAknsIIDQgnStatChiPinyinQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiPinyinQuery };

static const TAknsItemID KAknsIIDQgnStatChiStroke =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiStroke };

static const TAknsItemID KAknsIIDQgnStatChiStrokeFind =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiStrokeFind };

static const TAknsItemID KAknsIIDQgnStatChiStrokeFindQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiStrokeFindQuery };

static const TAknsItemID KAknsIIDQgnStatChiStrokeQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiStrokeQuery };

static const TAknsItemID KAknsIIDQgnStatChiStrokeTrad =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiStrokeTrad };

static const TAknsItemID KAknsIIDQgnStatChiStrokeTradQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiStrokeTradQuery };

static const TAknsItemID KAknsIIDQgnStatChiZhuyin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiZhuyin };

static const TAknsItemID KAknsIIDQgnStatChiZhuyinFind =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiZhuyinFind };

static const TAknsItemID KAknsIIDQgnStatChiZhuyinFindQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiZhuyinFindQuery };

static const TAknsItemID KAknsIIDQgnStatChiZhuyinQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiZhuyinQuery };

static const TAknsItemID KAknsIIDQgnStatCypheringOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCypheringOn };

static const TAknsItemID KAknsIIDQgnStatCypheringOnUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCypheringOnUni };

static const TAknsItemID KAknsIIDQgnStatDivert0 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDivert0 };

static const TAknsItemID KAknsIIDQgnStatDivert1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDivert1 };

static const TAknsItemID KAknsIIDQgnStatDivert12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDivert12 };

static const TAknsItemID KAknsIIDQgnStatDivert2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDivert2 };

static const TAknsItemID KAknsIIDQgnStatDivertVm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDivertVm };

static const TAknsItemID KAknsIIDQgnStatHeadset =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatHeadset };

static const TAknsItemID KAknsIIDQgnStatHeadsetUnavailable =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatHeadsetUnavailable };

static const TAknsItemID KAknsIIDQgnStatIhf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatIhf };

static const TAknsItemID KAknsIIDQgnStatIhfUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatIhfUni };

static const TAknsItemID KAknsIIDQgnStatImUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatImUni };

static const TAknsItemID KAknsIIDQgnStatIr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatIr };

static const TAknsItemID KAknsIIDQgnStatIrBlank =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatIrBlank };

static const TAknsItemID KAknsIIDQgnStatIrUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatIrUni };

static const TAknsItemID KAknsIIDQgnStatIrUniBlank =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatIrUniBlank };

static const TAknsItemID KAknsIIDQgnStatJapinHiragana =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatJapinHiragana };

static const TAknsItemID KAknsIIDQgnStatJapinHiraganaOnly =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatJapinHiraganaOnly };

static const TAknsItemID KAknsIIDQgnStatJapinKatakanaFull =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatJapinKatakanaFull };

static const TAknsItemID KAknsIIDQgnStatJapinKatakanaHalf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatJapinKatakanaHalf };

static const TAknsItemID KAknsIIDQgnStatKeyguard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatKeyguard };

static const TAknsItemID KAknsIIDQgnStatLine2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatLine2 };

static const TAknsItemID KAknsIIDQgnStatLoc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatLoc };

static const TAknsItemID KAknsIIDQgnStatLocOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatLocOff };

static const TAknsItemID KAknsIIDQgnStatLocOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatLocOn };

static const TAknsItemID KAknsIIDQgnStatLoopset =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatLoopset };

static const TAknsItemID KAknsIIDQgnStatMessage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessage };

static const TAknsItemID KAknsIIDQgnStatMessageBlank =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageBlank };

static const TAknsItemID KAknsIIDQgnStatMessageData =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageData };

static const TAknsItemID KAknsIIDQgnStatMessageDataUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageDataUni };

static const TAknsItemID KAknsIIDQgnStatMessageFax =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageFax };

static const TAknsItemID KAknsIIDQgnStatMessageFaxUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageFaxUni };

static const TAknsItemID KAknsIIDQgnStatMessageMail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageMail };

static const TAknsItemID KAknsIIDQgnStatMessageMailUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageMailUni };

static const TAknsItemID KAknsIIDQgnStatMessageOther =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageOther };

static const TAknsItemID KAknsIIDQgnStatMessageOtherUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageOtherUni };

static const TAknsItemID KAknsIIDQgnStatMessagePs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessagePs };

static const TAknsItemID KAknsIIDQgnStatMessageRemote =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageRemote };

static const TAknsItemID KAknsIIDQgnStatMessageRemoteUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageRemoteUni };

static const TAknsItemID KAknsIIDQgnStatMessageUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageUni };

static const TAknsItemID KAknsIIDQgnStatMessageUniBlank =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageUniBlank };

static const TAknsItemID KAknsIIDQgnStatMissedCallsUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMissedCallsUni };

static const TAknsItemID KAknsIIDQgnStatMissedCallPs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMissedCallPs };

static const TAknsItemID KAknsIIDQgnStatModBt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatModBt };

static const TAknsItemID KAknsIIDQgnStatOutbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatOutbox };

static const TAknsItemID KAknsIIDQgnStatOutboxUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatOutboxUni };

static const TAknsItemID KAknsIIDQgnStatQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatQuery };

static const TAknsItemID KAknsIIDQgnStatQueryQuery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatQueryQuery };

static const TAknsItemID KAknsIIDQgnStatT9 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatT9 };

static const TAknsItemID KAknsIIDQgnStatT9Query =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatT9Query };

static const TAknsItemID KAknsIIDQgnStatTty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatTty };

static const TAknsItemID KAknsIIDQgnStatUsb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatUsb };

static const TAknsItemID KAknsIIDQgnStatUsbUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatUsbUni };

static const TAknsItemID KAknsIIDQgnStatVm0 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVm0 };

static const TAknsItemID KAknsIIDQgnStatVm0Uni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVm0Uni };

static const TAknsItemID KAknsIIDQgnStatVm1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVm1 };

static const TAknsItemID KAknsIIDQgnStatVm12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVm12 };

static const TAknsItemID KAknsIIDQgnStatVm12Uni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVm12Uni };

static const TAknsItemID KAknsIIDQgnStatVm1Uni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVm1Uni };

static const TAknsItemID KAknsIIDQgnStatVm2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVm2 };

static const TAknsItemID KAknsIIDQgnStatVm2Uni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVm2Uni };

static const TAknsItemID KAknsIIDQgnStatZoneHome =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatZoneHome };

static const TAknsItemID KAknsIIDQgnStatZoneViag =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatZoneViag };

static const TAknsItemID KAknsIIDQgnIndiJapFindCaseNumericFull =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiJapFindCaseNumericFull };

static const TAknsItemID KAknsIIDQgnIndiJapFindCaseSmallFull =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiJapFindCaseSmallFull };

static const TAknsItemID KAknsIIDQgnIndiJapFindHiragana =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiJapFindHiragana };

static const TAknsItemID KAknsIIDQgnIndiJapFindHiraganaOnly =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiJapFindHiraganaOnly };

static const TAknsItemID KAknsIIDQgnIndiJapFindKatakanaFull =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiJapFindKatakanaFull };

static const TAknsItemID KAknsIIDQgnIndiJapFindKatakanaHalf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiJapFindKatakanaHalf };

static const TAknsItemID KAknsIIDQgnIndiJapFindPredictive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiJapFindPredictive };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonBack =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonBack };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonBackInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonBackInactive };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonBackPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonBackPressed };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonDown };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonDownInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonDownInactive };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonDownPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonDownPressed };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonForward =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonForward };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonForwardInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonForwardInactive };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonForwardPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonForwardPressed };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonPause };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonPauseInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonPauseInactive };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonPausePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonPausePressed };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonRecord =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonRecord };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonRecordInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonRecordInactive };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonRecordPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonRecordPressed };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonStop };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonStopInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonStopInactive };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonStopPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonStopPressed };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonUp };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonUpInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonUpInactive };

static const TAknsItemID KAknsIIDQgnIndiRadioButtonUpPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioButtonUpPressed };

static const TAknsItemID KAknsIIDQgnPropAlbumMain =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumMain };

static const TAknsItemID KAknsIIDQgnPropAlbumPhotoSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumPhotoSmall };

static const TAknsItemID KAknsIIDQgnPropAlbumVideoSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumVideoSmall };

static const TAknsItemID KAknsIIDQgnPropLogGprsReceivedSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogGprsReceivedSub };

static const TAknsItemID KAknsIIDQgnPropLogGprsSentSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogGprsSentSub };

static const TAknsItemID KAknsIIDQgnPropLogGprsTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogGprsTab3 };

static const TAknsItemID KAknsIIDQgnPropPinbLinkStreamId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbLinkStreamId };

static const TAknsItemID KAknsIIDQgnStatCaseShift =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseShift };

static const TAknsItemID KAknsIIDQgnIndiCamsBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsBw };

static const TAknsItemID KAknsIIDQgnIndiCamsCloudy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsCloudy };

static const TAknsItemID KAknsIIDQgnIndiCamsFluorescent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsFluorescent };

static const TAknsItemID KAknsIIDQgnIndiCamsNegative =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsNegative };

static const TAknsItemID KAknsIIDQgnIndiCamsSepia =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsSepia };

static const TAknsItemID KAknsIIDQgnIndiCamsSunny =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsSunny };

static const TAknsItemID KAknsIIDQgnIndiCamsTungsten =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTungsten };

static const TAknsItemID KAknsIIDQgnIndiPhoneAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPhoneAdd };

static const TAknsItemID KAknsIIDQgnPropLinkEmbdLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLinkEmbdLarge };

static const TAknsItemID KAknsIIDQgnPropLinkEmbdMedium =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLinkEmbdMedium };

static const TAknsItemID KAknsIIDQgnPropLinkEmbdSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLinkEmbdSmall };

static const TAknsItemID KAknsIIDQgnPropMceDraft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceDraft };

static const TAknsItemID KAknsIIDQgnPropMceDraftNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceDraftNew };

static const TAknsItemID KAknsIIDQgnPropMceInboxSmallNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceInboxSmallNew };

static const TAknsItemID KAknsIIDQgnPropMceOutboxSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceOutboxSmall };

static const TAknsItemID KAknsIIDQgnPropMceOutboxSmallNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceOutboxSmallNew };

static const TAknsItemID KAknsIIDQgnPropMceSent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSent };

static const TAknsItemID KAknsIIDQgnPropMceSentNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSentNew };

static const TAknsItemID KAknsIIDQgnPropSmlRemoteTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlRemoteTab4 };

static const TAknsItemID KAknsIIDQgnIndiAiSat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiSat };

static const TAknsItemID KAknsIIDQgnMenuCb2Cxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuCb2Cxt };

static const TAknsItemID KAknsIIDQgnMenuSimfdnCxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuSimfdnCxt };

static const TAknsItemID KAknsIIDQgnMenuSiminCxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuSiminCxt };

static const TAknsItemID KAknsIIDQgnPropDrmRightsExpForbidLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRightsExpForbidLarge };

static const TAknsItemID KAknsIIDQgnMenuCbCxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuCbCxt };

static const TAknsItemID KAknsIIDQgnGrafMmsTemplatePrevImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTemplatePrevImage };

static const TAknsItemID KAknsIIDQgnGrafMmsTemplatePrevText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTemplatePrevText };

static const TAknsItemID KAknsIIDQgnGrafMmsTemplatePrevVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsTemplatePrevVideo };

static const TAknsItemID KAknsIIDQgnIndiSignalNotAvailCdma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalNotAvailCdma };

static const TAknsItemID KAknsIIDQgnIndiSignalNoService =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalNoService };

static const TAknsItemID KAknsIIDQgnMenuDycRoamingCxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuDycRoamingCxt };

static const TAknsItemID KAknsIIDQgnMenuImRoamingCxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuImRoamingCxt };

static const TAknsItemID KAknsIIDQgnMenuMyAccountLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMyAccountLst };

static const TAknsItemID KAknsIIDQgnPropAmsGetNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAmsGetNew };

static const TAknsItemID KAknsIIDQgnPropFileOtherSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileOtherSub };

static const TAknsItemID KAknsIIDQgnPropFileOtherTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileOtherTab4 };

static const TAknsItemID KAknsIIDQgnPropMyAccount =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMyAccount };

static const TAknsItemID KAknsIIDQgnIndiAiCale =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiCale };

static const TAknsItemID KAknsIIDQgnIndiAiTodo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiTodo };

static const TAknsItemID KAknsIIDQgnIndiMmsLinksEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsLinksEmail };

static const TAknsItemID KAknsIIDQgnIndiMmsLinksPhone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsLinksPhone };

static const TAknsItemID KAknsIIDQgnIndiMmsLinksWml =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsLinksWml };

static const TAknsItemID KAknsIIDQgnIndiMmsSpeakerMuted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsSpeakerMuted };

static const TAknsItemID KAknsIIDQgnPropAiShortcut =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAiShortcut };

static const TAknsItemID KAknsIIDQgnPropImFriendAway =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendAway };

static const TAknsItemID KAknsIIDQgnPropImServer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImServer };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateImageBotSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateImageBotSub };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateImageMidSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateImageMidSub };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateImageSmBotSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateImageSmBotSub };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateImageSmLdiaSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateImageSmLdiaSub };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateImageSmManySub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateImageSmManySub };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateImageSmRdiaSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateImageSmRdiaSub };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateImageSmTlSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateImageSmTlSub };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateImageSmTrSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateImageSmTrSub };

static const TAknsItemID KAknsIIDQgnPropMmsTemplateTextSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsTemplateTextSub };

static const TAknsItemID KAknsIIDQgnPropWmlPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlPlay };

static const TAknsItemID KAknsIIDQgnIndiOnlineAlbumImageAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiOnlineAlbumImageAdd };

static const TAknsItemID KAknsIIDQgnIndiOnlineAlbumVideoAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiOnlineAlbumVideoAdd };

static const TAknsItemID KAknsIIDQgnPropClsInactiveChannel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClsInactiveChannel };

static const TAknsItemID KAknsIIDQgnPropClsTab1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClsTab1 };

static const TAknsItemID KAknsIIDQgnPropOnlineAlbumEmpty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropOnlineAlbumEmpty };

static const TAknsItemID KAknsIIDQgnPropNetwSharedConn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNetwSharedConn };

static const TAknsItemID KAknsIIDQgnPropFolderDynamic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderDynamic };

static const TAknsItemID KAknsIIDQgnPropFolderDynamicLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderDynamicLarge };

static const TAknsItemID KAknsIIDQgnPropFolderMmc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderMmc };

static const TAknsItemID KAknsIIDQgnPropFolderProfiles =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderProfiles };

static const TAknsItemID KAknsIIDQgnPropLmArea =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmArea };

static const TAknsItemID KAknsIIDQgnPropLmBusiness =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmBusiness };

static const TAknsItemID KAknsIIDQgnPropLmCategoriesTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmCategoriesTab2 };

static const TAknsItemID KAknsIIDQgnPropLmChurch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmChurch };

static const TAknsItemID KAknsIIDQgnPropLmCommunication =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmCommunication };

static const TAknsItemID KAknsIIDQgnPropLmCxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmCxt };

static const TAknsItemID KAknsIIDQgnPropLmEducation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmEducation };

static const TAknsItemID KAknsIIDQgnPropLmFun =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmFun };

static const TAknsItemID KAknsIIDQgnPropLmGene =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmGene };

static const TAknsItemID KAknsIIDQgnPropLmHotel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmHotel };

static const TAknsItemID KAknsIIDQgnPropLmLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmLst };

static const TAknsItemID KAknsIIDQgnPropLmNamesTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmNamesTab2 };

static const TAknsItemID KAknsIIDQgnPropLmOutdoor =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmOutdoor };

static const TAknsItemID KAknsIIDQgnPropLmPeople =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmPeople };

static const TAknsItemID KAknsIIDQgnPropLmPublic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmPublic };

static const TAknsItemID KAknsIIDQgnPropLmRestaurant =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmRestaurant };

static const TAknsItemID KAknsIIDQgnPropLmShopping =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmShopping };

static const TAknsItemID KAknsIIDQgnPropLmSightseeing =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmSightseeing };

static const TAknsItemID KAknsIIDQgnPropLmSport =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmSport };

static const TAknsItemID KAknsIIDQgnPropLmTransport =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmTransport };

static const TAknsItemID KAknsIIDQgnPropPmAttachAlbum =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPmAttachAlbum };

static const TAknsItemID KAknsIIDQgnPropProfiles =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropProfiles };

static const TAknsItemID KAknsIIDQgnPropProfilesSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropProfilesSmall };

static const TAknsItemID KAknsIIDQgnPropSmlSyncFromServer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlSyncFromServer };

static const TAknsItemID KAknsIIDQgnPropSmlSyncOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlSyncOff };

static const TAknsItemID KAknsIIDQgnPropSmlSyncServer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlSyncServer };

static const TAknsItemID KAknsIIDQgnPropSmlSyncToServer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlSyncToServer };

static const TAknsItemID KAknsIIDQgnPropAlbumPermanentPhoto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumPermanentPhoto };

static const TAknsItemID KAknsIIDQgnPropAlbumPermanentPhotoSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumPermanentPhotoSmall };

static const TAknsItemID KAknsIIDQgnPropAlbumPermanentVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumPermanentVideo };

static const TAknsItemID KAknsIIDQgnPropAlbumPermanentVideoSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumPermanentVideoSmall };

static const TAknsItemID KAknsIIDQgnPropAlbumSounds =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumSounds };

static const TAknsItemID KAknsIIDQgnPropAlbumSoundsSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumSoundsSmall };

static const TAknsItemID KAknsIIDQgnPropFolderPermanent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderPermanent };

static const TAknsItemID KAknsIIDQgnPropOnlineAlbumSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropOnlineAlbumSub };

static const TAknsItemID KAknsIIDQgnGrafDimWipeLsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafDimWipeLsc };

static const TAknsItemID KAknsIIDQgnGrafDimWipePrt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafDimWipePrt };

static const TAknsItemID KAknsIIDQgnGrafLinePrimaryHorizontal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafLinePrimaryHorizontal };

static const TAknsItemID KAknsIIDQgnGrafLinePrimaryHorizontalDashed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafLinePrimaryHorizontalDashed };

static const TAknsItemID KAknsIIDQgnGrafLinePrimaryVertical =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafLinePrimaryVertical };

static const TAknsItemID KAknsIIDQgnGrafLinePrimaryVerticalDashed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafLinePrimaryVerticalDashed };

static const TAknsItemID KAknsIIDQgnGrafLineSecondaryHorizontal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafLineSecondaryHorizontal };

static const TAknsItemID KAknsIIDQgnGrafLineSecondaryVertical =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafLineSecondaryVertical };

static const TAknsItemID KAknsIIDQgnGrafStatusSmallProgress =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafStatusSmallProgress };

static const TAknsItemID KAknsIIDQgnGrafStatusSmallWaitBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafStatusSmallWaitBg };

static const TAknsItemID KAknsIIDQgnGrafTabActiveL =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTabActiveL };

static const TAknsItemID KAknsIIDQgnGrafTabActiveM =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTabActiveM };

static const TAknsItemID KAknsIIDQgnGrafTabActiveR =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTabActiveR };

static const TAknsItemID KAknsIIDQgnGrafTabPassiveL =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTabPassiveL };

static const TAknsItemID KAknsIIDQgnGrafTabPassiveM =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTabPassiveM };

static const TAknsItemID KAknsIIDQgnGrafTabPassiveR =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTabPassiveR };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet10Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet10Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet10On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet10On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet1Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet1Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet1On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet1On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet2Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet2Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet2On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet2On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet3Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet3Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet3On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet3On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet4Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet4Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet4On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet4On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet5Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet5Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet5On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet5On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet6Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet6Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet6On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet6On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet7Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet7Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet7On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet7On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet8Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet8Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet8On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet8On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet9Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet9Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSet9On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSet9On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall10Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall10Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall10On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall10On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall1Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall1Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall1On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall1On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall2Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall2Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall2On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall2On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall3Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall3Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall3On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall3On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall4Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall4Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall4On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall4On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall5Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall5Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall5On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall5On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall6Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall6Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall6On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall6On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall7Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall7Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall7On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall7On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall8Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall8Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall8On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall8On };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall9Off =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall9Off };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmall9On =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmall9On };

static const TAknsItemID KAknsIIDQgnGrafWaitIncrem =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafWaitIncrem };

static const TAknsItemID KAknsIIDQgnImStatEmpty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnImStatEmpty };

static const TAknsItemID KAknsIIDQgnIndiAmInstNoAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAmInstNoAdd };

static const TAknsItemID KAknsIIDQgnIndiAttachAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAttachAdd };

static const TAknsItemID KAknsIIDQgnIndiAttachUnfetchedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAttachUnfetchedAdd };

static const TAknsItemID KAknsIIDQgnIndiAttachVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAttachVideo };

static const TAknsItemID KAknsIIDQgnIndiBatteryStrengthLsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBatteryStrengthLsc };

static const TAknsItemID KAknsIIDQgnIndiBrowserMmcAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserMmcAdd };

static const TAknsItemID KAknsIIDQgnIndiBrowserPauseAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserPauseAdd };

static const TAknsItemID KAknsIIDQgnIndiBtConnectedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBtConnectedAdd };

static const TAknsItemID KAknsIIDQgnIndiCallVideoBlindInMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVideoBlindInMaskIcon };

static const TAknsItemID KAknsIIDQgnIndiCallVideoBlindInMaskSoft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVideoBlindInMaskSoft };

static const TAknsItemID KAknsIIDQgnIndiCallVideoBlindOutMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVideoBlindOutMaskIcon };

static const TAknsItemID KAknsIIDQgnIndiCallVideoBlindOutMaskSoft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVideoBlindOutMaskSoft };

static const TAknsItemID KAknsIIDQgnIndiCamsBright =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsBright };

static const TAknsItemID KAknsIIDQgnIndiCamsBurst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsBurst };

static const TAknsItemID KAknsIIDQgnIndiCamsContrast =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsContrast };

static const TAknsItemID KAknsIIDQgnIndiCamsZoomBgMax =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsZoomBgMax };

static const TAknsItemID KAknsIIDQgnIndiCamsZoomBgMin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsZoomBgMin };

static const TAknsItemID KAknsIIDQgnIndiChiFindCangjie =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiChiFindCangjie };

static const TAknsItemID KAknsIIDQgnIndiConnectionOnRoamAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiConnectionOnRoamAdd };

static const TAknsItemID KAknsIIDQgnIndiDrmManyMoAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDrmManyMoAdd };

static const TAknsItemID KAknsIIDQgnIndiDycDiacreetAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDycDiacreetAdd };

static const TAknsItemID KAknsIIDQgnIndiEnter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiEnter };

static const TAknsItemID KAknsIIDQgnIndiFindGlassAdvanced =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFindGlassAdvanced };

static const TAknsItemID KAknsIIDQgnIndiFindNone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFindNone };

static const TAknsItemID KAknsIIDQgnIndiImportantAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImportantAdd };

static const TAknsItemID KAknsIIDQgnIndiImMessage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImMessage };

static const TAknsItemID KAknsIIDQgnIndiLocPolicyAcceptAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiLocPolicyAcceptAdd };

static const TAknsItemID KAknsIIDQgnIndiLocPolicyAskAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiLocPolicyAskAdd };

static const TAknsItemID KAknsIIDQgnIndiMmsEarpiece =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsEarpiece };

static const TAknsItemID KAknsIIDQgnIndiMmsNoncorm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsNoncorm };

static const TAknsItemID KAknsIIDQgnIndiMmsStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsStop };

static const TAknsItemID KAknsIIDQgnIndiSettProtectedInvAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSettProtectedInvAdd };

static const TAknsItemID KAknsIIDQgnIndiSignalStrengthLsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalStrengthLsc };

static const TAknsItemID KAknsIIDQgnIndiSignalWcdmaSuspended =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalWcdmaSuspended };

static const TAknsItemID KAknsIIDQgnIndiTextLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTextLeft };

static const TAknsItemID KAknsIIDQgnIndiTextRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTextRight };

static const TAknsItemID KAknsIIDQgnIndiWmlImageNoteShown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWmlImageNoteShown };

static const TAknsItemID KAknsIIDQgnIndiWmlImageNotShown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWmlImageNotShown };

static const TAknsItemID KAknsIIDQgnPropBildNavigationSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBildNavigationSub };

static const TAknsItemID KAknsIIDQgnPropBtDevicesTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtDevicesTab2 };

static const TAknsItemID KAknsIIDQgnPropGroupVip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropGroupVip };

static const TAknsItemID KAknsIIDQgnPropLogCallsTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogCallsTab3 };

static const TAknsItemID KAknsIIDQgnPropLogTimersTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogTimersTab3 };

static const TAknsItemID KAknsIIDQgnPropMceDrafts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceDrafts };

static const TAknsItemID KAknsIIDQgnPropMceDraftsNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceDraftsNew };

static const TAknsItemID KAknsIIDQgnPropMceMailFetReadDel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMailFetReadDel };

static const TAknsItemID KAknsIIDQgnPropMceSmsTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSmsTab4 };

static const TAknsItemID KAknsIIDQgnPropModeRing =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModeRing };

static const TAknsItemID KAknsIIDQgnPropPbContactsTab1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbContactsTab1 };

static const TAknsItemID KAknsIIDQgnPropPbContactsTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbContactsTab2 };

static const TAknsItemID KAknsIIDQgnPropPinbExclamationId =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbExclamationId };

static const TAknsItemID KAknsIIDQgnPropPlsnActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPlsnActive };

static const TAknsItemID KAknsIIDQgnPropSetButton =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetButton };

static const TAknsItemID KAknsIIDQgnPropVoiceMidi =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVoiceMidi };

static const TAknsItemID KAknsIIDQgnPropVoiceWav =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVoiceWav };

static const TAknsItemID KAknsIIDQgnPropVpnAccessPoint =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVpnAccessPoint };

static const TAknsItemID KAknsIIDQgnPropWmlUssd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlUssd };

static const TAknsItemID KAknsIIDQgnStatChiCangjie =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiCangjie };

static const TAknsItemID KAknsIIDQgnStatConnectionOnUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatConnectionOnUni };

static const TAknsItemID KAknsIIDQgnStatCsd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCsd };

static const TAknsItemID KAknsIIDQgnStatCsdUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCsdUni };

static const TAknsItemID KAknsIIDQgnStatDsign =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDsign };

static const TAknsItemID KAknsIIDQgnStatHscsd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatHscsd };

static const TAknsItemID KAknsIIDQgnStatHscsdUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatHscsdUni };

static const TAknsItemID KAknsIIDQgnStatMissedCalls =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMissedCalls };

static const TAknsItemID KAknsIIDQgnStatNoCalls =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatNoCalls };

static const TAknsItemID KAknsIIDQgnStatNoCallsUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatNoCallsUni };

static const TAknsItemID KAknsIIDQgnIndiWlanSecureNetworkAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWlanSecureNetworkAdd };

static const TAknsItemID KAknsIIDQgnIndiWlanSignalGoodAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWlanSignalGoodAdd };

static const TAknsItemID KAknsIIDQgnIndiWlanSignalLowAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWlanSignalLowAdd };

static const TAknsItemID KAknsIIDQgnIndiWlanSignalMedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWlanSignalMedAdd };

static const TAknsItemID KAknsIIDQgnPropCmonConnActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmonConnActive };

static const TAknsItemID KAknsIIDQgnPropCmonWlanAvail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmonWlanAvail };

static const TAknsItemID KAknsIIDQgnPropCmonWlanConn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmonWlanConn };

static const TAknsItemID KAknsIIDQgnPropWlanBearer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWlanBearer };

static const TAknsItemID KAknsIIDQgnPropWlanEasy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWlanEasy };

static const TAknsItemID KAknsIIDQgnStatWlanActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatWlanActive };

static const TAknsItemID KAknsIIDQgnStatWlanActiveSecure =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatWlanActiveSecure };

static const TAknsItemID KAknsIIDQgnStatWlanActiveSecureUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatWlanActiveSecureUni };

static const TAknsItemID KAknsIIDQgnStatWlanActiveUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatWlanActiveUni };

static const TAknsItemID KAknsIIDQgnStatWlanAvail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatWlanAvail };

static const TAknsItemID KAknsIIDQgnStatWlanAvailUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatWlanAvailUni };

static const TAknsItemID KAknsIIDQgnGrafMmsAudioCorrupted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsAudioCorrupted };

static const TAknsItemID KAknsIIDQgnGrafMmsAudioDrm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsAudioDrm };

static const TAknsItemID KAknsIIDQgnGrafMmsImageCorrupted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsImageCorrupted };

static const TAknsItemID KAknsIIDQgnGrafMmsImageDrm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsImageDrm };

static const TAknsItemID KAknsIIDQgnGrafMmsVideoCorrupted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsVideoCorrupted };

static const TAknsItemID KAknsIIDQgnGrafMmsVideoDrm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsVideoDrm };

static const TAknsItemID KAknsIIDQgnMenuEmpty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuEmpty };

static const TAknsItemID KAknsIIDQgnPropImFriendTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendTab3 };

static const TAknsItemID KAknsIIDQgnPropImIboxTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImIboxTab3 };

static const TAknsItemID KAknsIIDQgnPropImListTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImListTab3 };

static const TAknsItemID KAknsIIDQgnPropImSavedChatTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImSavedChatTab3 };

static const TAknsItemID KAknsIIDQgnIndiSignalEgprsAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalEgprsAttach };

static const TAknsItemID KAknsIIDQgnIndiSignalEgprsContext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalEgprsContext };

static const TAknsItemID KAknsIIDQgnIndiSignalEgprsMultipdp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalEgprsMultipdp };

static const TAknsItemID KAknsIIDQgnIndiSignalEgprsSuspended =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalEgprsSuspended };

static const TAknsItemID KAknsIIDQgnStatPocOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatPocOn };

static const TAknsItemID KAknsIIDQgnMenuGroupConnectLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupConnectLst };

static const TAknsItemID KAknsIIDQgnMenuGroupConnect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupConnect };

static const TAknsItemID KAknsIIDQgnMenuGroupExtrasLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupExtrasLst };

static const TAknsItemID KAknsIIDQgnMenuGroupExtras =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupExtras };

static const TAknsItemID KAknsIIDQgnMenuGroupInstallLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupInstallLst };

static const TAknsItemID KAknsIIDQgnMenuGroupInstall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupInstall };

static const TAknsItemID KAknsIIDQgnMenuGroupOrganiserLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupOrganiserLst };

static const TAknsItemID KAknsIIDQgnMenuGroupOrganiser =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupOrganiser };

static const TAknsItemID KAknsIIDQgnMenuGroupToolsLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupToolsLst };

static const TAknsItemID KAknsIIDQgnMenuGroupTools =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupTools };

static const TAknsItemID KAknsIIDQgnIndiCamsZoomMax =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsZoomMax };

static const TAknsItemID KAknsIIDQgnIndiCamsZoomMin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsZoomMin };

static const TAknsItemID KAknsIIDQgnIndiAiMusicPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiMusicPause };

static const TAknsItemID KAknsIIDQgnIndiAiMusicPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiMusicPlay };

static const TAknsItemID KAknsIIDQgnIndiAiNtDef =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtDef };

static const TAknsItemID KAknsIIDQgnIndiAlarmInactiveAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAlarmInactiveAdd };

static const TAknsItemID KAknsIIDQgnIndiCdrTodo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrTodo };

static const TAknsItemID KAknsIIDQgnIndiViewerPanningDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiViewerPanningDown };

static const TAknsItemID KAknsIIDQgnIndiViewerPanningLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiViewerPanningLeft };

static const TAknsItemID KAknsIIDQgnIndiViewerPanningRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiViewerPanningRight };

static const TAknsItemID KAknsIIDQgnIndiViewerPanningUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiViewerPanningUp };

static const TAknsItemID KAknsIIDQgnIndiViewerPointer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiViewerPointer };

static const TAknsItemID KAknsIIDQgnIndiViewerPointerHand =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiViewerPointerHand };

static const TAknsItemID KAknsIIDQgnPropLogCallsMostdialTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogCallsMostdialTab4 };

static const TAknsItemID KAknsIIDQgnPropLogMostdSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogMostdSub };

static const TAknsItemID KAknsIIDQgnAreaMainMup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnAreaMainMup };

static const TAknsItemID KAknsIIDQgnGrafBlid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlid };

static const TAknsItemID KAknsIIDQgnGrafBlidDestNear =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidDestNear };

static const TAknsItemID KAknsIIDQgnGrafBlidDir =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidDir };

static const TAknsItemID KAknsIIDQgnGrafMupBarProgress =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupBarProgress };

static const TAknsItemID KAknsIIDQgnGrafMupBarProgress2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupBarProgress2 };

static const TAknsItemID KAknsIIDQgnGrafMupVisualizerImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupVisualizerImage };

static const TAknsItemID KAknsIIDQgnGrafMupVisualizerMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupVisualizerMaskIcon };

static const TAknsItemID KAknsIIDQgnGrafMupVisualizerMaskSoft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupVisualizerMaskSoft };

static const TAknsItemID KAknsIIDQgnIndiAppOpen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAppOpen };

static const TAknsItemID KAknsIIDQgnIndiCallVoipActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVoipActive };

static const TAknsItemID KAknsIIDQgnIndiCallVoipActive2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVoipActive2 };

static const TAknsItemID KAknsIIDQgnIndiCallVoipActiveConf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVoipActiveConf };

static const TAknsItemID KAknsIIDQgnIndiCallVoipCallstaDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVoipCallstaDisconn };

static const TAknsItemID KAknsIIDQgnIndiCallVoipDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVoipDisconn };

static const TAknsItemID KAknsIIDQgnIndiCallVoipDisconnConf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVoipDisconnConf };

static const TAknsItemID KAknsIIDQgnIndiCallVoipHeld =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVoipHeld };

static const TAknsItemID KAknsIIDQgnIndiCallVoipHeldConf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVoipHeldConf };

static const TAknsItemID KAknsIIDQgnIndiCallVoipWaiting1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVoipWaiting1 };

static const TAknsItemID KAknsIIDQgnIndiCallVoipWaiting2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVoipWaiting2 };

static const TAknsItemID KAknsIIDQgnIndiMupButtonLink =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonLink };

static const TAknsItemID KAknsIIDQgnIndiMupButtonLinkDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonLinkDimmed };

static const TAknsItemID KAknsIIDQgnIndiMupButtonLinkHl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonLinkHl };

static const TAknsItemID KAknsIIDQgnIndiMupButtonLinkInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonLinkInact };

static const TAknsItemID KAknsIIDQgnIndiMupButtonMc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonMc };

static const TAknsItemID KAknsIIDQgnIndiMupButtonMcHl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonMcHl };

static const TAknsItemID KAknsIIDQgnIndiMupButtonMcInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonMcInact };

static const TAknsItemID KAknsIIDQgnIndiMupButtonNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonNext };

static const TAknsItemID KAknsIIDQgnIndiMupButtonNextHl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonNextHl };

static const TAknsItemID KAknsIIDQgnIndiMupButtonNextInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonNextInact };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPause };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPauseHl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPauseHl };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPauseInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPauseInact };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPlay };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPlaylist =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPlaylist };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPlaylistDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPlaylistDimmed };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPlaylistHl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPlaylistHl };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPlaylistInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPlaylistInact };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPlayHl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPlayHl };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPlayInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPlayInact };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPrev };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPrevHl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPrevHl };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPrevInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPrevInact };

static const TAknsItemID KAknsIIDQgnIndiMupButtonStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonStop };

static const TAknsItemID KAknsIIDQgnIndiMupButtonStopHl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonStopHl };

static const TAknsItemID KAknsIIDQgnIndiMupEq =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupEq };

static const TAknsItemID KAknsIIDQgnIndiMupEqBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupEqBg };

static const TAknsItemID KAknsIIDQgnIndiMupEqSlider =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupEqSlider };

static const TAknsItemID KAknsIIDQgnIndiMupPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupPause };

static const TAknsItemID KAknsIIDQgnIndiMupPauseAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupPauseAdd };

static const TAknsItemID KAknsIIDQgnIndiMupPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupPlay };

static const TAknsItemID KAknsIIDQgnIndiMupPlayAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupPlayAdd };

static const TAknsItemID KAknsIIDQgnIndiMupSpeaker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupSpeaker };

static const TAknsItemID KAknsIIDQgnIndiMupSpeakerMuted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupSpeakerMuted };

static const TAknsItemID KAknsIIDQgnIndiMupStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupStop };

static const TAknsItemID KAknsIIDQgnIndiMupStopAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupStopAdd };

static const TAknsItemID KAknsIIDQgnIndiMupVolumeSlider =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupVolumeSlider };

static const TAknsItemID KAknsIIDQgnIndiMupVolumeSliderBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupVolumeSliderBg };

static const TAknsItemID KAknsIIDQgnMenuGroupMedia =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupMedia };

static const TAknsItemID KAknsIIDQgnMenuVoip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuVoip };

static const TAknsItemID KAknsIIDQgnNoteAlarmTodo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteAlarmTodo };

static const TAknsItemID KAknsIIDQgnPropBlidTripSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidTripSub };

static const TAknsItemID KAknsIIDQgnPropBlidTripTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidTripTab3 };

static const TAknsItemID KAknsIIDQgnPropBlidWaypoint =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidWaypoint };

static const TAknsItemID KAknsIIDQgnPropLinkEmbd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLinkEmbd };

static const TAknsItemID KAknsIIDQgnPropMupAlbum =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupAlbum };

static const TAknsItemID KAknsIIDQgnPropMupArtist =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupArtist };

static const TAknsItemID KAknsIIDQgnPropMupAudio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupAudio };

static const TAknsItemID KAknsIIDQgnPropMupComposer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupComposer };

static const TAknsItemID KAknsIIDQgnPropMupGenre =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupGenre };

static const TAknsItemID KAknsIIDQgnPropMupPlaylist =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupPlaylist };

static const TAknsItemID KAknsIIDQgnPropMupSongs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupSongs };

static const TAknsItemID KAknsIIDQgnPropNrtypVoip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypVoip };

static const TAknsItemID KAknsIIDQgnPropNrtypVoipDiv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypVoipDiv };

static const TAknsItemID KAknsIIDQgnPropSubCurrent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSubCurrent };

static const TAknsItemID KAknsIIDQgnPropSubMarked =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSubMarked };

static const TAknsItemID KAknsIIDQgnStatPocOnUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatPocOnUni };

static const TAknsItemID KAknsIIDQgnStatVietCaseCapital =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVietCaseCapital };

static const TAknsItemID KAknsIIDQgnStatVietCaseSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVietCaseSmall };

static const TAknsItemID KAknsIIDQgnStatVietCaseText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVietCaseText };

static const TAknsItemID KAknsIIDQgnIndiSyncSetAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSyncSetAdd };

static const TAknsItemID KAknsIIDQgnPropMceMms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMms };

static const TAknsItemID KAknsIIDQgnPropUnknown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropUnknown };

static const TAknsItemID KAknsIIDQgnStatMsgNumber =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMsgNumber };

static const TAknsItemID KAknsIIDQgnStatMsgRoom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMsgRoom };

static const TAknsItemID KAknsIIDQgnStatSilent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatSilent };

static const TAknsItemID KAknsIIDQgnGrafBgGray =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBgGray };

static const TAknsItemID KAknsIIDQgnIndiAiNt3g =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNt3g };

static const TAknsItemID KAknsIIDQgnIndiAiNtAudvideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtAudvideo };

static const TAknsItemID KAknsIIDQgnIndiAiNtChat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtChat };

static const TAknsItemID KAknsIIDQgnIndiAiNtDirectio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtDirectio };

static const TAknsItemID KAknsIIDQgnIndiAiNtDownload =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtDownload };

static const TAknsItemID KAknsIIDQgnIndiAiNtEconomy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtEconomy };

static const TAknsItemID KAknsIIDQgnIndiAiNtErotic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtErotic };

static const TAknsItemID KAknsIIDQgnIndiAiNtEvent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtEvent };

static const TAknsItemID KAknsIIDQgnIndiAiNtFilm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtFilm };

static const TAknsItemID KAknsIIDQgnIndiAiNtFinanceu =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtFinanceu };

static const TAknsItemID KAknsIIDQgnIndiAiNtFinancuk =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtFinancuk };

static const TAknsItemID KAknsIIDQgnIndiAiNtFind =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtFind };

static const TAknsItemID KAknsIIDQgnIndiAiNtFlirt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtFlirt };

static const TAknsItemID KAknsIIDQgnIndiAiNtFormula1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtFormula1 };

static const TAknsItemID KAknsIIDQgnIndiAiNtFun =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtFun };

static const TAknsItemID KAknsIIDQgnIndiAiNtGames =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtGames };

static const TAknsItemID KAknsIIDQgnIndiAiNtHoroscop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtHoroscop };

static const TAknsItemID KAknsIIDQgnIndiAiNtLottery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtLottery };

static const TAknsItemID KAknsIIDQgnIndiAiNtMessage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtMessage };

static const TAknsItemID KAknsIIDQgnIndiAiNtMusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtMusic };

static const TAknsItemID KAknsIIDQgnIndiAiNtNewidea =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtNewidea };

static const TAknsItemID KAknsIIDQgnIndiAiNtNews =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtNews };

static const TAknsItemID KAknsIIDQgnIndiAiNtNewsweat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtNewsweat };

static const TAknsItemID KAknsIIDQgnIndiAiNtParty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtParty };

static const TAknsItemID KAknsIIDQgnIndiAiNtShopping =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtShopping };

static const TAknsItemID KAknsIIDQgnIndiAiNtSoccer1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtSoccer1 };

static const TAknsItemID KAknsIIDQgnIndiAiNtSoccer2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtSoccer2 };

static const TAknsItemID KAknsIIDQgnIndiAiNtSoccerwc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtSoccerwc };

static const TAknsItemID KAknsIIDQgnIndiAiNtStar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtStar };

static const TAknsItemID KAknsIIDQgnIndiAiNtTopten =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtTopten };

static const TAknsItemID KAknsIIDQgnIndiAiNtTravel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtTravel };

static const TAknsItemID KAknsIIDQgnIndiAiNtTv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtTv };

static const TAknsItemID KAknsIIDQgnIndiAiNtVodafone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtVodafone };

static const TAknsItemID KAknsIIDQgnIndiAiNtWeather =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtWeather };

static const TAknsItemID KAknsIIDQgnIndiAiNtWinterol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtWinterol };

static const TAknsItemID KAknsIIDQgnIndiAiNtXmas =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtXmas };

static const TAknsItemID KAknsIIDQgnPropPinbEight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPinbEight };

static const TAknsItemID KAknsIIDQgnGrafMmsPostcardBack =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsPostcardBack };

static const TAknsItemID KAknsIIDQgnGrafMmsPostcardFront =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsPostcardFront };

static const TAknsItemID KAknsIIDQgnGrafMmsPostcardInsertImageBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsPostcardInsertImageBg };

static const TAknsItemID KAknsIIDQgnIndiFileCorruptedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFileCorruptedAdd };

static const TAknsItemID KAknsIIDQgnIndiMmsPostcardDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsPostcardDown };

static const TAknsItemID KAknsIIDQgnIndiMmsPostcardImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsPostcardImage };

static const TAknsItemID KAknsIIDQgnIndiMmsPostcardStamp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsPostcardStamp };

static const TAknsItemID KAknsIIDQgnIndiMmsPostcardText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsPostcardText };

static const TAknsItemID KAknsIIDQgnIndiMmsPostcardUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsPostcardUp };

static const TAknsItemID KAknsIIDQgnIndiMupButtonMcDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonMcDimmed };

static const TAknsItemID KAknsIIDQgnIndiMupButtonStopInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonStopInact };

static const TAknsItemID KAknsIIDQgnIndiMupRandom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupRandom };

static const TAknsItemID KAknsIIDQgnIndiMupRepeat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupRepeat };

static const TAknsItemID KAknsIIDQgnIndiWmlWindows =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWmlWindows };

static const TAknsItemID KAknsIIDQgnPropFileVideoMp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileVideoMp };

static const TAknsItemID KAknsIIDQgnPropMcePostcard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMcePostcard };

static const TAknsItemID KAknsIIDQgnPropMmsPostcardAddressActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsPostcardAddressActive };

static const TAknsItemID KAknsIIDQgnPropMmsPostcardAddressInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsPostcardAddressInactive };

static const TAknsItemID KAknsIIDQgnPropMmsPostcardGreetingActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsPostcardGreetingActive };

static const TAknsItemID KAknsIIDQgnPropMmsPostcardGreetingInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmsPostcardGreetingInactive };

static const TAknsItemID KAknsIIDQgnPropDrmExpForbidSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmExpForbidSuper };

static const TAknsItemID KAknsIIDQgnPropDrmRemovedLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRemovedLarge };

static const TAknsItemID KAknsIIDQgnPropDrmRemovedTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRemovedTab3 };

static const TAknsItemID KAknsIIDQgnPropDrmRightsExpSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRightsExpSuper };

static const TAknsItemID KAknsIIDQgnPropDrmRightsGroup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRightsGroup };

static const TAknsItemID KAknsIIDQgnPropDrmRightsInvalidTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRightsInvalidTab3 };

static const TAknsItemID KAknsIIDQgnPropDrmRightsValidSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRightsValidSuper };

static const TAknsItemID KAknsIIDQgnPropDrmRightsValidTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmRightsValidTab3 };

static const TAknsItemID KAknsIIDQgnPropDrmSendForbidSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmSendForbidSuper };

static const TAknsItemID KAknsIIDQgnPropDrmValidLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDrmValidLarge };

static const TAknsItemID KAknsIIDQgnPropMupPlaylistAuto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupPlaylistAuto };

static const TAknsItemID KAknsIIDQgnStatCarkit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCarkit };

static const TAknsItemID KAknsIIDQgnGrafMmsVolumeOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsVolumeOff };

static const TAknsItemID KAknsIIDQgnGrafMmsVolumeOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsVolumeOn };

static const TAknsItemID KAknsIIDQgnStatRoaming =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatRoaming };

static const TAknsItemID KAknsIIDQgnStatRoamingUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatRoamingUni };

static const TAknsItemID KAknsIIDQgnGrafBarFrameCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarFrameCenter };

static const TAknsItemID KAknsIIDQgnGrafBgPhobThumbnail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBgPhobThumbnail };

static const TAknsItemID KAknsIIDQgnGrafBlidDirMask =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidDirMask };

static const TAknsItemID KAknsIIDQgnGrafCalcResultsLine =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCalcResultsLine };

static const TAknsItemID KAknsIIDQgnGrafMupBarFrame =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupBarFrame };

static const TAknsItemID KAknsIIDQgnIndiAiNtAntenna =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtAntenna };

static const TAknsItemID KAknsIIDQgnIndiAiNtArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtArrowLeft };

static const TAknsItemID KAknsIIDQgnIndiAiNtArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtArrowRight };

static const TAknsItemID KAknsIIDQgnIndiAiNtAt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtAt };

static const TAknsItemID KAknsIIDQgnIndiAiNtAttentio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtAttentio };

static const TAknsItemID KAknsIIDQgnIndiAiNtBirthday =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtBirthday };

static const TAknsItemID KAknsIIDQgnIndiAiNtCamera =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtCamera };

static const TAknsItemID KAknsIIDQgnIndiAiNtCar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtCar };

static const TAknsItemID KAknsIIDQgnIndiAiNtConferen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtConferen };

static const TAknsItemID KAknsIIDQgnIndiAiNtDisc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtDisc };

static const TAknsItemID KAknsIIDQgnIndiAiNtFilm1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtFilm1 };

static const TAknsItemID KAknsIIDQgnIndiAiNtFilmcam =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtFilmcam };

static const TAknsItemID KAknsIIDQgnIndiAiNtFirstaid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtFirstaid };

static const TAknsItemID KAknsIIDQgnIndiAiNtHeadset =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtHeadset };

static const TAknsItemID KAknsIIDQgnIndiAiNtLove =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtLove };

static const TAknsItemID KAknsIIDQgnIndiAiNtMicrowav =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtMicrowav };

static const TAknsItemID KAknsIIDQgnIndiAiNtMoney =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtMoney };

static const TAknsItemID KAknsIIDQgnIndiAiNtMusic1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtMusic1 };

static const TAknsItemID KAknsIIDQgnIndiAiNtRadio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtRadio };

static const TAknsItemID KAknsIIDQgnIndiAiNtRecordpl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtRecordpl };

static const TAknsItemID KAknsIIDQgnIndiAiNtScreen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtScreen };

static const TAknsItemID KAknsIIDQgnIndiAiNtStopwatc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtStopwatc };

static const TAknsItemID KAknsIIDQgnIndiAiNtTheme =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtTheme };

static const TAknsItemID KAknsIIDQgnIndiAiNtTourweat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtTourweat };

static const TAknsItemID KAknsIIDQgnIndiAiNtWorld =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiNtWorld };

static const TAknsItemID KAknsIIDQgnIndiDrmRightsAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDrmRightsAdd };

static const TAknsItemID KAknsIIDQgnPropFileSwf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileSwf };

static const TAknsItemID KAknsIIDQgnPropFileSwfSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileSwfSmall };

static const TAknsItemID KAknsIIDQgnIndiVoipCallActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVoipCallActive };

static const TAknsItemID KAknsIIDQgnIndiVoipCallActive2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVoipCallActive2 };

static const TAknsItemID KAknsIIDQgnIndiVoipCallDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVoipCallDisconn };

static const TAknsItemID KAknsIIDQgnIndiVoipCallHeld =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVoipCallHeld };

static const TAknsItemID KAknsIIDQgnIndiVoipCallWaiting1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVoipCallWaiting1 };

static const TAknsItemID KAknsIIDQgnIndiVoipCallWaiting2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVoipCallWaiting2 };

static const TAknsItemID KAknsIIDQgnIndiVoipCallWaitingDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVoipCallWaitingDisconn };

static const TAknsItemID KAknsIIDQgnIndiVoipReadiness =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVoipReadiness };

static const TAknsItemID KAknsIIDQgnStatDivertVoip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDivertVoip };

static const TAknsItemID KAknsIIDQgnStatImPs12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatImPs12 };

static const TAknsItemID KAknsIIDQgnStatImPs16 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatImPs16 };

static const TAknsItemID KAknsIIDQgnStatKeyguardPs12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatKeyguardPs12 };

static const TAknsItemID KAknsIIDQgnStatKeyguardPs16 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatKeyguardPs16 };

static const TAknsItemID KAknsIIDQgnStatMessageMailPs12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageMailPs12 };

static const TAknsItemID KAknsIIDQgnStatMessageMailPs16 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageMailPs16 };

static const TAknsItemID KAknsIIDQgnStatMessagePs12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessagePs12 };

static const TAknsItemID KAknsIIDQgnStatMessagePs16 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessagePs16 };

static const TAknsItemID KAknsIIDQgnStatMissedCallsPs12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMissedCallsPs12 };

static const TAknsItemID KAknsIIDQgnStatMissedCallsPs16 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMissedCallsPs16 };

static const TAknsItemID KAknsIIDQgnStatVm0Ps12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVm0Ps12 };

static const TAknsItemID KAknsIIDQgnStatVm0Ps16 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVm0Ps16 };

static const TAknsItemID KAknsIIDQgnGrafBlidDirringMask =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidDirringMask };

static const TAknsItemID KAknsIIDQgnGrafCallFirstOneActiveEmegency =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCallFirstOneActiveEmegency };

static const TAknsItemID KAknsIIDQgnGrafMmsAudioDrmInvalidSendForbid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsAudioDrmInvalidSendForbid };

static const TAknsItemID KAknsIIDQgnGrafMmsAudioDrmValidSend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsAudioDrmValidSend };

static const TAknsItemID KAknsIIDQgnGrafMmsAudioDrmValidSendForbid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsAudioDrmValidSendForbid };

static const TAknsItemID KAknsIIDQgnGrafMmsImageDrmInvalidSendForbid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsImageDrmInvalidSendForbid };

static const TAknsItemID KAknsIIDQgnGrafMmsPres =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsPres };

static const TAknsItemID KAknsIIDQgnGrafMmsPresCorrupted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsPresCorrupted };

static const TAknsItemID KAknsIIDQgnGrafMmsPresDrmInvalidSend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsPresDrmInvalidSend };

static const TAknsItemID KAknsIIDQgnGrafMmsPresDrmInvalidSendForbid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsPresDrmInvalidSendForbid };

static const TAknsItemID KAknsIIDQgnGrafMmsVideoDrmInvalidSendForbid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsVideoDrmInvalidSendForbid };

static const TAknsItemID KAknsIIDQgnGrafMmsVideoDrmValidSend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsVideoDrmValidSend };

static const TAknsItemID KAknsIIDQgnGrafMmsVideoDrmValidSendForbid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsVideoDrmValidSendForbid };

static const TAknsItemID KAknsIIDQgnGrafShutdown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafShutdown };

static const TAknsItemID KAknsIIDQgnGrafShutdownBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafShutdownBg };

static const TAknsItemID KAknsIIDQgnGrafStartup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafStartup };

static const TAknsItemID KAknsIIDQgnGrafStartupBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafStartupBg };

static const TAknsItemID KAknsIIDQgnGrafUsb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafUsb };

static const TAknsItemID KAknsIIDQgnGrafUsbBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafUsbBg };

static const TAknsItemID KAknsIIDQgnIndiCallActiveEmergencyCallsta =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallActiveEmergencyCallsta };

static const TAknsItemID KAknsIIDQgnIndiMcePriorityHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMcePriorityHigh };

static const TAknsItemID KAknsIIDQgnIndiMcePriorityLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMcePriorityLow };

static const TAknsItemID KAknsIIDQgnIndiMupButtonNextDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonNextDimmed };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPauseDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPauseDimmed };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPlayDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPlayDimmed };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPrevDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPrevDimmed };

static const TAknsItemID KAknsIIDQgnIndiMupButtonStopDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonStopDimmed };

static const TAknsItemID KAknsIIDQgnIndiMupRepeatOne =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupRepeatOne };

static const TAknsItemID KAknsIIDQgnIndiPocAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPocAdd };

static const TAknsItemID KAknsIIDQgnIndiVietFindSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVietFindSmall };

static const TAknsItemID KAknsIIDQgnNotePoc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNotePoc };

static const TAknsItemID KAknsIIDQgnPropFilePresentation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFilePresentation };

static const TAknsItemID KAknsIIDQgnPropFilePresentationsSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFilePresentationsSub };

static const TAknsItemID KAknsIIDQgnPropFilePresentationsTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFilePresentationsTab4 };

static const TAknsItemID KAknsIIDQgnPropImFriendInvisible =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendInvisible };

static const TAknsItemID KAknsIIDQgnPropMceDelivered =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceDelivered };

static const TAknsItemID KAknsIIDQgnPropMceDeliveryFailed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceDeliveryFailed };

static const TAknsItemID KAknsIIDQgnPropMceDeliveryPending =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceDeliveryPending };

static const TAknsItemID KAknsIIDQgnPropMceMmsDelivered =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMmsDelivered };

static const TAknsItemID KAknsIIDQgnPropMceMmsDeliveryFailed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMmsDeliveryFailed };

static const TAknsItemID KAknsIIDQgnPropMceMmsDeliveryPending =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMmsDeliveryPending };

static const TAknsItemID KAknsIIDQgnPropMocFile =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMocFile };

static const TAknsItemID KAknsIIDQgnPropMocFolder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMocFolder };

static const TAknsItemID KAknsIIDQgnPropMocFolderSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMocFolderSub };

static const TAknsItemID KAknsIIDQgnPropModAudio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModAudio };

static const TAknsItemID KAknsIIDQgnPropModAudioCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModAudioCol };

static const TAknsItemID KAknsIIDQgnPropModAudioExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModAudioExp };

static const TAknsItemID KAknsIIDQgnPropModChapter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModChapter };

static const TAknsItemID KAknsIIDQgnPropModChapterCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModChapterCol };

static const TAknsItemID KAknsIIDQgnPropModChapterExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModChapterExp };

static const TAknsItemID KAknsIIDQgnPropModComment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModComment };

static const TAknsItemID KAknsIIDQgnPropModCommentCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModCommentCol };

static const TAknsItemID KAknsIIDQgnPropModCommentExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModCommentExp };

static const TAknsItemID KAknsIIDQgnPropModDoc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModDoc };

static const TAknsItemID KAknsIIDQgnPropModDocCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModDocCol };

static const TAknsItemID KAknsIIDQgnPropModDocExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModDocExp };

static const TAknsItemID KAknsIIDQgnPropModHierarchyViewTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModHierarchyViewTab3 };

static const TAknsItemID KAknsIIDQgnPropModImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModImage };

static const TAknsItemID KAknsIIDQgnPropModImageCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModImageCol };

static const TAknsItemID KAknsIIDQgnPropModImageExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModImageExp };

static const TAknsItemID KAknsIIDQgnPropModLayoutViewTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModLayoutViewTab3 };

static const TAknsItemID KAknsIIDQgnPropModLink =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModLink };

static const TAknsItemID KAknsIIDQgnPropModLinkCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModLinkCol };

static const TAknsItemID KAknsIIDQgnPropModLinkExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModLinkExp };

static const TAknsItemID KAknsIIDQgnPropModNormViewTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModNormViewTab3 };

static const TAknsItemID KAknsIIDQgnPropModPaint =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModPaint };

static const TAknsItemID KAknsIIDQgnPropModPaintCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModPaintCol };

static const TAknsItemID KAknsIIDQgnPropModPaintExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModPaintExp };

static const TAknsItemID KAknsIIDQgnPropModPresentation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModPresentation };

static const TAknsItemID KAknsIIDQgnPropModPresentationCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModPresentationCol };

static const TAknsItemID KAknsIIDQgnPropModPresentationExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModPresentationExp };

static const TAknsItemID KAknsIIDQgnPropModReference =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModReference };

static const TAknsItemID KAknsIIDQgnPropModReferenceCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModReferenceCol };

static const TAknsItemID KAknsIIDQgnPropModReferenceExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModReferenceExp };

static const TAknsItemID KAknsIIDQgnPropModSheet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModSheet };

static const TAknsItemID KAknsIIDQgnPropModSheetCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModSheetCol };

static const TAknsItemID KAknsIIDQgnPropModSheetExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModSheetExp };

static const TAknsItemID KAknsIIDQgnPropModTable =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModTable };

static const TAknsItemID KAknsIIDQgnPropModTableCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModTableCol };

static const TAknsItemID KAknsIIDQgnPropModTableExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModTableExp };

static const TAknsItemID KAknsIIDQgnPropModUnknown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModUnknown };

static const TAknsItemID KAknsIIDQgnPropModUnknownCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModUnknownCol };

static const TAknsItemID KAknsIIDQgnPropModUnknownExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModUnknownExp };

static const TAknsItemID KAknsIIDQgnPropModVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModVideo };

static const TAknsItemID KAknsIIDQgnPropModVideoCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModVideoCol };

static const TAknsItemID KAknsIIDQgnPropModVideoExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModVideoExp };

static const TAknsItemID KAknsIIDQgnPropMopAlignHorizontalCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAlignHorizontalCenter };

static const TAknsItemID KAknsIIDQgnPropMopAlignHorizontalLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAlignHorizontalLeft };

static const TAknsItemID KAknsIIDQgnPropMopAlignHorizontalRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAlignHorizontalRight };

static const TAknsItemID KAknsIIDQgnPropMopAlignVerticalBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAlignVerticalBottom };

static const TAknsItemID KAknsIIDQgnPropMopAlignVerticalCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAlignVerticalCenter };

static const TAknsItemID KAknsIIDQgnPropMopAlignVerticalTop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAlignVerticalTop };

static const TAknsItemID KAknsIIDQgnPropMopAutoshape =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshape };

static const TAknsItemID KAknsIIDQgnPropMopAutoshapeArrowDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshapeArrowDown };

static const TAknsItemID KAknsIIDQgnPropMopAutoshapeArrowHeadDouble =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshapeArrowHeadDouble };

static const TAknsItemID KAknsIIDQgnPropMopAutoshapeArrowHeadSingle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshapeArrowHeadSingle };

static const TAknsItemID KAknsIIDQgnPropMopAutoshapeArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshapeArrowLeft };

static const TAknsItemID KAknsIIDQgnPropMopAutoshapeArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshapeArrowRight };

static const TAknsItemID KAknsIIDQgnPropMopAutoshapeArrowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshapeArrowUp };

static const TAknsItemID KAknsIIDQgnPropMopAutoshapeLine =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshapeLine };

static const TAknsItemID KAknsIIDQgnPropMopAutoshapeOval =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshapeOval };

static const TAknsItemID KAknsIIDQgnPropMopAutoshapeRectangle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshapeRectangle };

static const TAknsItemID KAknsIIDQgnPropMopAutoshapeRoundRectangle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshapeRoundRectangle };

static const TAknsItemID KAknsIIDQgnPropMopAutoshapeSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshapeSmall };

static const TAknsItemID KAknsIIDQgnPropMopAutoshapeTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopAutoshapeTab2 };

static const TAknsItemID KAknsIIDQgnPropMopBackgroundTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopBackgroundTab2 };

static const TAknsItemID KAknsIIDQgnPropMopBorderTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopBorderTab2 };

static const TAknsItemID KAknsIIDQgnPropMopChart =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopChart };

static const TAknsItemID KAknsIIDQgnPropMopChartSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopChartSmall };

static const TAknsItemID KAknsIIDQgnPropMopComment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopComment };

static const TAknsItemID KAknsIIDQgnPropMopCommentSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopCommentSmall };

static const TAknsItemID KAknsIIDQgnPropMopEmpty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopEmpty };

static const TAknsItemID KAknsIIDQgnPropMopImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopImage };

static const TAknsItemID KAknsIIDQgnPropMopImageSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopImageSmall };

static const TAknsItemID KAknsIIDQgnPropMopLayoutTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopLayoutTab3 };

static const TAknsItemID KAknsIIDQgnPropMopLineTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopLineTab2 };

static const TAknsItemID KAknsIIDQgnPropMopNotesTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopNotesTab3 };

static const TAknsItemID KAknsIIDQgnPropMopNoteSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopNoteSmall };

static const TAknsItemID KAknsIIDQgnPropMopOutlineTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopOutlineTab3 };

static const TAknsItemID KAknsIIDQgnPropMopSetLayoutTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSetLayoutTab3 };

static const TAknsItemID KAknsIIDQgnPropMopSetNotesTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSetNotesTab3 };

static const TAknsItemID KAknsIIDQgnPropMopSetOutlineTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSetOutlineTab3 };

static const TAknsItemID KAknsIIDQgnPropMopSlide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlide };

static const TAknsItemID KAknsIIDQgnPropMopSlide2Column =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlide2Column };

static const TAknsItemID KAknsIIDQgnPropMopSlideBlank =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlideBlank };

static const TAknsItemID KAknsIIDQgnPropMopSlideBullets =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlideBullets };

static const TAknsItemID KAknsIIDQgnPropMopSlideCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlideCol };

static const TAknsItemID KAknsIIDQgnPropMopSlideColHidden =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlideColHidden };

static const TAknsItemID KAknsIIDQgnPropMopSlideExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlideExp };

static const TAknsItemID KAknsIIDQgnPropMopSlideExpHidden =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlideExpHidden };

static const TAknsItemID KAknsIIDQgnPropMopSlideHidden =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlideHidden };

static const TAknsItemID KAknsIIDQgnPropMopSlideImageAndText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlideImageAndText };

static const TAknsItemID KAknsIIDQgnPropMopSlideTable =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlideTable };

static const TAknsItemID KAknsIIDQgnPropMopSlideTextAndImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlideTextAndImage };

static const TAknsItemID KAknsIIDQgnPropMopSlideTitle1Row =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlideTitle1Row };

static const TAknsItemID KAknsIIDQgnPropMopSlideTitle2Row =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopSlideTitle2Row };

static const TAknsItemID KAknsIIDQgnPropMopTable =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopTable };

static const TAknsItemID KAknsIIDQgnPropMopTableSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopTableSmall };

static const TAknsItemID KAknsIIDQgnPropMopTextbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopTextbox };

static const TAknsItemID KAknsIIDQgnPropMopTextboxSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopTextboxSmall };

static const TAknsItemID KAknsIIDQgnPropMopTextboxTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopTextboxTab2 };

static const TAknsItemID KAknsIIDQgnPropMopUnknown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopUnknown };

static const TAknsItemID KAknsIIDQgnPropMopUnknownSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMopUnknownSmall };

static const TAknsItemID KAknsIIDQgnPropMoEmpty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMoEmpty };

static const TAknsItemID KAknsIIDQgnPropMoFormatBorderTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMoFormatBorderTab4 };

static const TAknsItemID KAknsIIDQgnPropMoFormatBulletTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMoFormatBulletTab4 };

static const TAknsItemID KAknsIIDQgnPropMoFormatFontStyleTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMoFormatFontStyleTab4 };

static const TAknsItemID KAknsIIDQgnPropMoFormatFontTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMoFormatFontTab4 };

static const TAknsItemID KAknsIIDQgnPropMoFormatParaTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMoFormatParaTab4 };

static const TAknsItemID KAknsIIDQgnPropMoMmcMemc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMoMmcMemc };

static const TAknsItemID KAknsIIDQgnPropMoPhoneMemc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMoPhoneMemc };

static const TAknsItemID KAknsIIDQgnPropNrtypCnap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypCnap };

static const TAknsItemID KAknsIIDQgnPropNrtypPoc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypPoc };

static const TAknsItemID KAknsIIDQgnStatFarsiCase =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatFarsiCase };

static const TAknsItemID KAknsIIDQgnStatPocDnd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatPocDnd };

static const TAknsItemID KAknsIIDQgnStatPocMissed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatPocMissed };

static const TAknsItemID KAknsIIDQgnStatPocMissedUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatPocMissedUni };

static const TAknsItemID KAknsIIDQgnStatPocPocOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatPocPocOn };

static const TAknsItemID KAknsIIDQgnGrafBarFrameSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarFrameSideL };

static const TAknsItemID KAknsIIDQgnGrafBarFrameSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarFrameSideR };

static const TAknsItemID KAknsIIDQgnPropCaleAccepted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCaleAccepted };

static const TAknsItemID KAknsIIDQgnPropCaleAttendance =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCaleAttendance };

static const TAknsItemID KAknsIIDQgnPropCaleInfo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCaleInfo };

static const TAknsItemID KAknsIIDQgnPropCaleNotanswered =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCaleNotanswered };

static const TAknsItemID KAknsIIDQgnPropCaleOrganizer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCaleOrganizer };

static const TAknsItemID KAknsIIDQgnPropCaleRejected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCaleRejected };

static const TAknsItemID KAknsIIDQgnPropCaleTentative =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCaleTentative };

static const TAknsItemID KAknsIIDQgnPropMceMeetreqFetRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMeetreqFetRead };

static const TAknsItemID KAknsIIDQgnPropMceMeetreqFetUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMeetreqFetUnread };

static const TAknsItemID KAknsIIDQgnPropMceMeetreqReaDel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMeetreqReaDel };

static const TAknsItemID KAknsIIDQgnPropMceMeetreqUnfetRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMeetreqUnfetRead };

static const TAknsItemID KAknsIIDQgnPropMceMeetreqUnfetUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMeetreqUnfetUnread };

static const TAknsItemID KAknsIIDQgnGrafLineMessageHorizontal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafLineMessageHorizontal };

static const TAknsItemID KAknsIIDQgnPropGroupCollapsed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropGroupCollapsed };

static const TAknsItemID KAknsIIDQgnPropGroupExpanded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropGroupExpanded };

static const TAknsItemID KAknsIIDQgnPropSnoteWlanAdhoc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSnoteWlanAdhoc };

static const TAknsItemID KAknsIIDQgnPropSnoteWlanInfra =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSnoteWlanInfra };

static const TAknsItemID KAknsIIDQgnStatVoipReadiness =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVoipReadiness };

static const TAknsItemID KAknsIIDQgnPropMceMeetreqReadDel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMeetreqReadDel };

static const TAknsItemID KAknsIIDQgnPropMosCells =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosCells };

static const TAknsItemID KAknsIIDQgnPropMosChart =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosChart };

static const TAknsItemID KAknsIIDQgnPropMosClearBoth =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosClearBoth };

static const TAknsItemID KAknsIIDQgnPropMosClearContent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosClearContent };

static const TAknsItemID KAknsIIDQgnPropMosClearFormatting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosClearFormatting };

static const TAknsItemID KAknsIIDQgnPropMosDetailsTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosDetailsTab2 };

static const TAknsItemID KAknsIIDQgnPropMosEditCell =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosEditCell };

static const TAknsItemID KAknsIIDQgnPropMosEditLinkAddress =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosEditLinkAddress };

static const TAknsItemID KAknsIIDQgnPropMosEditLinkName =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosEditLinkName };

static const TAknsItemID KAknsIIDQgnPropMosEditName =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosEditName };

static const TAknsItemID KAknsIIDQgnPropMosFindLocTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFindLocTab2 };

static const TAknsItemID KAknsIIDQgnPropMosFindTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFindTab2 };

static const TAknsItemID KAknsIIDQgnPropMosFormatAlignTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFormatAlignTab4 };

static const TAknsItemID KAknsIIDQgnPropMosFormatNumberTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFormatNumberTab4 };

static const TAknsItemID KAknsIIDQgnPropMosFuncAllTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncAllTab3 };

static const TAknsItemID KAknsIIDQgnPropMosFuncCategoryTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncCategoryTab3 };

static const TAknsItemID KAknsIIDQgnPropMosFuncCommonTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncCommonTab3 };

static const TAknsItemID KAknsIIDQgnPropMosFuncDatetime =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncDatetime };

static const TAknsItemID KAknsIIDQgnPropMosFuncDatetimeTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncDatetimeTab4 };

static const TAknsItemID KAknsIIDQgnPropMosFuncFinancial =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncFinancial };

static const TAknsItemID KAknsIIDQgnPropMosFuncFinancialTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncFinancialTab4 };

static const TAknsItemID KAknsIIDQgnPropMosFuncInfo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncInfo };

static const TAknsItemID KAknsIIDQgnPropMosFuncInfoTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncInfoTab4 };

static const TAknsItemID KAknsIIDQgnPropMosFuncLogical =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncLogical };

static const TAknsItemID KAknsIIDQgnPropMosFuncLogicalTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncLogicalTab4 };

static const TAknsItemID KAknsIIDQgnPropMosFuncLookup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncLookup };

static const TAknsItemID KAknsIIDQgnPropMosFuncLookupTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncLookupTab4 };

static const TAknsItemID KAknsIIDQgnPropMosFuncMath =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncMath };

static const TAknsItemID KAknsIIDQgnPropMosFuncMathTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncMathTab4 };

static const TAknsItemID KAknsIIDQgnPropMosFuncStatistic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncStatistic };

static const TAknsItemID KAknsIIDQgnPropMosFuncStatisticTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncStatisticTab4 };

static const TAknsItemID KAknsIIDQgnPropMosFuncText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncText };

static const TAknsItemID KAknsIIDQgnPropMosFuncTextTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosFuncTextTab4 };

static const TAknsItemID KAknsIIDQgnPropMosLabelTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosLabelTab2 };

static const TAknsItemID KAknsIIDQgnPropMosSelectSheet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosSelectSheet };

static const TAknsItemID KAknsIIDQgnPropMosSetChartStyleTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosSetChartStyleTab2 };

static const TAknsItemID KAknsIIDQgnPropMosSetChartTitleTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosSetChartTitleTab2 };

static const TAknsItemID KAknsIIDQgnPropMosSetGeneralTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosSetGeneralTab2 };

static const TAknsItemID KAknsIIDQgnPropMosSetSheetTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosSetSheetTab2 };

static const TAknsItemID KAknsIIDQgnPropMosSheet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosSheet };

static const TAknsItemID KAknsIIDQgnPropMosSheetCol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosSheetCol };

static const TAknsItemID KAknsIIDQgnPropMosSheetExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosSheetExp };

static const TAknsItemID KAknsIIDQgnPropMosXaxisScaleTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosXaxisScaleTab2 };

static const TAknsItemID KAknsIIDQgnPropMosXaxisStyleTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosXaxisStyleTab2 };

static const TAknsItemID KAknsIIDQgnPropMosYaxisAppearTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosYaxisAppearTab3 };

static const TAknsItemID KAknsIIDQgnPropMosYaxisFormatTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosYaxisFormatTab3 };

static const TAknsItemID KAknsIIDQgnPropMosYaxisScaleTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMosYaxisScaleTab3 };

static const TAknsItemID KAknsIIDQgnStatModTarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatModTarm };

static const TAknsItemID KAknsIIDQgnStatTarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatTarm };

static const TAknsItemID KAknsIIDQgnGrafMupVisualizerImageMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupVisualizerImageMaskIcon };

static const TAknsItemID KAknsIIDQgnPropDycInsertImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDycInsertImage };

static const TAknsItemID KAknsIIDQgnGrafBlidDirBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidDirBg };

static const TAknsItemID KAknsIIDQgnGrafMupVisualizerBgImage1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupVisualizerBgImage1 };

static const TAknsItemID KAknsIIDQgnGrafMupVisualizerBgImage2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupVisualizerBgImage2 };

static const TAknsItemID KAknsIIDQgnIndiPocContactAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPocContactAdd };

static const TAknsItemID KAknsIIDQgnPropFileRss =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileRss };

static const TAknsItemID KAknsIIDQgnPropFolderRss =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderRss };

static const TAknsItemID KAknsIIDQgnPropPocBlock =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocBlock };

static const TAknsItemID KAknsIIDQgnStatTvout =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatTvout };

static const TAknsItemID KAknsIIDQgnGrafIdleFadeLsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafIdleFadeLsc };

static const TAknsItemID KAknsIIDQgnGrafScrollArrowDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafScrollArrowDown };

static const TAknsItemID KAknsIIDQgnGrafScrollArrowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafScrollArrowUp };

static const TAknsItemID KAknsIIDQgnGrafStatIndiButtonAvailable =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafStatIndiButtonAvailable };

static const TAknsItemID KAknsIIDQgnGrafTouchBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTouchBg };

static const TAknsItemID KAknsIIDQgnIndiAiMusicForw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiMusicForw };

static const TAknsItemID KAknsIIDQgnIndiAiMusicRew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiMusicRew };

static const TAknsItemID KAknsIIDQgnIndiCypheringOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCypheringOn };

static const TAknsItemID KAknsIIDQgnIndiMceAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMceAttach };

static const TAknsItemID KAknsIIDQgnIndiMmsAudioPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsAudioPause };

static const TAknsItemID KAknsIIDQgnIndiMmsAudioPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsAudioPlay };

static const TAknsItemID KAknsIIDQgnIndiMmsAudioRecord =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsAudioRecord };

static const TAknsItemID KAknsIIDQgnIndiMtvParentalControl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMtvParentalControl };

static const TAknsItemID KAknsIIDQgnIndiMtvPaused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMtvPaused };

static const TAknsItemID KAknsIIDQgnIndiMtvRec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMtvRec };

static const TAknsItemID KAknsIIDQgnIndiMtvRecAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMtvRecAdd };

static const TAknsItemID KAknsIIDQgnIndiMtvRightsForbid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMtvRightsForbid };

static const TAknsItemID KAknsIIDQgnIndiMtvServicesInfoAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMtvServicesInfoAdd };

static const TAknsItemID KAknsIIDQgnIndiMupForw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupForw };

static const TAknsItemID KAknsIIDQgnIndiMupForwAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupForwAdd };

static const TAknsItemID KAknsIIDQgnIndiMupRew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupRew };

static const TAknsItemID KAknsIIDQgnIndiMupRewAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupRewAdd };

static const TAknsItemID KAknsIIDQgnIndiTouchAvailable =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTouchAvailable };

static const TAknsItemID KAknsIIDQgnIndiTouchSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTouchSelected };

static const TAknsItemID KAknsIIDQgnIndiTouchUnavailable =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTouchUnavailable };

static const TAknsItemID KAknsIIDQgnIndiTpAppsgrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpAppsgrid };

static const TAknsItemID KAknsIIDQgnIndiTpAppswapper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpAppswapper };

static const TAknsItemID KAknsIIDQgnIndiTpFullscreen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpFullscreen };

static const TAknsItemID KAknsIIDQgnIndiTpIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpIdle };

static const TAknsItemID KAknsIIDQgnIndiTpInput =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpInput };

static const TAknsItemID KAknsIIDQgnIndiTpRotateScreen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpRotateScreen };

static const TAknsItemID KAknsIIDQgnIndiTpToolbar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpToolbar };

static const TAknsItemID KAknsIIDQgnMenuImAway =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuImAway };

static const TAknsItemID KAknsIIDQgnMenuImInvisible =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuImInvisible };

static const TAknsItemID KAknsIIDQgnMenuImOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuImOn };

static const TAknsItemID KAknsIIDQgnNoteBrowser =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteBrowser };

static const TAknsItemID KAknsIIDQgnNoteMtvProgStart =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteMtvProgStart };

static const TAknsItemID KAknsIIDQgnPropFmgrBackupSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrBackupSub };

static const TAknsItemID KAknsIIDQgnPropFmgrMmcNoSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrMmcNoSub };

static const TAknsItemID KAknsIIDQgnPropFmgrMmcSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrMmcSub };

static const TAknsItemID KAknsIIDQgnPropFmgrPhoneMemcSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrPhoneMemcSub };

static const TAknsItemID KAknsIIDQgnPropFolderEmpty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderEmpty };

static const TAknsItemID KAknsIIDQgnPropImJoinedNotSavedUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImJoinedNotSavedUnread };

static const TAknsItemID KAknsIIDQgnPropImListUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImListUnread };

static const TAknsItemID KAknsIIDQgnPropImNonuserCreatedSavedActiveUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImNonuserCreatedSavedActiveUnread };

static const TAknsItemID KAknsIIDQgnPropImUserCreatedActiveUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImUserCreatedActiveUnread };

static const TAknsItemID KAknsIIDQgnPropMceAudio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceAudio };

static const TAknsItemID KAknsIIDQgnPropMceAudioUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceAudioUnread };

static const TAknsItemID KAknsIIDQgnPropMtvChannel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvChannel };

static const TAknsItemID KAknsIIDQgnPropMtvChannelPackage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvChannelPackage };

static const TAknsItemID KAknsIIDQgnPropMtvChannelProgramSecured =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvChannelProgramSecured };

static const TAknsItemID KAknsIIDQgnPropMtvFolderVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvFolderVideo };

static const TAknsItemID KAknsIIDQgnPropMtvFolderVideoNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvFolderVideoNew };

static const TAknsItemID KAknsIIDQgnPropMtvParentalControl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvParentalControl };

static const TAknsItemID KAknsIIDQgnPropMtvProgram =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvProgram };

static const TAknsItemID KAknsIIDQgnPropMtvProgClip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvProgClip };

static const TAknsItemID KAknsIIDQgnPropMtvProgClipNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvProgClipNew };

static const TAknsItemID KAknsIIDQgnPropMtvRightsForbid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvRightsForbid };

static const TAknsItemID KAknsIIDQgnPropMtvServicesCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvServicesCall };

static const TAknsItemID KAknsIIDQgnPropMtvServicesJava =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvServicesJava };

static const TAknsItemID KAknsIIDQgnPropMtvServicesSms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvServicesSms };

static const TAknsItemID KAknsIIDQgnPropMtvServicesWeb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMtvServicesWeb };

static const TAknsItemID KAknsIIDQgnPropNrtypSimContact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypSimContact };

static const TAknsItemID KAknsIIDQgnPropPocChannelGroup1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocChannelGroup1 };

static const TAknsItemID KAknsIIDQgnPropPocChannelGroup2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocChannelGroup2 };

static const TAknsItemID KAknsIIDQgnPropPocGroupDetails =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocGroupDetails };

static const TAknsItemID KAknsIIDQgnPropPocGroupMembers =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocGroupMembers };

static const TAknsItemID KAknsIIDQgnPropPocNetworkGroup1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocNetworkGroup1 };

static const TAknsItemID KAknsIIDQgnPropPocNetworkGroup2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocNetworkGroup2 };

static const TAknsItemID KAknsIIDQgnStatCaseDevanagari =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseDevanagari };

static const TAknsItemID KAknsIIDQgnStatCaseDevanagariNumeric =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseDevanagariNumeric };

static const TAknsItemID KAknsIIDQgnStatIndiMtvOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatIndiMtvOn };

static const TAknsItemID KAknsIIDQgnStatPocNewRequest =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatPocNewRequest };

static const TAknsItemID KAknsIIDQgnStatPocNewRequestUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatPocNewRequestUni };

static const TAknsItemID KAknsIIDQgnAreaMainMup2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnAreaMainMup2 };

static const TAknsItemID KAknsIIDQgnGrafImBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafImBg };

static const TAknsItemID KAknsIIDQgnGrafMup2BarFrame =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMup2BarFrame };

static const TAknsItemID KAknsIIDQgnGrafMup2BarProgress =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMup2BarProgress };

static const TAknsItemID KAknsIIDQgnGrafMup2VisualizerImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMup2VisualizerImage };

static const TAknsItemID KAknsIIDQgnIndiAiMupButtonNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiMupButtonNext };

static const TAknsItemID KAknsIIDQgnIndiAiMupButtonPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiMupButtonPause };

static const TAknsItemID KAknsIIDQgnIndiAiMupButtonPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiMupButtonPlay };

static const TAknsItemID KAknsIIDQgnIndiAiMupButtonPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiMupButtonPrev };

static const TAknsItemID KAknsIIDQgnIndiAiMupButtonStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiMupButtonStop };

static const TAknsItemID KAknsIIDQgnIndiAiRadioButtonNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiRadioButtonNext };

static const TAknsItemID KAknsIIDQgnIndiAiRadioButtonOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiRadioButtonOff };

static const TAknsItemID KAknsIIDQgnIndiAiRadioButtonOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiRadioButtonOn };

static const TAknsItemID KAknsIIDQgnIndiAiRadioButtonPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiRadioButtonPrev };

static const TAknsItemID KAknsIIDQgnIndiCamsPhoto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsPhoto };

static const TAknsItemID KAknsIIDQgnIndiCamsVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsVideo };

static const TAknsItemID KAknsIIDQgnIndiFileCorrupted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFileCorrupted };

static const TAknsItemID KAknsIIDQgnIndiMceTb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMceTb };

static const TAknsItemID KAknsIIDQgnIndiMceTbAudio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMceTbAudio };

static const TAknsItemID KAknsIIDQgnIndiMceTbImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMceTbImage };

static const TAknsItemID KAknsIIDQgnIndiMceTbOther =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMceTbOther };

static const TAknsItemID KAknsIIDQgnIndiMceTbPres =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMceTbPres };

static const TAknsItemID KAknsIIDQgnIndiMceTbText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMceTbText };

static const TAknsItemID KAknsIIDQgnIndiMceTbVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMceTbVideo };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonPause };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonPauseDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonPauseDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonPausePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonPausePressed };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonPlay };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonPlayDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonPlayDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonPlayPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonPlayPressed };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonPrev };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonPrevDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonPrevDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonPrevPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonPrevPressed };

static const TAknsItemID KAknsIIDQgnIndiMupButtonMinus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonMinus };

static const TAknsItemID KAknsIIDQgnIndiMupButtonMinusDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonMinusDimmed };

static const TAknsItemID KAknsIIDQgnIndiMupButtonMinusPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonMinusPressed };

static const TAknsItemID KAknsIIDQgnIndiMupButtonNextPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonNextPressed };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPlus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPlus };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPlusDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPlusDimmed };

static const TAknsItemID KAknsIIDQgnIndiMupButtonPlusPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupButtonPlusPressed };

static const TAknsItemID KAknsIIDQgnIndiRepeatExceptionAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRepeatExceptionAdd };

static const TAknsItemID KAknsIIDQgnIndiWmlRss =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWmlRss };

static const TAknsItemID KAknsIIDQgnMenuAmMidlet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuAmMidlet };

static const TAknsItemID KAknsIIDQgnMenuAmSis =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuAmSis };

static const TAknsItemID KAknsIIDQgnPropMceAudioTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceAudioTitle };

static const TAknsItemID KAknsIIDQgnPropMceEmailTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceEmailTitle };

static const TAknsItemID KAknsIIDQgnPropMceMmsTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMmsTitle };

static const TAknsItemID KAknsIIDQgnPropMcePostcardTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMcePostcardTitle };

static const TAknsItemID KAknsIIDQgnPropMceSmsTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSmsTitle };

static const TAknsItemID KAknsIIDQgnPropPslnAiSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPslnAiSub };

static const TAknsItemID KAknsIIDQgnPropPslnAiTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPslnAiTab4 };

static const TAknsItemID KAknsIIDQgnPropPslnAppsgridSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPslnAppsgridSub };

static const TAknsItemID KAknsIIDQgnPropPslnAppsgridTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPslnAppsgridTab4 };

static const TAknsItemID KAknsIIDQgnPropPslnGeneralSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPslnGeneralSub };

static const TAknsItemID KAknsIIDQgnPropPslnGeneralTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPslnGeneralTab4 };

static const TAknsItemID KAknsIIDQgnPropPslnSsaverSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPslnSsaverSub };

static const TAknsItemID KAknsIIDQgnPropPslnSsaverTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPslnSsaverTab4 };

static const TAknsItemID KAknsIIDQgnPropPslnWpaperSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPslnWpaperSub };

static const TAknsItemID KAknsIIDQgnPropPslnWpaperTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPslnWpaperTab4 };

static const TAknsItemID KAknsIIDQgnPropSetAppsAm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsAm };

static const TAknsItemID KAknsIIDQgnPropSetAppsBt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsBt };

static const TAknsItemID KAknsIIDQgnPropSetAppsCale =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsCale };

static const TAknsItemID KAknsIIDQgnPropSetAppsCams =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsCams };

static const TAknsItemID KAknsIIDQgnPropSetAppsIm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsIm };

static const TAknsItemID KAknsIIDQgnPropSetAppsLoc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsLoc };

static const TAknsItemID KAknsIIDQgnPropSetAppsLog =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsLog };

static const TAknsItemID KAknsIIDQgnPropSetAppsMce =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsMce };

static const TAknsItemID KAknsIIDQgnPropSetAppsPhob =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsPhob };

static const TAknsItemID KAknsIIDQgnPropSetAppsPoc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsPoc };

static const TAknsItemID KAknsIIDQgnPropSetAppsRp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsRp };

static const TAknsItemID KAknsIIDQgnPropSetAppsSis =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsSis };

static const TAknsItemID KAknsIIDQgnPropSetAppsSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsSub };

static const TAknsItemID KAknsIIDQgnPropSetAppsTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsTab4 };

static const TAknsItemID KAknsIIDQgnPropSetAppsUsb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsUsb };

static const TAknsItemID KAknsIIDQgnPropSetAppsVoirec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsVoirec };

static const TAknsItemID KAknsIIDQgnPropSetAppsWml =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsWml };

static const TAknsItemID KAknsIIDQgnPropSetConnAccp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnAccp };

static const TAknsItemID KAknsIIDQgnPropSetConnConfig =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnConfig };

static const TAknsItemID KAknsIIDQgnPropSetConnData =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnData };

static const TAknsItemID KAknsIIDQgnPropSetConnDm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDm };

static const TAknsItemID KAknsIIDQgnPropSetConnGprs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnGprs };

static const TAknsItemID KAknsIIDQgnPropSetConnSip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnSip };

static const TAknsItemID KAknsIIDQgnPropSetConnSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnSub };

static const TAknsItemID KAknsIIDQgnPropSetConnTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnTab4 };

static const TAknsItemID KAknsIIDQgnPropSetConnVoip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnVoip };

static const TAknsItemID KAknsIIDQgnPropSetConnVpn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnVpn };

static const TAknsItemID KAknsIIDQgnPropSetConnWlan =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnWlan };

static const TAknsItemID KAknsIIDQgnPropSetGeneLoc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetGeneLoc };

static const TAknsItemID KAknsIIDQgnPropSetGenePhone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetGenePhone };

static const TAknsItemID KAknsIIDQgnPropSetGenePsln =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetGenePsln };

static const TAknsItemID KAknsIIDQgnPropSetGeneTv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetGeneTv };

static const TAknsItemID KAknsIIDQgnStatCaseArabicNumericSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseArabicNumericSelect };

static const TAknsItemID KAknsIIDQgnStatCaseArabicSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseArabicSelect };

static const TAknsItemID KAknsIIDQgnStatCaseCapitalFullSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseCapitalFullSelect };

static const TAknsItemID KAknsIIDQgnStatCaseCapitalSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseCapitalSelect };

static const TAknsItemID KAknsIIDQgnStatCaseHebrewSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseHebrewSelect };

static const TAknsItemID KAknsIIDQgnStatCaseNumericFullSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseNumericFullSelect };

static const TAknsItemID KAknsIIDQgnStatCaseNumericSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseNumericSelect };

static const TAknsItemID KAknsIIDQgnStatCaseSmallFullSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseSmallFullSelect };

static const TAknsItemID KAknsIIDQgnStatCaseSmallSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseSmallSelect };

static const TAknsItemID KAknsIIDQgnStatCaseTextFullSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseTextFullSelect };

static const TAknsItemID KAknsIIDQgnStatCaseTextSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseTextSelect };

static const TAknsItemID KAknsIIDQgnStatCaseThaiSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseThaiSelect };

static const TAknsItemID KAknsIIDQgnStatFarsiCaseSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatFarsiCaseSelect };

static const TAknsItemID KAknsIIDQgnStatImAway =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatImAway };

static const TAknsItemID KAknsIIDQgnStatImAwayUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatImAwayUni };

static const TAknsItemID KAknsIIDQgnStatImInvisible =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatImInvisible };

static const TAknsItemID KAknsIIDQgnStatImInvisibleUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatImInvisibleUni };

static const TAknsItemID KAknsIIDQgnStatImOnline =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatImOnline };

static const TAknsItemID KAknsIIDQgnStatImOnlineUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatImOnlineUni };

static const TAknsItemID KAknsIIDQgnStatIndiMtvRec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatIndiMtvRec };

static const TAknsItemID KAknsIIDQgnStatMceAudio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMceAudio };

static const TAknsItemID KAknsIIDQgnStatMceAudioUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMceAudioUni };

static const TAknsItemID KAknsIIDQgnStatVietCaseCapitalSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVietCaseCapitalSelect };

static const TAknsItemID KAknsIIDQgnStatVietCaseSmallSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVietCaseSmallSelect };

static const TAknsItemID KAknsIIDQgnStatVietCaseTextSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVietCaseTextSelect };

static const TAknsItemID KAknsIIDQgnGrafScrollArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafScrollArrowLeft };

static const TAknsItemID KAknsIIDQgnGrafScrollArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafScrollArrowRight };

static const TAknsItemID KAknsIIDQgnIndiChiFindHwrSimple =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiChiFindHwrSimple };

static const TAknsItemID KAknsIIDQgnIndiChiFindHwrTrad =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiChiFindHwrTrad };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonMinus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonMinus };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonMinusDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonMinusDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonMinusPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonMinusPressed };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonNext };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonNextDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonNextDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonNextPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonNextPressed };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonPlus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonPlus };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonPlusDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonPlusDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup2ButtonPlusPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2ButtonPlusPressed };

static const TAknsItemID KAknsIIDQgnIndiTpDialler =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpDialler };

static const TAknsItemID KAknsIIDQgnIndiTpHelp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpHelp };

static const TAknsItemID KAknsIIDQgnPropFileRssNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileRssNew };

static const TAknsItemID KAknsIIDQgnPropFileRssRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileRssRead };

static const TAknsItemID KAknsIIDQgnPropFileRssUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileRssUnread };

static const TAknsItemID KAknsIIDQgnPropImAwayTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImAwayTitle };

static const TAknsItemID KAknsIIDQgnPropImInvisibleTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImInvisibleTitle };

static const TAknsItemID KAknsIIDQgnPropImOffTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImOffTitle };

static const TAknsItemID KAknsIIDQgnPropImOnTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImOnTitle };

static const TAknsItemID KAknsIIDQgnPropMceMmsDeliveryUnknown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceMmsDeliveryUnknown };

static const TAknsItemID KAknsIIDQgnPropNrtypAssistant =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypAssistant };

static const TAknsItemID KAknsIIDQgnPropNrtypCar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypCar };

static const TAknsItemID KAknsIIDQgnPropNrtypReadOnly =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypReadOnly };

static const TAknsItemID KAknsIIDQgnPropNrtypSip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypSip };

static const TAknsItemID KAknsIIDQgnPropNrtypSwis =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypSwis };

static const TAknsItemID KAknsIIDQgnPropSetAppsRadio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsRadio };

static const TAknsItemID KAknsIIDQgnPropSetGeneSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetGeneSub };

static const TAknsItemID KAknsIIDQgnPropSetGeneTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetGeneTab4 };

static const TAknsItemID KAknsIIDQgnStatChiHwrSimple =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiHwrSimple };

static const TAknsItemID KAknsIIDQgnStatChiHwrTrad =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiHwrTrad };

static const TAknsItemID KAknsIIDQgnGrafBgTouchHorizontal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBgTouchHorizontal };

static const TAknsItemID KAknsIIDQgnGrafBgTouchVertical =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBgTouchVertical };

static const TAknsItemID KAknsIIDQgnGrafMmsAudioInsert =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMmsAudioInsert };

static const TAknsItemID KAknsIIDQgnGrafMup2BarProgress2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMup2BarProgress2 };

static const TAknsItemID KAknsIIDQgnGrafMup2VisualizerBgImage2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMup2VisualizerBgImage2 };

static const TAknsItemID KAknsIIDQgnIndiCamsLocFound =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsLocFound };

static const TAknsItemID KAknsIIDQgnIndiCamsLocNotFound =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsLocNotFound };

static const TAknsItemID KAknsIIDQgnIndiRss2ArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRss2ArrowLeft };

static const TAknsItemID KAknsIIDQgnIndiRss2ArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRss2ArrowRight };

static const TAknsItemID KAknsIIDQgnIndiViewerPointerText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiViewerPointerText };

static const TAknsItemID KAknsIIDQgnPropCamsSetImageTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCamsSetImageTab3 };

static const TAknsItemID KAknsIIDQgnPropCamsSetLocTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCamsSetLocTab3 };

static const TAknsItemID KAknsIIDQgnPropCamsSetVideoTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCamsSetVideoTab3 };

static const TAknsItemID KAknsIIDQgnPropPocGroupTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocGroupTab3 };

static const TAknsItemID KAknsIIDQgnPropPocXdm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocXdm };

static const TAknsItemID KAknsIIDQgnPropPslnCimageSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPslnCimageSub };

static const TAknsItemID KAknsIIDQgnPropSetConnXdm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnXdm };

static const TAknsItemID KAknsIIDQgnStatVideoSharing =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVideoSharing };

static const TAknsItemID KAknsIIDQgnVideoPluginAnimBuffering =
    { EAknsMajorGeneric, EAknsMinorGenericQgnVideoPluginAnimBuffering };

static const TAknsItemID KAknsIIDQgnVideoPluginAnimNoVisual =
    { EAknsMajorGeneric, EAknsMinorGenericQgnVideoPluginAnimNoVisual };

static const TAknsItemID KAknsIIDQgnGrafBubblePocIncall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBubblePocIncall };

static const TAknsItemID KAknsIIDQgnIndiCamsFlashAuto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsFlashAuto };

static const TAknsItemID KAknsIIDQgnIndiMidpChoicegroup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMidpChoicegroup };

static const TAknsItemID KAknsIIDQgnIndiPocUserDnd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPocUserDnd };

static const TAknsItemID KAknsIIDQgnIndiPocUserLoggedIn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPocUserLoggedIn };

static const TAknsItemID KAknsIIDQgnIndiPocUserNotLogged =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPocUserNotLogged };

static const TAknsItemID KAknsIIDQgnIndiPocUserUnknown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPocUserUnknown };

static const TAknsItemID KAknsIIDQgnPropFolderVcMedia =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderVcMedia };

static const TAknsItemID KAknsIIDQgnPropGalleryLocSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropGalleryLocSuper };

static const TAknsItemID KAknsIIDQgnPropImFriendBusy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendBusy };

static const TAknsItemID KAknsIIDQgnPropImFriendOnMobile =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendOnMobile };

static const TAknsItemID KAknsIIDQgnPropImOnMobileTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImOnMobileTitle };

static const TAknsItemID KAknsIIDQgnPropPocInboxCallbackReqRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocInboxCallbackReqRead };

static const TAknsItemID KAknsIIDQgnPropPocInboxCallbackReqUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocInboxCallbackReqUnread };

static const TAknsItemID KAknsIIDQgnPropPocLogInSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocLogInSub };

static const TAknsItemID KAknsIIDQgnPropPocLogMissedSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocLogMissedSub };

static const TAknsItemID KAknsIIDQgnPropPocLogOutSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPocLogOutSub };

static const TAknsItemID KAknsIIDQgnPropSetDefaultSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetDefaultSub };

static const TAknsItemID KAknsIIDQgnPropSetMpStreamTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetMpStreamTab2 };

static const TAknsItemID KAknsIIDQgnPropSetMpVideoTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetMpVideoTab2 };

static const TAknsItemID KAknsIIDQgnPropVcMediaNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVcMediaNext };

static const TAknsItemID KAknsIIDQgnPropVcMediaPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVcMediaPause };

static const TAknsItemID KAknsIIDQgnPropVcMediaPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVcMediaPlay };

static const TAknsItemID KAknsIIDQgnPropVcMediaPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVcMediaPrev };

static const TAknsItemID KAknsIIDQgnPropVcMediaStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVcMediaStop };

static const TAknsItemID KAknsIIDQgnPropVcMediaVolumeDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVcMediaVolumeDown };

static const TAknsItemID KAknsIIDQgnPropVcMediaVolumeUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVcMediaVolumeUp };

static const TAknsItemID KAknsIIDQgnPropWmlFolderAdapSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlFolderAdapSub };

static const TAknsItemID KAknsIIDQgnPropWmlFolderBmSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlFolderBmSub };

static const TAknsItemID KAknsIIDQgnPropWmlFolderNewsSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlFolderNewsSub };

static const TAknsItemID KAknsIIDQgnPropWmlFolderPageSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlFolderPageSub };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIdle };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem02 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem02 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem03 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem03 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem04 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem04 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem05 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem05 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem06 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem06 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem07 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem07 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem08 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem08 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem09 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem09 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem10 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem10 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem11 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem11 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem12 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem13 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem13 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem14 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem14 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem15 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem15 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem16 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem16 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem17 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem17 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem18 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem18 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncrem19 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncrem19 };

static const TAknsItemID KAknsIIDQgnGrafBarWaitIncremIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitIncremIdle };

static const TAknsItemID KAknsIIDQgnGrafFepBgColour =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepBgColour };

static const TAknsItemID KAknsIIDQgnGrafFepCandiListClose =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCandiListClose };

static const TAknsItemID KAknsIIDQgnGrafFepCandiListCloseSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCandiListCloseSel };

static const TAknsItemID KAknsIIDQgnGrafFepCandiListPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCandiListPressed };

static const TAknsItemID KAknsIIDQgnGrafFepCandiListPri =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCandiListPri };

static const TAknsItemID KAknsIIDQgnGrafFepCandiListScrollDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCandiListScrollDown };

static const TAknsItemID KAknsIIDQgnGrafFepCandiListScrollDownSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCandiListScrollDownSel };

static const TAknsItemID KAknsIIDQgnGrafFepCandiListScrollUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCandiListScrollUp };

static const TAknsItemID KAknsIIDQgnGrafFepCandiListScrollUpSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCandiListScrollUpSel };

static const TAknsItemID KAknsIIDQgnGrafFepCandiListSec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCandiListSec };

static const TAknsItemID KAknsIIDQgnGrafFepCandiListSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCandiListSel };

static const TAknsItemID KAknsIIDQgnGrafFepChar11x1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar11x1 };

static const TAknsItemID KAknsIIDQgnGrafFepChar11x1ButtonDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar11x1ButtonDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepChar11x1Stroke =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar11x1Stroke };

static const TAknsItemID KAknsIIDQgnGrafFepChar11x3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar11x3 };

static const TAknsItemID KAknsIIDQgnGrafFepChar11x3ButtonDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar11x3ButtonDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepChar11x3Pinyin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar11x3Pinyin };

static const TAknsItemID KAknsIIDQgnGrafFepChar11x4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar11x4 };

static const TAknsItemID KAknsIIDQgnGrafFepChar11x4ButtonDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar11x4ButtonDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepChar11x4Zhuyin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar11x4Zhuyin };

static const TAknsItemID KAknsIIDQgnGrafFepChar12x3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar12x3 };

static const TAknsItemID KAknsIIDQgnGrafFepChar12x3ButtonDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar12x3ButtonDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepCharButtonDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharButtonDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepInputBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepInputBg };

static const TAknsItemID KAknsIIDQgnGrafFepNumb11x3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepNumb11x3 };

static const TAknsItemID KAknsIIDQgnGrafFepNumb11x31 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepNumb11x31 };

static const TAknsItemID KAknsIIDQgnGrafFepNumb11x31ButtonDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepNumb11x31ButtonDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepNumb11x32 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepNumb11x32 };

static const TAknsItemID KAknsIIDQgnGrafFepNumb11x32ButtonDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepNumb11x32ButtonDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepNumb12x3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepNumb12x3 };

static const TAknsItemID KAknsIIDQgnGrafFepNumb12x31 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepNumb12x31 };

static const TAknsItemID KAknsIIDQgnGrafFepNumb12x31ButtonDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepNumb12x31ButtonDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepNumb12x32 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepNumb12x32 };

static const TAknsItemID KAknsIIDQgnGrafFepNumb12x32ButtonDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepNumb12x32ButtonDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepPopupShadowB =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepPopupShadowB };

static const TAknsItemID KAknsIIDQgnGrafFepPopupShadowBl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepPopupShadowBl };

static const TAknsItemID KAknsIIDQgnGrafFepPopupShadowBr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepPopupShadowBr };

static const TAknsItemID KAknsIIDQgnGrafFepPopupShadowL =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepPopupShadowL };

static const TAknsItemID KAknsIIDQgnGrafFepPopupShadowR =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepPopupShadowR };

static const TAknsItemID KAknsIIDQgnGrafFepPopupShadowT =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepPopupShadowT };

static const TAknsItemID KAknsIIDQgnGrafFepPopupShadowTl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepPopupShadowTl };

static const TAknsItemID KAknsIIDQgnGrafFepPopupShadowTr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepPopupShadowTr };

static const TAknsItemID KAknsIIDQgnIndiFepButtonBackspace1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonBackspace1 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonBackspace1Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonBackspace1Sel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonBackspace2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonBackspace2 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonBackspace2Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonBackspace2Sel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCapslock =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCapslock };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCapslockSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCapslockSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseAccented =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseAccented };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseAccentedSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseAccentedSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseCapital =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseCapital };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseCapitalSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseCapitalSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseNumeric =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseNumeric };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseNumericSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseNumericSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseSmall };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseSmallSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseSmallSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseSpecial =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseSpecial };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseSpecialSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseSpecialSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseText };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonChinese =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonChinese };

static const TAknsItemID KAknsIIDQgnIndiFepButtonChineseSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonChineseSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonClose =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonClose };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCloseSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCloseSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonEnter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonEnter };

static const TAknsItemID KAknsIIDQgnIndiFepButtonEnterSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonEnterSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonExpand =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonExpand };

static const TAknsItemID KAknsIIDQgnIndiFepButtonExpandSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonExpandSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonHwr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonHwr };

static const TAknsItemID KAknsIIDQgnIndiFepButtonHwrSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonHwrSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonMove1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonMove1 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonMove1Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonMove1Sel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonMove2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonMove2 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonMove2Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonMove2Sel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonOptions =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonOptions };

static const TAknsItemID KAknsIIDQgnIndiFepButtonOptionsSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonOptionsSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonShift =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonShift };

static const TAknsItemID KAknsIIDQgnIndiFepButtonShiftSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonShiftSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSpace1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSpace1 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSpace1Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSpace1Sel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSpace2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSpace2 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSpace2Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSpace2Sel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSpace3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSpace3 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSpace3Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSpace3Sel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSwitch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSwitch };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSwitchSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSwitchSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonTab =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonTab };

static const TAknsItemID KAknsIIDQgnIndiFepButtonTabSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonTabSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonVkb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonVkb };

static const TAknsItemID KAknsIIDQgnIndiFepButtonVkbSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonVkbSel };

static const TAknsItemID KAknsIIDQgnIndiViewerPointerWait =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiViewerPointerWait };

static const TAknsItemID KAknsIIDQgnPropRpTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropRpTitle };

static const TAknsItemID KAknsIIDQgnPropTalkingDictionary =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropTalkingDictionary };

static const TAknsItemID KAknsIIDQgnStatSync =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatSync };

static const TAknsItemID KAknsIIDQgnStatSyncUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatSyncUni };

static const TAknsItemID KAknsIIDQsnCpScrollHorizontalBgBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHorizontalBgBottom };

static const TAknsItemID KAknsIIDQsnCpScrollHorizontalBgMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHorizontalBgMiddle };

static const TAknsItemID KAknsIIDQsnCpScrollHorizontalBgTop =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHorizontalBgTop };

static const TAknsItemID KAknsIIDQsnCpScrollHorizontalHandleBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHorizontalHandleBottom };

static const TAknsItemID KAknsIIDQsnCpScrollHorizontalHandleMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHorizontalHandleMiddle };

static const TAknsItemID KAknsIIDQsnCpScrollHorizontalHandleTop =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHorizontalHandleTop };

static const TAknsItemID KAknsIIDQgnGrafDevaQuickEight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafDevaQuickEight };

static const TAknsItemID KAknsIIDQgnGrafDevaQuickFive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafDevaQuickFive };

static const TAknsItemID KAknsIIDQgnGrafDevaQuickFour =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafDevaQuickFour };

static const TAknsItemID KAknsIIDQgnGrafDevaQuickNine =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafDevaQuickNine };

static const TAknsItemID KAknsIIDQgnGrafDevaQuickOne =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafDevaQuickOne };

static const TAknsItemID KAknsIIDQgnGrafDevaQuickSeven =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafDevaQuickSeven };

static const TAknsItemID KAknsIIDQgnGrafDevaQuickSix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafDevaQuickSix };

static const TAknsItemID KAknsIIDQgnGrafDevaQuickThree =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafDevaQuickThree };

static const TAknsItemID KAknsIIDQgnGrafDevaQuickTwo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafDevaQuickTwo };

static const TAknsItemID KAknsIIDQgnGrafFepCharButtonPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharButtonPressed };

static const TAknsItemID KAknsIIDQgnIndiAppOpenAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAppOpenAdd };

static const TAknsItemID KAknsIIDQgnIndiBlidSatFirmaActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBlidSatFirmaActive };

static const TAknsItemID KAknsIIDQgnIndiBlidSatFirmaCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBlidSatFirmaCenter };

static const TAknsItemID KAknsIIDQgnIndiBlidSatFirmaInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBlidSatFirmaInact };

static const TAknsItemID KAknsIIDQgnIndiBlidSatFirmaMoon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBlidSatFirmaMoon };

static const TAknsItemID KAknsIIDQgnIndiBlidSatFirmaSun =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBlidSatFirmaSun };

static const TAknsItemID KAknsIIDQgnIndiFepButtonHwrDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonHwrDimmed };

static const TAknsItemID KAknsIIDQgnIndiFepButtonVkbDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonVkbDimmed };

static const TAknsItemID KAknsIIDQgnPropBlidActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidActive };

static const TAknsItemID KAknsIIDQgnPropBlidBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidBg };

static const TAknsItemID KAknsIIDQgnPropBlidInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidInactive };

static const TAknsItemID KAknsIIDQgnPropCheckboxInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCheckboxInactive };

static const TAknsItemID KAknsIIDQgnPropFmgrRemoteDriveTab =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrRemoteDriveTab };

static const TAknsItemID KAknsIIDQgnPropMskMenu =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMskMenu };

static const TAknsItemID KAknsIIDQgnPropMskSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMskSelect };

static const TAknsItemID KAknsIIDQgnPropNoteListAlphaDevaTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNoteListAlphaDevaTab2 };

static const TAknsItemID KAknsIIDQgnPropRadiobuttInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropRadiobuttInactive };

static const TAknsItemID KAknsIIDQgnPropSearchIndevice =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSearchIndevice };

static const TAknsItemID KAknsIIDQgnPropSearchIndeviceTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSearchIndeviceTitle };

static const TAknsItemID KAknsIIDQgnPropSetConnBearerAvailPacketdata =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnBearerAvailPacketdata };

static const TAknsItemID KAknsIIDQgnPropSetConnBearerAvailWlan =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnBearerAvailWlan };

static const TAknsItemID KAknsIIDQgnPropSetConnDestAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestAdd };

static const TAknsItemID KAknsIIDQgnPropSetConnDestDefault =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestDefault };

static const TAknsItemID KAknsIIDQgnPropSetConnDestDefaultSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestDefaultSmall };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIcon1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIcon1 };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIcon1Small =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIcon1Small };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIcon2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIcon2 };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIcon2Small =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIcon2Small };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIcon3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIcon3 };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIcon3Small =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIcon3Small };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIcon4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIcon4 };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIcon4Small =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIcon4Small };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIcon5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIcon5 };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIcon5Small =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIcon5Small };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIcon6 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIcon6 };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIcon6Small =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIcon6Small };

static const TAknsItemID KAknsIIDQgnPropSetConnDestInternet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestInternet };

static const TAknsItemID KAknsIIDQgnPropSetConnDestInternetSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestInternetSmall };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIntranet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIntranet };

static const TAknsItemID KAknsIIDQgnPropSetConnDestIntranetSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestIntranetSmall };

static const TAknsItemID KAknsIIDQgnPropSetConnDestMms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestMms };

static const TAknsItemID KAknsIIDQgnPropSetConnDestMmsSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestMmsSmall };

static const TAknsItemID KAknsIIDQgnPropSetConnDestOperator =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestOperator };

static const TAknsItemID KAknsIIDQgnPropSetConnDestOperatorSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestOperatorSmall };

static const TAknsItemID KAknsIIDQgnPropSetConnDestUncategorized =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestUncategorized };

static const TAknsItemID KAknsIIDQgnPropSetConnDestWap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestWap };

static const TAknsItemID KAknsIIDQgnPropSetConnDestWapSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnDestWapSmall };

static const TAknsItemID KAknsIIDQgnPropSetConnPresence =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnPresence };

static const TAknsItemID KAknsIIDQgnPropSetConnRemotedrive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnRemotedrive };

static const TAknsItemID KAknsIIDQgnPropSetConnWlanEasy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnWlanEasy };

static const TAknsItemID KAknsIIDQgnPropSetPhoneSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetPhoneSub };

static const TAknsItemID KAknsIIDQgnPropSipLocked =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSipLocked };

static const TAknsItemID KAknsIIDQgnStatHac =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatHac };

static const TAknsItemID KAknsIIDQgnStatT9Auto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatT9Auto };

static const TAknsItemID KAknsIIDQgnGrafPopupTransCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPopupTransCenter };

static const TAknsItemID KAknsIIDQgnGrafPopupTransCornerBl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPopupTransCornerBl };

static const TAknsItemID KAknsIIDQgnGrafPopupTransCornerBr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPopupTransCornerBr };

static const TAknsItemID KAknsIIDQgnGrafPopupTransCornerTl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPopupTransCornerTl };

static const TAknsItemID KAknsIIDQgnGrafPopupTransCornerTr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPopupTransCornerTr };

static const TAknsItemID KAknsIIDQgnGrafPopupTransSideB =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPopupTransSideB };

static const TAknsItemID KAknsIIDQgnGrafPopupTransSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPopupTransSideL };

static const TAknsItemID KAknsIIDQgnGrafPopupTransSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPopupTransSideR };

static const TAknsItemID KAknsIIDQgnGrafPopupTransSideT =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPopupTransSideT };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbBack =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbBack };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbForward =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbForward };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbForwardInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbForwardInact };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbGo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbGo };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbHome =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbHome };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbReload =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbReload };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbStop };

static const TAknsItemID KAknsIIDQgnIndiButtonDecrease =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonDecrease };

static const TAknsItemID KAknsIIDQgnIndiButtonDecreasePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonDecreasePressed };

static const TAknsItemID KAknsIIDQgnIndiButtonIncrease =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonIncrease };

static const TAknsItemID KAknsIIDQgnIndiButtonIncreasePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonIncreasePressed };

static const TAknsItemID KAknsIIDQgnIndiDropdownArrow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDropdownArrow };

static const TAknsItemID KAknsIIDQgnIndiHlColSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHlColSuper };

static const TAknsItemID KAknsIIDQgnIndiHlExpSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHlExpSuper };

static const TAknsItemID KAknsIIDQgnIndiHlLineBranch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHlLineBranch };

static const TAknsItemID KAknsIIDQgnIndiHlLineEnd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHlLineEnd };

static const TAknsItemID KAknsIIDQgnIndiHlLineStraight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHlLineStraight };

static const TAknsItemID KAknsIIDQgnIndiMceConnAlwaysAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMceConnAlwaysAdd };

static const TAknsItemID KAknsIIDQgnIndiMceConnOnAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMceConnOnAdd };

static const TAknsItemID KAknsIIDQgnIndiMceConnOnRoamAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMceConnOnRoamAdd };

static const TAknsItemID KAknsIIDQgnIndiMup2EqBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2EqBg };

static const TAknsItemID KAknsIIDQgnIndiMup2VolumeSlider =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2VolumeSlider };

static const TAknsItemID KAknsIIDQgnIndiMup2VolumeSliderBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2VolumeSliderBg };

static const TAknsItemID KAknsIIDQgnPropBlidSatFirma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidSatFirma };

static const TAknsItemID KAknsIIDQgnPropBlidSatFirmaActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidSatFirmaActive };

static const TAknsItemID KAknsIIDQgnPropBlidSatFirmaInact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidSatFirmaInact };

static const TAknsItemID KAknsIIDQgnPropBlidSatFirmaMoon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidSatFirmaMoon };

static const TAknsItemID KAknsIIDQgnPropBlidSatFirmaSun =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBlidSatFirmaSun };

static const TAknsItemID KAknsIIDQgnPropHlFile =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHlFile };

static const TAknsItemID KAknsIIDQgnPropHlFolder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHlFolder };

static const TAknsItemID KAknsIIDQgnPropHlFolderOpen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHlFolderOpen };

static const TAknsItemID KAknsIIDQgnPropImageTbClose =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbClose };

static const TAknsItemID KAknsIIDQgnPropImageTbCloseDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbCloseDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbCloseFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbCloseFocused };

static const TAknsItemID KAknsIIDQgnPropImageTbClosePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbClosePressed };

static const TAknsItemID KAknsIIDQgnPropImageTbDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbDelete };

static const TAknsItemID KAknsIIDQgnPropImageTbDeleteDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbDeleteDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbDeleteFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbDeleteFocused };

static const TAknsItemID KAknsIIDQgnPropImageTbDeletePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbDeletePressed };

static const TAknsItemID KAknsIIDQgnPropImageTbInfo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbInfo };

static const TAknsItemID KAknsIIDQgnPropImageTbInfoDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbInfoDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbInfoFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbInfoFocused };

static const TAknsItemID KAknsIIDQgnPropImageTbInfoPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbInfoPressed };

static const TAknsItemID KAknsIIDQgnPropImageTbPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPlay };

static const TAknsItemID KAknsIIDQgnPropImageTbPlayDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPlayDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbPlayFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPlayFocused };

static const TAknsItemID KAknsIIDQgnPropImageTbPlayPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPlayPressed };

static const TAknsItemID KAknsIIDQgnPropImageTbRotateL =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbRotateL };

static const TAknsItemID KAknsIIDQgnPropImageTbRotateLDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbRotateLDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbRotateLFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbRotateLFocused };

static const TAknsItemID KAknsIIDQgnPropImageTbRotateLPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbRotateLPressed };

static const TAknsItemID KAknsIIDQgnPropImageTbRotateR =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbRotateR };

static const TAknsItemID KAknsIIDQgnPropImageTbRotateRDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbRotateRDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbRotateRFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbRotateRFocused };

static const TAknsItemID KAknsIIDQgnPropImageTbRotateRPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbRotateRPressed };

static const TAknsItemID KAknsIIDQgnPropImageTbZoom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbZoom };

static const TAknsItemID KAknsIIDQgnPropImageTbZoomDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbZoomDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbZoomFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbZoomFocused };

static const TAknsItemID KAknsIIDQgnPropImageTbZoomPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbZoomPressed };

static const TAknsItemID KAknsIIDQgnPropImImsgNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImImsgNew };

static const TAknsItemID KAknsIIDQgnPropRemoteDriveMemc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropRemoteDriveMemc };

static const TAknsItemID KAknsIIDQgnPropRemoteDriveMemcLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropRemoteDriveMemcLarge };

static const TAknsItemID KAknsIIDQgnStatMemc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMemc };

static const TAknsItemID KAknsIIDQgnStatMemcUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMemcUni };

static const TAknsItemID KAknsIIDQgnIndiBrowserCursorEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserCursorEmail };

static const TAknsItemID KAknsIIDQgnIndiBrowserCursorPhone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserCursorPhone };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbFind =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbFind };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbPage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbPage };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbRss =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbRss };

static const TAknsItemID KAknsIIDQgnIndiMmsPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMmsPlay };

static const TAknsItemID KAknsIIDQgnPropSetConnAcl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnAcl };

static const TAknsItemID KAknsIIDQgnGrafVideoPluginAnimNoBufferingBroken00 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVideoPluginAnimNoBufferingBroken00 };

static const TAknsItemID KAknsIIDQgnGrafVideoPluginAnimNoBufferingBroken01 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVideoPluginAnimNoBufferingBroken01 };

static const TAknsItemID KAknsIIDQgnGrafVideoPluginAnimNoBufferingBroken02 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVideoPluginAnimNoBufferingBroken02 };

static const TAknsItemID KAknsIIDQgnGrafVideoPluginAnimNoBufferingBroken03 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVideoPluginAnimNoBufferingBroken03 };

static const TAknsItemID KAknsIIDQgnGrafVideoPluginAnimNoBufferingBroken04 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVideoPluginAnimNoBufferingBroken04 };

static const TAknsItemID KAknsIIDQgnGrafVideoPluginAnimNoBufferingBroken05 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVideoPluginAnimNoBufferingBroken05 };

static const TAknsItemID KAknsIIDQgnGrafVideoPluginAnimNoBufferingBroken06 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVideoPluginAnimNoBufferingBroken06 };

static const TAknsItemID KAknsIIDQgnGrafVideoPluginAnimNoBufferingBroken07 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVideoPluginAnimNoBufferingBroken07 };

static const TAknsItemID KAknsIIDQgnGrafVideoPluginAnimNoBufferingBroken08 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVideoPluginAnimNoBufferingBroken08 };

static const TAknsItemID KAknsIIDQgnGrafVideoPluginAnimNoBufferingBroken09 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVideoPluginAnimNoBufferingBroken09 };

static const TAknsItemID KAknsIIDQgnGrafVideoPluginAnimNoBufferingBroken10 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVideoPluginAnimNoBufferingBroken10 };

static const TAknsItemID KAknsIIDQgnGrafVideoPluginAnimNoBufferingBroken11 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVideoPluginAnimNoBufferingBroken11 };

static const TAknsItemID KAknsIIDQgnIndiLogMissedCallAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiLogMissedCallAdd };

static const TAknsItemID KAknsIIDQgnPropFileRssAuto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileRssAuto };

static const TAknsItemID KAknsIIDQgnPropFolderInstall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderInstall };

static const TAknsItemID KAknsIIDQgnPropFolderNotInstall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderNotInstall };

static const TAknsItemID KAknsIIDQgnPropImBusyTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImBusyTitle };

static const TAknsItemID KAknsIIDQgnPropSearchContacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSearchContacts };

static const TAknsItemID KAknsIIDQgnPropSearchFileNames =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSearchFileNames };

static const TAknsItemID KAknsIIDQgnPropSearchMailbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSearchMailbox };

static const TAknsItemID KAknsIIDQgnPropSearchOfficeDocs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSearchOfficeDocs };

static const TAknsItemID KAknsIIDQgnStatChiPinyinPhrase =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiPinyinPhrase };

static const TAknsItemID KAknsIIDQgnStatChiStrokePhrase =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiStrokePhrase };

static const TAknsItemID KAknsIIDQgnStatChiStrokeTradPhrase =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiStrokeTradPhrase };

static const TAknsItemID KAknsIIDQgnStatChiZhuyinPhrase =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatChiZhuyinPhrase };

static const TAknsItemID KAknsIIDQgnMenuNews =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuNews };

static const TAknsItemID KAknsIIDQgnMenuShortcut =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuShortcut };

static const TAknsItemID KAknsIIDQgnGrafVolumeSetOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSetOff };

static const TAknsItemID KAknsIIDQgnGrafVolumeSetOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSetOn };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmallOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmallOff };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmallOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmallOn };

static const TAknsItemID KAknsIIDQgnIndiCalcAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcAdd };

static const TAknsItemID KAknsIIDQgnIndiCalcCancel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcCancel };

static const TAknsItemID KAknsIIDQgnIndiCalcDivide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcDivide };

static const TAknsItemID KAknsIIDQgnIndiCalcEight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcEight };

static const TAknsItemID KAknsIIDQgnIndiCalcEquals =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcEquals };

static const TAknsItemID KAknsIIDQgnIndiCalcFive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcFive };

static const TAknsItemID KAknsIIDQgnIndiCalcFour =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcFour };

static const TAknsItemID KAknsIIDQgnIndiCalcMultiply =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcMultiply };

static const TAknsItemID KAknsIIDQgnIndiCalcNine =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcNine };

static const TAknsItemID KAknsIIDQgnIndiCalcOne =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcOne };

static const TAknsItemID KAknsIIDQgnIndiCalcPercent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcPercent };

static const TAknsItemID KAknsIIDQgnIndiCalcSeparator =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcSeparator };

static const TAknsItemID KAknsIIDQgnIndiCalcSeven =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcSeven };

static const TAknsItemID KAknsIIDQgnIndiCalcSign =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcSign };

static const TAknsItemID KAknsIIDQgnIndiCalcSix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcSix };

static const TAknsItemID KAknsIIDQgnIndiCalcSquareroot =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcSquareroot };

static const TAknsItemID KAknsIIDQgnIndiCalcSubtract =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcSubtract };

static const TAknsItemID KAknsIIDQgnIndiCalcThree =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcThree };

static const TAknsItemID KAknsIIDQgnIndiCalcTwo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcTwo };

static const TAknsItemID KAknsIIDQgnIndiCalcZero =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcZero };

static const TAknsItemID KAknsIIDQgnIndiCamsFocusAutoFrame =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsFocusAutoFrame };

static const TAknsItemID KAknsIIDQgnIndiCamsTbBurst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbBurst };

static const TAknsItemID KAknsIIDQgnIndiCamsTbCameraMain =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbCameraMain };

static const TAknsItemID KAknsIIDQgnIndiCamsTbCameraSecondary =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbCameraSecondary };

static const TAknsItemID KAknsIIDQgnIndiCamsTbCapture =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbCapture };

static const TAknsItemID KAknsIIDQgnIndiCamsTbClose =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbClose };

static const TAknsItemID KAknsIIDQgnIndiCamsTbFlash =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbFlash };

static const TAknsItemID KAknsIIDQgnIndiCamsTbFocusAuto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbFocusAuto };

static const TAknsItemID KAknsIIDQgnIndiCamsTbMinitb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbMinitb };

static const TAknsItemID KAknsIIDQgnIndiCamsTbNight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbNight };

static const TAknsItemID KAknsIIDQgnIndiCamsTbPhoto  =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbPhoto  };

static const TAknsItemID KAknsIIDQgnIndiCamsTbPhotoQuality =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbPhotoQuality };

static const TAknsItemID KAknsIIDQgnIndiCamsTbPhotoReso =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbPhotoReso };

static const TAknsItemID KAknsIIDQgnIndiCamsTbRec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbRec };

static const TAknsItemID KAknsIIDQgnIndiCamsTbRecPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbRecPause };

static const TAknsItemID KAknsIIDQgnIndiCamsTbRecStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbRecStop };

static const TAknsItemID KAknsIIDQgnIndiCamsTbTone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbTone };

static const TAknsItemID KAknsIIDQgnIndiCamsTbVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbVideo };

static const TAknsItemID KAknsIIDQgnIndiCamsTbVideoLength =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbVideoLength };

static const TAknsItemID KAknsIIDQgnIndiCamsTbVideoReso =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbVideoReso };

static const TAknsItemID KAknsIIDQgnIndiCamsTbWhite =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTbWhite };

static const TAknsItemID KAknsIIDQgnIndiMupDefaultAlbum =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupDefaultAlbum };

static const TAknsItemID KAknsIIDQgnIndiMupRp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupRp };

static const TAknsItemID KAknsIIDQgnIndiS60 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiS60 };

static const TAknsItemID KAknsIIDQgnIndiSignalHsdpaAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalHsdpaAttach };

static const TAknsItemID KAknsIIDQgnIndiSignalHsdpaContext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalHsdpaContext };

static const TAknsItemID KAknsIIDQgnIndiSignalHsdpaMultipdp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalHsdpaMultipdp };

static const TAknsItemID KAknsIIDQgnIndiSignalHsdpaSuspended =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalHsdpaSuspended };

static const TAknsItemID KAknsIIDQgnMenuImBusy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuImBusy };

static const TAknsItemID KAknsIIDQgnPropMpPlayPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMpPlayPause };

static const TAknsItemID KAknsIIDQgnPropMpViewNormal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMpViewNormal };

static const TAknsItemID KAknsIIDQgnPropS60 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropS60 };

static const TAknsItemID KAknsIIDQgnPropSetGenePay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetGenePay };

static const TAknsItemID KAknsIIDQgnPropUsb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropUsb };

static const TAknsItemID KAknsIIDQgnStatAlarmUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatAlarmUni };

static const TAknsItemID KAknsIIDQgnStatCarkitUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCarkitUni };

static const TAknsItemID KAknsIIDQgnStatDivert0Uni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDivert0Uni };

static const TAknsItemID KAknsIIDQgnStatDivert12Uni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDivert12Uni };

static const TAknsItemID KAknsIIDQgnStatDivert1Uni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDivert1Uni };

static const TAknsItemID KAknsIIDQgnStatDivert2Uni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDivert2Uni };

static const TAknsItemID KAknsIIDQgnStatDivertVmUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDivertVmUni };

static const TAknsItemID KAknsIIDQgnStatHacUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatHacUni };

static const TAknsItemID KAknsIIDQgnStatHeadsetUnavailableUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatHeadsetUnavailableUni };

static const TAknsItemID KAknsIIDQgnStatHeadsetUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatHeadsetUni };

static const TAknsItemID KAknsIIDQgnStatIndiMtvOnUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatIndiMtvOnUni };

static const TAknsItemID KAknsIIDQgnStatIndiMtvRecUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatIndiMtvRecUni };

static const TAknsItemID KAknsIIDQgnStatKeyguardUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatKeyguardUni };

static const TAknsItemID KAknsIIDQgnStatLine2Uni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatLine2Uni };

static const TAknsItemID KAknsIIDQgnStatLocUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatLocUni };

static const TAknsItemID KAknsIIDQgnStatLoopsetUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatLoopsetUni };

static const TAknsItemID KAknsIIDQgnStatModBtUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatModBtUni };

static const TAknsItemID KAknsIIDQgnStatModTarmUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatModTarmUni };

static const TAknsItemID KAknsIIDQgnStatPocDndUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatPocDndUni };

static const TAknsItemID KAknsIIDQgnStatTarmUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatTarmUni };

static const TAknsItemID KAknsIIDQgnStatTtyUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatTtyUni };

static const TAknsItemID KAknsIIDQgnStatTvoutUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatTvoutUni };

static const TAknsItemID KAknsIIDQgnStatVideoSharingUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVideoSharingUni };

static const TAknsItemID KAknsIIDQgnStatVoipReadinessUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVoipReadinessUni };

static const TAknsItemID KAknsIIDQgnStatZoneHomeUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatZoneHomeUni };

static const TAknsItemID KAknsIIDQgnIndiCaleTbDay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbDay };

static const TAknsItemID KAknsIIDQgnIndiCaleTbLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbLeft };

static const TAknsItemID KAknsIIDQgnIndiCaleTbMonth =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbMonth };

static const TAknsItemID KAknsIIDQgnIndiCaleTbNewEntry =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbNewEntry };

static const TAknsItemID KAknsIIDQgnIndiCaleTbRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbRight };

static const TAknsItemID KAknsIIDQgnIndiCaleTbTodo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbTodo };

static const TAknsItemID KAknsIIDQgnIndiCaleTbWeek =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbWeek };

static const TAknsItemID KAknsIIDQgnIndiTbAvailContacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbAvailContacts };

static const TAknsItemID KAknsIIDQgnIndiTbCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCall };

static const TAknsItemID KAknsIIDQgnIndiTbCallVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCallVideo };

static const TAknsItemID KAknsIIDQgnIndiTbMce =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMce };

static const TAknsItemID KAknsIIDQgnIndiTbPb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbPb };

static const TAknsItemID KAknsIIDQgnIndiVideoForw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoForw };

static const TAknsItemID KAknsIIDQgnIndiVideoPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoPause };

static const TAknsItemID KAknsIIDQgnIndiVideoPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoPlay };

static const TAknsItemID KAknsIIDQgnIndiVideoRecord =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoRecord };

static const TAknsItemID KAknsIIDQgnIndiVideoRecordNot =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoRecordNot };

static const TAknsItemID KAknsIIDQgnIndiVideoRew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoRew };

static const TAknsItemID KAknsIIDQgnIndiVideoStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoStop };

static const TAknsItemID KAknsIIDQgnIndiVideoWait1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoWait1 };

static const TAknsItemID KAknsIIDQgnIndiVideoWait2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoWait2 };

static const TAknsItemID KAknsIIDQgnIndiVideoWait3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoWait3 };

static const TAknsItemID KAknsIIDQgnIndiVideoWait4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoWait4 };

static const TAknsItemID KAknsIIDQgnIndiVideoWait5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoWait5 };

static const TAknsItemID KAknsIIDQgnIndiVideoWait6 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoWait6 };

static const TAknsItemID KAknsIIDQgnIndiVideoWait7 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoWait7 };

static const TAknsItemID KAknsIIDQgnIndiVideoWait8 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoWait8 };

static const TAknsItemID KAknsIIDQgnPropBtBlockedTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtBlockedTab3 };

static const TAknsItemID KAknsIIDQgnPropBtDevicesTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtDevicesTab3 };

static const TAknsItemID KAknsIIDQgnPropBtSetTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtSetTab3 };

static const TAknsItemID KAknsIIDQgnPropCodec3gp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCodec3gp };

static const TAknsItemID KAknsIIDQgnPropCodecAvc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCodecAvc };

static const TAknsItemID KAknsIIDQgnPropCodecH263 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCodecH263 };

static const TAknsItemID KAknsIIDQgnPropCodecMp4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCodecMp4 };

static const TAknsItemID KAknsIIDQgnPropCodecRv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCodecRv };

static const TAknsItemID KAknsIIDQgnPropCodecRv10 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCodecRv10 };

static const TAknsItemID KAknsIIDQgnPropCodecRv8 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCodecRv8 };

static const TAknsItemID KAknsIIDQgnPropCodecRv9 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCodecRv9 };

static const TAknsItemID KAknsIIDQgnPropSmlSync =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlSync };

static const TAknsItemID KAknsIIDQgnPropVideoMb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVideoMb };

static const TAknsItemID KAknsIIDQgnIndiMgTbDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMgTbDelete };

static const TAknsItemID KAknsIIDQgnIndiMgTbEdit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMgTbEdit };

static const TAknsItemID KAknsIIDQgnIndiMgTbSend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMgTbSend };

static const TAknsItemID KAknsIIDQgnIndiMgTbStreamNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMgTbStreamNew };

static const TAknsItemID KAknsIIDQgnIndiMpTbRemoveAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpTbRemoveAll };

static const TAknsItemID KAknsIIDQgnIndiMpTbRemoveOne =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpTbRemoveOne };

static const TAknsItemID KAknsIIDQgnIndiMupTbAddTracks =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbAddTracks };

static const TAknsItemID KAknsIIDQgnIndiMupTbNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbNext };

static const TAknsItemID KAknsIIDQgnIndiMupTbPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbPause };

static const TAknsItemID KAknsIIDQgnIndiMupTbPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbPlay };

static const TAknsItemID KAknsIIDQgnIndiMupTbPlaylistNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbPlaylistNew };

static const TAknsItemID KAknsIIDQgnIndiMupTbPlaylistRemove =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbPlaylistRemove };

static const TAknsItemID KAknsIIDQgnIndiMupTbPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbPrev };

static const TAknsItemID KAknsIIDQgnIndiMupTbStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbStop };

static const TAknsItemID KAknsIIDQgnPropBrowserDlCompletedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBrowserDlCompletedAdd };

static const TAknsItemID KAknsIIDQgnPropBrowserDlOngoingAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBrowserDlOngoingAdd };

static const TAknsItemID KAknsIIDQgnPropBrowserDlPausedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBrowserDlPausedAdd };

static const TAknsItemID KAknsIIDQgnPropFolderVcMessage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderVcMessage };

static const TAknsItemID KAknsIIDQgnPropFolderVcOrganiser =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderVcOrganiser };

static const TAknsItemID KAknsIIDQgnPropFolderVcTools =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderVcTools };

static const TAknsItemID KAknsIIDQgnPropImChatsCollapsed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImChatsCollapsed };

static const TAknsItemID KAknsIIDQgnPropImChatsExpanded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImChatsExpanded };

static const TAknsItemID KAknsIIDQgnPropImFriendsCollapsed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendsCollapsed };

static const TAknsItemID KAknsIIDQgnPropImFriendsExpanded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendsExpanded };

static const TAknsItemID KAknsIIDQgnPropSetAppsMp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsMp };

static const TAknsItemID KAknsIIDQgnStatLocTriggerOffUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatLocTriggerOffUni };

static const TAknsItemID KAknsIIDQgnStatLocTriggerOnUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatLocTriggerOnUni };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSmall1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSmall1 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSmall10 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSmall10 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSmall2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSmall2 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSmall3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSmall3 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSmall4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSmall4 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSmall5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSmall5 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSmall6 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSmall6 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSmall7 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSmall7 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSmall8 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSmall8 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSmall9 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSmall9 };

static const TAknsItemID KAknsIIDQgnGrafScreencalib =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafScreencalib };

static const TAknsItemID KAknsIIDQgnGrafScreencalib1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafScreencalib1 };

static const TAknsItemID KAknsIIDQgnGrafScreencalib2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafScreencalib2 };

static const TAknsItemID KAknsIIDQgnGrafScreencalib3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafScreencalib3 };

static const TAknsItemID KAknsIIDQgnGrafScreencalib4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafScreencalib4 };

static const TAknsItemID KAknsIIDQgnGrafScreencalib5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafScreencalib5 };

static const TAknsItemID KAknsIIDQgnIndiButtonMode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonMode };

static const TAknsItemID KAknsIIDQgnIndiCalcClear =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcClear };

static const TAknsItemID KAknsIIDQgnIndiDialerCallSend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerCallSend };

static const TAknsItemID KAknsIIDQgnIndiDialerClear =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerClear };

static const TAknsItemID KAknsIIDQgnIndiDialerContacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerContacts };

static const TAknsItemID KAknsIIDQgnIndiDialerEight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerEight };

static const TAknsItemID KAknsIIDQgnIndiDialerFive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerFive };

static const TAknsItemID KAknsIIDQgnIndiDialerFour =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerFour };

static const TAknsItemID KAknsIIDQgnIndiDialerHash =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerHash };

static const TAknsItemID KAknsIIDQgnIndiDialerNine =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerNine };

static const TAknsItemID KAknsIIDQgnIndiDialerOne =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerOne };

static const TAknsItemID KAknsIIDQgnIndiDialerPrefix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerPrefix };

static const TAknsItemID KAknsIIDQgnIndiDialerSeven =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerSeven };

static const TAknsItemID KAknsIIDQgnIndiDialerSix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerSix };

static const TAknsItemID KAknsIIDQgnIndiDialerThree =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerThree };

static const TAknsItemID KAknsIIDQgnIndiDialerTwo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerTwo };

static const TAknsItemID KAknsIIDQgnIndiDialerVideocallSend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerVideocallSend };

static const TAknsItemID KAknsIIDQgnIndiDialerZero =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerZero };

static const TAknsItemID KAknsIIDQgnIndiHlTabColSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHlTabColSuper };

static const TAknsItemID KAknsIIDQgnIndiHlTabExpSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHlTabExpSuper };

static const TAknsItemID KAknsIIDQgnIndiMupTbRemoveOne =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbRemoveOne };

static const TAknsItemID KAknsIIDQgnIndiOfflineFileAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiOfflineFileAdd };

static const TAknsItemID KAknsIIDQgnIndiTbCameraMain =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCameraMain };

static const TAknsItemID KAknsIIDQgnIndiTbCameraSecondary =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCameraSecondary };

static const TAknsItemID KAknsIIDQgnIndiTbGallery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbGallery };

static const TAknsItemID KAknsIIDQgnIndiTbMicrophoneMute =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMicrophoneMute };

static const TAknsItemID KAknsIIDQgnIndiTbMicrophoneUnmute =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMicrophoneUnmute };

static const TAknsItemID KAknsIIDQgnIndiTbPlaylistNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbPlaylistNew };

static const TAknsItemID KAknsIIDQgnIndiTbSwapImages =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbSwapImages };

static const TAknsItemID KAknsIIDQgnIndiTbVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbVideo };

static const TAknsItemID KAknsIIDQgnIndiTbVideoDisable =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbVideoDisable };

static const TAknsItemID KAknsIIDQgnIndiTbZoom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbZoom };

static const TAknsItemID KAknsIIDQgnIndiVideoVolMuted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoVolMuted };

static const TAknsItemID KAknsIIDQgnPropMceSubSenderCollapsed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubSenderCollapsed };

static const TAknsItemID KAknsIIDQgnPropMceSubSenderExpanded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubSenderExpanded };

static const TAknsItemID KAknsIIDQgnPropMceSubSizeCollapsed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubSizeCollapsed };

static const TAknsItemID KAknsIIDQgnPropMceSubSizeExpanded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubSizeExpanded };

static const TAknsItemID KAknsIIDQgnPropMceSubSubjectCollapsed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubSubjectCollapsed };

static const TAknsItemID KAknsIIDQgnPropMceSubSubjectExpanded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubSubjectExpanded };

static const TAknsItemID KAknsIIDQgnPropMceSubTimeCollapsed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubTimeCollapsed };

static const TAknsItemID KAknsIIDQgnPropMceSubTimeExpanded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubTimeExpanded };

static const TAknsItemID KAknsIIDQgnPropMceSubTypeCollapsed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubTypeCollapsed };

static const TAknsItemID KAknsIIDQgnPropMceSubTypeExpanded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubTypeExpanded };

static const TAknsItemID KAknsIIDQgnPropMpDownloadVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMpDownloadVideo };

static const TAknsItemID KAknsIIDQgnPropMpFolderRecentPlayed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMpFolderRecentPlayed };

static const TAknsItemID KAknsIIDQgnPropMpFolderStreamLink =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMpFolderStreamLink };

static const TAknsItemID KAknsIIDQgnPropMpFolderVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMpFolderVideo };

static const TAknsItemID KAknsIIDQgnPropSetVideoSharing =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetVideoSharing };

static const TAknsItemID KAknsIIDQgnPropSmlNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSmlNew };

static const TAknsItemID KAknsIIDQgnPropVideoCorrupted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVideoCorrupted };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSet0 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSet0 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSet1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSet1 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSet10 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSet10 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSet2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSet2 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSet3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSet3 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSet4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSet4 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSet5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSet5 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSet6 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSet6 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSet7 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSet7 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSet8 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSet8 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSet9 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSet9 };

static const TAknsItemID KAknsIIDQgnGrafAiVolumeSmall0 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAiVolumeSmall0 };

static const TAknsItemID KAknsIIDQgnIndiColSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiColSuper };

static const TAknsItemID KAknsIIDQgnIndiExpSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiExpSuper };

static const TAknsItemID KAknsIIDQgnIndiSignalEgprsIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalEgprsIcon };

static const TAknsItemID KAknsIIDQgnIndiSignalHsdpaIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalHsdpaIcon };

static const TAknsItemID KAknsIIDQgnIndiVolumeArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVolumeArrowLeft };

static const TAknsItemID KAknsIIDQgnIndiVolumeArrowLeftInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVolumeArrowLeftInactive };

static const TAknsItemID KAknsIIDQgnIndiVolumeArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVolumeArrowRight };

static const TAknsItemID KAknsIIDQgnIndiVolumeArrowRightInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVolumeArrowRightInactive };

static const TAknsItemID KAknsIIDQgnMenuImageprint =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuImageprint };

static const TAknsItemID KAknsIIDQgnPropMceSubSender =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubSender };

static const TAknsItemID KAknsIIDQgnPropMceSubSize =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubSize };

static const TAknsItemID KAknsIIDQgnPropMceSubSubject =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubSubject };

static const TAknsItemID KAknsIIDQgnPropMceSubTime =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubTime };

static const TAknsItemID KAknsIIDQgnPropMceSubType =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubType };

static const TAknsItemID KAknsIIDQsnFrSeparatorHLShdwin =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorHLShdwin };

static const TAknsItemID KAknsIIDQsnFrSeparatorHLShdwnone =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorHLShdwnone };

static const TAknsItemID KAknsIIDQsnFrSeparatorHLShdwout =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorHLShdwout };

static const TAknsItemID KAknsIIDQsnFrSeparatorHMShdwin =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorHMShdwin };

static const TAknsItemID KAknsIIDQsnFrSeparatorHMShdwnone =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorHMShdwnone };

static const TAknsItemID KAknsIIDQsnFrSeparatorHMShdwout =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorHMShdwout };

static const TAknsItemID KAknsIIDQsnFrSeparatorHRShdwin =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorHRShdwin };

static const TAknsItemID KAknsIIDQsnFrSeparatorHRShdwnone =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorHRShdwnone };

static const TAknsItemID KAknsIIDQsnFrSeparatorHRShdwout =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorHRShdwout };

static const TAknsItemID KAknsIIDQsnFrSeparatorVBShdwin =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorVBShdwin };

static const TAknsItemID KAknsIIDQsnFrSeparatorVBShdwnone =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorVBShdwnone };

static const TAknsItemID KAknsIIDQsnFrSeparatorVBShdwout =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorVBShdwout };

static const TAknsItemID KAknsIIDQsnFrSeparatorVMShdwin =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorVMShdwin };

static const TAknsItemID KAknsIIDQsnFrSeparatorVMShdwnone =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorVMShdwnone };

static const TAknsItemID KAknsIIDQsnFrSeparatorVMShdwout =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorVMShdwout };

static const TAknsItemID KAknsIIDQsnFrSeparatorVTShdwin =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorVTShdwin };

static const TAknsItemID KAknsIIDQsnFrSeparatorVTShdwnone =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorVTShdwnone };

static const TAknsItemID KAknsIIDQsnFrSeparatorVTShdwout =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrSeparatorVTShdwout };

static const TAknsItemID KAknsIIDQgnIndiBrowserDlCompletedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserDlCompletedAdd };

static const TAknsItemID KAknsIIDQgnIndiBrowserDlOngoingAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserDlOngoingAdd };

static const TAknsItemID KAknsIIDQgnIndiBrowserDlPausedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserDlPausedAdd };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseAccentedCyrillic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseAccentedCyrillic };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseAccentedCyrillicSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseAccentedCyrillicSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseCapitalCyrillic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseCapitalCyrillic };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseCapitalCyrillicSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseCapitalCyrillicSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseCapitalGreek =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseCapitalGreek };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseCapitalGreekSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseCapitalGreekSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseNumericArabicIndic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseNumericArabicIndic };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseNumericArabicIndicSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseNumericArabicIndicSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseNumericDevanagari =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseNumericDevanagari };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseNumericDevanagariSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseNumericDevanagariSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseNumericThai =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseNumericThai };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseNumericThaiSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseNumericThaiSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseSmallCyrillic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseSmallCyrillic };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseSmallCyrillicSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseSmallCyrillicSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseSmallGreek =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseSmallGreek };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseSmallGreekSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseSmallGreekSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextArabic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextArabic };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextArabicSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextArabicSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextCyrillic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextCyrillic };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextCyrillicSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextCyrillicSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextGreek =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextGreek };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextGreekSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextGreekSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextHebrew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextHebrew };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextHebrewSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextHebrewSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextHindi =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextHindi };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextHindiSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextHindiSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextThai =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextThai };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseTextThaiSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseTextThaiSel };

static const TAknsItemID KAknsIIDQgnIndiImedBrightSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedBrightSuper };

static const TAknsItemID KAknsIIDQgnIndiImedBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedBw };

static const TAknsItemID KAknsIIDQgnIndiImedCartoon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedCartoon };

static const TAknsItemID KAknsIIDQgnIndiImedClipart =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedClipart };

static const TAknsItemID KAknsIIDQgnIndiImedContrast =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedContrast };

static const TAknsItemID KAknsIIDQgnIndiImedContrastSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedContrastSuper };

static const TAknsItemID KAknsIIDQgnIndiImedCrop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedCrop };

static const TAknsItemID KAknsIIDQgnIndiImedCursorSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedCursorSuper };

static const TAknsItemID KAknsIIDQgnIndiImedDownple =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedDownple };

static const TAknsItemID KAknsIIDQgnIndiImedEye =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedEye };

static const TAknsItemID KAknsIIDQgnIndiImedFrame =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedFrame };

static const TAknsItemID KAknsIIDQgnIndiImedMoveSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedMoveSuper };

static const TAknsItemID KAknsIIDQgnIndiImedNegative =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedNegative };

static const TAknsItemID KAknsIIDQgnIndiImedResizeSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedResizeSuper };

static const TAknsItemID KAknsIIDQgnIndiImedRotateSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedRotateSuper };

static const TAknsItemID KAknsIIDQgnIndiImedSepia =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedSepia };

static const TAknsItemID KAknsIIDQgnIndiImedSharpness =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedSharpness };

static const TAknsItemID KAknsIIDQgnIndiImedSharpnessSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedSharpnessSuper };

static const TAknsItemID KAknsIIDQgnIndiMidpTrusted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMidpTrusted };

static const TAknsItemID KAknsIIDQgnIndiMidpUntrusted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMidpUntrusted };

static const TAknsItemID KAknsIIDQgnStatCaseLowerHindiPhonetic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseLowerHindiPhonetic };

static const TAknsItemID KAknsIIDQgnStatCaseUpperHindiPhonetic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseUpperHindiPhonetic };

static const TAknsItemID KAknsIIDQgnGrafAbout3edition =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAbout3edition };

static const TAknsItemID KAknsIIDQgnGrafCallImage1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCallImage1 };

static const TAknsItemID KAknsIIDQgnGrafS60Logo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafS60Logo };

static const TAknsItemID KAknsIIDQgnIndiImedBright =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedBright };

static const TAknsItemID KAknsIIDQgnIndiImedTalkbb05 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedTalkbb05 };

static const TAknsItemID KAknsIIDQgnIndiImedTalkbb06 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedTalkbb06 };

static const TAknsItemID KAknsIIDQgnIndiImedText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedText };

static const TAknsItemID KAknsIIDQgnIndiImedThinkbb05 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedThinkbb05 };

static const TAknsItemID KAknsIIDQgnIndiImedThinkbb06 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedThinkbb06 };

static const TAknsItemID KAknsIIDQgnIndiMsgListTab1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMsgListTab1 };

static const TAknsItemID KAknsIIDQgnPropDmTestFailed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDmTestFailed };

static const TAknsItemID KAknsIIDQgnPropDmTestPassed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDmTestPassed };

static const TAknsItemID KAknsIIDQgnPropFolderVcGeneral =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderVcGeneral };

static const TAknsItemID KAknsIIDQgnPropFolderVcProfiles =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderVcProfiles };

static const TAknsItemID KAknsIIDQgnPropSetAppsSearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsSearch };

static const TAknsItemID KAknsIIDQgnPropSetGeneSensor =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetGeneSensor };

static const TAknsItemID KAknsIIDQgnGrafFepChar11x5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar11x5 };

static const TAknsItemID KAknsIIDQgnGrafNsliderImedEndLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderImedEndLeft };

static const TAknsItemID KAknsIIDQgnGrafNsliderImedEndRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderImedEndRight };

static const TAknsItemID KAknsIIDQgnGrafNsliderImedMarker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderImedMarker };

static const TAknsItemID KAknsIIDQgnGrafNsliderImedMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderImedMiddle };

static const TAknsItemID KAknsIIDQgnGrafTvoutLogo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTvoutLogo };

static const TAknsItemID KAknsIIDQgnGrafTvoutProtected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTvoutProtected };

static const TAknsItemID KAknsIIDQgnIndiBrowserUrlCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserUrlCall };

static const TAknsItemID KAknsIIDQgnIndiBrowserUrlEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserUrlEmail };

static const TAknsItemID KAknsIIDQgnIndiBrowserUrlMm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserUrlMm };

static const TAknsItemID KAknsIIDQgnIndiBrowserUrlMms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserUrlMms };

static const TAknsItemID KAknsIIDQgnIndiBrowserUrlPage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserUrlPage };

static const TAknsItemID KAknsIIDQgnIndiBrowserUrlVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserUrlVideo };

static const TAknsItemID KAknsIIDQgnIndiCamsBrightSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsBrightSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsBurstSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsBurstSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsBwSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsBwSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsCloudySuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsCloudySuper };

static const TAknsItemID KAknsIIDQgnIndiCamsContrastSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsContrastSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsExpoSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsExpoSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsFlashAutoSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsFlashAutoSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsFlashOffSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsFlashOffSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsFlashOnSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsFlashOnSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsFluorescentSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsFluorescentSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsLocFoundSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsLocFoundSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsLocNotFoundSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsLocNotFoundSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsMicOffSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsMicOffSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsMmcSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsMmcSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsNegativeSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsNegativeSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsNightSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsNightSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsPausedSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsPausedSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsPhoneMemcSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsPhoneMemcSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsPhotoSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsPhotoSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsSepiaSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsSepiaSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsSunnySuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsSunnySuper };

static const TAknsItemID KAknsIIDQgnIndiCamsTimerSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTimerSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsTungstenSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsTungstenSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsVideoSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsVideoSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsZoomBgMaxSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsZoomBgMaxSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsZoomBgMinSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsZoomBgMinSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsZoomBgSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsZoomBgSuper };

static const TAknsItemID KAknsIIDQgnIndiCamsZoomElevatorSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsZoomElevatorSuper };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseAllTypesJapanese =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseAllTypesJapanese };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseAllTypesJapaneseSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseAllTypesJapaneseSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseKanaKanji =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseKanaKanji };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseKanaKanjiSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseKanaKanjiSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseLatinTextJapanese =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseLatinTextJapanese };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseLatinTextJapaneseSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseLatinTextJapaneseSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseNumericJapanese =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseNumericJapanese };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseNumericJapaneseSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseNumericJapaneseSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonClearJapanese1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonClearJapanese1 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonClearJapanese1Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonClearJapanese1Sel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonClearJapanese2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonClearJapanese2 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonClearJapanese2Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonClearJapanese2Sel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonConvertToKanji =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonConvertToKanji };

static const TAknsItemID KAknsIIDQgnIndiFepButtonConvertToKanjiDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonConvertToKanjiDimmed };

static const TAknsItemID KAknsIIDQgnIndiFepButtonConvertToKanjiSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonConvertToKanjiSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonEnterJapanese1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonEnterJapanese1 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonEnterJapanese1Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonEnterJapanese1Sel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonEnterJapanese2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonEnterJapanese2 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonEnterJapanese2Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonEnterJapanese2Sel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonHiragana =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonHiragana };

static const TAknsItemID KAknsIIDQgnIndiFepButtonHiraganaSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonHiraganaSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonKatakana =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonKatakana };

static const TAknsItemID KAknsIIDQgnIndiFepButtonKatakanaSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonKatakanaSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSpace4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSpace4 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSpace4Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSpace4Sel };

static const TAknsItemID KAknsIIDQgnIndiHelpInfo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHelpInfo };

static const TAknsItemID KAknsIIDQgnIndiHelpTip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHelpTip };

static const TAknsItemID KAknsIIDQgnIndiHelpWarning =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHelpWarning };

static const TAknsItemID KAknsIIDQgnIndiSliderNaviSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSliderNaviSuper };

static const TAknsItemID KAknsIIDQgnPropMsgAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgAttach };

static const TAknsItemID KAknsIIDQgnPropMsgRecipients =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgRecipients };

static const TAknsItemID KAknsIIDQgnPropMsgReply =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgReply };

static const TAknsItemID KAknsIIDQsnFrPopupPreviewMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrPopupPreviewMaskIcon };

static const TAknsItemID KAknsIIDQgnIndiDialerAddContacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerAddContacts };

static const TAknsItemID KAknsIIDQgnIndiMsgPriorityHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMsgPriorityHigh };

static const TAknsItemID KAknsIIDQgnIndiMsgPriorityLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMsgPriorityLow };

static const TAknsItemID KAknsIIDQgnPropMgGamsnapps =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMgGamsnapps };

static const TAknsItemID KAknsIIDQsnFrPopupPreviewCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrPopupPreviewCenter };

static const TAknsItemID KAknsIIDQsnFrPopupPreviewCornerBl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrPopupPreviewCornerBl };

static const TAknsItemID KAknsIIDQsnFrPopupPreviewCornerBr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrPopupPreviewCornerBr };

static const TAknsItemID KAknsIIDQsnFrPopupPreviewCornerTl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrPopupPreviewCornerTl };

static const TAknsItemID KAknsIIDQsnFrPopupPreviewCornerTr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrPopupPreviewCornerTr };

static const TAknsItemID KAknsIIDQsnFrPopupPreviewSideB =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrPopupPreviewSideB };

static const TAknsItemID KAknsIIDQsnFrPopupPreviewSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrPopupPreviewSideL };

static const TAknsItemID KAknsIIDQsnFrPopupPreviewSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrPopupPreviewSideR };

static const TAknsItemID KAknsIIDQsnFrPopupPreviewSideT =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrPopupPreviewSideT };

static const TAknsItemID KAknsIIDQgnGrafBgLscBottomMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBgLscBottomMaskIcon };

static const TAknsItemID KAknsIIDQgnGrafBgLscTopMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBgLscTopMaskIcon };

static const TAknsItemID KAknsIIDQgnGrafBgPrtBottomMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBgPrtBottomMaskIcon };

static const TAknsItemID KAknsIIDQgnGrafBgPrtTopMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBgPrtTopMaskIcon };

static const TAknsItemID KAknsIIDQgnGrafNsliderEndLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderEndLeft };

static const TAknsItemID KAknsIIDQgnGrafNsliderEndRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderEndRight };

static const TAknsItemID KAknsIIDQgnGrafNsliderMarker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderMarker };

static const TAknsItemID KAknsIIDQgnGrafNsliderMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderMiddle };

static const TAknsItemID KAknsIIDQgnGrafNsliderMupEndBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderMupEndBottom };

static const TAknsItemID KAknsIIDQgnGrafNsliderMupEndTop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderMupEndTop };

static const TAknsItemID KAknsIIDQgnGrafNsliderMupMarker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderMupMarker };

static const TAknsItemID KAknsIIDQgnGrafNsliderMupMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderMupMiddle };

static const TAknsItemID KAknsIIDQgnGrafNsliderMupTab =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderMupTab };

static const TAknsItemID KAknsIIDQgnIndiTbBrightness =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbBrightness };

static const TAknsItemID KAknsIIDQgnIndiTbCallVolume =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCallVolume };

static const TAknsItemID KAknsIIDQgnIndiTbFfwFrew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFfwFrew };

static const TAknsItemID KAknsIIDQgnIndiTbFullscreen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFullscreen };

static const TAknsItemID KAknsIIDQgnIndiTbIhfOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbIhfOff };

static const TAknsItemID KAknsIIDQgnIndiTbIhfOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbIhfOn };

static const TAknsItemID KAknsIIDQgnIndiTbPauseSendVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbPauseSendVideo };

static const TAknsItemID KAknsIIDQgnIndiTbPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbPlay };

static const TAknsItemID KAknsIIDQgnIndiTbSendVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbSendVideo };

static const TAknsItemID KAknsIIDQgnStatLocGpsUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatLocGpsUni };

static const TAknsItemID KAknsIIDQsnFrCallPocActCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActCenter };

static const TAknsItemID KAknsIIDQsnFrCallPocActCenterIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActCenterIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocActCornerBl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActCornerBl };

static const TAknsItemID KAknsIIDQsnFrCallPocActCornerBlIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActCornerBlIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocActCornerBr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActCornerBr };

static const TAknsItemID KAknsIIDQsnFrCallPocActCornerBrIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActCornerBrIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocActCornerTl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActCornerTl };

static const TAknsItemID KAknsIIDQsnFrCallPocActCornerTlIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActCornerTlIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocActCornerTr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActCornerTr };

static const TAknsItemID KAknsIIDQsnFrCallPocActCornerTrIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActCornerTrIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocActSideB =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActSideB };

static const TAknsItemID KAknsIIDQsnFrCallPocActSideBIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActSideBIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocActSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActSideL };

static const TAknsItemID KAknsIIDQsnFrCallPocActSideLIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActSideLIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocActSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActSideR };

static const TAknsItemID KAknsIIDQsnFrCallPocActSideRIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActSideRIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocActSideTl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActSideTl };

static const TAknsItemID KAknsIIDQsnFrCallPocActSideTlIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActSideTlIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocActSideTm =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActSideTm };

static const TAknsItemID KAknsIIDQsnFrCallPocActSideTmIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActSideTmIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocActSideTr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActSideTr };

static const TAknsItemID KAknsIIDQsnFrCallPocActSideTrIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocActSideTrIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocInactCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactCenter };

static const TAknsItemID KAknsIIDQsnFrCallPocInactCenterIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactCenterIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocInactCornerBl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactCornerBl };

static const TAknsItemID KAknsIIDQsnFrCallPocInactCornerBlIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactCornerBlIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocInactCornerBr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactCornerBr };

static const TAknsItemID KAknsIIDQsnFrCallPocInactCornerBrIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactCornerBrIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocInactCornerTl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactCornerTl };

static const TAknsItemID KAknsIIDQsnFrCallPocInactCornerTlIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactCornerTlIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocInactCornerTr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactCornerTr };

static const TAknsItemID KAknsIIDQsnFrCallPocInactCornerTrIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactCornerTrIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocInactSideB =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactSideB };

static const TAknsItemID KAknsIIDQsnFrCallPocInactSideBIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactSideBIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocInactSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactSideL };

static const TAknsItemID KAknsIIDQsnFrCallPocInactSideLIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactSideLIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocInactSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactSideR };

static const TAknsItemID KAknsIIDQsnFrCallPocInactSideRIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactSideRIdle };

static const TAknsItemID KAknsIIDQsnFrCallPocInactSideT =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactSideT };

static const TAknsItemID KAknsIIDQsnFrCallPocInactSideTIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCallPocInactSideTIdle };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCenter };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCenterDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCenterDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCenterMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCenterMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerBl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerBl };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerBlDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerBlDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerBlMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerBlMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerBrFirst =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerBrFirst };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerBrFirstDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerBrFirstDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerBrFirstMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerBrFirstMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerBrSecond =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerBrSecond };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerBrSecondDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerBrSecondDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerBrSecondMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerBrSecondMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerTlFirst =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerTlFirst };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerTlFirstDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerTlFirstDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerTlFirstMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerTlFirstMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerTlSecond =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerTlSecond };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerTlSecondDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerTlSecondDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerTlSecondMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerTlSecondMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerTr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerTr };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerTrDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerTrDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleCornerTrMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleCornerTrMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSideB =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleSideB };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSideBDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleSideBDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSideBMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleSideBMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleSideL };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSideLDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleSideLDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSideLMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleSideLMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleSideR };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSideRDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleSideRDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSideRMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleSideRMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSideT =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleSideT };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSideTDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleSideTDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2BubbleSideTMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2BubbleSideTMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2RectCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCenter };

static const TAknsItemID KAknsIIDQsnFrCall2RectCenterDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCenterDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2RectCenterMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCenterMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2RectCornerBl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCornerBl };

static const TAknsItemID KAknsIIDQsnFrCall2RectCornerBlDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCornerBlDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2RectCornerBlMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCornerBlMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2RectCornerBr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCornerBr };

static const TAknsItemID KAknsIIDQsnFrCall2RectCornerBrDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCornerBrDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2RectCornerBrMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCornerBrMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2RectCornerTl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCornerTl };

static const TAknsItemID KAknsIIDQsnFrCall2RectCornerTlDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCornerTlDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2RectCornerTlMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCornerTlMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2RectCornerTr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCornerTr };

static const TAknsItemID KAknsIIDQsnFrCall2RectCornerTrDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCornerTrDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2RectCornerTrMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectCornerTrMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2RectSideB =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectSideB };

static const TAknsItemID KAknsIIDQsnFrCall2RectSideBDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectSideBDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2RectSideBMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectSideBMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2RectSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectSideL };

static const TAknsItemID KAknsIIDQsnFrCall2RectSideLDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectSideLDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2RectSideLMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectSideLMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2RectSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectSideR };

static const TAknsItemID KAknsIIDQsnFrCall2RectSideRDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectSideRDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2RectSideRMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectSideRMaskIcon };

static const TAknsItemID KAknsIIDQsnFrCall2RectSideT =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectSideT };

static const TAknsItemID KAknsIIDQsnFrCall2RectSideTDisconn =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectSideTDisconn };

static const TAknsItemID KAknsIIDQsnFrCall2RectSideTMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrCall2RectSideTMaskIcon };

static const TAknsItemID KAknsIIDQgnGrafNsliderCamsEndLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCamsEndLeft };

static const TAknsItemID KAknsIIDQgnGrafNsliderCamsEndRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCamsEndRight };

static const TAknsItemID KAknsIIDQgnGrafNsliderCamsMarker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCamsMarker };

static const TAknsItemID KAknsIIDQgnGrafNsliderCamsMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCamsMiddle };

static const TAknsItemID KAknsIIDQgnGrafNsliderMarkerSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderMarkerSelected };

static const TAknsItemID KAknsIIDQgnGrafNsliderVdedEndLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVdedEndLeft };

static const TAknsItemID KAknsIIDQgnGrafNsliderVdedEndLeftSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVdedEndLeftSelected };

static const TAknsItemID KAknsIIDQgnGrafNsliderVdedEndMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVdedEndMiddle };

static const TAknsItemID KAknsIIDQgnGrafNsliderVdedEndRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVdedEndRight };

static const TAknsItemID KAknsIIDQgnGrafNsliderVdedEndRightSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVdedEndRightSelected };

static const TAknsItemID KAknsIIDQgnGrafNsliderVdedMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVdedMiddle };

static const TAknsItemID KAknsIIDQgnGrafNsliderVdedMiddleSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVdedMiddleSelected };

static const TAknsItemID KAknsIIDQgnIndiBrowserMsAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserMsAdd };

static const TAknsItemID KAknsIIDQgnIndiCamsRecSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamsRecSuper };

static const TAknsItemID KAknsIIDQgnIndiDefaultConnAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDefaultConnAdd };

static const TAknsItemID KAknsIIDQgnIndiFlashError =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashError };

static const TAknsItemID KAknsIIDQgnIndiImedRotate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedRotate };

static const TAknsItemID KAknsIIDQgnIndiImedRotateLeftSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedRotateLeftSuper };

static const TAknsItemID KAknsIIDQgnIndiImedRotateRightSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedRotateRightSuper };

static const TAknsItemID KAknsIIDQgnIndiNrtypDefault =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiNrtypDefault };

static const TAknsItemID KAknsIIDQgnIndiVdedEnd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdedEnd };

static const TAknsItemID KAknsIIDQgnIndiVdedPlayhead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdedPlayhead };

static const TAknsItemID KAknsIIDQgnIndiVdedScissors =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdedScissors };

static const TAknsItemID KAknsIIDQgnIndiVdedStart =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdedStart };

static const TAknsItemID KAknsIIDQgnIndiVdedTimelineSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdedTimelineSelected };

static const TAknsItemID KAknsIIDQgnIndiVdedVolumeUpDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdedVolumeUpDown };

static const TAknsItemID KAknsIIDQgnMenuAmWidget =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuAmWidget };

static const TAknsItemID KAknsIIDQgnMenuLocation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuLocation };

static const TAknsItemID KAknsIIDQgnPropContactDetailTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropContactDetailTab2 };

static const TAknsItemID KAknsIIDQgnPropContactPropTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropContactPropTab2 };

static const TAknsItemID KAknsIIDQgnPropCpConn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpConn };

static const TAknsItemID KAknsIIDQgnPropCpConnAdmin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpConnAdmin };

static const TAknsItemID KAknsIIDQgnPropCpConnDatasync =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpConnDatasync };

static const TAknsItemID KAknsIIDQgnPropCpConnExchange =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpConnExchange };

static const TAknsItemID KAknsIIDQgnPropCpConnIr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpConnIr };

static const TAknsItemID KAknsIIDQgnPropCpConnMan =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpConnMan };

static const TAknsItemID KAknsIIDQgnPropCpConnSync =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpConnSync };

static const TAknsItemID KAknsIIDQgnPropCpDev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDev };

static const TAknsItemID KAknsIIDQgnPropCpDevAbout =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevAbout };

static const TAknsItemID KAknsIIDQgnPropCpDevDef =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevDef };

static const TAknsItemID KAknsIIDQgnPropCpDevDiag =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevDiag };

static const TAknsItemID KAknsIIDQgnPropCpDevDisp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevDisp };

static const TAknsItemID KAknsIIDQgnPropCpDevInfo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevInfo };

static const TAknsItemID KAknsIIDQgnPropCpDevInteract =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevInteract };

static const TAknsItemID KAknsIIDQgnPropCpDevMan =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevMan };

static const TAknsItemID KAknsIIDQgnPropCpDevOrig =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevOrig };

static const TAknsItemID KAknsIIDQgnPropCpDevSecur =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevSecur };

static const TAknsItemID KAknsIIDQgnPropCpDevUpdate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevUpdate };

static const TAknsItemID KAknsIIDQgnPropCpInst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpInst };

static const TAknsItemID KAknsIIDQgnPropCpInstFiles =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpInstFiles };

static const TAknsItemID KAknsIIDQgnPropCpInstInstalls =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpInstInstalls };

static const TAknsItemID KAknsIIDQgnPropCpInstSettings =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpInstSettings };

static const TAknsItemID KAknsIIDQgnPropCpPerso =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpPerso };

static const TAknsItemID KAknsIIDQgnPropCpPersoIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpPersoIdle };

static const TAknsItemID KAknsIIDQgnPropCpPersoLang =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpPersoLang };

static const TAknsItemID KAknsIIDQgnPropCpPersoProf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpPersoProf };

static const TAknsItemID KAknsIIDQgnPropCpPersoTheme =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpPersoTheme };

static const TAknsItemID KAknsIIDQgnPropCpTele =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpTele };

static const TAknsItemID KAknsIIDQgnPropCpTeleSpeed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpTeleSpeed };

static const TAknsItemID KAknsIIDQgnPropCpTeleVmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpTeleVmail };

static const TAknsItemID KAknsIIDQgnPropFmgrMs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrMs };

static const TAknsItemID KAknsIIDQgnPropFmgrMsSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrMsSub };

static const TAknsItemID KAknsIIDQgnPropMemcMsTab =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMemcMsTab };

static const TAknsItemID KAknsIIDQgnPropMmcMsSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMmcMsSmall };

static const TAknsItemID KAknsIIDQgnPropNrtypCaltxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypCaltxt };

static const TAknsItemID KAknsIIDQgnPropNrtypDefault =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypDefault };

static const TAknsItemID KAknsIIDQgnPropNrtypQdial =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypQdial };

static const TAknsItemID KAknsIIDQgnPropNrtypSync =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypSync };

static const TAknsItemID KAknsIIDQsnCpImedScrollBgBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpImedScrollBgBottom };

static const TAknsItemID KAknsIIDQsnCpImedScrollBgMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpImedScrollBgMiddle };

static const TAknsItemID KAknsIIDQsnCpImedScrollBgTop =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpImedScrollBgTop };

static const TAknsItemID KAknsIIDQsnCpScrollImedHandleBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollImedHandleBottom };

static const TAknsItemID KAknsIIDQsnCpScrollImedHandleMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollImedHandleMiddle };

static const TAknsItemID KAknsIIDQsnCpScrollImedHandleTop =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollImedHandleTop };

static const TAknsItemID KAknsIIDQsnFrPopupPreviewLeftMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrPopupPreviewLeftMaskIcon };

static const TAknsItemID KAknsIIDQsnFrPopupPreviewRightMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrPopupPreviewRightMaskIcon };

static const TAknsItemID KAknsIIDQgnStatBtInvisibleUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatBtInvisibleUni };

static const TAknsItemID KAknsIIDQgnStatModBtInvisibleUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatModBtInvisibleUni };

static const TAknsItemID KAknsIIDQsnFrImedGridCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrImedGridCenter };

static const TAknsItemID KAknsIIDQsnFrImedGridCornerBl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrImedGridCornerBl };

static const TAknsItemID KAknsIIDQsnFrImedGridCornerBr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrImedGridCornerBr };

static const TAknsItemID KAknsIIDQsnFrImedGridCornerTl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrImedGridCornerTl };

static const TAknsItemID KAknsIIDQsnFrImedGridCornerTr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrImedGridCornerTr };

static const TAknsItemID KAknsIIDQsnFrImedGridSideB =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrImedGridSideB };

static const TAknsItemID KAknsIIDQsnFrImedGridSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrImedGridSideL };

static const TAknsItemID KAknsIIDQsnFrImedGridSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrImedGridSideR };

static const TAknsItemID KAknsIIDQsnFrImedGridSideT =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrImedGridSideT };

static const TAknsItemID KAknsIIDQgnIndiMupDefaultAlmumPcast =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupDefaultAlmumPcast };

static const TAknsItemID KAknsIIDQgnIndiTpContacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpContacts };

static const TAknsItemID KAknsIIDQgnPropMupLibraryMusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupLibraryMusic };

static const TAknsItemID KAknsIIDQgnPropMupLibraryPcast =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupLibraryPcast };

static const TAknsItemID KAknsIIDQgnPropMupNowPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupNowPlay };

static const TAknsItemID KAknsIIDQgnPropMupPcastEpisode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupPcastEpisode };

static const TAknsItemID KAknsIIDQgnPropMupPcastEpisodeAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupPcastEpisodeAll };

static const TAknsItemID KAknsIIDQgnPropMupPcastEpisodePublish =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupPcastEpisodePublish };

static const TAknsItemID KAknsIIDQgnPropMupPcastEpisodeTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupPcastEpisodeTitle };

static const TAknsItemID KAknsIIDQgnGrafFepChar11x4ChineseNumeric =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar11x4ChineseNumeric };

static const TAknsItemID KAknsIIDQgnIndiButtonPreviewClose =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonPreviewClose };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSpace5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSpace5 };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSpace5Sel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSpace5Sel };

static const TAknsItemID KAknsIIDQgnIndiImedRotateLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedRotateLeft };

static const TAknsItemID KAknsIIDQgnIndiImedRotateRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedRotateRight };

static const TAknsItemID KAknsIIDQgnPropMupArtistsCollapsed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupArtistsCollapsed };

static const TAknsItemID KAknsIIDQgnPropMupArtistsExpand =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupArtistsExpand };

static const TAknsItemID KAknsIIDQgnPropMupSongsCollapsed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupSongsCollapsed };

static const TAknsItemID KAknsIIDQgnPropMupSongsExpand =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupSongsExpand };

static const TAknsItemID KAknsIIDQgnPropPaSignup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPaSignup };

static const TAknsItemID KAknsIIDQgnPropPaUnsubscribe =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPaUnsubscribe };

static const TAknsItemID KAknsIIDQgnIndiMup3Forward =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup3Forward };

static const TAknsItemID KAknsIIDQgnIndiMup3ForwardFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup3ForwardFocused };

static const TAknsItemID KAknsIIDQgnIndiMup3PauseFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup3PauseFocused };

static const TAknsItemID KAknsIIDQgnIndiMup3Playpause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup3Playpause };

static const TAknsItemID KAknsIIDQgnIndiMup3PlayFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup3PlayFocused };

static const TAknsItemID KAknsIIDQgnIndiMup3Rewind =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup3Rewind };

static const TAknsItemID KAknsIIDQgnIndiMup3RewindFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup3RewindFocused };

static const TAknsItemID KAknsIIDQgnIndiMup3Stop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup3Stop };

static const TAknsItemID KAknsIIDQgnIndiMup3StopFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup3StopFocused };

static const TAknsItemID KAknsIIDQgnIndiWifiProtectedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWifiProtectedAdd };

static const TAknsItemID KAknsIIDQgnPropCpDevSec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevSec };

static const TAknsItemID KAknsIIDQgnPropImageTbNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbNext };

static const TAknsItemID KAknsIIDQgnPropImageTbPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPause };

static const TAknsItemID KAknsIIDQgnPropImageTbPlay2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPlay2 };

static const TAknsItemID KAknsIIDQgnPropImageTbPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPrev };

static const TAknsItemID KAknsIIDQgnPropImageTbZoomIn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbZoomIn };

static const TAknsItemID KAknsIIDQgnPropImageTbZoomOut =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbZoomOut };

static const TAknsItemID KAknsIIDQgnPropVideoNoRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVideoNoRight };

static const TAknsItemID KAknsIIDQgnPropVideoValidRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVideoValidRight };

static const TAknsItemID KAknsIIDQgnIndiCalcDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcDown };

static const TAknsItemID KAknsIIDQgnIndiCalcUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalcUp };

static const TAknsItemID KAknsIIDQgnIndiCaleTbMeetingNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbMeetingNew };

static const TAknsItemID KAknsIIDQgnIndiCaleTbTodoNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbTodoNew };

static const TAknsItemID KAknsIIDQgnIndiVdedPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdedPause };

static const TAknsItemID KAknsIIDQgnPropCamsMskSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCamsMskSelect };

static const TAknsItemID KAknsIIDQgnPropLinkVideoSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLinkVideoSuper };

static const TAknsItemID KAknsIIDQgnPropMupPcastTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupPcastTitle };

static const TAknsItemID KAknsIIDQgnGrafFepTrainingArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepTrainingArrowLeft };

static const TAknsItemID KAknsIIDQgnGrafFepTrainingArrowLeftSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepTrainingArrowLeftSel };

static const TAknsItemID KAknsIIDQgnGrafFepTrainingArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepTrainingArrowRight };

static const TAknsItemID KAknsIIDQgnGrafFepTrainingArrowRightSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepTrainingArrowRightSel };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmallVerticalMarker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmallVerticalMarker };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmallVerticalMarkerSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmallVerticalMarkerSelected };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmallVerticalOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmallVerticalOff };

static const TAknsItemID KAknsIIDQgnGrafVolumeSmallVerticalOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafVolumeSmallVerticalOn };

static const TAknsItemID KAknsIIDQgnIndiFepSctFwSymbols =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepSctFwSymbols };

static const TAknsItemID KAknsIIDQgnIndiFepSctFwSymbolsDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepSctFwSymbolsDimmed };

static const TAknsItemID KAknsIIDQgnIndiFepSctHwSymbols =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepSctHwSymbols };

static const TAknsItemID KAknsIIDQgnIndiFepSctHwSymbolsDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepSctHwSymbolsDimmed };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseCapital =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseCapital };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseCapitalSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseCapitalSel };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseNumeric =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseNumeric };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseNumericSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseNumericSel };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseSmall };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseSmallSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseSmallSel };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseSpecial =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseSpecial };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseSpecialSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseSpecialSel };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCharGrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCharGrid };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCharGridSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCharGridSel };

static const TAknsItemID KAknsIIDQgnIndiFmgrMsAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFmgrMsAdd };

static const TAknsItemID KAknsIIDQgnIndiImedCursor2Super =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedCursor2Super };

static const TAknsItemID KAknsIIDQgnIndiPlaying =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPlaying };

static const TAknsItemID KAknsIIDQgnIndiVolumeArrowDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVolumeArrowDown };

static const TAknsItemID KAknsIIDQgnIndiVolumeArrowDownInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVolumeArrowDownInactive };

static const TAknsItemID KAknsIIDQgnIndiVolumeArrowDownSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVolumeArrowDownSelected };

static const TAknsItemID KAknsIIDQgnIndiVolumeArrowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVolumeArrowUp };

static const TAknsItemID KAknsIIDQgnIndiVolumeArrowUpInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVolumeArrowUpInactive };

static const TAknsItemID KAknsIIDQgnIndiVolumeArrowUpSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVolumeArrowUpSelected };

static const TAknsItemID KAknsIIDQgnPropHwrShortcutTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHwrShortcutTab2 };

static const TAknsItemID KAknsIIDQgnPropHwrTrainingShortcut =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHwrTrainingShortcut };

static const TAknsItemID KAknsIIDQgnPropHwrTrainingTab1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHwrTrainingTab1 };

static const TAknsItemID KAknsIIDQgnGrafFepChar6x5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar6x5 };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbBlank =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbBlank };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbBm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbBm };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbFeeds =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbFeeds };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbFindKw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbFindKw };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbGoto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbGoto };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbHelp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbHelp };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbImages =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbImages };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbKeyMap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbKeyMap };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbPages =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbPages };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbRotate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbRotate };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbSaveBm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbSaveBm };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbSavePage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbSavePage };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbSendUrl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbSendUrl };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbSettings =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbSettings };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbSwitchWin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbSwitchWin };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbTb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbTb };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbUrls =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbUrls };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbZoomIn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbZoomIn };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbZoomOut =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbZoomOut };

static const TAknsItemID KAknsIIDQgnIndiFepButtonFullHalfWidth =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonFullHalfWidth };

static const TAknsItemID KAknsIIDQgnIndiFepButtonFullHalfWidthSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonFullHalfWidthSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonHalfFullWidth =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonHalfFullWidth };

static const TAknsItemID KAknsIIDQgnIndiFepButtonHalfFullWidthSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonHalfFullWidthSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonLongBackspace =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonLongBackspace };

static const TAknsItemID KAknsIIDQgnIndiFepButtonLongBackspaceSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonLongBackspaceSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonMarkCaseNumeric =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonMarkCaseNumeric };

static const TAknsItemID KAknsIIDQgnIndiFepButtonMarkCaseNumericSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonMarkCaseNumericSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonMarkCaseText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonMarkCaseText };

static const TAknsItemID KAknsIIDQgnIndiFepButtonMarkCaseTextSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonMarkCaseTextSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonMarkChinese =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonMarkChinese };

static const TAknsItemID KAknsIIDQgnIndiFepButtonMarkChineseSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonMarkChineseSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonMorefunction =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonMorefunction };

static const TAknsItemID KAknsIIDQgnIndiFepButtonMorefunctionSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonMorefunctionSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonShortSpace =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonShortSpace };

static const TAknsItemID KAknsIIDQgnIndiFepButtonShortSpaceSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonShortSpaceSel };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseCapitalCyrillic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseCapitalCyrillic };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseCapitalCyrillicSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseCapitalCyrillicSel };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseCapitalGreek =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseCapitalGreek };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseCapitalGreekSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseCapitalGreekSel };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseSmallCyrillic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseSmallCyrillic };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseSmallCyrillicSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseSmallCyrillicSel };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseSmallGreek =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseSmallGreek };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseSmallGreekSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseSmallGreekSel };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseTextHebrew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseTextHebrew };

static const TAknsItemID KAknsIIDQgnIndiFepTrainingButtonCaseTextHebrewSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepTrainingButtonCaseTextHebrewSel };

static const TAknsItemID KAknsIIDQgnIndiIvImages =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiIvImages };

static const TAknsItemID KAknsIIDQgnIndiIvLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiIvLeft };

static const TAknsItemID KAknsIIDQgnIndiIvRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiIvRight };

static const TAknsItemID KAknsIIDQgnIndiMup2Random =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2Random };

static const TAknsItemID KAknsIIDQgnIndiMup2RandomOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup2RandomOff };

static const TAknsItemID KAknsIIDQgnIndiMup4Forward =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4Forward };

static const TAknsItemID KAknsIIDQgnIndiMup4ForwardDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4ForwardDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup4ForwardFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4ForwardFocused };

static const TAknsItemID KAknsIIDQgnIndiMup4Pause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4Pause };

static const TAknsItemID KAknsIIDQgnIndiMup4PauseDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4PauseDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup4PauseFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4PauseFocused };

static const TAknsItemID KAknsIIDQgnIndiMup4Play =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4Play };

static const TAknsItemID KAknsIIDQgnIndiMup4PlayDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4PlayDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup4PlayFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4PlayFocused };

static const TAknsItemID KAknsIIDQgnIndiMup4Rewind =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4Rewind };

static const TAknsItemID KAknsIIDQgnIndiMup4RewindDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4RewindDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup4RewindFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4RewindFocused };

static const TAknsItemID KAknsIIDQgnIndiMup4Stop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4Stop };

static const TAknsItemID KAknsIIDQgnIndiMup4StopDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4StopDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup4StopFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4StopFocused };

static const TAknsItemID KAknsIIDQgnIndiMup4VolumeDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4VolumeDown };

static const TAknsItemID KAknsIIDQgnIndiMup4VolumeDownDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4VolumeDownDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup4VolumeDownFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4VolumeDownFocused };

static const TAknsItemID KAknsIIDQgnIndiMup4VolumeUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4VolumeUp };

static const TAknsItemID KAknsIIDQgnIndiMup4VolumeUpDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4VolumeUpDimmed };

static const TAknsItemID KAknsIIDQgnIndiMup4VolumeUpFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMup4VolumeUpFocused };

static const TAknsItemID KAknsIIDQgnIndiMupDefaultAlbumPcast =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupDefaultAlbumPcast };

static const TAknsItemID KAknsIIDQgnIndiMupRepeatOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupRepeatOff };

static const TAknsItemID KAknsIIDQgnIndiSctrlMaskActLsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSctrlMaskActLsc };

static const TAknsItemID KAknsIIDQgnIndiSctrlMaskActPrt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSctrlMaskActPrt };

static const TAknsItemID KAknsIIDQgnIndiSctrlMaskInactLsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSctrlMaskInactLsc };

static const TAknsItemID KAknsIIDQgnIndiSctrlSkMaskLeftPrt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSctrlSkMaskLeftPrt };

static const TAknsItemID KAknsIIDQgnIndiSctrlSkMaskLsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSctrlSkMaskLsc };

static const TAknsItemID KAknsIIDQgnIndiSctrlSkMaskRightPrt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSctrlSkMaskRightPrt };

static const TAknsItemID KAknsIIDQgnNoteNfcPrint =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteNfcPrint };

static const TAknsItemID KAknsIIDQgnNoteNfcWriteTag =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteNfcWriteTag };

static const TAknsItemID KAknsIIDQgnPropBatteryPsActivate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBatteryPsActivate };

static const TAknsItemID KAknsIIDQgnPropBatteryPsDeactivate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBatteryPsDeactivate };

static const TAknsItemID KAknsIIDQgnPropBtCarKit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtCarKit };

static const TAknsItemID KAknsIIDQgnPropBtConnected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtConnected };

static const TAknsItemID KAknsIIDQgnPropBtGenericDev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtGenericDev };

static const TAknsItemID KAknsIIDQgnPropBtKeyboard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtKeyboard };

static const TAknsItemID KAknsIIDQgnPropBtMouse =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtMouse };

static const TAknsItemID KAknsIIDQgnPropBtPrinter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtPrinter };

static const TAknsItemID KAknsIIDQgnPropFmgrMsSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrMsSmall };

static const TAknsItemID KAknsIIDQgnPropImageTbDelete2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbDelete2 };

static const TAknsItemID KAknsIIDQgnPropImageTbDelete2Dimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbDelete2Dimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbDelete2Focused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbDelete2Focused };

static const TAknsItemID KAknsIIDQgnPropImageTbNextDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbNextDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbNextFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbNextFocused };

static const TAknsItemID KAknsIIDQgnPropImageTbPauseDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPauseDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbPauseFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPauseFocused };

static const TAknsItemID KAknsIIDQgnPropImageTbPlay2Dimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPlay2Dimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbPlay2Focused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPlay2Focused };

static const TAknsItemID KAknsIIDQgnPropImageTbPrevDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPrevDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbPrevFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbPrevFocused };

static const TAknsItemID KAknsIIDQgnPropImageTbZoom2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbZoom2 };

static const TAknsItemID KAknsIIDQgnPropImageTbZoomInDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbZoomInDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbZoomInFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbZoomInFocused };

static const TAknsItemID KAknsIIDQgnPropImageTbZoomOutDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbZoomOutDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbZoomOutFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbZoomOutFocused };

static const TAknsItemID KAknsIIDQgnPropImageVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageVideo };

static const TAknsItemID KAknsIIDQgnPropMpTv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMpTv };

static const TAknsItemID KAknsIIDQgnPropNfcAuthPay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNfcAuthPay };

static const TAknsItemID KAknsIIDQgnPropNfcCloneTag =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNfcCloneTag };

static const TAknsItemID KAknsIIDQgnPropNfcCreateTag =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNfcCreateTag };

static const TAknsItemID KAknsIIDQgnPropNfcEraseTag =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNfcEraseTag };

static const TAknsItemID KAknsIIDQgnPropNfcReadTag =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNfcReadTag };

static const TAknsItemID KAknsIIDQgnPropNfcSessClosed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNfcSessClosed };

static const TAknsItemID KAknsIIDQgnPropNfcSessOpen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNfcSessOpen };

static const TAknsItemID KAknsIIDQgnPropSctrlCharGrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSctrlCharGrid };

static const TAknsItemID KAknsIIDQgnPropSctrlPreview =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSctrlPreview };

static const TAknsItemID KAknsIIDQgnPropSctrlRemove =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSctrlRemove };

static const TAknsItemID KAknsIIDQgnIndiDialerLogs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerLogs };

static const TAknsItemID KAknsIIDQgnIndiBrowserTxtSelectionMode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTxtSelectionMode };

static const TAknsItemID KAknsIIDQgnIndiMpOngoingInterrupt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpOngoingInterrupt };

static const TAknsItemID KAknsIIDQgnPropCpConnIrOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpConnIrOff };

static const TAknsItemID KAknsIIDQgnPropImGroupNotJoined =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImGroupNotJoined };

static const TAknsItemID KAknsIIDQgnPropSetAppsBtConnHidden =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsBtConnHidden };

static const TAknsItemID KAknsIIDQgnPropSetAppsBtConnShown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsBtConnShown };

static const TAknsItemID KAknsIIDQgnPropSetAppsBtOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsBtOff };

static const TAknsItemID KAknsIIDQgnPropSetAppsBtOnHidden =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsBtOnHidden };

static const TAknsItemID KAknsIIDQgnPropSetAppsBtOnShown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsBtOnShown };

static const TAknsItemID KAknsIIDQgnPropSetAppsUsbOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsUsbOff };

static const TAknsItemID KAknsIIDQgnPropSetNetworkSubOffline =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetNetworkSubOffline };

static const TAknsItemID KAknsIIDQgnStatFnLock =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatFnLock };

static const TAknsItemID KAknsIIDQgnStatFnMode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatFnMode };

static const TAknsItemID KAknsIIDQgnGrafMshopIconApp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMshopIconApp };

static const TAknsItemID KAknsIIDQgnGrafMshopIconCtx =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMshopIconCtx };

static const TAknsItemID KAknsIIDQgnGrafMupAdtlReorderDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupAdtlReorderDown };

static const TAknsItemID KAknsIIDQgnGrafMupAdtlReorderUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupAdtlReorderUp };

static const TAknsItemID KAknsIIDQgnGrafMupAdtlReorderUpdown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupAdtlReorderUpdown };

static const TAknsItemID KAknsIIDQgnGrafMupCtxAddsong =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupCtxAddsong };

static const TAknsItemID KAknsIIDQgnGrafMupCtxReordersong =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupCtxReordersong };

static const TAknsItemID KAknsIIDQgnGrafMupDlstMusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupDlstMusic };

static const TAknsItemID KAknsIIDQgnGrafMupDlstNowplaying =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupDlstNowplaying };

static const TAknsItemID KAknsIIDQgnGrafMupDlstPodcast =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupDlstPodcast };

static const TAknsItemID KAknsIIDQgnGrafMupIconUpnpRemote =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupIconUpnpRemote };

static const TAknsItemID KAknsIIDQgnGrafMupLstBrokenplayl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstBrokenplayl };

static const TAknsItemID KAknsIIDQgnGrafMupLstBrokenpodc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstBrokenpodc };

static const TAknsItemID KAknsIIDQgnGrafMupLstBrokentrack =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstBrokentrack };

static const TAknsItemID KAknsIIDQgnGrafMupLstColpsdArtist =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstColpsdArtist };

static const TAknsItemID KAknsIIDQgnGrafMupLstColpsdTrack =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstColpsdTrack };

static const TAknsItemID KAknsIIDQgnGrafMupLstCorruptpodc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstCorruptpodc };

static const TAknsItemID KAknsIIDQgnGrafMupLstCorrupttrack =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstCorrupttrack };

static const TAknsItemID KAknsIIDQgnGrafMupLstDrmExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstDrmExp };

static const TAknsItemID KAknsIIDQgnGrafMupLstEmpty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstEmpty };

static const TAknsItemID KAknsIIDQgnGrafMupLstExpdArtist =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstExpdArtist };

static const TAknsItemID KAknsIIDQgnGrafMupLstExpdTrack =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstExpdTrack };

static const TAknsItemID KAknsIIDQgnGrafMupLstPdcAdded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstPdcAdded };

static const TAknsItemID KAknsIIDQgnGrafMupLstPdcAuto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstPdcAuto };

static const TAknsItemID KAknsIIDQgnGrafMupLstPdcCateg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstPdcCateg };

static const TAknsItemID KAknsIIDQgnGrafMupLstPdcCompplay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstPdcCompplay };

static const TAknsItemID KAknsIIDQgnGrafMupLstPdcDate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstPdcDate };

static const TAknsItemID KAknsIIDQgnGrafMupLstPdcEpisode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstPdcEpisode };

static const TAknsItemID KAknsIIDQgnGrafMupLstPdcNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstPdcNew };

static const TAknsItemID KAknsIIDQgnGrafMupLstPdcNoplay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstPdcNoplay };

static const TAknsItemID KAknsIIDQgnGrafMupLstPdcPartplay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstPdcPartplay };

static const TAknsItemID KAknsIIDQgnGrafMupLstPdcTitle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstPdcTitle };

static const TAknsItemID KAknsIIDQgnGrafMupLstTrack =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstTrack };

static const TAknsItemID KAknsIIDQgnGrafMupLstUserplayl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupLstUserplayl };

static const TAknsItemID KAknsIIDQgnGrafMupNpvDefalbumartTransp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupNpvDefalbumartTransp };

static const TAknsItemID KAknsIIDQgnGrafMupNpvIconPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupNpvIconPause };

static const TAknsItemID KAknsIIDQgnGrafMupNpvIconPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupNpvIconPlay };

static const TAknsItemID KAknsIIDQgnGrafMupNpvIconRepeat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupNpvIconRepeat };

static const TAknsItemID KAknsIIDQgnGrafMupNpvIconRepeatone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupNpvIconRepeatone };

static const TAknsItemID KAknsIIDQgnGrafMupNpvIconShuffle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupNpvIconShuffle };

static const TAknsItemID KAknsIIDQgnGrafMupNpvPrbarBgd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupNpvPrbarBgd };

static const TAknsItemID KAknsIIDQgnGrafMupNpvPrbarBgdLs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupNpvPrbarBgdLs };

static const TAknsItemID KAknsIIDQgnGrafMupNpvPrbarMidDownload =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupNpvPrbarMidDownload };

static const TAknsItemID KAknsIIDQgnGrafMupNpvPrbarTopPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupNpvPrbarTopPlay };

static const TAknsItemID KAknsIIDQgnGrafMupSsBgnd01 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupSsBgnd01 };

static const TAknsItemID KAknsIIDQgnGrafMupSsBgnd02 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupSsBgnd02 };

static const TAknsItemID KAknsIIDQgnGrafMupSsBgnd03 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupSsBgnd03 };

static const TAknsItemID KAknsIIDQgnGrafMupSsBgnd04 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupSsBgnd04 };

static const TAknsItemID KAknsIIDQgnGrafMupStatusPopPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupStatusPopPause };

static const TAknsItemID KAknsIIDQgnGrafMupStatusPopPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupStatusPopPlay };

static const TAknsItemID KAknsIIDQgnGrafMupVolwIconMute =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupVolwIconMute };

static const TAknsItemID KAknsIIDQgnGrafMupVolwIconSpeaker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupVolwIconSpeaker };

static const TAknsItemID KAknsIIDQgnIndiMpNoAudio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpNoAudio };

static const TAknsItemID KAknsIIDQgnIndiMpNoVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpNoVideo };

static const TAknsItemID KAknsIIDQgnIndiMupVolwSlider =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupVolwSlider };

static const TAknsItemID KAknsIIDQgnIndiMupVolwSliderBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupVolwSliderBg };

static const TAknsItemID KAknsIIDQgnMenuSivc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuSivc };

static const TAknsItemID KAknsIIDQgnPropBtCarKitConnect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtCarKitConnect };

static const TAknsItemID KAknsIIDQgnPropBtGenericDevConnect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtGenericDevConnect };

static const TAknsItemID KAknsIIDQgnPropBtKeyboardConnect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtKeyboardConnect };

static const TAknsItemID KAknsIIDQgnPropBtMouseConnect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtMouseConnect };

static const TAknsItemID KAknsIIDQgnPropBtPrinterConnect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtPrinterConnect };

static const TAknsItemID KAknsIIDQgnGrafNsliderTickMajor =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderTickMajor };

static const TAknsItemID KAknsIIDQgnGrafNsliderTickMinor =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderTickMinor };

static const TAknsItemID KAknsIIDQgnGrafNsliderVerticalBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVerticalBottom };

static const TAknsItemID KAknsIIDQgnGrafNsliderVerticalMarker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVerticalMarker };

static const TAknsItemID KAknsIIDQgnGrafNsliderVerticalMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVerticalMiddle };

static const TAknsItemID KAknsIIDQgnGrafNsliderVerticalTickMajor =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVerticalTickMajor };

static const TAknsItemID KAknsIIDQgnGrafNsliderVerticalTickMinor =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVerticalTickMinor };

static const TAknsItemID KAknsIIDQgnGrafNsliderVerticalTop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVerticalTop };

static const TAknsItemID KAknsIIDQgnGrafTimetrackEndLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTimetrackEndLeft };

static const TAknsItemID KAknsIIDQgnGrafTimetrackEndRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTimetrackEndRight };

static const TAknsItemID KAknsIIDQgnGrafTimetrackMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTimetrackMiddle };

static const TAknsItemID KAknsIIDQgnGrafTimetrackTrimmedEndLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTimetrackTrimmedEndLeft };

static const TAknsItemID KAknsIIDQgnGrafTimetrackTrimmedEndRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTimetrackTrimmedEndRight };

static const TAknsItemID KAknsIIDQgnGrafTimetrackTrimmedMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTimetrackTrimmedMiddle };

static const TAknsItemID KAknsIIDQgnIndiCam4Flash =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Flash };

static const TAknsItemID KAknsIIDQgnIndiCam4ModeCamera =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ModeCamera };

static const TAknsItemID KAknsIIDQgnIndiCam4Reso =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Reso };

static const TAknsItemID KAknsIIDQgnIndiCam4Sequence =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Sequence };

static const TAknsItemID KAknsIIDQgnIndiCam4Shake =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Shake };

static const TAknsItemID KAknsIIDQgnIndiCam4Timer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Timer };

static const TAknsItemID KAknsIIDQgnIndiTbAppsgrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbAppsgrid };

static const TAknsItemID KAknsIIDQgnIndiTbDialler =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbDialler };

static const TAknsItemID KAknsIIDQgnIndiTbEmailNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbEmailNew };

static const TAknsItemID KAknsIIDQgnIndiTbEmailReply =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbEmailReply };

static const TAknsItemID KAknsIIDQgnIndiTbMsgNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMsgNew };

static const TAknsItemID KAknsIIDQgnIndiTbMsgReply =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMsgReply };

static const TAknsItemID KAknsIIDQgnIndiTbProfiles =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbProfiles };

static const TAknsItemID KAknsIIDQgnIndiTimetrackMarked =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTimetrackMarked };

static const TAknsItemID KAknsIIDQgnIndiTimetrackMarker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTimetrackMarker };

static const TAknsItemID KAknsIIDQgnIndiVid4AudioMute =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4AudioMute };

static const TAknsItemID KAknsIIDQgnIndiVid4LightOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4LightOn };

static const TAknsItemID KAknsIIDQgnIndiVid4MemoryMmc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4MemoryMmc };

static const TAknsItemID KAknsIIDQgnIndiVid4MemoryPhone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4MemoryPhone };

static const TAknsItemID KAknsIIDQgnIndiVid4ModeVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4ModeVideo };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityHigh };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityLow };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityNormal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityNormal };

static const TAknsItemID KAknsIIDQgnIndiVid4StabilizeOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4StabilizeOn };

static const TAknsItemID KAknsIIDQgnIndiWlanSnifferPluginOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWlanSnifferPluginOff };

static const TAknsItemID KAknsIIDQgnIndiWlanSnifferPluginOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWlanSnifferPluginOn };

static const TAknsItemID KAknsIIDQgnMenuGroupCustomerMusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupCustomerMusic };

static const TAknsItemID KAknsIIDQgnMenuGroupCustomerUtilities =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupCustomerUtilities };

static const TAknsItemID KAknsIIDQgnMenuWlanSniffer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuWlanSniffer };

static const TAknsItemID KAknsIIDQgnPropFolderParent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderParent };

static const TAknsItemID KAknsIIDQgnPropSetConnWlanConn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnWlanConn };

static const TAknsItemID KAknsIIDQgnPropSetConnWlanOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnWlanOff };

static const TAknsItemID KAknsIIDQgnGrafTbExtFindBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTbExtFindBg };

static const TAknsItemID KAknsIIDQgnGrafTbExtFindButtonBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTbExtFindButtonBg };

static const TAknsItemID KAknsIIDQgnIndiAiArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiArrowLeft };

static const TAknsItemID KAknsIIDQgnIndiAiArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiArrowRight };

static const TAknsItemID KAknsIIDQgnIndiAiBlinds =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiBlinds };

static const TAknsItemID KAknsIIDQgnIndiAiClosePlugin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiClosePlugin };

static const TAknsItemID KAknsIIDQgnIndiAiClosePluginPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiClosePluginPressed };

static const TAknsItemID KAknsIIDQgnIndiAiDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiDown };

static const TAknsItemID KAknsIIDQgnIndiAiDownDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiDownDimmed };

static const TAknsItemID KAknsIIDQgnIndiAiDownPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiDownPressed };

static const TAknsItemID KAknsIIDQgnIndiAiLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiLeft };

static const TAknsItemID KAknsIIDQgnIndiAiLeftDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiLeftDimmed };

static const TAknsItemID KAknsIIDQgnIndiAiLeftPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiLeftPressed };

static const TAknsItemID KAknsIIDQgnIndiAiMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiMiddle };

static const TAknsItemID KAknsIIDQgnIndiAiMiddleDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiMiddleDimmed };

static const TAknsItemID KAknsIIDQgnIndiAiMiddlePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiMiddlePressed };

static const TAknsItemID KAknsIIDQgnIndiAiRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiRight };

static const TAknsItemID KAknsIIDQgnIndiAiRightDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiRightDimmed };

static const TAknsItemID KAknsIIDQgnIndiAiRightPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiRightPressed };

static const TAknsItemID KAknsIIDQgnIndiAiShow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiShow };

static const TAknsItemID KAknsIIDQgnIndiAiShowLandscape =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiShowLandscape };

static const TAknsItemID KAknsIIDQgnIndiAiUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiUp };

static const TAknsItemID KAknsIIDQgnIndiAiUpDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiUpDimmed };

static const TAknsItemID KAknsIIDQgnIndiAiUpPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiUpPressed };

static const TAknsItemID KAknsIIDQgnIndiFepButtonInputSwitch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonInputSwitch };

static const TAknsItemID KAknsIIDQgnIndiFepButtonInputSwitchSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonInputSwitchSel };

static const TAknsItemID KAknsIIDQgnIndiItutCursorDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiItutCursorDown };

static const TAknsItemID KAknsIIDQgnIndiItutCursorLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiItutCursorLeft };

static const TAknsItemID KAknsIIDQgnIndiItutCursorRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiItutCursorRight };

static const TAknsItemID KAknsIIDQgnIndiItutCursorUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiItutCursorUp };

static const TAknsItemID KAknsIIDQgnIndiItutInputSwitch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiItutInputSwitch };

static const TAknsItemID KAknsIIDQgnIndiKeypadShift =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiKeypadShift };

static const TAknsItemID KAknsIIDQgnIndiKeypadSpace =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiKeypadSpace };

static const TAknsItemID KAknsIIDQgnIndiKeypadStar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiKeypadStar };

static const TAknsItemID KAknsIIDQgnIndiTbExtension =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbExtension };

static const TAknsItemID KAknsIIDQgnMenuAppsDcd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuAppsDcd };

static const TAknsItemID KAknsIIDQgnPropBtAudioConnect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtAudioConnect };

static const TAknsItemID KAknsIIDQgnPropBtComputerConnect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtComputerConnect };

static const TAknsItemID KAknsIIDQgnPropBtPhoneConnect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBtPhoneConnect };

static const TAknsItemID KAknsIIDQgnPropSetAppsDcd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsDcd };

static const TAknsItemID KAknsIIDQgnCalendarEventIndi =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCalendarEventIndi };

static const TAknsItemID KAknsIIDQgnCalendarIndiDate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCalendarIndiDate };

static const TAknsItemID KAknsIIDQgnEasydialActionMenu =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEasydialActionMenu };

static const TAknsItemID KAknsIIDQgnEasydialContact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEasydialContact };

static const TAknsItemID KAknsIIDQgnEasydialContactGroup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEasydialContactGroup };

static const TAknsItemID KAknsIIDQgnEmailFocusFrameBottomLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEmailFocusFrameBottomLeft };

static const TAknsItemID KAknsIIDQgnEmailFocusFrameBottomRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEmailFocusFrameBottomRight };

static const TAknsItemID KAknsIIDQgnEmailFocusFrameTopLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEmailFocusFrameTopLeft };

static const TAknsItemID KAknsIIDQgnEmailFocusFrameTopRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEmailFocusFrameTopRight };

static const TAknsItemID KAknsIIDQgnFscalIndiAlarmDay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiAlarmDay };

static const TAknsItemID KAknsIIDQgnFscalIndiAlarmTime =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiAlarmTime };

static const TAknsItemID KAknsIIDQgnFscalIndiEvents =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiEvents };

static const TAknsItemID KAknsIIDQgnFscalIndiMemo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiMemo };

static const TAknsItemID KAknsIIDQgnFscalIndiNewTodo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiNewTodo };

static const TAknsItemID KAknsIIDQgnFscalIndiOccasion =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiOccasion };

static const TAknsItemID KAknsIIDQgnFscalIndiPriorityHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiPriorityHigh };

static const TAknsItemID KAknsIIDQgnFscalIndiPriorityLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiPriorityLow };

static const TAknsItemID KAknsIIDQgnFscalIndiPriorityNormal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiPriorityNormal };

static const TAknsItemID KAknsIIDQgnFscalIndiRecurrence =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiRecurrence };

static const TAknsItemID KAknsIIDQgnFscalIndiSubject =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiSubject };

static const TAknsItemID KAknsIIDQgnFscalIndiSubject02 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiSubject02 };

static const TAknsItemID KAknsIIDQgnFscalIndiSubjectPrioHi =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiSubjectPrioHi };

static const TAknsItemID KAknsIIDQgnFscalIndiSynchronisation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiSynchronisation };

static const TAknsItemID KAknsIIDQgnFscalIndiTodo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiTodo };

static const TAknsItemID KAknsIIDQgnFseDropDownDeletedItemsIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseDropDownDeletedItemsIcon };

static const TAknsItemID KAknsIIDQgnFseDropDownDraftsIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseDropDownDraftsIcon };

static const TAknsItemID KAknsIIDQgnFseDropDownEmailAccountIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseDropDownEmailAccountIcon };

static const TAknsItemID KAknsIIDQgnFseDropDownInboxIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseDropDownInboxIcon };

static const TAknsItemID KAknsIIDQgnFseDropDownMoreFoldersIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseDropDownMoreFoldersIcon };

static const TAknsItemID KAknsIIDQgnFseDropDownOutboxIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseDropDownOutboxIcon };

static const TAknsItemID KAknsIIDQgnFseDropDownSentIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseDropDownSentIcon };

static const TAknsItemID KAknsIIDQgnFseDropDownSentIcon2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseDropDownSentIcon2 };

static const TAknsItemID KAknsIIDQgnFseFolderListAscendingIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseFolderListAscendingIcon };

static const TAknsItemID KAknsIIDQgnFseFolderListDeletedItemsIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseFolderListDeletedItemsIcon };

static const TAknsItemID KAknsIIDQgnFseFolderListDescendingIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseFolderListDescendingIcon };

static const TAknsItemID KAknsIIDQgnFseFolderListDraftsIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseFolderListDraftsIcon };

static const TAknsItemID KAknsIIDQgnFseFolderListInboxIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseFolderListInboxIcon };

static const TAknsItemID KAknsIIDQgnFseFolderListInboxSubfoldersIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseFolderListInboxSubfoldersIcon };

static const TAknsItemID KAknsIIDQgnFseFolderListServerFoldersIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseFolderListServerFoldersIcon };

static const TAknsItemID KAknsIIDQgnFseMailAttachment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailAttachment };

static const TAknsItemID KAknsIIDQgnFseMailIconForwardedAttachmentIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailIconForwardedAttachmentIcon };

static const TAknsItemID KAknsIIDQgnFseMailIconForwardedIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailIconForwardedIcon };

static const TAknsItemID KAknsIIDQgnFseMailIconHighPriorityIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailIconHighPriorityIcon };

static const TAknsItemID KAknsIIDQgnFseMailIconLowPriorityIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailIconLowPriorityIcon };

static const TAknsItemID KAknsIIDQgnFseMailIconReadAttachmentIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailIconReadAttachmentIcon };

static const TAknsItemID KAknsIIDQgnFseMailIconReadIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailIconReadIcon };

static const TAknsItemID KAknsIIDQgnFseMailIconRepliedAllAttachmentIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailIconRepliedAllAttachmentIcon };

static const TAknsItemID KAknsIIDQgnFseMailIconRepliedAllIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailIconRepliedAllIcon };

static const TAknsItemID KAknsIIDQgnFseMailIconRepliedAttachmentIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailIconRepliedAttachmentIcon };

static const TAknsItemID KAknsIIDQgnFseMailIconRepliedIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailIconRepliedIcon };

static const TAknsItemID KAknsIIDQgnFseMailIconUnreadIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailIconUnreadIcon };

static const TAknsItemID KAknsIIDQgnFseMailIconUnreadAttachmentIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailIconUnreadAttachmentIcon };

static const TAknsItemID KAknsIIDQgnFseMailRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailRead };

static const TAknsItemID KAknsIIDQgnFseMailReadAttachment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadAttachment };

static const TAknsItemID KAknsIIDQgnFseMailReadAttachmentLowPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadAttachmentLowPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadForwarded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadForwarded };

static const TAknsItemID KAknsIIDQgnFseMailReadForwardedAttachment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadForwardedAttachment };

static const TAknsItemID KAknsIIDQgnFseMailReadForwardedAttachmentHighPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadForwardedAttachmentHighPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadForwardedAttachmentLowPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadForwardedAttachmentLowPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadForwardedHighPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadForwardedHighPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadForwardedLowPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadForwardedLowPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadForwardedLowPrior2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadForwardedLowPrior2 };

static const TAknsItemID KAknsIIDQgnFseMailReadHighPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadHighPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadLowPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadLowPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadReplied =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadReplied };

static const TAknsItemID KAknsIIDQgnFseMailReadRepliedAttachment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadRepliedAttachment };

static const TAknsItemID KAknsIIDQgnFseMailReadRepliedAttachmentHighPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadRepliedAttachmentHighPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadRepliedAttachmentLowPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadRepliedAttachmentLowPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadRepliedForwarded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadRepliedForwarded };

static const TAknsItemID KAknsIIDQgnFseMailReadRepliedForwardedAttachment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadRepliedForwardedAttachment };

static const TAknsItemID KAknsIIDQgnFseMailReadRepliedForwardedAttachmentHighPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadRepliedForwardedAttachmentHighPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadRepliedForwardedAttachmentLowPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadRepliedForwardedAttachmentLowPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadRepliedForwardedHighPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadRepliedForwardedHighPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadRepliedHighPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadRepliedHighPrior };

static const TAknsItemID KAknsIIDQgnFseMailReadRepliedLowPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadRepliedLowPrior };

static const TAknsItemID KAknsIIDQgnFseMailSentMail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailSentMail };

static const TAknsItemID KAknsIIDQgnFseMailUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnread };

static const TAknsItemID KAknsIIDQgnFseMailUnreadAttachment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadAttachment };

static const TAknsItemID KAknsIIDQgnFseMailUnreadAttachmentHighPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadAttachmentHighPrior };

static const TAknsItemID KAknsIIDQgnFseMailUnreadAttachmentLowPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadAttachmentLowPrior };

static const TAknsItemID KAknsIIDQgnFseMailUnreadForwarded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadForwarded };

static const TAknsItemID KAknsIIDQgnFseMailUnreadForwardedAttachment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadForwardedAttachment };

static const TAknsItemID KAknsIIDQgnFseMailUnreadForwardedAttachmentHighPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadForwardedAttachmentHighPrior };

static const TAknsItemID KAknsIIDQgnFseMailUnreadForwardedAttachmentLowPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadForwardedAttachmentLowPrior };

static const TAknsItemID KAknsIIDQgnFseMailUnreadForwardedHighPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadForwardedHighPrior };

static const TAknsItemID KAknsIIDQgnFseMailUnreadForwardedLowPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadForwardedLowPrior };

static const TAknsItemID KAknsIIDQgnFseMailUnreadHighPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadHighPrior };

static const TAknsItemID KAknsIIDQgnFseMailUnreadLowPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadLowPrior };

static const TAknsItemID KAknsIIDQgnFseViewerFollowUpCompleteIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerFollowUpCompleteIcon };

static const TAknsItemID KAknsIIDQgnFseViewerFollowUpCompleteIcon02 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerFollowUpCompleteIcon02 };

static const TAknsItemID KAknsIIDQgnFseViewerFollowUpIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerFollowUpIcon };

static const TAknsItemID KAknsIIDQgnFseViewerIconHighPriorityIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerIconHighPriorityIcon };

static const TAknsItemID KAknsIIDQgnFseViewerIconLowPriorityIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerIconLowPriorityIcon };

static const TAknsItemID KAknsIIDQgnFseViewerIconReadIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerIconReadIcon };

static const TAknsItemID KAknsIIDQgnFseViewerIconRepliedAllIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerIconRepliedAllIcon };

static const TAknsItemID KAknsIIDQgnFseViewerIconRepliedIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerIconRepliedIcon };

static const TAknsItemID KAknsIIDQgnFseViewerIconUnreadIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerIconUnreadIcon };

static const TAknsItemID KAknsIIDQgnFseViewerAttachmentDocIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerAttachmentDocIcon };

static const TAknsItemID KAknsIIDQgnFseViewerAttachmentHtmlIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerAttachmentHtmlIcon };

static const TAknsItemID KAknsIIDQgnFseViewerAttachmentImageIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerAttachmentImageIcon };

static const TAknsItemID KAknsIIDQgnFseViewerAttachmentNotDownloadedIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerAttachmentNotDownloadedIcon };

static const TAknsItemID KAknsIIDQgnFseViewerAttachmentPdfIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerAttachmentPdfIcon };

static const TAknsItemID KAknsIIDQgnFseViewerAttachmentPptIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerAttachmentPptIcon };

static const TAknsItemID KAknsIIDQgnFseViewerAttachmentRtfIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerAttachmentRtfIcon };

static const TAknsItemID KAknsIIDQgnFseViewerAttachmentUnidentifiedExtensionIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerAttachmentUnidentifiedExtensionIcon };

static const TAknsItemID KAknsIIDQgnFseViewerAttachmentXlsIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseViewerAttachmentXlsIcon };

static const TAknsItemID KAknsIIDQgnFsActionCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionCall };

static const TAknsItemID KAknsIIDQgnFsActionConfService =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionConfService };

static const TAknsItemID KAknsIIDQgnFsActionConfWizard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionConfWizard };

static const TAknsItemID KAknsIIDQgnFsActionEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionEmail };

static const TAknsItemID KAknsIIDQgnFsActionMeeting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionMeeting };

static const TAknsItemID KAknsIIDQgnFsActionMms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionMms };

static const TAknsItemID KAknsIIDQgnFsActionPtt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionPtt };

static const TAknsItemID KAknsIIDQgnFsActionSms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionSms };

static const TAknsItemID KAknsIIDQgnFsActionVidcall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionVidcall };

static const TAknsItemID KAknsIIDQgnFsActionVoip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionVoip };

static const TAknsItemID KAknsIIDQgnFsContactsGroup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsContactsGroup };

static const TAknsItemID KAknsIIDQgnFsDatabasePhone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsDatabasePhone };

static const TAknsItemID KAknsIIDQgnFsEmailContentTypeGroupedResultView =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailContentTypeGroupedResultView };

static const TAknsItemID KAknsIIDQgnFsEmailGrafRoundedInputField0 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailGrafRoundedInputField0 };

static const TAknsItemID KAknsIIDQgnFsEmailGrafRoundedInputField01 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailGrafRoundedInputField01 };

static const TAknsItemID KAknsIIDQgnFsEmailGrafRoundedInputField02 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailGrafRoundedInputField02 };

static const TAknsItemID KAknsIIDQgnFsEmailGrafRoundedInputField03 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailGrafRoundedInputField03 };

static const TAknsItemID KAknsIIDQgnFsEmailGrafRoundedInputField04 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailGrafRoundedInputField04 };

static const TAknsItemID KAknsIIDQgnFsEmailGrafRoundedInputField05 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailGrafRoundedInputField05 };

static const TAknsItemID KAknsIIDQgnFsEmailGrafRoundedInputField06 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailGrafRoundedInputField06 };

static const TAknsItemID KAknsIIDQgnFsEmailGrafRoundedInputField07 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailGrafRoundedInputField07 };

static const TAknsItemID KAknsIIDQgnFsEmailGrafRoundedInputField08 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailGrafRoundedInputField08 };

static const TAknsItemID KAknsIIDQgnFsEmailGrafRoundedInputField09 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailGrafRoundedInputField09 };

static const TAknsItemID KAknsIIDQgnFsEmailMenuAppIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailMenuAppIcon };

static const TAknsItemID KAknsIIDQgnFsEmailReadSingleResultView =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailReadSingleResultView };

static const TAknsItemID KAknsIIDQgnFsEmailSentSingleResultView =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailSentSingleResultView };

static const TAknsItemID KAknsIIDQgnFsEmailUnreadSingleResultView =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailUnreadSingleResultView };

static const TAknsItemID KAknsIIDQgnFsGrafCalendarContent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafCalendarContent };

static const TAknsItemID KAknsIIDQgnFsGrafCalendarCtrlbar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafCalendarCtrlbar };

static const TAknsItemID KAknsIIDQgnFsGrafCalendarHeader =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafCalendarHeader };

static const TAknsItemID KAknsIIDQgnFsGrafCalendarHeaderCopy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafCalendarHeaderCopy };

static const TAknsItemID KAknsIIDQgnFsGrafContactsContent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafContactsContent };

static const TAknsItemID KAknsIIDQgnFsGrafContactsCtrlbar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafContactsCtrlbar };

static const TAknsItemID KAknsIIDQgnFsGrafContactsHeader =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafContactsHeader };

static const TAknsItemID KAknsIIDQgnFsGrafEmailContent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafEmailContent };

static const TAknsItemID KAknsIIDQgnFsGrafEmailCtrlbar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafEmailCtrlbar };

static const TAknsItemID KAknsIIDQgnFsGrafEmailHeader =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafEmailHeader };

static const TAknsItemID KAknsIIDQgnFsGroupConfService =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGroupConfService };

static const TAknsItemID KAknsIIDQgnFsGrpListQueryNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrpListQueryNew };

static const TAknsItemID KAknsIIDQgnFsHomeNotifActiveNoPopup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifActiveNoPopup };

static const TAknsItemID KAknsIIDQgnFsHomeNotifActiveWithPopup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifActiveWithPopup };

static const TAknsItemID KAknsIIDQgnFsHomeNotifInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifInactive };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupC1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupC1 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupC2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupC2 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupC3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupC3 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupC4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupC4 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupC5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupC5 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupC6 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupC6 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupL1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupL1 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupL2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupL2 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupL3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupL3 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupL4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupL4 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupL5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupL5 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupL6 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupL6 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupR1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupR1 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupR2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupR2 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupR3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupR3 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupR4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupR4 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupR5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupR5 };

static const TAknsItemID KAknsIIDQgnFsHomeNotifPopupR6 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHomeNotifPopupR6 };

static const TAknsItemID KAknsIIDQgnFsHscrActionArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHscrActionArrowLeft };

static const TAknsItemID KAknsIIDQgnFsHscrActionArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHscrActionArrowRight };

static const TAknsItemID KAknsIIDQgnFsHscrEmailPopup1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHscrEmailPopup1 };

static const TAknsItemID KAknsIIDQgnFsHscrEmailPopup2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHscrEmailPopup2 };

static const TAknsItemID KAknsIIDQgnFsHscrEmailPopup3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHscrEmailPopup3 };

static const TAknsItemID KAknsIIDQgnFsHscrEmailPopup4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHscrEmailPopup4 };

static const TAknsItemID KAknsIIDQgnFsHscrEmailPopup5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHscrEmailPopup5 };

static const TAknsItemID KAknsIIDQgnFsHscrEmailPopup6 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHscrEmailPopup6 };

static const TAknsItemID KAknsIIDQgnFsHscrGrafEasydialHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHscrGrafEasydialHigh };

static const TAknsItemID KAknsIIDQgnFsHscrGrafEasydialLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHscrGrafEasydialLow };

static const TAknsItemID KAknsIIDQgnFsIndiAddNewMailbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiAddNewMailbox };

static const TAknsItemID KAknsIIDQgnFsIndiConnected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiConnected };

static const TAknsItemID KAknsIIDQgnFsIndiDisconnectedError =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiDisconnectedError };

static const TAknsItemID KAknsIIDQgnFsIndiDisconnectedGeneral =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiDisconnectedGeneral };

static const TAknsItemID KAknsIIDQgnFsIndiDisconnectedLowBattery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiDisconnectedLowBattery };

static const TAknsItemID KAknsIIDQgnFsIndiIntellisyncInbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiIntellisyncInbox };

static const TAknsItemID KAknsIIDQgnFsIndiMarkedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiMarkedAdd };

static const TAknsItemID KAknsIIDQgnFsIndiMinusSign =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiMinusSign };

static const TAknsItemID KAknsIIDQgnFsIndiPlusSign =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiPlusSign };

static const TAknsItemID KAknsIIDQgnFsIndiPriorityHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiPriorityHigh };

static const TAknsItemID KAknsIIDQgnFsIndiPriorityHigh2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiPriorityHigh2 };

static const TAknsItemID KAknsIIDQgnFsIndiPriorityLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiPriorityLow };

static const TAknsItemID KAknsIIDQgnFsIndiPriorityLow2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiPriorityLow2 };

static const TAknsItemID KAknsIIDQgnFsIndiPriorityNormal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiPriorityNormal };

static const TAknsItemID KAknsIIDQgnFsIndiSynchronisation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiSynchronisation };

static const TAknsItemID KAknsIIDQgnFsIndiUpgrade =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiUpgrade };

static const TAknsItemID KAknsIIDQgnFsPropNrtypEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsPropNrtypEmail };

static const TAknsItemID KAknsIIDQgnGrafBarWaitAnim2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBarWaitAnim2 };

static const TAknsItemID KAknsIIDQgnGrpListConfService =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrpListConfService };

static const TAknsItemID KAknsIIDQgnHscrNotifierAction =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrNotifierAction };

static const TAknsItemID KAknsIIDQgnHscrNotifierMissedCalls =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrNotifierMissedCalls };

static const TAknsItemID KAknsIIDQgnHscrNotifierNewVoiceMail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrNotifierNewVoiceMail };

static const TAknsItemID KAknsIIDQgnHscrNotifierNewVoiceMail1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrNotifierNewVoiceMail1 };

static const TAknsItemID KAknsIIDQgnHscrNotifierNewVoiceMail1and2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrNotifierNewVoiceMail1and2 };

static const TAknsItemID KAknsIIDQgnHscrNotifierNewVoiceMail2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrNotifierNewVoiceMail2 };

static const TAknsItemID KAknsIIDQgnHscrNotifierUnreadMessages =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrNotifierUnreadMessages };

static const TAknsItemID KAknsIIDQgnHscrSecLocked =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrSecLocked };

static const TAknsItemID KAknsIIDQgnHscrSecLockNotifierMissedCalls =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrSecLockNotifierMissedCalls };

static const TAknsItemID KAknsIIDQgnHscrSecLockNotifierMissedCalls2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrSecLockNotifierMissedCalls2 };

static const TAknsItemID KAknsIIDQgnHscrSecLockNotifierNewVoicemails =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrSecLockNotifierNewVoicemails };

static const TAknsItemID KAknsIIDQgnHscrSecLockNotifierNewVoicemails1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrSecLockNotifierNewVoicemails1 };

static const TAknsItemID KAknsIIDQgnHscrSecLockNotifierNewVoicemails12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrSecLockNotifierNewVoicemails12 };

static const TAknsItemID KAknsIIDQgnHscrSecLockNotifierNewVoicemails2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrSecLockNotifierNewVoicemails2 };

static const TAknsItemID KAknsIIDQgnHscrSecLockNotifierUnreadMsgs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrSecLockNotifierUnreadMsgs };

static const TAknsItemID KAknsIIDQgnHscrSwitchMode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHscrSwitchMode };

static const TAknsItemID KAknsIIDQgnIndiActionMenu =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiActionMenu };

static const TAknsItemID KAknsIIDQgnIndiButtonAnswer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonAnswer };

static const TAknsItemID KAknsIIDQgnIndiButtonBluetooth =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonBluetooth };

static const TAknsItemID KAknsIIDQgnIndiButtonConference =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonConference };

static const TAknsItemID KAknsIIDQgnIndiButtonDrop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonDrop };

static const TAknsItemID KAknsIIDQgnIndiButtonEndActiveCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonEndActiveCall };

static const TAknsItemID KAknsIIDQgnIndiButtonEndAllCalls =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonEndAllCalls };

static const TAknsItemID KAknsIIDQgnIndiButtonEndCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonEndCall };

static const TAknsItemID KAknsIIDQgnIndiButtonGoIdle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonGoIdle };

static const TAknsItemID KAknsIIDQgnIndiButtonHandset =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonHandset };

static const TAknsItemID KAknsIIDQgnIndiButtonHold =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonHold };

static const TAknsItemID KAknsIIDQgnIndiButtonJoin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJoin };

static const TAknsItemID KAknsIIDQgnIndiButtonLoudspeaker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonLoudspeaker };

static const TAknsItemID KAknsIIDQgnIndiButtonMuteMic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonMuteMic };

static const TAknsItemID KAknsIIDQgnIndiButtonParticipants =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonParticipants };

static const TAknsItemID KAknsIIDQgnIndiButtonPrivate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonPrivate };

static const TAknsItemID KAknsIIDQgnIndiButtonReject =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonReject };

static const TAknsItemID KAknsIIDQgnIndiButtonSendDtmf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonSendDtmf };

static const TAknsItemID KAknsIIDQgnIndiButtonSwap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonSwap };

static const TAknsItemID KAknsIIDQgnIndiButtonUnhold =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonUnhold };

static const TAknsItemID KAknsIIDQgnIndiButtonUnmuteMic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonUnmuteMic };

static const TAknsItemID KAknsIIDQgnIndiButtonVideoToVoice =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonVideoToVoice };

static const TAknsItemID KAknsIIDQgnIndiButtonVoiceToVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonVoiceToVideo };

static const TAknsItemID KAknsIIDQgnIndiCam4Antired =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Antired };

static const TAknsItemID KAknsIIDQgnIndiCam4Audio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Audio };

static const TAknsItemID KAknsIIDQgnIndiCam4AudioMute =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4AudioMute };

static const TAknsItemID KAknsIIDQgnIndiCam4Autoflash =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Autoflash };

static const TAknsItemID KAknsIIDQgnIndiCam4Camera =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Camera };

static const TAknsItemID KAknsIIDQgnIndiCam4CameraSecond =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4CameraSecond };

static const TAknsItemID KAknsIIDQgnIndiCam4Capture =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Capture };

static const TAknsItemID KAknsIIDQgnIndiCam4Colour =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Colour };

static const TAknsItemID KAknsIIDQgnIndiCam4ColourBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ColourBw };

static const TAknsItemID KAknsIIDQgnIndiCam4ColourNatural =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ColourNatural };

static const TAknsItemID KAknsIIDQgnIndiCam4ColourNegative =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ColourNegative };

static const TAknsItemID KAknsIIDQgnIndiCam4ColourNormal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ColourNormal };

static const TAknsItemID KAknsIIDQgnIndiCam4ColourSepia =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ColourSepia };

static const TAknsItemID KAknsIIDQgnIndiCam4ColourVivid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ColourVivid };

static const TAknsItemID KAknsIIDQgnIndiCam4Delete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Delete };

static const TAknsItemID KAknsIIDQgnIndiCam4Edit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Edit };

static const TAknsItemID KAknsIIDQgnIndiCam4Exposure =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Exposure };

static const TAknsItemID KAknsIIDQgnIndiCam4Extension =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Extension };

static const TAknsItemID KAknsIIDQgnIndiCam4FlashOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4FlashOff };

static const TAknsItemID KAknsIIDQgnIndiCam4FlashOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4FlashOn };

static const TAknsItemID KAknsIIDQgnIndiCam4FocusFrameAutoBl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4FocusFrameAutoBl };

static const TAknsItemID KAknsIIDQgnIndiCam4FocusFrameAutoBr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4FocusFrameAutoBr };

static const TAknsItemID KAknsIIDQgnIndiCam4FocusFrameAutoTl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4FocusFrameAutoTl };

static const TAknsItemID KAknsIIDQgnIndiCam4FocusFrameAutoTr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4FocusFrameAutoTr };

static const TAknsItemID KAknsIIDQgnIndiCam4GotoGallery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4GotoGallery };

static const TAknsItemID KAknsIIDQgnIndiCam4Iso =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Iso };

static const TAknsItemID KAknsIIDQgnIndiCam4IsoAuto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4IsoAuto };

static const TAknsItemID KAknsIIDQgnIndiCam4IsoHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4IsoHigh };

static const TAknsItemID KAknsIIDQgnIndiCam4IsoLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4IsoLow };

static const TAknsItemID KAknsIIDQgnIndiCam4IsoMedium =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4IsoMedium };

static const TAknsItemID KAknsIIDQgnIndiCam4LightOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4LightOff };

static const TAknsItemID KAknsIIDQgnIndiCam4LightOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4LightOn };

static const TAknsItemID KAknsIIDQgnIndiCam4MemoryMmc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4MemoryMmc };

static const TAknsItemID KAknsIIDQgnIndiCam4MemoryPhone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4MemoryPhone };

static const TAknsItemID KAknsIIDQgnIndiCam4ModeAuto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ModeAuto };

static const TAknsItemID KAknsIIDQgnIndiCam4ModeCloseup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ModeCloseup };

static const TAknsItemID KAknsIIDQgnIndiCam4ModeLandscape =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ModeLandscape };

static const TAknsItemID KAknsIIDQgnIndiCam4ModeNight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ModeNight };

static const TAknsItemID KAknsIIDQgnIndiCam4ModePortrait =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ModePortrait };

static const TAknsItemID KAknsIIDQgnIndiCam4ModeSport =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ModeSport };

static const TAknsItemID KAknsIIDQgnIndiCam4ModeUserscene =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ModeUserscene };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality03mpLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality03mpLow };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality08mpLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality08mpLow };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality13mpLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality13mpLow };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality13mpMedium =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality13mpMedium };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality1mpLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality1mpLow };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality2mpHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality2mpHigh };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality2mpMedium =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality2mpMedium };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality3mpHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality3mpHigh };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality3mpMedium =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality3mpMedium };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality5mpHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality5mpHigh };

static const TAknsItemID KAknsIIDQgnIndiCam4Selftimer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Selftimer };

static const TAknsItemID KAknsIIDQgnIndiCam4Selftimer10s =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Selftimer10s };

static const TAknsItemID KAknsIIDQgnIndiCam4Selftimer20s =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Selftimer20s };

static const TAknsItemID KAknsIIDQgnIndiCam4SelftimerOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4SelftimerOff };

static const TAknsItemID KAknsIIDQgnIndiCam4Send =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Send };

static const TAknsItemID KAknsIIDQgnIndiCam4Sequence10min =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Sequence10min };

static const TAknsItemID KAknsIIDQgnIndiCam4Sequence10s =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Sequence10s };

static const TAknsItemID KAknsIIDQgnIndiCam4Sequence1min =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Sequence1min };

static const TAknsItemID KAknsIIDQgnIndiCam4Sequence30min =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Sequence30min };

static const TAknsItemID KAknsIIDQgnIndiCam4Sequence30s =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Sequence30s };

static const TAknsItemID KAknsIIDQgnIndiCam4Sequence5min =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Sequence5min };

static const TAknsItemID KAknsIIDQgnIndiCam4Sequence5s =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Sequence5s };

static const TAknsItemID KAknsIIDQgnIndiCam4SequenceBurst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4SequenceBurst };

static const TAknsItemID KAknsIIDQgnIndiCam4Video =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Video };

static const TAknsItemID KAknsIIDQgnIndiCam4Wb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Wb };

static const TAknsItemID KAknsIIDQgnIndiCam4WbAuto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4WbAuto };

static const TAknsItemID KAknsIIDQgnIndiCam4WbCloudy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4WbCloudy };

static const TAknsItemID KAknsIIDQgnIndiCam4WbFluorecent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4WbFluorecent };

static const TAknsItemID KAknsIIDQgnIndiCam4WbSunny =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4WbSunny };

static const TAknsItemID KAknsIIDQgnIndiCam4WbTungsten =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4WbTungsten };

static const TAknsItemID KAknsIIDQgnIndiCam4Zoom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Zoom };

static const TAknsItemID KAknsIIDQgnIndiHiddenWlan =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHiddenWlan };

static const TAknsItemID KAknsIIDQgnIndiTbAddRecipient =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbAddRecipient };

static const TAknsItemID KAknsIIDQgnIndiTbEmailForward =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbEmailForward };

static const TAknsItemID KAknsIIDQgnIndiTbMsgForward =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMsgForward };

static const TAknsItemID KAknsIIDQgnIndiTbMsgSend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMsgSend };

static const TAknsItemID KAknsIIDQgnIndiTbRetrieveMms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRetrieveMms };

static const TAknsItemID KAknsIIDQgnIndiVid4ContinuousAf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4ContinuousAf };

static const TAknsItemID KAknsIIDQgnIndiVid4Pause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4Pause };

static const TAknsItemID KAknsIIDQgnIndiVid4Play =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4Play };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityEmailHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityEmailHigh };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityEmailNormal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityEmailNormal };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityTvHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityTvHigh };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityTvNormal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityTvNormal };

static const TAknsItemID KAknsIIDQgnIndiVid4Record =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4Record };

static const TAknsItemID KAknsIIDQgnMeetReqArranger =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqArranger };

static const TAknsItemID KAknsIIDQgnMeetReqIndiAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqIndiAlarm };

static const TAknsItemID KAknsIIDQgnMeetReqIndiChecboxMark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqIndiChecboxMark };

static const TAknsItemID KAknsIIDQgnMeetReqIndiChecboxUnmark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqIndiChecboxUnmark };

static const TAknsItemID KAknsIIDQgnMeetReqIndiCheckboxMark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqIndiCheckboxMark };

static const TAknsItemID KAknsIIDQgnMeetReqIndiCheckboxUnmark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqIndiCheckboxUnmark };

static const TAknsItemID KAknsIIDQgnMeetReqIndiClock =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqIndiClock };

static const TAknsItemID KAknsIIDQgnMeetReqIndiDate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqIndiDate };

static const TAknsItemID KAknsIIDQgnMeetReqIndiDateEnd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqIndiDateEnd };

static const TAknsItemID KAknsIIDQgnMeetReqIndiDateStart =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqIndiDateStart };

static const TAknsItemID KAknsIIDQgnMeetReqIndiLocation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqIndiLocation };

static const TAknsItemID KAknsIIDQgnMeetReqIndiTimeAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqIndiTimeAlarm };

static const TAknsItemID KAknsIIDQgnMenuEncryption =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuEncryption };

static const TAknsItemID KAknsIIDQgnMenuModes =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuModes };

static const TAknsItemID KAknsIIDQgnMenuSwitchMode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuSwitchMode };

static const TAknsItemID KAknsIIDQgnPropAlbumPhotoVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAlbumPhotoVideo };

static const TAknsItemID KAknsIIDQgnPropCpDevKeyguard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevKeyguard };

static const TAknsItemID KAknsIIDQgnPropCpDevPsActivate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevPsActivate };

static const TAknsItemID KAknsIIDQgnPropCpDiagConn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDiagConn };

static const TAknsItemID KAknsIIDQgnPropCpDiagCoverage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDiagCoverage };

static const TAknsItemID KAknsIIDQgnPropCpDiagFail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDiagFail };

static const TAknsItemID KAknsIIDQgnPropCpDiagHw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDiagHw };

static const TAknsItemID KAknsIIDQgnPropCpDiagNot =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDiagNot };

static const TAknsItemID KAknsIIDQgnPropCpDiagPass =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDiagPass };

static const TAknsItemID KAknsIIDQgnPropCpDiagService =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDiagService };

static const TAknsItemID KAknsIIDQgnSwitchModeAnimation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnSwitchModeAnimation };

static const TAknsItemID KAknsIIDQgnIndiCam4Contrast =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Contrast };

static const TAknsItemID KAknsIIDQgnIndiCam4Sharpness =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Sharpness };

static const TAknsItemID KAknsIIDQgnIndiCam4TbCapture =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbCapture };

static const TAknsItemID KAknsIIDQgnIndiCam4TbDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbDelete };

static const TAknsItemID KAknsIIDQgnIndiCam4TbEdit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbEdit };

static const TAknsItemID KAknsIIDQgnIndiCam4TbExtension =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbExtension };

static const TAknsItemID KAknsIIDQgnIndiCam4TbFlash =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbFlash };

static const TAknsItemID KAknsIIDQgnIndiCam4TbLight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbLight };

static const TAknsItemID KAknsIIDQgnIndiCam4TbPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbPause };

static const TAknsItemID KAknsIIDQgnIndiCam4TbPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbPlay };

static const TAknsItemID KAknsIIDQgnIndiCam4TbRecord =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbRecord };

static const TAknsItemID KAknsIIDQgnIndiCam4TbSend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbSend };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomBottom };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomMarker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomMarker };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomMax =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomMax };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomMiddle };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomMin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomMin };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomTop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomTop };

static const TAknsItemID KAknsIIDQgnIndiTbBusinessCard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbBusinessCard };

static const TAknsItemID KAknsIIDQgnIndiTbCamcorder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCamcorder };

static const TAknsItemID KAknsIIDQgnIndiTbCamera =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCamera };

static const TAknsItemID KAknsIIDQgnIndiTbExpandInsert =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbExpandInsert };

static const TAknsItemID KAknsIIDQgnIndiTbMsgForward2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMsgForward2 };

static const TAknsItemID KAknsIIDQgnIndiTbNote =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbNote };

static const TAknsItemID KAknsIIDQgnIndiTbRetrieveMms2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRetrieveMms2 };

static const TAknsItemID KAknsIIDQgnIndiTbSlide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbSlide };

static const TAknsItemID KAknsIIDQgnIndiTbTemplate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbTemplate };

static const TAknsItemID KAknsIIDQgnPropCpConnShortcut =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpConnShortcut };

static const TAknsItemID KAknsIIDQgnPropCpDevPen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevPen };

static const TAknsItemID KAknsIIDQgnPropCpDevSensor =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevSensor };

static const TAknsItemID KAknsIIDQgnPropCpDevVc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevVc };

static const TAknsItemID KAknsIIDQgnPropDownloadVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDownloadVideo };

static const TAknsItemID KAknsIIDQgnPropImageTbSend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbSend };

static const TAknsItemID KAknsIIDQgnPropImageTbSendDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbSendDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbSendFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbSendFocused };

static const TAknsItemID KAknsIIDQgnPropImageTbSendPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbSendPressed };

static const TAknsItemID KAknsIIDQgnPropVdedColor =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVdedColor };

static const TAknsItemID KAknsIIDQgnPropVdedMute =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVdedMute };

static const TAknsItemID KAknsIIDQgnPropVdedSlow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVdedSlow };

static const TAknsItemID KAknsIIDQgnPropVdedUnmute =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVdedUnmute };

static const TAknsItemID KAknsIIDQgnFseMailReadAttachmentHighPriority =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailReadAttachmentHighPriority };

static const TAknsItemID KAknsIIDQgnFseMailSentMailFolder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailSentMailFolder };

static const TAknsItemID KAknsIIDQgnFseMailUnreadReplied =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadReplied };

static const TAknsItemID KAknsIIDQgnFseMailUnreadRepliedAttachment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadRepliedAttachment };

static const TAknsItemID KAknsIIDQgnFseMailUnreadRepliedAttachmentHighPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadRepliedAttachmentHighPrior };

static const TAknsItemID KAknsIIDQgnFseMailUnreadRepliedAttachmentLowPrior =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadRepliedAttachmentLowPrior };

static const TAknsItemID KAknsIIDQgnFsActionAudio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionAudio };

static const TAknsItemID KAknsIIDQgnFsCalendargArranger =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCalendargArranger };

static const TAknsItemID KAknsIIDQgnFsCaleBgLsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCaleBgLsc };

static const TAknsItemID KAknsIIDQgnFsCaleEvAcc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCaleEvAcc };

static const TAknsItemID KAknsIIDQgnFsCaleEvAct =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCaleEvAct };

static const TAknsItemID KAknsIIDQgnFsCaleEvCanc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCaleEvCanc };

static const TAknsItemID KAknsIIDQgnFsCaleEvConf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCaleEvConf };

static const TAknsItemID KAknsIIDQgnFsCaleEvDecl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCaleEvDecl };

static const TAknsItemID KAknsIIDQgnFsCaleEvHiddenIndiDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCaleEvHiddenIndiDown };

static const TAknsItemID KAknsIIDQgnFsCaleEvHiddenIndiUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCaleEvHiddenIndiUp };

static const TAknsItemID KAknsIIDQgnFsCaleEvNotsync =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCaleEvNotsync };

static const TAknsItemID KAknsIIDQgnFsCaleEvPass =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCaleEvPass };

static const TAknsItemID KAknsIIDQgnFsCaleEvTent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCaleEvTent };

static const TAknsItemID KAknsIIDQgnFsCalWeekendBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCalWeekendBg };

static const TAknsItemID KAknsIIDQgnFsDropMenuBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsDropMenuBg };

static const TAknsItemID KAknsIIDQgnFsEmailail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailail };

static const TAknsItemID KAknsIIDQgnFsEmailerGridInboxIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailerGridInboxIcon };

static const TAknsItemID KAknsIIDQgnFsEmaileUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmaileUnread };

static const TAknsItemID KAknsIIDQgnFsEmaileUnreadForwarded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmaileUnreadForwarded };

static const TAknsItemID KAknsIIDQgnFsEmaileUnreadWithAttachment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmaileUnreadWithAttachment };

static const TAknsItemID KAknsIIDQgnFsEmaileUnreadWithAttachmentForwarded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmaileUnreadWithAttachmentForwarded };

static const TAknsItemID KAknsIIDQgnFsEmailframeTopLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailframeTopLeft };

static const TAknsItemID KAknsIIDQgnFsEmailframeTopRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailframeTopRight };

static const TAknsItemID KAknsIIDQgnFsEmaililAppIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmaililAppIcon };

static const TAknsItemID KAknsIIDQgnFsEmailment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailment };

static const TAknsItemID KAknsIIDQgnFsEmailolder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailolder };

static const TAknsItemID KAknsIIDQgnFsEmailCalAcceptCalendarEvent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalAcceptCalendarEvent };

static const TAknsItemID KAknsIIDQgnFsEmailCalCallSender =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalCallSender };

static const TAknsItemID KAknsIIDQgnFsEmailCalDeclineCalendar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalDeclineCalendar };

static const TAknsItemID KAknsIIDQgnFsEmailCalDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalDelete };

static const TAknsItemID KAknsIIDQgnFsEmailCalEventRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalEventRead };

static const TAknsItemID KAknsIIDQgnFsEmailCalEventReadAttachments =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalEventReadAttachments };

static const TAknsItemID KAknsIIDQgnFsEmailCalEventReadAttachmentsHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalEventReadAttachmentsHighPrio };

static const TAknsItemID KAknsIIDQgnFsEmailCalEventReadAttachmentsLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalEventReadAttachmentsLowPrio };

static const TAknsItemID KAknsIIDQgnFsEmailCalEventReadHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalEventReadHighPrio };

static const TAknsItemID KAknsIIDQgnFsEmailCalEventReadLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalEventReadLowPrio };

static const TAknsItemID KAknsIIDQgnFsEmailCalEventUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalEventUnread };

static const TAknsItemID KAknsIIDQgnFsEmailCalEventUnreadAttachments =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalEventUnreadAttachments };

static const TAknsItemID KAknsIIDQgnFsEmailCalEventUnreadAttachmentsHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalEventUnreadAttachmentsHighPrio };

static const TAknsItemID KAknsIIDQgnFsEmailCalEventUnreadAttachmentsLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalEventUnreadAttachmentsLowPrio };

static const TAknsItemID KAknsIIDQgnFsEmailCalEventUnreadHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalEventUnreadHighPrio };

static const TAknsItemID KAknsIIDQgnFsEmailCalEventUnreadLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalEventUnreadLowPrio };

static const TAknsItemID KAknsIIDQgnFsEmailCalMarkRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalMarkRead };

static const TAknsItemID KAknsIIDQgnFsEmailCalMarkUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalMarkUnread };

static const TAknsItemID KAknsIIDQgnFsEmailCalMoveMessage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalMoveMessage };

static const TAknsItemID KAknsIIDQgnFsEmailCalMoveToDrafts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalMoveToDrafts };

static const TAknsItemID KAknsIIDQgnFsEmailCalOpenCalendar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalOpenCalendar };

static const TAknsItemID KAknsIIDQgnFsEmailCalRemoveFromCalendar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalRemoveFromCalendar };

static const TAknsItemID KAknsIIDQgnFsEmailCalReplyAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalReplyAll };

static const TAknsItemID KAknsIIDQgnFsEmailCalTentativeCalendar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailCalTentativeCalendar };

static const TAknsItemID KAknsIIDQgnFsGrafCalendarReqAreaBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafCalendarReqAreaBg };

static const TAknsItemID KAknsIIDQgnFsGrafDropL =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafDropL };

static const TAknsItemID KAknsIIDQgnFsGrafDropM =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafDropM };

static const TAknsItemID KAknsIIDQgnFsGrafDropOnepc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafDropOnepc };

static const TAknsItemID KAknsIIDQgnFsGrafDropR =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsGrafDropR };

static const TAknsItemID KAknsIIDQgnFsIndiAbout =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiAbout };

static const TAknsItemID KAknsIIDQgnFsIndiBackup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiBackup };

static const TAknsItemID KAknsIIDQgnFsIndiDefaultInbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiDefaultInbox };

static const TAknsItemID KAknsIIDQgnFsIndiFileSync =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiFileSync };

static const TAknsItemID KAknsIIDQgnFsIndiHelp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiHelp };

static const TAknsItemID KAknsIIDQgnFsIndiInfo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiInfo };

static const TAknsItemID KAknsIIDQgnFsIndiPhotoSync =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiPhotoSync };

static const TAknsItemID KAknsIIDQgnFsIndiRemoteLookup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiRemoteLookup };

static const TAknsItemID KAknsIIDQgnFsIndiRestore =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiRestore };

static const TAknsItemID KAknsIIDQgnFsIndiSettings =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiSettings };

static const TAknsItemID KAknsIIDQgnFsIndiTravelInfo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiTravelInfo };

static const TAknsItemID KAknsIIDQgnFsListItemSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsListItemSelected };

static const TAknsItemID KAknsIIDQgnFsListSelectedActionRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsListSelectedActionRight };

static const TAknsItemID KAknsIIDQgnIndiBatteryFull =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBatteryFull };

static const TAknsItemID KAknsIIDQgnIndiBatteryLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBatteryLow };

static const TAknsItemID KAknsIIDQgnIndiBatteryMid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBatteryMid };

static const TAknsItemID KAknsIIDQgnIndiBatteryPsActivate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBatteryPsActivate };

static const TAknsItemID KAknsIIDQgnIndiBatteryPsDeactivate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBatteryPsDeactivate };

static const TAknsItemID KAknsIIDQgnIndiLevelDecrease =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiLevelDecrease };

static const TAknsItemID KAknsIIDQgnIndiLevelIncrease =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiLevelIncrease };

static const TAknsItemID KAknsIIDQgnIndiOrgIconLocked =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiOrgIconLocked };

static const TAknsItemID KAknsIIDQgnIndiSwitchSct =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSwitchSct };

static const TAknsItemID KAknsIIDQgnIndiSwitchSmiley =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSwitchSmiley };

static const TAknsItemID KAknsIIDQgnIndiTbMsgDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMsgDelete };

static const TAknsItemID KAknsIIDQgnPropMceSubSenderUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubSenderUnread };

static const TAknsItemID KAknsIIDQgnPropMceSubSubjectUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubSubjectUnread };

static const TAknsItemID KAknsIIDQgnPropMceSubTimeUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceSubTimeUnread };

static const TAknsItemID KAknsIIDQgnPropSetAppsVr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsVr };

static const TAknsItemID KAknsIIDQsnFsScrollBgBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFsScrollBgBottom };

static const TAknsItemID KAknsIIDQsnFsScrollBgMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFsScrollBgMiddle };

static const TAknsItemID KAknsIIDQsnFsScrollBgTop =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFsScrollBgTop };

static const TAknsItemID KAknsIIDQsnFsScrollHandleBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFsScrollHandleBottom };

static const TAknsItemID KAknsIIDQsnFsScrollHandleMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFsScrollHandleMiddle };

static const TAknsItemID KAknsIIDQsnFsScrollHandleTop =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFsScrollHandleTop };

// ============================================================================
// ESeries specific skin constants.
// ============================================================================

/**
* Text color group for ESeries.
*
* @since 3.1
*/
static const TAknsItemID KAknsIIDFsTextColors =
    { EAknsMajorESeries, EAknsMinorESeriesTextColors };

/**
* Enumeration for values in FsTextColors color table.
*
* @since 3.1
*/
enum TAknsFsTextColorsIndex
    {
    // unfocused notifier	text on unfocused notifier	#0
    EAknsCIFsTextColorsCG1    = 0,
    // focused notifier	text on focused notifier	#0
    EAknsCIFsTextColorsCG2    = 1,
    // main area background mail/ contacts/ calendar	general not highlighted text in lists	#0
    EAknsCIFsTextColorsCG3    = 2,
    // input field	not highlighted text in inputfield	#0
    EAknsCIFsTextColorsCG4    = 3,
    // main area  background mail/ input field 	cut/copy/paste highlighted text color	#ffffff
    EAknsCIFsTextColorsCG5    = 4,
    // dropdown box	text on dropdown box	#0
    EAknsCIFsTextColorsCG6    = 5,
    // action menu background	general not highlighted text in lists	#0
    EAknsCIFsTextColorsCG7    = 6,
    // mail header area	general not highlighted text in mail header	#0
    EAknsCIFsTextColorsCG8    = 7,
    // mail header area	highlighted link text	#ffffff
    EAknsCIFsTextColorsCG9    = 8,
    // control bar	control bar area text in calendar	#0
    EAknsCIFsTextColorsCG10   = 9,
    // calendar week view background	day number text 	#0
    EAknsCIFsTextColorsCG11   = 10,
    // calendar view background	left pane text color	#0
    EAknsCIFsTextColorsCG12   = 11,
    // week view highlight	text on week view highlight	#0
    EAknsCIFsTextColorsCG13   = 12,
    // calendar event area	text on calendar event area	#0
    EAknsCIFsTextColorsCG14   = 13,
    // ALF dropdown menu	dropdown menu texts	#0
    EAknsCIFsTextColorsCG15   = 14,
    // notifier popup	unfocused texts in notifier popup	#0
    EAknsCIFsTextColorsCG16   = 15,
    // main area background calendar	current month day numbers	#0
    EAknsCIFsTextColorsCG17   = 16,
    // main area background calendar	adjacent month day numbers	#808080
    EAknsCIFsTextColorsCG18   = 17,
    // main area background calendar	anniversary  mark in current month	#FF4500
    EAknsCIFsTextColorsCG19   = 18,
    // main area background calendar	anniversary  mark in adjacent month	#F2A38B
    EAknsCIFsTextColorsCG20   = 19,
    // calendar left pane	calendar week numbers	#0
    EAknsCIFsTextColorsCG21   = 20,
    // main area background calendar	calendar day names	#0
    EAknsCIFsTextColorsCG22   = 21,
    // calendar preview pane	Calendar preview text	#0
    EAknsCIFsTextColorsCG23   = 22,
    // Contacts header /search area background Search pane editor indicator 	#0
    EAknsCIFsTextColorsCG24   = 23,
    // main area background calendar	calendar current day name	#0
    EAknsCIFsTextColorsCG25   = 24,
    // calendar week/month view background	Calender day view text color	#0
    EAknsCIFsTextColorsCG26   = 25,
    // mail area background	mail sorting header	#ffffff
    EAknsCIFsTextColorsCG27   = 26,
    // Contacts list view. Company name text.#666666
    EAknsCIFsTextColorsCG28   = 27,
    // Calendar scheduling view. Conflict in meeting request text. #ff0000
    EAknsCIFsTextColorsCG29   = 28,
    // In reserve	In reserve	#0
    EAknsCIFsTextColorsCG30   = 29,
    // In reserve	In reserve	#0
    EAknsCIFsTextColorsCG31   = 30
    };

/**
* Line color group for ESeries.
*
* @since 3.1
*/
static const TAknsItemID KAknsIIDFsLineColors =
    { EAknsMajorESeries, EAknsMinorESeriesLineColors };

/**
* Enumeration for values in FsLineColors color table.
*
* @since 3.1
*/
enum TAknsFsLineColorsIndex
    {
    // main area background mail / contacts	list seperator lines	#c7c7c7
    EAknsCIFsLineColorsCG1    = 0,
    // action menu background	action menu border	#c9c9c9
    EAknsCIFsLineColorsCG2    = 1,
    // calendar day/week/month view	calendar full hour lines  	#9b9b9b
    EAknsCIFsLineColorsCG3    = 2,
    // calendar day/week/month view	calendar half hour lines  	#a6a6a6
    EAknsCIFsLineColorsCG4    = 3,
    // calendar month view	calendar month grid line color  	#9b9b9b
    EAknsCIFsLineColorsCG5    = 4,
    // In reserve	In reserve	#0
    EAknsCIFsLineColorsCG6    = 5,
    // In reserve	In reserve	#0
    EAknsCIFsLineColorsCG7    = 6
    };

/**
* Other color group for ESeries.
*
* @since 3.1
*/
static const TAknsItemID KAknsIIDFsOtherColors =
    { EAknsMajorESeries, EAknsMinorESeriesOtherColors };

/**
* Enumeration for values in FsOtherColors color table.
*
* @since 3.1
*/
enum TAknsFsOtherColorsIndex
    {
    // dimmed main area background contacts / mail	action menu background	#ffffff
    EAknsCIFsOtherColorsCG1    = 0,
    // calendar week view background	calendar event conflict	#ffae01
    EAknsCIFsOtherColorsCG2    = 1,
    // calendar week view background	calendar event declined	#fe0000
    EAknsCIFsOtherColorsCG3    = 2,
    // calendar week view background	calendar event cancelled	#6801b8
    EAknsCIFsOtherColorsCG4    = 3,
    // calendar week view background	calendar event accepted	#0000fe
    EAknsCIFsOtherColorsCG5    = 4,
    // calendar week view background	calendar event tentative	#00cb12
    EAknsCIFsOtherColorsCG6    = 5,
    // calendar week view background	calendar event not synchronized	#e4e7eb
    EAknsCIFsOtherColorsCG7    = 6,
    // calendar week/month view background	left pane color	#ebebeb
    EAknsCIFsOtherColorsCG8    = 7,
    // main area background calendar	calendar month view bg color	#f2f2f2
    EAknsCIFsOtherColorsCG9    = 8,
    // calendar month view background	calendar bg color weekend	#b6b3b0
    EAknsCIFsOtherColorsCG10   = 9,
    // calendar month view background	calendar current day background	#cfeeff
    EAknsCIFsOtherColorsCG11   = 10,
    // calendar event details background	Meeting request text area background color	#e8e8e8
    EAknsCIFsOtherColorsCG12   = 11,
    // calendar event details background	Calendar Header area background color	#ffffff
    EAknsCIFsOtherColorsCG13   = 12,
    // calendar event details background	Calendar event focused input field border color	#0
    EAknsCIFsOtherColorsCG14   = 13,
    // calendar week/month view background	Calendar week background color	#d6d3d0
    EAknsCIFsOtherColorsCG15   = 14,
    // calendar week/month view background	Focused day background color	#ffffff
    EAknsCIFsOtherColorsCG16   = 15,
    // calendar month background	calendar month view background	#d5e6ec
    EAknsCIFsOtherColorsCG17   = 16,
    // calendar preview background	calendar day preview background	#ffffff
    EAknsCIFsOtherColorsCG18   = 17,
    // mail area background	Mail sorting header	#26a4da
    EAknsCIFsOtherColorsCG19   = 18,
    // Calendar scheduling view. Fill of the scheduling box.#ffffff
    EAknsCIFsOtherColorsCG20   = 19,
    // Calendar scheduling view.Non-working hours of the scheduling box.# ffff00
    EAknsCIFsOtherColorsCG21   = 20,
    // Calendar day view.Visual selection highlight colour.#ffe71f
    EAknsCIFsOtherColorsCG22   = 21,
    // In reserve	In reserve	#0
    EAknsCIFsOtherColorsCG23   = 22,
    // In reserve	In reserve	#0
    EAknsCIFsOtherColorsCG24   = 23
    };

/**
* Highlight color group for ESeries.
*
* @since 3.1
*/
static const TAknsItemID KAknsIIDFsHighlightColors =
    { EAknsMajorESeries, EAknsMinorESeriesHighlightColors };

/**
* Enumeration for values in FsHighlightColors color table.
*
* @since 3.1
*/
enum TAknsFsHighlightColorsIndex
    {
    // link highlight 	text on highlight	#0
    EAknsCIFsHighlightColorsCG1    = 0,
    // main background area mail 	cut/copy/paste highlight	#3bbaec
    EAknsCIFsHighlightColorsCG2    = 1,
    // mail header area 	link text	#0292ca
    EAknsCIFsHighlightColorsCG3    = 2,
    // mail header area 	highlighted link area	#3bbaec
    EAknsCIFsHighlightColorsCG4    = 3,
    // calendar week view background	Week view highlight side	#3bbaec
    EAknsCIFsHighlightColorsCG5    = 4,
    // calendar current day backgroud in month view	FS generic grid highlight	#000000
    EAknsCIFsHighlightColorsCG6    = 5,
    // In reserve	In reserve	#0
    EAknsCIFsHighlightColorsCG7    = 6,
    // In reserve	In reserve	#0
    EAknsCIFsHighlightColorsCG8    = 7
    };


static const TAknsItemID KAknsIIDQgnFscaIndiActionAnni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscaIndiActionAnni };

static const TAknsItemID KAknsIIDQgnFscaIndiActionInvitation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscaIndiActionInvitation };

static const TAknsItemID KAknsIIDQgnFscaIndiActionMeeting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscaIndiActionMeeting };

static const TAknsItemID KAknsIIDQgnFscaIndiActionMemo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscaIndiActionMemo };

static const TAknsItemID KAknsIIDQgnFscaIndiActionTodo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscaIndiActionTodo };

static const TAknsItemID KAknsIIDQgnFseActionMenuAcceptIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAcceptIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuAddToContactsIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAddToContactsIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuAttachmentListOptionsCancelAllIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAttachmentListOptionsCancelAllIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuAttachmentListOptionsRemoveAllIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAttachmentListOptionsRemoveAllIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuAttachmentListOptionsRemoveIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAttachmentListOptionsRemoveIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuAttachmentListOptionsViewAllIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAttachmentListOptionsViewAllIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuAttachCancelDownloadIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAttachCancelDownloadIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuAttachDownloadIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAttachDownloadIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuAttachSaveAllIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAttachSaveAllIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuCallIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuCallIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuContactDetailsIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuContactDetailsIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuCreateMeetingIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuCreateMeetingIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuCreateMessageIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuCreateMessageIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuDeleteIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuDeleteIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuForwardIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuForwardIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuMarkReadIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuMarkReadIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuMarkUnreadIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuMarkUnreadIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuMoveMessageIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuMoveMessageIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuMoveToDraftsIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuMoveToDraftsIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuRemoteLookupIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuRemoteLookupIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuRemoveFromCalendarIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuRemoveFromCalendarIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuReplyAllIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuReplyAllIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuReplyIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuReplyIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuTentativeIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuTentativeIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuViewCalendarIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuViewCalendarIcon };

static const TAknsItemID KAknsIIDQgnFsActionMenuAttachSaveIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionMenuAttachSaveIcon };

static const TAknsItemID KAknsIIDQgnFsCalPreviewPaneHl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsCalPreviewPaneHl };

static const TAknsItemID KAknsIIDQgnFsPropSetConnRcl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsPropSetConnRcl };

static const TAknsItemID KAknsIIDQgnFsRclActionRecipient =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsRclActionRecipient };

static const TAknsItemID KAknsIIDQgnFsRclActionSave =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsRclActionSave };

static const TAknsItemID KAknsIIDQgnFsRclSearchPane =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsRclSearchPane };

static const TAknsItemID KAknsIIDQgnGrafAdaptSearchBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAdaptSearchBg };

static const TAknsItemID KAknsIIDQgnGrafAdaptSearchPageBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafAdaptSearchPageBg };

static const TAknsItemID KAknsIIDQgnGrafFepCharTLeftDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTLeftDown };

static const TAknsItemID KAknsIIDQgnGrafFepCharTLeftDownDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTLeftDownDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepCharTLeftDownPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTLeftDownPressed };

static const TAknsItemID KAknsIIDQgnGrafFepCharTMiddleDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTMiddleDown };

static const TAknsItemID KAknsIIDQgnGrafFepCharTMiddleDownDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTMiddleDownDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepCharTMiddleDownPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTMiddleDownPressed };

static const TAknsItemID KAknsIIDQgnGrafFepCharTMiddleUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTMiddleUp };

static const TAknsItemID KAknsIIDQgnGrafFepCharTMiddleUpDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTMiddleUpDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepCharTMiddleUpPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTMiddleUpPressed };

static const TAknsItemID KAknsIIDQgnGrafFepCharTRightDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTRightDown };

static const TAknsItemID KAknsIIDQgnGrafFepCharTRightDownDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTRightDownDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepCharTRightDownPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTRightDownPressed };

static const TAknsItemID KAknsIIDQgnGrafFepCharTRightUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTRightUp };

static const TAknsItemID KAknsIIDQgnGrafFepCharTRightUpDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTRightUpDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepCharTRightUpPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharTRightUpPressed };

static const TAknsItemID KAknsIIDQgnGrafNsliderCam4Empty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCam4Empty };

static const TAknsItemID KAknsIIDQgnGrafNsliderCam4Image1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCam4Image1 };

static const TAknsItemID KAknsIIDQgnGrafNsliderCam4Image2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCam4Image2 };

static const TAknsItemID KAknsIIDQgnGrafNsliderCam4Image3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCam4Image3 };

static const TAknsItemID KAknsIIDQgnGrafNsliderCam4Image4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCam4Image4 };

static const TAknsItemID KAknsIIDQgnGrafNsliderCam4Marker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCam4Marker };

static const TAknsItemID KAknsIIDQgnGrafNsliderCam4Video1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCam4Video1 };

static const TAknsItemID KAknsIIDQgnGrafNsliderCam4Video2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCam4Video2 };

static const TAknsItemID KAknsIIDQgnGrafNsliderCam4Video3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCam4Video3 };

static const TAknsItemID KAknsIIDQgnGrafNsliderCam4Video4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCam4Video4 };

static const TAknsItemID KAknsIIDQgnGrafNsliderCam4Video5 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCam4Video5 };

static const TAknsItemID KAknsIIDQgnIndiAdaptSearchBackspace =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAdaptSearchBackspace };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbViewImages =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbViewImages };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbViewPages =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbViewPages };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbWebsearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbWebsearch };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerDown };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerDownDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerDownDimmed };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerDownPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerDownPressed };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerFire =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerFire };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerFireDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerFireDimmed };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerFirePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerFirePressed };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerLeft };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerLeftDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerLeftDimmed };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerLeftPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerLeftPressed };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerRight };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerRightDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerRightDimmed };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerRightPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerRightPressed };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerUp };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerUpDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerUpDimmed };

static const TAknsItemID KAknsIIDQgnIndiButtonJRockerUpPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonJRockerUpPressed };

static const TAknsItemID KAknsIIDQgnIndiCam4Change =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Change };

static const TAknsItemID KAknsIIDQgnIndiCam4ContrastMinus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ContrastMinus };

static const TAknsItemID KAknsIIDQgnIndiCam4ContrastPlus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ContrastPlus };

static const TAknsItemID KAknsIIDQgnIndiCam4ExposureMinus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ExposureMinus };

static const TAknsItemID KAknsIIDQgnIndiCam4ExposurePlus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ExposurePlus };

static const TAknsItemID KAknsIIDQgnIndiCam4IsoLowmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4IsoLowmed };

static const TAknsItemID KAknsIIDQgnIndiCam4IsoMedhigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4IsoMedhigh };

static const TAknsItemID KAknsIIDQgnIndiCam4Location =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Location };

static const TAknsItemID KAknsIIDQgnIndiCam4MemoryMass =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4MemoryMass };

static const TAknsItemID KAknsIIDQgnIndiCam4ModePortraitNight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ModePortraitNight };

static const TAknsItemID KAknsIIDQgnIndiCam4QualitySharing =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4QualitySharing };

static const TAknsItemID KAknsIIDQgnIndiCam4QualityWideHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4QualityWideHigh };

static const TAknsItemID KAknsIIDQgnIndiCam4SharpnessHard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4SharpnessHard };

static const TAknsItemID KAknsIIDQgnIndiCam4SharpnessNormal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4SharpnessNormal };

static const TAknsItemID KAknsIIDQgnIndiCam4SharpnessSoft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4SharpnessSoft };

static const TAknsItemID KAknsIIDQgnIndiCam4TbAddToAlbum =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbAddToAlbum };

static const TAknsItemID KAknsIIDQgnIndiCam4ViewfinderOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ViewfinderOff };

static const TAknsItemID KAknsIIDQgnIndiCam4ViewfinderOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ViewfinderOn };

static const TAknsItemID KAknsIIDQgnIndiCmodeClear =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmodeClear };

static const TAknsItemID KAknsIIDQgnIndiCmodePen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmodePen };

static const TAknsItemID KAknsIIDQgnIndiCmodeRockerDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmodeRockerDown };

static const TAknsItemID KAknsIIDQgnIndiCmodeRockerLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmodeRockerLeft };

static const TAknsItemID KAknsIIDQgnIndiCmodeRockerRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmodeRockerRight };

static const TAknsItemID KAknsIIDQgnIndiCmodeRockerSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmodeRockerSelect };

static const TAknsItemID KAknsIIDQgnIndiCmodeRockerUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmodeRockerUp };

static const TAknsItemID KAknsIIDQgnIndiFepButtonBackspaceWide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonBackspaceWide };

static const TAknsItemID KAknsIIDQgnIndiFepButtonBackspaceWideSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonBackspaceWideSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseNumericSpecial =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseNumericSpecial };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseNumericSpecialSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseNumericSpecialSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCloseWide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCloseWide };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCloseWideSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCloseWideSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCursorLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCursorLeft };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCursorLeftSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCursorLeftSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCursorRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCursorRight };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCursorRightSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCursorRightSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonOptionsWide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonOptionsWide };

static const TAknsItemID KAknsIIDQgnIndiFepButtonOptionsWideSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonOptionsWideSel };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSmileys =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSmileys };

static const TAknsItemID KAknsIIDQgnIndiFepButtonSmileysSel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonSmileysSel };

static const TAknsItemID KAknsIIDQgnIndiGameA =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiGameA };

static const TAknsItemID KAknsIIDQgnIndiGameB =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiGameB };

static const TAknsItemID KAknsIIDQgnIndiGameC =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiGameC };

static const TAknsItemID KAknsIIDQgnIndiGameD =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiGameD };

static const TAknsItemID KAknsIIDQgnIndiItutBackspace =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiItutBackspace };

static const TAknsItemID KAknsIIDQgnIndiItutClose =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiItutClose };

static const TAknsItemID KAknsIIDQgnIndiItutOptions =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiItutOptions };

static const TAknsItemID KAknsIIDQgnIndiLskHorizontal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiLskHorizontal };

static const TAknsItemID KAknsIIDQgnIndiNsliderCam4Minus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiNsliderCam4Minus };

static const TAknsItemID KAknsIIDQgnIndiNsliserCam4Plus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiNsliserCam4Plus };

static const TAknsItemID KAknsIIDQgnIndiRskHorizontal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRskHorizontal };

static const TAknsItemID KAknsIIDQgnIndiSctrlMaskInactPrt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSctrlMaskInactPrt };

static const TAknsItemID KAknsIIDQgnIndiSctClose =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSctClose };

static const TAknsItemID KAknsIIDQgnIndiSctPageNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSctPageNext };

static const TAknsItemID KAknsIIDQgnIndiSctPagePrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSctPagePrev };

static const TAknsItemID KAknsIIDQgnIndiSmileyAngry =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAngry };

static const TAknsItemID KAknsIIDQgnIndiSmileyBigsmile =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyBigsmile };

static const TAknsItemID KAknsIIDQgnIndiSmileyCry =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyCry };

static const TAknsItemID KAknsIIDQgnIndiSmileyEvil =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyEvil };

static const TAknsItemID KAknsIIDQgnIndiSmileyEyebrows =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyEyebrows };

static const TAknsItemID KAknsIIDQgnIndiSmileyHeart =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyHeart };

static const TAknsItemID KAknsIIDQgnIndiSmileyIrritated =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyIrritated };

static const TAknsItemID KAknsIIDQgnIndiSmileyKissing =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyKissing };

static const TAknsItemID KAknsIIDQgnIndiSmileyNerd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyNerd };

static const TAknsItemID KAknsIIDQgnIndiSmileyNeutral =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyNeutral };

static const TAknsItemID KAknsIIDQgnIndiSmileyPirate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyPirate };

static const TAknsItemID KAknsIIDQgnIndiSmileySarcastic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileySarcastic };

static const TAknsItemID KAknsIIDQgnIndiSmileySarcasticMad =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileySarcasticMad };

static const TAknsItemID KAknsIIDQgnIndiSmileySmile =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileySmile };

static const TAknsItemID KAknsIIDQgnIndiSmileySpring =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileySpring };

static const TAknsItemID KAknsIIDQgnIndiSmileySuprised =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileySuprised };

static const TAknsItemID KAknsIIDQgnIndiSmileyTongue =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyTongue };

static const TAknsItemID KAknsIIDQgnIndiSmileyUnhappy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyUnhappy };

static const TAknsItemID KAknsIIDQgnIndiSmileyVerycool =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyVerycool };

static const TAknsItemID KAknsIIDQgnIndiSmileyWink =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyWink };

static const TAknsItemID KAknsIIDQgnIndiSmileyWinkGrin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyWinkGrin };

static const TAknsItemID KAknsIIDQgnIndiSmileyWondering =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyWondering };

static const TAknsItemID KAknsIIDQgnMenuWlanLogon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuWlanLogon };

static const TAknsItemID KAknsIIDQgnStatFmtxOffUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatFmtxOffUni };

static const TAknsItemID KAknsIIDQgnStatFmtxOnUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatFmtxOnUni };

static const TAknsItemID KAknsIIDQgnStatInputPred =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatInputPred };

static const TAknsItemID KAknsIIDQgnVoipOnlineStatusPending =
    { EAknsMajorGeneric, EAknsMinorGenericQgnVoipOnlineStatusPending };

static const TAknsItemID KAknsIIDQgnEsGrafMshopIconApp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEsGrafMshopIconApp };

static const TAknsItemID KAknsIIDQgnEsGrafMshopIconCtx =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEsGrafMshopIconCtx };

static const TAknsItemID KAknsIIDQgnEsGrafNpodaApp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEsGrafNpodaApp };

static const TAknsItemID KAknsIIDQgnEsMenuGroupComms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEsMenuGroupComms };

static const TAknsItemID KAknsIIDQgnEsMenuGroupGps =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEsMenuGroupGps };

static const TAknsItemID KAknsIIDQgnEsMenuGroupHelp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEsMenuGroupHelp };

static const TAknsItemID KAknsIIDQgnEsMenuGroupOffice =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEsMenuGroupOffice };

static const TAknsItemID KAknsIIDQgnEsMenuMobilesearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEsMenuMobilesearch };

static const TAknsItemID KAknsIIDQgnEsMenuPrintserverCxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEsMenuPrintserverCxt };

static const TAknsItemID KAknsIIDQgnEsMenuPubCxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEsMenuPubCxt };

static const TAknsItemID KAknsIIDQgnEsMenuPubLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnEsMenuPubLst };

static const TAknsItemID KAknsIIDQgnFscalIndiWeekLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiWeekLeft };

static const TAknsItemID KAknsIIDQgnFscalIndiWeekRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFscalIndiWeekRight };

static const TAknsItemID KAknsIIDQgnFseActionMenuAttachmentListOptionsAddIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAttachmentListOptionsAddIcon };

static const TAknsItemID KAknsIIDQgnFseActionMenuDeclineIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuDeclineIcon };

static const TAknsItemID KAknsIIDQgnFsEmailLauncherGridInboxIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsEmailLauncherGridInboxIcon };

static const TAknsItemID KAknsIIDQgnFsMeetReqIndiDateAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsMeetReqIndiDateAlarm };

static const TAknsItemID KAknsIIDQgnGrafMupNpvDefalbumart =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupNpvDefalbumart };

static const TAknsItemID KAknsIIDQgnGrafMupPodcastArt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMupPodcastArt };

static const TAknsItemID KAknsIIDQgnGrafOrgBgGrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafOrgBgGrid };

static const TAknsItemID KAknsIIDQgnGrafOrgBgList =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafOrgBgList };

static const TAknsItemID KAknsIIDQgnGrafRkmAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafRkmAll };

static const TAknsItemID KAknsIIDQgnGrafRkmAllDim =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafRkmAllDim };

static const TAknsItemID KAknsIIDQgnGrafRkmPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafRkmPause };

static const TAknsItemID KAknsIIDQgnGrafRkmPauseNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafRkmPauseNext };

static const TAknsItemID KAknsIIDQgnGrafRkmPausePrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafRkmPausePrev };

static const TAknsItemID KAknsIIDQgnGrafRkmPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafRkmPlay };

static const TAknsItemID KAknsIIDQgnGrafRkmPlayNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafRkmPlayNext };

static const TAknsItemID KAknsIIDQgnGrafRkmPlayPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafRkmPlayPrev };

static const TAknsItemID KAknsIIDQgnGrafRkmStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafRkmStop };

static const TAknsItemID KAknsIIDQgnGrafRkmStopNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafRkmStopNext };

static const TAknsItemID KAknsIIDQgnGrafRkmStopPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafRkmStopPrev };

static const TAknsItemID KAknsIIDQgnIndiCall4ImageMaskLsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCall4ImageMaskLsc };

static const TAknsItemID KAknsIIDQgnIndiCall4ImageMaskPrt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCall4ImageMaskPrt };

static const TAknsItemID KAknsIIDQgnIndiInputCharNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCharNext };

static const TAknsItemID KAknsIIDQgnIndiInputCharPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCharPrev };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimCoffee =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimCoffee };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimConnive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimConnive };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimDenial =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimDenial };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimFlirt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimFlirt };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimFrustrated =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimFrustrated };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimGum =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimGum };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimIdea =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimIdea };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimInnocent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimInnocent };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimLaugh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimLaugh };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimParty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimParty };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimRun =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimRun };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimSilly =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimSilly };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimSleep =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimSleep };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimSurprised =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimSurprised };

static const TAknsItemID KAknsIIDQgnIndiTbChangeStatus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbChangeStatus };

static const TAknsItemID KAknsIIDQgnIndiTbCharGrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCharGrid };

static const TAknsItemID KAknsIIDQgnIndiTbConversation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbConversation };

static const TAknsItemID KAknsIIDQgnIndiTbEditModel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbEditModel };

static const TAknsItemID KAknsIIDQgnIndiTbModelPreview =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbModelPreview };

static const TAknsItemID KAknsIIDQgnIndiTbRemove =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRemove };

static const TAknsItemID KAknsIIDQgnIndiTbSmiley =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbSmiley };

static const TAknsItemID KAknsIIDQgnIndiTbVoip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbVoip };

static const TAknsItemID KAknsIIDQgnIndiTpVoip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpVoip };

static const TAknsItemID KAknsIIDQgnIndiVoipOnlineStatusAvailable =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVoipOnlineStatusAvailable };

static const TAknsItemID KAknsIIDQgnIndiVoipOnlineStatusBlocked =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVoipOnlineStatusBlocked };

static const TAknsItemID KAknsIIDQgnIndiVoipOnlineStatusOffline =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVoipOnlineStatusOffline };

static const TAknsItemID KAknsIIDQgnIndiWmlFlashBroken =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWmlFlashBroken };

static const TAknsItemID KAknsIIDQgnPropNrtypVoice =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypVoice };

static const TAknsItemID KAknsIIDQgnPropServiceTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropServiceTab4 };

static const TAknsItemID KAknsIIDQgnPropXspVoipReadyTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropXspVoipReadyTab2 };

static const TAknsItemID KAknsIIDQgnIndiCdrBirthdayMissedNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrBirthdayMissedNew };

static const TAknsItemID KAknsIIDQgnIndiCdrMeetingMissedNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrMeetingMissedNew };

static const TAknsItemID KAknsIIDQgnIndiCdrReminderMissedNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrReminderMissedNew };

static const TAknsItemID KAknsIIDQgnIndiCdrTodoUndone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrTodoUndone };

static const TAknsItemID KAknsIIDQgnIndiCdrTodoUndoneMissedNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrTodoUndoneMissedNew };

static const TAknsItemID KAknsIIDQgnIndiImedFreedraw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedFreedraw };

static const TAknsItemID KAknsIIDQgnIndiImedFreedrawCursorSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedFreedrawCursorSuper };

static const TAknsItemID KAknsIIDQgnIndiSwitchSct2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSwitchSct2 };

static const TAknsItemID KAknsIIDQgnIndiSwitchSmiley2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSwitchSmiley2 };

static const TAknsItemID KAknsIIDQgnIndiTbCaleAlarmDismiss =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCaleAlarmDismiss };

static const TAknsItemID KAknsIIDQgnIndiTbCaleAlarmDismissAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCaleAlarmDismissAll };

static const TAknsItemID KAknsIIDQgnMenuMupsv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMupsv };

static const TAknsItemID KAknsIIDQgnNoteMupsv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteMupsv };

static const TAknsItemID KAknsIIDQgnPropImageTbSend2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbSend2 };

static const TAknsItemID KAknsIIDQgnPropImageTbSend2Dimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbSend2Dimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbSend2Focused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbSend2Focused };

static const TAknsItemID KAknsIIDQgnPropUsbMemc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropUsbMemc };

static const TAknsItemID KAknsIIDQgnPropUsbMemcLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropUsbMemcLarge };

static const TAknsItemID KAknsIIDQgnPropUsbMemcSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropUsbMemcSub };

static const TAknsItemID KAknsIIDQgnPropUsbMemcTab =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropUsbMemcTab };

static const TAknsItemID KAknsIIDQgnPropUsbMemcTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropUsbMemcTab2 };

static const TAknsItemID KAknsIIDQgnStatCaleUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaleUni };

static const TAknsItemID KAknsIIDQgnStatUsbMemcConnectUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatUsbMemcConnectUni };

static const TAknsItemID KAknsIIDQgnStatUsbMemcTransferUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatUsbMemcTransferUni };

static const TAknsItemID KAknsIIDQgnFseFolderListOutboxIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseFolderListOutboxIcon };

static const TAknsItemID KAknsIIDQgnFseFolderListSentIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseFolderListSentIcon };

static const TAknsItemID KAknsIIDQgnFseMailUnreadRepliedHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadRepliedHighPrio };

static const TAknsItemID KAknsIIDQgnFseMailUnreadRepliedLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseMailUnreadRepliedLowPrio };

static const TAknsItemID KAknsIIDQgnIndiBtBlocked =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBtBlocked };

static const TAknsItemID KAknsIIDQgnIndiCam4Gridviewer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Gridviewer };

static const TAknsItemID KAknsIIDQgnIndiCam4Selftimer2sec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Selftimer2sec };

static const TAknsItemID KAknsIIDQgnIndiImedFreedraw10pix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedFreedraw10pix };

static const TAknsItemID KAknsIIDQgnIndiImedFreedraw15pix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedFreedraw15pix };

static const TAknsItemID KAknsIIDQgnIndiImedFreedraw20pix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedFreedraw20pix };

static const TAknsItemID KAknsIIDQgnIndiImedFreedraw3pix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedFreedraw3pix };

static const TAknsItemID KAknsIIDQgnIndiImedFreedraw5pix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedFreedraw5pix };

static const TAknsItemID KAknsIIDQgnIndiNsliderLevelDecrease =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiNsliderLevelDecrease };

static const TAknsItemID KAknsIIDQgnIndiNsliderLevelIncrease =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiNsliderLevelIncrease };

static const TAknsItemID KAknsIIDQgnIndiNsliderMuted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiNsliderMuted };

static const TAknsItemID KAknsIIDQgnIndiNsliderUnmuted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiNsliderUnmuted };

static const TAknsItemID KAknsIIDQgnIndiNsliderZoomIn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiNsliderZoomIn };

static const TAknsItemID KAknsIIDQgnIndiNsliderZoomOut =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiNsliderZoomOut };

static const TAknsItemID KAknsIIDQgnIndiVid4Audio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4Audio };

static const TAknsItemID KAknsIIDQgnIndiVid4LightOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4LightOff };

static const TAknsItemID KAknsIIDQgnIndiVid4Video =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4Video };

static const TAknsItemID KAknsIIDQgnMeetReqIndiDateAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMeetReqIndiDateAlarm };

static const TAknsItemID KAknsIIDQgnPropSetService =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetService };

static const TAknsItemID KAknsIIDQgnPropSetVoipAdvanced =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetVoipAdvanced };

static const TAknsItemID KAknsIIDQgnPropVoipNewService =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVoipNewService };

static const TAknsItemID KAknsIIDQgnGrafBlid2dfix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlid2dfix };

static const TAknsItemID KAknsIIDQgnGrafBlid3dfix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlid3dfix };

static const TAknsItemID KAknsIIDQgnGrafLineVerticalFade =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafLineVerticalFade };

static const TAknsItemID KAknsIIDQgnGrafNsliderVded2EndLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVded2EndLeft };

static const TAknsItemID KAknsIIDQgnGrafNsliderVded2EndLeftSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVded2EndLeftSelected };

static const TAknsItemID KAknsIIDQgnGrafNsliderVded2EndRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVded2EndRight };

static const TAknsItemID KAknsIIDQgnGrafNsliderVded2EndRightSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVded2EndRightSelected };

static const TAknsItemID KAknsIIDQgnGrafNsliderVded2Middle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVded2Middle };

static const TAknsItemID KAknsIIDQgnGrafNsliderVded2MiddleSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVded2MiddleSelected };

static const TAknsItemID KAknsIIDQgnIndiCam4TbLightOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbLightOff };

static const TAknsItemID KAknsIIDQgnIndiInputCaseAccented =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseAccented };

static const TAknsItemID KAknsIIDQgnIndiInputCaseCapital =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseCapital };

static const TAknsItemID KAknsIIDQgnIndiInputCaseCapitalCyrillic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseCapitalCyrillic };

static const TAknsItemID KAknsIIDQgnIndiInputCaseCapitalGreek =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseCapitalGreek };

static const TAknsItemID KAknsIIDQgnIndiInputCaseNumeric =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseNumeric };

static const TAknsItemID KAknsIIDQgnIndiInputCaseSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseSmall };

static const TAknsItemID KAknsIIDQgnIndiInputCaseSmallCyrillic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseSmallCyrillic };

static const TAknsItemID KAknsIIDQgnIndiInputCaseSmallGreek =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseSmallGreek };

static const TAknsItemID KAknsIIDQgnIndiInputCaseSpecial =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseSpecial };

static const TAknsItemID KAknsIIDQgnIndiInputCaseTextHebrew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseTextHebrew };

static const TAknsItemID KAknsIIDQgnIndiLskVertical =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiLskVertical };

static const TAknsItemID KAknsIIDQgnIndiRskVertical =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRskVertical };

static const TAknsItemID KAknsIIDQgnIndiTbBthf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbBthf };

static const TAknsItemID KAknsIIDQgnIndiTbHandset =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbHandset };

static const TAknsItemID KAknsIIDQgnIndiVded2End =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVded2End };

static const TAknsItemID KAknsIIDQgnIndiVded2Play =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVded2Play };

static const TAknsItemID KAknsIIDQgnIndiVded2Playhead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVded2Playhead };

static const TAknsItemID KAknsIIDQgnIndiVded2Start =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVded2Start };

static const TAknsItemID KAknsIIDQgnIndiVorecBiForw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecBiForw };

static const TAknsItemID KAknsIIDQgnIndiVorecBiPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecBiPause };

static const TAknsItemID KAknsIIDQgnIndiVorecBiPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecBiPlay };

static const TAknsItemID KAknsIIDQgnIndiVorecBiRec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecBiRec };

static const TAknsItemID KAknsIIDQgnIndiVorecBiRew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecBiRew };

static const TAknsItemID KAknsIIDQgnIndiVorecBiStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVorecBiStop };

static const TAknsItemID KAknsIIDQgnPropHwrtrainingShortcutNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHwrtrainingShortcutNew };

static const TAknsItemID KAknsIIDQgnPropHwrtrainingShortcutTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHwrtrainingShortcutTab2 };

static const TAknsItemID KAknsIIDQgnPropHwrtrainingTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHwrtrainingTab2 };

static const TAknsItemID KAknsIIDQgnStatCtrl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCtrl };

static const TAknsItemID KAknsIIDQgnStatStrg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatStrg };

static const TAknsItemID KAknsIIDQgnFsActionPostcard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionPostcard };

static const TAknsItemID KAknsIIDQgnGrafBlidDetCircle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidDetCircle };

static const TAknsItemID KAknsIIDQgnGrafBlidInfo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidInfo };

static const TAknsItemID KAknsIIDQgnGrafBlidNorth =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidNorth };

static const TAknsItemID KAknsIIDQgnGrafBlidRing =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidRing };

static const TAknsItemID KAknsIIDQgnGrafBlidSpwatch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSpwatch };

static const TAknsItemID KAknsIIDQgnGrafBlidTime =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidTime };

static const TAknsItemID KAknsIIDQgnGrafBlidTpmeter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidTpmeter };

static const TAknsItemID KAknsIIDQgnGrafBlidTpPointer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidTpPointer };

static const TAknsItemID KAknsIIDQgnIndiBrowserFeedsTbBackToWeb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserFeedsTbBackToWeb };

static const TAknsItemID KAknsIIDQgnIndiBrowserFeedsTbNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserFeedsTbNext };

static const TAknsItemID KAknsIIDQgnIndiBrowserFeedsTbOpenDetail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserFeedsTbOpenDetail };

static const TAknsItemID KAknsIIDQgnIndiBrowserFeedsTbOpenFull =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserFeedsTbOpenFull };

static const TAknsItemID KAknsIIDQgnIndiBrowserFeedsTbOpenTopic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserFeedsTbOpenTopic };

static const TAknsItemID KAknsIIDQgnIndiBrowserFeedsTbPrevious =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserFeedsTbPrevious };

static const TAknsItemID KAknsIIDQgnIndiBrowserFeedsTbUpdate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserFeedsTbUpdate };

static const TAknsItemID KAknsIIDQgnIndiBrowserFeedsTbUpdateAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserFeedsTbUpdateAll };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbFindKwNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbFindKwNext };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbFindKwPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbFindKwPrev };

static const TAknsItemID KAknsIIDQgnIndiSignalOffline =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalOffline };

static const TAknsItemID KAknsIIDQgnPropImageTbStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbStop };

static const TAknsItemID KAknsIIDQgnPropImageTbStopDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbStopDimmed };

static const TAknsItemID KAknsIIDQgnPropImageTbStopFocused =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImageTbStopFocused };

static const TAknsItemID KAknsIIDQgnIndiCam4Selftimer2s =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Selftimer2s };

static const TAknsItemID KAknsIIDQgnIndiEditVidpict =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiEditVidpict };

static const TAknsItemID KAknsIIDQgnIndiImageDrmInvalidSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImageDrmInvalidSuper };

static const TAknsItemID KAknsIIDQgnIndiImageDrmValidSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImageDrmValidSuper };

static const TAknsItemID KAknsIIDQgnIndiImedPosterize =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedPosterize };

static const TAknsItemID KAknsIIDQgnIndiItutListCollapse =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiItutListCollapse };

static const TAknsItemID KAknsIIDQgnIndiItutListExpand =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiItutListExpand };

static const TAknsItemID KAknsIIDQgnIndiTake5ButtonCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTake5ButtonCall };

static const TAknsItemID KAknsIIDQgnIndiTake5ButtonClose =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTake5ButtonClose };

static const TAknsItemID KAknsIIDQgnIndiTake5ButtonMail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTake5ButtonMail };

static const TAknsItemID KAknsIIDQgnIndiTake5ButtonSettings =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTake5ButtonSettings };

static const TAknsItemID KAknsIIDQgnIndiTake5ButtonUpdate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTake5ButtonUpdate };

static const TAknsItemID KAknsIIDQgnIndiTake5EventNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTake5EventNew };

static const TAknsItemID KAknsIIDQgnIndiTake5RssAudio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTake5RssAudio };

static const TAknsItemID KAknsIIDQgnIndiTake5RssImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTake5RssImage };

static const TAknsItemID KAknsIIDQgnIndiTake5RssProvider =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTake5RssProvider };

static const TAknsItemID KAknsIIDQgnIndiTake5RssText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTake5RssText };

static const TAknsItemID KAknsIIDQgnIndiTake5RssUnknown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTake5RssUnknown };

static const TAknsItemID KAknsIIDQgnIndiTake5RssVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTake5RssVideo };

static const TAknsItemID KAknsIIDQgnIndiTbFmgrDetail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFmgrDetail };

static const TAknsItemID KAknsIIDQgnIndiTbFmgrEject =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFmgrEject };

static const TAknsItemID KAknsIIDQgnIndiTbFmgrSort =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFmgrSort };

static const TAknsItemID KAknsIIDQgnIndiXmediabarBrowser =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarBrowser };

static const TAknsItemID KAknsIIDQgnIndiXmediabarBrowserActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarBrowserActive };

static const TAknsItemID KAknsIIDQgnIndiXmediabarBrowserPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarBrowserPressed };

static const TAknsItemID KAknsIIDQgnIndiXmediabarImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarImage };

static const TAknsItemID KAknsIIDQgnIndiXmediabarImageActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarImageActive };

static const TAknsItemID KAknsIIDQgnIndiXmediabarImagePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarImagePressed };

static const TAknsItemID KAknsIIDQgnIndiXmediabarMusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarMusic };

static const TAknsItemID KAknsIIDQgnIndiXmediabarMusicActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarMusicActive };

static const TAknsItemID KAknsIIDQgnIndiXmediabarMusicPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarMusicPressed };

static const TAknsItemID KAknsIIDQgnIndiXmediabarShareonline =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarShareonline };

static const TAknsItemID KAknsIIDQgnIndiXmediabarShareonlineActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarShareonlineActive };

static const TAknsItemID KAknsIIDQgnIndiXmediabarShareonlinePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarShareonlinePressed };

static const TAknsItemID KAknsIIDQgnIndiXmediabarVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarVideo };

static const TAknsItemID KAknsIIDQgnIndiXmediabarVideoActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarVideoActive };

static const TAknsItemID KAknsIIDQgnIndiXmediabarVideoPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiXmediabarVideoPressed };

static const TAknsItemID KAknsIIDQgnPropCam4Codec3gp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCam4Codec3gp };

static const TAknsItemID KAknsIIDQgnPropCam4CodecMp4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCam4CodecMp4 };

static const TAknsItemID KAknsIIDQgnPropSetAppsCmode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsCmode };

static const TAknsItemID KAknsIIDQgnPropSwupdFailed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSwupdFailed };

static const TAknsItemID KAknsIIDQgnPropTake5AddNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropTake5AddNew };

static const TAknsItemID KAknsIIDQgnPropTake5Contacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropTake5Contacts };

static const TAknsItemID KAknsIIDQgnPropTake5Dialer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropTake5Dialer };

static const TAknsItemID KAknsIIDQgnPropTake5Dismiss =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropTake5Dismiss };

static const TAknsItemID KAknsIIDQgnPropTake5Remind =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropTake5Remind };

static const TAknsItemID KAknsIIDQgnPropXmediabar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropXmediabar };

static const TAknsItemID KAknsIIDQgnStatMessageSorted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatMessageSorted };

static const TAknsItemID KAknsIIDQsnFrItutScrollBg =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutScrollBg };
    
static const TAknsItemID KAknsIIDQgnGrafTake5TabBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTake5TabBg };
    
static const TAknsItemID KAknsIIDQgnGrafTake5TabBgMask =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTake5TabBgMask };    
    
static const TAknsItemID KAknsIIDQgnGrafTake5TabBgAddNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTake5TabBgAddNew };
    
static const TAknsItemID KAknsIIDQgnGrafTake5TabBgLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTake5TabBgLeft };  

static const TAknsItemID KAknsIIDQgnGrafTake5TabBgLeftMask =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTake5TabBgLeftMask };  

static const TAknsItemID KAknsIIDQgnGrafTake5TabBgMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTake5TabBgMiddle };  

static const TAknsItemID KAknsIIDQgnGrafTake5TabBgMiddleMask =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTake5TabBgMiddleMask };  

static const TAknsItemID KAknsIIDQgnGrafTake5TabBgRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTake5TabBgRight };  

static const TAknsItemID KAknsIIDQgnGrafTake5TabBgRightMask =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafTake5TabBgRightMask };  

static const TAknsItemID KAknsIIDQsnFrButtonHighlight =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrButtonHighlight };  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightCornerTl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrButtonHighlightCornerTl };  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightCornerTr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrButtonHighlightCornerTr };  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightCornerBl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrButtonHighlightCornerBl };  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightCornerBr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrButtonHighlightCornerBr };  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightSideT =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrButtonHighlightSideT };  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightSideB =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrButtonHighlightSideB };  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrButtonHighlightSideL };  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrButtonHighlightSideR };  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrButtonHighlightCenter };  

static const TAknsItemID KAknsIIDQsnFrItutButtonCandiMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutButtonCandiMiddle };  

static const TAknsItemID KAknsIIDQsnFrItutButtonCandiSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutButtonCandiSideL };  

static const TAknsItemID KAknsIIDQsnFrItutButtonCandiSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutButtonCandiSideR };  

static const TAknsItemID KAknsIIDQsnFrItutButtonComposeMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutButtonComposeMiddle };  

static const TAknsItemID KAknsIIDQsnFrItutButtonComposeSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutButtonComposeSideL };  

static const TAknsItemID KAknsIIDQsnFrItutButtonComposeSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutButtonComposeSideR };  

static const TAknsItemID KAknsIIDQgnGrafBlidRingfix =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidRingfix };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TLeftDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TLeftDown };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TLeftDownDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TLeftDownDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TLeftDownPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TLeftDownPressed };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TMiddleDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TMiddleDown };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TMiddleDownDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TMiddleDownDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TMiddleDownPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TMiddleDownPressed };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TMiddleUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TMiddleUp };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TMiddleUpDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TMiddleUpDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TMiddleUpPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TMiddleUpPressed };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TRightDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TRightDown };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TRightDownDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TRightDownDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TRightDownPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TRightDownPressed };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TRightUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TRightUp };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TRightUpDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TRightUpDimmed };

static const TAknsItemID KAknsIIDQgnGrafFepChar2TRightUpPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepChar2TRightUpPressed };

static const TAknsItemID KAknsIIDQgnGrafInputBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafInputBg };

static const TAknsItemID KAknsIIDQgnGrafInputIcfBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafInputIcfBg };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbFull =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbFull };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbHistoryBack =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbHistoryBack };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbHistoryFw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbHistoryFw };

static const TAknsItemID KAknsIIDQgnIndiButtonExitFs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonExitFs };

static const TAknsItemID KAknsIIDQgnIndiInputArrowDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputArrowDown };

static const TAknsItemID KAknsIIDQgnIndiInputArrowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputArrowUp };

static const TAknsItemID KAknsIIDQgnIndiInputBackspace =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputBackspace };

static const TAknsItemID KAknsIIDQgnIndiInputButtonMode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputButtonMode };

static const TAknsItemID KAknsIIDQgnIndiInputCandiListClose =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCandiListClose };

static const TAknsItemID KAknsIIDQgnIndiInputCapslock =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCapslock };

static const TAknsItemID KAknsIIDQgnIndiInputCaseAccentedCyrillic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseAccentedCyrillic };

static const TAknsItemID KAknsIIDQgnIndiInputCaseAllTypesJapanese =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseAllTypesJapanese };

static const TAknsItemID KAknsIIDQgnIndiInputCaseNumericArabicIndic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseNumericArabicIndic };

static const TAknsItemID KAknsIIDQgnIndiInputCaseNumericDevanagari =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseNumericDevanagari };

static const TAknsItemID KAknsIIDQgnIndiInputCaseNumericSpecial =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseNumericSpecial };

static const TAknsItemID KAknsIIDQgnIndiInputCaseNumericThai =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseNumericThai };

static const TAknsItemID KAknsIIDQgnIndiInputCaseText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseText };

static const TAknsItemID KAknsIIDQgnIndiInputCaseTextArabic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseTextArabic };

static const TAknsItemID KAknsIIDQgnIndiInputCaseTextCyrillic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseTextCyrillic };

static const TAknsItemID KAknsIIDQgnIndiInputCaseTextGreek =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseTextGreek };

static const TAknsItemID KAknsIIDQgnIndiInputCaseTextHindi =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseTextHindi };

static const TAknsItemID KAknsIIDQgnIndiInputCaseTextThai =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseTextThai };

static const TAknsItemID KAknsIIDQgnIndiInputChinese =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputChinese };

static const TAknsItemID KAknsIIDQgnIndiInputClear =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputClear };

static const TAknsItemID KAknsIIDQgnIndiInputClose =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputClose };

static const TAknsItemID KAknsIIDQgnIndiInputConvertToKanji =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputConvertToKanji };

static const TAknsItemID KAknsIIDQgnIndiInputEnter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputEnter };

static const TAknsItemID KAknsIIDQgnIndiInputHiragana =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputHiragana };

static const TAknsItemID KAknsIIDQgnIndiInputKatakana =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputKatakana };

static const TAknsItemID KAknsIIDQgnIndiInputMove =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputMove };

static const TAknsItemID KAknsIIDQgnIndiInputOptions =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputOptions };

static const TAknsItemID KAknsIIDQgnIndiInputShift =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputShift };

static const TAknsItemID KAknsIIDQgnIndiInputSmileys =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputSmileys };

static const TAknsItemID KAknsIIDQgnIndiInputSpaceL =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputSpaceL };

static const TAknsItemID KAknsIIDQgnIndiInputSpaceMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputSpaceMiddle };

static const TAknsItemID KAknsIIDQgnIndiInputSpaceR =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputSpaceR };

static const TAknsItemID KAknsIIDQgnIndiInputSwitcher =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputSwitcher };

static const TAknsItemID KAknsIIDQgnPropFileRssError =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFileRssError };

static const TAknsItemID KAknsIIDQgnPropFolderRssError =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderRssError };

static const TAknsItemID KAknsIIDQsnFrKeypadButton2Inactive =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrKeypadButton2Inactive };

static const TAknsItemID KAknsIIDQsnFrKeypadButton2Normal =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrKeypadButton2Normal };

static const TAknsItemID KAknsIIDQsnFrKeypadButton2Pressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrKeypadButton2Pressed };

static const TAknsItemID KAknsIIDQsnFrKeypadButtonInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrKeypadButtonInactive };

static const TAknsItemID KAknsIIDQsnFrKeypadButtonNormal =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrKeypadButtonNormal };

static const TAknsItemID KAknsIIDQsnFrKeypadButtonPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrKeypadButtonPressed };


    // Option item frame 1
static const TAknsItemID KAknsIIDQsnFrTake5 =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5 };

static const TAknsItemID KAknsIIDQsnFrTake5CornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5CornerTl };

static const TAknsItemID KAknsIIDQsnFrTake5CornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5CornerTr };

static const TAknsItemID KAknsIIDQsnFrTake5CornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5CornerBl };

static const TAknsItemID KAknsIIDQsnFrTake5CornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5CornerBr };

static const TAknsItemID KAknsIIDQsnFrTake5SideT =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5SideT };

static const TAknsItemID KAknsIIDQsnFrTake5SideB =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5SideB };

static const TAknsItemID KAknsIIDQsnFrTake5SideL =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5SideL };

static const TAknsItemID KAknsIIDQsnFrTake5SideR =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5SideR };

static const TAknsItemID KAknsIIDQsnFrTake5Center =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Center };
    
    // Option item frame 2
static const TAknsItemID KAknsIIDQsnFrTake52 =
    { EAknsMajorSkin, EAknsMinorQsnFrTake52 };

static const TAknsItemID KAknsIIDQsnFrTake5Corner2Tl =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Corner2Tl };

static const TAknsItemID KAknsIIDQsnFrTake5Corner2Tr =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Corner2Tr };

static const TAknsItemID KAknsIIDQsnFrTake5Corner2Bl =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Corner2Bl };

static const TAknsItemID KAknsIIDQsnFrTake5Corner2Br =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Corner2Br };

static const TAknsItemID KAknsIIDQsnFrTake5Side2T =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Side2T };

static const TAknsItemID KAknsIIDQsnFrTake5Side2B =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Side2B };

static const TAknsItemID KAknsIIDQsnFrTake5Side2L =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Side2L };

static const TAknsItemID KAknsIIDQsnFrTake5Side2R =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Side2R };

static const TAknsItemID KAknsIIDQsnFrTake5Center2 =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Center2 };
    
    
    
    
    // Option item frame 3
static const TAknsItemID KAknsIIDQsnFrTake53 =
    { EAknsMajorSkin, EAknsMinorQsnFrTake53 };

static const TAknsItemID KAknsIIDQsnFrTake5Corner3Tl =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Corner3Tl };

static const TAknsItemID KAknsIIDQsnFrTake5Corner3Tr =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Corner3Tr };

static const TAknsItemID KAknsIIDQsnFrTake5Corner3Bl =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Corner3Bl };

static const TAknsItemID KAknsIIDQsnFrTake5Corner3Br =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Corner3Br };

static const TAknsItemID KAknsIIDQsnFrTake5Side3T =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Side3T };

static const TAknsItemID KAknsIIDQsnFrTake5Side3B =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Side3B };

static const TAknsItemID KAknsIIDQsnFrTake5Side3L =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Side3L };

static const TAknsItemID KAknsIIDQsnFrTake5Side3R =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Side3R };

static const TAknsItemID KAknsIIDQsnFrTake5Center3 =
    { EAknsMajorSkin, EAknsMinorQsnFrTake5Center3 };



    // Function button inactive -- option item frame
static const TAknsItemID KAknsIIDQsnFrFunctionButtonInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonInactive};

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCornerTlInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCornerTlInactive };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCornerTrInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCornerTrInactive };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCornerBlInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCornerBlInactive };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCornerBrInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCornerBrInactive };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonSideTInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonSideTInactive };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonSideBInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonSideBInactive };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonSideLInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonSideLInactive };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonSideRInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonSideRInactive };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCenterInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCenterInactive };
    
    
    
    // Function button normal -- option item frame
static const TAknsItemID KAknsIIDQsnFrFunctionButtonNormal =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonNormal};

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCornerTlNormal =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCornerTlNormal };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCornerTrNormal =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCornerTrNormal };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCornerBlNormal =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCornerBlNormal };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCornerBrNormal =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCornerBrNormal };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonSideTNormal =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonSideTNormal };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonSideBNormal =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonSideBNormal };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonSideLNormal =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonSideLNormal };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonSideRNormal =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonSideRNormal };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCenterNormal =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCenterNormal };
    
    
    // Function button pressed -- option item frame
static const TAknsItemID KAknsIIDQsnFrFunctionButtonPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonPressed};

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCornerTlPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCornerTlPressed };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCornerTrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCornerTrPressed };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCornerBlPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCornerBlPressed };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCornerBrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCornerBrPressed };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonSideTPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonSideTPressed };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonSideBPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonSideBPressed };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonSideLPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonSideLPressed };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonSideRPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonSideRPressed };

static const TAknsItemID KAknsIIDQsnFrFunctionButtonCenterPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrFunctionButtonCenterPressed };



    // Sctrl sk button pressed
static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonPressed};

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonCornerTlPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonCornerTlPressed};
    
static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonCornerTrPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonCornerTrPressed};
    
static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonCornerBlPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonCornerBlPressed};
    
static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonCornerBrPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonCornerBrPressed};    
   
static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonSideTPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonSideTPressed};   
    
static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonSideBPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonSideBPressed}; 

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonSideLPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonSideLPressed};  

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonSideRPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonSideRPressed};  

static const TAknsItemID KAknsIIDQgnFrSctrlSkButtonCenterPressed =
    { EAknsMajorSkin, EAknsMinorQgnFrSctrlSkButtonCenterPressed};  


    //Grid pressed
static const TAknsItemID KAknsIIDQsnFrGridPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrGridPressed};

static const TAknsItemID KAknsIIDQsnFrGridCornerTlPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrGridCornerTlPressed};
    
static const TAknsItemID KAknsIIDQsnFrGridCornerTrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrGridCornerTrPressed};
    
static const TAknsItemID KAknsIIDQsnFrGridCornerBlPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrGridCornerBlPressed};
    
static const TAknsItemID KAknsIIDQsnFrGridCornerBrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrGridCornerBrPressed};    
   
static const TAknsItemID KAknsIIDQsnFrGridSideTPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrGridSideTPressed};   
    
static const TAknsItemID KAknsIIDQsnFrGridSideBPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrGridSideBPressed}; 

static const TAknsItemID KAknsIIDQsnFrGridSideLPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrGridSideLPressed};  

static const TAknsItemID KAknsIIDQsnFrGridSideRPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrGridSideRPressed};  

static const TAknsItemID KAknsIIDQsnFrGridCenterPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrGridCenterPressed}; 


    //List pressed
static const TAknsItemID KAknsIIDQsnFrListPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrListPressed};

static const TAknsItemID KAknsIIDQsnFrListCornerTlPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrListCornerTlPressed};
    
static const TAknsItemID KAknsIIDQsnFrListCornerTrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrListCornerTrPressed};
    
static const TAknsItemID KAknsIIDQsnFrListCornerBlPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrListCornerBlPressed};
    
static const TAknsItemID KAknsIIDQsnFrListCornerBrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrListCornerBrPressed};    
   
static const TAknsItemID KAknsIIDQsnFrListSideTPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrListSideTPressed};   
    
static const TAknsItemID KAknsIIDQsnFrListSideBPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrListSideBPressed}; 

static const TAknsItemID KAknsIIDQsnFrListSideLPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrListSideLPressed};  

static const TAknsItemID KAknsIIDQsnFrListSideRPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrListSideRPressed};  

static const TAknsItemID KAknsIIDQsnFrListCenterPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrListCenterPressed}; 
    

    // Schedule Viewer
static const TAknsItemID KAknsIIDQgnFsFrScheduleViewer =
    { EAknsMajorSkin, EAknsMinorQgnFsFrScheduleViewer};

static const TAknsItemID KAknsIIDQgnFsFrScheduleViewerCornerTl =
    { EAknsMajorSkin, EAknsMinorQgnFsFrScheduleViewerCornerTl};
    
static const TAknsItemID KAknsIIDQgnFsFrScheduleViewerCornerTr =
    { EAknsMajorSkin, EAknsMinorQgnFsFrScheduleViewerCornerTr};
    
static const TAknsItemID KAknsIIDQgnFsFrScheduleViewerCornerBl =
    { EAknsMajorSkin, EAknsMinorQgnFsFrScheduleViewerCornerBl};
    
static const TAknsItemID KAknsIIDQgnFsFrScheduleViewerCornerBr =
    { EAknsMajorSkin, EAknsMinorQgnFsFrScheduleViewerCornerBr};    
   
static const TAknsItemID KAknsIIDQgnFsFrScheduleViewerSideT =
    { EAknsMajorSkin, EAknsMinorQgnFsFrScheduleViewerSideT};   
    
static const TAknsItemID KAknsIIDQgnFsFrScheduleViewerSideB =
    { EAknsMajorSkin, EAknsMinorQgnFsFrScheduleViewerSideB}; 

static const TAknsItemID KAknsIIDQgnFsFrScheduleViewerSideL =
    { EAknsMajorSkin, EAknsMinorQgnFsFrScheduleViewerSideL};  

static const TAknsItemID KAknsIIDQgnFsFrScheduleViewerSideR =
    { EAknsMajorSkin, EAknsMinorQgnFsFrScheduleViewerSideR};  

static const TAknsItemID KAknsIIDQgnFsFrScheduleViewerCenter =
    { EAknsMajorSkin, EAknsMinorQgnFsFrScheduleViewerCenter}; 
    

    // Home Button Widget
static const TAknsItemID KAknsIIDQgnHomeButtonWidget =
    { EAknsMajorSkin, EAknsMinorQgnHomeButtonWidget};

static const TAknsItemID KAknsIIDQgnHomeButtonWidgetTl =
    { EAknsMajorSkin, EAknsMinorQgnHomeButtonWidgetTl};
    
static const TAknsItemID KAknsIIDQgnHomeButtonWidgetTr =
    { EAknsMajorSkin, EAknsMinorQgnHomeButtonWidgetTr};
    
static const TAknsItemID KAknsIIDQgnHomeButtonWidgetBl =
    { EAknsMajorSkin, EAknsMinorQgnHomeButtonWidgetBl};
    
static const TAknsItemID KAknsIIDQgnHomeButtonWidgetBr =
    { EAknsMajorSkin, EAknsMinorQgnHomeButtonWidgetBr};    
   
static const TAknsItemID KAknsIIDQgnHomeButtonWidgetT =
    { EAknsMajorSkin, EAknsMinorQgnHomeButtonWidgetT};   
    
static const TAknsItemID KAknsIIDQgnHomeButtonWidgetB =
    { EAknsMajorSkin, EAknsMinorQgnHomeButtonWidgetB}; 

static const TAknsItemID KAknsIIDQgnHomeButtonWidgetL =
    { EAknsMajorSkin, EAknsMinorQgnHomeButtonWidgetL};  

static const TAknsItemID KAknsIIDQgnHomeButtonWidgetR =
    { EAknsMajorSkin, EAknsMinorQgnHomeButtonWidgetR};  

static const TAknsItemID KAknsIIDQgnHomeButtonWidgetCenter =
    { EAknsMajorSkin, EAknsMinorQgnHomeButtonWidgetCenter}; 
    

    // Home
static const TAknsItemID KAknsIIDQsnFrHome =
    { EAknsMajorSkin, EAknsMinorQsnFrHome};

static const TAknsItemID KAknsIIDQsnFrHomeTl =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeTl};
    
static const TAknsItemID KAknsIIDQsnFrHomeTr =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeTr};
    
static const TAknsItemID KAknsIIDQsnFrHomeBl =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeBl};
    
static const TAknsItemID KAknsIIDQsnFrHomeBr =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeBr};    
   
static const TAknsItemID KAknsIIDQsnFrHomeT =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeT};   
    
static const TAknsItemID KAknsIIDQsnFrHomeB =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeB}; 

static const TAknsItemID KAknsIIDQsnFrHomeL =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeL};  

static const TAknsItemID KAknsIIDQsnFrHomeR =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeR};  

static const TAknsItemID KAknsIIDQsnFrHomeCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeCenter}; 
    

    // Qsn Home Bg Widget
static const TAknsItemID KAknsIIDQsnHomeBgWidget =
    { EAknsMajorSkin, EAknsMinorQsnHomeBgWidget};

static const TAknsItemID KAknsIIDQsnHomeBgWidgetTl =
    { EAknsMajorSkin, EAknsMinorQsnHomeBgWidgetTl};
    
static const TAknsItemID KAknsIIDQsnHomeBgWidgetTr =
    { EAknsMajorSkin, EAknsMinorQsnHomeBgWidgetTr};
    
static const TAknsItemID KAknsIIDQsnHomeBgWidgetBl =
    { EAknsMajorSkin, EAknsMinorQsnHomeBgWidgetBl};
    
static const TAknsItemID KAknsIIDQsnHomeBgWidgetBr =
    { EAknsMajorSkin, EAknsMinorQsnHomeBgWidgetBr};    
   
static const TAknsItemID KAknsIIDQsnHomeBgWidgetT =
    { EAknsMajorSkin, EAknsMinorQsnHomeBgWidgetT};   
    
static const TAknsItemID KAknsIIDQsnHomeBgWidgetB =
    { EAknsMajorSkin, EAknsMinorQsnHomeBgWidgetB}; 

static const TAknsItemID KAknsIIDQsnHomeBgWidgetL =
    { EAknsMajorSkin, EAknsMinorQsnHomeBgWidgetL};  

static const TAknsItemID KAknsIIDQsnHomeBgWidgetR =
    { EAknsMajorSkin, EAknsMinorQsnHomeBgWidgetR};  

static const TAknsItemID KAknsIIDQsnHomeBgWidgetCenter =
    { EAknsMajorSkin, EAknsMinorQsnHomeBgWidgetCenter}; 
    

    // Qgn Home Bg Widget
static const TAknsItemID KAknsIIDQgnHomeBgWidget =
    { EAknsMajorSkin, EAknsMinorQgnHomeBgWidget};

static const TAknsItemID KAknsIIDQgnHomeBgWidgetTl =
    { EAknsMajorSkin, EAknsMinorQgnHomeBgWidgetTl};
    
static const TAknsItemID KAknsIIDQgnHomeBgWidgetTr =
    { EAknsMajorSkin, EAknsMinorQgnHomeBgWidgetTr};
    
static const TAknsItemID KAknsIIDQgnHomeBgWidgetBl =
    { EAknsMajorSkin, EAknsMinorQgnHomeBgWidgetBl};
    
static const TAknsItemID KAknsIIDQgnHomeBgWidgetBr =
    { EAknsMajorSkin, EAknsMinorQgnHomeBgWidgetBr};    
   
static const TAknsItemID KAknsIIDQgnHomeBgWidgetT =
    { EAknsMajorSkin, EAknsMinorQgnHomeBgWidgetT};   
    
static const TAknsItemID KAknsIIDQgnHomeBgWidgetB =
    { EAknsMajorSkin, EAknsMinorQgnHomeBgWidgetB}; 

static const TAknsItemID KAknsIIDQgnHomeBgWidgetL =
    { EAknsMajorSkin, EAknsMinorQgnHomeBgWidgetL};  

static const TAknsItemID KAknsIIDQgnHomeBgWidgetR =
    { EAknsMajorSkin, EAknsMinorQgnHomeBgWidgetR};  

static const TAknsItemID KAknsIIDQgnHomeBgWidgetCenter =
    { EAknsMajorSkin, EAknsMinorQgnHomeBgWidgetCenter}; 
    

    // Graf Mediatag Bubble
static const TAknsItemID KAknsIIDQgnGrafMediatagBubble =
    { EAknsMajorSkin, EAknsMinorQgnGrafMediatagBubble};

static const TAknsItemID KAknsIIDQgnGrafMediatagBubbleCornerTl =
    { EAknsMajorSkin, EAknsMinorQgnGrafMediatagBubbleCornerTl};
    
static const TAknsItemID KAknsIIDQgnGrafMediatagBubbleCornerTr =
    { EAknsMajorSkin, EAknsMinorQgnGrafMediatagBubbleCornerTr};
    
static const TAknsItemID KAknsIIDQgnGrafMediatagBubbleCornerBl =
    { EAknsMajorSkin, EAknsMinorQgnGrafMediatagBubbleCornerBl};
    
static const TAknsItemID KAknsIIDQgnGrafMediatagBubbleCornerBr =
    { EAknsMajorSkin, EAknsMinorQgnGrafMediatagBubbleCornerBr};    
   
static const TAknsItemID KAknsIIDQgnGrafMediatagBubbleSideT =
    { EAknsMajorSkin, EAknsMinorQgnGrafMediatagBubbleSideT};   
    
static const TAknsItemID KAknsIIDQgnGrafMediatagBubbleSideB =
    { EAknsMajorSkin, EAknsMinorQgnGrafMediatagBubbleSideB}; 

static const TAknsItemID KAknsIIDQgnGrafMediatagBubbleSideL =
    { EAknsMajorSkin, EAknsMinorQgnGrafMediatagBubbleSideL};  

static const TAknsItemID KAknsIIDQgnGrafMediatagBubbleSideR =
    { EAknsMajorSkin, EAknsMinorQgnGrafMediatagBubbleSideR};  

static const TAknsItemID KAknsIIDQgnGrafMediatagBubbleCenter =
    { EAknsMajorSkin, EAknsMinorQgnGrafMediatagBubbleCenter}; 
    
    
    // Qsn Fr Cmail List
static const TAknsItemID KAknsIIDQsnFrCmailList =
    { EAknsMajorSkin, EAknsMinorQsnFrCmailList};

static const TAknsItemID KAknsIIDQsnFrCmailListCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrCmailListCornerTl};
    
static const TAknsItemID KAknsIIDQsnFrCmailListCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrCmailListCornerTr};
    
static const TAknsItemID KAknsIIDQsnFrCmailListCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrCmailListCornerBl};
    
static const TAknsItemID KAknsIIDQsnFrCmailListCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrCmailListCornerBr};   
   
static const TAknsItemID KAknsIIDQsnFrCmailListSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrCmailListSideT};   
    
static const TAknsItemID KAknsIIDQsnFrCmailListSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrCmailListSideB}; 

static const TAknsItemID KAknsIIDQsnFrCmailListSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrCmailListSideL};  

static const TAknsItemID KAknsIIDQsnFrCmailListSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrCmailListSideR};  

static const TAknsItemID KAknsIIDQsnFrCmailListCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrCmailListCenter}; 
    

    // Qgn Fr Cmail Field
static const TAknsItemID KAknsIIDQgnFrCmailField =
    { EAknsMajorSkin, EAknsMinorQgnFrCmailField};

static const TAknsItemID KAknsIIDQgnFrCmailFieldCornerTl =
    { EAknsMajorSkin, EAknsMinorQgnFrCmailFieldCornerTl};
    
static const TAknsItemID KAknsIIDQgnFrCmailFieldCornerTr =
    { EAknsMajorSkin, EAknsMinorQgnFrCmailFieldCornerTr};
    
static const TAknsItemID KAknsIIDQgnFrCmailFieldCornerBl =
    { EAknsMajorSkin, EAknsMinorQgnFrCmailFieldCornerBl};
    
static const TAknsItemID KAknsIIDQgnFrCmailFieldCornerBr =
    { EAknsMajorSkin, EAknsMinorQgnFrCmailFieldCornerBr};   
   
static const TAknsItemID KAknsIIDQgnFrCmailFieldSideT =
    { EAknsMajorSkin, EAknsMinorQgnFrCmailFieldSideT};   
    
static const TAknsItemID KAknsIIDQgnFrCmailFieldSideB =
    { EAknsMajorSkin, EAknsMinorQgnFrCmailFieldSideB}; 

static const TAknsItemID KAknsIIDQgnFrCmailFieldSideL =
    { EAknsMajorSkin, EAknsMinorQgnFrCmailFieldSideL};  

static const TAknsItemID KAknsIIDQgnFrCmailFieldSideR =
    { EAknsMajorSkin, EAknsMinorQgnFrCmailFieldSideR};  

static const TAknsItemID KAknsIIDQgnFrCmailFieldCenter =
    { EAknsMajorSkin, EAknsMinorQgnFrCmailFieldCenter}; 
    

    // Home Pressed
static const TAknsItemID KAknsIIDQsnFrHomePressed =
    { EAknsMajorSkin, EAknsMinorQsnFrHomePressed};

static const TAknsItemID KAknsIIDQsnFrHomeTlPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeTlPressed};
    
static const TAknsItemID KAknsIIDQsnFrHomeTrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeTrPressed};
    
static const TAknsItemID KAknsIIDQsnFrHomeBlPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeBlPressed};
    
static const TAknsItemID KAknsIIDQsnFrHomeBrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeBrPressed};    
   
static const TAknsItemID KAknsIIDQsnFrHomeTPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeTPressed};   
    
static const TAknsItemID KAknsIIDQsnFrHomeBPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeBPressed}; 

static const TAknsItemID KAknsIIDQsnFrHomeLPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeLPressed};  

static const TAknsItemID KAknsIIDQsnFrHomeRPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeRPressed};  

static const TAknsItemID KAknsIIDQsnFrHomeCenterPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrHomeCenterPressed}; 
    
    
    // Qsn Fr Title Divider
static const TAknsItemID KAknsIIDQsnFrTitleDivider =
    { EAknsMajorSkin, EAknsMinorQsnFrTitleDivider};

static const TAknsItemID KAknsIIDQsnFrTitleDividerCornerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrTitleDividerCornerTl};
    
static const TAknsItemID KAknsIIDQsnFrTitleDividerCornerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrTitleDividerCornerTr};
    
static const TAknsItemID KAknsIIDQsnFrTitleDividerCornerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrTitleDividerCornerBl};
    
static const TAknsItemID KAknsIIDQsnFrTitleDividerCornerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrTitleDividerCornerBr};   
   
static const TAknsItemID KAknsIIDQsnFrTitleDividerSideT =
    { EAknsMajorSkin, EAknsMinorQsnFrTitleDividerSideT};   
    
static const TAknsItemID KAknsIIDQsnFrTitleDividerSideB =
    { EAknsMajorSkin, EAknsMinorQsnFrTitleDividerSideB}; 

static const TAknsItemID KAknsIIDQsnFrTitleDividerSideL =
    { EAknsMajorSkin, EAknsMinorQsnFrTitleDividerSideL};  

static const TAknsItemID KAknsIIDQsnFrTitleDividerSideR =
    { EAknsMajorSkin, EAknsMinorQsnFrTitleDividerSideR};  

static const TAknsItemID KAknsIIDQsnFrTitleDividerCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrTitleDividerCenter}; 
    
    
    // Qgn Home Contact Mask
static const TAknsItemID KAknsIIDQgnHomeContactMask =
    { EAknsMajorSkin, EAknsMinorQgnHomeContactMask};

static const TAknsItemID KAknsIIDQgnHomeContactMaskTl =
    { EAknsMajorSkin, EAknsMinorQgnHomeContactMaskTl};
    
static const TAknsItemID KAknsIIDQgnHomeContactMaskTr =
    { EAknsMajorSkin, EAknsMinorQgnHomeContactMaskTr};
    
static const TAknsItemID KAknsIIDQgnHomeContactMaskBl =
    { EAknsMajorSkin, EAknsMinorQgnHomeContactMaskBl};
    
static const TAknsItemID KAknsIIDQgnHomeContactMaskBr =
    { EAknsMajorSkin, EAknsMinorQgnHomeContactMaskBr};   
   
static const TAknsItemID KAknsIIDQgnHomeContactMaskT =
    { EAknsMajorSkin, EAknsMinorQgnHomeContactMaskT};   
    
static const TAknsItemID KAknsIIDQgnHomeContactMaskB =
    { EAknsMajorSkin, EAknsMinorQgnHomeContactMaskB}; 

static const TAknsItemID KAknsIIDQgnHomeContactMaskL =
    { EAknsMajorSkin, EAknsMinorQgnHomeContactMaskL};  

static const TAknsItemID KAknsIIDQgnHomeContactMaskR =
    { EAknsMajorSkin, EAknsMinorQgnHomeContactMaskR};  

static const TAknsItemID KAknsIIDQgnHomeContactMaskCenter =
    { EAknsMajorSkin, EAknsMinorQgnHomeContactMaskCenter}; 
    
    
    // Qgn Home Wm Button
static const TAknsItemID KAknsIIDQgnHomeWmButton =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButton};

static const TAknsItemID KAknsIIDQgnHomeWmButtonTl =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonTl};
    
static const TAknsItemID KAknsIIDQgnHomeWmButtonTr =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonTr};
    
static const TAknsItemID KAknsIIDQgnHomeWmButtonBl =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonBl};
    
static const TAknsItemID KAknsIIDQgnHomeWmButtonBr =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonBr};   
   
static const TAknsItemID KAknsIIDQgnHomeWmButtonT =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonT};   
    
static const TAknsItemID KAknsIIDQgnHomeWmButtonB =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonB}; 

static const TAknsItemID KAknsIIDQgnHomeWmButtonL =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonL};  

static const TAknsItemID KAknsIIDQgnHomeWmButtonR =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonR};  

static const TAknsItemID KAknsIIDQgnHomeWmButtonCenter =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonCenter}; 
    
    
    // Qsn Fr Button Highlight Answer
static const TAknsItemID KAknsIIDQsnFrButtonHighlightAnswer =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightAnswer};

static const TAknsItemID KAknsIIDQsnFrButtonHighlightAnswerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightAnswerTl};
    
static const TAknsItemID KAknsIIDQsnFrButtonHighlightAnswerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightAnswerTr};
    
static const TAknsItemID KAknsIIDQsnFrButtonHighlightAnswerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightAnswerBl};
    
static const TAknsItemID KAknsIIDQsnFrButtonHighlightAnswerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightAnswerBr};   
   
static const TAknsItemID KAknsIIDQsnFrButtonHighlightAnswerT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightAnswerT};   
    
static const TAknsItemID KAknsIIDQsnFrButtonHighlightAnswerB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightAnswerB}; 

static const TAknsItemID KAknsIIDQsnFrButtonHighlightAnswerL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightAnswerL};  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightAnswerR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightAnswerR};  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightAnswerCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightAnswerCenter}; 
    
    
    // Qsn Fr Button Highlight Hold
static const TAknsItemID KAknsIIDQsnFrButtonHighlightHold =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightHold};

static const TAknsItemID KAknsIIDQsnFrButtonHighlightHoldTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightHoldTl};
    
static const TAknsItemID KAknsIIDQsnFrButtonHighlightHoldTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightHoldTr};
    
static const TAknsItemID KAknsIIDQsnFrButtonHighlightHoldBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightHoldBl};
    
static const TAknsItemID KAknsIIDQsnFrButtonHighlightHoldBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightHoldBr};   
   
static const TAknsItemID KAknsIIDQsnFrButtonHighlightHoldT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightHoldT};   
    
static const TAknsItemID KAknsIIDQsnFrButtonHighlightHoldB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightHoldB}; 

static const TAknsItemID KAknsIIDQsnFrButtonHighlightHoldL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightHoldL};  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightHoldR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightHoldR};  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightHoldCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightHoldCenter}; 
    
    
    // Qsn Fr Button Highlight Reject
static const TAknsItemID KAknsIIDQsnFrButtonHighlightReject =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightReject};

static const TAknsItemID KAknsIIDQsnFrButtonHighlightRejectTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightRejectTl};
    
static const TAknsItemID KAknsIIDQsnFrButtonHighlightRejectTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightRejectTr};
    
static const TAknsItemID KAknsIIDQsnFrButtonHighlightRejectBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightRejectBl};
    
static const TAknsItemID KAknsIIDQsnFrButtonHighlightRejectBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightRejectBr};   
   
static const TAknsItemID KAknsIIDQsnFrButtonHighlightRejectT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightRejectT};   
    
static const TAknsItemID KAknsIIDQsnFrButtonHighlightRejectB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightRejectB}; 

static const TAknsItemID KAknsIIDQsnFrButtonHighlightRejectL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightRejectL};  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightRejectR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightRejectR};  

static const TAknsItemID KAknsIIDQsnFrButtonHighlightRejectCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonHighlightRejectCenter}; 
    
    
    // Qsn Fr Button Inactive Answer
static const TAknsItemID KAknsIIDQsnFrButtonInactiveAnswer =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveAnswer};

static const TAknsItemID KAknsIIDQsnFrButtonInactiveAnswerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveAnswerTl};
    
static const TAknsItemID KAknsIIDQsnFrButtonInactiveAnswerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveAnswerTr};
    
static const TAknsItemID KAknsIIDQsnFrButtonInactiveAnswerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveAnswerBl};
    
static const TAknsItemID KAknsIIDQsnFrButtonInactiveAnswerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveAnswerBr};   
   
static const TAknsItemID KAknsIIDQsnFrButtonInactiveAnswerT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveAnswerT};   
    
static const TAknsItemID KAknsIIDQsnFrButtonInactiveAnswerB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveAnswerB}; 

static const TAknsItemID KAknsIIDQsnFrButtonInactiveAnswerL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveAnswerL};  

static const TAknsItemID KAknsIIDQsnFrButtonInactiveAnswerR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveAnswerR};  

static const TAknsItemID KAknsIIDQsnFrButtonInactiveAnswerCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveAnswerCenter}; 
    
    
    // Qsn Fr Button Inactive Hold
static const TAknsItemID KAknsIIDQsnFrButtonInactiveHold =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveHold};

static const TAknsItemID KAknsIIDQsnFrButtonInactiveHoldTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveHoldTl};
    
static const TAknsItemID KAknsIIDQsnFrButtonInactiveHoldTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveHoldTr};
    
static const TAknsItemID KAknsIIDQsnFrButtonInactiveHoldBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveHoldBl};
    
static const TAknsItemID KAknsIIDQsnFrButtonInactiveHoldBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveHoldBr};   
   
static const TAknsItemID KAknsIIDQsnFrButtonInactiveHoldT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveHoldT};   
    
static const TAknsItemID KAknsIIDQsnFrButtonInactiveHoldB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveHoldB}; 

static const TAknsItemID KAknsIIDQsnFrButtonInactiveHoldL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveHoldL};  

static const TAknsItemID KAknsIIDQsnFrButtonInactiveHoldR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveHoldR};  

static const TAknsItemID KAknsIIDQsnFrButtonInactiveHoldCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveHoldCenter}; 
    
    
    // Qsn Fr Button Inactive Reject
static const TAknsItemID KAknsIIDQsnFrButtonInactiveReject =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveReject};

static const TAknsItemID KAknsIIDQsnFrButtonInactiveRejectTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveRejectTl};
    
static const TAknsItemID KAknsIIDQsnFrButtonInactiveRejectTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveRejectTr};
    
static const TAknsItemID KAknsIIDQsnFrButtonInactiveRejectBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveRejectBl};
    
static const TAknsItemID KAknsIIDQsnFrButtonInactiveRejectBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveRejectBr};   
   
static const TAknsItemID KAknsIIDQsnFrButtonInactiveRejectT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveRejectT};   
    
static const TAknsItemID KAknsIIDQsnFrButtonInactiveRejectB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveRejectB}; 

static const TAknsItemID KAknsIIDQsnFrButtonInactiveRejectL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveRejectL};  

static const TAknsItemID KAknsIIDQsnFrButtonInactiveRejectR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveRejectR};  

static const TAknsItemID KAknsIIDQsnFrButtonInactiveRejectCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonInactiveRejectCenter}; 
    
    
    // Qsn Fr Button Normal Answer
static const TAknsItemID KAknsIIDQsnFrButtonNormalAnswer =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalAnswer};

static const TAknsItemID KAknsIIDQsnFrButtonNormalAnswerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalAnswerTl};
    
static const TAknsItemID KAknsIIDQsnFrButtonNormalAnswerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalAnswerTr};
    
static const TAknsItemID KAknsIIDQsnFrButtonNormalAnswerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalAnswerBl};
    
static const TAknsItemID KAknsIIDQsnFrButtonNormalAnswerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalAnswerBr};   
   
static const TAknsItemID KAknsIIDQsnFrButtonNormalAnswerT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalAnswerT};   
    
static const TAknsItemID KAknsIIDQsnFrButtonNormalAnswerB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalAnswerB}; 

static const TAknsItemID KAknsIIDQsnFrButtonNormalAnswerL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalAnswerL};  

static const TAknsItemID KAknsIIDQsnFrButtonNormalAnswerR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalAnswerR};  

static const TAknsItemID KAknsIIDQsnFrButtonNormalAnswerCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalAnswerCenter}; 
    
    
    // Qsn Fr Button Normal Hold
static const TAknsItemID KAknsIIDQsnFrButtonNormalHold =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalHold};

static const TAknsItemID KAknsIIDQsnFrButtonNormalHoldTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalHoldTl};
    
static const TAknsItemID KAknsIIDQsnFrButtonNormalHoldTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalHoldTr};
    
static const TAknsItemID KAknsIIDQsnFrButtonNormalHoldBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalHoldBl};
    
static const TAknsItemID KAknsIIDQsnFrButtonNormalHoldBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalHoldBr};   
   
static const TAknsItemID KAknsIIDQsnFrButtonNormalHoldT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalHoldT};   
    
static const TAknsItemID KAknsIIDQsnFrButtonNormalHoldB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalHoldB}; 

static const TAknsItemID KAknsIIDQsnFrButtonNormalHoldL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalHoldL};  

static const TAknsItemID KAknsIIDQsnFrButtonNormalHoldR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalHoldR};  

static const TAknsItemID KAknsIIDQsnFrButtonNormalHoldCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalHoldCenter}; 
    
    
    // Qsn Fr Button Normal Reject
static const TAknsItemID KAknsIIDQsnFrButtonNormalReject =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalReject};

static const TAknsItemID KAknsIIDQsnFrButtonNormalRejectTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalRejectTl};
    
static const TAknsItemID KAknsIIDQsnFrButtonNormalRejectTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalRejectTr};
    
static const TAknsItemID KAknsIIDQsnFrButtonNormalRejectBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalRejectBl};
    
static const TAknsItemID KAknsIIDQsnFrButtonNormalRejectBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalRejectBr};   
   
static const TAknsItemID KAknsIIDQsnFrButtonNormalRejectT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalRejectT};   
    
static const TAknsItemID KAknsIIDQsnFrButtonNormalRejectB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalRejectB}; 

static const TAknsItemID KAknsIIDQsnFrButtonNormalRejectL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalRejectL};  

static const TAknsItemID KAknsIIDQsnFrButtonNormalRejectR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalRejectR};  

static const TAknsItemID KAknsIIDQsnFrButtonNormalRejectCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonNormalRejectCenter}; 
    
    
    // Qsn Fr Button Pressed Answer
static const TAknsItemID KAknsIIDQsnFrButtonPressedAnswer =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedAnswer};

static const TAknsItemID KAknsIIDQsnFrButtonPressedAnswerTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedAnswerTl};
    
static const TAknsItemID KAknsIIDQsnFrButtonPressedAnswerTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedAnswerTr};
    
static const TAknsItemID KAknsIIDQsnFrButtonPressedAnswerBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedAnswerBl};
    
static const TAknsItemID KAknsIIDQsnFrButtonPressedAnswerBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedAnswerBr};   
   
static const TAknsItemID KAknsIIDQsnFrButtonPressedAnswerT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedAnswerT};   
    
static const TAknsItemID KAknsIIDQsnFrButtonPressedAnswerB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedAnswerB}; 

static const TAknsItemID KAknsIIDQsnFrButtonPressedAnswerL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedAnswerL};  

static const TAknsItemID KAknsIIDQsnFrButtonPressedAnswerR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedAnswerR};  

static const TAknsItemID KAknsIIDQsnFrButtonPressedAnswerCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedAnswerCenter}; 
    
    
    // Qsn Fr Button Pressed Hold
static const TAknsItemID KAknsIIDQsnFrButtonPressedHold =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedHold};

static const TAknsItemID KAknsIIDQsnFrButtonPressedHoldTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedHoldTl};
    
static const TAknsItemID KAknsIIDQsnFrButtonPressedHoldTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedHoldTr};
    
static const TAknsItemID KAknsIIDQsnFrButtonPressedHoldBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedHoldBl};
    
static const TAknsItemID KAknsIIDQsnFrButtonPressedHoldBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedHoldBr};   
   
static const TAknsItemID KAknsIIDQsnFrButtonPressedHoldT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedHoldT};   
    
static const TAknsItemID KAknsIIDQsnFrButtonPressedHoldB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedHoldB}; 

static const TAknsItemID KAknsIIDQsnFrButtonPressedHoldL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedHoldL};  

static const TAknsItemID KAknsIIDQsnFrButtonPressedHoldR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedHoldR};  

static const TAknsItemID KAknsIIDQsnFrButtonPressedHoldCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedHoldCenter}; 
    
    
    // Qsn Fr Button Pressed Reject
static const TAknsItemID KAknsIIDQsnFrButtonPressedReject =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedReject};

static const TAknsItemID KAknsIIDQsnFrButtonPressedRejectTl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedRejectTl};
    
static const TAknsItemID KAknsIIDQsnFrButtonPressedRejectTr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedRejectTr};
    
static const TAknsItemID KAknsIIDQsnFrButtonPressedRejectBl =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedRejectBl};
    
static const TAknsItemID KAknsIIDQsnFrButtonPressedRejectBr =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedRejectBr};   
   
static const TAknsItemID KAknsIIDQsnFrButtonPressedRejectT =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedRejectT};   
    
static const TAknsItemID KAknsIIDQsnFrButtonPressedRejectB =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedRejectB}; 

static const TAknsItemID KAknsIIDQsnFrButtonPressedRejectL =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedRejectL};  

static const TAknsItemID KAknsIIDQsnFrButtonPressedRejectR =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedRejectR};  

static const TAknsItemID KAknsIIDQsnFrButtonPressedRejectCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrButtonPressedRejectCenter}; 
    
    
    // Qsn Fr Keypad Button Inactive
static const TAknsItemID KAknsIIDQsnFrKeypadButtonFrInactive =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonInactive};

static const TAknsItemID KAknsIIDQsnFrKeypadButtonInactiveTl =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonInactiveTl};
    
static const TAknsItemID KAknsIIDQsnFrKeypadButtonInactiveTr =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonInactiveTr};
    
static const TAknsItemID KAknsIIDQsnFrKeypadButtonInactiveBl =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonInactiveBl};
    
static const TAknsItemID KAknsIIDQsnFrKeypadButtonInactiveBr =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonInactiveBr};   
   
static const TAknsItemID KAknsIIDQsnFrKeypadButtonInactiveT =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonInactiveT};   
    
static const TAknsItemID KAknsIIDQsnFrKeypadButtonInactiveB =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonInactiveB}; 

static const TAknsItemID KAknsIIDQsnFrKeypadButtonInactiveL =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonInactiveL};  

static const TAknsItemID KAknsIIDQsnFrKeypadButtonInactiveR =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonInactiveR};  

static const TAknsItemID KAknsIIDQsnFrKeypadButtonInactiveCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonInactiveCenter}; 
    
    
    // Qsn Fr Keypad Button Normal
static const TAknsItemID KAknsIIDQsnFrKeypadButtonFrNormal =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonNormal};

static const TAknsItemID KAknsIIDQsnFrKeypadButtonNormalTl =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonNormalTl};
    
static const TAknsItemID KAknsIIDQsnFrKeypadButtonNormalTr =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonNormalTr};
    
static const TAknsItemID KAknsIIDQsnFrKeypadButtonNormalBl =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonNormalBl};
    
static const TAknsItemID KAknsIIDQsnFrKeypadButtonNormalBr =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonNormalBr};   
   
static const TAknsItemID KAknsIIDQsnFrKeypadButtonNormalT =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonNormalT};   
    
static const TAknsItemID KAknsIIDQsnFrKeypadButtonNormalB =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonNormalB}; 

static const TAknsItemID KAknsIIDQsnFrKeypadButtonNormalL =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonNormalL};  

static const TAknsItemID KAknsIIDQsnFrKeypadButtonNormalR =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonNormalR};  

static const TAknsItemID KAknsIIDQsnFrKeypadButtonNormalCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonNormalCenter}; 
    
    
    // Qsn Fr Keypad Button Pressed
static const TAknsItemID KAknsIIDQsnFrKeypadButtonFrPressed =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonPressed};

static const TAknsItemID KAknsIIDQsnFrKeypadButtonPressedTl =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonPressedTl};
    
static const TAknsItemID KAknsIIDQsnFrKeypadButtonPressedTr =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonPressedTr};
    
static const TAknsItemID KAknsIIDQsnFrKeypadButtonPressedBl =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonPressedBl};
    
static const TAknsItemID KAknsIIDQsnFrKeypadButtonPressedBr =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonPressedBr};   
   
static const TAknsItemID KAknsIIDQsnFrKeypadButtonPressedT =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonPressedT};   
    
static const TAknsItemID KAknsIIDQsnFrKeypadButtonPressedB =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonPressedB}; 

static const TAknsItemID KAknsIIDQsnFrKeypadButtonPressedL =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonPressedL};  

static const TAknsItemID KAknsIIDQsnFrKeypadButtonPressedR =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonPressedR};  

static const TAknsItemID KAknsIIDQsnFrKeypadButtonPressedCenter =
    { EAknsMajorSkin, EAknsMinorQsnFrKeypadButtonPressedCenter}; 
    
    
    // Qgn Home Wm Button Pressed
static const TAknsItemID KAknsIIDQgnHomeWmButtonPressed =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonPressed};

static const TAknsItemID KAknsIIDQgnHomeWmButtonPressedTl =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonPressedTl};
    
static const TAknsItemID KAknsIIDQgnHomeWmButtonPressedTr =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonPressedTr};
    
static const TAknsItemID KAknsIIDQgnHomeWmButtonPressedBl =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonPressedBl};
    
static const TAknsItemID KAknsIIDQgnHomeWmButtonPressedBr =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonPressedBr};   
   
static const TAknsItemID KAknsIIDQgnHomeWmButtonPressedT =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonPressedT};   
    
static const TAknsItemID KAknsIIDQgnHomeWmButtonPressedB =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonPressedB}; 

static const TAknsItemID KAknsIIDQgnHomeWmButtonPressedL =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonPressedL};  

static const TAknsItemID KAknsIIDQgnHomeWmButtonPressedR =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonPressedR};  

static const TAknsItemID KAknsIIDQgnHomeWmButtonPressedCenter =
    { EAknsMajorSkin, EAknsMinorQgnHomeWmButtonPressedCenter}; 
    
    

static const TAknsItemID KAknsIIDQgnGrafBlidFlag =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidFlag };

static const TAknsItemID KAknsIIDQgnGrafBlidSearching =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSearching };

static const TAknsItemID KAknsIIDQgnGrafBlidSearchingSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSearchingSmall };

static const TAknsItemID KAknsIIDQgnGrafBlidStartup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidStartup };

static const TAknsItemID KAknsIIDQgnGrafBlidUnavail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidUnavail };

static const TAknsItemID KAknsIIDQgnGrafNsliderVerticalMarkerSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderVerticalMarkerSelected };

static const TAknsItemID KAknsIIDQgnIndiCam4Pause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Pause };

static const TAknsItemID KAknsIIDQgnIndiCam4QualityEmailSharing =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4QualityEmailSharing };

static const TAknsItemID KAknsIIDQgnIndiCam4Record =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Record };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomMarkerSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomMarkerSelected };

static const TAknsItemID KAknsIIDQgnIndiVideocallBrightness =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideocallBrightness };

static const TAknsItemID KAknsIIDQgnIndiVideocallContrast =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideocallContrast };

static const TAknsItemID KAknsIIDQgnIndiVideocallZoom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideocallZoom };

static const TAknsItemID KAknsIIDQgnGrafBgLscSideRightMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBgLscSideRightMaskIcon };

static const TAknsItemID KAknsIIDQgnGrafBlidSatSignal01 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSatSignal01 };

static const TAknsItemID KAknsIIDQgnGrafBlidSatSignal02 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSatSignal02 };

static const TAknsItemID KAknsIIDQgnGrafBlidSatSignal03 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSatSignal03 };

static const TAknsItemID KAknsIIDQgnGrafBlidSatSignal04 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSatSignal04 };

static const TAknsItemID KAknsIIDQgnGrafBlidSatSignal05 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSatSignal05 };

static const TAknsItemID KAknsIIDQgnGrafBlidSignalBar01 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSignalBar01 };

static const TAknsItemID KAknsIIDQgnGrafBlidSignalBar02 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSignalBar02 };

static const TAknsItemID KAknsIIDQgnGrafBlidSignalBar03 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSignalBar03 };

static const TAknsItemID KAknsIIDQgnGrafBlidSignalBar04 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSignalBar04 };

static const TAknsItemID KAknsIIDQgnGrafBlidSignalBar05 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSignalBar05 };

static const TAknsItemID KAknsIIDQgnIndiBrowserBmTbNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserBmTbNew };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbDelete };

static const TAknsItemID KAknsIIDQgnIndiEqTbCreateNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiEqTbCreateNew };

static const TAknsItemID KAknsIIDQgnIndiImedDownpleSuper =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImedDownpleSuper };

static const TAknsItemID KAknsIIDQgnIndiMpttvTbUnmark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpttvTbUnmark };

static const TAknsItemID KAknsIIDQgnIndiMptvTbMark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMptvTbMark };

static const TAknsItemID KAknsIIDQgnIndiMupTbAddsongs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbAddsongs };

static const TAknsItemID KAknsIIDQgnIndiMupTbAddtoplaylist =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbAddtoplaylist };

static const TAknsItemID KAknsIIDQgnIndiMupTbGotostore =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbGotostore };

static const TAknsItemID KAknsIIDQgnIndiMupTbShuffle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbShuffle };

static const TAknsItemID KAknsIIDQgnMenuGroupHelp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupHelp };

static const TAknsItemID KAknsIIDQgnMenuGroupOwn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupOwn };

static const TAknsItemID KAknsIIDQgnMenuGroupWeb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupWeb };

static const TAknsItemID KAknsIIDQgnPropTake5Missing =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropTake5Missing };

static const TAknsItemID KAknsIIDQgnPropXmediabarLsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropXmediabarLsc };

static const TAknsItemID KAknsIIDQsnFrTake5CornerRTl =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrTake5CornerRTl };

static const TAknsItemID KAknsIIDQsnFrTake5CornerRTr =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrTake5CornerRTr };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbSwichWin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbSwichWin };

static const TAknsItemID KAknsIIDQgnIndiCaleTbMeeting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbMeeting };

static const TAknsItemID KAknsIIDQgnIndiCam4ModePortraitNigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ModePortraitNigh };

static const TAknsItemID KAknsIIDQgnIndiCamBatteryStrength =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamBatteryStrength };

static const TAknsItemID KAknsIIDQgnIndiInputFullHalfWidth =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputFullHalfWidth };

static const TAknsItemID KAknsIIDQgnIndiInputHalfFullWidth =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputHalfFullWidth };

static const TAknsItemID KAknsIIDQgnIndiInputListCollapse =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputListCollapse };

static const TAknsItemID KAknsIIDQgnIndiInputListExpand =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputListExpand };

static const TAknsItemID KAknsIIDQgnIndiInputMorefunction =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputMorefunction };

static const TAknsItemID KAknsIIDQgnIndiRadioDefault =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioDefault };

static const TAknsItemID KAknsIIDQgnIndiRadioPlaying =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioPlaying };

static const TAknsItemID KAknsIIDQgnIndiTbRadioAutotuneDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRadioAutotuneDown };

static const TAknsItemID KAknsIIDQgnIndiTbRadioAutotuneUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRadioAutotuneUp };

static const TAknsItemID KAknsIIDQgnIndiTbRadioNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRadioNext };

static const TAknsItemID KAknsIIDQgnIndiTbRadioPrevious =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRadioPrevious };

static const TAknsItemID KAknsIIDQgnIndiTbRadioScan =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRadioScan };

static const TAknsItemID KAknsIIDQgnIndiTbRadioSound =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRadioSound };

static const TAknsItemID KAknsIIDQgnIndiTbRadioSoundMuted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRadioSoundMuted };

static const TAknsItemID KAknsIIDQgnIndiTbRadioStationSave =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRadioStationSave };

static const TAknsItemID KAknsIIDQgnIndiTbRadioStationSaveAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRadioStationSaveAll };

static const TAknsItemID KAknsIIDQgnIndiVded2EndPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVded2EndPressed };

static const TAknsItemID KAknsIIDQgnIndiVded2PlayheadPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVded2PlayheadPressed };

static const TAknsItemID KAknsIIDQgnIndiVded2PlayPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVded2PlayPressed };

static const TAknsItemID KAknsIIDQgnIndiVded2StartPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVded2StartPressed };

static const TAknsItemID KAknsIIDQgnIndiVdedPausePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdedPausePressed };

static const TAknsItemID KAknsIIDQgnPropCamBatteryIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCamBatteryIcon };

static const TAknsItemID KAknsIIDQgnPropCatalogsItemUpgrade =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCatalogsItemUpgrade };

static const TAknsItemID KAknsIIDQgnPropCpDevPsActivat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevPsActivat };

static const TAknsItemID KAknsIIDQgnPropFmgrUsbMemcSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFmgrUsbMemcSub };

static const TAknsItemID KAknsIIDQsnFrInputListButtonHighlight =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrInputListButtonHighlight };

static const TAknsItemID KAknsIIDQsnFrItutButtonCandiPressedMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutButtonCandiPressedMiddle };

static const TAknsItemID KAknsIIDQsnFrItutButtonCandiPressedSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutButtonCandiPressedSideL };

static const TAknsItemID KAknsIIDQsnFrItutButtonCandiPressedSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutButtonCandiPressedSideR };

static const TAknsItemID KAknsIIDQsnFrItutButtonComposePressedMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutButtonComposePressedMiddle };

static const TAknsItemID KAknsIIDQsnFrItutButtonComposePressedSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutButtonComposePressedSideL };

static const TAknsItemID KAknsIIDQsnFrItutButtonComposePressedSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrItutButtonComposePressedSideR };

static const TAknsItemID KAknsIIDQgnGrafBlidSearchingSmall01 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSearchingSmall01 };

static const TAknsItemID KAknsIIDQgnGrafBlidSearchingSmall02 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSearchingSmall02 };

static const TAknsItemID KAknsIIDQgnGrafBlidSearchingSmall03 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSearchingSmall03 };

static const TAknsItemID KAknsIIDQgnGrafBlidSearchingSmall04 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSearchingSmall04 };

static const TAknsItemID KAknsIIDQgnGrafBlidSearchingSmall05 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSearchingSmall05 };

static const TAknsItemID KAknsIIDQgnGrafBlidSearchingSmall06 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSearchingSmall06 };

static const TAknsItemID KAknsIIDQgnGrafBlidSearchingSmall07 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSearchingSmall07 };

static const TAknsItemID KAknsIIDQgnGrafBlidSearchingSmall08 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidSearchingSmall08 };

static const TAknsItemID KAknsIIDQgnGrafNsliderCam4MarkerSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNsliderCam4MarkerSelected };

static const TAknsItemID KAknsIIDQgnNoteKeyguardLockedAnim1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteKeyguardLockedAnim1 };

static const TAknsItemID KAknsIIDQgnNoteKeyguardLockedAnim2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteKeyguardLockedAnim2 };

static const TAknsItemID KAknsIIDQgnNoteKeyguardLockedAnim3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteKeyguardLockedAnim3 };

static const TAknsItemID KAknsIIDQgnNoteKeyguardLockedAnim4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteKeyguardLockedAnim4 };

static const TAknsItemID KAknsIIDQgnNoteKeyguardTounlockAnim1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteKeyguardTounlockAnim1 };

static const TAknsItemID KAknsIIDQgnNoteKeyguardTounlockAnim2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteKeyguardTounlockAnim2 };

static const TAknsItemID KAknsIIDQgnNoteKeyguardTounlockAnim3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteKeyguardTounlockAnim3 };

static const TAknsItemID KAknsIIDQgnNoteKeyguardTounlockAnim4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteKeyguardTounlockAnim4 };

static const TAknsItemID KAknsIIDQgnNoteKeyguardUnlockedAnim1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteKeyguardUnlockedAnim1 };

static const TAknsItemID KAknsIIDQgnNoteKeyguardUnlockedAnim2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteKeyguardUnlockedAnim2 };

static const TAknsItemID KAknsIIDQgnNoteKeyguardUnlockedAnim3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteKeyguardUnlockedAnim3 };

static const TAknsItemID KAknsIIDQgnNoteKeyguardUnlockedAnim4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteKeyguardUnlockedAnim4 };

static const TAknsItemID KAknsIIDQgnIndiDialerEightLatin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerEightLatin };

static const TAknsItemID KAknsIIDQgnIndiDialerFiveLatin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerFiveLatin };

static const TAknsItemID KAknsIIDQgnIndiDialerFourLatin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerFourLatin };

static const TAknsItemID KAknsIIDQgnIndiDialerHashLatin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerHashLatin };

static const TAknsItemID KAknsIIDQgnIndiDialerNineLatin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerNineLatin };

static const TAknsItemID KAknsIIDQgnIndiDialerOneLatin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerOneLatin };

static const TAknsItemID KAknsIIDQgnIndiDialerPrefixLatin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerPrefixLatin };

static const TAknsItemID KAknsIIDQgnIndiDialerSevenLatin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerSevenLatin };

static const TAknsItemID KAknsIIDQgnIndiDialerSixLatin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerSixLatin };

static const TAknsItemID KAknsIIDQgnIndiDialerSpeedDial =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerSpeedDial };

static const TAknsItemID KAknsIIDQgnIndiDialerThreeLatin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerThreeLatin };

static const TAknsItemID KAknsIIDQgnIndiDialerTwoLatin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerTwoLatin };

static const TAknsItemID KAknsIIDQgnIndiDialerZeroLatin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerZeroLatin };

static const TAknsItemID KAknsIIDQgnMenuAppshellMp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuAppshellMp };

static const TAknsItemID KAknsIIDQgnMenuDrmExpForbid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuDrmExpForbid };

static const TAknsItemID KAknsIIDQgnMenuDrmRightsExp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuDrmRightsExp };

static const TAknsItemID KAknsIIDQgnMenuHwrTraining =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuHwrTraining };

static const TAknsItemID KAknsIIDQgnMenuImed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuImed };

static const TAknsItemID KAknsIIDQgnMenuIr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuIr };

static const TAknsItemID KAknsIIDQgnMenuMceGene =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMceGene };

static const TAknsItemID KAknsIIDQgnMenuMcePostcard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMcePostcard };

static const TAknsItemID KAknsIIDQgnMenuMceSelMes =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMceSelMes };

static const TAknsItemID KAknsIIDQgnMenuMceSms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMceSms };

static const TAknsItemID KAknsIIDQgnMenuMceSyncmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMceSyncmail };

static const TAknsItemID KAknsIIDQgnMenuMceUnified =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMceUnified };

static const TAknsItemID KAknsIIDQgnMenuNfc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuNfc };

static const TAknsItemID KAknsIIDQgnMenuSearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuSearch };

static const TAknsItemID KAknsIIDQgnMenuTrk =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuTrk };

static const TAknsItemID KAknsIIDQgnMenuUrl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuUrl };

static const TAknsItemID KAknsIIDQgnMenuVideoSharing =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuVideoSharing };

static const TAknsItemID KAknsIIDQgnIndiCam4CameraBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4CameraBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4FlashOffBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4FlashOffBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4FlashOnBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4FlashOnBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4FocusFrameAutoBlBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4FocusFrameAutoBlBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4FocusFrameAutoBrBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4FocusFrameAutoBrBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4FocusFrameAutoTlBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4FocusFrameAutoTlBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4FocusFrameAutoTrBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4FocusFrameAutoTrBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4MemoryMassBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4MemoryMassBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4MemoryMmcBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4MemoryMmcBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4MemoryPhoneBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4MemoryPhoneBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4PauseBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4PauseBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality03mpLowBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality03mpLowBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality08mpLowBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality08mpLowBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality13mpLowBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality13mpLowBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality13mpMediumBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality13mpMediumBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality1mpLowBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality1mpLowBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality2mpHighBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality2mpHighBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality2mpMediumBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality2mpMediumBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality3mpHighBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality3mpHighBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality3mpMediumBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality3mpMediumBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality5mpHighBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality5mpHighBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4QualityEmailSharingBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4QualityEmailSharingBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4QualitySharingBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4QualitySharingBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4QualityWideHighBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4QualityWideHighBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4RecordBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4RecordBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4SequenceBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4SequenceBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4SequenceBurstBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4SequenceBurstBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4ShakeBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ShakeBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomBottomBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomBottomBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomMarkerBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomMarkerBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomMarkerSelectedBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomMarkerSelectedBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomMaxBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomMaxBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomMiddleBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomMiddleBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomMinBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomMinBmp };

static const TAknsItemID KAknsIIDQgnIndiCam4ZoomTopBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ZoomTopBmp };

static const TAknsItemID KAknsIIDQgnIndiCamBatteryStrengthBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCamBatteryStrengthBmp };

static const TAknsItemID KAknsIIDQgnIndiVid4AudioBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4AudioBmp };

static const TAknsItemID KAknsIIDQgnIndiVid4AudioMuteBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4AudioMuteBmp };

static const TAknsItemID KAknsIIDQgnIndiVid4ContinuousAfBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4ContinuousAfBmp };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityEmailHighBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityEmailHighBmp };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityEmailNormalBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityEmailNormalBmp };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityHighBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityHighBmp };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityNormalBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityNormalBmp };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityTvHighBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityTvHighBmp };

static const TAknsItemID KAknsIIDQgnIndiVid4QualityTvNormalBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4QualityTvNormalBmp };

static const TAknsItemID KAknsIIDQgnIndiVid4StabilizeOnBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4StabilizeOnBmp };

static const TAknsItemID KAknsIIDQgnIndiVid4VideoBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4VideoBmp };

static const TAknsItemID KAknsIIDQgnPropCamBatteryIconBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCamBatteryIconBmp };

static const TAknsItemID KAknsIIDQgnPropCodec3gpBmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCodec3gpBmp };

static const TAknsItemID KAknsIIDQgnPropCodecMp4Bmp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCodecMp4Bmp };

static const TAknsItemID KAknsIIDQgnMenuFmgrRemoteDrive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuFmgrRemoteDrive };

static const TAknsItemID KAknsIIDQgnGrafBlidWalk =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBlidWalk };

static const TAknsItemID KAknsIIDQgnIndiWlanSnifferPluginOn0 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWlanSnifferPluginOn0 };

static const TAknsItemID KAknsIIDQgnIndiWlanSnifferPluginOn1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWlanSnifferPluginOn1 };

static const TAknsItemID KAknsIIDQgnPropCodecWmv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCodecWmv };

static const TAknsItemID KAknsIIDQgnPropLinkConnectionManager =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLinkConnectionManager };

static const TAknsItemID KAknsIIDQgnPropPbCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCall };

static const TAknsItemID KAknsIIDQgnPropPbChat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbChat };

static const TAknsItemID KAknsIIDQgnPropPbCommTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommTab3 };

static const TAknsItemID KAknsIIDQgnPropPbDetailsTab3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbDetailsTab3 };

static const TAknsItemID KAknsIIDQgnPropPbDflt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbDflt };

static const TAknsItemID KAknsIIDQgnPropPbEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbEmail };

static const TAknsItemID KAknsIIDQgnPropPbMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbMsg };

static const TAknsItemID KAknsIIDQgnPropPbMydat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbMydat };

static const TAknsItemID KAknsIIDQgnPropPbOffline =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbOffline };

static const TAknsItemID KAknsIIDQgnPropPbOnline =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbOnline };

static const TAknsItemID KAknsIIDQgnPropPbPtt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbPtt };

static const TAknsItemID KAknsIIDQgnPropPbSdn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbSdn };

static const TAknsItemID KAknsIIDQgnPropPbSim =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbSim };

static const TAknsItemID KAknsIIDQgnPropPbThumbUnknown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbThumbUnknown };

static const TAknsItemID KAknsIIDQgnPropPbTopc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbTopc };

static const TAknsItemID KAknsIIDQgnPropPbUnknown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbUnknown };

static const TAknsItemID KAknsIIDQgnPropPbUrl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbUrl };

static const TAknsItemID KAknsIIDQgnPropPbVcall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbVcall };

static const TAknsItemID KAknsIIDQgnPropPbVocall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbVocall };

static const TAknsItemID KAknsIIDQsnFrInputPreviewMiddle =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrInputPreviewMiddle };

static const TAknsItemID KAknsIIDQsnFrInputPreviewSideL =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrInputPreviewSideL };

static const TAknsItemID KAknsIIDQsnFrInputPreviewSideR =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrInputPreviewSideR };

static const TAknsItemID KAknsIIDQgnIndiImMsgEditor =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImMsgEditor };

static const TAknsItemID KAknsIIDQgnIndiQdialEightAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiQdialEightAdd };

static const TAknsItemID KAknsIIDQgnIndiQdialFiveAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiQdialFiveAdd };

static const TAknsItemID KAknsIIDQgnIndiQdialFourAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiQdialFourAdd };

static const TAknsItemID KAknsIIDQgnIndiQdialNineAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiQdialNineAdd };

static const TAknsItemID KAknsIIDQgnIndiQdialOneAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiQdialOneAdd };

static const TAknsItemID KAknsIIDQgnIndiQdialSevenAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiQdialSevenAdd };

static const TAknsItemID KAknsIIDQgnIndiQdialSixAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiQdialSixAdd };

static const TAknsItemID KAknsIIDQgnIndiQdialThreeAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiQdialThreeAdd };

static const TAknsItemID KAknsIIDQgnIndiQdialTwoAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiQdialTwoAdd };

static const TAknsItemID KAknsIIDQgnMenuDm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuDm };

static const TAknsItemID KAknsIIDQgnPropImFriendRequest =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendRequest };

static const TAknsItemID KAknsIIDQgnPropImOngoingConv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImOngoingConv };

static const TAknsItemID KAknsIIDQgnPropImOngoingConvNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImOngoingConvNew };

static const TAknsItemID KAknsIIDQgnPropImService =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImService };

static const TAknsItemID KAknsIIDQgnPropImServiceTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImServiceTab2 };

static const TAknsItemID KAknsIIDQgnPropNrtypCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypCall };

static const TAknsItemID KAknsIIDQgnPropNrtypChat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypChat };

static const TAknsItemID KAknsIIDQgnPropNrtypPtt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypPtt };

static const TAknsItemID KAknsIIDQgnPropNrtypVcall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNrtypVcall };

static const TAknsItemID KAknsIIDQgnStatKorCase =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatKorCase };

static const TAknsItemID KAknsIIDQgnStatKorCaseSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatKorCaseSelect };

static const TAknsItemID KAknsIIDQgnFsActionMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsActionMsg };

static const TAknsItemID KAknsIIDQgnFsContactsFavorite =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsContactsFavorite };

static const TAknsItemID KAknsIIDQgnFsContactsIndiMovable =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsContactsIndiMovable };

static const TAknsItemID KAknsIIDQgnFsFrRibbonBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsFrRibbonBottom };

static const TAknsItemID KAknsIIDQgnFsFrRibbonCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsFrRibbonCenter };

static const TAknsItemID KAknsIIDQgnFsFrRibbonSchedulerBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsFrRibbonSchedulerBottom };

static const TAknsItemID KAknsIIDQgnFsFrRibbonSchedulerCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsFrRibbonSchedulerCenter };

static const TAknsItemID KAknsIIDQgnFsFrRibbonSchedulerTop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsFrRibbonSchedulerTop };

static const TAknsItemID KAknsIIDQgnFsFrRibbonTop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsFrRibbonTop };

static const TAknsItemID KAknsIIDQgnFsHscrActionArrowDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHscrActionArrowDown };

static const TAknsItemID KAknsIIDQgnFsHscrActionArrowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsHscrActionArrowUp };

static const TAknsItemID KAknsIIDQgnFsIndiCaleTrackingAccept =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiCaleTrackingAccept };

static const TAknsItemID KAknsIIDQgnFsIndiCaleTrackingNone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiCaleTrackingNone };

static const TAknsItemID KAknsIIDQgnFsIndiCaleTrackingReject =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiCaleTrackingReject };

static const TAknsItemID KAknsIIDQgnFsIndiCaleTrackingTentative =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsIndiCaleTrackingTentative };

static const TAknsItemID KAknsIIDQgnFsPropConfActive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsPropConfActive };

static const TAknsItemID KAknsIIDQgnFsPropConfDropped =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsPropConfDropped };

static const TAknsItemID KAknsIIDQgnFsPropConfJoined =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsPropConfJoined };

static const TAknsItemID KAknsIIDQgnFsPropConfNotHandled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFsPropConfNotHandled };

static const TAknsItemID KAknsIIDQgnIndiInputClr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputClr };

static const TAknsItemID KAknsIIDQgnIndiInputHiraganaPredict =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputHiraganaPredict };

static const TAknsItemID KAknsIIDQgnIndiInputJpnAlphaFw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputJpnAlphaFw };

static const TAknsItemID KAknsIIDQgnIndiInputJpnAlphaHw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputJpnAlphaHw };

static const TAknsItemID KAknsIIDQgnIndiInputJpnCommit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputJpnCommit };

static const TAknsItemID KAknsIIDQgnIndiInputJpnFullWidth =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputJpnFullWidth };

static const TAknsItemID KAknsIIDQgnIndiInputJpnHalfWidth =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputJpnHalfWidth };

static const TAknsItemID KAknsIIDQgnIndiInputJpnNumberFw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputJpnNumberFw };

static const TAknsItemID KAknsIIDQgnIndiInputJpnNumberHw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputJpnNumberHw };

static const TAknsItemID KAknsIIDQgnIndiInputJpnOtherModes =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputJpnOtherModes };

static const TAknsItemID KAknsIIDQgnIndiInputJpnStartPredict =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputJpnStartPredict };

static const TAknsItemID KAknsIIDQgnIntraHomescreenPlugin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraHomescreenPlugin };

static const TAknsItemID KAknsIIDQgnIntraMenuChangeDest =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraMenuChangeDest };

static const TAknsItemID KAknsIIDQgnIntraMenuConnectIntranet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraMenuConnectIntranet };

static const TAknsItemID KAknsIIDQgnIntraMenuCurrentDestination =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraMenuCurrentDestination };

static const TAknsItemID KAknsIIDQgnIntraMenuHiddenWlan =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraMenuHiddenWlan };

static const TAknsItemID KAknsIIDQgnIntraMenuInternet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraMenuInternet };

static const TAknsItemID KAknsIIDQgnIntraMenuIntranet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraMenuIntranet };

static const TAknsItemID KAknsIIDQgnIntraMenuIntranetConnected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraMenuIntranetConnected };

static const TAknsItemID KAknsIIDQgnIntraMenuManualConnection =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraMenuManualConnection };

static const TAknsItemID KAknsIIDQgnIntraMenuReturnToHomescreen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraMenuReturnToHomescreen };

static const TAknsItemID KAknsIIDQgnIntraMenuStartBrowser =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraMenuStartBrowser };

static const TAknsItemID KAknsIIDQgnIntraMenuViewOtherWlans =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraMenuViewOtherWlans };

static const TAknsItemID KAknsIIDQgnIntraMenuVpnAp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIntraMenuVpnAp };

static const TAknsItemID KAknsIIDQgnMenuIntranet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuIntranet };

static const TAknsItemID KAknsIIDQgnStatCaseHiraganaKanji =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseHiraganaKanji };

static const TAknsItemID KAknsIIDQgnStatCaseKatakanaFw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseKatakanaFw };

static const TAknsItemID KAknsIIDQgnStatCaseKatakanaHw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseKatakanaHw };

static const TAknsItemID KAknsIIDQsnCpScrollBgBottomPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollBgBottomPressed };

static const TAknsItemID KAknsIIDQsnCpScrollBgMiddlePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollBgMiddlePressed };

static const TAknsItemID KAknsIIDQsnCpScrollBgTopPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollBgTopPressed };

static const TAknsItemID KAknsIIDQsnCpScrollHandleBottomPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHandleBottomPressed };

static const TAknsItemID KAknsIIDQsnCpScrollHandleMiddlePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHandleMiddlePressed };

static const TAknsItemID KAknsIIDQsnCpScrollHandleTopPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHandleTopPressed };

static const TAknsItemID KAknsIIDQsnCpScrollHorizontalBgBottomPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHorizontalBgBottomPressed };

static const TAknsItemID KAknsIIDQsnCpScrollHorizontalBgMiddlePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHorizontalBgMiddlePressed };

static const TAknsItemID KAknsIIDQsnCpScrollHorizontalBgTopPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHorizontalBgTopPressed };

static const TAknsItemID KAknsIIDQsnCpScrollHorizontalHandleBottomPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHorizontalHandleBottomPressed };

static const TAknsItemID KAknsIIDQsnCpScrollHorizontalHandleMiddlePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHorizontalHandleMiddlePressed };

static const TAknsItemID KAknsIIDQsnCpScrollHorizontalHandleTopPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnCpScrollHorizontalHandleTopPressed };

static const TAknsItemID KAknsIIDQsnFrKeypadButton2SmallInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrKeypadButton2SmallInactive };

static const TAknsItemID KAknsIIDQsnFrKeypadButton2SmallNormal =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrKeypadButton2SmallNormal };

static const TAknsItemID KAknsIIDQsnFrKeypadButton2SmallPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrKeypadButton2SmallPressed };

static const TAknsItemID KAknsIIDQsnFrKeypadButtonSmallInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrKeypadButtonSmallInactive };

static const TAknsItemID KAknsIIDQsnFrKeypadButtonSmallNormal =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrKeypadButtonSmallNormal };

static const TAknsItemID KAknsIIDQsnFrKeypadButtonSmallPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQsnFrKeypadButtonSmallPressed };

static const TAknsItemID KAknsIIDMuiCoverHandle =
    { EAknsMajorGeneric, EAknsMinorGenericMuiCoverHandle };

static const TAknsItemID KAknsIIDMuiDlProgressLsc =
    { EAknsMajorGeneric, EAknsMinorGenericMuiDlProgressLsc };

static const TAknsItemID KAknsIIDMuiHandle =
    { EAknsMajorGeneric, EAknsMinorGenericMuiHandle };

static const TAknsItemID KAknsIIDMuiProgressLsc =
    { EAknsMajorGeneric, EAknsMinorGenericMuiProgressLsc };

static const TAknsItemID KAknsIIDMuiSliderLsc =
    { EAknsMajorGeneric, EAknsMinorGenericMuiSliderLsc };

static const TAknsItemID KAknsIIDMuiSliderPrt =
    { EAknsMajorGeneric, EAknsMinorGenericMuiSliderPrt };

static const TAknsItemID KAknsIIDQgnIndiCam4Minus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Minus };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimConive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimConive };

static const TAknsItemID KAknsIIDQgnIndiVideoVolMute =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoVolMute };

static const TAknsItemID KAknsIIDQgnIndiDialerInternet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerInternet };

static const TAknsItemID KAknsIIDQgnIndiDialerSilent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerSilent };

static const TAknsItemID KAknsIIDQgnIndiDialerVoicemail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiDialerVoicemail };

static const TAknsItemID KAknsIIDQgnIndiInputFshwrSctPage1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputFshwrSctPage1 };

static const TAknsItemID KAknsIIDQgnIndiInputFshwrSctPage2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputFshwrSctPage2 };

static const TAknsItemID KAknsIIDQgnIndiInputJpnConvert =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputJpnConvert };

static const TAknsItemID KAknsIIDQgnIndiTbBack =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbBack };

static const TAknsItemID KAknsIIDQgnIndiTbDocNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbDocNew };

static const TAknsItemID KAknsIIDQgnIndiTbFindBack =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFindBack };

static const TAknsItemID KAknsIIDQgnIndiTbFindMode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFindMode };

static const TAknsItemID KAknsIIDQgnIndiTbFindNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFindNew };

static const TAknsItemID KAknsIIDQgnIndiTbFindNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFindNext };

static const TAknsItemID KAknsIIDQgnIndiTbNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbNext };

static const TAknsItemID KAknsIIDQgnIndiTbScrolldown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbScrolldown };

static const TAknsItemID KAknsIIDQgnIndiTbScrollup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbScrollup };

static const TAknsItemID KAknsIIDQgnIndiTbSheetAccept =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbSheetAccept };

static const TAknsItemID KAknsIIDQgnIndiTbZoomAccept =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbZoomAccept };

static const TAknsItemID KAknsIIDQgnIndiTbZoomIn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbZoomIn };

static const TAknsItemID KAknsIIDQgnIndiTbZoomOut =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbZoomOut };

static const TAknsItemID KAknsIIDQgnIndiVded2Pause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVded2Pause };

static const TAknsItemID KAknsIIDQgnIndiVded2PausePressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVded2PausePressed };

static const TAknsItemID KAknsIIDQgnIndiVdedPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdedPlay };

static const TAknsItemID KAknsIIDQgnIndiVdedPlayPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdedPlayPressed };

static const TAknsItemID KAknsIIDQgnMenuMshop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMshop };

static const TAknsItemID KAknsIIDQgnPropClkCntdwnTimer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClkCntdwnTimer };

static const TAknsItemID KAknsIIDQgnPropClkNewAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClkNewAlarm };

static const TAknsItemID KAknsIIDQgnPropClkStpWatch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClkStpWatch };

static const TAknsItemID KAknsIIDQgnPropClkWrldClock =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClkWrldClock };

static const TAknsItemID KAknsIIDQgnIndiInputJpnPredict =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputJpnPredict };

static const TAknsItemID KAknsIIDQgnIndiInputKatakanaHw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputKatakanaHw };

static const TAknsItemID KAknsIIDQgnIndiMusicshopTbActiveDownloads =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicshopTbActiveDownloads };

static const TAknsItemID KAknsIIDQgnIndiMusicshopTbNoActiveDownloads =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicshopTbNoActiveDownloads };

static const TAknsItemID KAknsIIDQgnIndiMusicshopTbSignin =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicshopTbSignin };

static const TAknsItemID KAknsIIDQgnIndiMusicshopTbStoreLink =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicshopTbStoreLink };

static const TAknsItemID KAknsIIDQgnIndiTbSwupdDetail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbSwupdDetail };

static const TAknsItemID KAknsIIDQgnIndiTbSwupdHistory =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbSwupdHistory };

static const TAknsItemID KAknsIIDQgnIndiTbSwupdStart =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbSwupdStart };

static const TAknsItemID KAknsIIDQgnMenuSwupdate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuSwupdate };

static const TAknsItemID KAknsIIDQgnCaleIndiDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCaleIndiDelete };

static const TAknsItemID KAknsIIDQgnCaleIndiDone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCaleIndiDone };

static const TAknsItemID KAknsIIDQgnCaleIndiEdit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCaleIndiEdit };

static const TAknsItemID KAknsIIDQgnCaleIndiNotDone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCaleIndiNotDone };

static const TAknsItemID KAknsIIDQgnFseActionMenuAttachDownloadAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAttachDownloadAll };

static const TAknsItemID KAknsIIDQgnFseActionMenuAttachOpen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAttachOpen };

static const TAknsItemID KAknsIIDQgnFseActionMenuAttachSave =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFseActionMenuAttachSave };

static const TAknsItemID KAknsIIDQgnGridEditBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGridEditBg };

static const TAknsItemID KAknsIIDQgnGridMenuAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGridMenuAdd };

static const TAknsItemID KAknsIIDQgnMenuBackup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuBackup };

static const TAknsItemID KAknsIIDQgnMenuRestore =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuRestore };

static const TAknsItemID KAknsIIDQgnMenuTravel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuTravel };

static const TAknsItemID KAknsIIDQgnMenuUpgrade =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuUpgrade };

static const TAknsItemID KAknsIIDQgnPropNoteListAlphaKorTab2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNoteListAlphaKorTab2 };

static const TAknsItemID KAknsIIDQgnIndiCam4TbGotoGallery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbGotoGallery };

static const TAknsItemID KAknsIIDQgnMenuFolderEmpty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuFolderEmpty };

static const TAknsItemID KAknsIIDQgnPropAudioMusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAudioMusic };

static const TAknsItemID KAknsIIDQgnPropAudioToneOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropAudioToneOff };

static const TAknsItemID KAknsIIDQgnGrafCam4TbBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCam4TbBottom };

static const TAknsItemID KAknsIIDQgnGrafCam4TbArrowDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCam4TbArrowDown };

static const TAknsItemID KAknsIIDQgnGrafCam4TbArrowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCam4TbArrowUp };

static const TAknsItemID KAknsIIDQgnGrafCam4TbBody =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCam4TbBody };

static const TAknsItemID KAknsIIDQgnPropLocevTrigger =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocevTrigger };

static const TAknsItemID KAknsIIDQgnGrafCam4TbFocus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCam4TbFocus };

static const TAknsItemID KAknsIIDQgnGrafCam4TbGap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCam4TbGap };

static const TAknsItemID KAknsIIDQgnGrafCam4TbTooltipBody =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCam4TbTooltipBody };

static const TAknsItemID KAknsIIDQgnGrafCam4TbTooltipEnd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCam4TbTooltipEnd };

static const TAknsItemID KAknsIIDQgnGrafCam4TbTop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCam4TbTop };

static const TAknsItemID KAknsIIDQgnIndiButtonSilence =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonSilence };

static const TAknsItemID KAknsIIDQgnIndiCam4GeotagOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4GeotagOff };

static const TAknsItemID KAknsIIDQgnIndiCam4GeotagOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4GeotagOn };

static const TAknsItemID KAknsIIDQgnNoteLocevAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteLocevAlarm };

static const TAknsItemID KAknsIIDQgnNoteLocevAlarmAcc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteLocevAlarmAcc };

static const TAknsItemID KAknsIIDQgnNoteLocevAlarmInacc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteLocevAlarmInacc };

static const TAknsItemID KAknsIIDQgnNoteLocevAlarmInaccHeavy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteLocevAlarmInaccHeavy };

static const TAknsItemID KAknsIIDQgnPropLocevActiveSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocevActiveSmall };

static const TAknsItemID KAknsIIDQgnPropLocevCompleted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocevCompleted };

static const TAknsItemID KAknsIIDQgnPropLocevCompletedSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocevCompletedSmall };

static const TAknsItemID KAknsIIDQgnPropLocevCurrentLocation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocevCurrentLocation };

static const TAknsItemID KAknsIIDQgnPropLocevDeleteSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocevDeleteSmall };

static const TAknsItemID KAknsIIDQgnPropLocevDraft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocevDraft };

static const TAknsItemID KAknsIIDQgnPropLocevDraftSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocevDraftSmall };

static const TAknsItemID KAknsIIDQgnPropLocevLandmark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocevLandmark };

static const TAknsItemID KAknsIIDQgnPropLocevMap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocevMap };

static const TAknsItemID KAknsIIDQgnPropLocevNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocevNew };

static const TAknsItemID KAknsIIDCam4TbArrowDown =
    { EAknsMajorGeneric, EAknsMinorGenericCam4TbArrowDown };

static const TAknsItemID KAknsIIDCam4TbArrowUp =
    { EAknsMajorGeneric, EAknsMinorGenericCam4TbArrowUp };

static const TAknsItemID KAknsIIDCam4TbBody =
    { EAknsMajorGeneric, EAknsMinorGenericCam4TbBody };

static const TAknsItemID KAknsIIDCam4TbBottom =
    { EAknsMajorGeneric, EAknsMinorGenericCam4TbBottom };

static const TAknsItemID KAknsIIDCam4TbFocus =
    { EAknsMajorGeneric, EAknsMinorGenericCam4TbFocus };

static const TAknsItemID KAknsIIDCam4TbTooltipBody =
    { EAknsMajorGeneric, EAknsMinorGenericCam4TbTooltipBody };

static const TAknsItemID KAknsIIDCam4TbTooltipEnd =
    { EAknsMajorGeneric, EAknsMinorGenericCam4TbTooltipEnd };

static const TAknsItemID KAknsIIDCam4TbTop =
    { EAknsMajorGeneric, EAknsMinorGenericCam4TbTop };

static const TAknsItemID KAknsIIDQgnCam4TbArrowDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCam4TbArrowDown };

static const TAknsItemID KAknsIIDQgnCam4TbArrowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCam4TbArrowUp };

static const TAknsItemID KAknsIIDQgnCam4TbBody =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCam4TbBody };

static const TAknsItemID KAknsIIDQgnCam4TbBottom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCam4TbBottom };

static const TAknsItemID KAknsIIDQgnCam4TbFocus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCam4TbFocus };

static const TAknsItemID KAknsIIDQgnCam4TbTooltipBody =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCam4TbTooltipBody };

static const TAknsItemID KAknsIIDQgnCam4TbTooltipEnd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCam4TbTooltipEnd };

static const TAknsItemID KAknsIIDQgnCam4TbTop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnCam4TbTop };

static const TAknsItemID KAknsIIDQgnMenuDownload =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuDownload };

static const TAknsItemID KAknsIIDQgnMenuGroupApps =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupApps };

static const TAknsItemID KAknsIIDQgnMenuMaps =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMaps };

static const TAknsItemID KAknsIIDQgnMenuMusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMusic };

static const TAknsItemID KAknsIIDQgnMenuNdg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuNdg };

static const TAknsItemID KAknsIIDQgnMenuPubCxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuPubCxt };

static const TAknsItemID KAknsIIDQgnMenuWeb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuWeb };

static const TAknsItemID KAknsIIDQgnNoteBattCharging0 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteBattCharging0 };

static const TAknsItemID KAknsIIDQgnNoteBattCharging1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteBattCharging1 };

static const TAknsItemID KAknsIIDQgnMenuPhotos =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuPhotos };

static const TAknsItemID KAknsIIDQgnMenuVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuVideo };

static const TAknsItemID KAknsIIDQgnMusicGrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMusicGrid };

static const TAknsItemID KAknsIIDQgnPropClockHomecity =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClockHomecity };

static const TAknsItemID KAknsIIDQgnIndiAiEplgDefault =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiEplgDefault };

static const TAknsItemID KAknsIIDQgnIndiAiEplgRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiEplgRead };

static const TAknsItemID KAknsIIDQgnIndiAiEplgUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAiEplgUnread };

static const TAknsItemID KAknsIIDQgnIndiTbCam4GotoMain =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCam4GotoMain };

static const TAknsItemID KAknsIIDQgnMenuGames =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGames };

static const TAknsItemID KAknsIIDQgnHomeAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeAdd };

static const TAknsItemID KAknsIIDQgnHomeEditBgWidget =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeEditBgWidget };

static const TAknsItemID KAknsIIDQgnIndiCam4TbMark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbMark };

static const TAknsItemID KAknsIIDQgnIndiCam4TbUpload =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbUpload };

static const TAknsItemID KAknsIIDQgnIndiHomePage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHomePage };

static const TAknsItemID KAknsIIDQgnIndiHomeProfileGeneral =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHomeProfileGeneral };

static const TAknsItemID KAknsIIDQgnIndiHomeProfileSilent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHomeProfileSilent };

static const TAknsItemID KAknsIIDQgnIndiSliderMarker =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSliderMarker };

static const TAknsItemID KAknsIIDQgnIndiTvNoSignal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTvNoSignal };

static const TAknsItemID KAknsIIDQgnNoteSwupdateNotification =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteSwupdateNotification };

static const TAknsItemID KAknsIIDQgnPropClkCntdwnTimerTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClkCntdwnTimerTab4 };

static const TAknsItemID KAknsIIDQgnPropClkNewAlarmTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClkNewAlarmTab4 };

static const TAknsItemID KAknsIIDQgnPropClkStpWatchTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClkStpWatchTab4 };

static const TAknsItemID KAknsIIDQgnPropClkWrldClkTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClkWrldClkTab4 };

static const TAknsItemID KAknsIIDQgnPropTv3g =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropTv3g };

static const TAknsItemID KAknsIIDQgnPropTvDvbH =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropTvDvbH };

static const TAknsItemID KAknsIIDQsnHomeClockAnalogueFace =
    { EAknsMajorGeneric, EAknsMinorGenericQsnHomeClockAnalogueFace };

static const TAknsItemID KAknsIIDQsnHomeClockAnaloguePointerHour =
    { EAknsMajorGeneric, EAknsMinorGenericQsnHomeClockAnaloguePointerHour };

static const TAknsItemID KAknsIIDQgnIndiMupTbForward =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbForward };

static const TAknsItemID KAknsIIDQgnIndiMupTbRewind =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupTbRewind };

static const TAknsItemID KAknsIIDQgnIndiTbCam4PhotoDetail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCam4PhotoDetail };

static const TAknsItemID KAknsIIDQgnPropSetGeneNotifilight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetGeneNotifilight };

static const TAknsItemID KAknsIIDQgnHomePhotoMask =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePhotoMask };

static const TAknsItemID KAknsIIDQgnIndiBtSignalGoodAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBtSignalGoodAdd };

static const TAknsItemID KAknsIIDQgnIndiBtSignalLowAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBtSignalLowAdd };

static const TAknsItemID KAknsIIDQgnIndiBtSignalMedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBtSignalMedAdd };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality8mpHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality8mpHigh };

static const TAknsItemID KAknsIIDQgnIndiCam4TbFacedet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbFacedet };

static const TAknsItemID KAknsIIDQgnIndiMemcMassAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMemcMassAdd };

static const TAknsItemID KAknsIIDQgnIndiVdcRecTvAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdcRecTvAdd };

static const TAknsItemID KAknsIIDQgnIndiVdcTbDetails =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdcTbDetails };

static const TAknsItemID KAknsIIDQgnIndiVdcTbDownload =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdcTbDownload };

static const TAknsItemID KAknsIIDQgnIndiVdcTbDownloadCancel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdcTbDownloadCancel };

static const TAknsItemID KAknsIIDQgnIndiVdcTbDownloadResumes =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdcTbDownloadResumes };

static const TAknsItemID KAknsIIDQgnIndiVdcVideoNewAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVdcVideoNewAdd };

static const TAknsItemID KAknsIIDQgnIndiVid4TbStill =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4TbStill };

static const TAknsItemID KAknsIIDQgnIndiVid4TbVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVid4TbVideo };

static const TAknsItemID KAknsIIDQgnMenuClkAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuClkAlarm };

static const TAknsItemID KAknsIIDQgnNoteDefaultVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteDefaultVideo };

static const TAknsItemID KAknsIIDQgnPropClkClockTab4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClkClockTab4 };

static const TAknsItemID KAknsIIDQgnGrafMusicHomeAnimDownload00 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMusicHomeAnimDownload00 };

static const TAknsItemID KAknsIIDQgnGrafMusicHomeAnimDownload01 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMusicHomeAnimDownload01 };

static const TAknsItemID KAknsIIDQgnGrafMusicHomeAnimDownload02 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMusicHomeAnimDownload02 };

static const TAknsItemID KAknsIIDQgnGrafMusicHomeAnimDownload03 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMusicHomeAnimDownload03 };

static const TAknsItemID KAknsIIDQgnGrafMusicHomeAnimDownload04 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMusicHomeAnimDownload04 };

static const TAknsItemID KAknsIIDQgnGrafMusicHomeAnimDownload05 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMusicHomeAnimDownload05 };

static const TAknsItemID KAknsIIDQgnGrafMusicHomeAnimDownload06 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMusicHomeAnimDownload06 };

static const TAknsItemID KAknsIIDQgnGrafMusicHomeAnimDownload07 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMusicHomeAnimDownload07 };

static const TAknsItemID KAknsIIDQgnIndiCalLocatEventAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalLocatEventAdd };

static const TAknsItemID KAknsIIDQgnIndiCam4ModeLowlight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4ModeLowlight };

static const TAknsItemID KAknsIIDQgnIndiHomeProfileTimed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHomeProfileTimed };

static const TAknsItemID KAknsIIDQgnIndiMupHomeDownloadCompleted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupHomeDownloadCompleted };

static const TAknsItemID KAknsIIDQgnIndiMupHomeNoMusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupHomeNoMusic };

static const TAknsItemID KAknsIIDQgnIndiMupHomePause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupHomePause };

static const TAknsItemID KAknsIIDQgnIndiMupHomePlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupHomePlay };

static const TAknsItemID KAknsIIDQgnNoteBtPopu =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteBtPopu };

static const TAknsItemID KAknsIIDQgnPropCodecWvga =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCodecWvga };

static const TAknsItemID KAknsIIDQgnIndiLgalTbAddToAlbum =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiLgalTbAddToAlbum };

static const TAknsItemID KAknsIIDQgnIndiLgalTbNewAlbum =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiLgalTbNewAlbum };

static const TAknsItemID KAknsIIDQgnIndiLgalTbRename =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiLgalTbRename };

static const TAknsItemID KAknsIIDQgnIndiLgalTbSlideshow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiLgalTbSlideshow };

static const TAknsItemID KAknsIIDQgnIndiNcimForgotPsw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiNcimForgotPsw };

static const TAknsItemID KAknsIIDQgnIndiSctrlSkMaskMiddlePrt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSctrlSkMaskMiddlePrt };

static const TAknsItemID KAknsIIDQgnIndiTbDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbDelete };

static const TAknsItemID KAknsIIDQgnIndiTbDeleteDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbDeleteDimmed };

static const TAknsItemID KAknsIIDQgnIndiTbMark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMark };

static const TAknsItemID KAknsIIDQgnIndiTbUnmark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbUnmark };

static const TAknsItemID KAknsIIDQgnIndiTbUpload =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbUpload };

static const TAknsItemID KAknsIIDQgnMenuHomeMedia =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuHomeMedia };

static const TAknsItemID KAknsIID3dAudio =
    { EAknsMajorGeneric, EAknsMinorGeneric3dAudio };

static const TAknsItemID KAknsIIDQgnAppSnifferGrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnAppSnifferGrid };

static const TAknsItemID KAknsIIDQgnIndiCam4TbSwitchStill =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbSwitchStill };

static const TAknsItemID KAknsIIDQgnIndiCam4TbSwitchVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbSwitchVideo };

static const TAknsItemID KAknsIIDQgnIndiFlashKeypadBackground =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashKeypadBackground };

static const TAknsItemID KAknsIIDQgnIndiFlashKeypadButtonBackground =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashKeypadButtonBackground };

static const TAknsItemID KAknsIIDQgnIndiFlashKeypadButtonBackgroundAlt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashKeypadButtonBackgroundAlt };

static const TAknsItemID KAknsIIDQgnIndiFlashKeypadDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashKeypadDown };

static const TAknsItemID KAknsIIDQgnIndiFlashKeypadExitFs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashKeypadExitFs };

static const TAknsItemID KAknsIIDQgnIndiFlashKeypadLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashKeypadLeft };

static const TAknsItemID KAknsIIDQgnIndiFlashKeypadLsk =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashKeypadLsk };

static const TAknsItemID KAknsIIDQgnIndiFlashKeypadRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashKeypadRight };

static const TAknsItemID KAknsIIDQgnIndiFlashKeypadRsk =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashKeypadRsk };

static const TAknsItemID KAknsIIDQgnIndiFlashKeypadSelect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashKeypadSelect };

static const TAknsItemID KAknsIIDQgnIndiFlashKeypadSelectAlt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashKeypadSelectAlt };

static const TAknsItemID KAknsIIDQgnIndiFlashKeypadUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashKeypadUp };

static const TAknsItemID KAknsIIDQgnIndiFlashToolbarFs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashToolbarFs };

static const TAknsItemID KAknsIIDQgnIndiFlashToolbarPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashToolbarPause };

static const TAknsItemID KAknsIIDQgnIndiFlashToolbarPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashToolbarPlay };

static const TAknsItemID KAknsIIDQgnIndiFlashToolbarZoom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFlashToolbarZoom };

static const TAknsItemID KAknsIIDQgnMenuActivenotes =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuActivenotes };

static const TAknsItemID KAknsIIDQgnMenuAudioTheme =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuAudioTheme };

static const TAknsItemID KAknsIIDQgnMenuFiles =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuFiles };

static const TAknsItemID KAknsIIDQgnMenuMobilesearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMobilesearch };

static const TAknsItemID KAknsIIDQgnMenuMyApplications =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMyApplications };

static const TAknsItemID KAknsIIDQgnMenuN95 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuN95 };

static const TAknsItemID KAknsIIDQgnMenuOviMaps =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuOviMaps };

static const TAknsItemID KAknsIIDQgnMenuOviMusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuOviMusic };

static const TAknsItemID KAknsIIDQgnMenuOviPhotos =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuOviPhotos };

static const TAknsItemID KAknsIIDQgnMenuOviSearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuOviSearch };

static const TAknsItemID KAknsIIDQgnMenuOviWeb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuOviWeb };

static const TAknsItemID KAknsIIDQgnMenuPeople =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuPeople };

static const TAknsItemID KAknsIIDQgnMenuSetwizard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuSetwizard };

static const TAknsItemID KAknsIIDQgnMenuSwitch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuSwitch };

static const TAknsItemID KAknsIIDQgnMenuTutor =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuTutor };

static const TAknsItemID KAknsIIDQgnMenuVr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuVr };

static const TAknsItemID KAknsIIDQgnMenuWelcomeCxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuWelcomeCxt };

static const TAknsItemID KAknsIIDQgnMenuWka =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuWka };

static const TAknsItemID KAknsIIDQsnHomeClockAnaloguePointerMinute =
    { EAknsMajorGeneric, EAknsMinorGenericQsnHomeClockAnaloguePointerMinute };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbGotoAndSearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbGotoAndSearch };

static const TAknsItemID KAknsIIDIconSyncEndRemotecontrol =
    { EAknsMajorGeneric, EAknsMinorGenericIconSyncEndRemotecontrol };

static const TAknsItemID KAknsIIDIconSyncFileSync =
    { EAknsMajorGeneric, EAknsMinorGenericIconSyncFileSync };

static const TAknsItemID KAknsIIDIconSyncProductInfo =
    { EAknsMajorGeneric, EAknsMinorGenericIconSyncProductInfo };

static const TAknsItemID KAknsIIDIconSyncRestore =
    { EAknsMajorGeneric, EAknsMinorGenericIconSyncRestore };

static const TAknsItemID KAknsIIDIconSyncTravelInfo =
    { EAknsMajorGeneric, EAknsMinorGenericIconSyncTravelInfo };

static const TAknsItemID KAknsIIDIconSyncUpgrade =
    { EAknsMajorGeneric, EAknsMinorGenericIconSyncUpgrade };

static const TAknsItemID KAknsIIDQgnGrafNpodaApp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNpodaApp };

static const TAknsItemID KAknsIIDQgnGrafSplashCatalogs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafSplashCatalogs };

static const TAknsItemID KAknsIIDQgnHqttsManagerAppsGrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHqttsManagerAppsGrid };

static const TAknsItemID KAknsIIDQgnIndiMopTableSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMopTableSmall };

static const TAknsItemID KAknsIIDQgnIndiMpVcAlbum =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpVcAlbum };

static const TAknsItemID KAknsIIDQgnIndiMpVcArtist =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpVcArtist };

static const TAknsItemID KAknsIIDQgnIndiMpVcPlaylist =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpVcPlaylist };

static const TAknsItemID KAknsIIDQgnIndiMpVcSong =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpVcSong };

static const TAknsItemID KAknsIIDQgnMenuCatalogs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuCatalogs };

static const TAknsItemID KAknsIIDQgnMenuContactbarFeedviewer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuContactbarFeedviewer };

static const TAknsItemID KAknsIIDQgnMenuContactbarSetup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuContactbarSetup };

static const TAknsItemID KAknsIIDQgnMenuContacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuContacts };

static const TAknsItemID KAknsIIDQgnMenuGroupPhone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupPhone };

static const TAknsItemID KAknsIIDQgnMenuLocev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuLocev };

static const TAknsItemID KAknsIIDQgnMenuNgage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuNgage };

static const TAknsItemID KAknsIIDQgnMenuSwicthMode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuSwicthMode };

static const TAknsItemID KAknsIIDQgnMenuVa =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuVa };

static const TAknsItemID KAknsIIDQgnMenuVdcSuite =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuVdcSuite };

static const TAknsItemID KAknsIIDQgnPropCatalogsItemBought =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCatalogsItemBought };

static const TAknsItemID KAknsIIDQgnPropCatalogsItemDependency =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCatalogsItemDependency };

static const TAknsItemID KAknsIIDQgnPropClockDefault =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropClockDefault };

static const TAknsItemID KAknsIIDQgnPropCmailNewMailbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailNewMailbox };

static const TAknsItemID KAknsIIDQgnPropServiceDefaultAvatar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropServiceDefaultAvatar };

static const TAknsItemID KAknsIIDQgnPropServiceFriendRequestReceived =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropServiceFriendRequestReceived };

static const TAknsItemID KAknsIIDQgnPropServiceFriendRequestSent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropServiceFriendRequestSent };

static const TAknsItemID KAknsIIDQgnPropServiceOffFriendRequestReceived =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropServiceOffFriendRequestReceived };

static const TAknsItemID KAknsIIDQgnPropServiceOffFriendRequestSent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropServiceOffFriendRequestSent };

static const TAknsItemID KAknsIIDQgnPropSetConnAuthentication =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetConnAuthentication };

static const TAknsItemID KAknsIIDQgnGrafImSigninScreen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafImSigninScreen };

static const TAknsItemID KAknsIIDQgnGrafImSplashScreen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafImSplashScreen };

static const TAknsItemID KAknsIIDQgnIndiCam4Facedet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Facedet };

static const TAknsItemID KAknsIIDQgnIndiCam4QualityWideNorm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4QualityWideNorm };

static const TAknsItemID KAknsIIDQgnIndiCam4TbFacedetOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbFacedetOff };

static const TAknsItemID KAknsIIDQgnIndiListView =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiListView };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerAutotuneDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerAutotuneDown };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerAutotuneDownPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerAutotuneDownPressed };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerAutotuneUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerAutotuneUp };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerAutotuneUpPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerAutotuneUpPressed };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerListView =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerListView };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerListViewPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerListViewPressed };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerNext };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerNextDisabled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerNextDisabled };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerNextPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerNextPressed };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerPrevious =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerPrevious };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerPreviousDisabled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerPreviousDisabled };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerPreviousPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerPreviousPressed };

static const TAknsItemID KAknsIIDQgnIndiTbFind =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFind };

static const TAknsItemID KAknsIIDQgnIndiTbRename =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbRename };

static const TAknsItemID KAknsIIDQgnPropLmCategories =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmCategories };

static const TAknsItemID KAknsIIDQgnGrafMediatagBubbleTail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafMediatagBubbleTail };

static const TAknsItemID KAknsIIDQgnIndiGalleryEditAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiGalleryEditAdd };

static const TAknsItemID KAknsIIDQgnIndiMediaFullscreenPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMediaFullscreenPlay };

static const TAknsItemID KAknsIIDQgnIndiMediaThumbnail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMediaThumbnail };

static const TAknsItemID KAknsIIDQgnIndiMgTvscreen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMgTvscreen };

static const TAknsItemID KAknsIIDQgnIndiTbGalleryRename =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbGalleryRename };

static const TAknsItemID KAknsIIDQgnIndiTbNewAlbum =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbNewAlbum };

static const TAknsItemID KAknsIIDQgnIndiTbSlideshow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbSlideshow };

static const TAknsItemID KAknsIIDQgnLocServerDisabled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnLocServerDisabled };

static const TAknsItemID KAknsIIDQgnPropCpOptiJoystick =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpOptiJoystick };

static const TAknsItemID KAknsIIDQgnPropDownloadImages =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropDownloadImages };

static const TAknsItemID KAknsIIDQgnGrafCmailBlank =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCmailBlank };

static const TAknsItemID KAknsIIDQgnGrafCmailDropMenuBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCmailDropMenuBg };

static const TAknsItemID KAknsIIDQgnGrafCmailDropOnepc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCmailDropOnepc };

static const TAknsItemID KAknsIIDQgnGrafCmailEmailContent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCmailEmailContent };

static const TAknsItemID KAknsIIDQgnGrafCmailEmailCtrlbar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCmailEmailCtrlbar };

static const TAknsItemID KAknsIIDQgnGrafCmailEmailHeader =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCmailEmailHeader };

static const TAknsItemID KAknsIIDQgnGrafCmailGridSelector =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCmailGridSelector };

static const TAknsItemID KAknsIIDQgnGrafCmailListSelector =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCmailListSelector };

static const TAknsItemID KAknsIIDQgnIndiCmailAbcMailbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailAbcMailbox };

static const TAknsItemID KAknsIIDQgnIndiCmailActionArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailActionArrowLeft };

static const TAknsItemID KAknsIIDQgnIndiCmailActionArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailActionArrowRight };

static const TAknsItemID KAknsIIDQgnIndiCmailActionMenu =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailActionMenu };

static const TAknsItemID KAknsIIDQgnIndiCmailArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailArrowLeft };

static const TAknsItemID KAknsIIDQgnIndiCmailAttachment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailAttachment };

static const TAknsItemID KAknsIIDQgnIndiCmailAttachment2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailAttachment2 };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarAlarm };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarAlarmDay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarAlarmDay };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarDelete };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarEventRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarEventRead };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarEventReadAttachments =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarEventReadAttachments };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarEventReadAttachmentsHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarEventReadAttachmentsHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarEventReadAttachmentsLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarEventReadAttachmentsLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarEventReadHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarEventReadHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarEventReadLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarEventReadLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarEventUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarEventUnread };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarEventUnreadAttachments =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarEventUnreadAttachments };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarEventUnreadAttachmentsHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarEventUnreadAttachmentsHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarEventUnreadAttachmentsLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarEventUnreadAttachmentsLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarEventUnreadHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarEventUnreadHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarEventUnreadLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarEventUnreadLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarOccasion =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarOccasion };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarPriorityHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarPriorityHigh };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarPriorityHigh2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarPriorityHigh2 };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarPriorityLow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarPriorityLow };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarPriorityLow2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarPriorityLow2 };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarPriorityNormal =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarPriorityNormal };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarRecurrence =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarRecurrence };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarSubject =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarSubject };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarTrackingAccept =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarTrackingAccept };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarTrackingNone =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarTrackingNone };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarTrackingReject =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarTrackingReject };

static const TAknsItemID KAknsIIDQgnIndiCmailCalendarTrackingTentative =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCalendarTrackingTentative };

static const TAknsItemID KAknsIIDQgnIndiCmailCollapse =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailCollapse };

static const TAknsItemID KAknsIIDQgnIndiCmailConnected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailConnected };

static const TAknsItemID KAknsIIDQgnIndiCmailConnecting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailConnecting };

static const TAknsItemID KAknsIIDQgnIndiCmailDisconnected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailDisconnected };

static const TAknsItemID KAknsIIDQgnIndiCmailDisconnectedError =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailDisconnectedError };

static const TAknsItemID KAknsIIDQgnIndiCmailDisconnectedLowBattery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailDisconnectedLowBattery };

static const TAknsItemID KAknsIIDQgnIndiCmailDropEmailAccount =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailDropEmailAccount };

static const TAknsItemID KAknsIIDQgnIndiCmailDropInbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailDropInbox };

static const TAknsItemID KAknsIIDQgnIndiCmailDropMoreFolders =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailDropMoreFolders };

static const TAknsItemID KAknsIIDQgnIndiCmailExpand =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailExpand };

static const TAknsItemID KAknsIIDQgnIndiCmailFoldersAsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailFoldersAsc };

static const TAknsItemID KAknsIIDQgnIndiCmailFoldersDesc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailFoldersDesc };

static const TAknsItemID KAknsIIDQgnIndiCmailGoogleMailbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailGoogleMailbox };

static const TAknsItemID KAknsIIDQgnIndiCmailHomeArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailHomeArrowRight };

static const TAknsItemID KAknsIIDQgnIndiCmailLauncherHelp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailLauncherHelp };

static const TAknsItemID KAknsIIDQgnIndiCmailLauncherInbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailLauncherInbox };

static const TAknsItemID KAknsIIDQgnIndiCmailLauncherInfo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailLauncherInfo };

static const TAknsItemID KAknsIIDQgnIndiCmailLauncherMailboxDefault =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailLauncherMailboxDefault };

static const TAknsItemID KAknsIIDQgnIndiCmailLauncherRemoteLookup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailLauncherRemoteLookup };

static const TAknsItemID KAknsIIDQgnIndiCmailLauncherSearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailLauncherSearch };

static const TAknsItemID KAknsIIDQgnIndiCmailLauncherSettings =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailLauncherSettings };

static const TAknsItemID KAknsIIDQgnIndiCmailMeetReqAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMeetReqAlarm };

static const TAknsItemID KAknsIIDQgnIndiCmailMeetReqCheckboxOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMeetReqCheckboxOff };

static const TAknsItemID KAknsIIDQgnIndiCmailMeetReqCheckboxOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMeetReqCheckboxOn };

static const TAknsItemID KAknsIIDQgnIndiCmailMeetReqClock =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMeetReqClock };

static const TAknsItemID KAknsIIDQgnIndiCmailMeetReqDateEnd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMeetReqDateEnd };

static const TAknsItemID KAknsIIDQgnIndiCmailMeetReqDateStart =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMeetReqDateStart };

static const TAknsItemID KAknsIIDQgnIndiCmailMeetReqLocation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMeetReqLocation };

static const TAknsItemID KAknsIIDQgnIndiCmailMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMsg };

static const TAknsItemID KAknsIIDQgnIndiCmailMsgEditor =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMsgEditor };

static const TAknsItemID KAknsIIDQgnIndiCmailMsgRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMsgRead };

static const TAknsItemID KAknsIIDQgnIndiCmailMsgReadDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMsgReadDelete };

static const TAknsItemID KAknsIIDQgnIndiCmailMsgReadRepliedAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMsgReadRepliedAll };

static const TAknsItemID KAknsIIDQgnIndiCmailRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailRead };

static const TAknsItemID KAknsIIDQgnIndiCmailReadAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadAttach };

static const TAknsItemID KAknsIIDQgnIndiCmailReadAttachment =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadAttachment };

static const TAknsItemID KAknsIIDQgnIndiCmailReadAttachHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadAttachHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadAttachLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadAttachLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadForwarded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadForwarded };

static const TAknsItemID KAknsIIDQgnIndiCmailReadForwardedAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadForwardedAttach };

static const TAknsItemID KAknsIIDQgnIndiCmailReadForwardedAttachHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadForwardedAttachHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadForwardedAttachLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadForwardedAttachLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadForwardedHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadForwardedHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadForwardedLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadForwardedLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadReplied =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadReplied };

static const TAknsItemID KAknsIIDQgnIndiCmailReadRepliedAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadRepliedAttach };

static const TAknsItemID KAknsIIDQgnIndiCmailReadRepliedAttachHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadRepliedAttachHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadRepliedAttachLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadRepliedAttachLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadRepliedForwarded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadRepliedForwarded };

static const TAknsItemID KAknsIIDQgnIndiCmailReadRepliedForwardedAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadRepliedForwardedAttach };

static const TAknsItemID KAknsIIDQgnIndiCmailReadRepliedForwardedAttachHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadRepliedForwardedAttachHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadRepliedForwardedAttachLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadRepliedForwardedAttachLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadRepliedForwardedHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadRepliedForwardedHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadRepliedHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadRepliedHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailReadRepliedLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadRepliedLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailSent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailSent };

static const TAknsItemID KAknsIIDQgnIndiCmailSync =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailSync };

static const TAknsItemID KAknsIIDQgnIndiCmailSynchronisation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailSynchronisation };

static const TAknsItemID KAknsIIDQgnIndiCmailUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnread };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadAttach };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadAttachHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadAttachHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadAttachLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadAttachLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadForwarded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadForwarded };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadForwardedAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadForwardedAttach };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadForwardedAttachHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadForwardedAttachHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadForwardedAttachLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadForwardedAttachLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadForwardedHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadForwardedHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadForwardedLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadForwardedLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadReplied =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadReplied };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadRepliedAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadRepliedAttach };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadRepliedAttachHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadRepliedAttachHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadRepliedAttachLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadRepliedAttachLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadRepliedHighPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadRepliedHighPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailUnreadRepliedLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnreadRepliedLowPrio };

static const TAknsItemID KAknsIIDQgnIndiCmailViewerAttachDoc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailViewerAttachDoc };

static const TAknsItemID KAknsIIDQgnIndiCmailViewerAttachHtml =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailViewerAttachHtml };

static const TAknsItemID KAknsIIDQgnIndiCmailViewerAttachImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailViewerAttachImage };

static const TAknsItemID KAknsIIDQgnIndiCmailViewerAttachNotDownloaded =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailViewerAttachNotDownloaded };

static const TAknsItemID KAknsIIDQgnIndiCmailViewerAttachPdf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailViewerAttachPdf };

static const TAknsItemID KAknsIIDQgnIndiCmailViewerAttachPpt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailViewerAttachPpt };

static const TAknsItemID KAknsIIDQgnIndiCmailViewerAttachRtf =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailViewerAttachRtf };

static const TAknsItemID KAknsIIDQgnIndiCmailViewerAttachUnidentified =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailViewerAttachUnidentified };

static const TAknsItemID KAknsIIDQgnIndiCmailViewerAttachXls =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailViewerAttachXls };

static const TAknsItemID KAknsIIDQgnIndiCmailViewerFollowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailViewerFollowUp };

static const TAknsItemID KAknsIIDQgnIndiCmailViewerFollowUpComplete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailViewerFollowUpComplete };

static const TAknsItemID KAknsIIDQgnMenuCmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuCmail };

static const TAknsItemID KAknsIIDQgnMenuCmailIntraBrowser =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuCmailIntraBrowser };

static const TAknsItemID KAknsIIDQgnMenuInternetRadio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuInternetRadio };

static const TAknsItemID KAknsIIDQgnPropCmailActionAddToContacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAddToContacts };

static const TAknsItemID KAknsIIDQgnPropCmailActionAttachmentCancelDownload =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAttachmentCancelDownload };

static const TAknsItemID KAknsIIDQgnPropCmailActionAttachmentDownload =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAttachmentDownload };

static const TAknsItemID KAknsIIDQgnPropCmailActionAttachmentDownloadAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAttachmentDownloadAll };

static const TAknsItemID KAknsIIDQgnPropCmailActionAttachmentListOptionsAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAttachmentListOptionsAdd };

static const TAknsItemID KAknsIIDQgnPropCmailActionAttachmentListOptionsCancelAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAttachmentListOptionsCancelAll };

static const TAknsItemID KAknsIIDQgnPropCmailActionAttachmentListOptionsDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAttachmentListOptionsDelete };

static const TAknsItemID KAknsIIDQgnPropCmailActionAttachmentListOptionsDeleteAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAttachmentListOptionsDeleteAll };

static const TAknsItemID KAknsIIDQgnPropCmailActionAttachmentListOptionsViewAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAttachmentListOptionsViewAll };

static const TAknsItemID KAknsIIDQgnPropCmailActionAttachmentOpen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAttachmentOpen };

static const TAknsItemID KAknsIIDQgnPropCmailActionAttachmentSave =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAttachmentSave };

static const TAknsItemID KAknsIIDQgnPropCmailActionAttachmentSaveAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAttachmentSaveAll };

static const TAknsItemID KAknsIIDQgnPropCmailActionAudio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionAudio };

static const TAknsItemID KAknsIIDQgnPropCmailActionBookmark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionBookmark };

static const TAknsItemID KAknsIIDQgnPropCmailActionCalendarDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionCalendarDelete };

static const TAknsItemID KAknsIIDQgnPropCmailActionCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionCall };

static const TAknsItemID KAknsIIDQgnPropCmailActionCall2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionCall2 };

static const TAknsItemID KAknsIIDQgnPropCmailActionCallVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionCallVideo };

static const TAknsItemID KAknsIIDQgnPropCmailActionConfService =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionConfService };

static const TAknsItemID KAknsIIDQgnPropCmailActionContactDetail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionContactDetail };

static const TAknsItemID KAknsIIDQgnPropCmailActionCreateMeeting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionCreateMeeting };

static const TAknsItemID KAknsIIDQgnPropCmailActionCreateMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionCreateMsg };

static const TAknsItemID KAknsIIDQgnPropCmailActionDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionDelete };

static const TAknsItemID KAknsIIDQgnPropCmailActionEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionEmail };

static const TAknsItemID KAknsIIDQgnPropCmailActionForward =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionForward };

static const TAknsItemID KAknsIIDQgnPropCmailActionMarkRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionMarkRead };

static const TAknsItemID KAknsIIDQgnPropCmailActionMarkUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionMarkUnread };

static const TAknsItemID KAknsIIDQgnPropCmailActionMeeting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionMeeting };

static const TAknsItemID KAknsIIDQgnPropCmailActionMoveMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionMoveMsg };

static const TAknsItemID KAknsIIDQgnPropCmailActionMoveToDrafts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionMoveToDrafts };

static const TAknsItemID KAknsIIDQgnPropCmailActionMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionMsg };

static const TAknsItemID KAknsIIDQgnPropCmailActionOpenInIntranet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionOpenInIntranet };

static const TAknsItemID KAknsIIDQgnPropCmailActionOpenInWeb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionOpenInWeb };

static const TAknsItemID KAknsIIDQgnPropCmailActionPostcard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionPostcard };

static const TAknsItemID KAknsIIDQgnPropCmailActionPtt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionPtt };

static const TAknsItemID KAknsIIDQgnPropCmailActionRemoteLookup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionRemoteLookup };

static const TAknsItemID KAknsIIDQgnPropCmailActionReply =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionReply };

static const TAknsItemID KAknsIIDQgnPropCmailActionReplyAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionReplyAll };

static const TAknsItemID KAknsIIDQgnPropCmailActionSave =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionSave };

static const TAknsItemID KAknsIIDQgnPropCmailActionViewCalendar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionViewCalendar };

static const TAknsItemID KAknsIIDQgnPropCmailActionVoip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailActionVoip };

static const TAknsItemID KAknsIIDQgnPropCmailContactsFavourite =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailContactsFavourite };

static const TAknsItemID KAknsIIDQgnPropCmailContactsGroup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailContactsGroup };

static const TAknsItemID KAknsIIDQgnPropCmailFoldersDeletedItems =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailFoldersDeletedItems };

static const TAknsItemID KAknsIIDQgnPropCmailFoldersDrafts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailFoldersDrafts };

static const TAknsItemID KAknsIIDQgnPropCmailFoldersInbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailFoldersInbox };

static const TAknsItemID KAknsIIDQgnPropCmailFoldersOutbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailFoldersOutbox };

static const TAknsItemID KAknsIIDQgnPropCmailFoldersSent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailFoldersSent };

static const TAknsItemID KAknsIIDQgnPropCmailFoldersServerFolder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailFoldersServerFolder };

static const TAknsItemID KAknsIIDQgnPropCmailFoldersSubfolders =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailFoldersSubfolders };

static const TAknsItemID KAknsIIDQgnPropCmailInboxSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailInboxSmall };

static const TAknsItemID KAknsIIDQgnPropCmailWmlBookmark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailWmlBookmark };

static const TAknsItemID KAknsIIDQgnWkaCxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWkaCxt };

static const TAknsItemID KAknsIIDQgnHomeRefreshing1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeRefreshing1 };

static const TAknsItemID KAknsIIDQgnHomeRefreshing2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeRefreshing2 };

static const TAknsItemID KAknsIIDQgnHomeRefreshing3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeRefreshing3 };

static const TAknsItemID KAknsIIDQgnHomeRefreshing4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeRefreshing4 };

static const TAknsItemID KAknsIIDQgnHomeRefreshingFails =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeRefreshingFails };

static const TAknsItemID KAknsIIDQgnIndiCallVideo12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVideo12 };

static const TAknsItemID KAknsIIDQgnIndiCallVideoCallsta12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallVideoCallsta12 };

static const TAknsItemID KAknsIIDQgnIndiCam4Panorama =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Panorama };

static const TAknsItemID KAknsIIDQgnIndiCam4TbPanorama =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbPanorama };

static const TAknsItemID KAknsIIDQgnIndiRadioNextDisabled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioNextDisabled };

static const TAknsItemID KAknsIIDQgnIndiRadioNextPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioNextPressed };

static const TAknsItemID KAknsIIDQgnIndiRadioPreviousDisabled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioPreviousDisabled };

static const TAknsItemID KAknsIIDQgnIndiRadioPreviousPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioPreviousPressed };

static const TAknsItemID KAknsIIDQgnIndiRadioSoundDisabled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioSoundDisabled };

static const TAknsItemID KAknsIIDQgnIndiRadioSoundMutedDisabled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioSoundMutedDisabled };

static const TAknsItemID KAknsIIDQgnIndiRadioSoundMutedPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioSoundMutedPressed };

static const TAknsItemID KAknsIIDQgnIndiRadioSoundPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioSoundPressed };

static const TAknsItemID KAknsIIDQgnPropHomeAddFriend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHomeAddFriend };

static const TAknsItemID KAknsIIDQgnPropHomeDefaultFriend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHomeDefaultFriend };

static const TAknsItemID KAknsIIDQgnPropMupAlbumLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupAlbumLarge };

static const TAknsItemID KAknsIIDQgnPropMupArtistLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupArtistLarge };

static const TAknsItemID KAknsIIDQgnPropMupComposerLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupComposerLarge };

static const TAknsItemID KAknsIIDQgnPropMupGenreLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupGenreLarge };

static const TAknsItemID KAknsIIDQgnPropMupPlaylistLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupPlaylistLarge };

static const TAknsItemID KAknsIIDQgnPropMupPodcastsLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupPodcastsLarge };

static const TAknsItemID KAknsIIDQgnPropMupSongsLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMupSongsLarge };

static const TAknsItemID KAknsIIDQgnGrafPbPicDefault =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPbPicDefault };

static const TAknsItemID KAknsIIDQgnGrafPbPicOvalMaskIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafPbPicOvalMaskIcon };

static const TAknsItemID KAknsIIDQgnGrafSwipeindiBgLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafSwipeindiBgLeft };

static const TAknsItemID KAknsIIDQgnGrafSwipeindiBgRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafSwipeindiBgRight };

static const TAknsItemID KAknsIIDQgnIndiBrowserOvi =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserOvi };

static const TAknsItemID KAknsIIDQgnIndiGreenHandle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiGreenHandle };

static const TAknsItemID KAknsIIDQgnIndiOrgArrowDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiOrgArrowDown };

static const TAknsItemID KAknsIIDQgnIndiOrgArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiOrgArrowLeft };

static const TAknsItemID KAknsIIDQgnIndiOrgArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiOrgArrowRight };

static const TAknsItemID KAknsIIDQgnIndiOrgArrowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiOrgArrowUp };

static const TAknsItemID KAknsIIDQgnIndiUnlockScreen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiUnlockScreen };

static const TAknsItemID KAknsIIDQgnMenuFmtx =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuFmtx };

static const TAknsItemID KAknsIIDQgnNoteNfcTouchtotrans =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteNfcTouchtotrans };

static const TAknsItemID KAknsIIDQgnPropLocevInvalid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocevInvalid };

static const TAknsItemID KAknsIIDQgnPropVpRatioOrig =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVpRatioOrig };

static const TAknsItemID KAknsIIDQgnPropVpRatioStretch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVpRatioStretch };

static const TAknsItemID KAknsIIDQgnPropVpRatioZoom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropVpRatioZoom };

static const TAknsItemID KAknsIIDQgnPropWmlBmOvi =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropWmlBmOvi };

static const TAknsItemID KAknsIIDQgnStatClkStpWatchUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatClkStpWatchUni };

static const TAknsItemID KAknsIIDQgnFrwidgetAddFriendPhoto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetAddFriendPhoto };

static const TAknsItemID KAknsIIDQgnFrwidgetDialledCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetDialledCall };

static const TAknsItemID KAknsIIDQgnFrwidgetEmptyPhoto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetEmptyPhoto };

static const TAknsItemID KAknsIIDQgnFrwidgetEventIndicator =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetEventIndicator };

static const TAknsItemID KAknsIIDQgnFrwidgetMissedCallRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetMissedCallRead };

static const TAknsItemID KAknsIIDQgnFrwidgetMissedCallUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetMissedCallUnread };

static const TAknsItemID KAknsIIDQgnFrwidgetReceivedCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetReceivedCall };

static const TAknsItemID KAknsIIDQgnFrwidgetReceivedEmailRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetReceivedEmailRead };

static const TAknsItemID KAknsIIDQgnFrwidgetReceivedEmailUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetReceivedEmailUnread };

static const TAknsItemID KAknsIIDQgnFrwidgetReceivedMsgRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetReceivedMsgRead };

static const TAknsItemID KAknsIIDQgnFrwidgetReceivedMsgUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetReceivedMsgUnread };

static const TAknsItemID KAknsIIDQgnFrwidgetRefreshingFeed1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetRefreshingFeed1 };

static const TAknsItemID KAknsIIDQgnFrwidgetRefreshingFeed2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetRefreshingFeed2 };

static const TAknsItemID KAknsIIDQgnFrwidgetRefreshingFeed3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetRefreshingFeed3 };

static const TAknsItemID KAknsIIDQgnFrwidgetRefreshingFeed4 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetRefreshingFeed4 };

static const TAknsItemID KAknsIIDQgnFrwidgetScrollIndicator =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetScrollIndicator };

static const TAknsItemID KAknsIIDQgnFrwidgetScutCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetScutCall };

static const TAknsItemID KAknsIIDQgnFrwidgetScutFeed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetScutFeed };

static const TAknsItemID KAknsIIDQgnFrwidgetScutNewMessage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetScutNewMessage };

static const TAknsItemID KAknsIIDQgnFrwidgetScutRefresh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetScutRefresh };

static const TAknsItemID KAknsIIDQgnFrwidgetScutSettings =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetScutSettings };

static const TAknsItemID KAknsIIDQgnFrwidgetSentEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetSentEmail };

static const TAknsItemID KAknsIIDQgnFrwidgetSentMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetSentMsg };

static const TAknsItemID KAknsIIDQgnFrwidgetSettDetails =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetSettDetails };

static const TAknsItemID KAknsIIDQgnFrwidgetSettPhoto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetSettPhoto };

static const TAknsItemID KAknsIIDQgnFrwidgetSettRemove =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetSettRemove };

static const TAknsItemID KAknsIIDQgnFrwidgetSettSort =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetSettSort };

static const TAknsItemID KAknsIIDQgnFrwidgetSettWebFeed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetSettWebFeed };

static const TAknsItemID KAknsIIDQgnFrwidgetTextFeedPreview =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetTextFeedPreview };

static const TAknsItemID KAknsIIDQgnFrwidgetUnknownFeed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnFrwidgetUnknownFeed };

static const TAknsItemID KAknsIIDQgnIndiActivenotesPause =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiActivenotesPause };

static const TAknsItemID KAknsIIDQgnIndiMpRatioOrig =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpRatioOrig };

static const TAknsItemID KAknsIIDQgnIndiMpRatioStretch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpRatioStretch };

static const TAknsItemID KAknsIIDQgnIndiMpRatioZoom =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMpRatioZoom };

static const TAknsItemID KAknsIIDQgnMenu =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenu };

static const TAknsItemID KAknsIIDQgnPropPaGotomynokia =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPaGotomynokia };

static const TAknsItemID KAknsIIDQgnPropPaInstructions =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPaInstructions };

static const TAknsItemID KAknsIIDQgnPropPbCommCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommCall };

static const TAknsItemID KAknsIIDQgnPropPbCommCallLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommCallLarge };

static const TAknsItemID KAknsIIDQgnPropPbCommChat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommChat };

static const TAknsItemID KAknsIIDQgnPropPbCommChatLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommChatLarge };

static const TAknsItemID KAknsIIDQgnPropPbCommEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommEmail };

static const TAknsItemID KAknsIIDQgnPropPbCommEmailLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommEmailLarge };

static const TAknsItemID KAknsIIDQgnPropPbCommMessage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommMessage };

static const TAknsItemID KAknsIIDQgnPropPbCommMessageLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommMessageLarge };

static const TAknsItemID KAknsIIDQgnPropPbCommNoValidLm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommNoValidLm };

static const TAknsItemID KAknsIIDQgnPropPbCommUrl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommUrl };

static const TAknsItemID KAknsIIDQgnPropPbCommUrlLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommUrlLarge };

static const TAknsItemID KAknsIIDQgnPropPbCommValidLm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommValidLm };

static const TAknsItemID KAknsIIDQgnPropPbCommValidLmLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommValidLmLarge };

static const TAknsItemID KAknsIIDQgnPropPbCommVcall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommVcall };

static const TAknsItemID KAknsIIDQgnPropPbCommVcallLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommVcallLarge };

static const TAknsItemID KAknsIIDQgnPropPbCommVoip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommVoip };

static const TAknsItemID KAknsIIDQgnPropPbCommVoipLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbCommVoipLarge };

static const TAknsItemID KAknsIIDQgnPropPbNoValidLm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbNoValidLm };

static const TAknsItemID KAknsIIDQgnGrafBgTportSw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafBgTportSw };

static const TAknsItemID KAknsIIDQgnGrafCamPanoramaActiveframe =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCamPanoramaActiveframe };

static const TAknsItemID KAknsIIDQgnGrafCamPanoramaArea =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCamPanoramaArea };

static const TAknsItemID KAknsIIDQgnGrafCamPanoramaCapture =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCamPanoramaCapture };

static const TAknsItemID KAknsIIDQgnGrafCamPanoramaFrame =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCamPanoramaFrame };

static const TAknsItemID KAknsIIDQgnGrafCamPanoramaGuide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCamPanoramaGuide };

static const TAknsItemID KAknsIIDQgnGrafCamPanoramaGuideDashed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCamPanoramaGuideDashed };

static const TAknsItemID KAknsIIDQgnGrafCamPanoramaLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCamPanoramaLeft };

static const TAknsItemID KAknsIIDQgnGrafCamPanoramaRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafCamPanoramaRight };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality12mpHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality12mpHigh };

static const TAknsItemID KAknsIIDQgnIndiTvButtonGotostore =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTvButtonGotostore };

static const TAknsItemID KAknsIIDQgnPropSetSlideSettings =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetSlideSettings };

static const TAknsItemID KAknsIIDQgnGrafSnoozealarmButtonGrey =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafSnoozealarmButtonGrey };

static const TAknsItemID KAknsIIDQgnGrafStopalarmButtonOrange =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafStopalarmButtonOrange };

static const TAknsItemID KAknsIIDQgnIndiInputFshwrSctPage3 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputFshwrSctPage3 };

static const TAknsItemID KAknsIIDQgnPropBrowserInfoSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropBrowserInfoSmall };

static const TAknsItemID KAknsIIDQgnMenuMessageReader =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMessageReader };

static const TAknsItemID KAknsIIDRlsApplicationNameGrid =
    { EAknsMajorGeneric, EAknsMinorGenericRlsApplicationNameGrid };

static const TAknsItemID KAknsIIDQgnIndiCmailMailForExchange =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailMailForExchange };

static const TAknsItemID KAknsIIDQgnIndiMusicWidgetTbRadioSound =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicWidgetTbRadioSound };

static const TAknsItemID KAknsIIDQgnIndiMusicWidgetTbRadioSoundDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicWidgetTbRadioSoundDimmed };

static const TAknsItemID KAknsIIDQgnIndiMusicWidgetTbRadioSoundMuted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicWidgetTbRadioSoundMuted };

static const TAknsItemID KAknsIIDQgnIndiMusicWidgetTbRadioSoundMutedDimmed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicWidgetTbRadioSoundMutedDimmed };

static const TAknsItemID KAknsIIDQgnIndiTvTbEpg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTvTbEpg };

static const TAknsItemID KAknsIIDQgnStatCaseCyrillicCapital =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseCyrillicCapital };

static const TAknsItemID KAknsIIDQgnStatCaseCyrillicSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseCyrillicSmall };

static const TAknsItemID KAknsIIDQgnStatCaseCyrillicText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseCyrillicText };

static const TAknsItemID KAknsIIDQgnStatCaseGreekCapital =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseGreekCapital };

static const TAknsItemID KAknsIIDQgnStatCaseGreekSmall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseGreekSmall };

static const TAknsItemID KAknsIIDQgnStatCaseGreekText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseGreekText };

static const TAknsItemID KAknsIIDQgnIndiCmailArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailArrowRight };

static const TAknsItemID KAknsIIDQgnIndiCmailReadRepliedForwardedLowPrio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailReadRepliedForwardedLowPrio };

static const TAknsItemID KAknsIIDQgnIndiInputCandiListOpen =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCandiListOpen };

static const TAknsItemID KAknsIIDQgnIndiPbTbImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPbTbImage };

static const TAknsItemID KAknsIIDQgnIndiPbTbSendBcard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPbTbSendBcard };

static const TAknsItemID KAknsIIDQgnMenuNgageDt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuNgageDt };

static const TAknsItemID KAknsIIDQgnMenuOviFiles =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuOviFiles };

static const TAknsItemID KAknsIIDQgnPropCmailAttachPresentation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailAttachPresentation };

static const TAknsItemID KAknsIIDQgnPropMceNfcRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceNfcRead };

static const TAknsItemID KAknsIIDQgnPropMceNfcUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMceNfcUnread };

static const TAknsItemID KAknsIIDQgnPropPbMycard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbMycard };

static const TAknsItemID KAknsIIDQgnStatHdmiConnect =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatHdmiConnect };

static const TAknsItemID KAknsIIDQgnIndiAlarmSilence =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAlarmSilence };

static const TAknsItemID KAknsIIDQgnIndiAlarmSnooze =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAlarmSnooze };

static const TAknsItemID KAknsIIDQgnIndiAlarmStop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAlarmStop };

static const TAknsItemID KAknsIIDQgnIndiPbDefaultConnAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPbDefaultConnAdd };

static const TAknsItemID KAknsIIDQgnPropServiceFriendBlocked =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropServiceFriendBlocked };

static const TAknsItemID KAknsIIDQgnHomeWidgetDisabled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeWidgetDisabled };

static const TAknsItemID KAknsIIDQgnIndiMupHomeNoAlbumArt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupHomeNoAlbumArt };

static const TAknsItemID KAknsIIDQgnMenuOviSync =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuOviSync };

static const TAknsItemID KAknsIIDQgnPropOviSync =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropOviSync };

static const TAknsItemID KAknsIIDExampleMsnTab =
    { EAknsMajorGeneric, EAknsMinorGenericExampleMsnTab };

static const TAknsItemID KAknsIIDQgnHomeRefreshingDisabled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeRefreshingDisabled };

static const TAknsItemID KAknsIIDQgnPropImwidgetBrandAvatar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImwidgetBrandAvatar };

static const TAknsItemID KAknsIIDQgnPropImwidgetDefaultAvatar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImwidgetDefaultAvatar };

static const TAknsItemID KAknsIIDQgnPropImwidgetFriendAway =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImwidgetFriendAway };

static const TAknsItemID KAknsIIDQgnPropImwidgetFriendBusy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImwidgetFriendBusy };

static const TAknsItemID KAknsIIDQgnPropImwidgetFriendInvisible =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImwidgetFriendInvisible };

static const TAknsItemID KAknsIIDQgnPropImwidgetFriendOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImwidgetFriendOff };

static const TAknsItemID KAknsIIDQgnPropImwidgetFriendOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImwidgetFriendOn };

static const TAknsItemID KAknsIIDQgnPropImwidgetImsgNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImwidgetImsgNew };

static const TAknsItemID KAknsIIDQgnPropImFriendVoip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendVoip };

static const TAknsItemID KAknsIIDQgnServtabAvatarBlocked =
    { EAknsMajorGeneric, EAknsMinorGenericQgnServtabAvatarBlocked };

static const TAknsItemID KAknsIIDQgnStatNewMsgUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatNewMsgUni };

static const TAknsItemID KAknsIIDQgnIndiCalendarClockAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCalendarClockAlarm };

static const TAknsItemID KAknsIIDQgnIndiCallAnswer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCallAnswer };

static const TAknsItemID KAknsIIDQgnIndiCam4TbTag =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbTag };

static const TAknsItemID KAknsIIDQgnIndiMupHomeMusicDefault =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMupHomeMusicDefault };

static const TAknsItemID KAknsIIDQgnMenuChiTalkingDict =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuChiTalkingDict };

static const TAknsItemID KAknsIIDQgnNoteChidictSearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteChidictSearch };

static const TAknsItemID KAknsIIDQgnNotePa4Tipalert =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNotePa4Tipalert };

static const TAknsItemID KAknsIIDQgnPropPa4Aboutmynokia =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPa4Aboutmynokia };

static const TAknsItemID KAknsIIDQgnPropPa4History =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPa4History };

static const TAknsItemID KAknsIIDQgnPropPa4Tip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPa4Tip };

static const TAknsItemID KAknsIIDQgnPropPa4VisitedTip =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPa4VisitedTip };

static const TAknsItemID KAknsIIDQgnPropSetGeneSlide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetGeneSlide };

static const TAknsItemID KAknsIIDQgnIndiCam4QualityHd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4QualityHd };

static const TAknsItemID KAknsIIDQgnMenuBrowserng =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuBrowserng };

static const TAknsItemID KAknsIIDQgnGrafFepGuideGrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepGuideGrid };

static const TAknsItemID KAknsIIDQgnGrafFepGuideLine =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepGuideLine };

static const TAknsItemID KAknsIIDQgnIndiClkTbReset =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiClkTbReset };

static const TAknsItemID KAknsIIDQgnIndiCmailDisconnectedScopy =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailDisconnectedScopy };

static const TAknsItemID KAknsIIDQgnIndiTbAddHomecity =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbAddHomecity };

static const TAknsItemID KAknsIIDQgnIndiTbAddLocation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbAddLocation };

static const TAknsItemID KAknsIIDQgnIndiTbNewTimer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbNewTimer };

static const TAknsItemID KAknsIIDQgnIndiTbStpWatchLap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbStpWatchLap };

static const TAknsItemID KAknsIIDQgnIndiTbStpWatchSplit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbStpWatchSplit };

static const TAknsItemID KAknsIIDQgnPropCmailAttachPresentation2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmailAttachPresentation2 };

static const TAknsItemID KAknsIIDQgnIndiCdrActionArrowDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrActionArrowDown };

static const TAknsItemID KAknsIIDQgnIndiCdrActionArrowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrActionArrowUp };

static const TAknsItemID KAknsIIDQgnIndiCdrDateAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrDateAlarm };

static const TAknsItemID KAknsIIDQgnIndiCdrEdit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrEdit };

static const TAknsItemID KAknsIIDQgnIndiCdrInvitation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrInvitation };

static const TAknsItemID KAknsIIDQgnIndiCdrNewTodo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrNewTodo };

static const TAknsItemID KAknsIIDQgnIndiCdrRecurrenceException =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrRecurrenceException };

static const TAknsItemID KAknsIIDQgnIndiCdrWeekLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrWeekLeft };

static const TAknsItemID KAknsIIDQgnIndiCdrWeekRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCdrWeekRight };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerAutotuneDownDisabled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerAutotuneDownDisabled };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerAutotuneUpDisabled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerAutotuneUpDisabled };

static const TAknsItemID KAknsIIDQgnIndiRadioRockerListViewDisabled =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioRockerListViewDisabled };

static const TAknsItemID KAknsIIDQgnIndiRadioTune =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioTune };

static const TAknsItemID KAknsIIDQgnMenuGroupDatam =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupDatam };

static const TAknsItemID KAknsIIDQgnMenuGroupEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuGroupEmail };

static const TAknsItemID KAknsIIDQgnStatCaseHybrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatCaseHybrid };

static const TAknsItemID KAknsIIDQgnGrafStartupProto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafStartupProto };

static const TAknsItemID KAknsIIDQgnPropContPerson =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropContPerson };

static const TAknsItemID KAknsIIDQgnPropEmailLog =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailLog };

static const TAknsItemID KAknsIIDQgnPropFolderOpenSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropFolderOpenSub };

static const TAknsItemID KAknsIIDQgnPropLocOnMap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLocOnMap };

static const TAknsItemID KAknsIIDQgnPropMsgLog =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgLog };

static const TAknsItemID KAknsIIDQgnPropOutgEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropOutgEmail };

static const TAknsItemID KAknsIIDQgnPropOutgMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropOutgMsg };

static const TAknsItemID KAknsIIDQgnPropOutgPhoto =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropOutgPhoto };

static const TAknsItemID KAknsIIDQgnPropPhotosNearYou =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPhotosNearYou };

static const TAknsItemID KAknsIIDQgnPropPluginsAv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPluginsAv };

static const TAknsItemID KAknsIIDQgnPropSearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSearch };

static const TAknsItemID KAknsIIDQgnPropSendBirthday =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSendBirthday };

static const TAknsItemID KAknsIIDQgnPropSendNowpl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSendNowpl };

static const TAknsItemID KAknsIIDQgnPropSendNowwatTv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSendNowwatTv };

static const TAknsItemID KAknsIIDQgnPropSendNowwatVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSendNowwatVideo };

static const TAknsItemID KAknsIIDQgnPropThisdayMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropThisdayMsg };

static const TAknsItemID KAknsIIDQgnPropThisdayPhotos =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropThisdayPhotos };

static const TAknsItemID KAknsIIDQgnPropSetAppsNfcOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsNfcOff };

static const TAknsItemID KAknsIIDQgnPropSetAppsNfcOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsNfcOn };

static const TAknsItemID KAknsIIDQgnGrafScreencalibUnfocus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafScreencalibUnfocus };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality6mpHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality6mpHigh };

static const TAknsItemID KAknsIIDQgnIndiCam4Quality9mpHigh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4Quality9mpHigh };

static const TAknsItemID KAknsIIDQgnIndiInputCaseSymbol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseSymbol };

static const TAknsItemID KAknsIIDQgnIndiInputConvertToEnglish =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputConvertToEnglish };

static const TAknsItemID KAknsIIDQgnIndiInputConvertToKorean =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputConvertToKorean };

static const TAknsItemID KAknsIIDQgnPropMpVideoFeeds =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMpVideoFeeds };

static const TAknsItemID KAknsIIDQgnPropServiceUnknownAvatar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropServiceUnknownAvatar };

static const TAknsItemID KAknsIIDQgnPropUsbModem =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropUsbModem };

static const TAknsItemID KAknsIIDQgnPropUsbMtp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropUsbMtp };

static const TAknsItemID KAknsIIDQgnPropUsbPcsuite =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropUsbPcsuite };

static const TAknsItemID KAknsIIDQgnPropUsbPrint =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropUsbPrint };

static const TAknsItemID KAknsIIDQgnIndiInputSctNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputSctNext };

static const TAknsItemID KAknsIIDQgnIndiInputSctPrev =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputSctPrev };

static const TAknsItemID KAknsIIDQgnGrafScreencalibDot =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafScreencalibDot };

static const TAknsItemID KAknsIIDQgnStatServtabUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatServtabUni };

static const TAknsItemID KAknsIIDQsnBigclockAnalogueFace =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockAnalogueFace };

static const TAknsItemID KAknsIIDQsnBigclockAnaloguePointerHours =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockAnaloguePointerHours };

static const TAknsItemID KAknsIIDQsnBigclockAnaloguePointerMinutes =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockAnaloguePointerMinutes };

static const TAknsItemID KAknsIIDQsnBigclockAnaloguePointerSeconds =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockAnaloguePointerSeconds };

static const TAknsItemID KAknsIIDQsnBigclockDateBackgroundCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockDateBackgroundCenter };

static const TAknsItemID KAknsIIDQsnBigclockDateBackgroundLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockDateBackgroundLeft };

static const TAknsItemID KAknsIIDQsnBigclockDateBackgroundRight =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockDateBackgroundRight };

static const TAknsItemID KAknsIIDQgnIndiImageFavourite =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImageFavourite };

static const TAknsItemID KAknsIIDQgnIndiImageFavouriteInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImageFavouriteInactive };

static const TAknsItemID KAknsIIDQgnIndiImageLocation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiImageLocation };

static const TAknsItemID KAknsIIDQgnIndiTbEmailAccept =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbEmailAccept };

static const TAknsItemID KAknsIIDQgnIndiTbEmailDecline =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbEmailDecline };

static const TAknsItemID KAknsIIDQgnIndiTbEmailTentative =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbEmailTentative };

static const TAknsItemID KAknsIIDQgnPropCameraLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCameraLarge };

static const TAknsItemID KAknsIIDQgnPropShareonlineLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropShareonlineLarge };

static const TAknsItemID KAknsIIDQgnHomeContactMaskC =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeContactMaskC };

static const TAknsItemID KAknsIIDQgnHomeContactMaskCl =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeContactMaskCl };

static const TAknsItemID KAknsIIDQgnHomeContactMaskCr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeContactMaskCr };

static const TAknsItemID KAknsIIDQgnIndiModeAskAutomatedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiModeAskAutomatedAdd };

static const TAknsItemID KAknsIIDQgnIndiModeAutomatedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiModeAutomatedAdd };

static const TAknsItemID KAknsIIDQgnIndiTbLoc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbLoc };

static const TAknsItemID KAknsIIDQgnIndiTbMap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMap };

static const TAknsItemID KAknsIIDQgnMenuContactbar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuContactbar };

static const TAknsItemID KAknsIIDQgnMenuOviStore =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuOviStore };

static const TAknsItemID KAknsIIDQgnMenuStoresfolder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuStoresfolder };

static const TAknsItemID KAknsIIDQgnPropHfvuiUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHfvuiUni };

static const TAknsItemID KAknsIIDQgnPropSelMap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSelMap };

static const TAknsItemID KAknsIIDQgnHomeEditBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeEditBg };

static const TAknsItemID KAknsIIDQgnPropImFriendRequestOffline =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropImFriendRequestOffline };

static const TAknsItemID KAknsIIDQgnIndiNaviFollowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiNaviFollowUp };

static const TAknsItemID KAknsIIDQgnIndiNaviFollowUpComplete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiNaviFollowUpComplete };

static const TAknsItemID KAknsIIDQgnIndiSmileyCoffee =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyCoffee };

static const TAknsItemID KAknsIIDQgnIndiSmileyConnive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyConnive };

static const TAknsItemID KAknsIIDQgnIndiSmileyDenial =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyDenial };

static const TAknsItemID KAknsIIDQgnIndiSmileyFlirt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyFlirt };

static const TAknsItemID KAknsIIDQgnIndiSmileyFrustrated =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyFrustrated };

static const TAknsItemID KAknsIIDQgnIndiSmileyGum =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyGum };

static const TAknsItemID KAknsIIDQgnIndiSmileyIdea =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyIdea };

static const TAknsItemID KAknsIIDQgnIndiSmileyInnocent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyInnocent };

static const TAknsItemID KAknsIIDQgnIndiSmileyLaugh =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyLaugh };

static const TAknsItemID KAknsIIDQgnIndiSmileyParty =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyParty };

static const TAknsItemID KAknsIIDQgnIndiSmileyRun =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyRun };

static const TAknsItemID KAknsIIDQgnIndiSmileySilly =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileySilly };

static const TAknsItemID KAknsIIDQgnIndiSmileySleep =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileySleep };

static const TAknsItemID KAknsIIDQgnIndiSmileySurprised =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileySurprised };

static const TAknsItemID KAknsIIDQgnIndiTbCollapseAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbCollapseAll };

static const TAknsItemID KAknsIIDQgnIndiTbExpandAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbExpandAll };

static const TAknsItemID KAknsIIDQgnIndiTbFolderSettings =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFolderSettings };

static const TAknsItemID KAknsIIDQgnIndiSignalUmaAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalUmaAttach };

static const TAknsItemID KAknsIIDQgnIndiSignalUmaContext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalUmaContext };

static const TAknsItemID KAknsIIDQgnIndiSignalUmaIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalUmaIcon };

static const TAknsItemID KAknsIIDQgnIndiSignalUmaMultipdp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalUmaMultipdp };

static const TAknsItemID KAknsIIDQgnIndiSignalUmaNoservice =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalUmaNoservice };

static const TAknsItemID KAknsIIDQgnIndiSignalUmaSuspended =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalUmaSuspended };

static const TAknsItemID KAknsIIDQgnIndiTbEmailExtend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbEmailExtend };

static const TAknsItemID KAknsIIDQgnIndiTbEmailReplyAll =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbEmailReplyAll };

static const TAknsItemID KAknsIIDQgnStatDebug =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDebug };

static const TAknsItemID KAknsIIDQgnIndiCaleTbChangeview =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbChangeview };

static const TAknsItemID KAknsIIDQgnIndiCaleTbHide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbHide };

static const TAknsItemID KAknsIIDQgnIndiCaleTbNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbNew };

static const TAknsItemID KAknsIIDQgnIndiCaleTbToday =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbToday };

static const TAknsItemID KAknsIIDQgnIndiCaleTbUnhide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCaleTbUnhide };

static const TAknsItemID KAknsIIDQgnIndiFsqCursorDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFsqCursorDown };

static const TAknsItemID KAknsIIDQgnIndiFsqCursorUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFsqCursorUp };

static const TAknsItemID KAknsIIDQgnIndiSharedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSharedAdd };

static const TAknsItemID KAknsIIDQgnIndiSyncOffAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSyncOffAdd };

static const TAknsItemID KAknsIIDQgnIndiSyncOnAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSyncOnAdd };

static const TAknsItemID KAknsIIDQgnIndiCmailArrowDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailArrowDown };

static const TAknsItemID KAknsIIDQgnIndiExitFs =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiExitFs };

static const TAknsItemID KAknsIIDQgnHomeEditMode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeEditMode };

static const TAknsItemID KAknsIIDQgnIndiCam4TbSave =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbSave };

static const TAknsItemID KAknsIIDQgnIndiCam4TbUse =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCam4TbUse };

static const TAknsItemID KAknsIIDQgnIndiCmailHeaderCollapse =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailHeaderCollapse };

static const TAknsItemID KAknsIIDQgnIndiCmailHeaderExpand =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailHeaderExpand };

static const TAknsItemID KAknsIIDQgnIndiMusicAlbumCover =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicAlbumCover };

static const TAknsItemID KAknsIIDQgnIndiMusicAlbumShuffle =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicAlbumShuffle };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimCoffeeStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimCoffeeStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimConniveStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimConniveStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimDenialStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimDenialStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimFlirtStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimFlirtStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimFrustratedStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimFrustratedStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimGumStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimGumStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimIdeaStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimIdeaStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimInnocentStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimInnocentStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimLaughStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimLaughStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimPartyStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimPartyStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimRunStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimRunStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimSillyStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimSillyStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimSleepStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimSleepStatic };

static const TAknsItemID KAknsIIDQgnIndiSmileyAnimSurprisedStatic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSmileyAnimSurprisedStatic };

static const TAknsItemID KAknsIIDQgnIndiVideoAc3Branding =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoAc3Branding };

static const TAknsItemID KAknsIIDQgnIndiVideoDolby =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVideoDolby };

static const TAknsItemID KAknsIIDQgnIndiWmAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWmAdd };

static const TAknsItemID KAknsIIDQgnLgalBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnLgalBg };

static const TAknsItemID KAknsIIDQgnLgalFav1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnLgalFav1 };

static const TAknsItemID KAknsIIDQgnLgalFav2 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnLgalFav2 };

static const TAknsItemID KAknsIIDQgnMenuHswidget =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuHswidget };

static const TAknsItemID KAknsIIDQgnPropCpConnSettings =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpConnSettings };

static const TAknsItemID KAknsIIDQgnPropPhotoAlbumLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPhotoAlbumLarge };

static const TAknsItemID KAknsIIDQgnPropPhotoAllLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPhotoAllLarge };

static const TAknsItemID KAknsIIDQgnPropPhotoCalendarLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPhotoCalendarLarge };

static const TAknsItemID KAknsIIDQgnPropPhotoLocLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPhotoLocLarge };

static const TAknsItemID KAknsIIDQgnPropPhotoTagLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPhotoTagLarge };

static const TAknsItemID KAknsIIDQgnHomePage11 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage11 };

static const TAknsItemID KAknsIIDQgnHomePage21 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage21 };

static const TAknsItemID KAknsIIDQgnHomePage22 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage22 };

static const TAknsItemID KAknsIIDQgnHomePage31 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage31 };

static const TAknsItemID KAknsIIDQgnHomePage32 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage32 };

static const TAknsItemID KAknsIIDQgnHomePage33 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage33 };

static const TAknsItemID KAknsIIDQgnHomePage41 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage41 };

static const TAknsItemID KAknsIIDQgnHomePage42 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage42 };

static const TAknsItemID KAknsIIDQgnHomePage43 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage43 };

static const TAknsItemID KAknsIIDQgnHomePage44 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage44 };

static const TAknsItemID KAknsIIDQgnHomePage51 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage51 };

static const TAknsItemID KAknsIIDQgnHomePage52 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage52 };

static const TAknsItemID KAknsIIDQgnHomePage53 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage53 };

static const TAknsItemID KAknsIIDQgnHomePage54 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage54 };

static const TAknsItemID KAknsIIDQgnHomePage55 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage55 };

static const TAknsItemID KAknsIIDQgnHomePage61 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage61 };

static const TAknsItemID KAknsIIDQgnHomePage62 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage62 };

static const TAknsItemID KAknsIIDQgnHomePage63 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage63 };

static const TAknsItemID KAknsIIDQgnHomePage64 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage64 };

static const TAknsItemID KAknsIIDQgnHomePage65 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage65 };

static const TAknsItemID KAknsIIDQgnHomePage66 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomePage66 };

static const TAknsItemID KAknsIIDQgnPropCpDevenc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCpDevenc };

static const TAknsItemID KAknsIIDQgnIndiCmailArrowNext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailArrowNext };

static const TAknsItemID KAknsIIDQgnIndiCmailArrowPrevious =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailArrowPrevious };

static const TAknsItemID KAknsIIDQgnIndiCmailOutboxMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailOutboxMsg };

static const TAknsItemID KAknsIIDQgnIndiCmailUnseenMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiCmailUnseenMsg };

static const TAknsItemID KAknsIIDQgnIndiHomeFriendEvent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHomeFriendEvent };

static const TAknsItemID KAknsIIDQgnIndiManyItemsAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiManyItemsAdd };

static const TAknsItemID KAknsIIDQgnMenuHswidgetContacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuHswidgetContacts };

static const TAknsItemID KAknsIIDQgnMenuHswidgetOneContact =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuHswidgetOneContact };

static const TAknsItemID KAknsIIDQgnMenuLogOut =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuLogOut };

static const TAknsItemID KAknsIIDQgnPropEmailSortAttachAsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortAttachAsc };

static const TAknsItemID KAknsIIDQgnPropEmailSortAttachDesc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortAttachDesc };

static const TAknsItemID KAknsIIDQgnPropEmailSortDateAsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortDateAsc };

static const TAknsItemID KAknsIIDQgnPropEmailSortDateDesc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortDateDesc };

static const TAknsItemID KAknsIIDQgnPropEmailSortFollowAsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortFollowAsc };

static const TAknsItemID KAknsIIDQgnPropEmailSortFollowDesc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortFollowDesc };

static const TAknsItemID KAknsIIDQgnPropEmailSortPriorityAsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortPriorityAsc };

static const TAknsItemID KAknsIIDQgnPropEmailSortPriorityDesc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortPriorityDesc };

static const TAknsItemID KAknsIIDQgnPropEmailSortSenderAsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortSenderAsc };

static const TAknsItemID KAknsIIDQgnPropEmailSortSenderDesc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortSenderDesc };

static const TAknsItemID KAknsIIDQgnPropEmailSortSizeAsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortSizeAsc };

static const TAknsItemID KAknsIIDQgnPropEmailSortSizeDesc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortSizeDesc };

static const TAknsItemID KAknsIIDQgnPropEmailSortSubjectAsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortSubjectAsc };

static const TAknsItemID KAknsIIDQgnPropEmailSortSubjectDesc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortSubjectDesc };

static const TAknsItemID KAknsIIDQgnPropEmailSortUnreadAsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortUnreadAsc };

static const TAknsItemID KAknsIIDQgnPropEmailSortUnreadDesc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEmailSortUnreadDesc };

static const TAknsItemID KAknsIIDQgnPropHomeNophotoFriend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHomeNophotoFriend };

static const TAknsItemID KAknsIIDQgnPropHomeRemoveFriend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropHomeRemoveFriend };

static const TAknsItemID KAknsIIDQgnPropLmLocfromapps =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmLocfromapps };

static const TAknsItemID KAknsIIDQgnPropLmRecentloc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLmRecentloc };

static const TAknsItemID KAknsIIDQgnPropLogMailSent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogMailSent };

static const TAknsItemID KAknsIIDQgnPropLogSmsSent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLogSmsSent };

static const TAknsItemID KAknsIIDQgnStatVisualVmUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatVisualVmUni };

static const TAknsItemID KAknsIIDQgnMenuN9720swu =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuN9720swu };

static const TAknsItemID KAknsIIDQgnGrafFpsBarFrame =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFpsBarFrame };

static const TAknsItemID KAknsIIDQgnGrafFpsBarProgress =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFpsBarProgress };

static const TAknsItemID KAknsIIDQgnGrafFpsNotAdequate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFpsNotAdequate };

static const TAknsItemID KAknsIIDQgnGrafFpsNotRecognized =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFpsNotRecognized };

static const TAknsItemID KAknsIIDQgnGrafFpsPrintOk =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFpsPrintOk };

static const TAknsItemID KAknsIIDQgnIndiAdaptSearchBackspace1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiAdaptSearchBackspace1 };

static const TAknsItemID KAknsIIDQgnIndiButtonAnswerWhite =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonAnswerWhite };

static const TAknsItemID KAknsIIDQgnIndiButtonLogdialerWhite =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonLogdialerWhite };

static const TAknsItemID KAknsIIDQgnIndiInputBackspace1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputBackspace1 };

static const TAknsItemID KAknsIIDQgnIndiItutBackspace1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiItutBackspace1 };

static const TAknsItemID KAknsIIDQgnIndiModeNotAutomatedAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiModeNotAutomatedAdd };

static const TAknsItemID KAknsIIDQgnIndiMusicshopTbAccount =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicshopTbAccount };

static const TAknsItemID KAknsIIDQgnIndiMusicshopTbHome =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicshopTbHome };

static const TAknsItemID KAknsIIDQgnIndiMusicshopTbSearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMusicshopTbSearch };

static const TAknsItemID KAknsIIDQgnIndiRadioTbGotoweb =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioTbGotoweb };

static const TAknsItemID KAknsIIDQgnIndiRadioTbList =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioTbList };

static const TAknsItemID KAknsIIDQgnIndiRadioTbManualtune =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioTbManualtune };

static const TAknsItemID KAknsIIDQgnIndiRadioTbMshop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioTbMshop };

static const TAknsItemID KAknsIIDQgnIndiRadioTbSongrecogn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRadioTbSongrecogn };

static const TAknsItemID KAknsIIDQgnMenuHswidgetClockProfiles =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuHswidgetClockProfiles };

static const TAknsItemID KAknsIIDQgnMenuHswidgetShortcuts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuHswidgetShortcuts };

static const TAknsItemID KAknsIIDQgnNoteFpsNotAdequate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteFpsNotAdequate };

static const TAknsItemID KAknsIIDQgnNoteFpsNotRecognized =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteFpsNotRecognized };

static const TAknsItemID KAknsIIDQgnNoteFpsPrintOk =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteFpsPrintOk };

static const TAknsItemID KAknsIIDQgnNoteRadioJackmini =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteRadioJackmini };

static const TAknsItemID KAknsIIDQgnPropSetAppsFps =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsFps };

static const TAknsItemID KAknsIIDQgnIndiTbFollowUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFollowUp };

static const TAknsItemID KAknsIIDQgnIndiTbFollowUpSelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbFollowUpSelected };

static const TAknsItemID KAknsIIDQgnIndiTbHideBcc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbHideBcc };

static const TAknsItemID KAknsIIDQgnIndiTbHideCc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbHideCc };

static const TAknsItemID KAknsIIDQgnIndiTbHighPriority =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbHighPriority };

static const TAknsItemID KAknsIIDQgnIndiTbHighPrioritySelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbHighPrioritySelected };

static const TAknsItemID KAknsIIDQgnIndiTbLowPriority =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbLowPriority };

static const TAknsItemID KAknsIIDQgnIndiTbLowPrioritySelected =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbLowPrioritySelected };

static const TAknsItemID KAknsIIDQgnIndiTbShowBcc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbShowBcc };

static const TAknsItemID KAknsIIDQgnIndiTbShowCc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbShowCc };

static const TAknsItemID KAknsIIDQgnNoteDevicelockSwipe =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteDevicelockSwipe };

static const TAknsItemID KAknsIIDQgnGrafFepCharButton =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafFepCharButton };

static const TAknsItemID KAknsIIDQgnIndiBigclockCalendar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBigclockCalendar };

static const TAknsItemID KAknsIIDQgnIndiBigclockCalls =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBigclockCalls };

static const TAknsItemID KAknsIIDQgnIndiBigclockEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBigclockEmail };

static const TAknsItemID KAknsIIDQgnIndiBigclockMail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBigclockMail };

static const TAknsItemID KAknsIIDQgnIndiBigclockVoicemail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBigclockVoicemail };

static const TAknsItemID KAknsIIDQgnIndiBigclockVoicemailStar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBigclockVoicemailStar };

static const TAknsItemID KAknsIIDQgnIndiBrowserTbExit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBrowserTbExit };

static const TAknsItemID KAknsIIDQgnIndiFepButtonCaseKoreanSymbol =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiFepButtonCaseKoreanSymbol };

static const TAknsItemID KAknsIIDQgnIndiInputCaseTextEnglishKorean =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseTextEnglishKorean };

static const TAknsItemID KAknsIIDQgnIndiInputCaseTextKoreanEnglish =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputCaseTextKoreanEnglish };

static const TAknsItemID KAknsIIDQgnIndiInputTableDown =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputTableDown };

static const TAknsItemID KAknsIIDQgnIndiInputTableUp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputTableUp };

static const TAknsItemID KAknsIIDQgnPropPbAddTop =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbAddTop };

static const TAknsItemID KAknsIIDQgnPropPbThumpMycard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropPbThumpMycard };

static const TAknsItemID KAknsIIDQsnBigclockScreensaverAnalogueFace =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockScreensaverAnalogueFace };

static const TAknsItemID KAknsIIDQsnBigclockScreensaverAnaloguePointerHours =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockScreensaverAnaloguePointerHours };

static const TAknsItemID KAknsIIDQsnBigclockScreensaverAnaloguePointerMinutes =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockScreensaverAnaloguePointerMinutes };

static const TAknsItemID KAknsIIDQsnBigclockScreensaverAnaloguePointerSeconds =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockScreensaverAnaloguePointerSeconds };

static const TAknsItemID KAknsIIDQgnHomeContactnameBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeContactnameBg };

static const TAknsItemID KAknsIIDQgnIndiBigclockIm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiBigclockIm };

static const TAknsItemID KAknsIIDQgnMenuActivenotesLinkToCallView =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuActivenotesLinkToCallView };

static const TAknsItemID KAknsIIDQgnMenuEzynotes =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuEzynotes };

static const TAknsItemID KAknsIIDQgnMenuSetwizLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuSetwizLst };

static const TAknsItemID KAknsIIDQgnMenuShortcutUnavailable =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuShortcutUnavailable };

static const TAknsItemID KAknsIIDQgnMenuSmartpromoui =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuSmartpromoui };

static const TAknsItemID KAknsIIDQgnMenuWelcome2Lst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuWelcome2Lst };

static const TAknsItemID KAknsIIDQgnMenuWelcomCxt =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuWelcomCxt };

static const TAknsItemID KAknsIIDQsnBigclockScreensaverDateBackgroundCenter =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockScreensaverDateBackgroundCenter };

static const TAknsItemID KAknsIIDQsnBigclockScreensaverDateBackgroundLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockScreensaverDateBackgroundLeft };

static const TAknsItemID KAknsIIDQsnBigclockScreensaverDateBackgroundRight =
    { EAknsMajorGeneric, EAknsMinorGenericQsnBigclockScreensaverDateBackgroundRight };

static const TAknsItemID KAknsIIDQgnHomeEmailLogos =
    { EAknsMajorGeneric, EAknsMinorGenericQgnHomeEmailLogos };

static const TAknsItemID KAknsIIDQgnIndiMessageAdd =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMessageAdd };

static const TAknsItemID KAknsIIDQgnStatJointImUni =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatJointImUni };

static const TAknsItemID KAknsIIDQgnVraIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnVraIcon };

static const TAknsItemID KAknsIIDQgnActivenotesFolder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnActivenotesFolder };

static const TAknsItemID KAknsIIDQgnActivenotesNote =
    { EAknsMajorGeneric, EAknsMinorGenericQgnActivenotesNote };

static const TAknsItemID KAknsIIDQgnGrafNotifBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNotifBg };

static const TAknsItemID KAknsIIDQgnIconAppCake =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIconAppCake };

static const TAknsItemID KAknsIIDQgnIndiActivenotesButtonNewGrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiActivenotesButtonNewGrid };

static const TAknsItemID KAknsIIDQgnIndiActivenotesButtonNewList =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiActivenotesButtonNewList };

static const TAknsItemID KAknsIIDQgnIndiActivenotesPlay =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiActivenotesPlay };

static const TAknsItemID KAknsIIDQgnIndiActivenotesRec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiActivenotesRec };

static const TAknsItemID KAknsIIDQgnIndiEzynoteButtonNew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiEzynoteButtonNew };

static const TAknsItemID KAknsIIDQgnIndiEzynoteButtonNewInactive =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiEzynoteButtonNewInactive };

static const TAknsItemID KAknsIIDQgnIndiEzynoteButtonNewList =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiEzynoteButtonNewList };

static const TAknsItemID KAknsIIDQgnIndiEzynoteButtonNewPressed =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiEzynoteButtonNewPressed };

static const TAknsItemID KAknsIIDQgnIndiHomePlasma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHomePlasma };

static const TAknsItemID KAknsIIDQgnIndiHomePlasmaCharging =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiHomePlasmaCharging };

static const TAknsItemID KAknsIIDQgnIndiMsgboardArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMsgboardArrowLeft };

static const TAknsItemID KAknsIIDQgnIndiMsgboardArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiMsgboardArrowRight };

static const TAknsItemID KAknsIIDQgnIndiPlasmaBatteryCharging =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiPlasmaBatteryCharging };

static const TAknsItemID KAknsIIDQgnIndiTbModesAddCurrentLoc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbModesAddCurrentLoc };

static const TAknsItemID KAknsIIDQgnIndiTbModesAddMyLoc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbModesAddMyLoc };

static const TAknsItemID KAknsIIDQgnIndiTbModesSelectMap =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbModesSelectMap };

static const TAknsItemID KAknsIIDQgnIndiTbMsgboardCreateMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMsgboardCreateMsg };

static const TAknsItemID KAknsIIDQgnIndiTbMsgboardDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMsgboardDelete };

static const TAknsItemID KAknsIIDQgnIndiTbMsgboardDetails =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMsgboardDetails };

static const TAknsItemID KAknsIIDQgnIndiTbMsgboardReply =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMsgboardReply };

static const TAknsItemID KAknsIIDQgnIndiTbMsgboardReplyGroup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMsgboardReplyGroup };

static const TAknsItemID KAknsIIDQgnIndiTbMsgboardSend =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTbMsgboardSend };

static const TAknsItemID KAknsIIDQgnIndiTpActivenotesNewFolder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpActivenotesNewFolder };

static const TAknsItemID KAknsIIDQgnIndiTpActivenotesNewNote =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiTpActivenotesNewNote };

static const TAknsItemID KAknsIIDQgnIndiVrRec =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiVrRec };

static const TAknsItemID KAknsIIDQgnLanguageIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnLanguageIcon };

static const TAknsItemID KAknsIIDQgnListAnimChicken =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimChicken };

static const TAknsItemID KAknsIIDQgnListAnimChickenBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimChickenBw };

static const TAknsItemID KAknsIIDQgnListAnimCow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimCow };

static const TAknsItemID KAknsIIDQgnListAnimCowBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimCowBw };

static const TAknsItemID KAknsIIDQgnListAnimDog =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimDog };

static const TAknsItemID KAknsIIDQgnListAnimDogBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimDogBw };

static const TAknsItemID KAknsIIDQgnListAnimDragon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimDragon };

static const TAknsItemID KAknsIIDQgnListAnimDragonBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimDragonBw };

static const TAknsItemID KAknsIIDQgnListAnimHorse =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimHorse };

static const TAknsItemID KAknsIIDQgnListAnimHorseBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimHorseBw };

static const TAknsItemID KAknsIIDQgnListAnimMonkey =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimMonkey };

static const TAknsItemID KAknsIIDQgnListAnimMonkeyBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimMonkeyBw };

static const TAknsItemID KAknsIIDQgnListAnimMouse =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimMouse };

static const TAknsItemID KAknsIIDQgnListAnimMouseBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimMouseBw };

static const TAknsItemID KAknsIIDQgnListAnimPig =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimPig };

static const TAknsItemID KAknsIIDQgnListAnimPigBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimPigBw };

static const TAknsItemID KAknsIIDQgnListAnimRabbit =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimRabbit };

static const TAknsItemID KAknsIIDQgnListAnimRabbitBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimRabbitBw };

static const TAknsItemID KAknsIIDQgnListAnimSheep =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimSheep };

static const TAknsItemID KAknsIIDQgnListAnimSheepBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimSheepBw };

static const TAknsItemID KAknsIIDQgnListAnimSnake =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimSnake };

static const TAknsItemID KAknsIIDQgnListAnimSnakeBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimSnakeBw };

static const TAknsItemID KAknsIIDQgnListAnimTiger =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimTiger };

static const TAknsItemID KAknsIIDQgnListAnimTigerBw =
    { EAknsMajorGeneric, EAknsMinorGenericQgnListAnimTigerBw };

static const TAknsItemID KAknsIIDQgnMcspluginLogOut =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMcspluginLogOut };

static const TAknsItemID KAknsIIDQgnMenuAnimplugingui =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuAnimplugingui };

static const TAknsItemID KAknsIIDQgnMenuCmccChinamobileservice =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuCmccChinamobileservice };

static const TAknsItemID KAknsIIDQgnMenuCmccCmmusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuCmccCmmusic };

static const TAknsItemID KAknsIIDQgnMenuCmccCmphonebook =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuCmccCmphonebook };

static const TAknsItemID KAknsIIDQgnMenuCmccCustomerservice =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuCmccCustomerservice };

static const TAknsItemID KAknsIIDQgnMenuCmccMonternet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuCmccMonternet };

static const TAknsItemID KAknsIIDQgnMenuCmccMyfavorite =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuCmccMyfavorite };

static const TAknsItemID KAknsIIDQgnMenuDcdAppicon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuDcdAppicon };

static const TAknsItemID KAknsIIDQgnMenuDcdChannelitem =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuDcdChannelitem };

static const TAknsItemID KAknsIIDQgnMenuDcdGssetting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuDcdGssetting };

static const TAknsItemID KAknsIIDQgnMenuModesAutoOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuModesAutoOn };

static const TAknsItemID KAknsIIDQgnMenuModesDefault =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuModesDefault };

static const TAknsItemID KAknsIIDQgnMenuMsgboard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuMsgboard };

static const TAknsItemID KAknsIIDQgnMenuN9721swu =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuN9721swu };

static const TAknsItemID KAknsIIDQgnMenuPlasma =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuPlasma };

static const TAknsItemID KAknsIIDQgnMsActivesearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsActivesearch };

static const TAknsItemID KAknsIIDQgnMsAnniversary =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsAnniversary };

static const TAknsItemID KAknsIIDQgnMsArrowLeft =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsArrowLeft };

static const TAknsItemID KAknsIIDQgnMsArrowRight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsArrowRight };

static const TAknsItemID KAknsIIDQgnMsCalendar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsCalendar };

static const TAknsItemID KAknsIIDQgnMsContacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsContacts };

static const TAknsItemID KAknsIIDQgnMsEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsEmail };

static const TAknsItemID KAknsIIDQgnMsEmailReceived =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsEmailReceived };

static const TAknsItemID KAknsIIDQgnMsEmailSent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsEmailSent };

static const TAknsItemID KAknsIIDQgnMsFiles =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsFiles };

static const TAknsItemID KAknsIIDQgnMsFilesApps =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsFilesApps };

static const TAknsItemID KAknsIIDQgnMsFilesAudio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsFilesAudio };

static const TAknsItemID KAknsIIDQgnMsFilesCategory =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsFilesCategory };

static const TAknsItemID KAknsIIDQgnMsFilesExcel =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsFilesExcel };

static const TAknsItemID KAknsIIDQgnMsFilesImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsFilesImage };

static const TAknsItemID KAknsIIDQgnMsFilesPowerpoint =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsFilesPowerpoint };

static const TAknsItemID KAknsIIDQgnMsFilesText =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsFilesText };

static const TAknsItemID KAknsIIDQgnMsFilesVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsFilesVideo };

static const TAknsItemID KAknsIIDQgnMsFilesWord =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsFilesWord };

static const TAknsItemID KAknsIIDQgnMsHelpCategoryIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsHelpCategoryIcon };

static const TAknsItemID KAknsIIDQgnMsIndevice1Music =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsIndevice1Music };

static const TAknsItemID KAknsIIDQgnMsIndevice2Contacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsIndevice2Contacts };

static const TAknsItemID KAknsIIDQgnMsIndevice2Placeholder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsIndevice2Placeholder };

static const TAknsItemID KAknsIIDQgnMsIndevice3Pictures =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsIndevice3Pictures };

static const TAknsItemID KAknsIIDQgnMsIndevice3Placeholder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsIndevice3Placeholder };

static const TAknsItemID KAknsIIDQgnMsIndevice4Placeholder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsIndevice4Placeholder };

static const TAknsItemID KAknsIIDQgnMsIndevice4Videos =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsIndevice4Videos };

static const TAknsItemID KAknsIIDQgnMsIndevice5PlacesLocations =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsIndevice5PlacesLocations };

static const TAknsItemID KAknsIIDQgnMsIndevice6aBookmarks =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsIndevice6aBookmarks };

static const TAknsItemID KAknsIIDQgnMsIndevice9AppsGames =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsIndevice9AppsGames };

static const TAknsItemID KAknsIIDQgnMsMeeting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsMeeting };

static const TAknsItemID KAknsIIDQgnMsMemo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsMemo };

static const TAknsItemID KAknsIIDQgnMsMessaging =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsMessaging };

static const TAknsItemID KAknsIIDQgnMsMmsReceived =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsMmsReceived };

static const TAknsItemID KAknsIIDQgnMsMmsSent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsMmsSent };

static const TAknsItemID KAknsIIDQgnMsNotes =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsNotes };

static const TAknsItemID KAknsIIDQgnMsOthersCategory =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsOthersCategory };

static const TAknsItemID KAknsIIDQgnMsSearchboxShadow =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsSearchboxShadow };

static const TAknsItemID KAknsIIDQgnMsSearchsettingsapp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsSearchsettingsapp };

static const TAknsItemID KAknsIIDQgnMsSmsReceived =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsSmsReceived };

static const TAknsItemID KAknsIIDQgnMsSmsSent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsSmsSent };

static const TAknsItemID KAknsIIDQgnMsTodos =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMsTodos };

static const TAknsItemID KAknsIIDQgnPopupAlarm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPopupAlarm };

static const TAknsItemID KAknsIIDQgnPropActivenotes =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotes };

static const TAknsItemID KAknsIIDQgnPropActivenotesBusinessCard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesBusinessCard };

static const TAknsItemID KAknsIIDQgnPropActivenotesFile =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesFile };

static const TAknsItemID KAknsIIDQgnPropActivenotesFileAudio =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesFileAudio };

static const TAknsItemID KAknsIIDQgnPropActivenotesFileBusinessCard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesFileBusinessCard };

static const TAknsItemID KAknsIIDQgnPropActivenotesFileCorrupted =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesFileCorrupted };

static const TAknsItemID KAknsIIDQgnPropActivenotesFileImage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesFileImage };

static const TAknsItemID KAknsIIDQgnPropActivenotesFileOther =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesFileOther };

static const TAknsItemID KAknsIIDQgnPropActivenotesFileVideo =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesFileVideo };

static const TAknsItemID KAknsIIDQgnPropActivenotesFolderGrid =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesFolderGrid };

static const TAknsItemID KAknsIIDQgnPropActivenotesFolderList =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesFolderList };

static const TAknsItemID KAknsIIDQgnPropActivenotesLinkToCall =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesLinkToCall };

static const TAknsItemID KAknsIIDQgnPropActivenotesLinkToCallList =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesLinkToCallList };

static const TAknsItemID KAknsIIDQgnPropActivenotesList =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesList };

static const TAknsItemID KAknsIIDQgnPropActivenotesLocation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropActivenotesLocation };

static const TAknsItemID KAknsIIDQgnPropCmccAreacode =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccAreacode };

static const TAknsItemID KAknsIIDQgnPropCmccChat =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccChat };

static const TAknsItemID KAknsIIDQgnPropCmccClubservice =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccClubservice };

static const TAknsItemID KAknsIIDQgnPropCmccCmmusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccCmmusic };

static const TAknsItemID KAknsIIDQgnPropCmccContactupdate =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccContactupdate };

static const TAknsItemID KAknsIIDQgnPropCmccCorporatemail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccCorporatemail };

static const TAknsItemID KAknsIIDQgnPropCmccCustomermanager =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccCustomermanager };

static const TAknsItemID KAknsIIDQgnPropCmccCustomermanagernumber =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccCustomermanagernumber };

static const TAknsItemID KAknsIIDQgnPropCmccFetion =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccFetion };

static const TAknsItemID KAknsIIDQgnPropCmccFinanceonline =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccFinanceonline };

static const TAknsItemID KAknsIIDQgnPropCmccForwardsms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccForwardsms };

static const TAknsItemID KAknsIIDQgnPropCmccGallery =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccGallery };

static const TAknsItemID KAknsIIDQgnPropCmccGames =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccGames };

static const TAknsItemID KAknsIIDQgnPropCmccGgame =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccGgame };

static const TAknsItemID KAknsIIDQgnPropCmccHotline =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccHotline };

static const TAknsItemID KAknsIIDQgnPropCmccLocalcontacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccLocalcontacts };

static const TAknsItemID KAknsIIDQgnPropCmccMagicbox =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccMagicbox };

static const TAknsItemID KAknsIIDQgnPropCmccMmscard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccMmscard };

static const TAknsItemID KAknsIIDQgnPropCmccMobilesearch =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccMobilesearch };

static const TAknsItemID KAknsIIDQgnPropCmccMobilesecretary =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccMobilesecretary };

static const TAknsItemID KAknsIIDQgnPropCmccMobilesecretarynumber =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccMobilesecretarynumber };

static const TAknsItemID KAknsIIDQgnPropCmccMomms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccMomms };

static const TAknsItemID KAknsIIDQgnPropCmccMonternet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccMonternet };

static const TAknsItemID KAknsIIDQgnPropCmccMosms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccMosms };

static const TAknsItemID KAknsIIDQgnPropCmccMovietv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccMovietv };

static const TAknsItemID KAknsIIDQgnPropCmccMymonternet =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccMymonternet };

static const TAknsItemID KAknsIIDQgnPropCmccNewservices =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccNewservices };

static const TAknsItemID KAknsIIDQgnPropCmccNewsweather =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccNewsweather };

static const TAknsItemID KAknsIIDQgnPropCmccOnlinecontacts =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccOnlinecontacts };

static const TAknsItemID KAknsIIDQgnPropCmccPbservices =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccPbservices };

static const TAknsItemID KAknsIIDQgnPropCmccPhoneanimation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccPhoneanimation };

static const TAknsItemID KAknsIIDQgnPropCmccPhonebook =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccPhonebook };

static const TAknsItemID KAknsIIDQgnPropCmccPhonebookmanager =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccPhonebookmanager };

static const TAknsItemID KAknsIIDQgnPropCmccPicturesringtones =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccPicturesringtones };

static const TAknsItemID KAknsIIDQgnPropCmccPlayer =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccPlayer };

static const TAknsItemID KAknsIIDQgnPropCmccPushemail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccPushemail };

static const TAknsItemID KAknsIIDQgnPropCmccSendsms =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccSendsms };

static const TAknsItemID KAknsIIDQgnPropCmccServicecenter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccServicecenter };

static const TAknsItemID KAknsIIDQgnPropCmccServiceguide =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccServiceguide };

static const TAknsItemID KAknsIIDQgnPropCmccSetting =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccSetting };

static const TAknsItemID KAknsIIDQgnPropCmccSimcardappication =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccSimcardappication };

static const TAknsItemID KAknsIIDQgnPropCmccTravelagent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccTravelagent };

static const TAknsItemID KAknsIIDQgnPropCmccYdzq =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccYdzq };

static const TAknsItemID KAknsIIDQgnPropCmccYdzqmore =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccYdzqmore };

static const TAknsItemID KAknsIIDQgnPropEzynotesFolder =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEzynotesFolder };

static const TAknsItemID KAknsIIDQgnPropEzynotesFolderLarge =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropEzynotesFolderLarge };

static const TAknsItemID KAknsIIDQgnPropLotus =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropLotus };

static const TAknsItemID KAknsIIDQgnPropModesAutomation =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModesAutomation };

static const TAknsItemID KAknsIIDQgnPropModesAutoOff =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModesAutoOff };

static const TAknsItemID KAknsIIDQgnPropModesAutoOn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModesAutoOn };

static const TAknsItemID KAknsIIDQgnPropModesCalendar =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModesCalendar };

static const TAknsItemID KAknsIIDQgnPropModesEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModesEmail };

static const TAknsItemID KAknsIIDQgnPropModesLandmark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModesLandmark };

static const TAknsItemID KAknsIIDQgnPropModesMsgkey =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModesMsgkey };

static const TAknsItemID KAknsIIDQgnPropModesProfile =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModesProfile };

static const TAknsItemID KAknsIIDQgnPropModesTheme =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModesTheme };

static const TAknsItemID KAknsIIDQgnPropMsgboard =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgboard };

static const TAknsItemID KAknsIIDQgnPropMsgboardMoreMsgSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgboardMoreMsgSub };

static const TAknsItemID KAknsIIDQgnPropMsgboardNewGroupSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgboardNewGroupSub };

static const TAknsItemID KAknsIIDQgnPropMsgboardRead =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgboardRead };

static const TAknsItemID KAknsIIDQgnPropMsgboardReadSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgboardReadSub };

static const TAknsItemID KAknsIIDQgnPropMsgboardSent =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgboardSent };

static const TAknsItemID KAknsIIDQgnPropMsgboardSentSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgboardSentSub };

static const TAknsItemID KAknsIIDQgnPropMsgboardUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgboardUnread };

static const TAknsItemID KAknsIIDQgnPropMsgboardUnreadSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropMsgboardUnreadSub };

static const TAknsItemID KAknsIIDQgnPropNotifCale =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNotifCale };

static const TAknsItemID KAknsIIDQgnPropNotifCalls =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNotifCalls };

static const TAknsItemID KAknsIIDQgnPropNotifDelete =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNotifDelete };

static const TAknsItemID KAknsIIDQgnPropNotifIm =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNotifIm };

static const TAknsItemID KAknsIIDQgnPropNotifMsg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNotifMsg };

static const TAknsItemID KAknsIIDQgnPropNotifVoicemail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropNotifVoicemail };

static const TAknsItemID KAknsIIDQgnPropSetActivenotesSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetActivenotesSub };

static const TAknsItemID KAknsIIDQgnPropSetAppsAn =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsAn };

static const TAknsItemID KAknsIIDQgnPropSetAppsAnykey =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetAppsAnykey };

static const TAknsItemID KAknsIIDQgnPropSetSlideSub =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropSetSlideSub };

static const TAknsItemID KAknsIIDQgnSetwizEmailMenuLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnSetwizEmailMenuLst };

static const TAknsItemID KAknsIIDQgnSetwizOperatorMenuLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnSetwizOperatorMenuLst };

static const TAknsItemID KAknsIIDQgnSetwizPttMenuLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnSetwizPttMenuLst };

static const TAknsItemID KAknsIIDQgnSetwizVsMenuLst =
    { EAknsMajorGeneric, EAknsMinorGenericQgnSetwizVsMenuLst };

static const TAknsItemID KAknsIIDQgnStatDcdChannelitemUnread =
    { EAknsMajorGeneric, EAknsMinorGenericQgnStatDcdChannelitemUnread };

static const TAknsItemID KAknsIIDQgnTeamuiActivenotespluginIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnTeamuiActivenotespluginIcon };

static const TAknsItemID KAknsIIDQgnWelcome2FinishedGraphic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcome2FinishedGraphic };

static const TAknsItemID KAknsIIDQgnWelcome2PluginEmailwizIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcome2PluginEmailwizIcon };

static const TAknsItemID KAknsIIDQgnWelcome2PluginEmailwizIntroGraphic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcome2PluginEmailwizIntroGraphic };

static const TAknsItemID KAknsIIDQgnWelcome2PluginPersIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcome2PluginPersIcon };

static const TAknsItemID KAknsIIDQgnWelcome2PluginPersIntroGraphic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcome2PluginPersIntroGraphic };

static const TAknsItemID KAknsIIDQgnWelcome2PluginSwitchIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcome2PluginSwitchIcon };

static const TAknsItemID KAknsIIDQgnWelcomeBackgroundDark =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcomeBackgroundDark };

static const TAknsItemID KAknsIIDQgnWelcomeBackgroundLight =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcomeBackgroundLight };

static const TAknsItemID KAknsIIDQgnWelcomePluginEmail =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcomePluginEmail };

static const TAknsItemID KAknsIIDQgnWelcomePluginEmailLandsc =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcomePluginEmailLandsc };

static const TAknsItemID KAknsIIDQgnWelcomePluginEmailPortr =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcomePluginEmailPortr };

static const TAknsItemID KAknsIIDQgnWelcomePluginMaps =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcomePluginMaps };

static const TAknsItemID KAknsIIDQgnWelcomePluginMusic =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcomePluginMusic };

static const TAknsItemID KAknsIIDQgnWelcomePluginSignup =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcomePluginSignup };

static const TAknsItemID KAknsIIDQgnWelcomeSetupComp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnWelcomeSetupComp };

static const TAknsItemID KAknsIIDQgnMenuWebtv =
    { EAknsMajorGeneric, EAknsMinorGenericQgnMenuWebtv };

static const TAknsItemID KAknsIIDQgnIndiButtonVideoShare =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiButtonVideoShare };

static const TAknsItemID KAknsIIDQgnGrafNotifNoEventsBg =
    { EAknsMajorGeneric, EAknsMinorGenericQgnGrafNotifNoEventsBg };

static const TAknsItemID KAknsIIDQgnIndiInputArabicBackspace =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputArabicBackspace };

static const TAknsItemID KAknsIIDQgnIndiInputArabicEnter =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputArabicEnter };

static const TAknsItemID KAknsIIDQgnIndiInputHwrArabicClose =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputHwrArabicClose };

static const TAknsItemID KAknsIIDQgnIndiInputHwrArabicPage12 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputHwrArabicPage12 };

static const TAknsItemID KAknsIIDQgnIndiInputHwrArabicPage13 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputHwrArabicPage13 };

static const TAknsItemID KAknsIIDQgnIndiInputHwrArabicPage22 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputHwrArabicPage22 };

static const TAknsItemID KAknsIIDQgnIndiInputHwrArabicPage23 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputHwrArabicPage23 };

static const TAknsItemID KAknsIIDQgnIndiInputHwrArabicPage33 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputHwrArabicPage33 };

static const TAknsItemID KAknsIIDQgnIndiInputHwrArabicSymbolTable =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputHwrArabicSymbolTable };

static const TAknsItemID KAknsIIDQgnIndiInputHwrArabicWritingArea =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiInputHwrArabicWritingArea };

static const TAknsItemID KAknsIIDQgnIndiManyItemsAdd1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiManyItemsAdd1 };

static const TAknsItemID KAknsIIDQgnIndiModeNotAutomatedAdd1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiModeNotAutomatedAdd1 };

static const TAknsItemID KAknsIIDQgnIndiRrsfeedwidgetFeedsTbAddnew =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiRrsfeedwidgetFeedsTbAddnew };

static const TAknsItemID KAknsIIDQgnIndiSignalGprsTdscdmaAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalGprsTdscdmaAttach };

static const TAknsItemID KAknsIIDQgnIndiSignalGprsTdscdmaContext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalGprsTdscdmaContext };

static const TAknsItemID KAknsIIDQgnIndiSignalGprsTdscdmaIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalGprsTdscdmaIcon };

static const TAknsItemID KAknsIIDQgnIndiSignalGprsTdscdmaMultipdp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalGprsTdscdmaMultipdp };

static const TAknsItemID KAknsIIDQgnIndiSignalGprsTdscdmaSuspended =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalGprsTdscdmaSuspended };

static const TAknsItemID KAknsIIDQgnIndiSignalHsdpaTdscdmaAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalHsdpaTdscdmaAttach };

static const TAknsItemID KAknsIIDQgnIndiSignalHsdpaTdscdmaContext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalHsdpaTdscdmaContext };

static const TAknsItemID KAknsIIDQgnIndiSignalHsdpaTdscdmaIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalHsdpaTdscdmaIcon };

static const TAknsItemID KAknsIIDQgnIndiSignalHsdpaTdscdmaMultipdp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalHsdpaTdscdmaMultipdp };

static const TAknsItemID KAknsIIDQgnIndiSignalHsdpaTdscdmaSuspended =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalHsdpaTdscdmaSuspended };

static const TAknsItemID KAknsIIDQgnIndiSignalTdscdmaAttach =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalTdscdmaAttach };

static const TAknsItemID KAknsIIDQgnIndiSignalTdscdmaContext =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalTdscdmaContext };

static const TAknsItemID KAknsIIDQgnIndiSignalTdscdmaIcon =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalTdscdmaIcon };

static const TAknsItemID KAknsIIDQgnIndiSignalTdscdmaMultipdp =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalTdscdmaMultipdp };

static const TAknsItemID KAknsIIDQgnIndiSignalTdscdmaSuspended =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiSignalTdscdmaSuspended };

static const TAknsItemID KAknsIIDQgnIndiWmAdd1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnIndiWmAdd1 };

static const TAknsItemID KAknsIIDQgnNoteFaxpc1 =
    { EAknsMajorGeneric, EAknsMinorGenericQgnNoteFaxpc1 };

static const TAknsItemID KAknsIIDQgnPropCmccCustomermanage =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropCmccCustomermanage };

static const TAknsItemID KAknsIIDQgnPropModesProfiles =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModesProfiles };

static const TAknsItemID KAknsIIDQgnPropModesThemes =
    { EAknsMajorGeneric, EAknsMinorGenericQgnPropModesThemes };

// SCMMARKER_INSERTIONPOINT

// SCCMARKER_END

// ============================================================================
// Other constants
// ============================================================================

/**
* UID that identifies active skin instance when fetched using
* <code>CCoeEnv::Static</code>.
*
* @since 2.0
*/
const TUid KAknsSkinInstanceTls         = {0x10005a27};

/**
* UID that identifies AppUi skin parameters when fetched using
* <code>CCoeEnv::Static</code>.
*
* @since 2.0
*/
const TUid KAknsAppUiParametersTls      = {0x101F84CD};

/**
* Skin change event UID value.
*
* @since 2.0
*/
const TInt KUidValueAknsSkinChangeEvent = 0x10005A30;

/**
* Skin change message value.
*
* @since 2.0
*/
const TInt KAknsMessageSkinChange       = 0x10005A31;

/**
* Image table indices for frame elements.
*
* @since 2.0
*/
enum TAknsFrameElementIndex
    {
    EAknsFrameIndexTl                   = 0,
    EAknsFrameIndexTr                   = 1,
    EAknsFrameIndexBl                   = 2,
    EAknsFrameIndexBr                   = 3,
    EAknsFrameIndexT                    = 4,
    EAknsFrameIndexB                    = 5,
    EAknsFrameIndexL                    = 6,
    EAknsFrameIndexR                    = 7,
    EAknsFrameIndexCenter               = 8,
    EAknsFrameElementsN                 = 9
    };

// ============================================================================
// Obsolete constants
// ============================================================================

// If defined, does not define obsolete constants.
#ifndef AKNS_EXCLUDE_OBSOLETE_CONSTANTS

/**
* Obsolete, do not use!
*/
enum TAknsCommonIIDMajorValue
    {
    EAknsIIDMajorNone           = -1,
    EAknsIIDMajorDefault        = 0,
    EAknsIIDMajorAppIcon        = EAknsMajorAppIcon,
    EAknsIIDMajorAppIconBmpLst  = EAknsMajorAppIconBmpLst,
    EAknsIIDMajorAppIconBmpCtx  = EAknsMajorAppIconBmpCxt,
    EAknsIIDMajorSkinBmp        = EAknsMajorSkin,
    EAknsIIDMajorEikCtlBmp      = 0x1000489c,   // EikCtl UID
    EAknsIIDMajorAvkonBmp       = EAknsMajorAvkon
    };

/**
* Obsolete, do not use!
*/
enum TAknsCommonIIDMinorValue
    {
    EAknsIIDMinorNone           = EAknsMinorNone,
    EAknsIIDMinorDefault        = EAknsMinorDefault
    };

/**
* Obsolete, do not use!
*/
enum TAknsSkinBmpControlPaneColorTableIndex
    {
    EAknsCTISkinBmpControlPane_CbaText      = 0,
    EAknsCTISkinBmpControlPane_ScindFirst   = 0,
    EAknsCTISkinBmpControlPane_ScindLast    = 15
    };

/**
* Obsolete, do not use!
*/
enum TAknsSkinBmpIIDMinorValue
    {
    EAknsIIDMinorSkinBmpControlPane                 = EAknsMinorQsnBgAreaControl,
    EAknsIIDMinorSkinBmpControlPaneColorTable       = EAknsMinorNone,
    EAknsIIDMinorSkinBmpIdleWallpaperDefault        = EAknsMinorQsnBgAreaMainIdle,
    EAknsIIDMinorSkinBmpPinboardWallpaperDefault    = EAknsMinorNone,
    EAknsIIDMinorSkinBmpMainPaneUsual               = EAknsMinorQsnBgAreaMain,
    EAknsIIDMinorSkinBmpListPaneNarrowA             = EAknsMinorQsnBgColumnA,
    EAknsIIDMinorSkinBmpListPaneWideA               = EAknsMinorQsnBgColumnAB,
    EAknsIIDMinorSkinBmpNoteBgDefault               = EAknsMinorNone,

    // R_AVKON_STATUS_PANE_LAYOUT_USUAL
    EAknsIIDMinorSkinBmpStatusPaneUsual             = EAknsMinorQsnBgAreaStatus,

    // R_AVKON_STATUS_PANE_LAYOUT_IDLE
    EAknsIIDMinorSkinBmpStatusPaneIdle              = EAknsMinorQsnBgAreaStatus
    };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDSkinBmpControlPane =
    { EAknsIIDMajorSkinBmp, EAknsIIDMinorSkinBmpControlPane };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDSkinBmpControlPaneColorTable =
    { EAknsIIDMajorSkinBmp, EAknsIIDMinorSkinBmpControlPaneColorTable };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDSkinBmpIdleWallpaperDefault =
    { EAknsIIDMajorSkinBmp, EAknsIIDMinorSkinBmpIdleWallpaperDefault };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDSkinBmpPinboardWallpaperDefault =
    { EAknsIIDMajorSkinBmp, EAknsIIDMinorSkinBmpPinboardWallpaperDefault };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDSkinBmpMainPaneUsual =
    { EAknsIIDMajorSkinBmp, EAknsIIDMinorSkinBmpMainPaneUsual };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDSkinBmpListPaneNarrowA =
    { EAknsIIDMajorSkinBmp, EAknsIIDMinorSkinBmpListPaneNarrowA };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDSkinBmpListPaneWideA =
    { EAknsIIDMajorSkinBmp, EAknsIIDMinorSkinBmpListPaneWideA };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDSkinBmpNoteBgDefault =
    { EAknsIIDMajorSkinBmp, EAknsIIDMinorSkinBmpNoteBgDefault };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDSkinBmpStatusPaneUsual =
    { EAknsIIDMajorSkinBmp, EAknsIIDMinorSkinBmpStatusPaneUsual };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDSkinBmpStatusPaneIdle =
    { EAknsIIDMajorSkinBmp, EAknsIIDMinorSkinBmpStatusPaneIdle };

/**
* Obsolete, do not use!
*/
enum TAknsAvkonBmpIIDMinorValue
    {
    EAknsIIDMinorAvkonBmpTab21            = 0,
    EAknsIIDMinorAvkonBmpTab22            = 2,
    EAknsIIDMinorAvkonBmpTab31            = 4,
    EAknsIIDMinorAvkonBmpTab32            = 6,
    EAknsIIDMinorAvkonBmpTab33            = 8,
    EAknsIIDMinorAvkonBmpTab41            = 10,
    EAknsIIDMinorAvkonBmpTab42            = 12,
    EAknsIIDMinorAvkonBmpTab43            = 14,
    EAknsIIDMinorAvkonBmpTab44            = 16,
    EAknsIIDMinorAvkonBmpTabLong21        = 18,
    EAknsIIDMinorAvkonBmpTabLong22        = 20,
    EAknsIIDMinorAvkonBmpTabLong31        = 22,
    EAknsIIDMinorAvkonBmpTabLong32        = 24,
    EAknsIIDMinorAvkonBmpTabLong33        = 26
    };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTab21 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTab21 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTab22 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTab22 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTab31 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTab31 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTab32 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTab32 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTab33 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTab33 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTab41 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTab41 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTab42 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTab42 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTab43 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTab43 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTab44 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTab44 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTabLong21 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTabLong21 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTabLong22 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTabLong22 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTabLong31 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTabLong31 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTabLong32 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTabLong32 };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDAvkonBmpTabLong33 =
    { EAknsIIDMajorAvkonBmp, EAknsIIDMinorAvkonBmpTabLong33 };

/**
* Obsolete, do not use!
*/
enum TAknsMinorSkinValueOBSOLETE
    {
    // Digital clock
    EAknsMinorQsnCpClockDigital0        = 0x4010,
    EAknsMinorQsnCpClockDigital1        = 0x4011,
    EAknsMinorQsnCpClockDigital2        = 0x4012,
    EAknsMinorQsnCpClockDigital3        = 0x4013,
    EAknsMinorQsnCpClockDigital4        = 0x4014,
    EAknsMinorQsnCpClockDigital5        = 0x4015,
    EAknsMinorQsnCpClockDigital6        = 0x4016,
    EAknsMinorQsnCpClockDigital7        = 0x4017,
    EAknsMinorQsnCpClockDigital8        = 0x4018,
    EAknsMinorQsnCpClockDigital9        = 0x4019,
    EAknsMinorQsnCpClockDigitalPeriod   = 0x401a,
    EAknsMinorQsnCpClockDigital0MaskSoft= 0x4020,
    EAknsMinorQsnCpClockDigital1MaskSoft= 0x4021,
    EAknsMinorQsnCpClockDigital2MaskSoft= 0x4022,
    EAknsMinorQsnCpClockDigital3MaskSoft= 0x4023,
    EAknsMinorQsnCpClockDigital4MaskSoft= 0x4024,
    EAknsMinorQsnCpClockDigital5MaskSoft= 0x4025,
    EAknsMinorQsnCpClockDigital6MaskSoft= 0x4026,
    EAknsMinorQsnCpClockDigital7MaskSoft= 0x4027,
    EAknsMinorQsnCpClockDigital8MaskSoft= 0x4028,
    EAknsMinorQsnCpClockDigital9MaskSoft= 0x4029,
    EAknsMinorQsnCpClockDigitalPeriodMaskSoft = 0x402a
    };

/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital0 =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital0 };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital1 =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital1 };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital2 =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital2 };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital3 =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital3 };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital4 =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital4 };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital5 =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital5 };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital6 =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital6 };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital7 =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital7 };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital8 =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital8 };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital9 =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital9 };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigitalPeriod =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalPeriod };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital0MaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital0MaskSoft };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital1MaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital1MaskSoft };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital2MaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital2MaskSoft };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital3MaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital3MaskSoft };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital4MaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital4MaskSoft };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital5MaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital5MaskSoft };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital6MaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital6MaskSoft };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital7MaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital7MaskSoft };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital8MaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital8MaskSoft };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigital9MaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigital9MaskSoft };
/**
* Obsolete, do not use!
*/
static const TAknsItemID KAknsIIDQsnCpClockDigitalPeriodMaskSoft =
    { EAknsMajorSkin, EAknsMinorQsnCpClockDigitalPeriodMaskSoft };

// If defined, does not define obsolete constants.
#endif // AKNS_EXCLUDE_OBSOLETE_CONSTANTS

#endif // AKNSCONSTANTS_H

// End of File
