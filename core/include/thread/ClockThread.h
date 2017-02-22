// ClockThread.h
// author: Johannes Wagner <wagner@hcm-lab.de>
// created: 2014/12/02
// Copyright (C) University of Augsburg, Lab for Human Centered Multimedia
//
// *************************************************************************************************
//
// This file is part of Social Signal Interpretation (SSI) developed at the 
// Lab for Human Centered Multimedia of the University of Augsburg
//
// This library is free software; you can redistribute itand/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3 of the License, or any laterversion.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FORA PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along withthis library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
//
//*************************************************************************************************

#pragma once

#ifndef SSI_THREAD_TIMEDTHREAD_H
#define SSI_THREAD_TIMEDTHREAD_H

#include "thread/Thread.h"
#include "thread/Timer.h"

namespace ssi {

class ClockThread : public Thread {

public:

	ClockThread (ssi_size_t timeout_in_ms = 10000);
	~ClockThread();

	void setClockS (ssi_time_t seconds);
	void setClockMs(ssi_size_t milliseconds);
	void setClockHz(ssi_time_t hz);

protected:

	static int ssi_log_level;
	static ssi_char_t *ssi_log_name;

	virtual void clock() = 0;

	void run ();	

	Timer _timer;
};


}

#endif
