/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   autotimer.h
/// \author Martin Reddy
/// \brief  An example of an API using the Pimpl idiom.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

#ifndef C2E71D0F_1F98_4CDC_B402_0A1BDD45F6E2
#define C2E71D0F_1F98_4CDC_B402_0A1BDD45F6E2

#ifndef AUTOTIMER_H
#define AUTOTIMER_H

#include <string>

namespace apibook {

///
/// An object that reports how long it was alive for when it
/// is destroyed.
///
class AutoTimer
{
public:
	/// Create a new timer object with a human-readable name
	explicit AutoTimer(const std::string &name);
	/// On destruction, the timer reports how long it was alive
	~AutoTimer();

private:
	// Make this object be noncopyable because it holds a pointer
	AutoTimer(const AutoTimer &);
	const AutoTimer &operator =(const AutoTimer &);

	class Impl;
	Impl *mImpl;
};

}

#endif


#endif /* C2E71D0F_1F98_4CDC_B402_0A1BDD45F6E2 */
