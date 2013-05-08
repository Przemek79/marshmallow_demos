/*
 * Copyright (c) 2013, Guillermo A. Amaral B. (gamaral) <g@maral.me>
 * All rights reserved.
 *
 * This file is part of Marshmallow Game Engine.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of the project as a whole.
 */

#pragma once

/*!
 * @file
 *
 * @author Guillermo A. Amaral B. (gamaral) <g@maral.me>
 */

#ifndef MARSHMALLOW_DEMOS_INPUTCOMPONENT_H
#define MARSHMALLOW_DEMOS_INPUTCOMPONENT_H 1

#include <game/component.h>
#include <event/ieventlistener.h>

MARSHMALLOW_NAMESPACE_BEGIN
namespace Game { class MovementComponent; }
MARSHMALLOW_NAMESPACE_END

MARSHMALLOW_NAMESPACE_USE

class InputComponent : public Game::Component
                     , public Event::IEventListener
{
	enum State {
		Idle = 0,
		Moving,
		Stopping 
	};

	Game::MovementComponent *m_movement_component;
	State m_state;

public:
	InputComponent(const Core::Identifier &identifier,
	               Game::IEntity *entity);
	virtual ~InputComponent(void);

public: /* reimp */

	VIRTUAL const Core::Type & type(void) const
	        { return(Type()); }

	VIRTUAL void update(float);

	VIRTUAL bool handleEvent(const Event::IEvent &event);

public: /* static */

	static const Core::Type & Type(void);

protected:

	void moveUp(void);
	void moveDown(void);
	void stop(void);
};

#endif
