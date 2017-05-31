#pragma once

#include "LuaBind.h"

namespace rvl {
	struct Keyboard {
		friend void Bind<Keyboard>(lua_State* lua);

		static bool IsKeyPressed(uint8 keycode);

		static uint8 A;
		static uint8 B;
		static uint8 C;
		static uint8 D;
		static uint8 E;
		static uint8 F;
		static uint8 G;
		static uint8 H;
		static uint8 I;
		static uint8 J;
		static uint8 K;
		static uint8 L;
		static uint8 M;
		static uint8 N;
		static uint8 O;
		static uint8 P;
		static uint8 Q;
		static uint8 R;
		static uint8 S;
		static uint8 T;
		static uint8 U;
		static uint8 V;
		static uint8 W;
		static uint8 X;
		static uint8 Y;
		static uint8 Z;
		static uint8 Num0;
		static uint8 Num1;
		static uint8 Num2;
		static uint8 Num3;
		static uint8 Num4;
		static uint8 Num5;
		static uint8 Num6;
		static uint8 Num7;
		static uint8 Num8;
		static uint8 Num9;
		static uint8 Escape;
		static uint8 LControl;
		static uint8 LShift;
		static uint8 LAlt;
		static uint8 LSystem;
		static uint8 RControl;
		static uint8 RShift;
		static uint8 RAlt;
		static uint8 RSystem;
		static uint8 RBracket;
		static uint8 LBracket;
		static uint8 Menu;
		static uint8 SemiColon;
		static uint8 Comma;
		static uint8 Period;
		static uint8 Quote;
		static uint8 Slash;
		static uint8 BackSlash;
		static uint8 Tilde;
		static uint8 Equal;
		static uint8 Dash;
		static uint8 Space;
		static uint8 Return;
		static uint8 BackSpace;
		static uint8 Tab;
		static uint8 PageUp;
		static uint8 PageDown;
		static uint8 End;
		static uint8 Home;
		static uint8 Insert;
		static uint8 Delete;
		static uint8 Add;
		static uint8 Subtract;
		static uint8 Multiply;
		static uint8 Divide;
		static uint8 Left;
		static uint8 Right;
		static uint8 Up;
		static uint8 Down;
		static uint8 Numpad0;
		static uint8 Numpad1;
		static uint8 Numpad2;
		static uint8 Numpad3;
		static uint8 Numpad4;
		static uint8 Numpad5;
		static uint8 Numpad6;
		static uint8 Numpad7;
		static uint8 Numpad8;
		static uint8 Numpad9;
		static uint8 F1;
		static uint8 F2;
		static uint8 F3;
		static uint8 F4;
		static uint8 F5;
		static uint8 F6;
		static uint8 F7;
		static uint8 F8;
		static uint8 F9;
		static uint8 F10;
		static uint8 F11;
		static uint8 F12;
		static uint8 F13;
		static uint8 F14;
		static uint8 F15;

		protected:
			static void						DoBind(lua_State* L);
	};
}
