// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
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

#ifndef __IMAGE_PROCESSOR_OBSERVER_H__
#define __IMAGE_PROCESSOR_OBSERVER_H__

#include <e32base.h>

namespace ImageProcessor
	{

class CImgProcessor;

/**
Plugin API for the observer of CImgProcessor.
When the CImgProcessor is set to EOptionNone, which means effects, geometric operations and rendering 
are applied asynchronously. After certain operations such as initialization or rendering finished, or after each iteration 
of operation, the certain function will be called, so that user can perform corresponding response. 

@see TEvent
@publishedAll
@released
*/	
class MImgProcessorObserver
	{
public: 
	/**
	The derived class must provide an implementation to perform actions after ImageProcessor complete its initialization
	
	@param  aImageProcessor
    		The CImgProcessor which has finished the initialization
    @param  aError
    		any error happened in the CImgProcessor initialize process
    */
	virtual void ImageProcessorInitializingComplete(CImgProcessor& aImageProcessor, TInt aError) = 0;
	
	/**
	The derived class must provide an implementation to perform actions after the preview of ImageProcessor complete its initialization
	
	@param  aImageProcessor
    		The CImgProcessor which has finished the initialization of its prview
    @param  aPreviewId
    		the id of the preview which has finished the initialization
    @param  aError
    		any error happened in the CImgProcessor preview initialize process
    */
	virtual void ImageProcessorPreviewInitializingComplete(CImgProcessor& aImageProcessor, TInt aPreviewId, TInt aError) = 0;
	
	/**
	The derived class must provide an implementation to perform actions after ImageProcessor complete its action of image processing
	
	@param  aImageProcessor
    		The CImgProcessor which has finished the rendering
    @param  aError
    		any error happened in the CImgProcessor rendering process
    */
	virtual void ImageProcessingComplete(CImgProcessor& aImageProcessor, TInt aError) = 0;
	
	/**
	The derived class must provide an implementation to perform actions after the preview of ImageProcessor complete its rendering process
	
	@param  aImageProcessor
    		The CImgProcessor which has finished the rendering of its prview
    @param  aPreviewId
    		the id of the preview which has finished the rendering
    @param  aError
    		any error happened in the CImgProcessor preview rendering process
    */
	virtual void ImageProcessorPreviewRenderingComplete(CImgProcessor& aImageProcessor, TInt aPreviewId, TInt aError) = 0;
	
	/**
	During image processing, after each iteration, this function will be notified and
	the derived class must provide an implementation to perform actions (optional) such as showing messages to response.
	
	@param  aImageProcessor
    		The current CImgProcessor 
    @param  aEventId
    		the event id of the current iteration, which is defined in imageprocessor.h as TEvent enumeration,
    		could be EEventInitializing, EEventProcessing, EEventRendering, EEventPreviewInitializing or EEventPreviewRendering,
    @param  aUid
    		The value depends on aEventId, and reserved for future purpose
    @param  aId
    		The value depends on aEventId, for example, if aEventId is EEventPreviewRendering, aId will be the id of the preview.
    */
	virtual void ImageProcessorEvent(CImgProcessor& aImageProcessor, TInt aEventId, TUid aUid, TInt aId) = 0;
	};

}	//namespace ImageProcessor

#endif //__IMAGE_PROCESSOR_OBSERVER_H__
