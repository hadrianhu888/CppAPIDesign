/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   rendererfactory.h
/// \author Martin Reddy
/// \brief  A factory object to create Renderer instances.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

#ifndef B8CB8BFA_B7BF_47AD_9906_E2BD7F8D6AF8
#define B8CB8BFA_B7BF_47AD_9906_E2BD7F8D6AF8

#ifndef RENDERERFACTORY_H
#define RENDERERFACTORY_H

#include "renderer.h"
#include <string>

///
/// A factory object that creates instances of different
/// 3D renderers.
///
class RendererFactory
{
public:
	/// Create a new instance of a named 3D renderer.
	/// type can be one of "opengl", "directx", or "mesa"
	IRenderer *CreateRenderer(const std::string &type);
};

#endif


#endif /* B8CB8BFA_B7BF_47AD_9906_E2BD7F8D6AF8 */
