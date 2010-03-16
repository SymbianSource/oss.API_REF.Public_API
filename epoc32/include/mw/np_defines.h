/*
* Copyright (c) 2008 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Plugin defines that are specific to Symbian OS.
*
*/

#ifndef NP_DEFINES_H
#define NP_DEFINES_H

struct TKeyEvent;
struct TPointerEvent;

enum TNppEventType
{
    ENppEventKey,
    ENppEventPointer,
    ENppEventDraw,
    ENppEventVisibility
};

typedef struct _NPEventKey
{
    const TKeyEvent* keyEvent;
    unsigned int type;
    void* reserved;
} NPEventKey;

typedef struct _NPEventPointer
{
    const TPointerEvent* pointerEvent;
    void* reserved;
} NPEventPointer;

typedef struct _NpEventVisibility
{
    bool visible;
    void* reserved;
} NpEventVisibility;

#endif      // NP_DEFINES_H

// End of File

