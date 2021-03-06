/**
 * Created by univrsal on 06.07.2018.
 * This file is part of input-overlay which is licensed
 * under the MOZILLA PUBLIC LICENSE 2.0 - mozilla.org/en-US/MPL/2.0/
 * github.com/univrsal/input-overlay
 */
#pragma once

#define CFG_DEFAULT_WIDTH	"default_width"
#define CFG_DEFAULT_HEIGHT	"default_height"
#define CFG_H_SPACE		"space_h"
#define CFG_V_SPACE		"space_v"

#define CFG_TOTAL_WIDTH	"overlay_width"
#define CFG_TOTAL_HEIGHT "overlay_height"

#define CFG_X_POS	"_x_pos"
#define CFG_Y_POS	"_y_pos"
#define CFG_U		"_u"
#define CFG_V		"_v"
#define CFG_TYPE	"_type"
#define CFG_KEY_CODE	"_code"
#define CFG_WIDTH	"_width"
#define CFG_HEIGHT	"_height"
#define CFG_Z_LEVEL	"_z_level"
#define CFG_FIRST_ID	"first_element"
#define CFG_NEXT_ID	"_next"

enum ElementType
{
	INVALID = -1,
	TEXTURE,
	BUTTON,
	MOUSE_SCROLLWHEEL, /* MOUSE_WHEEL was taken :( */
	MOUSE_MOVEMENT,
	ANALOG_STICK,
	TRIGGER,
	TEXT,
	DPAD_STICK,
};
