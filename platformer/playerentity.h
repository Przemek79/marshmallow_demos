/*
 * Copyright (c) 2011-2013, Guillermo A. Amaral B. (gamaral) <g@maral.me>
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

#ifndef DEMO_PLAYERENTITY_H
#define DEMO_PLAYERENTITY_H 1

#include "../common/actorentity.h"

#include <core/shared.h>

MARSHMALLOW_NAMESPACE_BEGIN
namespace Game
{
	class AudioComponent;
	typedef Core::Shared<AudioComponent> SharedAudioComponent;

	class AnimationComponent;
	typedef Core::Shared<AnimationComponent> SharedAnimationComponent;

	class MovementComponent;
	typedef Core::Shared<MovementComponent> SharedMovementComponent;
}
MARSHMALLOW_NAMESPACE_END

MARSHMALLOW_NAMESPACE_USE

class InputComponent;
typedef Core::Shared<InputComponent> SharedInputComponent;

class ActorColliderComponent;
typedef Core::Shared<ActorColliderComponent> SharedActorColliderComponent;

class PlayerEntity : public Common::ActorEntity
{
	Game::SharedAudioComponent m_audio_component;
	Game::SharedAnimationComponent m_animation_component;
	Game::SharedMovementComponent m_movement_component;
	SharedActorColliderComponent m_collider_component;
	SharedInputComponent m_input_component;

	int m_direction;
	float m_moving_sky;
	double m_moving_sky_bg;
	bool m_in_motion;
	bool m_on_platform;
	bool m_init;

	NO_ASSIGN_COPY(PlayerEntity);
public:

	PlayerEntity(const Core::Identifier &identifier, Game::EntitySceneLayer &layer);
	virtual ~PlayerEntity(void);

public: /* virtual */

	VIRTUAL void update(float delta);
	VIRTUAL bool handleEvent(const Event::IEvent &event);

public: /* static */

	static const Core::Type & Type(void);
};

#endif
