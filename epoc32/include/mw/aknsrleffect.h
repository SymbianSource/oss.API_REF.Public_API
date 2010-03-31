/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  ?Description
*
*/


#ifndef AKNSRLEFFECT_H
#define AKNSRLEFFECT_H

//  INCLUDES
#include <AknsRlEffectContext.h>
#include <AknsRlParameter.h>

// CONSTANTS

/**
* Constant value indicating that @c MAknsRlEffect::Render has not completed
* rendering and should be called again.
*
* @since 2.8
*/
const TInt KAknsRlRenderIncomplete        = 1;

// DATA TYPES

/**
* Effect capabilities structure.
*
* @since 2.8
*/
struct TAknsRlEffectCaps
    {
    /**
    * Supported status of input layer A.
    * This must be a binary combination of @c KAknsRlLayer constants.
    *
    * @since 2.8
    */
    TInt iInputLayerASupport;

    /**
    * Supported status of input layer B.
    * This must be a binary combination of @c KAknsRlLayer constants.
    *
    * @since 2.8
    */
    TInt iInputLayerBSupport;

    /**
    * Supported status of output layer.
    * This must be a binary combination of @c KAknsRlLayer constants.
    *
    * @since 2.8
    */
    TInt iOutputLayerSupport;
    };

/**
* Rendering operation parameter structure.
*
* @since 2.8
*/
struct TAknsRlRenderOpParam
    {
    /**
    * Status (including channel configuration) of input layer A.
    * This value must be one of @c KAknsRlLayer constants.
    *
    * @since 2.8
    */
    TInt iInputLayerAStatus;

    /**
    * Index of input layer A.
    * If iInputLayerAStatus is @c KAknsRlLayerNone, this value is
    * undefined.
    *
    * @since 2.8
    */
    TInt iInputLayerAIndex;

    /**
    * Status (including channel configuration) of input layer B.
    * This value must be one of @c KAknsRlLayer constants.
    *
    * @since 2.8
    */
    TInt iInputLayerBStatus;

    /**
    * Index of input layer B.
    * If iInputLayerBStatus is @c KAknsRlLayerNone, this value is
    * undefined.
    *
    * @since 2.8
    */
    TInt iInputLayerBIndex;

    /**
    * Status (including channel configuration) of output layer.
    * This value must be one of @c KAknsRlLayer constants.
    * The value of this field is never @c KAknsRlLayerNone.
    *
    * @since 2.8
    */
    TInt iOutputLayerStatus;

    /**
    * Index of output layer.
    *
    * @since 2.8
    */
    TInt iOutputLayerIndex;
    };

// FORWARD DECLARATIONS

// CLASS DECLARATION

/**
* Interface to skin effect plugin implementation.
* 
* States of an effect plugin are:
*  - Dead: Effect plugin has not been created. Destructing the plugin
*       returns the plugin to this state.
*  - Created: Effect plugin has been created (by calling its default
*       constructor). No dynamic data can be allocated at this state.
*       Call to @c Release returns the plugin to this state.
*  - Initialized: Effect plugin has been successfully initialized
*       (by calling @c InitializeL). Any dynamic data (common to the
*       entire lifetime of the plugin) has been constructed.
*       Call to @c Deactivate returns the plugin to this state.
*  - Activated: Effect plugin has been successfully activated
*       for rendering (by calling @c ActivateL). This is the only
*       state where parameter setup or rendering can take place.
*
* A plugin instance is owned by the effect pool. A plugin instance
* is activated by the effect renderer to perform one rendering
* operation.
*
* The effect renderer maintains a set of layers to store graphical
* content during the rendering of a single skin item. The effect renderer
* provides the active plugin with an effect context that is used to access
* these layers.
*
* The plugin may assume the following restrictions:
*  - No calls (except construction) are made to a dead plugin.
*  - No calls (except initialization or destruction) are made to a 
*       created plugin.
*  - Parameter setup or rendering operation is never requested from
*       a plugin that has not been activated.
*  - Capabilities can be queried only from an initialized or activated
*       plugin.
*  - After a rendering operation has been requested, no further
*       parameter setup or capability queries are made.
*
* @since 2.8
*/
class MAknsRlEffect
    {
    public: // Constructors and destructor

        // This interface is not used to control ownership.

    public: // New functions - Lifetime handling

        /**
        * Initializes the effect plugin instance.
        *
        * This method is called once for each effect by the effect pool before
        * calls to any other methods are made.
        *
        * @par Exceptions:
        * If effect plugin initialization fails (i.e., this method leaves
        * with an error code), the effect is considered to be non-existent.
        * 
        * @since 2.8
        */
        virtual void InitializeL() =0;

        /**
        * Releases the effect plugin instance.
        *
        * This method is called once for each effect by the effect pool. No
        * calls to any methods can be done after this method has been called.
        *
        * @since 2.8
        */
        virtual void Release() =0;

        /**
        * Activates the effect plugin to perform a single rendering operation.
        *
        * This method is called once by the effect renderer before a rendering
        * operation is requested.
        *
        * @param aContext Effect context. The context is guaranteed to be valid
        *   (and non-null) until @c Deactivate is called. No ownership is
        *   transferred.
        *
        * @par Exceptions:
        * If effect plugin activation fails (i.e., this method leaves with an 
        * error code), the effect renderer may try to re-activate the effect
        * later or instruct the effect pool to release it permanently 
        * (by calling @c Release).
        *
        * @since 2.8
        */
        virtual void ActivateL( MAknsRlEffectContext* aContext ) =0;

        /**
        * Deactivates the effect plugin after a rendering operation.
        *
        * This method is called once by the effect renderer after a rendering
        * operation has completed, or the operation is aborted.
        *
        * @since 2.8
        */
        virtual void Deactivate() =0;

    public: // New functions - Rendering setup

        /**
        * Sets the parameters for an active effect plugin.
        *
        * The effect may call this method zero or more times for any
        * active plugin before starting the rendering operation
        *
        * If any parameter appears more than once in the given iterator
        * (or in iterators given in more than one call to this method),
        * the latest parameter value must be used. Already set parameters
        * can not be removed, but their values can be updated.
        *
        * Any parameters not supported by this plugin at all (i.e., the
        * name of the parameter is not recognized) must be ignored silently.
        * If parameter type or value is not supported, the plugin may 
        * leave with @c KErrArgument.
        *
        * If a particular combination of parameters is not supported
        * (and further calls to this method can not change the situation), 
        * the plugin may leave with @c KErrArgument. Otherwise, the invalid
        * combination should be checked in @c Render.
        *
        * @c SetParametersL should also leave if the parameter values
        * can not be stored, e.g., because of an OOM condition.
        *
        * @param aParameters Iterator to the parameters. The iterator (and all
        *   the returned values) is guaranteed to be valid during the call
        *   to this method. No ownership is transferred, unless specified 
        *   otherwise in iterator API.
        *
        * @par Exceptions:
        * If parameter setup fails (i.e., this method leaves with an error 
        * code), the effect renderer will abort the rendering operation and 
        * deactivate the plugin.
        *
        * @since 2.8
        */
        virtual void SetParametersL(
            MAknsRlParameterIterator& aParameters ) =0;

    public: // New functions - Capability retrieval

        /**
        * Retrieves the capabilities of the effect plugin.
        *
        * The capabilities returned by this method must reflect the currently
        * set parameters (if any). If @c SetParametersL is called after 
        * querying the capabilities, the effect renderer may call this method
        * again to fetch the updated capabilities.
        *
        * If this method is called for an effect instance that has been
        * initialized but not activated, the capabilities must reflect the
        * support for any (valid and supported) parameters. If the plugin
        * can not determine the capabilities without knowing the parameters,
        * it must set all the layer support fields to 
        * @c KAknsRlLayerNone.
        *
        * If the returned capabilities indicate that no output layer is
        * supported (only @c KAknsRlLayerNone is returned in output layer
        * field), the rendering operation will not be started at all,
        * unless additional parameters are supplied.
        *
        * @param aCaps Capabilities structure that the plugin must fill
        *   during the call. The initial values of the structure are
        *   undefined.
        *
        * @since 2.8
        */
        virtual void GetCapabilities( TAknsRlEffectCaps& aCaps ) =0;

    public: // New functions - Rendering

        /**
        * Renders the effect.
        *
        * The plugin implementation can perform rendering in one or more
        * steps. Although the plugin has access to all the layers
        * (and both RGB and alpha channels) during rendering, it should
        * only use the content of the input layers (and channels) 
        * specified in @c aParam. Similarly, it should only alter the
        * content of the specified output layer (and channels), although
        * the context initialization for previously unused layers should
        * be followed.
        *
        * The same layer index can be specified as both the input and
        * the output layer (if at least one input layer is supported by the 
        * plugin). The plugin must implement the effect so that any combination
        * of layer indices is correctly rendered.
        *
        * The plugin may assume that rendering operation is never called
        * with parameters inconsistent with the plugin capabilities (as
        * the capabilities would have been returned if @c GetCapabilities was
        * called just before starting the rendering operation).
        *
        * @param aParam Rendering operation parameters. The structure
        *   is guaranteed to be valid for the duration of the call.
        *   If @c KAknsRlRenderIncomplete is returned, the same structure
        *   is given for subsequent calls.
        *
        * @return Result of the rendering operation. This must be one of the
        *   following values:
        *   - @c KErrNone Rendering was completed successfully.
        *   - @c KAknsRlRenderIncomplete Rendering was not completed and
        *       @c Render should be called again.
        *   - Any negative value indicates that an error occured. Notably,
        *       @c KErrArgument must be returned, if the given combination
        *       of parameters is not supported, or the parameters are
        *       insufficient. The effect renderer will deactivate the plugin.
        *
        * @since 2.8
        */
        virtual TInt Render( const TAknsRlRenderOpParam& aParam ) =0;
    };

#endif // AKNSRLEFFECT_H
            
// End of File
