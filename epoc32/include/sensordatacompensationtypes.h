/*
* Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Sensor data compensation types definitions.
*
*/


#ifndef SENSORDATACOMPENSATIONTYPES_H
#define SENSORDATACOMPENSATIONTYPES_H

/**
* Sensor data compensation types
*/  
enum TSensorCompensationType
    {
    ESensorCompensateDeviceOrientation = 0, // Use device orientation in compensation
    ESensorCompensateUIOrientation,         // Use UI orientation in compensation
    ESensorCompensateDeviceAndUIOrientation // Use both device and UI orientation in compensation
    };

#endif // SENSORDATACOMPENSATIONTYPES
