/*
 * Constants.hpp
 *
 *  Created on: October 16, 2019
 *      Author: LightCat
 */

// This file will include global constant expressions
#pragma once

constexpr const char *CON_PREFIX = "cow_";

constexpr unsigned short MAX_ENTITIES = 6400;
constexpr unsigned char MAX_PLAYERS  = 100;
// 0 is "World" but we still can have MAX_PLAYERS players, so consider that
constexpr unsigned short PLAYER_ARRAY_SIZE = 1 + MAX_PLAYERS;
