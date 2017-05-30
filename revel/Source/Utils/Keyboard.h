#pragma once

#include "LuaBind.h"

namespace rvl {
	struct Keyboard {
		friend void Bind<Keyboard>(lua_State* lua);

		static bool IsKeyPressed(int32 keycode);

		int32 A			=	sf::Keyboard::A;
		int32 B			=	sf::Keyboard::B;
		int32 C			=	sf::Keyboard::C;
		int32 D			=	sf::Keyboard::D;
		int32 E			=	sf::Keyboard::E;
		int32 F			=	sf::Keyboard::F;
		int32 G			=	sf::Keyboard::G;
		int32 H			=	sf::Keyboard::H;
		int32 I			=	sf::Keyboard::I;
		int32 J			=	sf::Keyboard::J;
		int32 K			=	sf::Keyboard::K;
		int32 L			=	sf::Keyboard::L;
		int32 M			=	sf::Keyboard::M;
		int32 N			=	sf::Keyboard::N;
		int32 O			=	sf::Keyboard::O;
		int32 P			=	sf::Keyboard::P;
		int32 Q			=	sf::Keyboard::Q;
		int32 R			=	sf::Keyboard::R;
		int32 S			=	sf::Keyboard::S;
		int32 T			=	sf::Keyboard::T;
		int32 U			=	sf::Keyboard::U;
		int32 V			=	sf::Keyboard::V;
		int32 W			=	sf::Keyboard::W;
		int32 X			=	sf::Keyboard::X;
		int32 Y			=	sf::Keyboard::Y;
		int32 Z			=	sf::Keyboard::Z;
		int32 Num0			=	sf::Keyboard::Num0;
		int32 Num1			=	sf::Keyboard::Num1;
		int32 Num2			=	sf::Keyboard::Num2;
		int32 Num3			=	sf::Keyboard::Num3;
		int32 Num4			=	sf::Keyboard::Num4;
		int32 Num5			=	sf::Keyboard::Num5;
		int32 Num6			=	sf::Keyboard::Num6;
		int32 Num7			=	sf::Keyboard::Num7;
		int32 Num8			=	sf::Keyboard::Num8;
		int32 Num9			=	sf::Keyboard::Num9;
		int32 Escape		=	sf::Keyboard::Escape;
		int32 LControl		=	sf::Keyboard::LControl;
		int32 LShift		=	sf::Keyboard::LShift;
		int32 LAlt			=	sf::Keyboard::LAlt;
		int32 LSystem		=	sf::Keyboard::LSystem;
		int32 RControl		=	sf::Keyboard::RControl;
		int32 RShift		=	sf::Keyboard::RShift;
		int32 RAlt			=	sf::Keyboard::RAlt;
		int32 RSystem		=	sf::Keyboard::RSystem;
		int32 RBracket		=	sf::Keyboard::RBracket;
		int32 LBracket		=	sf::Keyboard::LBracket;
		int32 Menu			=	sf::Keyboard::Menu;
		int32 SemiColon	=	sf::Keyboard::SemiColon;
		int32 Comma		=	sf::Keyboard::Comma;
		int32 Period		=	sf::Keyboard::Period;
		int32 Quote		=	sf::Keyboard::Quote;
		int32 Slash		=	sf::Keyboard::Slash;
		int32 BackSlash	=	sf::Keyboard::BackSlash;
		int32 Tilde		=	sf::Keyboard::Tilde;
		int32 Equal		=	sf::Keyboard::Equal;
		int32 Dash			=	sf::Keyboard::Dash;
		int32 Space		=	sf::Keyboard::Space;
		int32 Return		=	sf::Keyboard::Space;
		int32 BackSpace	=	sf::Keyboard::BackSpace;
		int32 Tab			=	sf::Keyboard::Tab;
		int32 PageUp		=	sf::Keyboard::PageUp;
		int32 PageDown		=	sf::Keyboard::PageDown;
		int32 End			=	sf::Keyboard::End;
		int32 Home			=	sf::Keyboard::Home;
		int32 Insert		=	sf::Keyboard::Insert;
		int32 Delete		=	sf::Keyboard::Delete;
		int32 Add			=	sf::Keyboard::Add;
		int32 Subtract		=	sf::Keyboard::Subtract;
		int32 Multiply		=	sf::Keyboard::Multiply;
		int32 Divide		=	sf::Keyboard::Divide;
		int32 Left			=	sf::Keyboard::Left;
		int32 Right		=	sf::Keyboard::Right;
		int32 Up			=	sf::Keyboard::Up;
		int32 Down			=	sf::Keyboard::Down;
		int32 Numpad0		=	sf::Keyboard::Numpad0;
		int32 Numpad1		=	sf::Keyboard::Numpad1;
		int32 Numpad2		=	sf::Keyboard::Numpad2;
		int32 Numpad3		=	sf::Keyboard::Numpad3;
		int32 Numpad4		=	sf::Keyboard::Numpad4;
		int32 Numpad5		=	sf::Keyboard::Numpad5;
		int32 Numpad6		=	sf::Keyboard::Numpad6;
		int32 Numpad7		=	sf::Keyboard::Numpad7;
		int32 Numpad8		=	sf::Keyboard::Numpad8;
		int32 Numpad9		=	sf::Keyboard::Numpad9;
		int32 F1			=	sf::Keyboard::F1;
		int32 F2			=	sf::Keyboard::F2;
		int32 F3			=	sf::Keyboard::F3;
		int32 F4			=	sf::Keyboard::F4;
		int32 F5			=	sf::Keyboard::F5;
		int32 F6			=	sf::Keyboard::F6;
		int32 F7			=	sf::Keyboard::F7;
		int32 F8			=	sf::Keyboard::F8;
		int32 F9			=	sf::Keyboard::F9;
		int32 F10			=	sf::Keyboard::F10;
		int32 F11			=	sf::Keyboard::F11;
		int32 F12			=	sf::Keyboard::F12;
		int32 F13			=	sf::Keyboard::F13;
		int32 F14			=	sf::Keyboard::F14;
		int32 F15			=	sf::Keyboard::F15;

		protected:
			static void						DoBind(lua_State* L);
	};
}
